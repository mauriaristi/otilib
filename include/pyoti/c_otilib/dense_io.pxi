# Dense C declarations: save / read.
# GENERATED from include/oti/dense/**/*.h (PLAN-dense-update.md) by
# tools/gen_dense_pxi.py; re-run it when a dense header changes.
# Do not edit by hand.
cdef extern from "oti/dense.h" nogil:

    # io/io.h
    cdef enum:
        DNIO_HEADER_BYTES
        DNIO_VERSION
        DNIO_TYPE_SCALAR
        DNIO_TYPE_AOS
        DNIO_TYPE_SOA
        DNIO_LITTLE_ENDIAN
        DNIO_BIG_ENDIAN
        DNIO_OK
        DNIO_ERR_OPEN
        DNIO_ERR_IO
        DNIO_ERR_MAGIC
        DNIO_ERR_VERSION
        DNIO_ERR_TYPE
        DNIO_ERR_FORMAT
        DNIO_ERR_TRUNCATED
        DNIO_ERR_SIZE
        DNIO_ERR_ARGUMENT
        DNIO_ERR_MEMORY

    ctypedef struct dnio_info_t:
        int type
        int version
        ord_t trc_order
        ord_t act_order
        uint32_t nact
        uint64_t nrows
        uint64_t ncols
        uint64_t payload

    const char* dnio_strerror(int status)
    int dnio_peek(const char* filename, dnio_info_t* p_info)
    int oti_save(const char* filename, const otinum_t* num)
    int oti_read(const char* filename, otinum_t* res)
    int arro_save(const char* filename, const arro_t* arr)
    int arro_read(const char* filename, arro_t* res)
    int oarr_save(const char* filename, const oarr_t* arr)
    int oarr_read(const char* filename, oarr_t* res)
