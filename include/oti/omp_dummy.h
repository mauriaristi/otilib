#ifndef OMP_MOCKUP_H
#define OMP_MOCKUP_H


#ifndef _LIBGOMP_OMP_LOCK_DEFINED
#define _LIBGOMP_OMP_LOCK_DEFINED 1
/* These two structures get edited by the libgomp build process to 
   reflect the shape of the two types.  Their internals are private
   to the library.  */

typedef struct
{
  unsigned char _x[4] 
    __attribute__((__aligned__(4)));
} omp_lock_t;

typedef struct
{
  unsigned char _x[8 + sizeof (void *)] 
    __attribute__((__aligned__(sizeof (void *))));
} omp_nest_lock_t;

#endif

typedef enum omp_sched_t
{
  omp_sched_static = 1,
  omp_sched_dynamic = 2,
  omp_sched_guided = 3,
  omp_sched_auto = 4
} omp_sched_t;



void omp_set_num_threads (int);
int omp_get_num_threads (void){
	return 1;
};
int omp_get_max_threads (void){
	return 1;
};
int omp_get_thread_num (void){
	return 0;
};
int omp_get_num_procs (void);

int omp_in_parallel (void);

void omp_set_dynamic (int);
int omp_get_dynamic (void);

void omp_set_nested (int);
int omp_get_nested (void);

void omp_init_lock (omp_lock_t *);
void omp_destroy_lock (omp_lock_t *);
void omp_set_lock (omp_lock_t *);
void omp_unset_lock (omp_lock_t *);
int omp_test_lock (omp_lock_t *);

void omp_init_nest_lock (omp_nest_lock_t *);
void omp_destroy_nest_lock (omp_nest_lock_t *);
void omp_set_nest_lock (omp_nest_lock_t *);
void omp_unset_nest_lock (omp_nest_lock_t *);
int omp_test_nest_lock (omp_nest_lock_t *);

double omp_get_wtime (void);
double omp_get_wtick (void);

void omp_set_schedule (omp_sched_t, int);
void omp_get_schedule (omp_sched_t *, int *);
int omp_get_thread_limit (void);
void omp_set_max_active_levels (int);
int omp_get_max_active_levels (void);
int omp_get_level (void);
int omp_get_ancestor_thread_num (int);
int omp_get_team_size (int);
int omp_get_active_level (void);

#endif
