! ********************************************************************************************************
! Conformance of the Fortran ndarray module (Phase F2): borrowed sections without copies, elementwise
! operations, math functions, reductions, creators, layouts (a) and (b), ranks 0 and 15, zero extents
! and statuses. Run once per Fortran vendor (ctest fortran_nd_ops).
! ********************************************************************************************************
program test_nd_ops

  use, intrinsic :: iso_c_binding, only: c_loc, c_associated, c_int64_t
  use oti_real_ndarray
  use nd_test_util
  implicit none

  integer, parameter :: n = 7, m = 9
  real(dp), target :: big(n, m)
  real(dp) :: work(n, m)
  integer :: i

  big = reshape([(real(i, dp), i = 1, n * m)], [n, m])

  call t_borrow()
  call t_binary()
  call t_unary()
  call t_reduce()
  call t_creators()
  call t_zero_extents()
  call t_rank15()
  call summary('test_nd_ops')

contains

  ! ******************************************************************************************************
  ! Sections reach the core without a copy: the borrowed descriptor points into big.
  subroutine t_borrow()
    type(ndarr_t) :: nd
    integer :: st

    call nd_borrow(big(1:n:2, :), nd)
    call check(c_associated(nd%data, c_loc(big(1, 1))) .and. nd%ndim == 2 .and. &
               all(nd%shape(1:2) == [4, m]) .and. all(nd%strides(1:2) == [2, n]), &
               'borrow big(1:n:2,:): strides (2, n), no copy')
    call nd_borrow(big(:, m:1:-1), nd)
    call check(c_associated(nd%data, c_loc(big(1, m))) .and. all(nd%strides(1:2) == [1, -n]), &
               'borrow big(:,m:1:-1): strides (1, -n), data at big(1,m)')
    call nd_borrow(big(2:, 3:5), nd)
    call check(c_associated(nd%data, c_loc(big(2, 3))) .and. all(nd%shape(1:2) == [n - 1, 3]) .and. &
               all(nd%strides(1:2) == [1, n]), 'borrow big(2:,3:5): offset section, no copy')
    call nd_borrow(big(n:1:-3, 7:1:-2), nd)
    call check(c_associated(nd%data, c_loc(big(n, 7))) .and. all(nd%shape(1:2) == [3, 4]) .and. &
               all(nd%strides(1:2) == [-3, -2 * n]), 'borrow big(n:1:-3,7:1:-2): strides (-3, -2n)')
    call nd_borrow(big(3, :), nd)
    call check(nd%ndim == 1 .and. nd%strides(1) == n .and. c_associated(nd%data, c_loc(big(3, 1))), &
               'borrow a row: stride n')
    call nd_borrow(big(:, 4), nd)
    call check(nd%strides(1) == 1 .and. iand(nd%flags, ND_F_CONTIG) /= 0 .and. &
               iand(nd%flags, ND_WRITEABLE) == 0, 'borrow a column: contiguous, read-only')
    call nd_borrow(big(2, 2), nd)
    call check(nd%ndim == 0 .and. c_associated(nd%data, c_loc(big(2, 2))), 'borrow a scalar: rank 0')
    call nd_borrow(big(3:2, :), nd, stat=st)
    call check(st == OTI_OK .and. all(nd%shape(1:2) == [0, m]) .and. .not. c_associated(nd%data), &
               'borrow big(3:2,:): size 0, data NULL')
    call nd_borrow_writeable(big(1:n:2, 2:3), nd)
    call check(iand(nd%flags, ND_WRITEABLE) /= 0 .and. c_associated(nd%data, c_loc(big(1, 2))), &
               'borrow_writeable sets ND_WRITEABLE')
  end subroutine t_borrow
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  subroutine t_binary()
    real(dp), allocatable :: r2(:,:), r1(:), r0, x(:,:)
    real(dp) :: p(n, m), q(n, m), expect(n, m)
    character(:), allocatable :: where
    integer :: st, j

    call nd_add(big, big, r2)
    call check(all(shape(r2) == [n, m]) .and. all(r2 == 2 * big), 'nd_add whole arrays')
    call nd_mul(big(1:n:2, :), big(n:1:-2, m:1:-1), r2)
    call check(all(shape(r2) == [4, m]) .and. all(r2 == big(1:n:2, :) * big(n:1:-2, m:1:-1)), &
               'nd_mul strided x reversed sections')
    p = big / 10
    q = big / 7 + 1
    call nd_sub(p, q, r2)
    call check(all(r2 == p - q), 'nd_sub')
    call nd_div(p, q, r2)
    call check(all(r2 == p / q), 'nd_div')
    call nd_pow(p, q, r2)
    call check(all(close_to(r2, p ** q)), 'nd_pow')
    call nd_maximum(p, q, r2)
    call check(all(r2 == max(p, q)), 'nd_maximum')
    call nd_minimum(p, q, r2)
    call check(all(r2 == min(p, q)), 'nd_minimum')
    call nd_binary(ND_OP_ADD, big(2:, 3:5), 0.5_dp, r2)
    call check(all(r2 == big(2:, 3:5) + 0.5_dp), 'nd_binary with a scalar actual (rank 0)')

    ! Broadcasting aligns the last dimensions: a(n, m) + b(m).
    call nd_add(big, big(1, :), r2)
    do j = 1, m
      expect(:, j) = big(:, j) + big(1, j)
    end do
    call check(all(r2 == expect), 'broadcast a(n,m) + b(m) along the last dimension')

    call nd_add(2.0_dp, 3.0_dp, r0)
    call check(allocated(r0), 'rank-0 result allocated')
    if (allocated(r0)) call check(r0 == 5.0_dp, 'rank-0 result value')

    ! Layout (b): reversed extents, the C-order memory of the result.
    call nd_sub(big, 1.0_dp, x, layout='reversed')
    call check(all(shape(x) == [m, n]) .and. all(x == transpose(big - 1)), &
               "layout='reversed': transposed result")
    call nd_sub(big, 1.0_dp, x, layout='fortran')
    call check(all(shape(x) == [n, m]) .and. all(x == big - 1), "layout='fortran'")

    ! In place into a section of an existing array: only the section changes.
    work = big
    expect = big
    expect(1:n:2, m:1:-1) = big(1:n:2, m:1:-1) + 100
    call nd_binary_into(ND_OP_ADD, big(1:n:2, m:1:-1), 100.0_dp, work(1:n:2, m:1:-1))
    call check(all(work == expect), 'nd_binary_into a strided reversed section, in place')

    ! A previously allocated result is replaced.
    deallocate(r2)
    allocate(r2(2, 2))
    call nd_add(big, big, r2)
    call check(all(shape(r2) == [n, m]), 'allocated result replaced')

    ! Statuses.
    call nd_add(big, big(1:3, :), r2, stat=st)
    call check(st == OTI_ERR_SHAPE .and. .not. allocated(r2), 'shape mismatch: OTI_ERR_SHAPE')
    call check(nd_last_error(where) == OTI_ERR_SHAPE .and. where == 'nd_binary_to', &
               'last error names nd_binary_to')
    call nd_add(big, big, r1, stat=st)
    call check(st == OTI_ERR_SHAPE .and. .not. allocated(r1), 'result of the wrong rank: OTI_ERR_SHAPE')
    call nd_add(big, big, r2, layout='rowmajor', stat=st)
    call check(st == OTI_ERR_ARGUMENT .and. .not. allocated(r2), 'unknown layout: OTI_ERR_ARGUMENT')
    call nd_binary(99, big, big, r2, stat=st)
    call check(st == OTI_ERR_ARGUMENT, 'unknown op: OTI_ERR_ARGUMENT')
    call nd_binary_into(ND_OP_ADD, big, big, work(1:3, :), stat=st)
    call check(st == OTI_ERR_SHAPE, 'nd_binary_into of the wrong shape: OTI_ERR_SHAPE')
    call check(index(nd_status_string(OTI_ERR_SHAPE), 'OTI_ERR_SHAPE') == 1, 'nd_status_string')
  end subroutine t_binary
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  subroutine t_unary()
    real(dp), allocatable :: r2(:,:)
    real(dp) :: p(n, m)

    p = big / (n * m)
    call nd_sqrt(big, r2)
    call check(all(close_to(r2, sqrt(big))), 'nd_sqrt')
    call nd_exp(p, r2)
    call check(all(close_to(r2, exp(p))), 'nd_exp')
    call nd_log(big, r2)
    call check(all(close_to(r2, log(big))), 'nd_log')
    call nd_log10(big, r2)
    call check(all(close_to(r2, log10(big))), 'nd_log10')
    call nd_sin(big, r2)
    call check(all(close_to(r2, sin(big))), 'nd_sin')
    call nd_cos(big, r2)
    call check(all(close_to(r2, cos(big))), 'nd_cos')
    call nd_tan(p, r2)
    call check(all(close_to(r2, tan(p))), 'nd_tan')
    call nd_asin(p, r2)
    call check(all(close_to(r2, asin(p))), 'nd_asin')
    call nd_atan(big, r2)
    call check(all(close_to(r2, atan(big))), 'nd_atan')
    call nd_tanh(p, r2)
    call check(all(close_to(r2, tanh(p))), 'nd_tanh')
    call nd_cosh(p, r2)
    call check(all(close_to(r2, cosh(p))), 'nd_cosh')
    call nd_neg(big, r2)
    call check(all(r2 == -big), 'nd_neg')
    call nd_abs(-big, r2)
    call check(all(r2 == big), 'nd_abs of an expression')
    call nd_floor(big / 4, r2)
    call check(all(r2 == real(floor(big / 4), dp)), 'nd_floor')
    call nd_square(big(2:, 3:5), r2)
    call check(all(r2 == big(2:, 3:5) ** 2), 'nd_square of an offset section')
    call nd_reciprocal(big(n:1:-1, :), r2)
    call check(all(r2 == 1 / big(n:1:-1, :)), 'nd_reciprocal of a reversed section')
    call nd_sign(big - 30, r2)
    call check(all(r2 == sign(1.0_dp, big - 30) .or. big == 30), 'nd_sign')
    call nd_unary(ND_FN_CBRT, big, r2)
    call check(all(close_to(r2 ** 3, big, 1.0e-12_dp)), 'nd_unary(ND_FN_CBRT)')
    work = 0
    call nd_unary_into(ND_FN_SQRT, big(1:n:2, :), work(2:n:2, :) , stat=i)
    call check(i == OTI_ERR_SHAPE, 'nd_unary_into of the wrong shape')
    call nd_unary_into(ND_FN_SQRT, big(1:n:2, :), work(1:n:2, :))
    call check(all(close_to(work(1:n:2, :), sqrt(big(1:n:2, :)))) .and. all(work(2:n:2, :) == 0), &
               'nd_unary_into a strided section')
  end subroutine t_unary
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  subroutine t_reduce()
    real(dp), allocatable :: r1(:), r2(:,:), r0
    real(dp) :: s, mean(m), var(m)
    integer :: st, j

    call nd_sum(big, r1, dim=1)
    call check(all(close_to(r1, sum(big, dim=1))) .and. size(r1) == m, 'nd_sum dim=1')
    call nd_sum(big, r1, dim=2)
    call check(all(close_to(r1, sum(big, dim=2))) .and. size(r1) == n, 'nd_sum dim=2')
    call nd_sum(big, r0)
    call check(close_to(r0, sum(big)), 'nd_sum of every dimension: rank 0')
    call nd_sum(big, r2, dim=2, keepdims=.true.)
    call check(all(shape(r2) == [n, 1]) .and. all(close_to(r2(:, 1), sum(big, dim=2))), &
               'nd_sum keepdims')
    call nd_sum(big, r2, keepdims=.true.)
    call check(all(shape(r2) == [1, 1]), 'nd_sum of every dimension with keepdims')
    call nd_sum(big(n:1:-2, m:1:-3), r1, dim=2)
    call check(all(close_to(r1, sum(big(n:1:-2, m:1:-3), dim=2))), 'nd_sum of a reversed section')
    call nd_sum(big, r2, dim=1, layout='reversed', keepdims=.true.)
    call check(all(shape(r2) == [m, 1]), "nd_sum keepdims, layout='reversed'")
    call nd_prod(big(1:2, 1:3) / 3, r1, dim=1)
    call check(all(close_to(r1, product(big(1:2, 1:3) / 3, dim=1))), 'nd_prod')
    call nd_min(big, r1, dim=2)
    call check(all(r1 == minval(big, dim=2)), 'nd_min')
    call nd_max(big, r1, dim=1)
    call check(all(r1 == maxval(big, dim=1)), 'nd_max')
    call nd_mean(big, r1, dim=1)
    mean = sum(big, dim=1) / n
    call check(all(close_to(r1, mean)), 'nd_mean')
    do j = 1, m
      var(j) = sum((big(:, j) - mean(j)) ** 2) / (n - 1)
    end do
    call nd_var(big, r1, dim=1, ddof=1)
    call check(all(close_to(r1, var)), 'nd_var ddof=1')
    call nd_std(big, r1, dim=1, ddof=1)
    call check(all(close_to(r1, sqrt(var))), 'nd_std ddof=1')
    call nd_reduce(ND_RED_MAX, big(2:4, :), r0)
    call check(r0 == maxval(big(2:4, :)), 'nd_reduce(ND_RED_MAX) to a scalar')

    call nd_reduce_into(ND_RED_SUM, big, s)
    call check(close_to(s, sum(big)), 'nd_reduce_into a scalar actual')
    work = -1
    call nd_reduce_into(ND_RED_MAX, big, work(2, :), dim=1)
    call check(all(work(2, :) == maxval(big, dim=1)) .and. all(work(1, :) == -1), &
               'nd_reduce_into a row section')

    call nd_sum(big, r1, dim=3, stat=st)
    call check(st == OTI_ERR_INDEX .and. .not. allocated(r1), 'dim > rank: OTI_ERR_INDEX')
    call nd_sum(big, r1, dim=0, stat=st)
    call check(st == OTI_ERR_INDEX, 'dim = 0: OTI_ERR_INDEX')
    call nd_max(big(3:2, :), r0, stat=st)
    call check(st == OTI_ERR_SHAPE .and. .not. allocated(r0), 'max of an empty array: OTI_ERR_SHAPE')
    call nd_sum(big(3:2, :), r0)
    call check(r0 == 0, 'sum of an empty array is 0')
  end subroutine t_reduce
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  subroutine t_creators()
    real(dp), allocatable :: r1(:), r2(:,:), r3(:,:,:)
    real(dp) :: eye3(3, 3)
    integer :: st

    call nd_zeros([3, 4], r2)
    call check(all(shape(r2) == [3, 4]) .and. all(r2 == 0), 'nd_zeros')
    call nd_ones([2, 0, 5], r3)
    call check(all(shape(r3) == [2, 0, 5]), 'nd_ones with a zero extent')
    call nd_full([2, 3], 7.5_dp, r2, layout='reversed')
    call check(all(shape(r2) == [3, 2]) .and. all(r2 == 7.5_dp), "nd_full, layout='reversed'")
    eye3 = 0
    eye3(1, 1) = 1
    eye3(2, 2) = 1
    eye3(3, 3) = 1
    call nd_eye(3, r2)
    call check(all(r2 == eye3), 'nd_eye(3)')
    call nd_eye(3, r2, m=4, k=1)
    call check(all(shape(r2) == [3, 4]) .and. r2(1, 2) == 1 .and. r2(3, 4) == 1 .and. sum(r2) == 3, &
               'nd_eye(3, m=4, k=1)')
    call nd_arange(0.0_dp, 5.0_dp, r1)
    call check(all(r1 == [0, 1, 2, 3, 4]), 'nd_arange(0, 5)')
    call nd_arange(1.0_dp, 2.0_dp, r1, step=0.25_dp)
    call check(all(r1 == [1.0_dp, 1.25_dp, 1.5_dp, 1.75_dp]), 'nd_arange step 0.25')
    call nd_linspace(0.0_dp, 1.0_dp, 5, r1)
    call check(all(r1 == [0.0_dp, 0.25_dp, 0.5_dp, 0.75_dp, 1.0_dp]), 'nd_linspace')
    call nd_linspace(0.0_dp, 1.0_dp, 4, r1, endpoint=.false.)
    call check(all(r1 == [0.0_dp, 0.25_dp, 0.5_dp, 0.75_dp]), 'nd_linspace endpoint=.false.')
    call nd_zeros([3, 4], r1, stat=st)
    call check(st == OTI_ERR_SHAPE .and. .not. allocated(r1), 'nd_zeros of the wrong rank')
    call nd_zeros([3, -1], r2, stat=st)
    call check(st == OTI_ERR_SHAPE, 'nd_zeros of a negative extent')
    call nd_arange(0.0_dp, 1.0_dp, r1, step=0.0_dp, stat=st)
    call check(st == OTI_ERR_ARGUMENT, 'nd_arange step 0: OTI_ERR_ARGUMENT')
  end subroutine t_creators
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  subroutine t_zero_extents()
    real(dp) :: z(3, 0)
    real(dp), allocatable :: r1(:), r2(:,:)

    call nd_add(z, z, r2)
    call check(allocated(r2), 'zero-size result allocated')
    if (allocated(r2)) call check(all(shape(r2) == [3, 0]), 'zero-size result shape (3, 0)')
    call nd_mul(big(3:2, :), 2.0_dp, r2)
    call check(all(shape(r2) == [0, m]), 'zero-size section input big(3:2,:)')
    call nd_sum(z, r1, dim=1)
    call check(size(r1) == 0, 'sum over dim 1 of (3, 0): shape (0)')
    call nd_sum(z, r1, dim=2)
    call check(size(r1) == 3 .and. all(r1 == 0), 'sum over dim 2 of (3, 0): zeros(3)')
    call nd_sub(z, 1.0_dp, r2, layout='reversed')
    call check(all(shape(r2) == [0, 3]), "zero-size result, layout='reversed'")
    call nd_unary_into(ND_FN_EXP, big(3:2, :), work(5:4, :))
    call check(all(work(1, :) == work(1, :)), 'nd_unary_into a zero-size section')
  end subroutine t_zero_extents
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  subroutine t_rank15()
    real(dp), allocatable, target :: a15(:,:,:,:,:,:,:,:,:,:,:,:,:,:,:)
    real(dp), allocatable :: r15(:,:,:,:,:,:,:,:,:,:,:,:,:,:,:), q15(:,:,:,:,:,:,:,:,:,:,:,:,:,:,:)
    real(dp), allocatable :: r0
    type(ndarr_t) :: nd
    integer :: k, ext(15), rev(15)

    allocate(a15(2, 1, 3, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2))
    a15 = reshape([(real(k, dp), k = 1, size(a15))], shape(a15))
    ext = shape(a15)
    rev = ext(15:1:-1)

    call nd_add(a15, a15, r15)
    call check(all(shape(r15) == ext) .and. all(r15 == 2 * a15), 'rank 15: nd_add')
    call nd_mul(a15, 3.0_dp, q15, layout='reversed')
    call check(all(shape(q15) == rev), "rank 15, layout='reversed': extents reversed")
    if (all(shape(q15) == rev)) then
      call check(all(q15 == reshape(3 * a15, rev, order=[(k, k = 15, 1, -1)])), &
                 "rank 15, layout='reversed': q(i15, ..., i1) = 3 a(i1, ..., i15)")
    end if
    call nd_sum(a15, r15, dim=15, keepdims=.true.)
    call check(all(r15 == reshape(sum(a15, dim=15), shape(r15))), 'rank 15: nd_sum dim=15 keepdims')
    call nd_sum(a15, r0)
    call check(r0 == sum(a15), 'rank 15: full reduction to rank 0')
    call nd_borrow(a15(2:1:-1, :, 3:1:-2, :, :, :, :, :, :, :, :, :, :, :, :), nd)
    call check(nd%ndim == 15 .and. nd%strides(1) == -1 .and. nd%strides(3) == -4 .and. &
               c_associated(nd%data, c_loc(a15(2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1))), &
               'rank 15: reversed strided section without a copy')
    call nd_neg(a15(2:1:-1, :, 3:1:-2, :, :, :, :, :, :, :, :, :, :, :, :), r15)
    call check(all(r15 == -a15(2:1:-1, :, 3:1:-2, :, :, :, :, :, :, :, :, :, :, :, :)), &
               'rank 15: nd_neg of the section')
  end subroutine t_rank15
  ! ------------------------------------------------------------------------------------------------------

end program test_nd_ops
