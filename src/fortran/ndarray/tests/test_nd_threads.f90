! ********************************************************************************************************
! Thread control (contracts S29): the optional nthreads argument. nthreads < 0 is rejected; 0, 1 and 4
! give bit-identical results (the core is deterministic at every thread count); calls with nthreads=1
! from inside the caller's own OpenMP region (libgomp under gfortran, libomp under flang) are correct.
! ********************************************************************************************************
program test_nd_threads

  !$ use omp_lib
  use oti_real_ndarray
  use nd_test_util
  implicit none

  integer, parameter :: n = 2**19, nt = 4, nm = 64
  real(dp), allocatable :: x(:), y(:), r0(:), r1(:), r4(:), s0, s1, s4
  real(dp), allocatable :: m(:,:), p(:,:)
  real(dp) :: out(8)
  integer :: i, st, bad, nthr

  ! Explicit loops throughout: with -fopenmp gfortran puts array temporaries on the (thread) stack,
  ! and 2^19-element temporaries overflow it.
  allocate(x(n), y(n))
  do i = 1, n
    x(i) = sin(real(i, dp))
    y(i) = cos(real(i, dp))
  end do

  call nd_add(x, y, r0, nthreads=-1, stat=st)
  call check(st == OTI_ERR_ARGUMENT .and. .not. allocated(r0), 'nthreads=-1: OTI_ERR_ARGUMENT')
  call nd_binary_into(ND_OP_ADD, x(1:8), y(1:8), out, nthreads=-3, stat=st)
  call check(st == OTI_ERR_ARGUMENT, '_into with nthreads=-3: OTI_ERR_ARGUMENT')

  call nd_mul(x, y, r0)
  call nd_mul(x, y, r1, nthreads=1)
  call nd_mul(x, y, r4, nthreads=nt)
  bad = 0
  do i = 1, n
    if (r0(i) /= x(i) * y(i) .or. r1(i) /= r0(i) .or. r4(i) /= r0(i)) bad = bad + 1
  end do
  call check(bad == 0, 'nd_mul of 2^19 elements: nthreads absent, 1 and 4 agree bitwise')
  call nd_sum(x, s0)
  call nd_sum(x, s1, nthreads=1)
  call nd_sum(x, s4, nthreads=nt)
  call check(s1 == s0 .and. s4 == s0, 'nd_sum of 2^19 elements: bit-identical for nthreads 0, 1, 4')
  call nd_exp(x, r1, nthreads=0)
  call nd_exp(x, r4, nthreads=nt)
  bad = 0
  do i = 1, n
    if (r1(i) /= r4(i)) bad = bad + 1
  end do
  call check(bad == 0, 'nd_exp: nthreads 0 and 4 agree bitwise')

  ! Inside the caller's own parallel region: nthreads=1 in every thread.
  nthr = 1
  bad = 0
  !$omp parallel private(r1, m, p, st, i) reduction(+:bad) shared(nthr)
  !$ if (omp_get_thread_num() == 0) nthr = omp_get_num_threads()
  call nd_add(x, y, r1, nthreads=1, stat=st)
  if (st /= OTI_OK) bad = bad + 1
  if (st == OTI_OK) then
    do i = 1, n
      if (r1(i) /= x(i) + y(i)) bad = bad + 1
    end do
  end if
  allocate(m(nm, nm))
  m = 0
  do i = 1, nm
    m(i, i) = 2
  end do
  call nd_matmul(m, m, p, nthreads=1, stat=st)
  if (st /= OTI_OK) bad = bad + 1
  if (st == OTI_OK) then
    do i = 1, nm
      if (p(i, i) /= 4 .or. sum(abs(p(:, i))) /= 4) bad = bad + 1
    end do
  end if
  deallocate(m)
  !$omp end parallel
  write(*, '(a,i0,a)') '  (caller region with ', nthr, ' threads)'
  call check(bad == 0, 'calls with nthreads=1 inside the caller''s OpenMP region are correct')

  call summary('test_nd_threads')

end program test_nd_threads
