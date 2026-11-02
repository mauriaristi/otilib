! ********************************************************************************************************
! Conformance of the Fortran ndarray module (Phase F2): matmul, solve, inv and det through the Phase 3
! BLAS / LAPACK dispatch, on whole arrays, sections, batches and both result layouts.
! ********************************************************************************************************
program test_nd_linalg

  use oti_real_ndarray
  use nd_test_util
  implicit none

  integer, parameter :: n = 4
  real(dp) :: a(n, n), b(n, 3), v(n), ident(n, n), big(9, 11)
  integer :: i, j

  ident = 0
  do i = 1, n
    ident(i, i) = 1
    do j = 1, n
      a(i, j) = 1.0_dp / (i + j - 1) + merge(4.0_dp, 0.0_dp, i == j)
    end do
  end do
  b = reshape([(real(mod(7 * i, 11), dp) - 5, i = 1, 3 * n)], [n, 3])
  v = [1.0_dp, -2.0_dp, 0.5_dp, 3.0_dp]
  big = reshape([(sin(real(i, dp)), i = 1, size(big))], shape(big))

  call t_matmul()
  call t_solve_inv()
  call t_det()
  call summary('test_nd_linalg')

contains

  ! ******************************************************************************************************
  subroutine t_matmul()
    real(dp), allocatable :: r2(:,:), r1(:), r0, r3(:,:,:)
    real(dp) :: a3(2, n, n), b3(2, n, 3), work(n, 8)
    integer :: st, ib

    call nd_matmul(a, b, r2)
    call check(all(shape(r2) == [n, 3]) .and. all_close(reshape(r2, [n * 3]), &
               reshape(matmul(a, b), [n * 3]), 1.0e-12_dp), 'nd_matmul(a, b) = matmul(a, b)')
    call nd_matmul(big(1:9:2, 2:11:3), big(9:6:-1, 11:1:-2), r2)
    call check(all(shape(r2) == [5, 6]) .and. all_close(reshape(r2, [30]), &
               reshape(matmul(big(1:9:2, 2:11:3), big(9:6:-1, 11:1:-2)), [30]), 1.0e-12_dp), &
               'nd_matmul of strided and reversed sections')
    call nd_matmul(transpose(a), a, r2)
    call check(all_close(reshape(r2, [n * n]), reshape(matmul(transpose(a), a), [n * n]), 1.0e-12_dp), &
               'nd_matmul(transpose(a), a)')
    call nd_matmul(a, v, r1)
    call check(all_close(r1, matmul(a, v), 1.0e-12_dp), 'matrix x vector')
    call nd_matmul(v, a, r1)
    call check(all_close(r1, matmul(v, a), 1.0e-12_dp), 'vector x matrix')
    call nd_matmul(v, v, r0)
    call check(close_to(r0, dot_product(v, v)), 'vector x vector: rank 0')
    call nd_matmul(a, b, r2, layout='reversed')
    call check(all(shape(r2) == [3, n]) .and. all_close(reshape(r2, [n * 3]), &
               reshape(transpose(matmul(a, b)), [n * 3]), 1.0e-12_dp), "nd_matmul, layout='reversed'")
    work = 0
    call nd_matmul_into(a, b, work(:, 8:3:-2))
    call check(all_close(reshape(work(:, 8:3:-2), [n * 3]), reshape(matmul(a, b), [n * 3]), &
               1.0e-12_dp) .and. all(work(:, 1:7:2) == 0), 'nd_matmul_into a reversed strided section')

    ! Batch: leading dimension = batch axis.
    do ib = 1, 2
      a3(ib, :, :) = a * ib
      b3(ib, :, :) = b - ib
    end do
    call nd_matmul(a3, b3, r3)
    call check(all(shape(r3) == [2, n, 3]), 'batched nd_matmul shape (2, n, 3)')
    do ib = 1, 2
      call check(all_close(reshape(r3(ib, :, :), [n * 3]), &
                 reshape(matmul(a3(ib, :, :), b3(ib, :, :)), [n * 3]), 1.0e-12_dp), &
                 'batched nd_matmul: one matrix of the batch')
    end do

    call nd_matmul(a, b(1:3, :), r2, stat=st)
    call check(st == OTI_ERR_SHAPE .and. .not. allocated(r2), 'nd_matmul inner mismatch: OTI_ERR_SHAPE')
    call nd_matmul(a, b, r1, stat=st)
    call check(st == OTI_ERR_SHAPE .and. .not. allocated(r1), 'nd_matmul into a result of the wrong rank')
    call nd_matmul(1.0_dp, a, r2, stat=st)
    call check(st == OTI_ERR_SHAPE, 'nd_matmul of a rank-0 operand: OTI_ERR_SHAPE')
  end subroutine t_matmul
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  subroutine t_solve_inv()
    real(dp), allocatable :: x1(:), x2(:,:), ai(:,:)
    real(dp) :: sing(3, 3), out(n, 3), ns(3, 3), work8(8), out3(3)
    integer :: st

    call nd_solve(a, v, x1)
    call check(all_close(matmul(a, x1), v, 1.0e-12_dp), 'nd_solve with a vector b')
    call nd_solve(a, b, x2)
    call check(all(shape(x2) == [n, 3]) .and. &
               all_close(reshape(matmul(a, x2), [n * 3]), reshape(b, [n * 3]), 1.0e-12_dp), &
               'nd_solve with a matrix b')
    call nd_solve(a(n:1:-1, :), b(:, 3:1:-1), x2)
    call check(all_close(reshape(matmul(a(n:1:-1, :), x2), [n * 3]), reshape(b(:, 3:1:-1), [n * 3]), &
               1.0e-12_dp), 'nd_solve on reversed sections')
    out = 0
    call nd_solve_into(a, b, out)
    call check(all_close(reshape(matmul(a, out), [n * 3]), reshape(b, [n * 3]), 1.0e-12_dp), &
               'nd_solve_into')

    work8 = 0
    call nd_solve_into(a, v, work8(8:2:-2))
    call check(all_close(matmul(a, work8(8:2:-2)), v, 1.0e-12_dp) .and. all(work8(1:7:2) == 0), &
               'nd_solve_into a reversed strided section (nd_solve_to, in place)')
    call nd_solve_into(a, b, out, nthreads=1)
    call check(all_close(reshape(matmul(a, out), [n * 3]), reshape(b, [n * 3]), 1.0e-12_dp), &
               'nd_solve_into with nthreads=1')

    call nd_inv(a, ai)
    call check(all_close(reshape(matmul(a, ai), [n * n]), reshape(ident, [n * n]), 1.0e-12_dp), &
               'nd_inv: a inv(a) = I')
    call nd_inv(a(1:n:2, 1:n:2), ai)
    call check(all(shape(ai) == [2, 2]) .and. all_close(reshape(matmul(a(1:n:2, 1:n:2), ai), [4]), &
               [1.0_dp, 0.0_dp, 0.0_dp, 1.0_dp], 1.0e-12_dp), 'nd_inv of a strided section')
    ns = a(1:3, 1:3) + 0.1_dp * b(1:3, :)
    call nd_inv(ns, ai, layout='reversed')
    call check(all_close(reshape(matmul(ns, transpose(ai)), [9]), reshape(ident(1:3, 1:3), [9]), &
               1.0e-12_dp), "nd_inv, layout='reversed': the transpose of the inverse")

    sing = reshape([1, 3, 5, 0, 0, 0, 2, 4, 6], [3, 3])   ! zero column: an exactly zero pivot
    call nd_inv(sing, ai, stat=st)
    call check(st > 0 .and. .not. allocated(ai), 'nd_inv of a singular matrix: stat > 0 (LAPACK info)')
    call nd_solve(sing, v(1:3), x1, stat=st)
    call check(st > 0 .and. .not. allocated(x1), 'nd_solve with a singular matrix: stat > 0')
    call nd_solve_into(sing, v(1:3), out3, stat=st)
    call check(st > 0, 'nd_solve_into with a singular matrix: stat > 0')
    call nd_solve_into(a, v, out3, stat=st)
    call check(st == OTI_ERR_SHAPE, 'nd_solve_into of the wrong shape: OTI_ERR_SHAPE')
    call nd_solve(a, v(1:3), x1, stat=st)
    call check(st == OTI_ERR_SHAPE, 'nd_solve size mismatch: OTI_ERR_SHAPE')
    call nd_inv(b, ai, stat=st)
    call check(st == OTI_ERR_SHAPE, 'nd_inv of a non-square matrix: OTI_ERR_SHAPE')
  end subroutine t_solve_inv
  ! ------------------------------------------------------------------------------------------------------


  ! ******************************************************************************************************
  subroutine t_det()
    real(dp), allocatable :: d0, d1(:)
    real(dp) :: t(n, n), c(3, 3), a3(2, 3, 3), d, expect
    integer :: i, st

    t = 0
    do i = 1, n
      t(i, i:) = real(i + 1, dp)
    end do
    call nd_det(t, d0)
    call check(close_to(d0, 120.0_dp), 'nd_det of a triangular matrix = 2*3*4*5')
    c = reshape([2.0_dp, -1.0_dp, 0.5_dp, 1.0_dp, 3.0_dp, -2.0_dp, 4.0_dp, 0.0_dp, 1.5_dp], [3, 3])
    expect = c(1, 1) * (c(2, 2) * c(3, 3) - c(2, 3) * c(3, 2)) &
           - c(1, 2) * (c(2, 1) * c(3, 3) - c(2, 3) * c(3, 1)) &
           + c(1, 3) * (c(2, 1) * c(3, 2) - c(2, 2) * c(3, 1))
    call nd_det(c, d0)
    call check(close_to(d0, expect), 'nd_det of a general 3x3 = cofactor expansion')
    call nd_det_into(c(3:1:-1, :), d)
    call check(close_to(d, -expect), 'nd_det_into a scalar, rows reversed: -det')
    call nd_det(reshape([1.0_dp, 2.0_dp, 2.0_dp, 4.0_dp], [2, 2]), d0)
    call check(d0 == 0, 'nd_det of an exactly singular matrix = 0 (status OK)')
    a3(1, :, :) = c
    a3(2, :, :) = 2 * c
    call nd_det(a3, d1)
    call check(size(d1) == 2 .and. all_close(d1, [expect, 8 * expect]), 'batched nd_det')
    call nd_det(b, d0, stat=st)
    call check(st == OTI_ERR_SHAPE .and. .not. allocated(d0), 'nd_det of a non-square matrix')
    call nd_det(c, d1, stat=st)
    call check(st == OTI_ERR_SHAPE, 'nd_det into a result of the wrong rank')
  end subroutine t_det
  ! ------------------------------------------------------------------------------------------------------

end program test_nd_linalg
