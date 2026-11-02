! ********************************************************************************************************
! The gfortran 16.2 SAVE / dtype bug pattern (S3; decision 24): results written into SAVEd actuals
! (module variables, SAVE locals), directly and through a user wrapper that forwards its own
! intent(out) dummy. With the module's local temporary + move_alloc the descriptor's type and rank
! are right: list-directed output, copy-in of non-contiguous sections (internal_pack) and select rank
! all read them. A broken dtype aborts ("type_name(): Bad type") or picks the wrong rank.
! ********************************************************************************************************
module nd_saved_vars

  use nd_test_util, only: dp
  implicit none

  real(dp), allocatable :: g0, g1(:), g2(:,:), g3(:,:,:), h2(:,:)

end module nd_saved_vars


program test_nd_saved

  use oti_real_ndarray
  use nd_test_util
  use nd_saved_vars
  implicit none

  real(dp) :: a(3, 4)
  character(512) :: line
  integer :: i, pass

  a = reshape([(real(i, dp), i = 1, 12)], [3, 4])

  do pass = 1, 2
    call nd_add(a, a, g2)
    call check(allocated(g2) .and. all(shape(g2) == [3, 4]) .and. all(g2 == 2 * a), &
               'module variable g2 <- nd_add')
    write(line, *) g2
    call check(len_trim(line) > 0, 'list-directed output of g2 (dtype type)')
    call check(rank_of(g2) == 2, 'select rank sees rank 2 (dtype rank)')
    call check(explicit_sum(g2(1:3:2, :), 8) == sum(2 * a(1:3:2, :)), &
               'copy-in of a strided section of g2 to an explicit-shape dummy')

    call nd_sum(a, g1, dim=2)
    call check(all(g1 == sum(a, dim=2)) .and. rank_of(g1) == 1, 'module variable g1 <- nd_sum dim=2')
    write(line, *) g1
    call check(len_trim(line) > 0, 'list-directed output of g1')

    call nd_sum(a, g0)
    call check(g0 == sum(a) .and. rank_of(g0) == 0, 'module variable g0 (rank 0) <- nd_sum')
    write(line, *) g0
    call check(len_trim(line) > 0, 'list-directed output of g0')

    call nd_ones([2, 3, 2], g3, layout='reversed')
    call check(all(shape(g3) == [2, 3, 2]) .and. rank_of(g3) == 3 .and. all(g3 == 1), &
               "module variable g3 <- nd_ones, layout='reversed'")
    write(line, *) g3
    call check(len_trim(line) > 0, 'list-directed output of g3')

    call user_wrapper(a, g2)
    call check(all(g2 == a * a) .and. rank_of(g2) == 2, 'through a wrapper forwarding intent(out)')
    write(line, *) g2(2, :)
    call check(len_trim(line) > 0, 'list-directed output after the wrapper')

    call saved_local(a)
    call nd_matmul(g2, transpose(a), h2, stat=i)
    call check(i == OTI_OK .and. all(shape(h2) == [3, 3]) .and. rank_of(h2) == 2, &
               'module variable g2 as an input, h2 <- nd_matmul(g2, a^T)')
    write(line, *) h2
    call check(len_trim(line) > 0, 'list-directed output of h2')
  end do
  call summary('test_nd_saved')

contains

  ! ******************************************************************************************************
  ! A user wrapper: its own intent(out) allocatable dummy (associated with a module variable) goes to
  ! the module as the result.
  subroutine user_wrapper(x, r)
    real(dp), intent(in) :: x(:,:)
    real(dp), allocatable, intent(out) :: r(:,:)
    call nd_mul(x, x, r)
  end subroutine user_wrapper
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  ! A SAVE local result, reused across calls.
  subroutine saved_local(x)
    real(dp), intent(in) :: x(:,:)
    real(dp), allocatable, save :: s2(:,:)
    character(256) :: buf
    call nd_sqrt(x, s2)
    call check(all(s2 == sqrt(x)) .and. rank_of(s2) == 2, 'SAVE local s2 <- nd_sqrt')
    write(buf, *) s2(:, 1)
    call check(len_trim(buf) > 0, 'list-directed output of the SAVE local')
  end subroutine saved_local
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  integer function rank_of(x)
    real(dp), intent(in) :: x(..)
    select rank (x)
    rank (0)
      rank_of = 0
    rank (1)
      rank_of = 1
    rank (2)
      rank_of = 2
    rank (3)
      rank_of = 3
    rank default
      rank_of = -1
    end select
  end function rank_of
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  real(dp) function explicit_sum(x, nx)
    integer, intent(in) :: nx
    real(dp), intent(in) :: x(nx)
    explicit_sum = sum(x)
  end function explicit_sum
  ! ------------------------------------------------------------------------------------------------------

end program test_nd_saved
