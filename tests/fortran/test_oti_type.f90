PROGRAM test_oti

  USE otistamod

  IMPLICIT NONE

  TYPE(oti_t) ::  x, y, z(3)
  REAL(dp)::arr(3,3)
  INTEGER:: i, j

  arr = 1.0_dp

  x      = 10.5_dp
  z(:)   = eps(2,order=2)
  z(:)%r = 4.5d0
  z(2)   = 0.5d0
  y      = eps(2,order=2)

  print*, ' Program to test oti_type module.'

  CALL pprint(x,advance='YES')

  y%act_ord = 2

  CALL pprint(y)

  DO i=1,2
    arr(:,i) = z%im(i)
  END DO 

  CALL PPRINT(z)

END PROGRAM test_oti