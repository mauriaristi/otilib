! ********************************************************************************************************
! Allocation lifetime: many CFI_allocate results (both layouts, every result kind, failures included)
! are deallocated by Fortran and nothing leaks. ctest fortran_nd_leaks runs it under `leaks --atExit`.
! ********************************************************************************************************
program test_nd_alloc

  use oti_real_ndarray
  use nd_test_util
  implicit none

  integer, parameter :: niter = 2000
  real(dp) :: a(6, 5), m(4, 4)
  real(dp), allocatable :: r0, r1(:), r2(:,:), loc(:,:)
  integer :: it, i, st
  real(dp) :: acc

  a = reshape([(real(i, dp) / 7, i = 1, 30)], [6, 5])
  m = 0
  do i = 1, 4
    m(i, i) = 3
  end do
  m(1, 4) = 1
  acc = 0
  do it = 1, niter
    call nd_add(a, a(:, 5:1:-1), r2, layout=merge('reversed', 'fortran ', mod(it, 2) == 0))
    call nd_exp(a(1:6:2, :), r2)
    call nd_sum(a, r1, dim=1)
    call nd_sum(a, r0)
    call nd_matmul(a, transpose(a), r2)
    call nd_inv(m, r2)
    call nd_solve(m, a(1:4, 1), r1)
    call nd_det(m, r0)
    call nd_linspace(0.0_dp, 1.0_dp, 17, r1)
    call nd_add(a, a(1:2, :), r2, stat=st)            ! fails: nothing allocated, nothing leaked
    call nd_inv(a(1:2, 1:2) * 0, r2, stat=st)         ! singular: positive info, nothing allocated
    call local_result(loc)
    acc = acc + r0 + sum(r1) + sum(loc)
    deallocate(loc)
  end do
  call check(acc == acc, 'loop finished')
  call check(.not. allocated(r2), 'the last failed call left r2 unallocated')
  ! Main-program allocatables are not deallocated at exit: free the last results for `leaks`.
  deallocate(r0, r1)
  call summary('test_nd_alloc')

contains

  ! ******************************************************************************************************
  ! A local result that is deallocated automatically on return, and one returned to the caller.
  subroutine local_result(out)
    real(dp), allocatable, intent(out) :: out(:,:)
    real(dp), allocatable :: tmp(:,:)
    call nd_full([3, 3], 2.0_dp, tmp)
    call nd_mul(tmp, tmp, out)
  end subroutine local_result
  ! ------------------------------------------------------------------------------------------------------

end program test_nd_alloc
