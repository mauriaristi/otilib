PROGRAM MAIN

    USE OTIM2N2
    IMPLICIT NONE

    TYPE(ONUM_M2N2)       :: X, Y, Z   !>OTI VARIABLE

    ! ============================================================
    
    PRINT *, " "
    PRINT *, " THIS MODULE TESTS THE FORTRAN OTI IMPLEMENTATION."
    PRINT *, " "


    X     = 1.5D0
    X%E1  = 1.0D0


    Y     = 5.2D0
    Y%E2  = 1.0D0    

    ! CALL PPRINT(X/3.5d0)

    ! CALL PPRINT(Y)

    ! CALL PPRINT(X**5)

    ! CALL PPRINT(Y**5)

    ! CALL PPRINT((2.0d0*X+3.0d0*Y)**5)

    CALL PPRINT((2.0d0*X+3.0d0*Y)**0.5d0)

    ! CALL PPRINT(X)
    ! CALL PPRINT(Y)
    Z = X*Y
    CALL PPRINT(Z)
    CALL PPRINT(SIN(X*Y))

    PRINT *, " "
    PRINT *, " PROGRAM ENDED SUCCESSFULLY."
    PRINT *, " "



END PROGRAM MAIN