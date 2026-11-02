// Dense OTI numbers (PLAN-dense-update.md).
// Contents: save / read, magic 0x93 'O' 'T' 'D' (include/oti/dense/io/io.h).
//
// Owner: WP5 (dense-aux). Unity-included from src/c/dense.c, so every static helper here carries the
// dnis_ prefix (all dense sources share one translation unit).
//
// Template: src/c/semisparse/io/io.c without the base labels (a dense number is over bases 1..nact).
// Every size read from a file is validated against the size of the file before anything is
// allocated, so a corrupt header cannot ask for a huge allocation.

#include <sys/types.h>
#include <unistd.h>


// *******************************************************************************************************
const char* dnio_strerror(int status){

    switch (status){

        case DNIO_OK:            return "success";
        case DNIO_ERR_OPEN:      return "cannot open the file";
        case DNIO_ERR_IO:        return "read or write error";
        case DNIO_ERR_MAGIC:     return "not a dense OTI file (bad magic number)";
        case DNIO_ERR_VERSION:   return "unsupported dense file format version";
        case DNIO_ERR_TYPE:      return "the file holds another dense type";
        case DNIO_ERR_FORMAT:    return "corrupt dense file (inconsistent header or data)";
        case DNIO_ERR_TRUNCATED: return "truncated dense file";
        case DNIO_ERR_SIZE:      return "dense file is longer than its header says";
        case DNIO_ERR_ARGUMENT:  return "invalid argument (NULL pointer or unrepresentable object)";
        case DNIO_ERR_MEMORY:    return "out of memory while reading";
        default:                 return "unknown dense I/O status";

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Byte order flag of the host.
static int dnis_host_order(void){

    const uint16_t one = 1;

    return (*(const uint8_t*)&one == 1) ? DNIO_LITTLE_ENDIAN : DNIO_BIG_ENDIAN;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Maps a DN_* status of an inner call (oti_, oarr_, arro_) to the DNIO_* code that this file returns:
// the two families reuse -1, -2, so a status is never passed through.
static int dnis_map(int status){

    switch (status){

        case DN_OK:         return DNIO_OK;
        case DN_ERR_MEMORY: return DNIO_ERR_MEMORY;
        case DN_ERR_INDEX:  return DNIO_ERR_FORMAT;
        default:            return DNIO_ERR_ARGUMENT;

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Number of doubles in a block layout: (1 + N(k, trc)) blocks of `size` reals. A nonzero return is
// DNIO_ERR_FORMAT: the count overflows the index types or the byte count overflows size_t.
static int dnis_nreals(bases_t k, ord_t trc, uint64_t size, uint64_t* p_nreal){

    ndir_t nimag;
    uint64_t nblocks;

    if (trc > _MAXORDER_OTI || sshelp_ndir_total_checked(k, trc, &nimag) != SSHELP_OK){
        return DNIO_ERR_FORMAT;
    }

    nblocks = 1 + (uint64_t)nimag;

    if (size != 0 && nblocks > (SIZE_MAX / sizeof(coeff_t)) / size){
        return DNIO_ERR_FORMAT;
    }

    *p_nreal = nblocks * size;

    return DNIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes of a scalar's data (real part and order blocks) over k bases up to order trc.
static int dnis_scalar_bytes(bases_t k, ord_t trc, uint64_t* p_bytes){

    uint64_t nreal = 0;
    int status = dnis_nreals(k, trc, 1, &nreal);

    *p_bytes = nreal * sizeof(coeff_t);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes of a SoA array's payload: 1 + N(k, trc) blocks of nrows * ncols reals.
static int dnis_soa_bytes(bases_t k, ord_t trc, uint64_t nrows, uint64_t ncols, uint64_t* p_bytes){

    uint64_t nreal = 0;
    int status;

    *p_bytes = 0;

    if (nrows != 0 && ncols > UINT64_MAX / nrows){
        return DNIO_ERR_FORMAT;
    }

    status = dnis_nreals(k, trc, nrows * ncols, &nreal);

    *p_bytes = nreal * sizeof(coeff_t);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes of an AoS record: the 8-byte header plus a scalar's data.
static int dnis_aos_record_bytes(bases_t k, ord_t trc, uint64_t* p_bytes){

    int status = dnis_scalar_bytes(k, trc, p_bytes);

    if (status == DNIO_OK && *p_bytes > SIZE_MAX - 8){
        return DNIO_ERR_FORMAT;
    }

    *p_bytes += 8;

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// True when p[lo .. hi) is all zero.
static int dnis_all_zero(const coeff_t* p, uint64_t lo, uint64_t hi){

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
// Writes the 64-byte header.
static int dnis_header_write(FILE* file, int type, ord_t trc, ord_t act, uint32_t nact,
                             uint64_t nrows, uint64_t ncols, uint64_t payload){

    uint8_t head[DNIO_HEADER_BYTES];
    const char magic[4] = {(char)0x93, 'O', 'T', 'D'};
    const uint16_t version = DNIO_VERSION;

    memset(head, 0, sizeof(head));
    memcpy(head, magic, 4);
    memcpy(head + 4, &version, sizeof(version));

    head[6]  = (uint8_t)type;
    head[7]  = (uint8_t)dnis_host_order();
    head[8]  = (uint8_t)sizeof(coeff_t);
    head[10] = trc;
    head[11] = act;

    memcpy(head + 12, &nact, sizeof(nact));
    memcpy(head + 16, &nrows, sizeof(nrows));
    memcpy(head + 24, &ncols, sizeof(ncols));
    memcpy(head + 32, &payload, sizeof(payload));

    return (fwrite(head, 1, sizeof(head), file) == sizeof(head)) ? DNIO_OK : DNIO_ERR_IO;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Size of an open file in bytes; the position is left at the start.
static int dnis_file_bytes(FILE* file, uint64_t* p_bytes){

    off_t n;

    if (fseeko(file, 0, SEEK_END) != 0){
        return DNIO_ERR_IO;
    }

    n = ftello(file);

    if (n < 0 || fseeko(file, 0, SEEK_SET) != 0){
        return DNIO_ERR_IO;
    }

    *p_bytes = (uint64_t)n;

    return DNIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reads and validates the header of an open file (position at the start): magic, version, field
// sizes and ranges, that the payload size is the one the shape implies, and that the file size is
// header + payload. p_info is written only on success.
static int dnis_header_read(FILE* file, dnio_info_t* p_info){

    uint8_t head[DNIO_HEADER_BYTES];
    uint16_t version;
    uint64_t file_bytes, expected, size, i;
    size_t got;
    int status;
    dnio_info_t info;

    status = dnis_file_bytes(file, &file_bytes);

    if (status != DNIO_OK){
        return status;
    }

    got = fread(head, 1, sizeof(head), file);

    if (got < 4 || head[0] != 0x93 || head[1] != 'O' || head[2] != 'T' || head[3] != 'D'){
        return DNIO_ERR_MAGIC;
    }

    if (got < sizeof(head)){
        return DNIO_ERR_TRUNCATED;
    }

    // The byte order comes first: a foreign-endian file decodes every multi-byte field wrongly.
    if (head[7] != dnis_host_order()){
        return DNIO_ERR_FORMAT;
    }

    memcpy(&version, head + 4, sizeof(version));

    if (version > DNIO_VERSION){
        return DNIO_ERR_VERSION;
    }

    if (version != DNIO_VERSION){
        return DNIO_ERR_FORMAT;
    }

    info.version   = version;
    info.type      = head[6];
    info.trc_order = head[10];
    info.act_order = head[11];

    memcpy(&info.nact, head + 12, sizeof(info.nact));
    memcpy(&info.nrows, head + 16, sizeof(info.nrows));
    memcpy(&info.ncols, head + 24, sizeof(info.ncols));
    memcpy(&info.payload, head + 32, sizeof(info.payload));

    if (head[8] != sizeof(coeff_t) || head[9] != 0){
        return DNIO_ERR_FORMAT;
    }

    // Reserved bytes are zero.
    for (i = 40; i < DNIO_HEADER_BYTES; i++){

        if (head[i] != 0){
            return DNIO_ERR_FORMAT;
        }

    }

    if (info.type != DNIO_TYPE_SCALAR && info.type != DNIO_TYPE_AOS && info.type != DNIO_TYPE_SOA){
        return DNIO_ERR_FORMAT;
    }

    if (info.act_order > info.trc_order || info.trc_order > _MAXORDER_OTI
        || info.nact > (uint32_t)((bases_t)~(bases_t)0)){
        return DNIO_ERR_FORMAT;
    }

    if (info.payload > UINT64_MAX - DNIO_HEADER_BYTES){
        return DNIO_ERR_FORMAT;
    }

    if (info.type == DNIO_TYPE_SCALAR){

        if (info.nrows != 1 || info.ncols != 1
            || dnis_scalar_bytes((bases_t)info.nact, info.trc_order, &expected) != DNIO_OK
            || expected != info.payload){
            return DNIO_ERR_FORMAT;
        }

    } else if (info.type == DNIO_TYPE_SOA){

        if (dnis_soa_bytes((bases_t)info.nact, info.trc_order, info.nrows, info.ncols, &expected)
                != DNIO_OK || expected != info.payload){
            return DNIO_ERR_FORMAT;
        }

    } else {

        if (info.nrows != 0 && info.ncols > UINT64_MAX / info.nrows){
            return DNIO_ERR_FORMAT;
        }

        size = info.nrows * info.ncols;

        // Every record takes at least 16 bytes (its header and the real part), which bounds the
        // number of elements, hence the allocation in arro_read(), by the size of the file. An empty
        // array has nothing to be the maximum of.
        if (size > info.payload / 16
            || (size == 0 && (info.payload != 0 || info.trc_order != 0 || info.act_order != 0
                              || info.nact != 0))){
            return DNIO_ERR_FORMAT;
        }

    }

    if (file_bytes < DNIO_HEADER_BYTES + info.payload){
        return DNIO_ERR_TRUNCATED;
    }

    if (file_bytes > DNIO_HEADER_BYTES + info.payload){
        return DNIO_ERR_SIZE;
    }

    *p_info = info;

    return DNIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int dnio_peek(const char* filename, dnio_info_t* p_info){

    FILE* file;
    int status;

    if (filename == NULL || p_info == NULL){
        return DNIO_ERR_ARGUMENT;
    }

    file = fopen(filename, "rb");

    if (file == NULL){
        return DNIO_ERR_OPEN;
    }

    status = dnis_header_read(file, p_info);
    fclose(file);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes `n` bytes.
static int dnis_write(FILE* file, const void* p_src, size_t n){

    return (n == 0 || fwrite(p_src, 1, n, file) == n) ? DNIO_OK : DNIO_ERR_IO;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reads exactly `n` bytes.
static int dnis_read(FILE* file, void* p_dst, size_t n){

    if (n == 0 || fread(p_dst, 1, n, file) == n){
        return DNIO_OK;
    }

    return feof(file) ? DNIO_ERR_TRUNCATED : DNIO_ERR_IO;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Opens a temporary file <filename>.tmp.<pid>.<n> in the directory of the target for writing, so that a
// save is atomic: the target is only replaced (rename) once the whole file is written. *pp_tmp receives
// the malloc'd name of the temporary file (NULL on failure). Returns DNIO_OK, DNIO_ERR_MEMORY or
// DNIO_ERR_OPEN.
static int dnis_open_tmp(const char* filename, FILE** p_file, char** pp_tmp){

    static unsigned long counter = 0;
    size_t size = strlen(filename) + 64;
    unsigned long n = __atomic_fetch_add(&counter, 1, __ATOMIC_RELAXED);
    char* tmp = (char*)malloc(size);

    *p_file  = NULL;
    *pp_tmp  = NULL;

    if (tmp == NULL){
        return DNIO_ERR_MEMORY;
    }

    snprintf(tmp, size, "%s.tmp.%ld.%lu", filename, (long)getpid(), n);

    *p_file = fopen(tmp, "wb");

    if (*p_file == NULL){

        free(tmp);
        return DNIO_ERR_OPEN;

    }

    *pp_tmp = tmp;

    return DNIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Closes the temporary file of a save and, when everything was written, renames it over the target
// (an existing target is replaced only then). On any failure only the temporary file is removed, so an
// existing file of that name survives. Releases tmp; returns the final status (DNIO_ERR_OPEN when the
// target cannot be replaced, e.g. it is a directory).
static int dnis_finish_save(FILE* file, char* tmp, const char* filename, int status){

    if (fclose(file) != 0 && status == DNIO_OK){
        status = DNIO_ERR_IO;
    }

    if (status == DNIO_OK){

#ifdef _WIN32
        remove(filename);   // rename() does not replace an existing file there
#endif

        if (rename(tmp, filename) != 0){
            status = DNIO_ERR_OPEN;
        }

    }

    if (status != DNIO_OK){
        remove(tmp);
    }

    free(tmp);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks that a scalar can be written (a layout the format represents, coefficients above the active
// order zero, so that the file reads back) and returns its data bytes. A nonzero return is
// DNIO_ERR_ARGUMENT.
static int dnis_scalar_check(const otinum_t* num, uint64_t* p_bytes){

    ndir_t nimag;

    if (num->act_order > num->trc_order || dnis_scalar_bytes(num->nact, num->trc_order, p_bytes)
            != DNIO_OK){
        return DNIO_ERR_ARGUMENT;
    }

    nimag = sshelp_ndir_total(num->nact, num->trc_order);

    if (nimag > 0 && num->p_im == NULL){
        return DNIO_ERR_ARGUMENT;
    }

    if (num->act_order < num->trc_order && nimag > 0
        && !dnis_all_zero(num->p_im, sshelp_order_offset(num->nact, (ord_t)(num->act_order + 1)),
                          nimag)){
        return DNIO_ERR_ARGUMENT;
    }

    return DNIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes a scalar's data: the real part, then the order blocks.
static int dnis_scalar_write(FILE* file, const otinum_t* num){

    int status = dnis_write(file, &num->re, sizeof(coeff_t));

    if (status == DNIO_OK){
        status = dnis_write(file, num->p_im,
            (size_t)sshelp_ndir_total(num->nact, num->trc_order) * sizeof(coeff_t));
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reads a scalar's data into `num` (a valid number, its buffer is reused) over k bases up to order
// trc. The orders above `act` must be zero. On failure num is left valid.
static int dnis_scalar_read(FILE* file, bases_t k, ord_t trc, ord_t act, otinum_t* num){

    ndir_t nimag;
    int status = dnis_map(oti_create_empty_to(k, trc, num));

    if (status != DNIO_OK){
        return status;
    }

    nimag  = sshelp_ndir_total(k, trc);
    status = dnis_read(file, &num->re, sizeof(coeff_t));

    if (status == DNIO_OK){
        status = dnis_read(file, num->p_im, (size_t)nimag * sizeof(coeff_t));
    }

    if (status == DNIO_OK && act < trc && nimag > 0
        && !dnis_all_zero(num->p_im, sshelp_order_offset(k, (ord_t)(act + 1)), nimag)){
        status = DNIO_ERR_FORMAT;
    }

    if (status == DNIO_OK){
        num->act_order = act;
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_save(const char* filename, const otinum_t* num){

    FILE* file;
    char* tmp;
    uint64_t payload;
    int status;

    if (filename == NULL || num == NULL || dnis_scalar_check(num, &payload) != DNIO_OK){
        return DNIO_ERR_ARGUMENT;
    }

    status = dnis_open_tmp(filename, &file, &tmp);

    if (status != DNIO_OK){
        return status;
    }

    status = dnis_header_write(file, DNIO_TYPE_SCALAR, num->trc_order, num->act_order, num->nact, 1, 1,
        payload);

    if (status == DNIO_OK){
        status = dnis_scalar_write(file, num);
    }

    return dnis_finish_save(file, tmp, filename, status);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_read(const char* filename, otinum_t* res){

    FILE* file;
    dnio_info_t info;
    otinum_t num = oti_init();
    int status;

    if (res == NULL){
        return DNIO_ERR_ARGUMENT;
    }

    *res = oti_init();

    if (filename == NULL){
        return DNIO_ERR_ARGUMENT;
    }

    file = fopen(filename, "rb");

    if (file == NULL){
        return DNIO_ERR_OPEN;
    }

    status = dnis_header_read(file, &info);

    if (status == DNIO_OK && info.type != DNIO_TYPE_SCALAR){
        status = DNIO_ERR_TYPE;
    }

    // The header check made the payload size equal to the file size, so the allocation is bounded.
    if (status == DNIO_OK){
        status = dnis_scalar_read(file, (bases_t)info.nact, info.trc_order, info.act_order, &num);
    }

    fclose(file);

    if (status != DNIO_OK){

        oti_free(&num);
        return status;

    }

    *res = num;

    return DNIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_save(const char* filename, const oarr_t* arr){

    FILE* file;
    char* tmp;
    uint64_t payload = 0, nreal;
    int status;

    if (filename == NULL || arr == NULL || arr->act_order > arr->trc_order
        || (arr->nrows != 0 && arr->ncols > UINT64_MAX / arr->nrows)
        || arr->size != arr->nrows * arr->ncols
        || dnis_soa_bytes(arr->nact, arr->trc_order, arr->nrows, arr->ncols, &payload) != DNIO_OK){
        return DNIO_ERR_ARGUMENT;
    }

    nreal = payload / sizeof(coeff_t);

    if (nreal > 0 && arr->p_data == NULL){
        return DNIO_ERR_ARGUMENT;
    }

    // Blocks above the active order must be zero, or the file would not read back.
    if (arr->act_order < arr->trc_order && nreal > 0
        && !dnis_all_zero(arr->p_data,
               (1 + (uint64_t)sshelp_order_offset(arr->nact, (ord_t)(arr->act_order + 1))) * arr->size,
               nreal)){
        return DNIO_ERR_ARGUMENT;
    }

    status = dnis_open_tmp(filename, &file, &tmp);

    if (status != DNIO_OK){
        return status;
    }

    status = dnis_header_write(file, DNIO_TYPE_SOA, arr->trc_order, arr->act_order, arr->nact,
        arr->nrows, arr->ncols, payload);

    if (status == DNIO_OK){
        status = dnis_write(file, arr->p_data, (size_t)nreal * sizeof(coeff_t));
    }

    return dnis_finish_save(file, tmp, filename, status);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_read(const char* filename, oarr_t* res){

    FILE* file;
    dnio_info_t info;
    oarr_t arr = oarr_init();
    uint64_t nreal;
    bases_t k;
    int status;

    if (res == NULL){
        return DNIO_ERR_ARGUMENT;
    }

    *res = oarr_init();

    if (filename == NULL){
        return DNIO_ERR_ARGUMENT;
    }

    file = fopen(filename, "rb");

    if (file == NULL){
        return DNIO_ERR_OPEN;
    }

    status = dnis_header_read(file, &info);
    k      = 0;

    if (status == DNIO_OK && info.type != DNIO_TYPE_SOA){
        status = DNIO_ERR_TYPE;
    }

    if (status == DNIO_OK){
        k = (bases_t)info.nact;
    }

    // The header check made the payload size equal to the file size, so the allocation is bounded.
    if (status == DNIO_OK){
        status = dnis_map(oarr_zeros_to(k, info.nrows, info.ncols, info.trc_order, &arr));
    }

    if (status == DNIO_OK){

        nreal  = (uint64_t)(1 + sshelp_ndir_total(k, info.trc_order)) * arr.size;
        status = dnis_read(file, arr.p_data, (size_t)nreal * sizeof(coeff_t));

        if (status == DNIO_OK && info.act_order < info.trc_order && nreal > 0
            && !dnis_all_zero(arr.p_data,
                   (1 + (uint64_t)sshelp_order_offset(k, (ord_t)(info.act_order + 1))) * arr.size,
                   nreal)){
            status = DNIO_ERR_FORMAT;
        }

    }

    fclose(file);

    if (status != DNIO_OK){

        oarr_free(&arr);
        return status;

    }

    arr.act_order = info.act_order;
    *res          = arr;

    return DNIO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_save(const char* filename, const arro_t* arr){

    FILE* file;
    char* tmp;
    uint64_t payload = 0, i, bytes;
    ord_t trc = 0, act = 0;
    bases_t nact = 0;
    int status = DNIO_OK;

    if (filename == NULL || arr == NULL || (arr->nrows != 0 && arr->ncols > UINT64_MAX / arr->nrows)
        || arr->size != arr->nrows * arr->ncols || (arr->size > 0 && arr->p_data == NULL)){
        return DNIO_ERR_ARGUMENT;
    }

    // Validate every element and gather the payload size and the maxima for the header.
    for (i = 0; i < arr->size; i++){

        const otinum_t* num = &arr->p_data[i];

        if (dnis_scalar_check(num, &bytes) != DNIO_OK || bytes > UINT64_MAX - 8 - payload){
            return DNIO_ERR_ARGUMENT;
        }

        payload += bytes + 8;
        trc      = (num->trc_order > trc) ? num->trc_order : trc;
        act      = (num->act_order > act) ? num->act_order : act;
        nact     = (num->nact > nact) ? num->nact : nact;

    }

    status = dnis_open_tmp(filename, &file, &tmp);

    if (status != DNIO_OK){
        return status;
    }

    status = dnis_header_write(file, DNIO_TYPE_AOS, trc, act, nact, arr->nrows, arr->ncols, payload);

    for (i = 0; i < arr->size && status == DNIO_OK; i++){

        const otinum_t* num = &arr->p_data[i];
        uint8_t head[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        uint16_t k = (uint16_t)num->nact;

        head[0] = num->trc_order;
        head[1] = num->act_order;
        memcpy(head + 2, &k, sizeof(k));

        status = dnis_write(file, head, sizeof(head));

        if (status == DNIO_OK){
            status = dnis_scalar_write(file, num);
        }

    }

    return dnis_finish_save(file, tmp, filename, status);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_read(const char* filename, arro_t* res){

    FILE* file;
    dnio_info_t info;
    arro_t arr = arro_init();
    uint64_t i, size, consumed = 0, bytes;
    ord_t max_trc = 0, max_act = 0;
    bases_t max_nact = 0;
    int status;

    if (res == NULL){
        return DNIO_ERR_ARGUMENT;
    }

    *res = arro_init();

    if (filename == NULL){
        return DNIO_ERR_ARGUMENT;
    }

    file = fopen(filename, "rb");

    if (file == NULL){
        return DNIO_ERR_OPEN;
    }

    status = dnis_header_read(file, &info);

    if (status == DNIO_OK && info.type != DNIO_TYPE_AOS){
        status = DNIO_ERR_TYPE;
    }

    // The header check bounded the number of elements by the payload size (16 bytes per record at
    // least), so this allocation is bounded by the size of the file.
    if (status == DNIO_OK){
        status = dnis_map(arro_zeros_to(info.nrows, info.ncols, 0, &arr));
    }

    size = arr.size;

    for (i = 0; i < size && status == DNIO_OK; i++){

        uint8_t head[8];
        uint16_t k16;
        ord_t trc, act;
        bases_t k;

        // A record needs at least 16 bytes: fewer left means the shape claims more elements than
        // the payload holds (the file itself is complete, so this is not a truncation).
        if (info.payload - consumed < 16){

            status = DNIO_ERR_FORMAT;
            break;

        }

        status = dnis_read(file, head, sizeof(head));

        if (status != DNIO_OK){
            break;
        }

        trc = head[0];
        act = head[1];
        memcpy(&k16, head + 2, sizeof(k16));
        k = (bases_t)k16;

        // The record must fit in what is left of the payload and respect the maxima of the header;
        // its four last header bytes are zero.
        if (act > trc || trc > info.trc_order || act > info.act_order || k > info.nact
            || head[4] != 0 || head[5] != 0 || head[6] != 0 || head[7] != 0
            || dnis_aos_record_bytes(k, trc, &bytes) != DNIO_OK || bytes > info.payload - consumed){

            status = DNIO_ERR_FORMAT;
            break;

        }

        status = dnis_scalar_read(file, k, trc, act, &arr.p_data[i]);

        if (status != DNIO_OK){
            break;
        }

        consumed += bytes;
        max_trc   = (trc > max_trc) ? trc : max_trc;
        max_act   = (act > max_act) ? act : max_act;
        max_nact  = (k > max_nact) ? k : max_nact;

    }

    // The payload is exactly the records, and the header holds their maxima.
    if (status == DNIO_OK
        && (consumed != info.payload || max_trc != info.trc_order || max_act != info.act_order
            || max_nact != info.nact)){
        status = DNIO_ERR_FORMAT;
    }

    fclose(file);

    if (status != DNIO_OK){

        arro_free(&arr);
        return status;

    }

    *res = arr;

    return DNIO_OK;

}
// -------------------------------------------------------------------------------------------------------
