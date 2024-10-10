PROGRAM ex2_sparse_n1

    USE real_utils
    USE sotin1

    IMPLICIT NONE

    TYPE(sotin1_t) :: x , y, z, f

    INTEGER i

    x =  eps(2) + (eps(1) + 3.5d0)*2.0d0

    y = 0.5d0

    DO i=1,20
        y = y + eps(i   )
        x = x + eps(i+30)
    END DO


    DO i = 1,10000000
        z = x*y
    END DO 

    print*, " >>> SPARSE OTI FORTRAN EXAMPLE USAGE <<< "


    CALL PPRINT(x,fmt='ES10.4')
    CALL PPRINT(y,fmt='ES10.4')
    CALL PPRINT(z,fmt='ES10.4')

    x = 0.75d0 + eps(1) + 2.0d0 * eps(10)
    f = FUNC1(x)


    WRITE(*,*)  " "
    WRITE(*,*)  " >> FUNCTION EVALUATION"
    
    CALL PPRINT(f,fmt='ES10.4')

    ! Expected value of the derivative, vs derivative from OTI.
    WRITE(*,*) dFUNC1_dx(x%r), f%im(1)

    
    WRITE(*,*)  " "
    WRITE(*,*)  " >> FUNCTION EVALUATION - SIN"
    
    f = sin(x)

    CALL PPRINT(f,fmt='ES10.4')

    WRITE(*,*) sin(x%r), cos(x%r), 2.0d0*cos(x%r)



CONTAINS

    FUNCTION FUNC1(x) RESULT (f)
        
        IMPLICIT NONE

        TYPE(sotin1_t) :: x
        TYPE(sotin1_t) :: f

        ! x**5 + 4*x**2
        f = x*x*x*x*x + 4.0d0 * x*x 

    END FUNCTION

    FUNCTION dFUNC1_dx(x) RESULT (df)
        
        IMPLICIT NONE

        REAL(dp) :: x
        REAL(dp) :: df

        ! 5*x**4 + 8*x
        df = 5.0d0 * x*x*x*x + 8.0d0 * x 

    END FUNCTION

END PROGRAM ex2_sparse_n1