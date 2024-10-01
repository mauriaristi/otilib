PROGRAM ex2_sparse_n1

    USE real_utils
    USE sotin1

    IMPLICIT NONE

    TYPE(sotin1_t) :: x , y, z

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

END PROGRAM ex2_sparse_n1