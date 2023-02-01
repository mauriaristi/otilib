PROGRAM main

    USE Octonions
    IMPLICIT NONE

    TYPE(octn)       :: Qx                           !>Quaternion variables
    TYPE(octn)       :: Qzero, Qone                  !>Quaternion variables
    TYPE(octn)       :: Qmat1(50,100), Qmat2(50,100) !>Quaternion matrices
    TYPE(octn)       :: Qma2T(100,50)             !>Quaternion matrices
    ! TYPE(octn)       :: Qmat1(200,300), Qmat2(200,300) !>Quaternion matrices
    ! TYPE(octn)       :: Qma2T(300,200)             !>Quaternion matrices
    TYPE(octn)       :: Qres2(50,50)             !>Quaternion matrices
    REAL(8)          :: Rmat(50,50)              !>Real matrix
    REAL(8)          :: Rmatw(2,3)             !>Real matrix
    REAL(8)          :: Rmatx(2,3)             !>Real matrix
    REAL(8)          :: Rmaty(2,3)             !>Real matrix
    REAL(8)          :: Rmatz(2,3)             !>Real matrix
    REAL(8)          :: Rmata(2,3)             !>Real matrix
    REAL(8)          :: Rmatb(2,3)             !>Real matrix
    REAL(8)          :: Rmatc(2,3)             !>Real matrix
    REAL(8)          :: Rmatd(2,3)             !>Real matrix
    INTEGER(kind=8)  :: i,j                    !>Counters
    REAL(KIND=8)::            &                !>Step
        time_start(3), time_finish(3)          !>Stores time
    ! ============================================================
    
    PRINT *, " "
    PRINT *, " Quaternion Based Automatic Differentiation in FORTRAN"
    PRINT *, " "

    PRINT *, " "
    PRINT *, " Nomenclature:"
    PRINT *, "  -> Q:    Quaternion number"
    PRINT *, "  -> Qmat: Matrix of quaternion elements"
    PRINT *, "  -> R:    Quaternion number"
    PRINT *, "  -> Rmat: Matrix of quaternion elements"    
    PRINT *, " "



    ! CALL INIT(0.0d0,Qzero)
    Qzero = 0.0d0
    Qone  = 1.0d0

    CALL PPRINT(Qzero)
    CALL PPRINT(Qone)
    

    Rmat(1,1) = 2.0_8
    Rmat(1,2) = 0.0_8
    Rmat(2,1) = 0.0_8
    Rmat(2,2) = 2.0_8

    ! Initialize matrices
    CALL INIT(1.0d0,Qmat2)
    CALL INIT(0.0d0,Qmat1)


    Qmat1(1,1)%w = 1.0d0 
    Qmat1(2,2)%w = 1.0d0 
    Qmat1(2,3)%w = 1.0d0 

    CALL PPRINT(Qmat1)
    print *, ' '
    CALL PPRINT(Qmat2)





    print *, ' '
    print *, 'Printing Reference values'
    print *, 'Quaternion Matrix (Qmat) 1: '
    print *, ' '
    CALL PPRINT(Qmat1) ! This is the call to beautifully print matrices.

    print *, ' '
    print *, 'Qmat 2: '
    print *, ' '
    CALL PPRINT(Qmat2)

    Qx = octn(1.0d0,2.0d0,3.0d0,4.0d0,5.0d0,6.0d0,7.0d0,8.0d0)
    CALL PPRINT(Qx)





    
    print *, ' '
    print *, 'Define all elements in specific directions to be x: '
    print *, ' '

    Qmat2%w = 0.0d0  ! This is analogous to do 
    Qmat2%x = 2.0d0  ! Qmat1(:,:)%... = REAL COEFFICIENT or even a real matrix.
    Qmat2%y = 50.5d0 !
    Qmat2%z = 20.0d0 ! Sets all coefficients of the matrix 
    Qmat2%a = -1.0d0 ! to the specified value
    Qmat2%b = -2.0d0
    Qmat2%c = -3.0d0
    Qmat2%d = -4.0d0
    CALL PPRINT(Qmat2)

    print *, ' '
    print *, 'Define all coefficients as particular values: '
    print *, ' '

    Qx%w = 0.5d0 ! 
    Qx%x = 3.0d0 !
    Qx%y = 1.0d0 !
    Qx%z = 2.5d0 !

    Qmat1 = Qx
    CALL PPRINT(Qmat1)  

    ! Qx%w = 1.0d0 ! 
    ! Qx%x = 2.0d0 !
    ! Qx%y = 3.0d0 !
    ! Qx%z = 4.0d0 !
    ! Qx%a = 5.0d0 ! 
    ! Qx%b = 6.0d0 !
    ! Qx%c = 7.0d0 !
    ! Qx%d = 8.0d0 !

    ! Qmat1 = Qx


    print *, ' '
    print *, 'Multiply Qmat x r: '
    print *, ' '
    CALL PPRINT(Qmat1*2.0d0) 
    print *, ' '
    print *, 'Multiply r x Qmat: '
    print *, ' '
    CALL PPRINT(2.0d0*Qmat1)  

    print *, ' '
    print *, 'Multiply Qmat x q: '
    print *, ' '
    CALL PPRINT(Qmat1*Qx) 
    print *, ' '
    print *, 'Multiply q x Qmat: '
    print *, ' '
    CALL PPRINT(Qx*Qmat1) 
    print *, ' '
    print *,' --> expected result:'
    print *, ' '
    CALL PPRINT(Qx*Qx)

    CALL PPRINT(Qx)



    print *, ' '
    print *, ' ======================= '
    print *, ' TEST IMPLICIT FUNCTIONS '
    print *, ' ======================= '
    print *, ' '

    print *, 'Matrix transpose: '
    print *, ' '

    ! Redefine the matrix Qmat2
    DO i=1,size(Qmat2,1)
        DO j=1,size(Qmat2,2)
            
            Qmat2(i,j)%w = j+(i-1)*(size(Qmat2,2))
            Qmat2(i,j)%x = Qmat2(i,j)%w + (size(Qmat2,1)*size(Qmat2,2))
            Qmat2(i,j)%y = Qmat2(i,j)%x + (size(Qmat2,1)*size(Qmat2,2))
            Qmat2(i,j)%z = Qmat2(i,j)%y + (size(Qmat2,1)*size(Qmat2,2))
            Qmat2(i,j)%a = Qmat2(i,j)%z + (size(Qmat2,1)*size(Qmat2,2))
            Qmat2(i,j)%b = Qmat2(i,j)%a + (size(Qmat2,1)*size(Qmat2,2))
            Qmat2(i,j)%c = Qmat2(i,j)%b + (size(Qmat2,1)*size(Qmat2,2))
            Qmat2(i,j)%d = Qmat2(i,j)%c + (size(Qmat2,1)*size(Qmat2,2))

        END DO
    END DO

    print *, 'Original:'
    CALL PPRINT(Qmat2)
    print *, 'Transposed:'
    CALL PPRINT(TRANSPOSE(Qmat2))


    print *, ' '
    print *, 'Matrix multiplication (Qmat x Qmat): '
    print *, ' '
    print *, 'Matrix 1, shape: ', SIZE(Qmat2,1),SIZE(Qmat2,2) 
    CALL PPRINT(Qmat2)
    print *, 'Matrix 2, shape: ', &
        SIZE(TRANSPOSE(Qmat1),1),SIZE(TRANSPOSE(Qmat1),2)
    CALL PPRINT( TRANSPOSE(Qmat1) )
    print *, 'Result:'
    CALL PPRINT( MATMUL(Qmat2, TRANSPOSE(Qmat1) ), fmt = 'F10.0' )

    Qres2 = MATMUL(Qmat2, TRANSPOSE(Qmat1) )

    print *, ' '
    print *, 'Matrix multiplication (Rmat x Qmat): '
    print *, ' '
    CALL PPRINT( MATMUL( Rmat, Qres2), fmt = 'F10.0'  )
    print *, 'Matrix multiplication (Qmat x Rmat ): '
    CALL PPRINT( MATMUL( Qres2, Rmat), fmt = 'F10.0'  )





    print *, ' '
    print *, ' ========================= '
    print *, ' TEST ARITHMATIC OPERATORS '
    print *, ' ========================= '
    print *, ' '

    print *, 'Element-wise addition: '
    print *, ' '
    print *, 'Original Qmat 1:'
    CALL PPRINT(Qmat1)
    print *, 'Original Qmat 2:'
    CALL PPRINT(Qmat2)
    print *, 'Sum result Qmat 1 + Qmat 2:'
    CALL PPRINT(Qmat1+Qmat2)


    print *, ' '
    print *, ' Addition Qmat + Rmat: '
    print *, ' '
    print *, 'Original Qmat 1:'
    CALL PPRINT(Qres2, fmt = 'F10.0' )
    print *, 'Original Rmat 2:'
    CALL PPRINT(Rmat)
    print *, 'Sum result Qmat + Rmat:'
    CALL PPRINT(Qres2+Rmat, fmt = 'F10.0' )
    print *, 'Sum result Rmat + Qmat:'
    CALL PPRINT(Rmat+Qres2, fmt = 'F10.0' )


    print *, ' '
    print *, ' Addition Qmat + R: '
    print *, ' '
    print *, 'Qmat 1:'
    CALL PPRINT(Qres2, fmt = 'F10.0' )
    print *, 'R:'
    CALL PPRINT(3.5d0)
    print *, 'Sum result Qmat + R:'
    CALL PPRINT(Qres2+3.5d0, fmt = 'F10.0' )
    print *, 'Sum result R + Qmat:'
    CALL PPRINT(3.5d0+Qres2, fmt = 'F10.0' )

    print *, ' '
    print *, ' Addition Qmat + R: '
    print *, ' '
    print *, 'Qmat 1:'
    CALL PPRINT(Qmat1)
    print *, 'Q:'
    CALL PPRINT(Qx)
    print *, 'Sum result Qmat + Q:'
    CALL PPRINT(Qmat1+Qx)
    print *, 'Sum result Q + Qmat:'
    CALL PPRINT(Qx+Qmat1)



    print *, ' '
    print *, 'Element-wise subtraction: '
    print *, ' '
    print *, 'Original Qmat 1:'
    CALL PPRINT(Qmat1)
    print *, 'Original Qmat 2:'
    CALL PPRINT(Qmat2)
    print *, 'Sum result Qmat 1 - Qmat 2:'
    CALL PPRINT(Qmat1-Qmat2)


    print *, ' '
    print *, ' Subtraction Qmat - Rmat: '
    print *, ' '
    print *, 'Original Qmat 1:'
    CALL PPRINT(Qres2, fmt = 'F10.0' )
    print *, 'Original Rmat 2:'
    CALL PPRINT(Rmat)
    print *, 'Sum result Qmat - Rmat:'
    CALL PPRINT(Qres2-Rmat, fmt = 'F10.0' )
    print *, 'Sum result Rmat - Qmat:'
    CALL PPRINT(Rmat-Qres2, fmt = 'F10.0' )


    print *, ' '
    print *, ' Addition Qmat - R: '
    print *, ' '
    print *, 'Qmat 1:'
    CALL PPRINT(Qres2, fmt = 'F10.0' )
    print *, 'R:'
    CALL RPrint(3.5d0)
    print *, 'Sum result Qmat - R:'
    CALL PPRINT(Qres2-3.5d0, fmt = 'F10.0' )
    print *, 'Sum result R - Qmat:'
    CALL PPRINT(3.5d0-Qres2, fmt = 'F10.0' )

    print *, ' '
    print *, ' Addition Qmat - R: '
    print *, ' '
    print *, 'Qmat 1:'
    CALL PPRINT(Qmat1)
    print *, 'Q:'
    CALL PPRINT(Qx)
    print *, 'Sum result Qmat - Q:'
    CALL PPRINT(Qmat1-Qx)
    print *, 'Sum result Q - Qmat:'
    CALL PPRINT(Qx-Qmat1)
    

    ! Disadvantages of this approach: 
    ! Slow because tons of memory copies, however very easy to implement.

    

    print *, ' '
    print *, ' Negate: '
    print *, ' '
    CALL PPRINT(-Qmat1)


    print *, ' '
    print *, ' ========================== '
    print *, ' TEST FOLD/UNFOLD OPERATORS '
    print *, ' ========================== '
    print *, ' '
    DO i=1,size(Rmatw,1)
        DO j=1,size(Rmatw,2)
            
            Rmatw(i,j) = j+(i-1)*(size(Rmatw,2))
            Rmatx(i,j) = Rmatw(i,j) + (size(Rmatw,1)*size(Rmatw,2))
            Rmaty(i,j) = Rmatx(i,j) + (size(Rmatw,1)*size(Rmatw,2))
            Rmatz(i,j) = Rmaty(i,j) + (size(Rmatw,1)*size(Rmatw,2))
            Rmata(i,j) = Rmatz(i,j) + (size(Rmatw,1)*size(Rmatw,2))
            Rmatb(i,j) = Rmata(i,j) + (size(Rmatw,1)*size(Rmatw,2))
            Rmatc(i,j) = Rmatb(i,j) + (size(Rmatw,1)*size(Rmatw,2))
            Rmatd(i,j) = Rmatc(i,j) + (size(Rmatw,1)*size(Rmatw,2))

        END DO
    END DO

    Qmat1 = MATFOLD(Rmatw,Rmatx,Rmaty,Rmatz,Rmata,Rmatb,Rmatc,Rmatd)
    CALL PPRINT(Qmat1)
    Qmat1 = Qzero
    print *, ' '
    print *, ' Using vector unfold function: '
    print *, ' '
    Qmat1(:,1) = MATFOLD(Rmatw(:,1),Rmatx(:,1),Rmaty(:,1),Rmatz(:,1),Rmata(:,1),Rmatb(:,1),Rmatc(:,1),Rmatd(:,1))
    CALL PPRINT(Qmat1)

    ! ! Unfold operator:

    
    print *, ' '
    print *, ' Change print format: '
    print *, ' '
    CALL PPRINT(Qmat1(:,1),fmt='E12.4')









    CALL INIT(1.0d0,Qmat1)
    CALL INIT(2.0d0,Qmat2)

    Qres2 = MATMUL( Qmat2, TRANSPOSE(Qmat1) )
    PRINT *, 'FUNCTION RESULT: '
    CALL PPRINT(Qres2,fmt='E10.1')  

    CALL INIT(0.0d0,Qres2)

    
    ! CALL MATMUL_SUB(Qmat2,Qmat1,'N','T', 1.0d0, 0.0d0, Qres2)
    ! print *, 'SUBROUTINE RESULT: '
    ! CALL PPRINT(Qres2,fmt='F10.1')











    ! ! Time comparison between the INTENT(INOUT) vs the 
    ! ! standard assignment calls.

    CALL CPU_TIME(time_start(1))
    DO i=1,100000
        ! Multiplication with assignation
        Qres2 = MATMUL( Qmat2, TRANSPOSE(Qmat1) )
        ! Qma2T = TRANSPOSE(Qmat2)
    END DO

    CALL CPU_TIME(time_finish(1))


    ! CALL CPU_TIME(time_start(2))
    ! DO i=1,100000
    !     ! Multiplication with assignation
    !     CALL MATMUL_SUB(Qmat2,Qmat1,'N','T', 1.0d0, 0.0d0, Qres2)
    !     !qmatXqmat_sub(r,q,tr,tq,alpha,beta,res)
    !     ! CALL TRANSPOSE_SUB(Qmat2, Qma2T)
    ! END DO

    ! CALL CPU_TIME(time_finish(2))

    PRINT "(2(A,F20.3,8X))", 'MATMUL OTI 8 var    time (CPU_TIME) [ms]:', &!
                            (time_finish(1)-time_start(1))*1000
    ! PRINT "(2(A,F9.3,8X))", 'SUBROUNTINE time (CPU_TIME) [ms]:', &!
    !                         (time_finish(2)-time_start(2))*1000





END PROGRAM MAIN