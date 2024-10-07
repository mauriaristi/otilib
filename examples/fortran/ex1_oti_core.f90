PROGRAM ex1_oti_core

    USE oti_core
    
    IMPLICIT NONE

    INTEGER(imdir_t) :: m = 10
    INTEGER(ord_t)   :: n = 5


    PRINT*, "ndir_order", ndir_order(m,n)
    PRINT*, "ndir_total", ndir_total(m,n)

END PROGRAM ex1_oti_core