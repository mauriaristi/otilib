/* Independent checks of semi-sparse save / read (include/oti/semisparse/io/io.h, PLAN-semisparse-
 * sparse-leveling.md Phase 3): round trips of scalars, AoS and SoA arrays through
 * {ssoti,arrss,oarrss}_save() / _read() that must reproduce every field and coefficient bit for
 * bit, the header reported by ssio_peek(), and the status every kind of bad file must produce
 * (missing, empty, wrong magic, another type, truncated at several points, trailing bytes, bad
 * version, byte order, order and label fields, coefficients above the active order, sizes claimed
 * by the header that the file cannot back), without ever calling exit(). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/oti.h>
#include <oti/semisparse.h>

static int n_failed = 0;

static uint64_t g_rng_state = 0x5EED5EED12345678ULL;

static const char* PATH = "test_ssio_tmp.bin";


// *******************************************************************************************************
static void check(int cond, const char* name){

    if (!cond){
        fprintf(stderr, "FAILED: %s\n", name);
        n_failed++;
    } else {
        printf("passed: %s\n", name);
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


// -------------------------------------------------------------------------------------------------------
// --------------------------------------     BUILDING OBJECTS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// A scalar over `bases` with random coefficients up to order `act` (zeros above), truncation `trc`.
static ssotinum_t make_scalar(const bases_t* bases, bases_t k, ord_t trc, ord_t act){

    ssotinum_t num = ssoti_create_empty(bases, k, trc);
    ord_t p;
    ndir_t j;

    num.re = rng_value();

    for (p = 1; p <= act && p <= trc; p++){

        for (j = 0; j < sshelp_ndir_order(k, p); j++){
            num.p_im[sshelp_order_offset(k, p) + j] = rng_value();
        }

    }

    num.act_order = (act < trc) ? act : trc;

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static oarrss_t make_soa(const bases_t* bases, bases_t k, uint64_t nrows, uint64_t ncols, ord_t trc,
                         ord_t act){

    oarrss_t arr = oarrss_zeros(bases, k, nrows, ncols, trc);
    uint64_t i, n = (1 + sshelp_ndir_total(k, trc)) * arr.size, per = arr.size;

    for (i = 0; i < n; i++){

        // Blocks above the active order stay zero.
        if (i < per || i < (1 + (uint64_t)sshelp_order_offset(k, (ord_t)(act + 1))) * per
            || act >= trc){
            arr.p_data[i] = rng_value();
        }

    }

    arr.act_order = (act < trc) ? act : trc;

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// An array whose elements have different active sets and orders.
static arrss_t make_aos(uint64_t nrows, uint64_t ncols){

    static const bases_t SETS[4][3] = { {1, 0, 0}, {2, 5, 0}, {1, 3, 65535}, {7, 0, 0} };
    static const bases_t SIZES[4]   = { 0, 2, 3, 1 };
    arrss_t arr = arrss_zeros(nrows, ncols, 0);
    uint64_t i;

    for (i = 0; i < arr.size; i++){

        ssotinum_t num = make_scalar(SETS[i % 4], SIZES[i % 4], (ord_t)(1 + i % 4),
            (ord_t)(1 + (i % 3)));

        // An element with no bases keeps one of its own too, to exercise k = 0.
        arrss_set_item(&num, i / ncols, i % ncols, &arr);
        ssoti_free(&num);

    }

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int same_scalar(const ssotinum_t* a, const ssotinum_t* b){

    ndir_t nimag;

    if (a->nbases != b->nbases || a->trc_order != b->trc_order || a->act_order != b->act_order
        || memcmp(&a->re, &b->re, sizeof(coeff_t)) != 0){
        return 0;
    }

    nimag = sshelp_ndir_total(a->nbases, a->trc_order);

    return (a->nbases == 0 || memcmp(a->p_bases, b->p_bases, a->nbases * sizeof(bases_t)) == 0)
        && (nimag == 0 || memcmp(a->p_im, b->p_im, nimag * sizeof(coeff_t)) == 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int same_soa(const oarrss_t* a, const oarrss_t* b){

    size_t nreal;

    if (a->nbases != b->nbases || a->trc_order != b->trc_order || a->act_order != b->act_order
        || a->nrows != b->nrows || a->ncols != b->ncols){
        return 0;
    }

    nreal = (size_t)(1 + sshelp_ndir_total(a->nbases, a->trc_order)) * a->size;

    return (a->nbases == 0 || memcmp(a->p_bases, b->p_bases, a->nbases * sizeof(bases_t)) == 0)
        && (nreal == 0 || memcmp(a->p_data, b->p_data, nreal * sizeof(coeff_t)) == 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int same_aos(const arrss_t* a, const arrss_t* b){

    uint64_t i;

    if (a->nrows != b->nrows || a->ncols != b->ncols){
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


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------     FILE HELPERS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Whole file into a malloc'd buffer.
static uint8_t* slurp(const char* path, size_t* p_n){

    FILE* f = fopen(path, "rb");
    uint8_t* buf;

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

    if (n > 0 && fwrite(buf, 1, n, f) != n){
        fprintf(stderr, "test harness: cannot write %s\n", path);
    }

    fclose(f);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Status of reading the file with each of the three readers, in order scalar, AoS, SoA.
static void read_all(const char* path, int st[3]){

    ssotinum_t s;
    arrss_t a;
    oarrss_t o;

    st[0] = ssoti_read(path, &s);
    st[1] = arrss_read(path, &a);
    st[2] = oarrss_read(path, &o);

    if (st[0] == SSIO_OK){ ssoti_free(&s); }
    if (st[1] == SSIO_OK){ arrss_free(&a); }
    if (st[2] == SSIO_OK){ oarrss_free(&o); }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -----------------------------------------     ROUND TRIPS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_scalar_roundtrip(void){

    static const bases_t SET_1[1] = {3};
    static const bases_t SET_2[2] = {2, 5};
    static const bases_t SET_4[4] = {1, 2, 4, 9};
    static const bases_t SET_BIG[3] = {1, 300, 65535};
    static const struct { const bases_t* bases; bases_t k; ord_t trc, act; } CASES[] = {
        { NULL,    0, 0, 0 }, { NULL,    0, 3, 0 }, { SET_1,   1, 1, 1 }, { SET_2,   2, 3, 3 },
        { SET_4,   4, 4, 2 }, { SET_4,   4, 5, 5 }, { SET_BIG, 3, 4, 4 }, { SET_2,   2, 2, 0 },
        { SET_1,   1, 6, 6 }, { SET_BIG, 3, 5, 5 },
    };
    size_t c;

    for (c = 0; c < sizeof(CASES) / sizeof(CASES[0]); c++){

        ssotinum_t num = make_scalar(CASES[c].bases, CASES[c].k, CASES[c].trc, CASES[c].act);
        ssotinum_t back;
        ssio_info_t info;
        char name[96];

        snprintf(name, sizeof(name), "scalar k=%u trc=%u act=%u", (unsigned)CASES[c].k,
            (unsigned)CASES[c].trc, (unsigned)CASES[c].act);

        check(ssoti_save(PATH, &num) == SSIO_OK, name);
        check(ssoti_read(PATH, &back) == SSIO_OK && same_scalar(&num, &back), name);
        check(ssio_peek(PATH, &info) == SSIO_OK && info.type == SSIO_TYPE_SCALAR
            && info.nbases == CASES[c].k && info.trc_order == CASES[c].trc
            && info.nrows == 1 && info.ncols == 1, name);

        ssoti_free(&back);
        ssoti_free(&num);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_soa_roundtrip(void){

    static const bases_t SET_2[2] = {2, 5};
    static const bases_t SET_3[3] = {1, 4, 7};
    static const bases_t SET_BIG[3] = {1, 300, 65535};
    static const struct { const bases_t* bases; bases_t k; uint64_t nr, nc; ord_t trc, act; }
    CASES[] = {
        { NULL,    0, 0, 0, 0, 0 }, { SET_2,   2, 0, 0, 3, 3 }, { SET_2,   2, 4, 0, 2, 2 },
        { NULL,    0, 1, 1, 2, 0 }, { SET_2,   2, 1, 1, 1, 1 }, { SET_2,   2, 3, 2, 2, 2 },
        { SET_3,   3, 3, 3, 3, 3 }, { SET_3,   3, 2, 5, 4, 2 }, { SET_3,   3, 4, 4, 5, 5 },
        { SET_BIG, 3, 2, 2, 3, 3 }, { SET_2,   2, 5, 1, 4, 0 }, { SET_BIG, 3, 2, 2, 5, 5 },
    };
    size_t c;

    for (c = 0; c < sizeof(CASES) / sizeof(CASES[0]); c++){

        oarrss_t arr = make_soa(CASES[c].bases, CASES[c].k, CASES[c].nr, CASES[c].nc, CASES[c].trc,
            CASES[c].act);
        oarrss_t back;
        ssio_info_t info;
        char name[112];

        snprintf(name, sizeof(name), "SoA %llux%llu k=%u trc=%u act=%u",
            (unsigned long long)CASES[c].nr, (unsigned long long)CASES[c].nc,
            (unsigned)CASES[c].k, (unsigned)CASES[c].trc, (unsigned)CASES[c].act);

        check(oarrss_save(PATH, &arr) == SSIO_OK, name);
        check(oarrss_read(PATH, &back) == SSIO_OK && same_soa(&arr, &back), name);
        check(ssio_peek(PATH, &info) == SSIO_OK && info.type == SSIO_TYPE_SOA
            && info.nrows == CASES[c].nr && info.ncols == CASES[c].nc
            && info.nbases == CASES[c].k, name);

        oarrss_free(&back);
        oarrss_free(&arr);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_aos_roundtrip(void){

    static const struct { uint64_t nr, nc; } SHAPES[] = { {0, 0}, {0, 3}, {1, 1}, {3, 2}, {4, 4} };
    size_t c;

    for (c = 0; c < sizeof(SHAPES) / sizeof(SHAPES[0]); c++){

        arrss_t arr = make_aos(SHAPES[c].nr, SHAPES[c].nc);
        arrss_t back;
        ssio_info_t info;
        char name[64];

        snprintf(name, sizeof(name), "AoS %llux%llu", (unsigned long long)SHAPES[c].nr,
            (unsigned long long)SHAPES[c].nc);

        check(arrss_save(PATH, &arr) == SSIO_OK, name);
        check(arrss_read(PATH, &back) == SSIO_OK && same_aos(&arr, &back), name);
        check(ssio_peek(PATH, &info) == SSIO_OK && info.type == SSIO_TYPE_AOS
            && info.nrows == SHAPES[c].nr && info.ncols == SHAPES[c].nc && info.nbases == 0, name);

        arrss_free(&back);
        arrss_free(&arr);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A bases whose coefficients are all zero stay active through a round trip (nothing is compacted).
static void test_zero_bases_kept(void){

    static const bases_t SET[3] = {1, 2, 3};
    oarrss_t arr = oarrss_zeros(SET, 3, 2, 2, 2);
    oarrss_t back;

    check(oarrss_save(PATH, &arr) == SSIO_OK && oarrss_read(PATH, &back) == SSIO_OK
        && back.nbases == 3 && same_soa(&arr, &back), "zero coefficients keep their bases");

    oarrss_free(&back);
    oarrss_free(&arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Saving over an existing file replaces it entirely.
static void test_overwrite(void){

    static const bases_t SET[2] = {1, 2};
    oarrss_t big = make_soa(SET, 2, 5, 5, 4, 4);
    oarrss_t small = make_soa(SET, 2, 1, 1, 1, 1);
    oarrss_t back;

    check(oarrss_save(PATH, &big) == SSIO_OK && oarrss_save(PATH, &small) == SSIO_OK
        && oarrss_read(PATH, &back) == SSIO_OK && same_soa(&small, &back),
        "saving over an existing file replaces it");

    oarrss_free(&back);
    oarrss_free(&small);
    oarrss_free(&big);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ------------------------------------------     BAD FILES     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_bad_files(void){

    static const bases_t SET[3] = {1, 4, 7};
    ssotinum_t num = make_scalar(SET, 3, 3, 3);
    oarrss_t soa = make_soa(SET, 3, 2, 3, 3, 3);
    arrss_t aos = make_aos(2, 2);
    ssotinum_t s;
    arrss_t a;
    oarrss_t o;
    ssio_info_t info;
    int st[3];
    uint8_t* buf;
    size_t n, cut;

    // Missing file, and missing directory on save.
    remove(PATH);
    check(ssoti_read(PATH, &s) == SSIO_ERR_OPEN && s.nbases == 0, "scalar read: missing file");
    check(arrss_read(PATH, &a) == SSIO_ERR_OPEN && a.size == 0, "AoS read: missing file");
    check(oarrss_read(PATH, &o) == SSIO_ERR_OPEN && o.size == 0, "SoA read: missing file");
    check(ssio_peek(PATH, &info) == SSIO_ERR_OPEN, "peek: missing file");
    check(oarrss_save("no_such_directory/x.bin", &soa) == SSIO_ERR_OPEN, "save: missing directory");

    // NULL arguments.
    check(ssoti_save(NULL, &num) == SSIO_ERR_ARGUMENT && ssoti_save(PATH, NULL) == SSIO_ERR_ARGUMENT
        && oarrss_read(PATH, NULL) == SSIO_ERR_ARGUMENT, "NULL arguments");

    // Empty file, short garbage, another format's magic.
    spit(PATH, (const uint8_t*)"", 0);
    read_all(PATH, st);
    check(st[0] == SSIO_ERR_MAGIC && st[1] == SSIO_ERR_MAGIC && st[2] == SSIO_ERR_MAGIC,
        "empty file: bad magic");

    {
        const uint8_t sparse_head[64] = {0x93, 'O', 'T', 'I', 1, 0, 21, 0};

        spit(PATH, sparse_head, sizeof(sparse_head));
        read_all(PATH, st);
        check(st[0] == SSIO_ERR_MAGIC && st[1] == SSIO_ERR_MAGIC && st[2] == SSIO_ERR_MAGIC,
            "a sparse (matso) file: bad magic");
    }

    // Another type than requested.
    ssoti_save(PATH, &num);
    read_all(PATH, st);
    check(st[0] == SSIO_OK && st[1] == SSIO_ERR_TYPE && st[2] == SSIO_ERR_TYPE,
        "scalar file read as array: wrong type");
    oarrss_save(PATH, &soa);
    read_all(PATH, st);
    check(st[0] == SSIO_ERR_TYPE && st[1] == SSIO_ERR_TYPE && st[2] == SSIO_OK,
        "SoA file read as scalar or AoS: wrong type");
    arrss_save(PATH, &aos);
    read_all(PATH, st);
    check(st[0] == SSIO_ERR_TYPE && st[1] == SSIO_OK && st[2] == SSIO_ERR_TYPE,
        "AoS file read as scalar or SoA: wrong type");

    // Truncated everywhere in each kind of file: in the magic, the header and the payload.
    oarrss_save(PATH, &soa);
    buf = slurp(PATH, &n);

    for (cut = 0; cut < n; cut += (cut < 80) ? 3 : 41){

        int status;

        spit(PATH, buf, cut);
        status = oarrss_read(PATH, &o);

        if (cut < 4){
            check(status == SSIO_ERR_MAGIC && o.size == 0, "SoA cut inside the magic");
        } else {
            check(status == SSIO_ERR_TRUNCATED && o.size == 0, "SoA truncated file");
        }

    }

    free(buf);

    arrss_save(PATH, &aos);
    buf = slurp(PATH, &n);

    for (cut = 4; cut < n; cut += 23){

        spit(PATH, buf, cut);
        check(arrss_read(PATH, &a) == SSIO_ERR_TRUNCATED && a.size == 0, "AoS truncated file");

    }

    free(buf);

    ssoti_save(PATH, &num);
    buf = slurp(PATH, &n);

    for (cut = 4; cut < n; cut += 17){

        spit(PATH, buf, cut);
        check(ssoti_read(PATH, &s) == SSIO_ERR_TRUNCATED && s.nbases == 0, "scalar truncated file");

    }

    // Trailing bytes.
    {
        uint8_t* longer = (uint8_t*)malloc(n + 1);

        memcpy(longer, buf, n);
        longer[n] = 0;
        spit(PATH, longer, n + 1);
        check(ssoti_read(PATH, &s) == SSIO_ERR_SIZE, "scalar file with a trailing byte");
        free(longer);
    }

    // Header fields.
    {
        uint8_t* bad = (uint8_t*)malloc(n);
        uint16_t version = 2;

        memcpy(bad, buf, n);
        memcpy(bad + 4, &version, sizeof(version));
        spit(PATH, bad, n);
        check(ssoti_read(PATH, &s) == SSIO_ERR_VERSION, "unsupported version");

        memcpy(bad, buf, n);
        bad[6] = 9;
        spit(PATH, bad, n);
        check(ssoti_read(PATH, &s) == SSIO_ERR_FORMAT, "unknown type tag");

        memcpy(bad, buf, n);
        bad[7] = (uint8_t)(3 - bad[7]);
        spit(PATH, bad, n);
        check(ssoti_read(PATH, &s) == SSIO_ERR_FORMAT, "other byte order");

        memcpy(bad, buf, n);
        bad[8] = 4;
        spit(PATH, bad, n);
        check(ssoti_read(PATH, &s) == SSIO_ERR_FORMAT, "other coefficient size");

        memcpy(bad, buf, n);
        bad[11] = (uint8_t)(bad[10] + 1);
        spit(PATH, bad, n);
        check(ssoti_read(PATH, &s) == SSIO_ERR_FORMAT, "active order above truncation order");

        memcpy(bad, buf, n);
        bad[12] = (uint8_t)(bad[12] + 1);
        spit(PATH, bad, n);
        check(ssoti_read(PATH, &s) == SSIO_ERR_FORMAT, "wrong number of bases");

        // Labels not increasing (labels are at byte 64: 1, 4, 7 -> 4, 1, 7).
        memcpy(bad, buf, n);
        bad[64] = 4;
        bad[66] = 1;
        spit(PATH, bad, n);
        check(ssoti_read(PATH, &s) == SSIO_ERR_FORMAT && s.nbases == 0, "unsorted labels");

        // Nonzero padding after the labels.
        memcpy(bad, buf, n);
        bad[64 + 6] = 1;
        spit(PATH, bad, n);
        check(ssoti_read(PATH, &s) == SSIO_ERR_FORMAT, "nonzero label padding");

        free(bad);
    }

    free(buf);

    // Coefficients above the active order: a scalar saved with act = 1 whose order-2 slot is set.
    {
        ssotinum_t low = make_scalar(SET, 3, 3, 1);
        ssotinum_t back = ssoti_init();

        check(ssoti_save(PATH, &low) == SSIO_OK && ssoti_read(PATH, &back) == SSIO_OK
            && back.act_order == 1, "act < trc round trip");
        ssoti_free(&back);

        low.p_im[sshelp_order_offset(3, 2)] = 1.0;
        check(ssoti_save(PATH, &low) == SSIO_OK && ssoti_read(PATH, &back) == SSIO_ERR_FORMAT
            && back.nbases == 0, "nonzero coefficient above the active order");
        ssoti_free(&low);
    }

    // A header that claims far more than the file holds must not be trusted: the payload field is
    // consistent with the 64-byte file, so only the shape fields are bad.
    {
        uint8_t head[64];
        uint64_t rows, zero = 0;
        uint32_t k = 65535;

        ssoti_save(PATH, &num);
        buf = slurp(PATH, &n);
        memcpy(head, buf, 64);
        memcpy(head + 32, &zero, sizeof(zero));

        // Both dimensions 2^40: the element count overflows 64 bits.
        rows = 1ULL << 40;
        memcpy(head + 16, &rows, sizeof(rows));
        memcpy(head + 24, &rows, sizeof(rows));
        head[6] = SSIO_TYPE_SOA;
        spit(PATH, head, 64);
        check(oarrss_read(PATH, &o) == SSIO_ERR_FORMAT && o.size == 0, "SoA claiming 2^80 elements");

        head[6] = SSIO_TYPE_AOS;
        head[12] = head[13] = head[14] = head[15] = 0;
        spit(PATH, head, 64);
        check(arrss_read(PATH, &a) == SSIO_ERR_FORMAT && a.size == 0, "AoS claiming 2^80 elements");

        // 2^20 x 2^20 fits in 64 bits but not in the file.
        rows = 1ULL << 20;
        memcpy(head + 16, &rows, sizeof(rows));
        memcpy(head + 24, &rows, sizeof(rows));
        spit(PATH, head, 64);
        check(arrss_read(PATH, &a) == SSIO_ERR_FORMAT && a.size == 0, "AoS claiming 2^40 elements");

        memcpy(head + 12, buf + 12, 4);
        head[6] = SSIO_TYPE_SOA;
        spit(PATH, head, 64);
        check(oarrss_read(PATH, &o) == SSIO_ERR_FORMAT && o.size == 0, "SoA claiming 2^40 elements");

        // 65535 bases at order 200: the coefficient count overflows.
        memcpy(head, buf, 64);
        memcpy(head + 12, &k, sizeof(k));
        memcpy(head + 32, &zero, sizeof(zero));
        head[10] = 200;
        head[11] = 200;
        spit(PATH, head, 64);
        check(ssoti_read(PATH, &s) == SSIO_ERR_FORMAT && s.nbases == 0,
            "scalar claiming 65535 bases at order 200");

        free(buf);
    }

    // An AoS record claiming more than the payload left.
    {
        arrss_save(PATH, &aos);
        buf = slurp(PATH, &n);
        buf[64 + 2] = 0xFF;
        buf[64 + 3] = 0xFF;
        spit(PATH, buf, n);
        check(arrss_read(PATH, &a) == SSIO_ERR_FORMAT && a.size == 0, "AoS record with a huge k");
        free(buf);
    }

    remove(PATH);
    ssoti_free(&num);
    oarrss_free(&soa);
    arrss_free(&aos);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Saving an object the format cannot represent fails without creating a file.
static void test_unrepresentable(void){

    static const bases_t UNSORTED[2] = {5, 2};
    ssotinum_t num = make_scalar(UNSORTED, 2, 2, 2);
    FILE* f;

    remove(PATH);
    check(ssoti_save(PATH, &num) == SSIO_ERR_ARGUMENT, "saving a scalar with unsorted bases");
    f = fopen(PATH, "rb");
    check(f == NULL, "a failed save creates no file");

    if (f != NULL){
        fclose(f);
    }

    ssoti_free(&num);
    remove(PATH);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    test_scalar_roundtrip();
    test_soa_roundtrip();
    test_aos_roundtrip();
    test_zero_bases_kept();
    test_overwrite();
    test_bad_files();
    test_unrepresentable();

    remove(PATH);

    if (n_failed != 0){
        fprintf(stderr, "%d semisparse I/O test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C semisparse I/O tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
