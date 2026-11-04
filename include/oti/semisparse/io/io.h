#ifndef OTI_SEMISPARSE_IO_H
#define OTI_SEMISPARSE_IO_H

// Semi-sparse save / read binary format (PLAN-semisparse-sparse-leveling.md, Phase 3).
//
// One file holds one semi-sparse scalar (ssotinum_t), one AoS array (arrss_t) or one SoA array
// (oarrss_t). Nothing here calls exit(): every function returns a status (SSIO_OK or a negative
// SSIO_ERR_*), and the Python layer turns a status into an exception. Allocation failures inside the
// constructors of the scalar and array types still exit, like everywhere else in the semi-sparse
// module, but reading checks every size against the size of the file first, so a corrupt header
// cannot ask for a huge allocation.

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     FILE FORMAT     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Semi-sparse file format, versions 1 and 2
 *
 * All multi-byte values are stored in the byte order of the host that wrote the file (flagged in
 * the header; a file is only read back on a host of the same byte order: little-endian for every
 * platform the library supports). The file is a header (64 bytes in v1, 64 + 8 * ndim in v2)
 * followed by the payload.
 *
 * Header (offsets in bytes, unused bytes are zero):
 *
 * | offset | size | field |
 * |---|---|---|
 * | 0  | 4 | magic: 0x93 'O' 'T' 'S' (sparse files start 0x93 'O' 'T' 'I') |
 * | 4  | 2 | format version (uint16): 1 (pyoti 1.x) or 2 (SSIO_VERSION, written since 2.0.0) |
 * | 6  | 1 | type tag: SSIO_TYPE_SCALAR = 1, SSIO_TYPE_AOS = 2, SSIO_TYPE_SOA = 3 |
 * | 7  | 1 | byte order: SSIO_LITTLE_ENDIAN = 1, SSIO_BIG_ENDIAN = 2 |
 * | 8  | 1 | bytes per coefficient (8) |
 * | 9  | 1 | bytes per base label (2) |
 * | 10 | 1 | truncation order (AoS: largest over the elements) |
 * | 11 | 1 | active order (AoS: largest over the elements) |
 * | 12 | 4 | number of active bases k (uint32; 0 for AoS, whose elements carry their own) |
 * | 16 | 8 | number of rows (uint64; 1 for a scalar). v2: the matricized shape, S[0] (1 for 0-D) |
 * | 24 | 8 | number of columns (uint64; 1 for a scalar). v2: the product of S[1..] (1 for 0-D, 1-D) |
 * | 32 | 8 | payload size in bytes (uint64); the file is exactly header + payload bytes long |
 * | 40 | 4 | v1: zero. v2: ndim, the rank of the logical shape S (uint32, 0 .. SSIO_MAX_NDIM) |
 * | 44 | 1 | v1: zero. v2: payload layout, SSIO_LAYOUT_F = 1 (SoA, scalar) or SSIO_LAYOUT_C = 2 (AoS) |
 * | 45 | 19 | reserved, zero |
 * | 64 | 8 * ndim | v2 only: the extents S[0 .. ndim-1] (uint64 each) |
 *
 * Payload, by type. "Labels" are the k sorted active global bases (uint16 each, strictly
 * increasing), zero-padded up to a multiple of 8 bytes. The "order blocks" are the imaginary
 * coefficients of orders 1..trc, order p holding N_p(k) = C(k+p-1, p) local directions in the
 * colex numbering of include/oti/core/semisparse.h, so orders are back to back with no gaps.
 *
 * - Scalar: labels, the real part (1 double), then the order blocks (one double per local
 *   direction, order 1 first): 1 + sshelp_ndir_total(k, trc) doubles in all.
 * - SoA: labels, then 1 + sshelp_ndir_total(k, trc) blocks of nrows * ncols doubles, each
 *   column-major (element (r, c) at r + c*nrows). Block 0 is the real part; block
 *   1 + sshelp_order_offset(k, p) + i is local direction i of order p. The active set is shared
 *   by every element.
 * - AoS: nrows * ncols records in memory order (row-major, element (i, j) is record j + i*ncols).
 *   A record is an 8-byte header (uint8 trc, uint8 act, uint16 k, 4 zero bytes), its own labels,
 *   then its real part and order blocks as in a scalar.
 *
 * Orders above the active order must be zero; a file that says otherwise is rejected.
 * Version 2 follows the one v2 header rule of the three formats (contracts 11.12; 'OTS' keeps byte 9
 * for the label width, so its layout flag is byte 44): the logical shape S of the Python object over
 * the 2-D C struct, matricized as rows = S[0] and columns = the product of S[1..], so (n) is n x 1 and
 * () is 1 x 1. The layout flag must be the type's own (F for SoA, C for AoS; a scalar either). A
 * version-1 file reads back with its stored 2-D shape (ndim 2; 0 for a scalar). The payload is the
 * same in both versions. The header represents ndim up to SSIO_MAX_NDIM; the Python arrays of 2.0
 * development read ndim <= 2 (Phase 8 the rest). The develop-only v2 layout written before this rule
 * (ndim at byte 40, 'F' / 'C' at 41, extents at 48) is not read.
 * @{
 */

#define SSIO_HEADER_BYTES   64  ///< Size of the file header.
#define SSIO_VERSION         2  ///< Format version written by this library.
#define SSIO_VERSION_1       1  ///< Oldest format version read (pyoti 1.x).
#define SSIO_MAX_NDIM       31  ///< Largest ndim of a version-2 file (the 'OTD' limit, DNIO_MAXDIM).

#define SSIO_LAYOUT_F        1  ///< v2 layout flag: column-major payload elements (SoA, scalar).
#define SSIO_LAYOUT_C        2  ///< v2 layout flag: row-major payload elements (AoS records).

#define SSIO_TYPE_SCALAR     1  ///< File holds an ssotinum_t.
#define SSIO_TYPE_AOS        2  ///< File holds an arrss_t.
#define SSIO_TYPE_SOA        3  ///< File holds an oarrss_t.

#define SSIO_LITTLE_ENDIAN   1  ///< Byte order flag: little-endian host.
#define SSIO_BIG_ENDIAN      2  ///< Byte order flag: big-endian host.

/** @} */


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     STATUS CODES     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

#define SSIO_OK               0  ///< Success.
#define SSIO_ERR_OPEN       (-1) ///< The file cannot be opened (missing, unreadable, not writable).
#define SSIO_ERR_IO         (-2) ///< A read or write failed.
#define SSIO_ERR_MAGIC      (-3) ///< Not a semi-sparse OTI file (magic mismatch or a short file).
#define SSIO_ERR_VERSION    (-4) ///< Format version newer than this library reads.
#define SSIO_ERR_TYPE       (-5) ///< The file holds another type than the one requested.
#define SSIO_ERR_FORMAT     (-6) ///< Inconsistent header or payload (orders, sizes, labels, order).
#define SSIO_ERR_TRUNCATED  (-7) ///< The file is shorter than its header says.
#define SSIO_ERR_SIZE       (-8) ///< The file is longer than its header says.
#define SSIO_ERR_ARGUMENT   (-9) ///< A NULL pointer, or an object the format cannot represent.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     DECLARATIONS     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Header fields of a semi-sparse file, as returned by ssio_peek().
 */
typedef struct {
    int         type; ///< SSIO_TYPE_SCALAR, SSIO_TYPE_AOS or SSIO_TYPE_SOA.
    int      version; ///< Format version of the file.
    ord_t  trc_order; ///< Truncation order (AoS: largest over the elements).
    ord_t  act_order; ///< Active order (AoS: largest over the elements).
    uint32_t nbases;  ///< Number of active bases (0 for AoS).
    uint64_t  nrows;  ///< Number of rows (1 for a scalar).
    uint64_t  ncols;  ///< Number of columns (1 for a scalar).
    uint64_t payload; ///< Payload size in bytes.
    int         ndim; ///< Logical ndim (version 1: 2 for arrays, 0 for a scalar).
    int       layout; ///< SSIO_LAYOUT_F or SSIO_LAYOUT_C (version 1: F for SoA, C otherwise).
    uint64_t head_bytes; ///< Header size: 64 (version 1) or 64 + 8 * ndim (version 2).
    uint64_t shape[SSIO_MAX_NDIM]; ///< Logical shape; entries past ndim are zero.
} ssio_info_t;        ///< Header of a semi-sparse file.


/**
 * @brief Short description of a status code.
 *
 * @param[in] status SSIO_OK or an SSIO_ERR_* code.
 *
 * @return Static string; never NULL, not to be freed.
 */
const char* ssio_strerror(int status);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Reads and validates the header of a semi-sparse file, without reading the payload.
 *
 * Checks the magic, version (1 or 2), byte order and field sizes, that the orders are consistent,
 * that a version-2 shape and layout match the C dimensions and the type, and that the file size is
 * header + payload bytes.
 *
 * @param[in]  filename Path of the file.
 * @param[out] p_info   Header fields; unchanged on error.
 *
 * @return SSIO_OK, or an SSIO_ERR_* code.
 */
int ssio_peek(const char* filename, ssio_info_t* p_info);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Saves a semi-sparse scalar (version 2, ndim 0).
 *
 * @param[in] filename Path of the file to create (overwritten if it exists).
 * @param[in] num      Scalar.
 *
 * @return SSIO_OK, or an SSIO_ERR_* code (the file may be left incomplete on SSIO_ERR_IO).
 */
int ssoti_save(const char* filename, const ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Reads a semi-sparse scalar saved with ssoti_save().
 *
 * @param[in]  filename Path of the file.
 * @param[out] res      The scalar, newly allocated; previous contents are overwritten, not freed.
 *                      On error it is set to ssoti_init().
 *
 * @return SSIO_OK, or an SSIO_ERR_* code. On success the caller owns @p res and must free it via
 *         ssoti_free().
 */
int ssoti_read(const char* filename, ssotinum_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Saves an AoS array (version 2, logical shape (nrows, ncols)).
 *
 * @param[in] filename Path of the file to create (overwritten if it exists).
 * @param[in] arr      Array.
 *
 * @return SSIO_OK, or an SSIO_ERR_* code (the file may be left incomplete on SSIO_ERR_IO).
 */
int arrss_save(const char* filename, const arrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Saves an AoS array with the logical shape of its Python object (version 2).
 *
 * @param[in] filename Path of the file to create (overwritten if it exists).
 * @param[in] arr      Array.
 * @param[in] ndim     Logical ndim, 0 to SSIO_MAX_NDIM.
 * @param[in] shape    Logical shape, ndim values (may be NULL for ndim 0); S[0] must be nrows and
 *                     the product of S[1..] ncols.
 *
 * @return SSIO_OK, or an SSIO_ERR_* code (SSIO_ERR_ARGUMENT for a shape that does not match).
 */
int arrss_save_shape(const char* filename, const arrss_t* arr, int ndim, const uint64_t* shape);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Reads an AoS array saved with arrss_save() or arrss_save_shape() (version 1 or 2).
 *
 * @param[in]  filename Path of the file.
 * @param[out] res      The array, newly allocated; previous contents are overwritten, not freed.
 *                      On error it is set to arrss_init().
 *
 * @return SSIO_OK, or an SSIO_ERR_* code. On success the caller owns @p res and must free it via
 *         arrss_free().
 */
int arrss_read(const char* filename, arrss_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Saves a SoA array (version 2, logical shape (nrows, ncols)).
 *
 * @param[in] filename Path of the file to create (overwritten if it exists).
 * @param[in] arr      Array.
 *
 * @return SSIO_OK, or an SSIO_ERR_* code (the file may be left incomplete on SSIO_ERR_IO).
 */
int oarrss_save(const char* filename, const oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Saves a SoA array with the logical shape of its Python object (version 2).
 *
 * @param[in] filename Path of the file to create (overwritten if it exists).
 * @param[in] arr      Array.
 * @param[in] ndim     Logical ndim, 0 to SSIO_MAX_NDIM.
 * @param[in] shape    Logical shape, ndim values (may be NULL for ndim 0); S[0] must be nrows and
 *                     the product of S[1..] ncols.
 *
 * @return SSIO_OK, or an SSIO_ERR_* code (SSIO_ERR_ARGUMENT for a shape that does not match).
 */
int oarrss_save_shape(const char* filename, const oarrss_t* arr, int ndim, const uint64_t* shape);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Reads a SoA array saved with oarrss_save() or oarrss_save_shape() (version 1 or 2).
 *
 * The logical shape of a version-2 file is reported by ssio_peek().
 *
 * @param[in]  filename Path of the file.
 * @param[out] res      The array, newly allocated; previous contents are overwritten, not freed.
 *                      On error it is set to oarrss_init().
 *
 * @return SSIO_OK, or an SSIO_ERR_* code. On success the caller owns @p res and must free it via
 *         oarrss_free().
 */
int oarrss_read(const char* filename, oarrss_t* res);
// -------------------------------------------------------------------------------------------------------


#endif
