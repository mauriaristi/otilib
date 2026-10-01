/* Independent checks of dense save / read (include/oti/dense/io/io.h, PLAN-dense-update.md, WP5):
 * bit-exact round trips of scalars, SoA and AoS arrays through {oti,oarr,arro}_save() / _read()
 * (nact 0, 1, 3, 11, orders 0..5 and 150, act_order below trc, AoS elements with different nact,
 * trc and act, 0 x 0 and 1 x n arrays, NaN / inf / -0.0 coefficients), the byte layout of the file,
 * the header reported by dnio_peek(), the status of every kind of bad file (missing, empty, wrong
 * magic including real semi-sparse and sparse files, another type, truncated at many points,
 * trailing bytes, bad version, byte order, coefficient size, reserved bytes, order fields, a
 * nonzero coefficient above the active order, payload / shape mismatches, sizes claimed by the
 * header that the file cannot back, corrupt AoS records), the objects save refuses, and a
 * cross-check that a file written from a sparse (sotinum_t / arrso_t) value reads back to that
 * value. Nothing here may call exit(); all scratch files live in a temporary directory that the
 * test removes. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <sys/resource.h>
#include <oti/oti.h>
#include <oti/semisparse.h>
#include <oti/dense.h>

static int n_failed = 0;
static int n_passed = 0;
static int g_verbose = 0;

static uint64_t g_rng_state = 0x5EED5EED12345678ULL;

/// Relative tolerance against the sparse oracle (plan section 6).
#define TOL_ORACLE 1e-13

static char g_dir[512];
static char g_path[600];


// *******************************************************************************************************
static void check(int cond, const char* name){

    if (!cond){

        fprintf(stderr, "FAILED: %s\n", name);
        n_failed++;

    } else {

        n_passed++;

        if (g_verbose){
            printf("passed: %s\n", name);
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A value in (-2, 2), never exactly zero.
static coeff_t rng_value(void){

    g_rng_state = g_rng_state * 6364136223846793005ULL + 1442695040888963407ULL;

    return ((double)(g_rng_state >> 11) / 9007199254740992.0) * 4.0 - 2.0 + 1e-3;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double rng_range(double lo, double hi){

    return lo + (hi - lo) * (rng_value() + 2.0) / 4.0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int approx_equal(coeff_t a, coeff_t b, double tol){

    double diff = fabs(a - b);
    double scale = fmax(1.0, fmax(fabs(a), fabs(b)));

    return diff <= tol * scale;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Scratch directory, removed by the test at the end.
static void make_scratch_dir(void){

    const char* base = getenv("TMPDIR");

    if (base == NULL || base[0] == '\0'){
        base = "/tmp";
    }

    snprintf(g_dir, sizeof(g_dir), "%s/oti_dense_io_XXXXXX", base);

    if (mkdtemp(g_dir) == NULL){

        fprintf(stderr, "test harness: cannot create a temporary directory under %s\n", base);
        exit(2);

    }

    snprintf(g_path, sizeof(g_path), "%s/f.bin", g_dir);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void remove_scratch_dir(void){

    remove(g_path);
    rmdir(g_dir);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// --------------------------------------     BUILDING OBJECTS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Random coefficients in the real part and in orders 1..act (zeros above); act_order = act.
static void fill_scalar(otinum_t* num, ord_t act){

    ord_t p;
    ndir_t j;

    if (act > num->trc_order){
        act = num->trc_order;
    }

    num->re = rng_value();

    for (p = 1; p <= act; p++){

        ndir_t off = sshelp_order_offset(num->nact, p), n = sshelp_ndir_order(num->nact, p);

        for (j = 0; j < n; j++){
            num->p_im[off + j] = rng_value();
        }

    }

    num->act_order = act;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static otinum_t make_scalar(bases_t k, ord_t trc, ord_t act){

    otinum_t num = oti_create_empty(k, trc);

    fill_scalar(&num, act);

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static oarr_t make_soa(bases_t k, uint64_t nrows, uint64_t ncols, ord_t trc, ord_t act){

    oarr_t arr = oarr_init();
    uint64_t i, n, lim;

    if (oarr_zeros_to(k, nrows, ncols, trc, &arr) != DN_OK){
        fprintf(stderr, "test harness: oarr_zeros_to failed\n");
        exit(2);
    }

    n   = (1 + (uint64_t)sshelp_ndir_total(k, trc)) * arr.size;
    lim = (act >= trc) ? n : (1 + (uint64_t)sshelp_order_offset(k, (ord_t)(act + 1))) * arr.size;

    for (i = 0; i < lim; i++){
        arr.p_data[i] = rng_value();
    }

    arr.act_order = (act < trc) ? act : trc;

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// An array whose elements have different nact, truncation and active orders.
static arro_t make_aos(uint64_t nrows, uint64_t ncols){

    static const bases_t KS[6] = { 0, 1, 3, 11, 2, 5 };
    arro_t arr = arro_init();
    uint64_t i;

    if (arro_zeros_to(nrows, ncols, 0, &arr) != DN_OK){
        fprintf(stderr, "test harness: arro_zeros_to failed\n");
        exit(2);
    }

    for (i = 0; i < arr.size; i++){

        ord_t trc = (ord_t)(i % 6);
        ord_t act = (ord_t)((i * 5 + 1) % (trc + 1));

        if (oti_create_empty_to(KS[(i * 7) % 6], trc, &arr.p_data[i]) != DN_OK){
            fprintf(stderr, "test harness: oti_create_empty_to failed\n");
            exit(2);
        }

        fill_scalar(&arr.p_data[i], act);

    }

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bit-exact equality (shape, orders, every coefficient up to trc).
static int same_scalar(const otinum_t* a, const otinum_t* b){

    ndir_t nimag;

    if (a->nact != b->nact || a->trc_order != b->trc_order || a->act_order != b->act_order
        || memcmp(&a->re, &b->re, sizeof(coeff_t)) != 0){
        return 0;
    }

    nimag = sshelp_ndir_total(a->nact, a->trc_order);

    return nimag == 0 || memcmp(a->p_im, b->p_im, nimag * sizeof(coeff_t)) == 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int same_soa(const oarr_t* a, const oarr_t* b){

    size_t nreal;

    if (a->nact != b->nact || a->trc_order != b->trc_order || a->act_order != b->act_order
        || a->nrows != b->nrows || a->ncols != b->ncols || a->size != b->size){
        return 0;
    }

    nreal = (size_t)(1 + sshelp_ndir_total(a->nact, a->trc_order)) * a->size;

    return nreal == 0 || memcmp(a->p_data, b->p_data, nreal * sizeof(coeff_t)) == 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int same_aos(const arro_t* a, const arro_t* b){

    uint64_t i;

    if (a->nrows != b->nrows || a->ncols != b->ncols || a->size != b->size){
        return 0;
    }

    for (i = 0; i < a->size; i++){

        if (!same_scalar(&a->p_data[i], &b->p_data[i])){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int host_order(void){

    const uint16_t one = 1;

    return (*(const uint8_t*)&one == 1) ? DNIO_LITTLE_ENDIAN : DNIO_BIG_ENDIAN;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The values oti_init() / oarr_init() / arro_init() give (what a failed read must leave in res).
static int is_init_scalar(const otinum_t* n){

    return n->p_im == NULL && n->nact == 0 && n->nbases == 0 && n->trc_order == 0
        && n->act_order == 0 && n->re == 0.0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int is_init_soa(const oarr_t* o){

    return o->p_data == NULL && o->nact == 0 && o->nbases == 0 && o->trc_order == 0
        && o->act_order == 0 && o->nrows == 0 && o->ncols == 0 && o->size == 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int is_init_aos(const arro_t* a){

    return a->p_data == NULL && a->nrows == 0 && a->ncols == 0 && a->size == 0;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------     FILE HELPERS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Whole file into a malloc'd buffer.
static uint8_t* slurp(const char* path, size_t* p_n){

    FILE* f = fopen(path, "rb");
    uint8_t* buf;

    if (f == NULL){
        fprintf(stderr, "test harness: cannot open %s\n", path);
        exit(2);
    }

    fseek(f, 0, SEEK_END);
    *p_n = (size_t)ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = (uint8_t*)malloc(*p_n + 1);

    if (fread(buf, 1, *p_n, f) != *p_n){
        fprintf(stderr, "test harness: cannot read %s\n", path);
    }

    fclose(f);

    return buf;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void spit(const char* path, const uint8_t* buf, size_t n){

    FILE* f = fopen(path, "wb");

    if (f == NULL){
        fprintf(stderr, "test harness: cannot write %s\n", path);
        exit(2);
    }

    if (n > 0 && fwrite(buf, 1, n, f) != n){
        fprintf(stderr, "test harness: cannot write %s\n", path);
    }

    fclose(f);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int file_exists(const char* path){

    FILE* f = fopen(path, "rb");

    if (f != NULL){
        fclose(f);
    }

    return f != NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Stores the low `len` (1, 2, 4 or 8) bytes of `v` at buf[off], in host order.
static void poke(uint8_t* buf, size_t off, size_t len, uint64_t v){

    uint8_t v8 = (uint8_t)v;
    uint16_t v16 = (uint16_t)v;
    uint32_t v32 = (uint32_t)v;

    switch (len){

        case 1:  memcpy(buf + off, &v8, 1);  break;
        case 2:  memcpy(buf + off, &v16, 2); break;
        case 4:  memcpy(buf + off, &v32, 4); break;
        default: memcpy(buf + off, &v, 8);   break;

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static uint64_t peek_u64(const uint8_t* buf, size_t off){

    uint64_t v;

    memcpy(&v, buf + off, sizeof(v));

    return v;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Status of reading the file with each of the three readers, in order scalar, AoS, SoA. Every
// result is poisoned first, and a failed read must leave the init value in it.
static void read_all(const char* path, int st[3]){

    otinum_t s = oti_create_r(7.0, 3);
    arro_t a = arro_init();
    oarr_t o = oarr_init();

    a.nrows = 2; a.ncols = 2; a.size = 4;
    o.nrows = 2; o.ncols = 2; o.size = 4; o.nact = 3; o.trc_order = 2;

    st[0] = oti_read(path, &s);
    st[1] = arro_read(path, &a);
    st[2] = oarr_read(path, &o);

    if (st[0] == DNIO_OK){
        oti_free(&s);
    } else {
        check(is_init_scalar(&s), "failed oti_read leaves init");
    }

    if (st[1] == DNIO_OK){
        arro_free(&a);
    } else {
        check(is_init_aos(&a), "failed arro_read leaves init");
    }

    if (st[2] == DNIO_OK){
        oarr_free(&o);
    } else {
        check(is_init_soa(&o), "failed oarr_read leaves init");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reader of one kind (DNIO_TYPE_*) on `path`; the status, with the result freed.
static int read_kind(const char* path, int kind){

    int st[3];

    read_all(path, st);

    return st[kind - 1];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The three reader statuses against the expected ones.
static void check3(const int st[3], int e0, int e1, int e2, const char* name){

    char full[160];

    snprintf(full, sizeof(full), "%s [%d %d %d, want %d %d %d]", name, st[0], st[1], st[2], e0, e1, e2);
    check(st[0] == e0 && st[1] == e1 && st[2] == e2, full);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -----------------------------------------     ROUND TRIPS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Saves, reads back and compares one scalar; also peeks and checks the file size.
static void roundtrip_scalar(bases_t k, ord_t trc, ord_t act){

    otinum_t num = make_scalar(k, trc, act);
    otinum_t back = oti_init();
    dnio_info_t info;
    uint64_t expect;
    size_t n;
    uint8_t* buf;
    char name[96];

    snprintf(name, sizeof(name), "scalar k=%u trc=%u act=%u", (unsigned)k, (unsigned)trc,
        (unsigned)act);

    expect = 8 * (1 + (uint64_t)sshelp_ndir_total(k, trc));

    check(oti_save(g_path, &num) == DNIO_OK, name);
    check(oti_read(g_path, &back) == DNIO_OK && same_scalar(&num, &back), name);
    check(dnio_peek(g_path, &info) == DNIO_OK && info.type == DNIO_TYPE_SCALAR
        && info.version == DNIO_VERSION && info.trc_order == trc && info.act_order == num.act_order
        && info.nact == k && info.nrows == 1 && info.ncols == 1 && info.payload == expect, name);

    buf = slurp(g_path, &n);
    check(n == DNIO_HEADER_BYTES + expect, name);
    free(buf);

    oti_free(&back);
    oti_free(&num);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_scalar_roundtrip(void){

    static const bases_t KS[4] = { 0, 1, 3, 11 };
    size_t ik;
    ord_t trc;

    for (ik = 0; ik < 4; ik++){

        for (trc = 0; trc <= 5; trc++){

            roundtrip_scalar(KS[ik], trc, trc);
            roundtrip_scalar(KS[ik], trc, 0);

            if (trc >= 2){
                roundtrip_scalar(KS[ik], trc, (ord_t)(trc - 1));
            }

        }

    }

    // Larger layouts: the maximum order, and many bases.
    roundtrip_scalar(1, _MAXORDER_OTI, _MAXORDER_OTI);
    roundtrip_scalar(1, _MAXORDER_OTI, 3);
    roundtrip_scalar(2, _MAXORDER_OTI, _MAXORDER_OTI);
    roundtrip_scalar(200, 2, 2);
    roundtrip_scalar(65535, 1, 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void roundtrip_soa(bases_t k, uint64_t nrows, uint64_t ncols, ord_t trc, ord_t act){

    oarr_t arr = make_soa(k, nrows, ncols, trc, act);
    oarr_t back = oarr_init();
    dnio_info_t info;
    uint64_t expect;
    char name[112];

    snprintf(name, sizeof(name), "SoA %llux%llu k=%u trc=%u act=%u", (unsigned long long)nrows,
        (unsigned long long)ncols, (unsigned)k, (unsigned)trc, (unsigned)act);

    expect = 8 * (1 + (uint64_t)sshelp_ndir_total(k, trc)) * arr.size;

    check(oarr_save(g_path, &arr) == DNIO_OK, name);
    check(oarr_read(g_path, &back) == DNIO_OK && same_soa(&arr, &back), name);
    check(dnio_peek(g_path, &info) == DNIO_OK && info.type == DNIO_TYPE_SOA
        && info.trc_order == trc && info.act_order == arr.act_order && info.nact == k
        && info.nrows == nrows && info.ncols == ncols && info.payload == expect, name);

    oarr_free(&back);
    oarr_free(&arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_soa_roundtrip(void){

    static const bases_t KS[4] = { 0, 1, 3, 11 };
    static const struct { uint64_t nr, nc; } SHAPES[] = {
        {0, 0}, {0, 4}, {4, 0}, {1, 1}, {1, 5}, {5, 1}, {3, 2}, {4, 4},
    };
    size_t ik, is;
    ord_t trc;

    for (ik = 0; ik < 4; ik++){

        for (is = 0; is < sizeof(SHAPES) / sizeof(SHAPES[0]); is++){

            for (trc = 0; trc <= 5; trc += (ord_t)((KS[ik] > 3 || SHAPES[is].nr * SHAPES[is].nc > 4)
                                                  ? 2 : 1)){

                roundtrip_soa(KS[ik], SHAPES[is].nr, SHAPES[is].nc, trc, trc);

                if (trc >= 2){
                    roundtrip_soa(KS[ik], SHAPES[is].nr, SHAPES[is].nc, trc, (ord_t)(trc - 1));
                }

                if (trc >= 1){
                    roundtrip_soa(KS[ik], SHAPES[is].nr, SHAPES[is].nc, trc, 0);
                }

            }

        }

    }

    roundtrip_soa(2, 2, 2, _MAXORDER_OTI, _MAXORDER_OTI);
    roundtrip_soa(30, 2, 3, 3, 2);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void roundtrip_aos(uint64_t nrows, uint64_t ncols){

    arro_t arr = make_aos(nrows, ncols);
    arro_t back = arro_init();
    dnio_info_t info;
    ord_t trc = 0, act = 0;
    bases_t nact = 0;
    uint64_t i, payload = 0;
    char name[64];

    snprintf(name, sizeof(name), "AoS %llux%llu", (unsigned long long)nrows,
        (unsigned long long)ncols);

    for (i = 0; i < arr.size; i++){

        const otinum_t* e = &arr.p_data[i];

        trc     = (e->trc_order > trc) ? e->trc_order : trc;
        act     = (e->act_order > act) ? e->act_order : act;
        nact    = (e->nact > nact) ? e->nact : nact;
        payload += 8 + 8 * (1 + (uint64_t)sshelp_ndir_total(e->nact, e->trc_order));

    }

    check(arro_save(g_path, &arr) == DNIO_OK, name);
    check(arro_read(g_path, &back) == DNIO_OK && same_aos(&arr, &back), name);
    check(dnio_peek(g_path, &info) == DNIO_OK && info.type == DNIO_TYPE_AOS
        && info.trc_order == trc && info.act_order == act && info.nact == nact
        && info.nrows == nrows && info.ncols == ncols && info.payload == payload, name);

    arro_free(&back);
    arro_free(&arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_aos_roundtrip(void){

    static const struct { uint64_t nr, nc; } SHAPES[] = {
        {0, 0}, {0, 3}, {3, 0}, {1, 1}, {1, 5}, {5, 1}, {3, 2}, {4, 4}, {6, 6}, {1, 60},
    };
    size_t is;

    for (is = 0; is < sizeof(SHAPES) / sizeof(SHAPES[0]); is++){
        roundtrip_aos(SHAPES[is].nr, SHAPES[is].nc);
    }

    // Every element with the same layout, and a single element at the maximum order.
    {
        arro_t arr = arro_init(), back = arro_init();
        uint64_t i;

        check(arro_zeros_to(2, 3, 0, &arr) == DN_OK, "AoS uniform: zeros");

        for (i = 0; i < arr.size; i++){

            check(oti_create_empty_to(3, 4, &arr.p_data[i]) == DN_OK, "AoS uniform: element");
            fill_scalar(&arr.p_data[i], 4);

        }

        check(arro_save(g_path, &arr) == DNIO_OK && arro_read(g_path, &back) == DNIO_OK
            && same_aos(&arr, &back), "AoS with equal elements");

        arro_free(&back);
        arro_free(&arr);

        check(arro_zeros_to(1, 1, 0, &arr) == DN_OK
            && oti_create_empty_to(1, _MAXORDER_OTI, &arr.p_data[0]) == DN_OK, "AoS max order: build");
        fill_scalar(&arr.p_data[0], _MAXORDER_OTI);
        check(arro_save(g_path, &arr) == DNIO_OK && arro_read(g_path, &back) == DNIO_OK
            && same_aos(&arr, &back), "AoS element at the maximum order");

        arro_free(&back);
        arro_free(&arr);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// NaN, infinities and -0.0 survive bit for bit, in the real part and in every order.
static void test_special_values(void){

    otinum_t num = make_scalar(3, 3, 3), back = oti_init();
    oarr_t soa = make_soa(2, 2, 2, 2, 2), sback = oarr_init();

    num.re = NAN;
    num.p_im[0] = -0.0;
    num.p_im[1] = INFINITY;
    num.p_im[2] = -INFINITY;
    num.p_im[sshelp_order_offset(3, 3)] = 5e-324;

    check(oti_save(g_path, &num) == DNIO_OK && oti_read(g_path, &back) == DNIO_OK
        && same_scalar(&num, &back), "scalar with NaN, inf, -0.0 and a denormal");

    soa.p_data[0] = NAN;
    soa.p_data[5] = -0.0;
    soa.p_data[9] = INFINITY;

    check(oarr_save(g_path, &soa) == DNIO_OK && oarr_read(g_path, &sback) == DNIO_OK
        && same_soa(&soa, &sback), "SoA with NaN, inf and -0.0");

    oti_free(&back);
    oti_free(&num);
    oarr_free(&sback);
    oarr_free(&soa);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// An active base whose coefficients are all zero stays active through a round trip.
static void test_zero_bases_kept(void){

    otinum_t num = oti_create_empty(3, 2), back = oti_init();
    oarr_t arr = oarr_init(), aback = oarr_init();

    check(oti_save(g_path, &num) == DNIO_OK && oti_read(g_path, &back) == DNIO_OK
        && back.nact == 3 && back.trc_order == 2 && same_scalar(&num, &back),
        "zero scalar keeps its bases");

    check(oarr_zeros_to(3, 2, 2, 2, &arr) == DN_OK && oarr_save(g_path, &arr) == DNIO_OK
        && oarr_read(g_path, &aback) == DNIO_OK && aback.nact == 3 && same_soa(&arr, &aback),
        "zero SoA keeps its bases");

    oti_free(&back);
    oti_free(&num);
    oarr_free(&aback);
    oarr_free(&arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Saving over an existing file replaces it entirely, and a read overwrites its result without
// freeing what it held.
static void test_overwrite(void){

    oarr_t big = make_soa(2, 5, 5, 4, 4), small = make_soa(2, 1, 1, 1, 1), back = oarr_init();
    otinum_t old = make_scalar(2, 2, 2), num = make_scalar(3, 3, 3), res;
    otinum_t keep;

    check(oarr_save(g_path, &big) == DNIO_OK && oarr_save(g_path, &small) == DNIO_OK
        && oarr_read(g_path, &back) == DNIO_OK && same_soa(&small, &back),
        "saving over an existing file replaces it");

    res  = old;
    keep = old;

    check(oti_save(g_path, &num) == DNIO_OK && oti_read(g_path, &res) == DNIO_OK
        && same_scalar(&num, &res) && res.p_im != keep.p_im, "oti_read overwrites res");

    oti_free(&res);
    oti_free(&keep);
    oti_free(&num);
    oarr_free(&back);
    oarr_free(&small);
    oarr_free(&big);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -----------------------------------------     FILE LAYOUT     -----------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The header and the payload byte by byte, and that capacity slack is not written.
static void test_scalar_layout(void){

    otinum_t num = make_scalar(2, 2, 2);
    otinum_t back = oti_init();
    uint8_t* buf;
    size_t n, i;
    int ok = 1;
    const uint8_t host = (uint8_t)host_order();

    check(oti_save(g_path, &num) == DNIO_OK, "layout: save scalar");

    buf = slurp(g_path, &n);

    check(n == 64 + 8 * (1 + 2 + 3), "layout: scalar file size");
    check(buf[0] == 0x93 && buf[1] == 'O' && buf[2] == 'T' && buf[3] == 'D', "layout: magic");
    check(buf[4] == DNIO_VERSION && buf[5] == 0, "layout: version");
    check(buf[6] == DNIO_TYPE_SCALAR && buf[7] == host && buf[8] == 8 && buf[9] == 0,
        "layout: type, byte order, coefficient size, reserved");
    check(buf[10] == 2 && buf[11] == 2, "layout: orders");

    {
        uint32_t k;

        memcpy(&k, buf + 12, sizeof(k));
        check(k == 2, "layout: nact");
    }

    check(peek_u64(buf, 16) == 1 && peek_u64(buf, 24) == 1 && peek_u64(buf, 32) == 48,
        "layout: rows, columns, payload");

    for (i = 40; i < 64; i++){
        ok = ok && buf[i] == 0;
    }

    check(ok, "layout: reserved bytes are zero");
    check(memcmp(buf + 64, &num.re, 8) == 0 && memcmp(buf + 72, num.p_im, 8 * 5) == 0,
        "layout: real part, then order 1 (2 directions), then order 2 (3 directions)");

    free(buf);

    // Room for 30 bases in the buffer does not change the file.
    check(oti_reserve(&num, 30, 2) == DN_OK && num.nact == 2, "layout: reserve slack");
    check(oti_save(g_path, &num) == DNIO_OK && oti_read(g_path, &back) == DNIO_OK
        && same_scalar(&num, &back), "layout: scalar with capacity slack round trips");

    buf = slurp(g_path, &n);
    check(n == 64 + 48, "layout: capacity slack is not written");
    free(buf);

    oti_free(&back);
    oti_free(&num);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_soa_layout(void){

    oarr_t arr = make_soa(2, 2, 3, 2, 2), back = oarr_init();
    otinum_t item = oti_init();
    uint8_t* buf;
    size_t n;
    coeff_t v;

    check(oarr_save(g_path, &arr) == DNIO_OK, "layout: save SoA");

    buf = slurp(g_path, &n);

    check(n == 64 + 8 * 6 * (1 + 5), "layout: SoA file size");
    check(buf[6] == DNIO_TYPE_SOA && buf[10] == 2 && buf[11] == 2 && peek_u64(buf, 16) == 2
        && peek_u64(buf, 24) == 3 && peek_u64(buf, 32) == 8 * 6 * 6, "layout: SoA header");
    check(memcmp(buf + 64, arr.p_data, 8 * 6 * 6) == 0, "layout: SoA blocks in memory order");

    // Element (1, 2), order 2 direction 1: block 1 + offset(2, 2) + 1 = 4, at 1 + 2 * 2 in the block.
    check(oarr_get_item_to(1, 2, &arr, &item) == DN_OK, "layout: get_item");
    memcpy(&v, buf + 64 + 8 * (4 * 6 + 1 + 2 * 2), sizeof(v));
    check(v == oti_get_item(1, 2, &item), "layout: element (r, c) of a block is at r + c * nrows");

    free(buf);
    oti_free(&item);

    check(oarr_reserve(&arr, 25, 2, 3, 2) == DN_OK && arr.nact == 2, "layout: SoA reserve slack");
    check(oarr_save(g_path, &arr) == DNIO_OK && oarr_read(g_path, &back) == DNIO_OK
        && same_soa(&arr, &back), "layout: SoA with capacity slack round trips");

    buf = slurp(g_path, &n);
    check(n == 64 + 8 * 6 * 6, "layout: SoA capacity slack is not written");
    free(buf);

    oarr_free(&back);
    oarr_free(&arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_aos_layout(void){

    arro_t arr = arro_init(), back = arro_init();
    uint8_t* buf;
    size_t n;
    uint16_t k16;

    check(arro_zeros_to(1, 2, 0, &arr) == DN_OK
        && oti_create_empty_to(1, 1, &arr.p_data[0]) == DN_OK
        && oti_create_empty_to(2, 2, &arr.p_data[1]) == DN_OK, "layout: AoS build");
    fill_scalar(&arr.p_data[0], 1);
    fill_scalar(&arr.p_data[1], 1);

    check(arro_save(g_path, &arr) == DNIO_OK && arro_read(g_path, &back) == DNIO_OK
        && same_aos(&arr, &back), "layout: AoS round trip");

    buf = slurp(g_path, &n);

    // Records: 8 + 8 * (1 + 1) = 24 bytes, and 8 + 8 * (1 + 2 + 3) = 56 bytes.
    check(n == 64 + 24 + 56, "layout: AoS file size");
    check(buf[6] == DNIO_TYPE_AOS && buf[10] == 2 && buf[11] == 1 && peek_u64(buf, 16) == 1
        && peek_u64(buf, 24) == 2 && peek_u64(buf, 32) == 80, "layout: AoS header (maxima)");

    {
        uint32_t k;

        memcpy(&k, buf + 12, sizeof(k));
        check(k == 2, "layout: AoS header nact is the largest");
    }

    memcpy(&k16, buf + 64 + 2, sizeof(k16));
    check(buf[64] == 1 && buf[65] == 1 && k16 == 1 && buf[68] == 0 && buf[69] == 0 && buf[70] == 0
        && buf[71] == 0, "layout: first record header (trc, act, k, zeros)");
    check(memcmp(buf + 72, &arr.p_data[0].re, 8) == 0
        && memcmp(buf + 80, arr.p_data[0].p_im, 8) == 0, "layout: first record data");

    memcpy(&k16, buf + 64 + 24 + 2, sizeof(k16));
    check(buf[88] == 2 && buf[89] == 1 && k16 == 2, "layout: second record header");
    check(memcmp(buf + 96, &arr.p_data[1].re, 8) == 0
        && memcmp(buf + 104, arr.p_data[1].p_im, 8 * 5) == 0, "layout: second record data");

    free(buf);
    arro_free(&back);
    arro_free(&arr);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// --------------------------------------     PEEK AND MESSAGES     --------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_peek(void){

    dnio_info_t info;
    otinum_t num = make_scalar(4, 3, 2);
    uint8_t* buf;
    size_t n;

    remove(g_path);
    memset(&info, 0x5A, sizeof(info));
    check(dnio_peek(g_path, &info) == DNIO_ERR_OPEN && info.nrows == 0x5A5A5A5A5A5A5A5AULL,
        "peek: missing file leaves info unchanged");
    check(dnio_peek(NULL, &info) == DNIO_ERR_ARGUMENT && dnio_peek(g_path, NULL) == DNIO_ERR_ARGUMENT,
        "peek: NULL arguments");

    check(oti_save(g_path, &num) == DNIO_OK, "peek: save");
    check(dnio_peek(g_path, &info) == DNIO_OK && info.type == DNIO_TYPE_SCALAR && info.version == 1
        && info.trc_order == 3 && info.act_order == 2 && info.nact == 4,
        "peek: scalar fields");

    // A bad file leaves the info untouched.
    buf = slurp(g_path, &n);
    buf[6] = 9;
    spit(g_path, buf, n);
    memset(&info, 0x5A, sizeof(info));
    check(dnio_peek(g_path, &info) == DNIO_ERR_FORMAT && info.nrows == 0x5A5A5A5A5A5A5A5AULL
        && info.type == 0x5A5A5A5A, "peek: bad header leaves info unchanged");
    free(buf);

    oti_free(&num);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_strerror(void){

    static const int CODES[] = {
        DNIO_OK, DNIO_ERR_OPEN, DNIO_ERR_IO, DNIO_ERR_MAGIC, DNIO_ERR_VERSION, DNIO_ERR_TYPE,
        DNIO_ERR_FORMAT, DNIO_ERR_TRUNCATED, DNIO_ERR_SIZE, DNIO_ERR_ARGUMENT, DNIO_ERR_MEMORY,
    };
    size_t i, j;
    int ok = 1;

    for (i = 0; i < sizeof(CODES) / sizeof(CODES[0]); i++){

        const char* a = dnio_strerror(CODES[i]);

        ok = ok && a != NULL && a[0] != '\0';

        for (j = 0; j < i; j++){
            ok = ok && strcmp(a, dnio_strerror(CODES[j])) != 0;
        }

    }

    check(ok, "strerror: every code has its own message");
    check(dnio_strerror(-99) != NULL && dnio_strerror(-99)[0] != '\0'
        && dnio_strerror(1) != NULL, "strerror: unknown codes");

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ------------------------------------------     BAD FILES     ------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// One header patch: `len` bytes of `val` at byte `off`. peek_ok marks a patch that only a full read
// can detect (the header alone stays consistent).
typedef struct { const char* name; size_t off; size_t len; uint64_t val; int want; int peek_ok; } patch_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Saves an object of each kind and returns the bytes of the file of `kind` (DNIO_TYPE_*).
static uint8_t* file_of_kind(int kind, size_t* p_n){

    otinum_t num = make_scalar(3, 3, 3);
    arro_t aos = make_aos(2, 2);
    oarr_t soa = make_soa(3, 2, 3, 3, 3);
    uint8_t* buf;

    if (kind == DNIO_TYPE_SCALAR){
        check(oti_save(g_path, &num) == DNIO_OK, "bad files: build scalar file");
    } else if (kind == DNIO_TYPE_AOS){
        check(arro_save(g_path, &aos) == DNIO_OK, "bad files: build AoS file");
    } else {
        check(oarr_save(g_path, &soa) == DNIO_OK, "bad files: build SoA file");
    }

    buf = slurp(g_path, p_n);

    oti_free(&num);
    arro_free(&aos);
    oarr_free(&soa);

    return buf;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Applies each patch to a copy of `buf` and expects `want` from the reader of `kind` and from peek.
static void run_patches(int kind, const uint8_t* buf, size_t n, const patch_t* patches, size_t np,
                        const char* label){

    uint8_t* bad = (uint8_t*)malloc(n);
    dnio_info_t info;
    size_t i;
    char name[160];

    for (i = 0; i < np; i++){

        memcpy(bad, buf, n);
        poke(bad, patches[i].off, patches[i].len, patches[i].val);
        spit(g_path, bad, n);

        snprintf(name, sizeof(name), "%s: %s", label, patches[i].name);
        check(read_kind(g_path, kind) == patches[i].want, name);

        snprintf(name, sizeof(name), "%s: %s (peek)", label, patches[i].name);
        check(dnio_peek(g_path, &info) == (patches[i].peek_ok ? DNIO_OK : patches[i].want), name);

    }

    free(bad);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Header fields that are bad the same way in every kind of file.
static void test_bad_header_fields(void){

    static const struct { int kind; const char* label; } KINDS[3] = {
        { DNIO_TYPE_SCALAR, "scalar" }, { DNIO_TYPE_AOS, "AoS" }, { DNIO_TYPE_SOA, "SoA" },
    };
    const patch_t generic[] = {
        { "version 2 is newer",              4,  2, 2,          DNIO_ERR_VERSION },
        { "version 65535 is newer",          4,  2, 65535,      DNIO_ERR_VERSION },
        { "version 0",                       4,  2, 0,          DNIO_ERR_FORMAT },
        { "unknown type 0",                  6,  1, 0,          DNIO_ERR_FORMAT },
        { "unknown type 9",                  6,  1, 9,          DNIO_ERR_FORMAT },
        { "byte order 0",                    7,  1, 0,          DNIO_ERR_FORMAT },
        { "byte order 3",                    7,  1, 3,          DNIO_ERR_FORMAT },
        { "other byte order",                7,  1, (uint64_t)(3 - host_order()), DNIO_ERR_FORMAT },
        { "4-byte coefficients",             8,  1, 4,          DNIO_ERR_FORMAT },
        { "reserved byte 9",                 9,  1, 1,          DNIO_ERR_FORMAT },
        { "active order above truncation",   11, 1, 4,          DNIO_ERR_FORMAT },
        { "truncation order 151",            10, 1, 151,        DNIO_ERR_FORMAT },
        { "truncation order 255",            10, 1, 255,        DNIO_ERR_FORMAT },
        { "nact 70000",                      12, 4, 70000,      DNIO_ERR_FORMAT },
        { "nact 2^32 - 1",                   12, 4, 0xFFFFFFFFu, DNIO_ERR_FORMAT },
        { "payload 0",                       32, 8, 0,          DNIO_ERR_FORMAT },
        { "payload 2^64 - 1",                32, 8, UINT64_MAX, DNIO_ERR_FORMAT },
        { "payload 2^64 - 64",               32, 8, UINT64_MAX - 63, DNIO_ERR_FORMAT },
        { "reserved byte 40",                40, 1, 1,          DNIO_ERR_FORMAT },
        { "reserved byte 63",                63, 1, 1,          DNIO_ERR_FORMAT },
    };
    size_t ik;

    for (ik = 0; ik < 3; ik++){

        size_t n;
        uint8_t* buf = file_of_kind(KINDS[ik].kind, &n);

        run_patches(KINDS[ik].kind, buf, n, generic, sizeof(generic) / sizeof(generic[0]),
            KINDS[ik].label);

        free(buf);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Shape and size fields, per kind: scalar and SoA payloads follow from the shape and nact.
static void test_bad_shapes(void){

    // Scalar file: k = 3, trc = 3 (payload 8 * 20 = 160).
    const patch_t scalar[] = {
        { "2 rows",                 16, 8, 2,      DNIO_ERR_FORMAT },
        { "0 columns",              24, 8, 0,      DNIO_ERR_FORMAT },
        { "nact 4 (payload differs)", 12, 4, 4,    DNIO_ERR_FORMAT },
        { "nact 2 (payload differs)", 12, 4, 2,    DNIO_ERR_FORMAT },
        { "payload + 8",            32, 8, 168,    DNIO_ERR_FORMAT },
        { "payload - 8",            32, 8, 152,    DNIO_ERR_FORMAT },
        { "nact 65535 (payload differs)", 12, 4, 65535, DNIO_ERR_FORMAT },
    };
    // SoA file: k = 3, trc = 3, 2 x 3 (payload 8 * 6 * 20 = 960).
    const patch_t soa[] = {
        { "3 rows (payload differs)",  16, 8, 3,   DNIO_ERR_FORMAT },
        { "0 columns",                 24, 8, 0,   DNIO_ERR_FORMAT },
        { "nact 4 (payload differs)",  12, 4, 4,   DNIO_ERR_FORMAT },
        { "payload + 8",               32, 8, 968, DNIO_ERR_FORMAT },
        { "2^40 rows",                 16, 8, 1ULL << 40, DNIO_ERR_FORMAT },
    };
    // AoS file: 2 x 2 (make_aos).
    const patch_t aos[] = {
        { "3 rows (fewer bytes than records)", 16, 8, 3, DNIO_ERR_FORMAT, 1 },
        { "1 row (records left over)",         16, 8, 1, DNIO_ERR_FORMAT, 1 },
        { "0 columns",                         24, 8, 0, DNIO_ERR_FORMAT },
        { "2^40 rows (2^41 elements)",         16, 8, 1ULL << 40, DNIO_ERR_FORMAT },
        { "payload 0",                         32, 8, 0, DNIO_ERR_FORMAT },
    };
    size_t n;
    uint8_t* buf;
    uint8_t* bad;
    dnio_info_t info;
    uint64_t v;

    buf = file_of_kind(DNIO_TYPE_SCALAR, &n);
    run_patches(DNIO_TYPE_SCALAR, buf, n, scalar, sizeof(scalar) / sizeof(scalar[0]), "scalar shape");
    free(buf);

    buf = file_of_kind(DNIO_TYPE_SOA, &n);
    run_patches(DNIO_TYPE_SOA, buf, n, soa, sizeof(soa) / sizeof(soa[0]), "SoA shape");
    free(buf);

    buf = file_of_kind(DNIO_TYPE_AOS, &n);
    run_patches(DNIO_TYPE_AOS, buf, n, aos, sizeof(aos) / sizeof(aos[0]), "AoS shape");

    // Payload + 8 with a matching 8 extra file bytes: the records leave 8 bytes unconsumed.
    bad = (uint8_t*)malloc(n + 8);
    memcpy(bad, buf, n);
    memset(bad + n, 0, 8);
    v = peek_u64(buf, 32) + 8;
    poke(bad, 32, 8, v);
    spit(g_path, bad, n + 8);
    check(read_kind(g_path, DNIO_TYPE_AOS) == DNIO_ERR_FORMAT, "AoS: payload longer than its records");
    free(bad);

    // An empty array whose header claims orders or a payload.
    {
        arro_t empty = arro_init();
        uint8_t* eb;
        size_t en;

        check(arro_zeros_to(0, 3, 0, &empty) == DN_OK && arro_save(g_path, &empty) == DNIO_OK,
            "AoS empty: save");
        eb = slurp(g_path, &en);
        check(en == 64 && dnio_peek(g_path, &info) == DNIO_OK && info.payload == 0
            && info.trc_order == 0 && info.nact == 0, "AoS empty: header holds zeros");

        eb[10] = 1;
        spit(g_path, eb, en);
        check(read_kind(g_path, DNIO_TYPE_AOS) == DNIO_ERR_FORMAT, "AoS empty: nonzero trc");
        eb[10] = 0;
        poke(eb, 12, 4, 1);
        spit(g_path, eb, en);
        check(read_kind(g_path, DNIO_TYPE_AOS) == DNIO_ERR_FORMAT, "AoS empty: nonzero nact");

        free(eb);
        arro_free(&empty);
    }

    free(buf);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A header whose sizes are consistent with each other but far beyond the file: the reader must
// return DNIO_ERR_TRUNCATED from the size check, before it allocates anything.
static void test_huge_claims(void){

    uint8_t head[64];
    uint32_t k;
    uint64_t rows, payload;
    int st[3];
    otinum_t num = make_scalar(1, 1, 1);
    size_t n;
    uint8_t* buf;

    check(oti_save(g_path, &num) == DNIO_OK, "huge: save");
    buf = slurp(g_path, &n);
    memcpy(head, buf, 64);
    free(buf);
    oti_free(&num);

    // Scalar over 65535 bases at order 2: C(65537, 2) coefficients, 17 GB.
    k = 65535;
    memcpy(head + 12, &k, sizeof(k));
    head[10] = 2;
    head[11] = 2;
    payload = 8 * (uint64_t)(65537ULL * 65536ULL / 2);
    memcpy(head + 32, &payload, sizeof(payload));
    spit(g_path, head, 64);
    read_all(g_path, st);
    check(st[0] == DNIO_ERR_TRUNCATED, "scalar claiming 17 GB in a 64-byte file: truncated");
    check(dnio_peek(g_path, &(dnio_info_t){0}) == DNIO_ERR_TRUNCATED, "same file: peek");

    // SoA with 2^20 x 2^20 elements of a real array (nact = 0, order 0): 8 TB.
    memset(head + 12, 0, 4);
    head[6]  = DNIO_TYPE_SOA;
    head[10] = 0;
    head[11] = 0;
    rows     = 1ULL << 20;
    payload  = 8 * (1ULL << 40);
    memcpy(head + 16, &rows, sizeof(rows));
    memcpy(head + 24, &rows, sizeof(rows));
    memcpy(head + 32, &payload, sizeof(payload));
    spit(g_path, head, 64);
    read_all(g_path, st);
    check(st[2] == DNIO_ERR_TRUNCATED, "SoA claiming 8 TB in a 64-byte file: truncated");

    // The same shape with an AoS header: 2^40 elements cannot fit in the payload / 16.
    head[6] = DNIO_TYPE_AOS;
    payload = 0;
    memcpy(head + 32, &payload, sizeof(payload));
    spit(g_path, head, 64);
    read_all(g_path, st);
    check(st[1] == DNIO_ERR_FORMAT, "AoS claiming 2^40 elements with no payload: format");

    // 2^40 x 2^40 elements: the count overflows 64 bits.
    rows = 1ULL << 40;
    memcpy(head + 16, &rows, sizeof(rows));
    memcpy(head + 24, &rows, sizeof(rows));
    spit(g_path, head, 64);
    read_all(g_path, st);
    check(st[1] == DNIO_ERR_FORMAT, "AoS claiming 2^80 elements: format");

    head[6] = DNIO_TYPE_SOA;
    spit(g_path, head, 64);
    read_all(g_path, st);
    check(st[2] == DNIO_ERR_FORMAT, "SoA claiming 2^80 elements: format");

    // 65535 bases at order 150: the coefficient count overflows.
    head[6] = DNIO_TYPE_SCALAR;
    k = 65535;
    memcpy(head + 12, &k, sizeof(k));
    head[10] = 150;
    head[11] = 150;
    rows = 1;
    memcpy(head + 16, &rows, sizeof(rows));
    memcpy(head + 24, &rows, sizeof(rows));
    spit(g_path, head, 64);
    read_all(g_path, st);
    check(st[0] == DNIO_ERR_FORMAT, "scalar claiming 65535 bases at order 150: format");

    // A 0 x N SoA with a huge nact and an order that overflows: the payload is 0 but the layout is
    // not representable.
    head[6] = DNIO_TYPE_SOA;
    rows = 0;
    memcpy(head + 16, &rows, sizeof(rows));
    payload = 0;
    memcpy(head + 32, &payload, sizeof(payload));
    spit(g_path, head, 64);
    read_all(g_path, st);
    check(st[2] == DNIO_ERR_FORMAT, "empty SoA claiming an unrepresentable layout: format");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_missing_and_foreign_files(dhelpl_t dhl){

    otinum_t num = make_scalar(3, 3, 3), s;
    arro_t aos = make_aos(2, 2), a;
    oarr_t soa = make_soa(3, 2, 3, 3, 3), o;
    dnio_info_t info;
    uint8_t* buf;
    size_t n, cut;
    int st[3];
    char sub[700];

    // Missing file.
    remove(g_path);
    s = oti_create_r(7.0, 3);
    check(oti_read(g_path, &s) == DNIO_ERR_OPEN && is_init_scalar(&s), "scalar read: missing file");
    a = arro_init(); a.size = 3; a.nrows = 3; a.ncols = 1;
    check(arro_read(g_path, &a) == DNIO_ERR_OPEN && is_init_aos(&a), "AoS read: missing file");
    o = oarr_init(); o.size = 3; o.nrows = 3; o.ncols = 1;
    check(oarr_read(g_path, &o) == DNIO_ERR_OPEN && is_init_soa(&o), "SoA read: missing file");
    check(dnio_peek(g_path, &info) == DNIO_ERR_OPEN, "peek: missing file");

    // Save into a missing directory, and onto a directory.
    snprintf(sub, sizeof(sub), "%s/no_such_dir/x.bin", g_dir);
    check(oti_save(sub, &num) == DNIO_ERR_OPEN && arro_save(sub, &aos) == DNIO_ERR_OPEN
        && oarr_save(sub, &soa) == DNIO_ERR_OPEN, "save: missing directory");
    check(oti_save(g_dir, &num) == DNIO_ERR_OPEN && oarr_save(g_dir, &soa) == DNIO_ERR_OPEN
        && arro_save(g_dir, &aos) == DNIO_ERR_OPEN, "save: path is a directory");

    // NULL arguments (the result is still set to init when there is one).
    s = oti_create_r(7.0, 3);
    check(oti_read(NULL, &s) == DNIO_ERR_ARGUMENT && is_init_scalar(&s), "scalar read: NULL path");
    check(oti_read(g_path, NULL) == DNIO_ERR_ARGUMENT && arro_read(g_path, NULL) == DNIO_ERR_ARGUMENT
        && oarr_read(g_path, NULL) == DNIO_ERR_ARGUMENT, "read: NULL result");
    a = arro_init();
    o = oarr_init();
    check(arro_read(NULL, &a) == DNIO_ERR_ARGUMENT && oarr_read(NULL, &o) == DNIO_ERR_ARGUMENT,
        "read: NULL path for the arrays");

    // Empty file, short garbage.
    spit(g_path, (const uint8_t*)"", 0);
    read_all(g_path, st);
    check3(st, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, "empty file: bad magic");
    spit(g_path, (const uint8_t*)"\x93OT", 3);
    read_all(g_path, st);
    check3(st, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, "3-byte file: bad magic");
    spit(g_path, (const uint8_t*)"just some text, not a dense file at all, no header here, nothing", 65);
    read_all(g_path, st);
    check3(st, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, "text file: bad magic");

    // Magic but nothing else.
    spit(g_path, (const uint8_t*)"\x93OTD", 4);
    read_all(g_path, st);
    check3(st, DNIO_ERR_TRUNCATED, DNIO_ERR_TRUNCATED, DNIO_ERR_TRUNCATED, "magic only: truncated");

    // Real semi-sparse files: another magic.
    {
        static const bases_t B[2] = { 1, 4 };
        ssotinum_t ss = ssoti_create_empty(B, 2, 2);
        oarrss_t soss = oarrss_zeros(B, 2, 2, 2, 2);
        arrss_t aoss = arrss_zeros(2, 2, 2);

        check(ssoti_save(g_path, &ss) == SSIO_OK, "semi-sparse scalar file: save");
        read_all(g_path, st);
        check3(st, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, "a semi-sparse scalar file");
        check(oarrss_save(g_path, &soss) == SSIO_OK, "semi-sparse SoA file: save");
        read_all(g_path, st);
        check3(st, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, "a semi-sparse SoA file");
        check(arrss_save(g_path, &aoss) == SSIO_OK, "semi-sparse AoS file: save");
        read_all(g_path, st);
        check3(st, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, "a semi-sparse AoS file");
        check(dnio_peek(g_path, &info) == DNIO_ERR_MAGIC, "peek: semi-sparse file");

        ssoti_free(&ss);
        oarrss_free(&soss);
        arrss_free(&aoss);
    }

    // A real sparse file (arrso_save), and a crafted sparse header.
    {
        arrso_t sp;

        sp = arrso_zeros_bases(2, 2, 0, 2, dhl);
        arrso_save(g_path, &sp, dhl);
        read_all(g_path, st);
        check3(st, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, "a sparse file");
        arrso_free(&sp);
    }

    {
        const uint8_t sparse_head[64] = {0x93, 'O', 'T', 'I', 1, 0, 21, 0};

        spit(g_path, sparse_head, sizeof(sparse_head));
        read_all(g_path, st);
        check3(st, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, DNIO_ERR_MAGIC, "a sparse (OTI) header");
    }

    // Another type than requested.
    check(oti_save(g_path, &num) == DNIO_OK, "types: save scalar");
    read_all(g_path, st);
    check3(st, DNIO_OK, DNIO_ERR_TYPE, DNIO_ERR_TYPE, "scalar file read as an array");
    check(oarr_save(g_path, &soa) == DNIO_OK, "types: save SoA");
    read_all(g_path, st);
    check3(st, DNIO_ERR_TYPE, DNIO_ERR_TYPE, DNIO_OK, "SoA file read as scalar or AoS");
    check(arro_save(g_path, &aos) == DNIO_OK, "types: save AoS");
    read_all(g_path, st);
    check3(st, DNIO_ERR_TYPE, DNIO_OK, DNIO_ERR_TYPE, "AoS file read as scalar or SoA");

    // Truncated everywhere: inside the magic, the header and the payload.
    {
        static const int KINDS[3] = { DNIO_TYPE_SCALAR, DNIO_TYPE_AOS, DNIO_TYPE_SOA };
        size_t ik;

        for (ik = 0; ik < 3; ik++){

            buf = file_of_kind(KINDS[ik], &n);

            for (cut = 0; cut < n; cut += (cut < 80) ? 1 : 23){

                int ok;

                spit(g_path, buf, cut);
                ok = read_kind(g_path, KINDS[ik]) == ((cut < 4) ? DNIO_ERR_MAGIC : DNIO_ERR_TRUNCATED)
                    && dnio_peek(g_path, &info) == ((cut < 4) ? DNIO_ERR_MAGIC : DNIO_ERR_TRUNCATED);

                if (!ok){

                    fprintf(stderr, "kind %d cut at %zu of %zu\n", KINDS[ik], cut, n);
                    check(0, "truncated file");
                    break;

                }

            }

            check(cut >= n, "truncated files: every cut gives MAGIC or TRUNCATED");

            // Trailing bytes.
            {
                uint8_t* longer = (uint8_t*)malloc(n + 1);

                memcpy(longer, buf, n);
                longer[n] = 0;
                spit(g_path, longer, n + 1);
                check(read_kind(g_path, KINDS[ik]) == DNIO_ERR_SIZE
                    && dnio_peek(g_path, &info) == DNIO_ERR_SIZE, "file with a trailing byte");
                free(longer);
            }

            free(buf);

        }
    }

    remove(g_path);
    oti_free(&num);
    arro_free(&aos);
    oarr_free(&soa);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Coefficients above the active order, and AoS records that disagree with the header.
static void test_bad_payload(void){

    otinum_t num = make_scalar(3, 3, 3);
    oarr_t soa = make_soa(3, 2, 2, 3, 3);
    arro_t aos = arro_init();
    uint8_t* buf;
    size_t n;
    int st[3];

    // Scalar saved with act = 3; the header is patched down to act = 1 while order 2 is nonzero.
    check(oti_save(g_path, &num) == DNIO_OK, "payload: save scalar");
    buf = slurp(g_path, &n);
    buf[11] = 1;
    spit(g_path, buf, n);
    check(read_kind(g_path, DNIO_TYPE_SCALAR) == DNIO_ERR_FORMAT,
        "scalar: nonzero above the active order");
    buf[11] = 0;
    spit(g_path, buf, n);
    check(read_kind(g_path, DNIO_TYPE_SCALAR) == DNIO_ERR_FORMAT, "scalar: nonzero above act = 0");
    free(buf);

    check(oarr_save(g_path, &soa) == DNIO_OK, "payload: save SoA");
    buf = slurp(g_path, &n);
    buf[11] = 2;
    spit(g_path, buf, n);
    check(read_kind(g_path, DNIO_TYPE_SOA) == DNIO_ERR_FORMAT, "SoA: nonzero above the active order");
    buf[11] = 0;
    spit(g_path, buf, n);
    check(read_kind(g_path, DNIO_TYPE_SOA) == DNIO_ERR_FORMAT, "SoA: nonzero above act = 0");
    free(buf);

    // AoS: one element, act patched down in the record and in the header.
    check(arro_zeros_to(1, 1, 0, &aos) == DN_OK && oti_create_empty_to(3, 3, &aos.p_data[0]) == DN_OK,
        "payload: build AoS");
    fill_scalar(&aos.p_data[0], 3);
    check(arro_save(g_path, &aos) == DNIO_OK, "payload: save AoS");
    buf = slurp(g_path, &n);

    buf[11] = 1;
    buf[64 + 1] = 1;
    spit(g_path, buf, n);
    check(read_kind(g_path, DNIO_TYPE_AOS) == DNIO_ERR_FORMAT, "AoS: nonzero above the active order");

    // Records that disagree with the header or with themselves.
    {
        static const struct { const char* name; size_t off; size_t len; uint64_t val; } BAD[] = {
            { "record trc above the header's",   64,     1, 4 },
            { "record act above the header's",   64 + 1, 1, 4 },
            { "record act above its trc",        64 + 1, 1, 200 },
            { "record trc 151",                  64,     1, 151 },
            { "record k above the header's",     64 + 2, 2, 4 },
            { "record k 65535",                  64 + 2, 2, 65535 },
            { "record padding nonzero (byte 4)", 64 + 4, 1, 1 },
            { "record padding nonzero (byte 7)", 64 + 7, 1, 1 },
            { "record k below the header's",     64 + 2, 2, 2 },
        };
        size_t i;

        for (i = 0; i < sizeof(BAD) / sizeof(BAD[0]); i++){

            uint8_t* bad = (uint8_t*)malloc(n);

            memcpy(bad, buf, n);
            bad[11] = 3;
            bad[64 + 1] = 3;
            poke(bad, BAD[i].off, BAD[i].len, BAD[i].val);
            spit(g_path, bad, n);
            check(read_kind(g_path, DNIO_TYPE_AOS) == DNIO_ERR_FORMAT, BAD[i].name);
            free(bad);

        }
    }

    free(buf);

    // Header maxima that the records do not reach.
    check(arro_save(g_path, &aos) == DNIO_OK, "payload: save AoS again");
    buf = slurp(g_path, &n);
    buf[10] = 4;
    spit(g_path, buf, n);
    check(read_kind(g_path, DNIO_TYPE_AOS) == DNIO_ERR_FORMAT, "AoS: header trc above every record's");
    buf[10] = 3;
    poke(buf, 12, 4, 4);
    spit(g_path, buf, n);
    check(read_kind(g_path, DNIO_TYPE_AOS) == DNIO_ERR_FORMAT, "AoS: header nact above every record's");
    free(buf);

    // A valid file still reads (the patch harness restored it correctly).
    check(arro_save(g_path, &aos) == DNIO_OK, "payload: save AoS a third time");
    read_all(g_path, st);
    check3(st, DNIO_ERR_TYPE, DNIO_OK, DNIO_ERR_TYPE, "payload: the unpatched AoS file reads");

    remove(g_path);
    oti_free(&num);
    oarr_free(&soa);
    arro_free(&aos);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Saving an object the format cannot represent fails with DNIO_ERR_ARGUMENT and leaves no file.
static void test_save_refuses(void){

    otinum_t num = make_scalar(3, 3, 1), bad;
    oarr_t soa = make_soa(2, 2, 2, 2, 1), sbad;
    arro_t aos = make_aos(2, 2), abad;
    otinum_t elem;
    uint64_t i;

    remove(g_path);

    // NULL arguments.
    check(oti_save(NULL, &num) == DNIO_ERR_ARGUMENT && oti_save(g_path, NULL) == DNIO_ERR_ARGUMENT
        && oarr_save(NULL, &soa) == DNIO_ERR_ARGUMENT && oarr_save(g_path, NULL) == DNIO_ERR_ARGUMENT
        && arro_save(NULL, &aos) == DNIO_ERR_ARGUMENT && arro_save(g_path, NULL) == DNIO_ERR_ARGUMENT,
        "save: NULL arguments");
    check(!file_exists(g_path), "save: NULL arguments create no file");

    // Scalars.
    bad = num;
    bad.act_order = 4;
    check(oti_save(g_path, &bad) == DNIO_ERR_ARGUMENT, "save scalar: act above trc");

    bad = num;
    bad.p_im[sshelp_order_offset(3, 2)] = 1.0;
    check(oti_save(g_path, &bad) == DNIO_ERR_ARGUMENT, "save scalar: nonzero above act");
    bad.p_im[sshelp_order_offset(3, 2)] = NAN;
    check(oti_save(g_path, &bad) == DNIO_ERR_ARGUMENT, "save scalar: NaN above act");
    bad.p_im[sshelp_order_offset(3, 2)] = 0.0;

    bad = num;
    bad.p_im = NULL;
    check(oti_save(g_path, &bad) == DNIO_ERR_ARGUMENT, "save scalar: missing buffer");

    bad = oti_init();
    bad.trc_order = 151;
    check(oti_save(g_path, &bad) == DNIO_ERR_ARGUMENT, "save scalar: trc 151");

    bad = oti_init();
    bad.trc_order = 2;
    bad.nact = 65535;
    check(oti_save(g_path, &bad) == DNIO_ERR_ARGUMENT, "save scalar: 17 GB layout with no buffer");

    // SoA.
    sbad = soa;
    sbad.act_order = 3;
    check(oarr_save(g_path, &sbad) == DNIO_ERR_ARGUMENT, "save SoA: act above trc");

    sbad = soa;
    sbad.size = 5;
    check(oarr_save(g_path, &sbad) == DNIO_ERR_ARGUMENT, "save SoA: size != nrows * ncols");

    sbad = soa;
    sbad.p_data = NULL;
    check(oarr_save(g_path, &sbad) == DNIO_ERR_ARGUMENT, "save SoA: missing buffer");

    sbad = soa;
    sbad.p_data[sbad.size * (1 + sshelp_order_offset(2, 2)) + 1] = 1.0;
    check(oarr_save(g_path, &sbad) == DNIO_ERR_ARGUMENT, "save SoA: nonzero above act");
    sbad.p_data[sbad.size * (1 + sshelp_order_offset(2, 2)) + 1] = 0.0;

    sbad = soa;
    sbad.nrows = 1ULL << 40;
    sbad.ncols = 1ULL << 40;
    sbad.size  = 0;
    check(oarr_save(g_path, &sbad) == DNIO_ERR_ARGUMENT, "save SoA: shape overflows");

    // AoS: an invalid element anywhere, a missing buffer, a wrong size.
    for (i = 0; i < aos.size; i++){

        abad = aos;
        elem = aos.p_data[i];
        elem.act_order = (ord_t)(elem.trc_order + 1);
        abad.p_data = (otinum_t*)malloc(aos.size * sizeof(otinum_t));
        memcpy(abad.p_data, aos.p_data, aos.size * sizeof(otinum_t));
        abad.p_data[i] = elem;
        check(arro_save(g_path, &abad) == DNIO_ERR_ARGUMENT, "save AoS: an element with act above trc");
        free(abad.p_data);

    }

    abad = aos;
    abad.p_data = NULL;
    check(arro_save(g_path, &abad) == DNIO_ERR_ARGUMENT, "save AoS: missing buffer");

    abad = aos;
    abad.size = 3;
    check(arro_save(g_path, &abad) == DNIO_ERR_ARGUMENT, "save AoS: size != nrows * ncols");

    check(!file_exists(g_path), "save: refused objects create no file");

    oti_free(&num);
    oarr_free(&soa);
    arro_free(&aos);

}

// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Number of temporary files (<name>.tmp.*) left in the scratch directory.
static int count_tmp_files(void){

    DIR* dir = opendir(g_dir);
    struct dirent* entry;
    int count = 0;

    if (dir == NULL){
        return -1;
    }

    while ((entry = readdir(dir)) != NULL){

        if (strstr(entry->d_name, ".tmp.") != NULL){
            count++;
        }

    }

    closedir(dir);

    return count;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A write failure gives DNIO_ERR_IO from the three writers, leaves no temporary file, and an existing
// file of that name survives untouched (saves are atomic: temporary file, then rename). The failure is
// made with a lowered soft RLIMIT_FSIZE (the hard limit is kept) and SIGXFSZ ignored, then both are
// restored. Also: saving onto a directory fails with DNIO_ERR_OPEN and leaves no temporary file.
static void test_write_failure(void){

    otinum_t num = make_scalar(20, 3, 3), keep = make_scalar(2, 2, 2), back = oti_init();
    oarr_t soa   = make_soa(2, 20, 20, 3, 3);
    arro_t aos   = make_aos(30, 30);
    struct rlimit old, low;
    void (*old_handler)(int);
    int got_limit, s_num = 0, s_soa = 0, s_aos = 0;
    int left_num, left_soa, left_aos, after_num;
    int ok_num, ok_soa, ok_aos;

    got_limit = (getrlimit(RLIMIT_FSIZE, &old) == 0);

    low = old;
    low.rlim_cur = 4096;
    old_handler = signal(SIGXFSZ, SIG_IGN);

    if (!got_limit || setrlimit(RLIMIT_FSIZE, &low) != 0){

        signal(SIGXFSZ, old_handler);
        fprintf(stderr, "skipped: RLIMIT_FSIZE is not available\n");
        oti_free(&num);
        oti_free(&keep);
        oarr_free(&soa);
        arro_free(&aos);
        return;

    }

    // An old file exists at the target (small enough for the lowered limit); each failed save must
    // leave it in place and readable.
    remove(g_path);
    check(oti_save(g_path, &keep) == DNIO_OK, "the old file is saved under the lowered limit");

    s_num    = oti_save(g_path, &num);
    ok_num   = (oti_read(g_path, &back) == DNIO_OK && same_scalar(&keep, &back));
    left_num = count_tmp_files();
    oti_free(&back);

    s_soa    = oarr_save(g_path, &soa);
    ok_soa   = (oti_read(g_path, &back) == DNIO_OK && same_scalar(&keep, &back));
    left_soa = count_tmp_files();
    oti_free(&back);

    s_aos    = arro_save(g_path, &aos);
    ok_aos   = (oti_read(g_path, &back) == DNIO_OK && same_scalar(&keep, &back));
    left_aos = count_tmp_files();
    oti_free(&back);

    setrlimit(RLIMIT_FSIZE, &old);
    signal(SIGXFSZ, old_handler);

    check(s_num == DNIO_ERR_IO && left_num == 0 && ok_num,
          "oti_save: a write failure gives DNIO_ERR_IO, no temporary file, the old file survives");
    check(s_soa == DNIO_ERR_IO && left_soa == 0 && ok_soa,
          "oarr_save: a write failure gives DNIO_ERR_IO, no temporary file, the old file survives");
    check(s_aos == DNIO_ERR_IO && left_aos == 0 && ok_aos,
          "arro_save: a write failure gives DNIO_ERR_IO, no temporary file, the old file survives");

    // No old file: a failed save leaves nothing at all.
    remove(g_path);
    setrlimit(RLIMIT_FSIZE, &low);
    signal(SIGXFSZ, SIG_IGN);
    s_num = oti_save(g_path, &num);
    setrlimit(RLIMIT_FSIZE, &old);
    signal(SIGXFSZ, old_handler);
    check(s_num == DNIO_ERR_IO && !file_exists(g_path) && count_tmp_files() == 0,
          "a failed save without an old file leaves no file");

    // The limit is back: the same objects save and read again, replacing the old file.
    after_num = oti_save(g_path, &keep);
    check(after_num == DNIO_OK && oti_save(g_path, &num) == DNIO_OK
        && oti_read(g_path, &back) == DNIO_OK && same_scalar(&num, &back)
        && oarr_save(g_path, &soa) == DNIO_OK && arro_save(g_path, &aos) == DNIO_OK
        && count_tmp_files() == 0, "the writers work again and replace the file after the limit is back");
    oti_free(&back);

    // The target cannot be replaced (a directory): DNIO_ERR_OPEN, no temporary file left.
    check(oti_save(g_dir, &keep) == DNIO_ERR_OPEN && count_tmp_files() == 0,
          "saving onto a directory gives DNIO_ERR_OPEN and no temporary file");

    oti_free(&num);
    oti_free(&keep);
    oarr_free(&soa);
    arro_free(&aos);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------     SPARSE ORACLE     ----------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* A random sotinum_t over bases 1..k at truncation order trc: every order-1 coefficient is nonzero (so
 * the dense number sees every base), orders 2..trc hold a `density` fraction of the directions. */
static sotinum_t build_soti(bases_t k, ord_t trc, double density, dhelpl_t dhl){

    sotinum_t num = soti_createEmpty(trc, dhl);
    ndir_t j, n;
    ord_t p;

    soti_set_item(rng_range(0.5, 1.5), 0, 0, &num, dhl);

    for (p = 1; p <= trc && k > 0; p++){

        n = sshelp_ndir_order(k, p);

        for (j = 0; j < n; j++){

            coeff_t v = rng_range(0.05, 0.3) * ((rng_value() > 0.0) ? 1.0 : -1.0);

            if (p == 1 || rng_range(0.0, 1.0) < density){
                soti_set_item(v, (imdir_t)j, p, &num, dhl);
            }

        }

    }

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Every coefficient of `d` against the sparse oracle `s`, orders 0..trc over bases 1..k.
static int matches_soti(const otinum_t* d, sotinum_t* s, bases_t k, ord_t trc, dhelpl_t dhl){

    ndir_t j;
    ord_t p;

    if (d->trc_order != trc){
        return 0;
    }

    for (p = 0; p <= trc; p++){

        for (j = 0; j < sshelp_ndir_order(k, p); j++){

            if (!approx_equal(oti_get_item((imdir_t)j, p, d), soti_get_item((imdir_t)j, p, s, dhl),
                    TOL_ORACLE)){
                return 0;
            }

        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A file written from a sparse value reads back to that value.
static void test_sparse_oracle(dhelpl_t dhl){

    static const bases_t KS[3] = { 1, 4, 8 };
    size_t ik;
    ord_t trc;

    for (ik = 0; ik < 3; ik++){

        for (trc = 1; trc <= 5; trc++){

            bases_t k = KS[ik];
            sotinum_t s = build_soti(k, trc, 0.6, dhl);
            otinum_t d = oti_from_soti(&s, dhl), back = oti_init();
            arrso_t arr = arrso_zeros_bases(3, 2, 0, trc, dhl);
            oarr_t soa = oarr_init(), sback = oarr_init();
            arro_t aos = arro_init(), aback = arro_init();
            uint64_t e;
            int ok = 1;
            char name[96];

            snprintf(name, sizeof(name), "sparse oracle k=%u trc=%u", (unsigned)k, (unsigned)trc);

            check(oti_save(g_path, &d) == DNIO_OK && oti_read(g_path, &back) == DNIO_OK
                && matches_soti(&back, &s, k, trc, dhl), name);

            for (e = 0; e < arr.size; e++){

                sotinum_t tmp = build_soti(k, trc, 0.6, dhl);

                soti_copy_to(&tmp, &arr.p_data[e], dhl);
                soti_free(&tmp);

            }

            check(oarr_from_arrso_to(&arr, &soa, dhl) == DN_OK
                && arro_from_arrso_to(&arr, &aos, dhl) == DN_OK, name);
            check(oarr_save(g_path, &soa) == DNIO_OK && oarr_read(g_path, &sback) == DNIO_OK
                && same_soa(&soa, &sback), name);

            for (e = 0; e < arr.size; e++){

                otinum_t item = oti_init();
                uint64_t i = e / 2, j = e % 2;

                ok = ok && oarr_get_item_to(i, j, &sback, &item) == DN_OK
                    && matches_soti(&item, &arr.p_data[e], k, trc, dhl);
                oti_free(&item);

            }

            check(ok, name);

            check(arro_save(g_path, &aos) == DNIO_OK && arro_read(g_path, &aback) == DNIO_OK
                && same_aos(&aos, &aback), name);

            for (e = 0; e < arr.size; e++){
                ok = ok && matches_soti(&aback.p_data[e], &arr.p_data[e], k, trc, dhl);
            }

            check(ok, name);

            soti_free(&s);
            oti_free(&d);
            oti_free(&back);
            arrso_free(&arr);
            oarr_free(&soa);
            oarr_free(&sback);
            arro_free(&aos);
            arro_free(&aback);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The invariants of a well-formed scalar: orders in range, buffer present, zeros above act_order.
static int valid_scalar(const otinum_t* n){

    ndir_t nimag = sshelp_ndir_total(n->nact, n->trc_order), j;

    if (n->act_order > n->trc_order || n->trc_order > _MAXORDER_OTI
        || (nimag > 0 && n->p_im == NULL)){
        return 0;
    }

    for (j = (n->act_order < n->trc_order && n->nact > 0)
             ? sshelp_order_offset(n->nact, (ord_t)(n->act_order + 1)) : nimag; j < nimag; j++){

        if (n->p_im[j] != 0.0){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Random corruption of valid files of every kind: no reader may crash or misbehave, and whatever
// reads back with DNIO_OK must be well-formed, save again and read back to the same object.
static void test_fuzz(void){

    static const int KINDS[3] = { DNIO_TYPE_SCALAR, DNIO_TYPE_AOS, DNIO_TYPE_SOA };
    size_t ik, n;
    int iter, nok = 0, bad_ok = 0, bad_resave = 0;

    for (ik = 0; ik < 3; ik++){

        uint8_t* buf = file_of_kind(KINDS[ik], &n);
        uint8_t* mut = (uint8_t*)malloc(n + 16);

        for (iter = 0; iter < 600; iter++){

            size_t len = n, nflip = 1 + (size_t)((rng_value() + 2.0) * 0.75), f;
            int st[3];

            memcpy(mut, buf, n);

            for (f = 0; f < nflip; f++){

                size_t span = (iter % 2 == 0) ? 64 : n;
                size_t pos = (size_t)((rng_value() + 2.0) / 4.0 * (double)span) % span;

                mut[pos] = (uint8_t)((int64_t)(rng_value() * 100.0 + 128.0) & 0xFF);

            }

            if (iter % 7 == 0){
                len = (size_t)((rng_value() + 2.0) / 4.0 * (double)n);
            } else if (iter % 11 == 0){

                memset(mut + n, 0, 16);
                len = n + 1 + (size_t)(iter % 15);

            }

            spit(g_path, mut, len);

            // Each reader on its own, so a success can be re-saved and compared.
            {
                otinum_t s = oti_init();
                arro_t a = arro_init();
                oarr_t o = oarr_init();

                st[0] = oti_read(g_path, &s);
                st[1] = arro_read(g_path, &a);
                st[2] = oarr_read(g_path, &o);

                if (st[0] == DNIO_OK){

                    otinum_t again = oti_init();

                    nok++;
                    bad_ok += !valid_scalar(&s);
                    bad_resave += !(oti_save(g_path, &s) == DNIO_OK
                        && oti_read(g_path, &again) == DNIO_OK && same_scalar(&s, &again));
                    oti_free(&again);

                }

                if (st[1] == DNIO_OK){

                    arro_t again = arro_init();
                    uint64_t e;

                    nok++;

                    for (e = 0; e < a.size; e++){
                        bad_ok += !valid_scalar(&a.p_data[e]);
                    }

                    bad_resave += !(arro_save(g_path, &a) == DNIO_OK
                        && arro_read(g_path, &again) == DNIO_OK && same_aos(&a, &again));
                    arro_free(&again);

                }

                if (st[2] == DNIO_OK){

                    oarr_t again = oarr_init();

                    nok++;
                    bad_resave += !(oarr_save(g_path, &o) == DNIO_OK
                        && oarr_read(g_path, &again) == DNIO_OK && same_soa(&o, &again));
                    oarr_free(&again);

                }

                oti_free(&s);
                arro_free(&a);
                oarr_free(&o);
            }

        }

        free(mut);
        free(buf);

    }

    check(bad_ok == 0, "fuzz: every successful read is well-formed");
    check(bad_resave == 0, "fuzz: every successful read saves and reads back unchanged");
    check(nok > 0, "fuzz: some corruptions (a flip in a coefficient) still read");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(int argc, char** argv){

    dhelpl_t dhl;

    g_verbose = (argc > 1 && strcmp(argv[1], "-v") == 0);
    dhelp_load(NULL, &dhl);
    make_scratch_dir();

    test_scalar_roundtrip();
    test_soa_roundtrip();
    test_aos_roundtrip();
    test_special_values();
    test_zero_bases_kept();
    test_overwrite();
    test_scalar_layout();
    test_soa_layout();
    test_aos_layout();
    test_peek();
    test_strerror();
    test_bad_header_fields();
    test_bad_shapes();
    test_huge_claims();
    test_missing_and_foreign_files(dhl);
    test_bad_payload();
    test_save_refuses();
    test_write_failure();
    test_sparse_oracle(dhl);
    test_fuzz();

    remove_scratch_dir();
    oti_ws_release();
    dhelp_free(&dhl);

    if (n_failed != 0){

        fprintf(stderr, "%d dense I/O check(s) failed (%d passed).\n", n_failed, n_passed);
        return 1;

    }

    printf("C dense I/O tests passed successfully (%d checks).\n", n_passed);

    return 0;

}
// -------------------------------------------------------------------------------------------------------
