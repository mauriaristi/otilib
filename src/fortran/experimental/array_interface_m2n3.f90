MODULE array_interface_m2n3

    use iso_c_binding
    use otim2n3

    IMPLICIT NONE

    INTEGER(c_int64_t), PARAMETER :: op_load_var = 0
    INTEGER(c_int64_t), PARAMETER :: op_load_const = 1
    INTEGER(c_int64_t), PARAMETER :: op_add = 2 ! bi-variate
    INTEGER(c_int64_t), PARAMETER :: op_sub = 3 ! bi-variate
    INTEGER(c_int64_t), PARAMETER :: op_mul = 4 ! bi-variate
    INTEGER(c_int64_t), PARAMETER :: op_div = 5 ! bi-variate
    INTEGER(c_int64_t), PARAMETER :: op_sin = 6
    INTEGER(c_int64_t), PARAMETER :: op_cos = 7
    INTEGER(c_int64_t), PARAMETER :: op_exp = 8
    INTEGER(c_int64_t), PARAMETER :: op_log = 9
    INTEGER(c_int64_t), PARAMETER :: op_power = 10 ! bi-variate
    INTEGER(c_int64_t), PARAMETER :: op_abs = 11
    INTEGER(c_int64_t), PARAMETER :: op_sqrt = 12
    INTEGER(c_int64_t), PARAMETER :: op_abs_power = 13 ! bi-variate
    INTEGER(c_int64_t), PARAMETER :: op_sinh = 14
    INTEGER(c_int64_t), PARAMETER :: op_cosh = 15

    ! Create a type binding for OTI arrays
    TYPE, BIND(C) :: oarrm2n3_t
       TYPE(c_ptr)        :: p_data
       INTEGER(c_int64_t) :: nrows
       INTEGER(c_int64_t) :: ncols
       INTEGER(c_int64_t) :: size
    END TYPE

CONTAINS
    
    ! SUBROUTINE test1(a,b) BIND(C)
        
    !     IMPLICIT NONE

    !     INTEGER, INTENT(IN) :: a
    !     INTEGER, INTENT(INOUT) :: b
    
    !     PRINT*, 'From Fortran test1 subroutine'
    !     print*, '-> Received: a=',a
    !     print*, '-> Received: b=',b
    
    ! END SUBROUTINE test1

    ! SUBROUTINE test2(a_ptr, n_a) BIND(C)
    !     ! Test to pass an intrinsic rank-1 array from C.
    !     IMPLICIT NONE

    !     ! subroutine inputs.
    !     REAL(c_double), INTENT(IN) :: a_ptr(n_a) !< Array 
    !     INTEGER, INTENT(IN)     :: n_a   !< Array dimension.

    !     ! Local declarations
    !     INTEGER :: i
    !     ! REAL(c_double), POINTER ::  a_arr(:)

    !     ! CALL c_f_pointer( a_ptr, a_arr, [n_a])
    
    !     PRINT*, 'From Fortran test2 subroutine'
    !     print*, 'Received array of size', n_a
    !     CALL pprint(a_ptr)
    
    ! END SUBROUTINE test2

    ! SUBROUTINE test3(a_ptr, n_a, m_a) BIND(C)
    !     ! Test to pass an intrinsic rank-2 array from C.
    !     IMPLICIT NONE

    !     ! subroutine inputs.
    !     REAL(c_double), INTENT(IN) :: a_ptr(n_a,m_a) !< Array 
    !     INTEGER, INTENT(IN)     :: n_a , m_a  !< Array dimension.

    !     ! Local declarations
    !     INTEGER :: i,j
    !     ! REAL(c_double), POINTER ::  a_arr(:)

    !     ! CALL c_f_pointer( a_ptr, a_arr, [n_a])
    
    !     PRINT*, 'From Fortran test3 subroutine'
    !     print*, 'Received array of size', n_a, m_a
        
    !     CALL pprint(a_ptr)
    
    ! END SUBROUTINE test3



    ! SUBROUTINE graph_eval(graph, stack_size, columns) BIND(C)
    !     ! Test to pass a graph as a rank-2 int64 array from C.
    !     IMPLICIT NONE

    !     ! subroutine inputs.
    !     INTEGER, INTENT(IN) :: stack_size, columns   !< Array dimension.
    !     INTEGER(c_int64_t), INTENT(IN) :: graph(columns,stack_size) !< Array (transposed)

    !     ! Local declarations
    !     INTEGER :: i,j

    !     PRINT*, 'From Fortran graph_eval subroutine'
    !     PRINT*, 'Received graph with stack_size:', stack_size
        
    !     ! The graph array is transposed from the C-configuration.
    !     DO j=1,stack_size
    !         DO i=1,3
    !             WRITE(*,'(I16,A2)',ADVANCE='NO') graph(i,j),', '
    !         END DO
    !         WRITE(*,*) " "
    !     END DO

    !     ! We
    
    ! END SUBROUTINE graph_eval

    SUBROUTINE pytorch_graph_eval_m2n3(graph, stack_size, c_arr, c_size,x_matso,w_matso) BIND(C)
        ! Test to pass a graph as a rank-2 int64 array from C.
        IMPLICIT NONE

        ! subroutine inputs.
        INTEGER, INTENT(IN) :: stack_size, c_size  !< Array dimensions.
        TYPE(oarrm2n3_t), INTENT(IN) :: x_matso      !< input arrays. (Contains dimensions)
        TYPE(oarrm2n3_t), INTENT(INOUT) :: w_matso   !< output arrays. (Contains dimensions)
        REAL(c_double), INTENT(IN) :: c_arr(c_size)  !< constant arrays.
        INTEGER(c_int64_t), INTENT(IN) :: graph(3,stack_size) !< Array (transposed)

        ! Local declarations
        INTEGER :: i,j, p1, p2, k
        INTEGER(c_int64_t) :: node_oper

        TYPE(onumm2n3), POINTER :: x_arr(:,:)
        TYPE(onumm2n3), POINTER :: w_arr(:,:)

        ! type(onumm2n3) :: a_lhs, a_rhs


        TYPE(onumm2n3), POINTER :: p1_ptr(:) ! %%%%%% added new pointer variable.
        TYPE(onumm2n3), POINTER :: p2_ptr(:) ! %%%%%% added new pointer variable.

        ! type(onumm1n3) :: a_lhs, a_rhs


        CALL c_f_pointer( x_matso%p_data, x_arr, [x_matso%ncols,x_matso%nrows])
        CALL c_f_pointer( w_matso%p_data, w_arr, [w_matso%ncols,w_matso%nrows])

        !print*,"-> c_arr:"
        !CALL pprint(c_arr) 
        
        ! The graph array is transposed from the C-configuration.
        DO j=1,stack_size
            
            node_oper = graph(1,j)

            SELECT CASE(node_oper)
            
            CASE(op_load_var) ! %%%%%% Modified here. This is removed to avoid
                                ! %%%%%% unecessary memory copy.
                
            !     ! Get the id of the variable to load.
            !     p1 = graph(2,j)+1
                
            !     ! PRINT*, "Loading variable",p1

            !     w_arr(:,j) = x_arr(:,p1)


            CASE(op_load_const)

                ! Get the id of the constant to load.
                p1 = graph(2,j)+1
                
                !PRINT*, "Loading constant", p1
                !PRINT*, "Loading constant", c_arr(p1)
                w_arr(:,j) = c_arr(p1)
                !PRINT*, "Loading constant", w_arr(:,j)
            
            CASE(op_add) 

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
                p2 = graph(3,j)+1
                
                ! %%%%%% Modified the way variables are loaded. 
                IF (graph(1,p1) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p1 = graph(2,p1)+1                      ! %%%%%%
                    p1_ptr => x_arr(:,p1)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p1_ptr => w_arr(:,p1)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%

                IF (graph(1,p2) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p2 = graph(2,p2)+1                      ! %%%%%%
                    p2_ptr => x_arr(:,p2)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p2_ptr => w_arr(:,p2)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%
                    

                ! PRINT*, "performing xi+xj operation"
                ! w_arr(:,j) = w_arr(:,p1)+ w_arr(:,p2)
                
                ! DO k=1,w_matso%ncols
                !     w_arr(k,j)%r = w_arr(k,p1)%r+w_arr(k,p2)%r
                !     w_arr(k,j)%e1 = w_arr(k,p1)%e1+w_arr(k,p2)%e1
                ! END DO

                !                    lhs         rhs        res
                ! CALL add_oo_vv_to(w_arr(:,p1),w_arr(:,p2),w_arr(:,j))
                CALL add_oo_vv_to( p1_ptr, p2_ptr, w_arr(:,j) ) ! %%%%%% Modified the parameters that go into the subroutine call

                NULLIFY(p1_ptr,p2_ptr) ! %%%%% Deassociate pointers so we can use them later.
                

            CASE(op_sub)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
                p2 = graph(3,j)+1
                
                ! %%%%%% Modified the way variables are loaded. 
                IF (graph(1,p1) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p1 = graph(2,p1)+1                      ! %%%%%%
                    p1_ptr => x_arr(:,p1)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p1_ptr => w_arr(:,p1)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%

                IF (graph(1,p2) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p2 = graph(2,p2)+1                      ! %%%%%%
                    p2_ptr => x_arr(:,p2)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p2_ptr => w_arr(:,p2)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%
                    

                ! PRINT*, "performing xi+xj operation"
                ! w_arr(:,j) = w_arr(:,p1)+ w_arr(:,p2)
                
                ! DO k=1,w_matso%ncols
                !     w_arr(k,j)%r = w_arr(k,p1)%r+w_arr(k,p2)%r
                !     w_arr(k,j)%e1 = w_arr(k,p1)%e1+w_arr(k,p2)%e1
                ! END DO

                !                    lhs         rhs        res
                ! CALL add_oo_vv_to(w_arr(:,p1),w_arr(:,p2),w_arr(:,j))
                CALL sub_oo_vv_to( p1_ptr, p2_ptr, w_arr(:,j) ) ! %%%%%% Modified the parameters that go into the subroutine call

                NULLIFY(p1_ptr,p2_ptr) ! %%%%% Deassociate pointers so we can use them later.
                

            CASE(op_mul)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
                p2 = graph(3,j)+1
                
                ! %%%%%% Modified the way variables are loaded. 
                IF (graph(1,p1) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p1 = graph(2,p1)+1                      ! %%%%%%
                    p1_ptr => x_arr(:,p1)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p1_ptr => w_arr(:,p1)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%

                IF (graph(1,p2) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p2 = graph(2,p2)+1                      ! %%%%%%
                    p2_ptr => x_arr(:,p2)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p2_ptr => w_arr(:,p2)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%
                    

                ! PRINT*, "performing xi+xj operation"
                ! w_arr(:,j) = w_arr(:,p1)+ w_arr(:,p2)
                
                ! DO k=1,w_matso%ncols
                !     w_arr(k,j)%r = w_arr(k,p1)%r+w_arr(k,p2)%r
                !     w_arr(k,j)%e1 = w_arr(k,p1)%e1+w_arr(k,p2)%e1
                ! END DO

                !                    lhs         rhs        res
                ! CALL add_oo_vv_to(w_arr(:,p1),w_arr(:,p2),w_arr(:,j))
                CALL mul_oo_vv_to( p1_ptr, p2_ptr, w_arr(:,j) ) ! %%%%%% Modified the parameters that go into the subroutine call

                NULLIFY(p1_ptr,p2_ptr) ! %%%%% Deassociate pointers so we can use them later.
                
            CASE(op_div)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
                p2 = graph(3,j)+1
                
                ! %%%%%% Modified the way variables are loaded. 
                IF (graph(1,p1) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p1 = graph(2,p1)+1                      ! %%%%%%
                    p1_ptr => x_arr(:,p1)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p1_ptr => w_arr(:,p1)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%

                IF (graph(1,p2) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p2 = graph(2,p2)+1                      ! %%%%%%
                    p2_ptr => x_arr(:,p2)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p2_ptr => w_arr(:,p2)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%
                    

                ! PRINT*, "performing xi+xj operation"
                ! w_arr(:,j) = w_arr(:,p1)+ w_arr(:,p2)
                
                ! DO k=1,w_matso%ncols
                !     w_arr(k,j)%r = w_arr(k,p1)%r+w_arr(k,p2)%r
                !     w_arr(k,j)%e1 = w_arr(k,p1)%e1+w_arr(k,p2)%e1
                ! END DO

                !                    lhs         rhs        res
                ! CALL add_oo_vv_to(w_arr(:,p1),w_arr(:,p2),w_arr(:,j))
                CALL div_oo_vv_to( p1_ptr, p2_ptr, w_arr(:,j) ) ! %%%%%% Modified the parameters that go into the subroutine call

                NULLIFY(p1_ptr,p2_ptr) ! %%%%% Deassociate pointers so we can use them later.
            CASE(op_sin)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
              
                
                ! %%%%%% Modified the way variables are loaded. 
                IF (graph(1,p1) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p1 = graph(2,p1)+1                      ! %%%%%%
                    p1_ptr => x_arr(:,p1)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p1_ptr => w_arr(:,p1)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%
        


                CALL sin_v_to( p1_ptr, w_arr(:,j) ) ! %%%%%% Modified the parameters that go into the subroutine call

                NULLIFY(p1_ptr) ! %%%%% Deassociate pointers so we can use them later.

            CASE(op_cos)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
              
                
                ! %%%%%% Modified the way variables are loaded. 
                IF (graph(1,p1) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p1 = graph(2,p1)+1                      ! %%%%%%
                    p1_ptr => x_arr(:,p1)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p1_ptr => w_arr(:,p1)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%
        


                CALL cos_v_to( p1_ptr, w_arr(:,j) ) ! %%%%%% Modified the parameters that go into the subroutine call

                NULLIFY(p1_ptr) ! %%%%% Deassociate pointers so we can use them later.

            CASE(op_exp)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
              
                
                ! %%%%%% Modified the way variables are loaded. 
                IF (graph(1,p1) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p1 = graph(2,p1)+1                      ! %%%%%%
                    p1_ptr => x_arr(:,p1)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p1_ptr => w_arr(:,p1)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%
        


                CALL exp_v_to( p1_ptr, w_arr(:,j) ) ! %%%%%% Modified the parameters that go into the subroutine call

                NULLIFY(p1_ptr) ! %%%%% Deassociate pointers so we can use them later.
            CASE(op_log)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
              
                
                ! %%%%%% Modified the way variables are loaded. 
                IF (graph(1,p1) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p1 = graph(2,p1)+1                      ! %%%%%%
                    p1_ptr => x_arr(:,p1)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p1_ptr => w_arr(:,p1)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%
        


                CALL log_v_to( p1_ptr, w_arr(:,j) ) ! %%%%%% Modified the parameters that go into the subroutine call

                NULLIFY(p1_ptr) ! %%%%% Deassociate pointers so we can use them later.
            CASE(op_power)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
                p2 = graph(3,j)+1
                
                ! %%%%%% Modified the way variables are loaded. 
                IF (graph(1,p1) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p1 = graph(2,p1)+1                      ! %%%%%%
                    p1_ptr => x_arr(:,p1)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p1_ptr => w_arr(:,p1)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%

                IF (graph(1,p2) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p2 = graph(2,p2)+1                      ! %%%%%%
                    p2_ptr => x_arr(:,p2)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p2_ptr => w_arr(:,p2)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%
                    

                ! PRINT*, "performing xi+xj operation"
                ! w_arr(:,j) = w_arr(:,p1)+ w_arr(:,p2)
                
                ! DO k=1,w_matso%ncols
                !     w_arr(k,j)%r = w_arr(k,p1)%r+w_arr(k,p2)%r
                !     w_arr(k,j)%e1 = w_arr(k,p1)%e1+w_arr(k,p2)%e1
                ! END DO

                !                    lhs         rhs        res
                ! CALL add_oo_vv_to(w_arr(:,p1),w_arr(:,p2),w_arr(:,j))
                CALL pow_oo_vv_to( p1_ptr, p2_ptr, w_arr(:,j) ) ! %%%%%% Modified the parameters that go into the subroutine call

                NULLIFY(p1_ptr,p2_ptr) ! %%%%% Deassociate pointers so we can use them later.
            CASE(op_abs)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1

                ! PRINT*, "performing abs(xi) evaluation"

            CASE(op_sqrt)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
              
                
                ! %%%%%% Modified the way variables are loaded. 
                IF (graph(1,p1) == op_load_var) THEN        ! %%%%%%
                    ! Associate pointer to portion of x_arr ! %%%%%%
                    p1 = graph(2,p1)+1                      ! %%%%%%
                    p1_ptr => x_arr(:,p1)                   ! %%%%%% Associate pointer.
                ELSE                                        ! %%%%%%
                    p1_ptr => w_arr(:,p1)                   ! %%%%%% Associate pointer.
                END IF                                      ! %%%%%%
        


                CALL sqrt_v_to( p1_ptr, w_arr(:,j) ) ! %%%%%% Modified the parameters that go into the subroutine call

                NULLIFY(p1_ptr) ! %%%%% Deassociate pointers so we can use them later.
            CASE(op_abs_power)
                ! Get the id of the variable to load.
                p1 = graph(2,j)+1
                p2 = graph(3,j)+1

                ! PRINT*, "performing (abs(xi))**xj evaluation"

            CASE(op_sinh)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1

                ! PRINT*, "performing sinh(xi) evaluation"
                w_arr(:,j) = sinh(w_arr(:,p1))

            CASE(op_cosh)

                ! Get the id of the variable to load.
                p1 = graph(2,j)+1

                ! PRINT*, "performing cosh(xi) evaluation"
                w_arr(:,j) = cosh(w_arr(:,p1))

            CASE DEFAULT
                PRINT*, "ERROR: Undefined node operation in the graph structure."
                PRINT*, ' EXITING - .'
                EXIT
        END SELECT

        END DO

        ! print*," "
        ! print*,"-> w_arr (after evaluation):"
        ! CALL pprint(w_arr)
    
    END SUBROUTINE pytorch_graph_eval_m2n3

    SUBROUTINE sub_oo_vv_to(lhs,rhs,res)
      IMPLICIT NONE
      TYPE(onumm2n3), INTENT(IN) :: lhs(:)
      TYPE(onumm2n3), INTENT(IN) :: rhs(SIZE(lhs,1))
      TYPE(onumm2n3), INTENT(INOUT) :: res(SIZE(lhs,1))

      INTEGER :: i

      ! Subtraction like function 'LHS - RHS'

      DO i=1,SIZE(lhs,1)

          ! Order 3
          RES(i)%E111 = LHS(i)%e111 - RHS(i)%e111
          RES(i)%E112 = LHS(i)%e112 - RHS(i)%e112
          RES(i)%E122 = LHS(i)%e122 - RHS(i)%e122
          RES(i)%E222 = LHS(i)%e222 - RHS(i)%e222
          ! Order 2
          RES(i)%E11 = LHS(i)%e11 - RHS(i)%e11
          RES(i)%E12 = LHS(i)%e12 - RHS(i)%e12
          RES(i)%E22 = LHS(i)%e22 - RHS(i)%e22
          ! Order 1
          RES(i)%E1 = LHS(i)%e1 - RHS(i)%e1
          RES(i)%E2 = LHS(i)%e2 - RHS(i)%e2
          ! Order 0
          RES(i)%R = LHS(i)%R-RHS(i)%R
      END DO

   END SUBROUTINE sub_oo_vv_to



   SUBROUTINE add_oo_vv_to(lhs,rhs,res)
      IMPLICIT NONE
      TYPE(onumm2n3), INTENT(IN) :: lhs(:)
      TYPE(onumm2n3), INTENT(IN) :: rhs(SIZE(lhs,1))
      TYPE(onumm2n3), INTENT(INOUT) :: res(SIZE(lhs,1))

      INTEGER :: i

      ! Addition like function 'LHS + RHS'
      DO i=1,SIZE(lhs,1)

          ! Order 3
          RES(i)%E111 = LHS(i)%e111 + RHS(i)%e111
          RES(i)%E112 = LHS(i)%e112 + RHS(i)%e112
          RES(i)%E122 = LHS(i)%e122 + RHS(i)%e122
          RES(i)%E222 = LHS(i)%e222 + RHS(i)%e222
          ! Order 2
          RES(i)%E11 = LHS(i)%e11 + RHS(i)%e11
          RES(i)%E12 = LHS(i)%e12 + RHS(i)%e12
          RES(i)%E22 = LHS(i)%e22 + RHS(i)%e22
          ! Order 1
          RES(i)%E1 = LHS(i)%e1 + RHS(i)%e1
          RES(i)%E2 = LHS(i)%e2 + RHS(i)%e2
          ! Order 0
          RES(i)%R = LHS(i)%R+RHS(i)%R

      END DO

   END SUBROUTINE add_oo_vv_to

   SUBROUTINE mul_oo_vv_to(lhs,rhs,res)
      IMPLICIT NONE
      TYPE(onumm2n3), INTENT(IN) :: lhs(:)
      TYPE(onumm2n3), INTENT(IN) :: rhs(SIZE(lhs,1))
      TYPE(onumm2n3), INTENT(INOUT) :: res(SIZE(lhs,1))

      INTEGER :: i

      !  Multiplication like function 'LHS*RHS'
      DO i=1,SIZE(lhs,1)

          ! Order 3
          RES(i)%E111 = LHS(i)%R*RHS(i)%e111 + LHS(i)%e1*RHS(i)%e11 + LHS(i)%e11*RHS(i)%e1 + LHS(i)%e111*RHS(i)%R
          RES(i)%E112 = LHS(i)%R*RHS(i)%e112 + LHS(i)%e1*RHS(i)%e12 + LHS(i)%e11*RHS(i)%e2 + LHS(i)%e112*RHS(i)%R + LHS(i)%e12*RHS(i)%e1 + LHS(i)%e2*RHS(i)%e11
          RES(i)%E122 = LHS(i)%R*RHS(i)%e122 + LHS(i)%e1*RHS(i)%e22 + LHS(i)%e12*RHS(i)%e2 + LHS(i)%e122*RHS(i)%R + LHS(i)%e2*RHS(i)%e12 + LHS(i)%e22*RHS(i)%e1
          RES(i)%E222 = LHS(i)%R*RHS(i)%e222 + LHS(i)%e2*RHS(i)%e22 + LHS(i)%e22*RHS(i)%e2 + LHS(i)%e222*RHS(i)%R
          ! Order 2
          RES(i)%E11 = LHS(i)%R*RHS(i)%e11 + LHS(i)%e1*RHS(i)%e1 + LHS(i)%e11*RHS(i)%R
          RES(i)%E12 = LHS(i)%R*RHS(i)%e12 + LHS(i)%e1*RHS(i)%e2 + LHS(i)%e12*RHS(i)%R + LHS(i)%e2*RHS(i)%e1
          RES(i)%E22 = LHS(i)%R*RHS(i)%e22 + LHS(i)%e2*RHS(i)%e2 + LHS(i)%e22*RHS(i)%R
          ! Order 1
          RES(i)%E1 = LHS(i)%R*RHS(i)%e1 + LHS(i)%e1*RHS(i)%R
          RES(i)%E2 = LHS(i)%R*RHS(i)%e2 + LHS(i)%e2*RHS(i)%R
          ! Order 0
          RES(i)%R = LHS(i)%R*RHS(i)%R


       END DO

   END SUBROUTINE mul_oo_vv_to

   SUBROUTINE div_oo_vv_to(lhs,rhs,res)
      IMPLICIT NONE
      TYPE(onumm2n3), INTENT(IN) :: lhs(:)
      TYPE(onumm2n3), INTENT(IN) :: rhs(SIZE(lhs,1))
      TYPE(onumm2n3), INTENT(INOUT) :: res(SIZE(lhs,1))

      INTEGER :: i

      ! Addition like function 'LHS + RHS'
      DO i=1,SIZE(lhs,1)
          !Order 3
          RES(i)%E111 = -LHS(i)%R*RHS(i)%e111/RHS(i)%R**2 + 2*LHS(i)%R*RHS(i)%e1*RHS(i)%e11/RHS(i)%R**3 - LHS(i)%R*RHS(i)%e1**3/RHS(i)%R**4 - LHS(i)%e1*RHS(i)%e11/RHS(i)%R**2 + LHS(i)%e1*RHS(i)%e1**2/RHS(i)%R**3 - LHS(i)%e11*RHS(i)%e1/RHS(i)%R**2 + LHS(i)%e111/RHS(i)%R
          RES(i)%E112 = -LHS(i)%R*RHS(i)%e112/RHS(i)%R**2 + 2*LHS(i)%R*RHS(i)%e1*RHS(i)%e12/RHS(i)%R**3 + 2*LHS(i)%R*RHS(i)%e11*RHS(i)%e2/RHS(i)%R**3 - 3*LHS(i)%R*RHS(i)%e1**2*RHS(i)%e2/RHS(i)%R**4 - LHS(i)%e1*RHS(i)%e12/RHS(i)%R**2 + 2*LHS(i)%e1*RHS(i)%e1*RHS(i)%e2/RHS(i)%R**3 - LHS(i)%e11*RHS(i)%e2/RHS(i)%R**2 + LHS(i)%e112/RHS(i)%R - LHS(i)%e12*RHS(i)%e1/RHS(i)%R**2 - LHS(i)%e2*RHS(i)%e11/RHS(i)%R**2 + LHS(i)%e2*RHS(i)%e1**2/RHS(i)%R**3
          RES(i)%E122 = -LHS(i)%R*RHS(i)%e122/RHS(i)%R**2 + 2*LHS(i)%R*RHS(i)%e1*RHS(i)%e22/RHS(i)%R**3 + 2*LHS(i)%R*RHS(i)%e12*RHS(i)%e2/RHS(i)%R**3 - 3*LHS(i)%R*RHS(i)%e1*RHS(i)%e2**2/RHS(i)%R**4 - LHS(i)%e1*RHS(i)%e22/RHS(i)%R**2 + LHS(i)%e1*RHS(i)%e2**2/RHS(i)%R**3 - LHS(i)%e12*RHS(i)%e2/RHS(i)%R**2 + LHS(i)%e122/RHS(i)%R - LHS(i)%e2*RHS(i)%e12/RHS(i)%R**2 + 2*LHS(i)%e2*RHS(i)%e1*RHS(i)%e2/RHS(i)%R**3 - LHS(i)%e22*RHS(i)%e1/RHS(i)%R**2
          RES(i)%E222 = -LHS(i)%R*RHS(i)%e222/RHS(i)%R**2 + 2*LHS(i)%R*RHS(i)%e2*RHS(i)%e22/RHS(i)%R**3 - LHS(i)%R*RHS(i)%e2**3/RHS(i)%R**4 - LHS(i)%e2*RHS(i)%e22/RHS(i)%R**2 + LHS(i)%e2*RHS(i)%e2**2/RHS(i)%R**3 - LHS(i)%e22*RHS(i)%e2/RHS(i)%R**2 + LHS(i)%e222/RHS(i)%R
          ! Order 2
          RES(i)%E11 = -LHS(i)%R*RHS(i)%e11/RHS(i)%R**2 + LHS(i)%R*RHS(i)%e1**2/RHS(i)%R**3 - LHS(i)%e1*RHS(i)%e1/RHS(i)%R**2 + LHS(i)%e11/RHS(i)%R
          RES(i)%E12 = -LHS(i)%R*RHS(i)%e12/RHS(i)%R**2 + 2*LHS(i)%R*RHS(i)%e1*RHS(i)%e2/RHS(i)%R**3 - LHS(i)%e1*RHS(i)%e2/RHS(i)%R**2 + LHS(i)%e12/RHS(i)%R - LHS(i)%e2*RHS(i)%e1/RHS(i)%R**2
          RES(i)%E22 = -LHS(i)%R*RHS(i)%e22/RHS(i)%R**2 + LHS(i)%R*RHS(i)%e2**2/RHS(i)%R**3 - LHS(i)%e2*RHS(i)%e2/RHS(i)%R**2 + LHS(i)%e22/RHS(i)%R
          ! Order 1
          RES(i)%E1 = -LHS(i)%R*RHS(i)%e1/RHS(i)%R**2 + LHS(i)%e1/RHS(i)%R
          RES(i)%E2 = -LHS(i)%R*RHS(i)%e2/RHS(i)%R**2 + LHS(i)%e2/RHS(i)%R
          ! Order 0
          RES(i)%R = LHS(i)%R/RHS(i)%R


      END DO

   END SUBROUTINE div_oo_vv_to
   SUBROUTINE sin_v_to(X,RES)

      TYPE(onumm2n3), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1)),DER2(SIZE(x,1)),DER3(SIZE(x,1))
      TYPE(onumm2n3), INTENT(INOUT) :: RES(SIZE(x,1))

      
         DER0 = SIN(X%R)
         DER1 = COS(X%R)
         DER2 = -SIN(X%R)
         DER3 = -COS(X%R)

      
          

         CALL feval_v_to(X,DER0,DER1,DER2,DER3,RES)

   END SUBROUTINE sin_v_to

   SUBROUTINE cos_v_to(X,RES)

      TYPE(onumm2n3), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1)),DER2(SIZE(x,1)),DER3(SIZE(x,1))
      TYPE(onumm2n3), INTENT(INOUT) :: RES(SIZE(x,1))

      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)
      DER2 = -COS(X%R)
      DER3 = SIN(X%R)

      
          

         CALL feval_v_to(X,DER0,DER1,DER2,DER3,RES)

   END SUBROUTINE cos_v_to

   SUBROUTINE exp_v_to(X,RES)

      TYPE(onumm2n3), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1)),DER2(SIZE(x,1)),DER3(SIZE(x,1))
      TYPE(onumm2n3), INTENT(INOUT) :: RES(SIZE(x,1))

      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)
      DER2 = EXP(X%R)
      DER3 = EXP(X%R)
    
          

         CALL feval_v_to(X,DER0,DER1,DER2,DER3,RES)

   END SUBROUTINE exp_v_to

   SUBROUTINE log_v_to(X,RES)

      TYPE(onumm2n3), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1)),DER2(SIZE(x,1)),DER3(SIZE(x,1))
      TYPE(onumm2n3), INTENT(INOUT) :: RES(SIZE(x,1))

      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R
      DER2 = -1/X%R**2
      DER3 = 2/X%R**3
      
          

         CALL feval_v_to(X,DER0,DER1,DER2,DER3,RES)

   END SUBROUTINE log_v_to


   SUBROUTINE pow_oo_vv_to(lhs,rhs,res)
      IMPLICIT NONE
      TYPE(onumm2n3), INTENT(IN) :: lhs(:)
      TYPE(onumm2n3), INTENT(IN) :: rhs(SIZE(lhs,1))
      TYPE(onumm2n3), INTENT(INOUT) :: res(SIZE(lhs,1))

      INTEGER :: i

      ! Addition like function 'LHS + RHS'
      DO i=1,SIZE(lhs,1)

          ! Order 3
          RES(i)%E111 =  exp(RHS(i)%R*log(LHS(i)%R))*((1/2)*(LHS(i)%e1*RHS(i)%R + RHS(i)%e1*LHS(i)%R*log(LHS(i)%R))*((2*LHS(i)%E11*LHS(i)%R - LHS(i)%e1**2)*RHS(i)%R + 2*LHS(i)%e1*RHS(i)%e1*LHS(i)%R + 2*RHS(i)%E11*LHS(i)%R**2*log(LHS(i)%R) + (LHS(i)%e1*RHS(i)%R + RHS(i)%e1*LHS(i)%R*log(LHS(i)%R))**2) + (-1/3)*(-3*LHS(i)%E111*LHS(i)%R**2 + (LHS(i)%E11*LHS(i)%R - LHS(i)%e1**2)*LHS(i)%e1 + 2*LHS(i)%e1*LHS(i)%E11*LHS(i)%R)*RHS(i)%R + LHS(i)%e1*RHS(i)%E11*LHS(i)%R**2 + RHS(i)%E111*LHS(i)%R**3*log(LHS(i)%R) + (1/2)*(2*LHS(i)%E11*LHS(i)%R - LHS(i)%e1**2)*RHS(i)%e1*LHS(i)%R + (-1/3)*(LHS(i)%e1*RHS(i)%R + RHS(i)%e1*LHS(i)%R*log(LHS(i)%R))**3)/LHS(i)%R**3
          RES(i)%E112 = (1/2)*exp(RHS(i)%R*log(LHS(i)%R))*(LHS(i)%R*(-LHS(i)%e1**2*RHS(i)%e2 - 2*LHS(i)%e1*LHS(i)%E12*RHS(i)%R + 2*LHS(i)%e1*LHS(i)%E12*RHS(i)%R**2 + 2*LHS(i)%e1**2*RHS(i)%e2*RHS(i)%R - 2*LHS(i)%e2*LHS(i)%E11*RHS(i)%R + 2*LHS(i)%e2*LHS(i)%E11*RHS(i)%R**2 - 2*LHS(i)%e2*LHS(i)%e1*RHS(i)%e1 - LHS(i)%e1**2*RHS(i)%e2*RHS(i)%R*log(LHS(i)%R) + LHS(i)%e1**2*RHS(i)%e2*RHS(i)%R**2*log(LHS(i)%R) + 4*LHS(i)%e2*LHS(i)%e1*RHS(i)%e1*RHS(i)%R - 2*LHS(i)%e2*LHS(i)%e1*RHS(i)%e1*RHS(i)%R*log(LHS(i)%R) + 2*LHS(i)%e2*LHS(i)%e1*RHS(i)%e1*RHS(i)%R**2*log(LHS(i)%R)) + (2*LHS(i)%E112*RHS(i)%R + 2*LHS(i)%e1*RHS(i)%E12 + 2*LHS(i)%e2*RHS(i)%E11 + 2*RHS(i)%e1*LHS(i)%E12 + 2*RHS(i)%e2*LHS(i)%E11 + 2*LHS(i)%e2*RHS(i)%e1**2*log(LHS(i)%R) + 2*LHS(i)%e1*RHS(i)%E12*RHS(i)%R*log(LHS(i)%R) + 4*LHS(i)%e1*RHS(i)%e2*RHS(i)%e1*log(LHS(i)%R) + 2*LHS(i)%e2*RHS(i)%E11*RHS(i)%R*log(LHS(i)%R) + LHS(i)%e2*RHS(i)%e1**2*RHS(i)%R*log(LHS(i)%R)**2 + 2*RHS(i)%e1*LHS(i)%E12*RHS(i)%R*log(LHS(i)%R) + 2*RHS(i)%e2*LHS(i)%E11*RHS(i)%R*log(LHS(i)%R) + 2*LHS(i)%e1*RHS(i)%e2*RHS(i)%e1*RHS(i)%R*log(LHS(i)%R)**2)*LHS(i)%R**2 + (2*RHS(i)%E112 + 2*RHS(i)%e1*RHS(i)%E12*log(LHS(i)%R) + 2*RHS(i)%e2*RHS(i)%E11*log(LHS(i)%R) + RHS(i)%e2*RHS(i)%e1**2*log(LHS(i)%R)**2)*LHS(i)%R**3*log(LHS(i)%R) + LHS(i)%e2*LHS(i)%e1**2*RHS(i)%R*(2 - 3*RHS(i)%R + RHS(i)%R**2))/LHS(i)%R**3
          RES(i)%E122 = (1/2)*exp(RHS(i)%R*log(LHS(i)%R))*(LHS(i)%R*(-LHS(i)%e2**2*RHS(i)%e1 - 2*LHS(i)%e1*LHS(i)%E22*RHS(i)%R + 2*LHS(i)%e1*LHS(i)%E22*RHS(i)%R**2 - 2*LHS(i)%e2*LHS(i)%E12*RHS(i)%R + 2*LHS(i)%e2*LHS(i)%E12*RHS(i)%R**2 - 2*LHS(i)%e2*LHS(i)%e1*RHS(i)%e2 + 2*LHS(i)%e2**2*RHS(i)%e1*RHS(i)%R + 4*LHS(i)%e2*LHS(i)%e1*RHS(i)%e2*RHS(i)%R - LHS(i)%e2**2*RHS(i)%e1*RHS(i)%R*log(LHS(i)%R) + LHS(i)%e2**2*RHS(i)%e1*RHS(i)%R**2*log(LHS(i)%R) - 2*LHS(i)%e2*LHS(i)%e1*RHS(i)%e2*RHS(i)%R*log(LHS(i)%R) + 2*LHS(i)%e2*LHS(i)%e1*RHS(i)%e2*RHS(i)%R**2*log(LHS(i)%R)) + LHS(i)%R**2*(2*LHS(i)%E122*RHS(i)%R + 2*LHS(i)%e1*RHS(i)%E22 + 2*LHS(i)%e2*RHS(i)%E12 + 2*RHS(i)%e1*LHS(i)%E22 + 2*RHS(i)%e2*LHS(i)%E12 + 2*LHS(i)%e1*RHS(i)%e2**2*log(LHS(i)%R) + 2*LHS(i)%e1*RHS(i)%E22*RHS(i)%R*log(LHS(i)%R) + LHS(i)%e1*RHS(i)%e2**2*RHS(i)%R*log(LHS(i)%R)**2 + 2*LHS(i)%e2*RHS(i)%E12*RHS(i)%R*log(LHS(i)%R) + 4*LHS(i)%e2*RHS(i)%e2*RHS(i)%e1*log(LHS(i)%R) + 2*RHS(i)%e1*LHS(i)%E22*RHS(i)%R*log(LHS(i)%R) + 2*RHS(i)%e2*LHS(i)%E12*RHS(i)%R*log(LHS(i)%R) + 2*LHS(i)%e2*RHS(i)%e2*RHS(i)%e1*RHS(i)%R*log(LHS(i)%R)**2) + (2*RHS(i)%E122 + 2*RHS(i)%e1*RHS(i)%E22*log(LHS(i)%R) + 2*RHS(i)%e2*RHS(i)%E12*log(LHS(i)%R) + RHS(i)%e2**2*RHS(i)%e1*log(LHS(i)%R)**2)*LHS(i)%R**3*log(LHS(i)%R) + LHS(i)%e2**2*LHS(i)%e1*RHS(i)%R*(2 - 3*RHS(i)%R + RHS(i)%R**2))/LHS(i)%R**3
          RES(i)%E222 = exp(RHS(i)%R*log(LHS(i)%R))*((1/2)*(LHS(i)%e2*RHS(i)%R + RHS(i)%e2*LHS(i)%R*log(LHS(i)%R))*((2*LHS(i)%E22*LHS(i)%R - LHS(i)%e2**2)*RHS(i)%R + 2*LHS(i)%e2*RHS(i)%e2*LHS(i)%R + 2*RHS(i)%E22*LHS(i)%R**2*log(LHS(i)%R) + (LHS(i)%e2*RHS(i)%R + RHS(i)%e2*LHS(i)%R*log(LHS(i)%R))**2) + (-1/3)*(-3*LHS(i)%E222*LHS(i)%R**2 + (LHS(i)%E22*LHS(i)%R - LHS(i)%e2**2)*LHS(i)%e2 + 2*LHS(i)%e2*LHS(i)%E22*LHS(i)%R)*RHS(i)%R + LHS(i)%e2*RHS(i)%E22*LHS(i)%R**2 + RHS(i)%E222*LHS(i)%R**3*log(LHS(i)%R) + (1/2)*(2*LHS(i)%E22*LHS(i)%R - LHS(i)%e2**2)*RHS(i)%e2*LHS(i)%R + (-1/3)*(LHS(i)%e2*RHS(i)%R + RHS(i)%e2*LHS(i)%R*log(LHS(i)%R))**3)/LHS(i)%R**3
          ! Order 2
          RES(i)%E11 = exp(RHS(i)%R*log(LHS(i)%R))*((1/2)*(2*LHS(i)%E11*LHS(i)%R - LHS(i)%e1**2)*RHS(i)%R + LHS(i)%e1*RHS(i)%e1*LHS(i)%R + RHS(i)%E11*LHS(i)%R**2*log(LHS(i)%R) + (1/2)*(LHS(i)%e1*RHS(i)%R + RHS(i)%e1*LHS(i)%R*log(LHS(i)%R))**2)/LHS(i)%R**2
          RES(i)%E12 = exp(RHS(i)%R*log(LHS(i)%R))*((LHS(i)%E12*RHS(i)%R + LHS(i)%e1*RHS(i)%e2 + LHS(i)%e2*RHS(i)%e1 + LHS(i)%e1*RHS(i)%e2*RHS(i)%R*log(LHS(i)%R) + LHS(i)%e2*RHS(i)%e1*RHS(i)%R*log(LHS(i)%R))*LHS(i)%R + (RHS(i)%E12 + RHS(i)%e2*RHS(i)%e1*log(LHS(i)%R))*LHS(i)%R**2*log(LHS(i)%R) + LHS(i)%e2*LHS(i)%e1*(-1 + RHS(i)%R)*RHS(i)%R)/LHS(i)%R**2
          RES(i)%E22 = exp(RHS(i)%R*log(LHS(i)%R))*((1/2)*(2*LHS(i)%E22*LHS(i)%R - LHS(i)%e2**2)*RHS(i)%R + LHS(i)%e2*RHS(i)%e2*LHS(i)%R + RHS(i)%E22*LHS(i)%R**2*log(LHS(i)%R) + (1/2)*(LHS(i)%e2*RHS(i)%R + RHS(i)%e2*LHS(i)%R*log(LHS(i)%R))**2)/LHS(i)%R**2
          ! Order 1
          RES(i)%E1 = exp(RHS(i)%R*log(LHS(i)%R))*(LHS(i)%e1*RHS(i)%R + RHS(i)%e1*LHS(i)%R*log(LHS(i)%R))/LHS(i)%R
          RES(i)%E2 =  exp(RHS(i)%R*log(LHS(i)%R))*(LHS(i)%e2*RHS(i)%R + RHS(i)%e2*LHS(i)%R*log(LHS(i)%R))/LHS(i)%R
          ! Order 0
          RES(i)%R = LHS(i)%R**RHS(i)%R
 
      END DO

   END SUBROUTINE pow_oo_vv_to

   SUBROUTINE sqrt_v_to(X,RES)

      TYPE(onumm2n3), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1)),DER2(SIZE(x,1)),DER3(SIZE(x,1))
      TYPE(onumm2n3), INTENT(INOUT) :: RES(SIZE(x,1))

      
         DER0 = SQRT(X%R)
         DER1 = 0.5_DP*((X%R)**(-0.5_DP))
         DER2 = -0.25_DP*(X%R)**(-1.5_DP)
         DER3 = 0.375_DP*(X%R)**(-2.5_DP)
    
          

         CALL feval_v_to(X,DER0,DER1,DER2,DER3,RES)

   END SUBROUTINE sqrt_v_to
   SUBROUTINE sinh_v_to(X,RES)

      TYPE(onumm2n3), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1)),DER2(SIZE(x,1)),DER3(SIZE(x,1))
      TYPE(onumm2n3), INTENT(INOUT) :: RES(SIZE(x,1))

      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)
      DER2 = SINH(X%R)
      DER3 = COSH(X%R)

          

         CALL feval_v_to(X,DER0,DER1,DER2,DER3,RES)

   END SUBROUTINE sinh_v_to
   SUBROUTINE cosh_v_to(X,RES)

      TYPE(onumm2n3), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1)),DER2(SIZE(x,1)),DER3(SIZE(x,1))
      TYPE(onumm2n3), INTENT(INOUT) :: RES(SIZE(x,1))

      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)
      DER2 = COSH(X%R)
      DER3 = SINH(X%R)

      
          

         CALL feval_v_to(X,DER0,DER1,DER2,DER3,RES)

   END SUBROUTINE cosh_v_to

   SUBROUTINE feval_v_to(X,DER0,DER1,DER2,DER3,RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(ONUMm2n3), INTENT(IN)  :: X(:)
      REAL(DP), INTENT(IN)  :: DER0(SIZE(x,1)),DER1(SIZE(x,1)),DER2(SIZE(x,1)),DER3(SIZE(x,1))
      TYPE(ONUMm2n3), INTENT(INOUT) :: RES(SIZE(x,1))
      TYPE(ONUMm2n3) :: DX, DX_P
      INTEGER :: i

      ! Sets real part
      
      DO i=1,SIZE(x,1)
      RES(i)%R = DER0(i)
      FACTOR = 1.0_DP
      COEF   = 0.0_DP
      DX     = X(i)
      DX_P   = X(i)

      !  Set real part of deltas zero.
      DX%R = 0.0_DP
      DX_P%R = 0.0_DP

      ! Sets real part

      ! Sets order 1
      FACTOR = FACTOR * 1
      COEF = DER1(i) / FACTOR
      ! RES(i) = RES(i) COEF * DX_P
      ! Order 3
      RES(i)%E111 = RES(i)%E111+COEF*DX_P%E111
      RES(i)%E112 = RES(i)%E112+COEF*DX_P%E112
      RES(i)%E122 = RES(i)%E122+COEF*DX_P%E122
      RES(i)%E222 = RES(i)%E222+COEF*DX_P%E222
      ! Order 2
      RES(i)%E11 = RES(i)%E11+COEF*DX_P%E11
      RES(i)%E12 = RES(i)%E12+COEF*DX_P%E12
      RES(i)%E22 = RES(i)%E22+COEF*DX_P%E22
      ! Order 1
      RES(i)%E1 = RES(i)%E1+COEF*DX_P%E1
      RES(i)%E2 = RES(i)%E2+COEF*DX_P%E2
      ! DX_P = DX_P * DX
      ! Order 3
      DX_P%E111 = DX_P%E1*DX%E11+DX_P%E11*DX%E1
      DX_P%E112 = DX_P%E1*DX%E12+DX_P%E12*DX%E1+ &
               DX_P%E2*DX%E11+DX_P%E11*DX%E2
      DX_P%E122 = DX_P%E1*DX%E22+DX_P%E22*DX%E1+ &
               DX_P%E2*DX%E12+DX_P%E12*DX%E2
      DX_P%E222 = DX_P%E2*DX%E22+DX_P%E22*DX%E2
      ! Order 2
      DX_P%E11 = DX_P%E1*DX%E1
      DX_P%E12 = DX_P%E1*DX%E2+DX_P%E2*DX%E1
      DX_P%E22 = DX_P%E2*DX%E2
      
      ! Sets order 2
      FACTOR = FACTOR * 2
      COEF = DER2(i) / FACTOR
      ! RES(i) = RES(i) COEF * DX_P
      ! Order 3
      RES(i)%E111 = RES(i)%E111+COEF*DX_P%E111
      RES(i)%E112 = RES(i)%E112+COEF*DX_P%E112
      RES(i)%E122 = RES(i)%E122+COEF*DX_P%E122
      RES(i)%E222 = RES(i)%E222+COEF*DX_P%E222
      ! Order 2
      RES(i)%E11 = RES(i)%E11+COEF*DX_P%E11
      RES(i)%E12 = RES(i)%E12+COEF*DX_P%E12
      RES(i)%E22 = RES(i)%E22+COEF*DX_P%E22
      ! DX_P = DX_P * DX
      ! Order 3
      DX_P%E111 = DX_P%E11*DX%E1
      DX_P%E112 = DX_P%E12*DX%E1+DX_P%E11*DX%E2
      DX_P%E122 = DX_P%E22*DX%E1+DX_P%E12*DX%E2
      DX_P%E222 = DX_P%E22*DX%E2
      
      ! Sets order 3
      FACTOR = FACTOR * 3
      COEF = DER3(i) / FACTOR
      ! RES(i) = RES(i) COEF * DX_P
      ! Order 3
      RES(i)%E111 = RES(i)%E111+COEF*DX_P%E111
      RES(i)%E112 = RES(i)%E112+COEF*DX_P%E112
      RES(i)%E122 = RES(i)%E122+COEF*DX_P%E122
      RES(i)%E222 = RES(i)%E222+COEF*DX_P%E222
      ! DX_P = DX_P * DX
      
        END DO
      
   END SUBROUTINE feval_v_to



END MODULE array_interface_m2n3