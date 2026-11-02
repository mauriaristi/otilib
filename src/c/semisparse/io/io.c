// Semi-sparse save / read binary format (PLAN-semisparse-sparse-leveling.md, Phase 3).
// Declarations and the file layout in include/oti/semisparse/io/io.h.

#include <sys/types.h>


// *******************************************************************************************************
const char* ssio_strerror(int status){

    switch (status){

        case SSIO_OK:            return "success";
        case SSIO_ERR_OPEN:      return "cannot open the file";
        case SSIO_ERR_IO:        return "read or write error";
        case SSIO_ERR_MAGIC:     return "not a semi-sparse OTI file (bad magic number)";
        case SSIO_ERR_VERSION:   return "unsupported semi-sparse file format version";
        case SSIO_ERR_TYPE:      return "the file holds another semi-sparse type";
        case SSIO_ERR_FORMAT:    return "corrupt semi-sparse file (inconsistent header or data)";
        case SSIO_ERR_TRUNCATED: return "truncated semi-sparse file";
        case SSIO_ERR_SIZE:      return "semi-sparse file is longer than its header says";
        case SSIO_ERR_ARGUMENT:  return "invalid argument (NULL pointer or unrepresentable object)";
        default:                 return "unknown semi-sparse I/O status";

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Byte order flag of the host.
static int ssio_host_order(void){

    const uint16_t one = 1;

    return (*(const uint8_t*)&one == 1) ? SSIO_LITTLE_ENDIAN : SSIO_BIG_ENDIAN;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes taken by k labels, padded up to a multiple of 8.
static uint64_t ssio_labels_bytes(bases_t k){

    return (((uint64_t)k * sizeof(bases_t) + 7) / 8) * 8;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// True when the labels are strictly increasing.
static int ssio_labels_sorted(const bases_t* p_bases, bases_t k){

    bases_t i;

    for (i = 1; i < k; i++){

        if (p_bases[i] <= p_bases[i - 1]){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes of a scalar's data (labels, real part, order blocks) over k bases up to order trc; a
// nonzero return is an SSIO_ERR_* code.
static int ssio_scalar_bytes(bases_t k, ord_t trc, uint64_t* p_bytes){

    ndir_t nimag;
    uint64_t labels = ssio_labels_bytes(k);

    if (sshelp_ndir_total_checked(k, trc, &nimag) != SSHELP_OK){
        return SSIO_ERR_FORMAT;
    }

    if (nimag > (UINT64_MAX - labels) / sizeof(coeff_t) - 1){
        return SSIO_ERR_FORMAT;
    }

    *p_bytes = labels + (1 + nimag) * sizeof(coeff_t);

    return SSIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes of a SoA array's payload (labels, then 1 + ndir_total blocks of nrows * ncols reals).
static int ssio_soa_bytes(bases_t k, ord_t trc, uint64_t nrows, uint64_t ncols, uint64_t* p_bytes){

    ndir_t nimag;
    uint64_t labels = ssio_labels_bytes(k), size, nblocks;

    if (nrows != 0 && ncols > UINT64_MAX / nrows){
        return SSIO_ERR_FORMAT;
    }

    size = nrows * ncols;

    if (sshelp_ndir_total_checked(k, trc, &nimag) != SSHELP_OK){
        return SSIO_ERR_FORMAT;
    }

    nblocks = 1 + nimag;

    if (size != 0 && nblocks > (UINT64_MAX - labels) / sizeof(coeff_t) / size){
        return SSIO_ERR_FORMAT;
    }

    *p_bytes = labels + nblocks * size * sizeof(coeff_t);

    return SSIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes the 64-byte header.
static int ssio_header_write(FILE* file, int type, ord_t trc, ord_t act, uint32_t nbases,
                             uint64_t nrows, uint64_t ncols, uint64_t payload){

    uint8_t head[SSIO_HEADER_BYTES];
    const char magic[4] = {(char)0x93, 'O', 'T', 'S'};
    const uint16_t version = SSIO_VERSION;

    memset(head, 0, sizeof(head));
    memcpy(head, magic, 4);
    memcpy(head + 4, &version, sizeof(version));

    head[6]  = (uint8_t)type;
    head[7]  = (uint8_t)ssio_host_order();
    head[8]  = (uint8_t)sizeof(coeff_t);
    head[9]  = (uint8_t)sizeof(bases_t);
    head[10] = trc;
    head[11] = act;

    memcpy(head + 12, &nbases, sizeof(nbases));
    memcpy(head + 16, &nrows, sizeof(nrows));
    memcpy(head + 24, &ncols, sizeof(ncols));
    memcpy(head + 32, &payload, sizeof(payload));

    return (fwrite(head, 1, sizeof(head), file) == sizeof(head)) ? SSIO_OK : SSIO_ERR_IO;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Size of an open file in bytes; the position is left at the start.
static int ssio_file_bytes(FILE* file, uint64_t* p_bytes){

    off_t n;

    if (fseeko(file, 0, SEEK_END) != 0){
        return SSIO_ERR_IO;
    }

    n = ftello(file);

    if (n < 0 || fseeko(file, 0, SEEK_SET) != 0){
        return SSIO_ERR_IO;
    }

    *p_bytes = (uint64_t)n;

    return SSIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reads and validates the header of an open file (position at the start), including that the file
// size is header + payload.
static int ssio_header_read(FILE* file, ssio_info_t* p_info){

    uint8_t head[SSIO_HEADER_BYTES];
    uint16_t version;
    uint64_t file_bytes;
    size_t got;
    int status;
    ssio_info_t info;

    status = ssio_file_bytes(file, &file_bytes);

    if (status != SSIO_OK){
        return status;
    }

    got = fread(head, 1, sizeof(head), file);

    if (got < 4 || head[0] != 0x93 || head[1] != 'O' || head[2] != 'T' || head[3] != 'S'){
        return SSIO_ERR_MAGIC;
    }

    if (got < sizeof(head)){
        return SSIO_ERR_TRUNCATED;
    }

    memcpy(&version, head + 4, sizeof(version));

    if (version != SSIO_VERSION){
        return SSIO_ERR_VERSION;
    }

    info.version   = version;
    info.type      = head[6];
    info.trc_order = head[10];
    info.act_order = head[11];

    memcpy(&info.nbases, head + 12, sizeof(info.nbases));
    memcpy(&info.nrows, head + 16, sizeof(info.nrows));
    memcpy(&info.ncols, head + 24, sizeof(info.ncols));
    memcpy(&info.payload, head + 32, sizeof(info.payload));

    if (head[7] != ssio_host_order() || head[8] != sizeof(coeff_t) || head[9] != sizeof(bases_t)){
        return SSIO_ERR_FORMAT;
    }

    if (info.type != SSIO_TYPE_SCALAR && info.type != SSIO_TYPE_AOS && info.type != SSIO_TYPE_SOA){
        return SSIO_ERR_FORMAT;
    }

    if (info.act_order > info.trc_order || info.nbases > (uint32_t)((bases_t)~(bases_t)0)){
        return SSIO_ERR_FORMAT;
    }

    if ((info.type == SSIO_TYPE_AOS && info.nbases != 0)
        || (info.type == SSIO_TYPE_SCALAR && (info.nrows != 1 || info.ncols != 1))){
        return SSIO_ERR_FORMAT;
    }

    if (info.payload > UINT64_MAX - SSIO_HEADER_BYTES){
        return SSIO_ERR_FORMAT;
    }

    if (file_bytes < SSIO_HEADER_BYTES + info.payload){
        return SSIO_ERR_TRUNCATED;
    }

    if (file_bytes > SSIO_HEADER_BYTES + info.payload){
        return SSIO_ERR_SIZE;
    }

    *p_info = info;

    return SSIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int ssio_peek(const char* filename, ssio_info_t* p_info){

    FILE* file;
    int status;

    if (filename == NULL || p_info == NULL){
        return SSIO_ERR_ARGUMENT;
    }

    file = fopen(filename, "rb");

    if (file == NULL){
        return SSIO_ERR_OPEN;
    }

    status = ssio_header_read(file, p_info);
    fclose(file);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes `n` bytes.
static int ssio_write(FILE* file, const void* p_src, size_t n){

    return (n == 0 || fwrite(p_src, 1, n, file) == n) ? SSIO_OK : SSIO_ERR_IO;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reads exactly `n` bytes.
static int ssio_read(FILE* file, void* p_dst, size_t n){

    if (n == 0 || fread(p_dst, 1, n, file) == n){
        return SSIO_OK;
    }

    return feof(file) ? SSIO_ERR_TRUNCATED : SSIO_ERR_IO;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes k labels and the zero padding after them.
static int ssio_labels_write(FILE* file, const bases_t* p_bases, bases_t k){

    static const uint8_t zeros[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    uint64_t pad = ssio_labels_bytes(k) - (uint64_t)k * sizeof(bases_t);
    int status = ssio_write(file, p_bases, (size_t)k * sizeof(bases_t));

    return (status != SSIO_OK) ? status : ssio_write(file, zeros, (size_t)pad);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reads k labels and their padding into `p_bases` (room for k), checking padding and order.
static int ssio_labels_read(FILE* file, bases_t* p_bases, bases_t k){

    uint8_t pad[8];
    uint64_t npad = ssio_labels_bytes(k) - (uint64_t)k * sizeof(bases_t);
    uint64_t i;
    int status = ssio_read(file, p_bases, (size_t)k * sizeof(bases_t));

    if (status == SSIO_OK){
        status = ssio_read(file, pad, (size_t)npad);
    }

    if (status != SSIO_OK){
        return status;
    }

    for (i = 0; i < npad; i++){

        if (pad[i] != 0){
            return SSIO_ERR_FORMAT;
        }

    }

    return ssio_labels_sorted(p_bases, k) ? SSIO_OK : SSIO_ERR_FORMAT;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// True when p[lo .. hi) is all zero.
static int ssio_all_zero(const coeff_t* p, uint64_t lo, uint64_t hi){

    uint64_t i;

    for (i = lo; i < hi; i++){

        if (p[i] != 0.0){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reads a scalar's data (labels, real part, order blocks) into a new number of k bases and order
// trc. The orders above `act` must be zero.
static int ssio_scalar_read(FILE* file, bases_t k, ord_t trc, ord_t act, ssotinum_t* res){

    bases_t* p_bases = NULL;
    ssotinum_t num;
    ndir_t nimag = sshelp_ndir_total(k, trc);
    int status;

    if (k > 0){

        p_bases = (bases_t*)malloc((size_t)k * sizeof(bases_t));

        if (p_bases == NULL){
            ssoti_out_of_memory();
        }

    }

    status = ssio_labels_read(file, p_bases, k);

    if (status != SSIO_OK){

        free(p_bases);
        return status;

    }

    num = ssoti_create_empty(p_bases, k, trc);
    free(p_bases);

    status = ssio_read(file, &num.re, sizeof(coeff_t));

    if (status == SSIO_OK){
        status = ssio_read(file, num.p_im, (size_t)nimag * sizeof(coeff_t));
    }

    if (status == SSIO_OK && act < trc && nimag > 0
        && !ssio_all_zero(num.p_im, sshelp_order_offset(k, (ord_t)(act + 1)), nimag)){
        status = SSIO_ERR_FORMAT;
    }

    if (status != SSIO_OK){

        ssoti_free(&num);
        return status;

    }

    num.act_order = act;
    *res = num;

    return SSIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int ssoti_save(const char* filename, const ssotinum_t* num){

    FILE* file;
    uint64_t payload;
    int status;

    if (filename == NULL || num == NULL || (num->nbases > 0 && num->p_bases == NULL)
        || (num->nbases > 0 && num->trc_order > 0 && num->p_im == NULL)
        || num->act_order > num->trc_order || !ssio_labels_sorted(num->p_bases, num->nbases)){
        return SSIO_ERR_ARGUMENT;
    }

    status = ssio_scalar_bytes(num->nbases, num->trc_order, &payload);

    if (status != SSIO_OK){
        return SSIO_ERR_ARGUMENT;
    }

    file = fopen(filename, "wb");

    if (file == NULL){
        return SSIO_ERR_OPEN;
    }

    status = ssio_header_write(file, SSIO_TYPE_SCALAR, num->trc_order, num->act_order, num->nbases, 1,
        1, payload);

    if (status == SSIO_OK){
        status = ssio_labels_write(file, num->p_bases, num->nbases);
    }

    if (status == SSIO_OK){
        status = ssio_write(file, &num->re, sizeof(coeff_t));
    }

    if (status == SSIO_OK){
        status = ssio_write(file, num->p_im,
            (size_t)sshelp_ndir_total(num->nbases, num->trc_order) * sizeof(coeff_t));
    }

    if (fclose(file) != 0 && status == SSIO_OK){
        status = SSIO_ERR_IO;
    }

    if (status != SSIO_OK){
        remove(filename);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int ssoti_read(const char* filename, ssotinum_t* res){

    FILE* file;
    ssio_info_t info;
    uint64_t expected;
    int status;

    if (filename == NULL || res == NULL){
        return SSIO_ERR_ARGUMENT;
    }

    memset(&info, 0, sizeof(info));
    *res = ssoti_init();
    file = fopen(filename, "rb");

    if (file == NULL){
        return SSIO_ERR_OPEN;
    }

    status = ssio_header_read(file, &info);

    if (status == SSIO_OK && info.type != SSIO_TYPE_SCALAR){
        status = SSIO_ERR_TYPE;
    }

    if (status == SSIO_OK){
        status = ssio_scalar_bytes((bases_t)info.nbases, info.trc_order, &expected);
    }

    if (status == SSIO_OK && expected != info.payload){
        status = SSIO_ERR_FORMAT;
    }

    if (status == SSIO_OK){
        status = ssio_scalar_read(file, (bases_t)info.nbases, info.trc_order, info.act_order, res);
    }

    fclose(file);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_save(const char* filename, const oarrss_t* arr){

    FILE* file;
    uint64_t payload = 0;
    size_t nreal = 0;
    int status;

    if (filename == NULL || arr == NULL || (arr->nbases > 0 && arr->p_bases == NULL)
        || arr->act_order > arr->trc_order || arr->size != arr->nrows * arr->ncols
        || !ssio_labels_sorted(arr->p_bases, arr->nbases)){
        return SSIO_ERR_ARGUMENT;
    }

    status = ssio_soa_bytes(arr->nbases, arr->trc_order, arr->nrows, arr->ncols, &payload);

    if (status != SSIO_OK){
        return SSIO_ERR_ARGUMENT;
    }

    nreal = (size_t)((payload - ssio_labels_bytes(arr->nbases)) / sizeof(coeff_t));

    if (nreal > 0 && arr->p_data == NULL){
        return SSIO_ERR_ARGUMENT;
    }

    file = fopen(filename, "wb");

    if (file == NULL){
        return SSIO_ERR_OPEN;
    }

    status = ssio_header_write(file, SSIO_TYPE_SOA, arr->trc_order, arr->act_order, arr->nbases,
        arr->nrows, arr->ncols, payload);

    if (status == SSIO_OK){
        status = ssio_labels_write(file, arr->p_bases, arr->nbases);
    }

    if (status == SSIO_OK){
        status = ssio_write(file, arr->p_data, nreal * sizeof(coeff_t));
    }

    if (fclose(file) != 0 && status == SSIO_OK){
        status = SSIO_ERR_IO;
    }

    if (status != SSIO_OK){
        remove(filename);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_read(const char* filename, oarrss_t* res){

    FILE* file;
    ssio_info_t info;
    uint64_t expected;
    bases_t* p_bases = NULL;
    bases_t k;
    oarrss_t arr;
    ndir_t nimag;
    int status;

    if (filename == NULL || res == NULL){
        return SSIO_ERR_ARGUMENT;
    }

    memset(&info, 0, sizeof(info));
    *res = oarrss_init();
    file = fopen(filename, "rb");

    if (file == NULL){
        return SSIO_ERR_OPEN;
    }

    status = ssio_header_read(file, &info);
    k      = (bases_t)info.nbases;

    if (status == SSIO_OK && info.type != SSIO_TYPE_SOA){
        status = SSIO_ERR_TYPE;
    }

    if (status == SSIO_OK){
        status = ssio_soa_bytes(k, info.trc_order, info.nrows, info.ncols, &expected);
    }

    if (status == SSIO_OK && expected != info.payload){
        status = SSIO_ERR_FORMAT;
    }

    if (status != SSIO_OK){

        fclose(file);
        return status;

    }

    // The payload size matches the file size, so these allocations are bounded by it.
    if (k > 0){

        p_bases = (bases_t*)malloc((size_t)k * sizeof(bases_t));

        if (p_bases == NULL){
            ssoti_out_of_memory();
        }

    }

    status = ssio_labels_read(file, p_bases, k);

    if (status != SSIO_OK){

        free(p_bases);
        fclose(file);
        return status;

    }

    arr = oarrss_zeros(p_bases, k, info.nrows, info.ncols, info.trc_order);
    free(p_bases);

    nimag  = sshelp_ndir_total(k, info.trc_order);
    status = ssio_read(file, arr.p_data, (size_t)(1 + nimag) * arr.size * sizeof(coeff_t));

    if (status == SSIO_OK && info.act_order < info.trc_order && arr.size > 0 && nimag > 0
        && !ssio_all_zero(arr.p_data,
               (1 + (uint64_t)sshelp_order_offset(k, (ord_t)(info.act_order + 1))) * arr.size,
               (1 + nimag) * arr.size)){
        status = SSIO_ERR_FORMAT;
    }

    fclose(file);

    if (status != SSIO_OK){

        oarrss_free(&arr);
        return status;

    }

    arr.act_order = info.act_order;
    *res = arr;

    return SSIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes of an AoS record: the 8-byte header plus a scalar's data.
static int ssio_aos_record_bytes(bases_t k, ord_t trc, uint64_t* p_bytes){

    int status = ssio_scalar_bytes(k, trc, p_bytes);

    *p_bytes += 8;

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arrss_save(const char* filename, const arrss_t* arr){

    FILE* file;
    uint64_t payload = 0, i, bytes;
    ord_t trc = 0, act = 0;
    int status = SSIO_OK;

    if (filename == NULL || arr == NULL || arr->size != arr->nrows * arr->ncols
        || (arr->size > 0 && arr->p_data == NULL)){
        return SSIO_ERR_ARGUMENT;
    }

    for (i = 0; i < arr->size; i++){

        const ssotinum_t* num = &arr->p_data[i];

        if ((num->nbases > 0 && num->p_bases == NULL)
            || (num->nbases > 0 && num->trc_order > 0 && num->p_im == NULL)
            || num->act_order > num->trc_order || !ssio_labels_sorted(num->p_bases, num->nbases)
            || ssio_aos_record_bytes(num->nbases, num->trc_order, &bytes) != SSIO_OK
            || bytes > UINT64_MAX - payload){
            return SSIO_ERR_ARGUMENT;
        }

        payload += bytes;
        trc = (num->trc_order > trc) ? num->trc_order : trc;
        act = (num->act_order > act) ? num->act_order : act;

    }

    file = fopen(filename, "wb");

    if (file == NULL){
        return SSIO_ERR_OPEN;
    }

    status = ssio_header_write(file, SSIO_TYPE_AOS, trc, act, 0, arr->nrows, arr->ncols, payload);

    for (i = 0; i < arr->size && status == SSIO_OK; i++){

        const ssotinum_t* num = &arr->p_data[i];
        uint8_t head[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        uint16_t k = (uint16_t)num->nbases;

        head[0] = num->trc_order;
        head[1] = num->act_order;
        memcpy(head + 2, &k, sizeof(k));

        status = ssio_write(file, head, sizeof(head));

        if (status == SSIO_OK){
            status = ssio_labels_write(file, num->p_bases, num->nbases);
        }

        if (status == SSIO_OK){
            status = ssio_write(file, &num->re, sizeof(coeff_t));
        }

        if (status == SSIO_OK){
            status = ssio_write(file, num->p_im,
                (size_t)sshelp_ndir_total(num->nbases, num->trc_order) * sizeof(coeff_t));
        }

    }

    if (fclose(file) != 0 && status == SSIO_OK){
        status = SSIO_ERR_IO;
    }

    if (status != SSIO_OK){
        remove(filename);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arrss_read(const char* filename, arrss_t* res){

    FILE* file;
    ssio_info_t info;
    arrss_t arr;
    uint64_t i, size, consumed = 0, bytes;
    int status;

    if (filename == NULL || res == NULL){
        return SSIO_ERR_ARGUMENT;
    }

    memset(&info, 0, sizeof(info));
    *res = arrss_init();
    file = fopen(filename, "rb");

    if (file == NULL){
        return SSIO_ERR_OPEN;
    }

    status = ssio_header_read(file, &info);

    if (status == SSIO_OK && info.type != SSIO_TYPE_AOS){
        status = SSIO_ERR_TYPE;
    }

    if (status == SSIO_OK
        && (info.nrows != 0 && info.ncols > UINT64_MAX / info.nrows)){
        status = SSIO_ERR_FORMAT;
    }

    size = info.nrows * info.ncols;

    // Every record takes at least 16 bytes (its header and the real part), which bounds the
    // number of elements, hence the allocation below, by the size of the file.
    if (status == SSIO_OK && (size > info.payload / 16 || (size == 0 && info.payload != 0))){
        status = SSIO_ERR_FORMAT;
    }

    if (status != SSIO_OK){

        fclose(file);
        return status;

    }

    arr = arrss_zeros(info.nrows, info.ncols, 0);

    for (i = 0; i < size && status == SSIO_OK; i++){

        uint8_t head[8];
        uint16_t k16;
        ord_t trc, act;
        bases_t k;
        ssotinum_t num;

        status = ssio_read(file, head, sizeof(head));

        if (status != SSIO_OK){
            break;
        }

        trc = head[0];
        act = head[1];
        memcpy(&k16, head + 2, sizeof(k16));
        k = (bases_t)k16;

        if (act > trc || ssio_aos_record_bytes(k, trc, &bytes) != SSIO_OK
            || bytes > info.payload - consumed){

            status = SSIO_ERR_FORMAT;
            break;

        }

        status = ssio_scalar_read(file, k, trc, act, &num);

        if (status != SSIO_OK){
            break;
        }

        ssoti_free(&arr.p_data[i]);
        arr.p_data[i] = num;
        consumed += bytes;

    }

    if (status == SSIO_OK && consumed != info.payload){
        status = SSIO_ERR_FORMAT;
    }

    fclose(file);

    if (status != SSIO_OK){

        arrss_free(&arr);
        return status;

    }

    *res = arr;

    return SSIO_OK;

}
// -------------------------------------------------------------------------------------------------------
