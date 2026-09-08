PROGRAM test_sparse_scalar

    USE real_utils
    USE sotin1
    
    IMPLICIT NONE

    TYPE(sotin1_t) :: x, f
    REAL(dp) :: tol = 1.0d-8
    REAL(dp) :: expected_r, expected_df

    x = 2.0d0 + eps(1)
    ! f(x) = x^3 + 4*x
    f = x*x*x + 4.0d0 * x

    expected_r = 8.0d0 + 8.0d0   ! 16.0
    expected_df = 3.0d0 * (2.0d0**2) + 4.0d0 ! 16.0

    IF (abs(f%r - expected_r) > tol) THEN
        WRITE(*,*) "Sparse scalar test failed on real part"
        STOP 1
    END IF

    IF (abs(f%imCoeff(1) - expected_df) > tol) THEN
        WRITE(*,*) "Sparse scalar test failed on derivative"
        STOP 1
    END IF

    WRITE(*,*) "Fortran sparse scalar test passed successfully."
END PROGRAM test_sparse_scalar
