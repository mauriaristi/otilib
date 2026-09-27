! ****************************************************************************************************
! OTIlib -> C-callable wrappers of the LAPACK / BLAS routines used by the C core.
!
! The C core never calls LAPACK symbols directly. Going through these BIND(C) wrappers lets the
! Fortran compiler handle what differs between platforms and LAPACK vendors:
!   - symbol names (dgetrf_, dgetrf, DGETRF),
!   - the hidden string-length arguments of CHARACTER dummies (dtrsm, dtrmm, dgetrs),
! and it keeps vendor headers (Accelerate, MKL, LAPACKE) out of the build.
!
! Integers are INTEGER(C_INT): the library links a 32-bit-integer (LP64) LAPACK
! (BLA_SIZEOF_INTEGER = 4 in CMake). Arrays are column-major, as in LAPACK.
!
! CHARACTER flags arrive as C chars (kind c_char, by value) and are copied into default-kind
! CHARACTER(LEN=1) locals before the LAPACK call, so the actual argument always has the kind and
! length the Fortran LAPACK interface expects, whatever c_char maps to.
!
! These are external subroutines (no module), so no .mod file is produced.
! ****************************************************************************************************


! ****************************************************************************************************
subroutine oti_dgetrf(m, n, a, lda, ipiv, info) bind(C, name="oti_dgetrf")
  ! LU factorization with partial pivoting: A = P L U (LAPACK dgetrf).
  use, intrinsic :: iso_c_binding, only: c_int, c_double
  implicit none
  integer(c_int), value         :: m, n, lda
  real(c_double), intent(inout) :: a(lda, *)
  integer(c_int), intent(out)   :: ipiv(*)
  integer(c_int), intent(out)   :: info
  external :: dgetrf

  call dgetrf(m, n, a, lda, ipiv, info)

end subroutine oti_dgetrf
! ----------------------------------------------------------------------------------------------------


! ****************************************************************************************************
subroutine oti_dgetrs(trans, n, nrhs, a, lda, ipiv, b, ldb, info) bind(C, name="oti_dgetrs")
  ! Solves A X = B or A^T X = B with the factors of oti_dgetrf (LAPACK dgetrs).
  use, intrinsic :: iso_c_binding, only: c_int, c_double, c_char
  implicit none
  character(kind=c_char), value :: trans
  integer(c_int), value         :: n, nrhs, lda, ldb
  real(c_double), intent(in)    :: a(lda, *)
  integer(c_int), intent(in)    :: ipiv(*)
  real(c_double), intent(inout) :: b(ldb, *)
  integer(c_int), intent(out)   :: info
  character(len=1)              :: f_trans
  external :: dgetrs

  f_trans = trans

  call dgetrs(f_trans, n, nrhs, a, lda, ipiv, b, ldb, info)

end subroutine oti_dgetrs
! ----------------------------------------------------------------------------------------------------


! ****************************************************************************************************
subroutine oti_dtrsm(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb) bind(C, name="oti_dtrsm")
  ! Triangular solve with multiple right-hand sides: B = alpha op(A)^-1 B or B = alpha B op(A)^-1.
  use, intrinsic :: iso_c_binding, only: c_int, c_double, c_char
  implicit none
  character(kind=c_char), value :: side, uplo, transa, diag
  integer(c_int), value         :: m, n, lda, ldb
  real(c_double), value         :: alpha
  real(c_double), intent(in)    :: a(lda, *)
  real(c_double), intent(inout) :: b(ldb, *)
  character(len=1)              :: f_side, f_uplo, f_transa, f_diag
  external :: dtrsm

  f_side   = side
  f_uplo   = uplo
  f_transa = transa
  f_diag   = diag

  call dtrsm(f_side, f_uplo, f_transa, f_diag, m, n, alpha, a, lda, b, ldb)

end subroutine oti_dtrsm
! ----------------------------------------------------------------------------------------------------


! ****************************************************************************************************
subroutine oti_dtrmm(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb) bind(C, name="oti_dtrmm")
  ! Triangular matrix product: B = alpha op(A) B or B = alpha B op(A).
  use, intrinsic :: iso_c_binding, only: c_int, c_double, c_char
  implicit none
  character(kind=c_char), value :: side, uplo, transa, diag
  integer(c_int), value         :: m, n, lda, ldb
  real(c_double), value         :: alpha
  real(c_double), intent(in)    :: a(lda, *)
  real(c_double), intent(inout) :: b(ldb, *)
  character(len=1)              :: f_side, f_uplo, f_transa, f_diag
  external :: dtrmm

  f_side   = side
  f_uplo   = uplo
  f_transa = transa
  f_diag   = diag

  call dtrmm(f_side, f_uplo, f_transa, f_diag, m, n, alpha, a, lda, b, ldb)

end subroutine oti_dtrmm
! ----------------------------------------------------------------------------------------------------
