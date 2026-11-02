! ********************************************************************************************************
! Helpers of the Fortran ndarray conformance tests (src/fortran/ndarray/tests): pass / fail counting,
! tolerant comparisons and the exit status.
! ********************************************************************************************************
module nd_test_util

  use, intrinsic :: iso_c_binding, only: c_double, c_int
  implicit none
  private

  integer, parameter, public :: dp = c_double
  integer, public, save :: nfail = 0, npass = 0

  public :: check, close_to, all_close, summary

  interface
    integer(c_int) function c_test_shim(verbose) bind(C, name='otif_test_shim_c')
      import :: c_int
      integer(c_int), value :: verbose
    end function c_test_shim
  end interface
  public :: c_test_shim

contains

  ! ******************************************************************************************************
  !> Records one check and prints it.
  subroutine check(cond, what)
    logical, intent(in) :: cond
    character(*), intent(in) :: what
    if (cond) then
      npass = npass + 1
      write(*, '(a,a)') '  PASS ', what
    else
      nfail = nfail + 1
      write(*, '(a,a)') '  FAIL ', what
    end if
  end subroutine check
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  !> |a - b| <= tol * max(1, |b|) (tol defaults to 1e-13).
  elemental logical function close_to(a, b, tol)
    real(dp), intent(in) :: a, b
    real(dp), intent(in), optional :: tol
    real(dp) :: t
    t = 1.0e-13_dp
    if (present(tol)) t = tol
    close_to = abs(a - b) <= t * max(1.0_dp, abs(b))
  end function close_to
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  !> Same size and close_to element by element, in array element order.
  logical function all_close(a, b, tol)
    real(dp), intent(in) :: a(:), b(:)
    real(dp), intent(in), optional :: tol
    all_close = size(a) == size(b)
    if (all_close) all_close = all(close_to(a, b, tol))
  end function all_close
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  !> Prints the totals; a nonzero exit status when a check failed.
  subroutine summary(prog)
    character(*), intent(in) :: prog
    write(*, '(a,a,i0,a,i0)') prog, ' summary: pass=', npass, ' fail=', nfail
    if (nfail > 0) error stop 1
  end subroutine summary
  ! ------------------------------------------------------------------------------------------------------

end module nd_test_util
