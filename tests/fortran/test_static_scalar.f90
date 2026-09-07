PROGRAM test_static_scalar

    USE otim1n3
    
    IMPLICIT NONE

    TYPE(onumm1n3) :: x, f
    REAL(dp) :: tol = 1.0d-8
    REAL(dp) :: expected_r, expected_d1

    x = 1.0d0 + E1
    f = exp(x)

    expected_r = exp(1.0d0)
    expected_d1 = exp(1.0d0)

    IF (abs(f%r - expected_r) > tol) THEN
        WRITE(*,*) "Static scalar test failed on real part"
        STOP 1
    END IF

    IF (abs(f%e1 - expected_d1) > tol) THEN
        WRITE(*,*) "Static scalar test failed on 1st derivative"
        STOP 1
    END IF

    WRITE(*,*) "Fortran static scalar test passed successfully."

END PROGRAM test_static_scalar
