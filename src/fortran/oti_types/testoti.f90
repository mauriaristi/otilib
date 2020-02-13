PROGRAM MAIN

    USE OTIM2N2
    IMPLICIT NONE
    ! INTEGER, PARAMETER :: sizex = 18
    TYPE(ONUM_M2N2)       :: X, Y, Z   !>OTI VARIABLE
    TYPE(ONUM_M2N2)       :: A(sizex,sizex), B(sizex,sizex), C(sizex,sizex)   !>OTI VARIABLE
    TYPE(OMAT_M2N2_18x18) :: A2, B2, C2   !>OTI VARIABLE
    INTEGER :: I
    REAL(KIND=8)::            &                !>Step
        time_start(3), time_finish(3)          !>Stores time
    ! ============================================================
    
    PRINT *, " "
    PRINT *, " THIS MODULE TESTS THE FORTRAN OTI IMPLEMENTATION."
    PRINT *, " "


    X     = 1.5D0
    X%E1  = 1.0D0


    Y     = 5.2D0
    Y%E2  = 1.0D0    

    CALL PPRINT(X)

    CALL PPRINT(Y)

    ! CALL PPRINT(X**5)

    ! CALL PPRINT(Y**5)

    ! CALL PPRINT((2.0d0*X+3.0d0*Y)**5)

    CALL PPRINT( (2.0d0*X+3.0d0*Y)**0.5d0 )

    ! CALL PPRINT(X)
    ! CALL PPRINT(Y)
    Z = X*Y
    CALL PPRINT( Z )
    CALL PPRINT( SIN(X*Y) )



    A = 32.0D0 
    B = 0.5D0

    CALL PPRINT(A+B)

    ! Measure time.
    CALL CPU_TIME(time_start(1))
    DO i=1,100000
        ! Multiplication with assignation
        C = MATMUL( A, B )
    END DO
    CALL CPU_TIME(time_finish(1))

    PRINT "(2(A,F20.3,8X))", '(CPU_TIME using array of ONUM_M2N2) [ms]:', &!
                            (time_finish(1)-time_start(1))*1000

    A2 = 32.0D0 
    B2 = 0.5D0

    ! Measure time.
    CALL CPU_TIME(time_start(2))
    DO i=1,100000
        ! Multiplication with assignation
        C2 = MATMUL( A2, B2 )
    END DO
    CALL CPU_TIME(time_finish(2))
    PRINT "(2(A,F20.3,8X))", '(CPU_TIME using OMAT_M2N2_18x18) [ms]:', &!
                            (time_finish(2)-time_start(2))*1000
    PRINT *, " "
    PRINT *, " PROGRAM ENDED SUCCESSFULLY."
    PRINT *, " "



END PROGRAM MAIN