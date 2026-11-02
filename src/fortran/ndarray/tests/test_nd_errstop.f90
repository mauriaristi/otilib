! ********************************************************************************************************
! Without stat, a failing call stops the program with a message naming the status and the C function
! (ctest checks the message: fortran_nd_errstop).
! ********************************************************************************************************
program test_nd_errstop

  use oti_real_ndarray
  use nd_test_util, only: dp
  implicit none

  real(dp) :: a(2), b(3)
  real(dp), allocatable :: r(:)

  a = 1.0_dp
  b = 2.0_dp
  call nd_add(a, b, r)
  print *, 'not reached', allocated(r)

end program test_nd_errstop
