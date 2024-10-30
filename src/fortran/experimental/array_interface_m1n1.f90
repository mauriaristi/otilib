MODULE array_interface_m1n1

    use iso_c_binding
    use otim1n1

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
    TYPE, BIND(C) :: oarrm1n1_t
       TYPE(c_ptr)        :: p_data
       INTEGER(c_int64_t) :: nrows
       INTEGER(c_int64_t) :: ncols
       INTEGER(c_int64_t) :: size
    END TYPE

CONTAINS
    
    SUBROUTINE test1(a,b) BIND(C)
        
        IMPLICIT NONE

        INTEGER, INTENT(IN) :: a
        INTEGER, INTENT(INOUT) :: b
    
        PRINT*, 'From Fortran test1 subroutine'
        print*, '-> Received: a=',a
        print*, '-> Received: b=',b
    
    END SUBROUTINE test1

    SUBROUTINE test2(a_ptr, n_a) BIND(C)
        ! Test to pass an intrinsic rank-1 array from C.
        IMPLICIT NONE

        ! subroutine inputs.
        REAL(c_double), INTENT(IN) :: a_ptr(n_a) !< Array 
        INTEGER, INTENT(IN)     :: n_a   !< Array dimension.

        ! Local declarations
        INTEGER :: i
        ! REAL(c_double), POINTER ::  a_arr(:)

        ! CALL c_f_pointer( a_ptr, a_arr, [n_a])
    
        PRINT*, 'From Fortran test2 subroutine'
        print*, 'Received array of size', n_a
        CALL pprint(a_ptr)
    
    END SUBROUTINE test2

    SUBROUTINE test3(a_ptr, n_a, m_a) BIND(C)
        ! Test to pass an intrinsic rank-2 array from C.
        IMPLICIT NONE

        ! subroutine inputs.
        REAL(c_double), INTENT(IN) :: a_ptr(n_a,m_a) !< Array 
        INTEGER, INTENT(IN)     :: n_a , m_a  !< Array dimension.

        ! Local declarations
        INTEGER :: i,j
        ! REAL(c_double), POINTER ::  a_arr(:)

        ! CALL c_f_pointer( a_ptr, a_arr, [n_a])
    
        PRINT*, 'From Fortran test3 subroutine'
        print*, 'Received array of size', n_a, m_a
        
        CALL pprint(a_ptr)
    
    END SUBROUTINE test3



    SUBROUTINE graph_eval(graph, stack_size, columns) BIND(C)
        ! Test to pass a graph as a rank-2 int64 array from C.
        IMPLICIT NONE

        ! subroutine inputs.
        INTEGER, INTENT(IN) :: stack_size, columns   !< Array dimension.
        INTEGER(c_int64_t), INTENT(IN) :: graph(columns,stack_size) !< Array (transposed)

        ! Local declarations
        INTEGER :: i,j

        PRINT*, 'From Fortran graph_eval subroutine'
        PRINT*, 'Received graph with stack_size:', stack_size
        
        ! The graph array is transposed from the C-configuration.
        DO j=1,stack_size
            DO i=1,3
                WRITE(*,'(I16,A2)',ADVANCE='NO') graph(i,j),', '
            END DO
            WRITE(*,*) " "
        END DO

        ! We
    
    END SUBROUTINE graph_eval

    SUBROUTINE pytorch_graph_eval_m1n1(graph, stack_size, c_arr, c_size,x_matso,w_matso) BIND(C)
        ! Test to pass a graph as a rank-2 int64 array from C.
        IMPLICIT NONE

        ! subroutine inputs.
        INTEGER, INTENT(IN) :: stack_size, c_size  !< Array dimensions.
        TYPE(oarrm1n1_t), INTENT(IN) :: x_matso      !< input arrays. (Contains dimensions)
        TYPE(oarrm1n1_t), INTENT(INOUT) :: w_matso   !< output arrays. (Contains dimensions)
        REAL(c_double), INTENT(IN) :: c_arr(c_size)  !< constant arrays.
        INTEGER(c_int64_t), INTENT(IN) :: graph(3,stack_size) !< Array (transposed)

        ! Local declarations
        INTEGER :: i,j, p1, p2, k
        INTEGER(c_int64_t) :: node_oper

        TYPE(onumm1n1), POINTER :: x_arr(:,:)
        TYPE(onumm1n1), POINTER :: w_arr(:,:)

        TYPE(onumm1n1), POINTER :: p1_ptr(:) ! %%%%%% added new pointer variable.
        TYPE(onumm1n1), POINTER :: p2_ptr(:) ! %%%%%% added new pointer variable.

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

            ! CASE(op_sinh)

            !     ! Get the id of the variable to load.
            !     p1 = graph(2,j)+1

            !     ! PRINT*, "performing sinh(xi) evaluation"
            !     w_arr(:,j) = sinh(w_arr(:,p1))

            ! CASE(op_cosh)

            !     ! Get the id of the variable to load.
            !     p1 = graph(2,j)+1

            !     ! PRINT*, "performing cosh(xi) evaluation"
            !     w_arr(:,j) = cosh(w_arr(:,p1))

            CASE DEFAULT
                PRINT*, "ERROR: Undefined node operation in the graph structure."
                PRINT*, ' EXITING - .'
                EXIT
        END SELECT

        END DO

        ! print*," "
        ! print*,"-> w_arr (after evaluation):"
        ! CALL pprint(w_arr)
    
    END SUBROUTINE pytorch_graph_eval_m1n1

    SUBROUTINE sub_oo_vv_to(lhs,rhs,res)
      IMPLICIT NONE
      TYPE(onumm1n1), INTENT(IN) :: lhs(:)
      TYPE(onumm1n1), INTENT(IN) :: rhs(SIZE(lhs,1))
      TYPE(onumm1n1), INTENT(INOUT) :: res(SIZE(lhs,1))

      INTEGER :: i

      ! Subtraction like function 'LHS - RHS'
      DO i=1,SIZE(lhs,1)
          !  Real
          res(i)%r = lhs(i)%r - rhs(i)%r

          ! Order 1
          res(i)%e1 = lhs(i)%e1 - rhs(i)%e1
      END DO

   END SUBROUTINE sub_oo_vv_to

   SUBROUTINE add_oo_vv_to(lhs,rhs,res)
      IMPLICIT NONE
      TYPE(onumm1n1), INTENT(IN) :: lhs(:)
      TYPE(onumm1n1), INTENT(IN) :: rhs(SIZE(lhs,1))
      TYPE(onumm1n1), INTENT(INOUT) :: res(SIZE(lhs,1))

      INTEGER :: i

      ! Addition like function 'LHS + RHS'
      DO i=1,SIZE(lhs,1)
          !  Real
          res(i)%r = lhs(i)%r + rhs(i)%r

          ! Order 1
          res(i)%e1 = lhs(i)%e1 + rhs(i)%e1
      END DO

   END SUBROUTINE add_oo_vv_to

   SUBROUTINE mul_oo_vv_to(lhs,rhs,res)
      IMPLICIT NONE
      TYPE(onumm1n1), INTENT(IN) :: lhs(:)
      TYPE(onumm1n1), INTENT(IN) :: rhs(SIZE(lhs,1))
      TYPE(onumm1n1), INTENT(INOUT) :: res(SIZE(lhs,1))

      INTEGER :: i

      ! Addition like function 'LHS + RHS'
      DO i=1,SIZE(lhs,1)
          !  Real
          res(i)%r = lhs(i)%r*rhs(i)%r

          ! Order 1
          res(i)%e1 = lhs(i)%r*rhs(i)%e1 + lhs(i)%e1*rhs(i)%r
 
      END DO

   END SUBROUTINE mul_oo_vv_to

   SUBROUTINE div_oo_vv_to(lhs,rhs,res)
      IMPLICIT NONE
      TYPE(onumm1n1), INTENT(IN) :: lhs(:)
      TYPE(onumm1n1), INTENT(IN) :: rhs(SIZE(lhs,1))
      TYPE(onumm1n1), INTENT(INOUT) :: res(SIZE(lhs,1))

      INTEGER :: i

      ! Addition like function 'LHS + RHS'
      DO i=1,SIZE(lhs,1)
          !  Real
          res(i)%r = lhs(i)%r/rhs(i)%r

          ! Order 1
          res(i)%e1 = (1/(rhs(i)%r*rhs(i)%r))*(lhs(i)%e1*rhs(i)%r - lhs(i)%r*rhs(i)%e1)
 
      END DO

   END SUBROUTINE div_oo_vv_to
   SUBROUTINE sin_v_to(X,RES)

      TYPE(onumm1n1), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1))
      TYPE(onumm1n1), INTENT(INOUT) :: RES(SIZE(x,1))

      
        DER0 = SIN(X%R)
        DER1 = COS(X%R)
      
          

         CALL feval_v_to(X,DER0,DER1,RES)

   END SUBROUTINE sin_v_to

   SUBROUTINE cos_v_to(X,RES)

      TYPE(onumm1n1), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1))
      TYPE(onumm1n1), INTENT(INOUT) :: RES(SIZE(x,1))

      
        DER0 = COS(X%R)
        DER1 = -SIN(X%R)
      
          

         CALL feval_v_to(X,DER0,DER1,RES)

   END SUBROUTINE cos_v_to

   SUBROUTINE exp_v_to(X,RES)

      TYPE(onumm1n1), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1))
      TYPE(onumm1n1), INTENT(INOUT) :: RES(SIZE(x,1))

      
        DER0 = EXP(X%R)
        DER1 = EXP(X%R)
      
          

         CALL feval_v_to(X,DER0,DER1,RES)

   END SUBROUTINE exp_v_to

   SUBROUTINE log_v_to(X,RES)

      TYPE(onumm1n1), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1))
      TYPE(onumm1n1), INTENT(INOUT) :: RES(SIZE(x,1))

      
        DER0 = LOG(X%R)
        DER1 = 1/(X%R)
      
          

         CALL feval_v_to(X,DER0,DER1,RES)

   END SUBROUTINE log_v_to


   SUBROUTINE pow_oo_vv_to(lhs,rhs,res)
      IMPLICIT NONE
      TYPE(onumm1n1), INTENT(IN) :: lhs(:)
      TYPE(onumm1n1), INTENT(IN) :: rhs(SIZE(lhs,1))
      TYPE(onumm1n1), INTENT(INOUT) :: res(SIZE(lhs,1))

      INTEGER :: i

      ! Addition like function 'LHS + RHS'
      DO i=1,SIZE(lhs,1)
          !  Real
          res(i)%r = lhs(i)%r**rhs(i)%r

          ! Order 1
          res(i)%e1 = exp(RHS(i)%R*log(LHS(i)%R))*(LHS(i)%e1*RHS(i)%R + RHS(i)%e1*LHS(i)%R*log(LHS(i)%R))/LHS(i)%R

 
      END DO

   END SUBROUTINE pow_oo_vv_to

   SUBROUTINE sqrt_v_to(X,RES)

      TYPE(onumm1n1), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1))
      TYPE(onumm1n1), INTENT(INOUT) :: RES(SIZE(x,1))

      
        DER0 = (X%R)**(0.5d0)
        DER1 = 0.5d0*(X%R)**(-0.5d0)
      
          

         CALL feval_v_to(X,DER0,DER1,RES)

   END SUBROUTINE sqrt_v_to
   SUBROUTINE sinh_v_to(X,RES)

      TYPE(onumm1n1), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1))
      TYPE(onumm1n1), INTENT(INOUT) :: RES(SIZE(x,1))

      
        DER0 = SINH(X%R)
        DER1 = COSH(X%R)
      
          

         CALL feval_v_to(X,DER0,DER1,RES)

   END SUBROUTINE sinh_v_to
   SUBROUTINE cosh_v_to(X,RES)

      TYPE(onumm1n1), INTENT(IN) :: x(:)
      REAL(dp) :: DER0(SIZE(x,1)),DER1(SIZE(x,1))
      TYPE(onumm1n1), INTENT(INOUT) :: RES(SIZE(x,1))

      
        DER0 = COSH(X%R)
        DER1 = SINH(X%R)
      
          

         CALL feval_v_to(X,DER0,DER1,RES)

   END SUBROUTINE cosh_v_to

   SUBROUTINE feval_v_to(X,DER0,DER1,RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(ONUMM1N1), INTENT(IN)  :: X(:)
      REAL(DP), INTENT(IN)  :: DER0(SIZE(x,1)),DER1(SIZE(x,1))
      TYPE(ONUMM1N1), INTENT(INOUT) :: RES(SIZE(x,1))
      TYPE(ONUMM1N1) :: DX, DX_P
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

         

          ! Sets order 1
          FACTOR = FACTOR * 1
          COEF = DER1(i) / FACTOR
          ! RES = RES COEF * DX_P
          ! Order 1
          RES(i)%E1 = RES(i)%E1+COEF*DX_P%E1
        END DO
      
   END SUBROUTINE feval_v_to

END MODULE array_interface_m1n1