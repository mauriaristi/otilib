# Semi-sparse C declarations, Phase 3: save / read.
# (PLAN-semisparse-sparse-leveling.md). Declare against "oti/semisparse.h".
cdef extern from "oti/semisparse.h":
    ctypedef struct ssio_info_t:
        int type
        int version
        ord_t trc_order
        ord_t act_order
        uint32_t nbases
        uint64_t nrows
        uint64_t ncols
        uint64_t payload

    cdef enum:
        SSIO_OK
        SSIO_ERR_OPEN
        SSIO_ERR_IO
        SSIO_ERR_MAGIC
        SSIO_ERR_VERSION
        SSIO_ERR_TYPE
        SSIO_ERR_FORMAT
        SSIO_ERR_TRUNCATED
        SSIO_ERR_SIZE
        SSIO_ERR_ARGUMENT
        SSIO_TYPE_SCALAR
        SSIO_TYPE_AOS
        SSIO_TYPE_SOA

    const char *ssio_strerror(int status)
    int ssio_peek(const char *filename, ssio_info_t *p_info)
    int ssoti_save(const char *filename, const ssotinum_t *num)
    int ssoti_read(const char *filename, ssotinum_t *res)
    int arrss_save(const char *filename, const arrss_t *arr)
    int arrss_read(const char *filename, arrss_t *res)
    int oarrss_save(const char *filename, const oarrss_t *arr)
    int oarrss_read(const char *filename, oarrss_t *res)
