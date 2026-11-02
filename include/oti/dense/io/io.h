#ifndef OTI_DENSE_IO_H
#define OTI_DENSE_IO_H

// Dense save / read binary format (PLAN-dense-update.md, WP5).
//
// One file holds one dense scalar (otinum_t), one AoS array (arro_t) or one SoA array (oarr_t). Nothing
// here calls exit(): every function returns a status (DNIO_OK or a negative DNIO_ERR_*), and the Python
// layer turns a status into an exception. These functions return only DNIO_* codes: a DN_ERR_* from an
// inner oti_ / oarr_ / arro_ call is mapped (DN_ERR_MEMORY -> DNIO_ERR_MEMORY, anything else ->
// DNIO_ERR_FORMAT or DNIO_ERR_ARGUMENT), since the two families reuse -1, -2. Reading checks every size
// against the size of the file first, so a corrupt header cannot ask for a huge allocation. The format
// mirrors the semi-sparse one (include/oti/semisparse/io/io.h) without the base labels, since a dense
// number is always over bases 1..nact; the files are not interchangeable (different magic).

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     FILE FORMAT     -------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Dense file format, version 1
 *
 * All multi-byte values are stored in the byte order of the host that wrote the file (flagged in
 * the header; a file is only read back on a host of the same byte order (DNIO_ERR_FORMAT otherwise,
 * checked before any multi-byte field is decoded): little-endian for every
 * platform the library supports). The file is a 64-byte header followed by the payload.
 *
 * Header (offsets in bytes, unused bytes are zero):
 *
 * | offset | size | field |
 * |---|---|---|
 * | 0  | 4 | magic: 0x93 'O' 'T' 'D' (semi-sparse 0x93 'O' 'T' 'S', sparse 0x93 'O' 'T' 'I') |
 * | 4  | 2 | format version (uint16, DNIO_VERSION = 1) |
 * | 6  | 1 | type tag: DNIO_TYPE_SCALAR = 1, DNIO_TYPE_AOS = 2, DNIO_TYPE_SOA = 3 |
 * | 7  | 1 | byte order: DNIO_LITTLE_ENDIAN = 1, DNIO_BIG_ENDIAN = 2 |
 * | 8  | 1 | bytes per coefficient (8) |
 * | 9  | 1 | reserved, zero |
 * | 10 | 1 | truncation order (AoS: largest over the elements) |
 * | 11 | 1 | active order (AoS: largest over the elements) |
 * | 12 | 4 | nact, the number of active bases k (uint32; AoS: largest over the elements) |
 * | 16 | 8 | number of rows (uint64; 1 for a scalar) |
 * | 24 | 8 | number of columns (uint64; 1 for a scalar) |
 * | 32 | 8 | payload size in bytes (uint64); the file is exactly 64 + payload bytes long |
 * | 40 | 24 | reserved, zero |
 *
 * Payload, by type. The "order blocks" are the imaginary coefficients of orders 1..trc, order p
 * holding N_p(k) = C(k+p-1, p) directions in global index order (the dense layout of otinum_t), so
 * orders are back to back with no gaps.
 *
 * - Scalar: the real part (1 double), then the order blocks (one double per direction, order 1
 *   first): 1 + sshelp_ndir_total(k, trc) doubles in all.
 * - SoA: 1 + sshelp_ndir_total(k, trc) blocks of nrows * ncols doubles, each column-major (element
 *   (r, c) at r + c*nrows). Block 0 is the real part; block 1 + sshelp_order_offset(k, p) + i is
 *   direction i of order p. nact is shared by every element.
 * - AoS: nrows * ncols records in memory order (row-major, element (i, j) is record j + i*ncols).
 *   A record is an 8-byte header (uint8 trc, uint8 act, uint16 k, 4 zero bytes), then its real
 *   part and order blocks as in a scalar.
 *
 * Orders above the active order must be zero; a file that says otherwise is rejected, and saving an
 * object with a nonzero coefficient above its act_order returns DNIO_ERR_ARGUMENT (no file). The
 * reserved bytes and the AoS record padding must be zero. An empty AoS array carries zero maxima
 * (trc, act, nact) and payload 0. dnio_peek() validates the header only, not the AoS records.
 * @{
 */

#define DNIO_HEADER_BYTES   64  ///< Size of the file header.
#define DNIO_VERSION         1  ///< Format version written by this library.

#define DNIO_TYPE_SCALAR     1  ///< File holds an otinum_t.
#define DNIO_TYPE_AOS        2  ///< File holds an arro_t.
#define DNIO_TYPE_SOA        3  ///< File holds an oarr_t.

#define DNIO_LITTLE_ENDIAN   1  ///< Byte order flag: little-endian host.
#define DNIO_BIG_ENDIAN      2  ///< Byte order flag: big-endian host.

/** @} */


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     STATUS CODES     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

#define DNIO_OK               0  ///< Success.
#define DNIO_ERR_OPEN       (-1) ///< The file cannot be opened (missing, unreadable, not writable).
#define DNIO_ERR_IO         (-2) ///< A read or write failed.
#define DNIO_ERR_MAGIC      (-3) ///< Not a dense OTI file (magic mismatch or a short file).
#define DNIO_ERR_VERSION    (-4) ///< Format version newer than this library reads.
#define DNIO_ERR_TYPE       (-5) ///< The file holds another type than the one requested.
#define DNIO_ERR_FORMAT     (-6) ///< Inconsistent header or payload (orders, sizes).
#define DNIO_ERR_TRUNCATED  (-7) ///< The file is shorter than its header says.
#define DNIO_ERR_SIZE       (-8) ///< The file is longer than its header says.
#define DNIO_ERR_ARGUMENT   (-9) ///< A NULL pointer, or an object the format cannot represent.
#define DNIO_ERR_MEMORY    (-10) ///< An allocation failed while reading.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     DECLARATIONS     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Header fields of a dense file, as returned by dnio_peek().
 */
typedef struct {
    int         type; ///< DNIO_TYPE_SCALAR, DNIO_TYPE_AOS or DNIO_TYPE_SOA.
    int      version; ///< Format version of the file.
    ord_t  trc_order; ///< Truncation order (AoS: largest over the elements).
    ord_t  act_order; ///< Active order (AoS: largest over the elements).
    uint32_t    nact; ///< Number of active bases (AoS: largest over the elements).
    uint64_t   nrows; ///< Number of rows (1 for a scalar).
    uint64_t   ncols; ///< Number of columns (1 for a scalar).
    uint64_t payload; ///< Payload size in bytes.
} dnio_info_t;        ///< Header of a dense file.


/**
 * @brief Short description of a status code.
 *
 * @param[in] status DNIO_OK or a DNIO_ERR_* code.
 *
 * @return Static string; never NULL, not to be freed.
 */
const char* dnio_strerror(int status);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Reads and validates the header of a dense file, without reading the payload.
 *
 * Checks the magic, version, byte order and field sizes, that the orders are consistent, and that
 * the file size is 64 + payload bytes.
 *
 * @param[in]  filename Path of the file.
 * @param[out] p_info   Header fields; unchanged on error.
 *
 * @return DNIO_OK, or a DNIO_ERR_* code.
 */
int dnio_peek(const char* filename, dnio_info_t* p_info);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Saves a dense scalar.
 *
 * @param[in] filename Path of the file to create (overwritten if it exists).
 * @param[in] num      Scalar.
 *
 * @return DNIO_OK, or a DNIO_ERR_* code. The save is atomic: the data is written to a temporary file
 *         <filename>.tmp.<pid>.<n> in the same directory and renamed over @p filename on success.
 *         On any failure only the temporary file is removed, so an existing file of that name survives
 *         (DNIO_ERR_OPEN also when @p filename cannot be replaced, e.g. a directory). A successful
 *         save replaces the file itself (a symbolic link is replaced, an old file's mode is not kept).
 */
int oti_save(const char* filename, const otinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Reads a dense scalar saved with oti_save().
 *
 * @param[in]  filename Path of the file.
 * @param[out] res      The scalar, newly allocated; previous contents are overwritten, not freed.
 *                      On error it is set to oti_init().
 *
 * @return DNIO_OK, or a DNIO_ERR_* code. On success the caller owns @p res and must free it via
 *         oti_free().
 */
int oti_read(const char* filename, otinum_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Saves an AoS array.
 *
 * @param[in] filename Path of the file to create (overwritten if it exists).
 * @param[in] arr      Array.
 *
 * @return DNIO_OK, or a DNIO_ERR_* code. The save is atomic: the data is written to a temporary file
 *         <filename>.tmp.<pid>.<n> in the same directory and renamed over @p filename on success.
 *         On any failure only the temporary file is removed, so an existing file of that name survives
 *         (DNIO_ERR_OPEN also when @p filename cannot be replaced, e.g. a directory). A successful
 *         save replaces the file itself (a symbolic link is replaced, an old file's mode is not kept).
 */
int arro_save(const char* filename, const arro_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Reads an AoS array saved with arro_save().
 *
 * @param[in]  filename Path of the file.
 * @param[out] res      The array, newly allocated; previous contents are overwritten, not freed.
 *                      On error it is set to arro_init().
 *
 * @return DNIO_OK, or a DNIO_ERR_* code. On success the caller owns @p res and must free it via
 *         arro_free().
 */
int arro_read(const char* filename, arro_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Saves a SoA array.
 *
 * @param[in] filename Path of the file to create (overwritten if it exists).
 * @param[in] arr      Array.
 *
 * @return DNIO_OK, or a DNIO_ERR_* code. The save is atomic: the data is written to a temporary file
 *         <filename>.tmp.<pid>.<n> in the same directory and renamed over @p filename on success.
 *         On any failure only the temporary file is removed, so an existing file of that name survives
 *         (DNIO_ERR_OPEN also when @p filename cannot be replaced, e.g. a directory). A successful
 *         save replaces the file itself (a symbolic link is replaced, an old file's mode is not kept).
 */
int oarr_save(const char* filename, const oarr_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Reads a SoA array saved with oarr_save().
 *
 * @param[in]  filename Path of the file.
 * @param[out] res      The array, newly allocated; previous contents are overwritten, not freed.
 *                      On error it is set to oarr_init().
 *
 * @return DNIO_OK, or a DNIO_ERR_* code. On success the caller owns @p res and must free it via
 *         oarr_free().
 */
int oarr_read(const char* filename, oarr_t* res);
// -------------------------------------------------------------------------------------------------------


#endif
