// Heap tracker for the C memory benchmark (bench_semisparse_memory.c), macOS only.
//
// Built as a dylib and linked into the benchmark. dyld applies its __interpose section at launch,
// so every malloc family call of the process (library, OpenMP runtime, libc) goes through the
// wrappers below. Each wrapper updates the live byte count by the allocator's usable size
// (malloc_size) and keeps the peak. Allocations that bypass malloc (mmap, e.g. OpenBLAS's
// work buffers) are not seen.

#include <malloc/malloc.h>
#include <stdatomic.h>
#include <stdint.h>
#include <stdlib.h>

#define MEMTRACK_INTERPOSE(repl, orig) \
    __attribute__((used)) static struct { const void* r; const void* o; } \
    interpose_##orig __attribute__((section("__DATA,__interpose"))) = \
    { (const void*)(unsigned long)&repl, (const void*)(unsigned long)&orig }

static _Atomic int64_t memtrack_live_bytes = 0;
static _Atomic int64_t memtrack_peak_bytes = 0;


// *******************************************************************************************************
static void memtrack_add(int64_t delta){

    int64_t now = atomic_fetch_add(&memtrack_live_bytes, delta) + delta;
    int64_t peak = atomic_load(&memtrack_peak_bytes);

    while (now > peak && !atomic_compare_exchange_weak(&memtrack_peak_bytes, &peak, now)){
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes currently allocated through the malloc family.
int64_t memtrack_live(void){

    return atomic_load(&memtrack_live_bytes);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Largest live byte count since the last memtrack_reset_peak().
int64_t memtrack_peak(void){

    return atomic_load(&memtrack_peak_bytes);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Restart the peak from the current live byte count.
void memtrack_reset_peak(void){

    atomic_store(&memtrack_peak_bytes, atomic_load(&memtrack_live_bytes));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void* mt_malloc(size_t size){

    void* p = malloc(size);

    if (p){
        memtrack_add((int64_t)malloc_size(p));
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void* mt_calloc(size_t count, size_t size){

    void* p = calloc(count, size);

    if (p){
        memtrack_add((int64_t)malloc_size(p));
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void* mt_realloc(void* ptr, size_t size){

    int64_t old = ptr ? (int64_t)malloc_size(ptr) : 0;
    void* p = realloc(ptr, size);

    if (p){
        memtrack_add((int64_t)malloc_size(p) - old);
    } else if (size == 0 && ptr){
        memtrack_add(-old);
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void mt_free(void* ptr){

    if (ptr){
        memtrack_add(-(int64_t)malloc_size(ptr));
    }

    free(ptr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int mt_posix_memalign(void** out, size_t align, size_t size){

    int rc = posix_memalign(out, align, size);

    if (rc == 0 && *out){
        memtrack_add((int64_t)malloc_size(*out));
    }

    return rc;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void* mt_aligned_alloc(size_t align, size_t size){

    void* p = aligned_alloc(align, size);

    if (p){
        memtrack_add((int64_t)malloc_size(p));
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void* mt_valloc(size_t size){

    void* p = valloc(size);

    if (p){
        memtrack_add((int64_t)malloc_size(p));
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------

MEMTRACK_INTERPOSE(mt_malloc, malloc);
MEMTRACK_INTERPOSE(mt_calloc, calloc);
MEMTRACK_INTERPOSE(mt_realloc, realloc);
MEMTRACK_INTERPOSE(mt_free, free);
MEMTRACK_INTERPOSE(mt_posix_memalign, posix_memalign);
MEMTRACK_INTERPOSE(mt_aligned_alloc, aligned_alloc);
MEMTRACK_INTERPOSE(mt_valloc, valloc);
