!********************************************************************************************************!
!                                          module_name
!********************************************************************************************************!
!> @brief This module defines a sparse implementation of the Order truncated imaginary numbers in Fortran
!! A key characteristic of this implementation is the support of OTI structure as a parameterized derived
!! type that simplifies the support for arbitrary number of imaginary directions, not requiring a fixed.
!! definition of the type in 
!!
!! Author: Mauricio Aristizabal, PhD
!! Last mod date: Jan/7/2025
!********************************************************************************************************!
MODULE param_sparse_oti
    ! ---------------------------------------------------------------------------------------------------!
    USE real_utils
    USE master_parameters
    ! ---------------------------------------------------------------------------------------------------!
    IMPLICIT NONE
    ! ---------------------------------------------------------------------------------------------------!
    INTEGER(ord_t),   PARAMETER, PRIVATE ::  max_n = 3  !< Max. Imag. order supported.
    INTEGER(bases_t), PARAMETER, PRIVATE ::  max_m = 4  !< Max. num. basis supported.
    INTEGER(imdir_t), PARAMETER, DIMENSION(max_n)   ::  ndir_order = [ 4, 10, 20 ]
    INTEGER(imdir_t), PARAMETER, PRIVATE            ::  max_ndir = 34 !< Max. im. dirs supportd.
    INTEGER(imdir_t), PARAMETER, DIMENSION(max_n+1) ::  ndir_order_cum = [ 1, 5, 15, 35 ]
    ! ---------------------------------------------------------------------------------------------------!
    TYPE ssoti
       REAL(dp)                       :: r                  !<- Real coefficient.
       REAL(dp),                      :: im(max_m,max_n)    !<- Imaginary coefficients. (data)
       INTEGER(ord_t)                 :: act_ord=0          !<- Actual order of the number. 
       INTEGER(ord_t)                 :: trc_ord=0          !<- Truncation order of the number
    CONTAINS
       final :: ssoti_destructor
    END TYPE ssoti
    ! ----------------------------------------------------------------------------------------------------!
    INTERFACE PPRINT
       MODULE PROCEDURE ssoti_pprint_s!, ssoti_pprint_v, ssoti_pprint_m
    END INTERFACE
 
    INTERFACE PPRINT
       MODULE PROCEDURE ssoti_pfullprint_s
    END INTERFACE
 
    INTERFACE ASSIGNMENT(=)
       MODULE PROCEDURE ssoti_assign_r, ssoti_assign_i
    END INTERFACE
 
    INTERFACE OPERATOR(+)
       MODULE PROCEDURE ssoti_add_ro_ss, ssoti_add_or_ss
    !    ssoti_add_oo_ss ! Scalar addition OTI - OTI
    END INTERFACE
 
    INTERFACE OPERATOR(*)
       MODULE PROCEDURE ssoti_mul_ro_ss, ssoti_mul_or_ss
    END INTERFACE
 
    INTERFACE EPS
       MODULE PROCEDURE ssoti_epsilon_i     ! Create ssoti from integer 
       ! MODULE PROCEDURE ssoti_epsilon_2i    ! Create ssoti from two integers
       ! MODULE PROCEDURE ssoti_epsilon_imdir ! Create ssoti from imdir
       ! MODULE PROCEDURE ssoti_epsilon_list  ! Create ssoti from list representing IMDIR
    END INTERFACE
    ! -----------------------------------------------------------------------------------------!
 
    CONTAINS
 
    !==========================================================================================!
    !> @brief This function assigns a real scalar to an OTI number object.
    !! 
    !! res = rhs
    !!
    !! @param[inout] res: otinum object.
    !! @param[in] rhs: (real) Real number to be assigned.
    !!
    !******************************************************************************************!
    SUBROUTINE ssoti_assign_r(res,rhs)
       ! --------------------------------------------------------------------------------------!
       IMPLICIT NONE
       ! --------------------------------------------------------------------------------------!
       REAL(dp), INTENT(IN) :: rhs
       TYPE(ssoti), INTENT(OUT) :: res
       ! --------------------------------------------------------------------------------------!
       
       ! Real
       res%r = rhs
       res%im(:) = 0.0 ! Initialized for safety (TODO: Not required though).
             
       ! Actual order and order should be initialized to zero, but hereinitialized for safety.
       res%act_ord = 0
 
       ! Truncation order is zero for real numbers
       res%trc_ord  = 0
       
    END SUBROUTINE ssoti_assign_r
    !==========================================================================================!
 
    !==========================================================================================!
    !> @brief This function assigns a real number to an OTI number object.
    !! 
    !! res = rhs
    !!
    !! @param[inout] res: otinum object.
    !! @param[in] rhs: (integer) Real number to be assigned.
    !!
    !******************************************************************************************!
    SUBROUTINE ssoti_assign_i(res,rhs)
       ! --------------------------------------------------------------------------------------!
       IMPLICIT NONE
       ! --------------------------------------------------------------------------------------!
       INTEGER, INTENT(IN) :: rhs
       TYPE(ssoti), INTENT(OUT) :: res
       ! --------------------------------------------------------------------------------------!
       
       ! Real
       res = REAL(rhs, DP)
       
    END SUBROUTINE ssoti_assign_i
    !==========================================================================================!
 
    !==========================================================================================!
    !> @brief Add real and ssoti 
    !! 
    !! lhs + rhs
    !! 
    !! @param[in] lhs: (real) left hand side operation.
    !! @param[in] rhs: (ssoti) right hand side operation.
    !******************************************************************************************!
    FUNCTION ssoti_add_ro_ss(lhs,rhs) RESULT (res)
       ! --------------------------------------------------------------------------------------!
       IMPLICIT NONE
       ! --------------------------------------------------------------------------------------!
       REAL(dp), INTENT(IN)      :: lhs
       TYPE(ssoti), INTENT(IN) :: rhs
       TYPE(ssoti)             :: res
       INTEGER(ord_t) ::i_ord
       INTEGER(nnz_t) ::i_im
 
       ! --------------------------------------------------------------------------------------!
       
       ! Add two real numbers. This also deallocates memory.
       res = lhs + rhs.r 
 
       IF (rhs%act_ord>0) THEN
          
          ! Allocate memory
          ALLOCATE( res%imcoef( SIZE( rhs%imcoef, 1) ), &
                    res%imdir(  SIZE( rhs%imdir,  1) ), &
                    res%nnz(    SIZE( rhs%nnz,    1) ) )
          
          res%act_ord = rhs%act_ord
          res%trc_ord   = rhs%trc_ord
          res%nnz(1)  = rhs%nnz(1) ! This should be 1.
          
          ! Copy information from rhs to res.
          DO i_ord = 1, rhs%act_ord            
             ! Loop through the imaginary terms.
             res%nnz(i_ord+1) = rhs%nnz(i_ord+1)
          
             DO i_im=rhs%nnz(i_ord),rhs%nnz(i_ord+1)-1
          
                res%imcoef(i_im) = rhs%imcoef(i_im)
                res%imdir( i_im) = rhs%imdir( i_im)
          
             END DO
 
          END DO
 
       END IF 
 
    END FUNCTION ssoti_add_ro_ss
    !==========================================================================================!
 
    !==========================================================================================!
    !> @brief Add  ssoti and real
    !! 
    !! lhs + rhs
    !! 
    !! @param[in] lhs: (ssoti) left hand side operation.
    !! @param[in] rhs: (real) right hand side operation.
    !******************************************************************************************!
    FUNCTION ssoti_add_or_ss(lhs,rhs) RESULT (res)
       ! --------------------------------------------------------------------------------------!
       IMPLICIT NONE
       ! --------------------------------------------------------------------------------------!
       TYPE(ssoti), INTENT(IN) :: lhs
       REAL(dp), INTENT(IN)      :: rhs
       TYPE(ssoti)             :: res
       INTEGER(ord_t) ::i_ord
       INTEGER(nnz_t) ::i_im
 
       ! --------------------------------------------------------------------------------------!
       
       ! Add two real numbers. This also deallocates memory.
       res = lhs.r + rhs
 
       IF (lhs%act_ord>0) THEN
          
          ! Allocate memory
          ALLOCATE( res%imcoef( SIZE( lhs%imcoef, 1) ), &
                    res%imdir(  SIZE( lhs%imdir,  1) ), &
                    res%nnz(    SIZE( lhs%nnz,    1) ) )
          
          res%act_ord = lhs%act_ord
          res%trc_ord   = lhs%trc_ord
          res%nnz(1)  = lhs%nnz(1) ! This should be 1.
          
          ! Copy information from rhs to res.
          DO i_ord = 1, lhs%act_ord            
             ! Loop through the imaginary terms.
             res%nnz(i_ord+1) = lhs%nnz(i_ord+1)
          
             DO i_im=lhs%nnz(i_ord),lhs%nnz(i_ord+1)-1
          
                res%imcoef(i_im) = lhs%imcoef(i_im)
                res%imdir( i_im) = lhs%imdir( i_im)
          
             END DO
 
          END DO
 
       END IF 
 
    END FUNCTION ssoti_add_or_ss
    !==========================================================================================!
 
    !==========================================================================================!
    !> @brief Multiply real and ssoti 
    !! 
    !! lhs * rhs
    !! 
    !! @param[in] lhs: (real) left hand side operation.
    !! @param[in] rhs: (ssoti) right hand side operation.
    !******************************************************************************************!
    FUNCTION ssoti_mul_ro_ss(lhs,rhs) RESULT (res)
       ! --------------------------------------------------------------------------------------!
       IMPLICIT NONE
       ! --------------------------------------------------------------------------------------!
       REAL(dp), INTENT(IN)      :: lhs
       TYPE(ssoti), INTENT(IN) :: rhs
       TYPE(ssoti)             :: res
       INTEGER(ord_t) :: i_ord
       INTEGER(nnz_t) :: i_im
 
       ! --------------------------------------------------------------------------------------!
       
       ! Add two real numbers. This also deallocates memory.
       res = lhs * rhs.r 
 
       IF (rhs%act_ord>0) THEN
          
          ! Allocate memory
          ALLOCATE( res%imcoef( SIZE( rhs%imcoef, 1) ), &
                    res%imdir(  SIZE( rhs%imdir,  1) ), &
                    res%nnz(    SIZE( rhs%nnz,    1) ) )
          
          res%act_ord = rhs%act_ord
          res%trc_ord   = rhs%trc_ord
          res%nnz(1)  = rhs%nnz(1) ! This should be 1.
          
          ! Copy information from rhs to res.
          DO i_ord = 1, rhs%act_ord            
             ! Loop through the imaginary terms.
             res%nnz(i_ord+1) = rhs%nnz(i_ord+1)
          
             DO i_im=rhs%nnz(i_ord),rhs%nnz(i_ord+1)-1
          
                res%imcoef(i_im) = lhs*rhs%imcoef(i_im)
                res%imdir( i_im) = rhs%imdir( i_im)
          
             END DO
 
          END DO
 
       END IF 
 
    END FUNCTION ssoti_mul_ro_ss
    !==========================================================================================!
 
    !==========================================================================================!
    !> @brief Multiply  ssoti and real
    !! 
    !! lhs * rhs
    !! 
    !! @param[in] lhs: (ssoti) left hand side operation.
    !! @param[in] rhs: (real) right hand side operation.
    !******************************************************************************************!
    FUNCTION ssoti_mul_or_ss(lhs,rhs) RESULT (res)
       ! --------------------------------------------------------------------------------------!
       IMPLICIT NONE
       ! --------------------------------------------------------------------------------------!
       TYPE(ssoti), INTENT(IN) :: lhs
       REAL(dp), INTENT(IN)      :: rhs
       TYPE(ssoti)             :: res
       INTEGER(ord_t) ::i_ord
       INTEGER(nnz_t) ::i_im
       ! --------------------------------------------------------------------------------------!
       
       ! Add two real numbers. This also deallocates memory.
       res = lhs.r * rhs
 
       IF (lhs%act_ord>0) THEN
          
          ! Allocate memory
          ALLOCATE( res%imcoef( SIZE( lhs%imcoef, 1) ), &
                    res%imdir(  SIZE( lhs%imdir,  1) ), &
                    res%nnz(    SIZE( lhs%nnz,    1) ) )
          
          res%act_ord = lhs%act_ord
          res%trc_ord   = lhs%trc_ord
          res%nnz(1)  = lhs%nnz(1) ! This should be 1.
          
          ! Copy information from rhs to res.
          DO i_ord = 1, lhs%act_ord            
             ! Loop through the imaginary terms.
             res%nnz(i_ord+1) = lhs%nnz(i_ord+1)
          
             DO i_im=lhs%nnz(i_ord),lhs%nnz(i_ord+1)-1
          
                res%imcoef(i_im) = rhs*lhs%imcoef(i_im)
                res%imdir( i_im) = lhs%imdir( i_im)
          
             END DO
 
          END DO
 
       END IF 
 
    END FUNCTION ssoti_mul_or_ss
    !==========================================================================================!
 
    !==========================================================================================!
    !> @brief This function only creates imaginary directions with integer parameters.
    !!        of actual order 1.
    !!
    !! @param[in] base: Imaginary base to be created.
    !! @param[in] order(optional): Truncation order to be set to the number. Default 1.
    !!
    !******************************************************************************************!
    FUNCTION ssoti_epsilon_i(base,order) RESULT (res)
       ! --------------------------------------------------------------------------------------!
       IMPLICIT NONE
       ! --------------------------------------------------------------------------------------!
       INTEGER, INTENT(IN) :: base
       INTEGER, INTENT(IN),OPTIONAL :: order
       INTEGER(ord_t)      :: i_ord
       TYPE(ssoti)         :: res
       ! --------------------------------------------------------------------------------------!
 
       ! Create number as a zero. It also Deallocates memory.
       res = zero
 
       IF ( PRESENT(order) ) THEN
          i_ord = order
       ELSE
          i_ord = 1
       END IF
       
       ! Set truncation order to the one given.
       res%trc_ord = i_ord
 
       IF (i_ord == 0) THEN
          res = one
       ELSE
          ! Only if imaginary basis supported, allocate memory. See how to update this.
          IF (base <= max_m) THEN
             
             ALLOCATE( res%imcoef(1), res%imdir(1), res%nnz(i_ord+1) ) 
 
             res%act_ord  = i_ord
             
             res%imcoef(1) = one
             res%imdir(1)  = base
             
             res%nnz(:) = 1
             res%nnz(i_ord+1) = 2
          
          END IF
 
       END IF
 
    END FUNCTION ssoti_epsilon_i
    !==========================================================================================!
 
    ! !==========================================================================================!
    ! !>
    ! !!
    ! !!
    ! !******************************************************************************************!
    ! FUNCTION ssoti_epsilon_2i(idx,ordin,order) RESULT (res)
    !    ! --------------------------------------------------------------------------------------!
    !    IMPLICIT NONE
    !    ! --------------------------------------------------------------------------------------!
    !    INTEGER, INTENT(IN) :: idx
    !    INTEGER, INTENT(IN) :: ordin
    !    INTEGER, INTENT(IN),OPTIONAL :: order
    !    INTEGER(ord_t)      :: i_ord
    !    INTEGER(imdir_t)    :: i_idx
    !    TYPE(ssoti)       :: res
    !    ! --------------------------------------------------------------------------------------!
 
    !    res = zero
    !    i_ord = ordin
       
    !    IF ( PRESENT(order) ) THEN
    !       i_ord = MIN(MAX(order,ordin),max_n)
    !    END IF
 
    !    IF (idx <= ndir_order(ordin) .and. ordin <= max_n ) THEN
 
    !       i_idx = ndir_order_cum(ordin)
 
    !       res%im(i_idx)    = one 
    !       res%imdir(i_idx) = idx
    !       res%nnz(ordin)   = 1
    !       res%act_ord      = ordin
    !       res%trc_ord        = i_ord
 
    !    END IF
 
 
    ! END FUNCTION ssoti_epsilon_2i
    ! !==========================================================================================!
 
 
 
    ! ssoti_pfullprint_s
    !==========================================================================================!
    !> @ brief This function prints in a human friendly manner a ssoti object.
    !! 
    !! @param[in] num: ssoti object to be printed.
    !! @param[in] fmt(optional): Format of the real coefficients to be printed. Default: 'F10.4'
    !! @param[in] unit(optional): Unit to print. Default 6.
    !! @param[in] advance(optional): if 'YES', advance to next line, otherwise sets . Default 'YES'.
    !!
    !******************************************************************************************!
    SUBROUTINE ssoti_pfullprint_s(num, fmt, unit, advance)
       ! --------------------------------------------------------------------------------------!
       IMPLICIT NONE
       ! --------------------------------------------------------------------------------------!
       ! Inputs
       TYPE(ssoti), INTENT(IN), TARGET      :: num
       CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
       CHARACTER(len=*), INTENT(IN), OPTIONAL :: advance
       INTEGER, INTENT(IN), OPTIONAL          :: unit
       ! --------------------------------------------------------------------------------------!
       ! Local Defs.
       CHARACTER(len=:),ALLOCATABLE             :: output_format
       CHARACTER(len=:),ALLOCATABLE             :: advance_option
       INTEGER                                  :: unt
       INTEGER(ord_t)                           :: i_ord
       INTEGER(imdir_t)                         :: i_im
       INTEGER                                  :: offset, next_offset
       ! --------------------------------------------------------------------------------------!
       IF ( PRESENT(unit) ) THEN
          unt = unit
       ELSE
          unt = 6
       END IF
 
       IF ( PRESENT(fmt) ) THEN
          output_format = '('//trim(fmt)//')'
       ELSE
          output_format = '(F10.4)'
       END IF
 
       IF (PRESENT(advance)) THEN
          advance_option = trim(advance)
       ELSE
          advance_option = 'YES'
       END IF      
 
       ! Print real part.
       CALL pprint(num%r,unit=unt,fmt=output_format,advance='no')
       WRITE(unt,'(A)',advance='NO') ' ' !<- Adds space.
 
       ! Print imaginary coefficients.
       DO i_ord = 1, num%act_ord
          
          ! Loop through the imaginary terms
          DO i_im=num%nnz(i_ord),num%nnz(i_ord+1)
             
             ! Print imaginary coefficient 
             WRITE(unt,'(A)',advance='NO') '+ ' 
 
             CALL pprint( num%imcoef(i_im), unit=unt, fmt=output_format, advance='no')
              
             WRITE(unt,'(A)',advance='NO') '*eps(' 
             WRITE(unt,'(I2,A,I2)',advance='NO') num%imdir(i_im), ',', i_ord
             WRITE(unt,'(A)',advance='NO') ') '    !<- Adds space.
       
          END DO
 
       END DO
 
       WRITE(unt,'(A)',advance=advance_option) ''
       !
    END SUBROUTINE ssoti_pfullprint_s
    !==========================================================================================!
 
 
    !==========================================================================================!
    !> @ brief This function prints in a human friendly manner a ssoti object.
    !! 
    !! @param[in] num: ssoti object to be printed.
    !! @param[in] fmt(optional): Format of the real coefficients to be printed. Default: 'F10.4'
    !! @param[in] unit(optional): Unit to print. Default 6.
    !! @param[in] advance(optional): if 'YES', advance to next line, otherwise sets . Default 'YES'.
    !!
    !******************************************************************************************!
    SUBROUTINE ssoti_pprint_s(num, fmt, unit, advance)
       ! --------------------------------------------------------------------------------------!
       IMPLICIT NONE
       ! --------------------------------------------------------------------------------------!
       ! Inputs
       TYPE(ssoti), INTENT(IN), TARGET      :: num
       CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
       CHARACTER(len=*), INTENT(IN), OPTIONAL :: advance
       INTEGER, INTENT(IN), OPTIONAL          :: unit
       ! --------------------------------------------------------------------------------------!
       ! Local Defs.
       CHARACTER(len=:),ALLOCATABLE             :: output_format
       CHARACTER(len=:),ALLOCATABLE             :: advance_option
       INTEGER                                  :: unt
       INTEGER(ord_t)                           :: i_ord
       INTEGER(imdir_t)                         :: i_im
       INTEGER                                  :: offset, next_offset
       ! --------------------------------------------------------------------------------------!
       IF ( PRESENT(unit) ) THEN
          unt = unit
       ELSE
          unt = 6
       END IF
 
       IF ( PRESENT(fmt) ) THEN
          output_format = '('//trim(fmt)//')'
       ELSE
          output_format = '(F10.4)'
       END IF
 
       IF (PRESENT(advance)) THEN
          advance_option = trim(advance)
       ELSE
          advance_option = 'YES'
       END IF      
 
       ! Print real part.
       CALL pprint(num%r,unit=unt,fmt=output_format,advance='no')
       WRITE(unt,'(A)',advance='NO') ' ' !<- Adds space.
 
       ! Print imaginary coefficients (if memory has been allocated).
       IF (ALLOCATED(num%imcoef).and.ALLOCATED(num%imdir).and.ALLOCATED(num%nnz)) THEN
          DO i_ord = 1, num%act_ord
             
             ! Loop through the imaginary terms
             DO i_im=num%nnz(i_ord),num%nnz(i_ord+1)-1
                
                ! Print imaginary coefficient 
                WRITE(unt,'(A)',advance='NO') '+ ' !<- Adds space.
 
                CALL pprint( num%imcoef(i_im), unit=unt, fmt=output_format, advance='no')
                 
                WRITE(unt,'(A)',advance='NO') '*eps(' 
                WRITE(unt,'(I2,A,I2)',advance='NO') num%imdir(i_im), ',', i_ord
                WRITE(unt,'(A)',advance='NO') ') '    !<- Adds space.
          
             END DO
 
          END DO
 
       END IF 
 
       WRITE(unt,'(A)',advance=advance_option) ''
       !
    END SUBROUTINE ssoti_pprint_s
    !==========================================================================================!
       
 
 
 END MODULE param_sparse_oti
!********************************************************************************************************!
!                                          param_sparse_oti
!********************************************************************************************************!