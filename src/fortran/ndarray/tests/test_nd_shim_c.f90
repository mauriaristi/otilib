! ********************************************************************************************************
! Shim validator checks on hand-built descriptors (shim_checks.c), plus the module / shim self-check.
! ********************************************************************************************************
program test_nd_shim_c

  use oti_real_ndarray
  use nd_test_util
  implicit none

  integer :: st, nbad

  call nd_selfcheck(stat=st)
  call check(st == OTI_OK, 'nd_selfcheck: ndarr_t and the request match the shim')
  nbad = c_test_shim(1)
  call check(nbad == 0, 'shim_checks.c: every hand-built descriptor check')
  call summary('test_nd_shim_c')

end program test_nd_shim_c
