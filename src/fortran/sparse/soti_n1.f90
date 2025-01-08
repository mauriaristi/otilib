! ============================================================================================!
!> This module defines a sparse implementation of the Order truncated
!! imaginary numbers in Fortran with truncation order 1.
!! 
!! This implementation resembles a dual number with multiple imaginary directions.
!!
!! Author: Mauricio Aristizabal, PhD
!! Last mod date: 9/27/2024
! ============================================================================================!
MODULE sotin1
   ! -----------------------------------------------------------------------------------------!
   USE oti_core
   ! -----------------------------------------------------------------------------------------!
   IMPLICIT NONE
   ! -----------------------------------------------------------------------------------------!
   
   INTEGER, PARAMETER, PRIVATE :: m_max   = 100 ! up-to m_max imag. basis.

   ! INTEGER, PARAMETER, PRIVATE :: ord_t   = 1  ! TODO This should go in a core Module.
   ! INTEGER, PARAMETER, PRIVATE :: bases_t = 8
   ! INTEGER, PARAMETER, PRIVATE :: bases_t = 8 ! TODO: Evaluate if this is better a 4 byte int.

   ! -----------------------------------------------------------------------------------------!
   TYPE sotin1_t(m_max)
      REAL(dp)          :: r               !<- Real coefficient.
      REAL(dp)          :: im(m_max)       !<- Imag. coeffs.
      INTEGER(bases_t)  :: base(m_max)     !<- Imag. dirs. (active, sorted). 
      INTEGER(bases_t)  :: act_bas = 0     !<- Number of active dirs.
      INTEGER(ord_t)    :: act_ord = 0     !<- Actual order. TODO: Should this be per-basis?
      INTEGER(bases_t), LEN :: m_max
   END TYPE sotin1_t
   ! -----------------------------------------------------------------------------------------!
   INTERFACE PPRINT
      MODULE PROCEDURE sotin1_pprint_s!, sotin1_pprint_v, sotin1_pprint_m
   END INTERFACE

   ! INTERFACE PPRINT
   !    MODULE PROCEDURE sotin1_pfullprint_s
   ! END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE sotin1_assign_r, sotin1_assign_i
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE &
         sotin1_add_ro_ss, sotin1_add_or_ss, sotin1_add_oo_ss ! Scalar addition
   END INTERFACE

   INTERFACE OPERATOR(*)
      MODULE PROCEDURE sotin1_mul_ro_ss, sotin1_mul_or_ss, sotin1_mul_oo_ss
   END INTERFACE

   INTERFACE EPS
      MODULE PROCEDURE sotin1_epsilon_i     ! Create sotin1_t from integer 
      ! MODULE PROCEDURE sotin1_epsilon_2i    ! Create sotin1_t from two integers
      ! MODULE PROCEDURE sotin1_epsilon_base ! Create sotin1_t from base
      ! MODULE PROCEDURE sotin1_epsilon_list  ! Create sotin1_t from list representing base
   END INTERFACE

   INTERFACE FEVAL1
      MODULE PROCEDURE sotin1_feval_1var_o_s
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE sotin1_sin_o_s 
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE sotin1_cos_o_s 
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
   SUBROUTINE sotin1_assign_r(res,rhs)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      REAL(dp), INTENT(IN) :: rhs
      TYPE( sotin1_t ), INTENT(OUT) :: res
      ! --------------------------------------------------------------------------------------!
      
      ! Real
      res%r       = rhs
      res%im(:)   = zero ! Initialized for safety.
      res%base(:) = 0    ! Initialized for safety.
            
      ! Actual order and act_bas should be initialized to zero for safety.
      res%act_bas = 0 ! Number of active bases.
      res%act_ord = 0 ! Actual order of this number (per basis?)

      ! ! Truncation order is zero for real numbers
      ! res%trc_ord  = 0 ! Truncation order
      
   END SUBROUTINE sotin1_assign_r
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
   SUBROUTINE sotin1_assign_i(res,rhs)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      INTEGER, INTENT(IN) :: rhs
      TYPE( sotin1_t ), INTENT(OUT) :: res
      ! --------------------------------------------------------------------------------------!
      
      ! Real
      res = REAL(rhs, DP)
      
   END SUBROUTINE sotin1_assign_i
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Add real and sotin1_t 
   !! 
   !! lhs + rhs
   !! 
   !! @param[in] lhs: (real) left hand side operation.
   !! @param[in] rhs: (sotin1_t) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_add_ro_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      REAL(dp), INTENT(IN)         :: lhs
      TYPE( sotin1_t ), INTENT(IN) :: rhs
      TYPE( sotin1_t )             :: res
      ! 
      ! Internal variables
      INTEGER(ord_t) :: i_ord
      INTEGER(bases_t) :: i_im, i
      ! --------------------------------------------------------------------------------------!
      
      ! Add two real numbers. This also initializes memory.
      res = lhs + rhs%r 

      IF (rhs%act_ord>0) THEN
         
         res%act_ord  = rhs%act_ord
         res%act_bas = rhs%act_bas
         
         ! Copy information from rhs to res.
         DO i_ord = 1, rhs%act_ord            
            
            res%im(1:rhs%act_bas) = rhs%im(1:rhs%act_bas)

            res%base(1:rhs%act_bas)   = rhs%base(1:rhs%act_bas)
            
         END DO

      END IF 

   END FUNCTION sotin1_add_ro_ss
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Add  sotin1_t and real
   !! 
   !! lhs + rhs
   !! 
   !! @param[in] lhs: (sotin1_t) left hand side operation.
   !! @param[in] rhs: (real) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_add_or_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE( sotin1_t ), INTENT(IN) :: lhs
      REAL(dp), INTENT(IN)         :: rhs
      TYPE( sotin1_t )             :: res
      ! --------------------------------------------------------------------------------------!
      
      ! Reuse previous implementation.
      res = rhs + lhs

   END FUNCTION sotin1_add_or_ss
   !==========================================================================================!


   !==========================================================================================!
   !> @brief Add real and sotin1_t 
   !! 
   !! lhs + rhs
   !! 
   !! @param[in] lhs: (real) left hand side operation.
   !! @param[in] rhs: (sotin1_t) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_add_oo_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE( sotin1_t ), INTENT(IN) :: lhs
      TYPE( sotin1_t ), INTENT(IN) :: rhs
      TYPE( sotin1_t )             :: res
      ! 
      ! Internal variables
      INTEGER(ord_t)  :: i_ord
      INTEGER(bases_t) :: i_im, i_lhs, i_rhs, i_res
      INTEGER(bases_t) :: n_active
      ! --------------------------------------------------------------------------------------!
      
      res = lhs%r + rhs%r  ! This initializes res.

      IF ( (rhs%act_ord>0) .and. (lhs%act_ord>0) ) THEN
         
         res%act_ord  = MAX(rhs%act_ord,lhs%act_ord)
         res%act_bas = 0

         ! Start at first location of both operators.
         i_lhs = 1 !
         i_rhs = 1 !
         i_res = 1 !
         ! Add up Copy information from rhs to res.
         DO 
            ! This is like a do while loop.
            IF (i_lhs>lhs%act_bas .and. i_rhs>rhs%act_bas)  exit

            IF (i_lhs>lhs%act_bas) THEN ! Prevent overflow rhs
               ! Only add the rhs.
               res%im( i_res ) = rhs%im( i_rhs )
               res%base(   i_res ) = rhs%base(   i_rhs )
               i_rhs = i_rhs + 1
            ELSE IF (i_rhs>rhs%act_bas) THEN ! Prevent overflow lhs
               ! Only add the lhs.
               res%im( i_res ) = lhs%im( i_lhs )
               res%base(   i_res ) = lhs%base(   i_lhs )
               i_lhs = i_lhs + 1
            ELSE ! Both lhs and rhs have something to evaluate.
               IF (rhs%base(i_rhs)==lhs%base(i_lhs)) THEN ! Same bases.
                  res%im(i_res) = rhs%im(i_rhs)+lhs%im(i_lhs)
                  res%base(i_res)   = rhs%base(i_rhs)
                  i_lhs = i_lhs + 1
                  i_rhs = i_rhs + 1
               ELSE IF (rhs%base(i_rhs) < lhs%base(i_lhs)) THEN ! Lower base rhs
                  res%im(i_res) = rhs%im(i_rhs)
                  res%base(i_res)   = rhs%base(i_rhs)
                  i_rhs = i_rhs + 1
               ELSE  ! Lower base lhs
                  res%im(i_res) = lhs%im(i_lhs)
                  res%base(i_res)   = lhs%base(i_lhs)
                  i_lhs = i_lhs + 1
               END IF 

            END IF

            res%act_bas  = res%act_bas + 1
            i_res = i_res + 1

         END DO

      ELSE IF(rhs%act_ord==0) THEN
         
         res = rhs%r  + lhs 

      ELSE  ! lhs%act_ord==0
         
         res = lhs%r  + rhs

      END IF 

   END FUNCTION sotin1_add_oo_ss
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Multiply real and sotin1_t 
   !! 
   !! lhs * rhs
   !! 
   !! @param[in] lhs: (real) left hand side operation.
   !! @param[in] rhs: (sotin1_t) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_mul_ro_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      REAL(dp), INTENT(IN)       :: lhs
      TYPE(sotin1_t), INTENT(IN) :: rhs
      TYPE(sotin1_t)             :: res
      INTEGER(ord_t) :: i_ord
      INTEGER(bases_t) :: i_im

      ! --------------------------------------------------------------------------------------!
      
      ! Add two real numbers. This also deallocates memory.
      res = lhs * rhs%r 

      IF (rhs%act_ord>0) THEN
         
         res%act_ord = rhs%act_ord
         res%act_bas = rhs%act_bas
         
         ! Copy information from rhs to res.
         DO i_im = 1, rhs%act_bas
         
            res%im(i_im) = lhs*rhs%im(i_im)
            res%base( i_im)  = rhs%base( i_im)

         END DO

      END IF 

   END FUNCTION sotin1_mul_ro_ss
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Multiply sotin1_t and sotin1_t 
   !! 
   !! lhs * rhs
   !! 
   !! @param[in] lhs: (sotin1_t) left hand side operation.
   !! @param[in] rhs: (sotin1_t) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_mul_oo_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN)       :: lhs
      TYPE(sotin1_t), INTENT(IN) :: rhs
      TYPE(sotin1_t)             :: res
      
      INTEGER(bases_t) :: i_res, i_rhs, i_lhs

      ! --------------------------------------------------------------------------------------!
      
      IF ( (rhs%act_ord>0) .and. (lhs%act_ord>0) ) THEN
         
         res%r = lhs%r * rhs%r  ! This initializes res.

         res%act_ord  = MAX(rhs%act_ord,lhs%act_ord)
         res%act_bas = 0

         ! Start at first location of both operators.
         i_lhs = 1 !
         i_rhs = 1 !
         i_res = 1 !
         ! Multiply real x bases and add up
         DO 
            ! This is like a do while loop.
            IF (i_lhs>lhs%act_bas .and. i_rhs>rhs%act_bas)  exit

            IF (i_lhs>lhs%act_bas) THEN ! Prevent overflow rhs
               ! Only add the rhs.
               res%im( i_res ) = lhs%r * rhs%im( i_rhs )
               res%base(   i_res ) = rhs%base(   i_rhs )
               i_rhs = i_rhs + 1
            ELSE IF (i_rhs>rhs%act_bas) THEN ! Prevent overflow lhs
               ! Only add the lhs.
               res%im( i_res ) = rhs%r * lhs%im( i_lhs )
               res%base(   i_res ) = lhs%base(   i_lhs )
               i_lhs = i_lhs + 1
            ELSE ! Both lhs and rhs have something to evaluate.
               IF (rhs%base(i_rhs)==lhs%base(i_lhs)) THEN ! Same bases.
                  res%im(i_res) = lhs%r * rhs%im(i_rhs) + rhs%r * lhs%im(i_lhs)
                  res%base(i_res)   = rhs%base(i_rhs)
                  i_lhs = i_lhs + 1
                  i_rhs = i_rhs + 1
               ELSE IF (rhs%base(i_rhs) < lhs%base(i_lhs)) THEN ! Lower base rhs
                  res%im(i_res) = lhs%r*rhs%im(i_rhs)
                  res%base(i_res)   =       rhs%base(  i_rhs)
                  i_rhs = i_rhs + 1
               ELSE  ! Lower base lhs
                  res%im(i_res) = rhs%r*lhs%im(i_lhs)
                  res%base(i_res)   =       lhs%base(  i_lhs)
                  i_lhs = i_lhs + 1
               END IF 

            END IF

            ! TODO: Need a lower level function that handles this multiplication. 
            ! This can be done quite quickly for both cases. 
            res%act_bas  = res%act_bas + 1
            i_res = i_res + 1

         END DO

      ELSE IF(rhs%act_ord==0) THEN
         
         res = rhs%r  + lhs 

      ELSE  ! lhs%act_ord==0
         
         res = lhs%r  + rhs

      END IF 

   END FUNCTION sotin1_mul_oo_ss
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Multiply  sotin1_t and real
   !! 
   !! lhs * rhs
   !! 
   !! @param[in] lhs: (sotin1_t) left hand side operation.
   !! @param[in] rhs: (real) right hand side operation.
   !******************************************************************************************!
   FUNCTION sotin1_mul_or_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! -------- INPUTS OUTPUTS --------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN) :: lhs
      REAL(dp), INTENT(IN)       :: rhs
      TYPE(sotin1_t)             :: res
      ! --------------------------------------------------------------------------------------!
      INTEGER(ord_t)  :: i_ord
      INTEGER(bases_t) :: i_im
      ! --------------------------------------------------------------------------------------!
      
      ! multiply real - oti
      res = rhs * lhs

   END FUNCTION sotin1_mul_or_ss
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Evaluate OTI function (single-variable) at given OTI point.
   !! 
   !! func(val)
   !! 
   !! @param[in] func: (sotin1_t) Value to evaluate the function (OTI).
   !! @param[in] val: (sotin1_t) Value to evaluate the function (OTI).
   !******************************************************************************************!
   FUNCTION sotin1_feval_1var_o_s(func, val) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN) :: func
      TYPE(sotin1_t), INTENT(IN) :: val
      TYPE(sotin1_t)             :: res      
      ! --------------------------------------------------------------------------------------!
      INTEGER(bases_t) :: i_im, i_ord
      ! --------------------------------------------------------------------------------------!
      
      ! Considerations. This considers single variable evaluation.
      !
      ! 1. initialize with the real value.
      res  = func%r
      
      res%act_ord = val%act_ord

      ! 2. Loop through order
      DO  i_ord=1,func%act_ord
         
         ! Assume the first base is the only one to be evaluated. Loop through bases 
         ! preparing for higher orders: +-
         res%im(:val%act_bas)   = func%im(i_ord) * val%im(:val%act_bas)
         res%base(:val%act_bas) = val%base(:val%act_bas)
         res%act_bas = val%act_bas

      END DO


   END FUNCTION sotin1_feval_1var_o_s
   !==========================================================================================!

   ! !==========================================================================================!
   ! !> @brief Evaluate single variable function at sotin1_t
   ! !! 
   ! !! f(val)
   ! !! 
   ! !! @param[in] val: (sotin1_t) Value to evaluate the function (OTI).
   ! !! @param[in] rhs: (sotin1_t) right hand side operation.
   ! !******************************************************************************************!
   ! FUNCTION sotin1_feval_o_s(val,fevald) RESULT (res)
   !    ! --------------------------------------------------------------------------------------!
   !    IMPLICIT NONE
   !    ! --------------------------------------------------------------------------------------!
   !    TYPE(sotin1_t), INTENT(IN) :: val
   !    TYPE(sotin1_t), INTENT(IN) :: fevald
   !    TYPE(sotin1_t)             :: res      
   !    ! --------------------------------------------------------------------------------------!
   !    INTEGER(bases_t) :: i_res, i_val
   !    ! --------------------------------------------------------------------------------------!
            
   ! END FUNCTION sotin1_feval_o_s
   ! !==========================================================================================!



   

   !==========================================================================================!
   !> @brief Evaluate cosine function at oti number.
   !! 
   !! res = cos(x)
   !! 
   !! @param[in] x: (sotin1_t) Value to evaluate the function (OTI).
   !******************************************************************************************!
   FUNCTION sotin1_cos_o_s(x) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN) :: x
      TYPE(sotin1_t)             :: func
      TYPE(sotin1_t)             :: res      
      ! --------------------------------------------------------------------------------------!
      INTEGER(bases_t) :: i_res, i_val
      ! --------------------------------------------------------------------------------------!
      
      ! Evaluate function for cosine
      ! known
      func%r       = cos(x%r)
      func%im(1)   = -sin(x%r)
      func%base(1) = 1
      func%act_ord = 1
      func%act_bas = 1

      res = FEVAL1(func,x)

   END FUNCTION sotin1_cos_o_s
   !==========================================================================================!
   
   !==========================================================================================!
   !> @brief Evaluate hyperbolic cosine function at oti number.
   !! 
   !! res = cosh(x)
   !! 
   !! @param[in] x: (sotin1_t) Value to evaluate the function (OTI).
   !******************************************************************************************!
   FUNCTION sotin1_cosh_o_s(x) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN) :: x
      TYPE(sotin1_t)             :: func
      TYPE(sotin1_t)             :: res      
      ! --------------------------------------------------------------------------------------!
      INTEGER(bases_t) :: i_res, i_val
      ! --------------------------------------------------------------------------------------!
      
      ! Evaluate function for cosine
      ! known
      func%r       = cosh(x%r)
      func%im(1)   = sinh(x%r)
      func%base(1) = 1
      func%act_ord = 1
      func%act_bas = 1

      res = FEVAL1(func,x)

   END FUNCTION sotin1_cosh_o_s
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Evaluate exponential function at oti number.
   !! 
   !! res = exp(x)
   !! 
   !! @param[in] x: (sotin1_t) Value to evaluate the function (OTI).
   !******************************************************************************************!
   FUNCTION sotin1_exp_o_s(x) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN) :: x
      TYPE(sotin1_t)             :: func
      TYPE(sotin1_t)             :: res      
      ! --------------------------------------------------------------------------------------!
      INTEGER(bases_t) :: i_res, i_val
      ! --------------------------------------------------------------------------------------!
      
      ! Evaluate function
      func%r       = exp(x%r)
      func%im(1)   = func%r
      func%base(1) = 1
      func%act_ord = 1
      func%act_bas = 1

      res = FEVAL1(func,x)

   END FUNCTION sotin1_exp_o_s
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Evaluate natural logarithm function at oti number.
   !! 
   !! res = log(x)
   !! 
   !! @param[in] x: (sotin1_t) Value to evaluate the function (OTI).
   !******************************************************************************************!
   FUNCTION sotin1_log_o_s(x) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN) :: x
      TYPE(sotin1_t)             :: func
      TYPE(sotin1_t)             :: res      
      ! --------------------------------------------------------------------------------------!
      INTEGER(bases_t) :: i_res, i_val
      ! --------------------------------------------------------------------------------------!
      
      ! Evaluate function
      func%r       = log(x%r)
      func%im(1)   = one/x%r
      func%base(1) = 1
      func%act_ord = 1
      func%act_bas = 1

      res = FEVAL1(func,x)

   END FUNCTION sotin1_log_o_s
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Evaluate sine function at oti number.
   !! 
   !! res = sin(x)
   !! 
   !! @param[in] x: (sotin1_t) Value to evaluate the function (OTI).
   !******************************************************************************************!
   FUNCTION sotin1_sin_o_s(x) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN) :: x
      TYPE(sotin1_t)             :: func
      TYPE(sotin1_t)             :: res      
      ! --------------------------------------------------------------------------------------!
      INTEGER(bases_t) :: i_res, i_val
      ! --------------------------------------------------------------------------------------!
      
      ! Evaluate function for sine
      ! known
      func%r = sin(x%r)
      func%im(1) = cos(x%r)
      func%base(1) = 1
      func%act_ord = 1
      func%act_bas = 1

      res = FEVAL1(func,x)

   END FUNCTION sotin1_sin_o_s
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Evaluate hyperbolic sine function at oti number.
   !! 
   !! res = sinh(x)
   !! 
   !! @param[in] x: (sotin1_t) Value to evaluate the function (OTI).
   !******************************************************************************************!
   FUNCTION sotin1_sinh_o_s(x) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN) :: x
      TYPE(sotin1_t)             :: func
      TYPE(sotin1_t)             :: res      
      ! --------------------------------------------------------------------------------------!
      INTEGER(bases_t) :: i_res, i_val
      ! --------------------------------------------------------------------------------------!
      
      ! Evaluate function for sine
      ! known
      func%r       = sinh(x%r)
      func%im(1)   = cosh(x%r)
      func%base(1) = 1
      func%act_ord = 1
      func%act_bas = 1

      res = FEVAL1(func,x)

   END FUNCTION sotin1_sinh_o_s
   !==========================================================================================!

   !==========================================================================================!
   !> @brief Evaluate tangent function at oti number.
   !! 
   !! res = tan(x)
   !! 
   !! @param[in] x: (sotin1_t) Value to evaluate the function (OTI).
   !******************************************************************************************!
   FUNCTION sotin1_tan_o_s(x) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotin1_t), INTENT(IN) :: x
      TYPE(sotin1_t)             :: func
      TYPE(sotin1_t)             :: res      
      ! --------------------------------------------------------------------------------------!
      INTEGER(bases_t) :: i_res, i_val
      REAL(dp) :: x_tmp
      ! --------------------------------------------------------------------------------------!
      
      ! Evaluate function
      func%r = tan(x%r)

      ! The following depends on truncation order.
      x_tmp = cos(x%r)
      func%im(1)   = one/(x_tmp*x_tmp)
      func%base(1) = 1
      func%act_ord = 1
      func%act_bas = 1

      res = FEVAL1(func,x)

   END FUNCTION sotin1_tan_o_s
   !==========================================================================================!

   ! !==========================================================================================!
   ! !> @brief Evaluate natural logarithm function at oti number.
   ! !! 
   ! !! res = log(x)
   ! !! 
   ! !! @param[in] x: (sotin1_t) Value to evaluate the function (OTI).
   ! !******************************************************************************************!
   ! FUNCTION sotin1_log_o_s(x) RESULT (res)
   !    ! --------------------------------------------------------------------------------------!
   !    IMPLICIT NONE
   !    ! --------------------------------------------------------------------------------------!
   !    TYPE(sotin1_t), INTENT(IN) :: x
   !    TYPE(sotin1_t)             :: func
   !    TYPE(sotin1_t)             :: res      
   !    ! --------------------------------------------------------------------------------------!
   !    INTEGER(bases_t) :: i_res, i_val
   !    ! --------------------------------------------------------------------------------------!
      
   !    ! Evaluate function
   !    func%r       = log(x%r)
   !    func%im(1)   = one/x%r
   !    func%base(1) = 1
   !    func%act_ord = 1
   !    func%act_bas = 1

   !    res = FEVAL1(func,x)

   ! END FUNCTION sotin1_log_o_s
   ! !==========================================================================================!















   !==========================================================================================!
   !> @brief This function only creates imaginary directions with integer parameters.
   !!        of actual order 1.
   !!
   !! @param[in] base: Imaginary base to be created.
   !! @param[in] order(optional): Truncation order to be set to the number. Default 1.
   !!
   !******************************************************************************************!
   FUNCTION sotin1_epsilon_i(base,order) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      INTEGER, INTENT(IN)          :: base
      INTEGER, INTENT(IN),OPTIONAL :: order
      INTEGER(ord_t)               :: i_ord
      TYPE(sotin1_t)               :: res
      ! --------------------------------------------------------------------------------------!

      ! Create number as a zero. It also Deallocates memory.
      res = zero

      IF ( PRESENT(order) ) THEN
         i_ord = order
      ELSE
         i_ord = 1
      END IF
      
      ! Set truncation order to the one given.
      ! res%order=i_ord

      IF (i_ord == 0) THEN
         res = one
      ELSE
         ! Only if imaginary basis supported, allocate memory. See how to update this.
         IF (base <= m_max) THEN
            
            res%im(1)   = one   
            res%base(1) = base  
            res%act_ord = i_ord 
            res%act_bas = 1
            
         ELSE
            
            ! RAISE Warning that the number of imaginary direction is not supported 
            ! in this occation.
            PRINT*, "WARNING: Cant create OTI number with t" 

         END IF

      END IF

   END FUNCTION sotin1_epsilon_i
   !==========================================================================================!

   !==========================================================================================!
   !> @brief This function only activates a set of imaginary directions given an integer list.
   !!
   !! @param[in] base: (int, array) Array of imaginary bases to be created.
   !! @param[in] order(optional): Truncation order to be set to the number. Default 1.
   !!
   !******************************************************************************************!
   FUNCTION sotin1_epsilon_il(base,order) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      INTEGER, INTENT(IN)          :: base(:)
      INTEGER, INTENT(IN),OPTIONAL :: order
      INTEGER(ord_t)               :: i_ord
      INTEGER                      :: i
      INTEGER(bases_t)             :: basei
      TYPE(sotin1_t)               :: res
      ! --------------------------------------------------------------------------------------!

      ! Create number as a zero. It also Deallocates memory.
      res = zero

      IF ( PRESENT(order) ) THEN
         i_ord = order
      ELSE
         i_ord = 1
      END IF
      
      ! Set truncation order to the one given.
      ! res%order=i_ord

      IF (i_ord == 0) THEN
         res = one
      ELSE
         DO i=1,SIZE(base)
            ! Only if imaginary basis supported, allocate memory. See how to update this.
            basei = base(i)
            IF (basei <= m_max) THEN
               
               res%im(i) = one   
               res%base(i)   = basei
               res%act_ord    = i_ord 
               res%act_bas   = res%act_bas + 1
               
            ELSE
               ! RAISE Warning that the number of imaginary direction is not supported 
               ! in this occation.
               PRINT*, "WARNING: Cant create OTI number with base ", basei 
            END IF
         END DO

      END IF

   END FUNCTION sotin1_epsilon_il
   !==========================================================================================!

   ! ! !==========================================================================================!
   ! ! !>
   ! ! !!
   ! ! !!
   ! ! !******************************************************************************************!
   ! ! FUNCTION sotin1_epsilon_2i(idx,ordin,order) RESULT (res)
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    IMPLICIT NONE
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    INTEGER, INTENT(IN) :: idx
   ! !    INTEGER, INTENT(IN) :: ordin
   ! !    INTEGER, INTENT(IN),OPTIONAL :: order
   ! !    INTEGER(ord_t)      :: i_ord
   ! !    INTEGER(bases_t)    :: i_idx
   ! !    TYPE(sotin1_t)       :: res
   ! !    ! --------------------------------------------------------------------------------------!

   ! !    res = zero
   ! !    i_ord = ordin
      
   ! !    IF ( PRESENT(order) ) THEN
   ! !       i_ord = MIN(MAX(order,ordin),max_n)
   ! !    END IF

   ! !    IF (idx <= ndir_order(ordin) .and. ordin <= max_n ) THEN

   ! !       i_idx = ndir_order_cum(ordin)

   ! !       res%im(i_idx)    = one 
   ! !       res%base(i_idx) = idx
   ! !       res%nnz(ordin)   = 1
   ! !       res%act_ord      = ordin
   ! !       res%order        = i_ord

   ! !    END IF


   ! ! END FUNCTION sotin1_epsilon_2i
   ! ! !==========================================================================================!



   ! ! ! sotin1_pfullprint_s
   ! ! !==========================================================================================!
   ! ! !> @ brief This function prints in a human friendly manner a sotin1_t object.
   ! ! !! 
   ! ! !! @param[in] num: sotin1_t object to be printed.
   ! ! !! @param[in] fmt(optional): Format of the real coefficients to be printed. Default: 'F10.4'
   ! ! !! @param[in] unit(optional): Unit to print. Default 6.
   ! ! !! @param[in] advance(optional): if 'YES', advance to next line, otherwise sets . Default 'YES'.
   ! ! !!
   ! ! !******************************************************************************************!
   ! ! SUBROUTINE sotin1_pfullprint_s(num, fmt, unit, advance)
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    IMPLICIT NONE
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    ! Inputs
   ! !    TYPE(sotin1_t), INTENT(IN), TARGET      :: num
   ! !    CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
   ! !    CHARACTER(len=*), INTENT(IN), OPTIONAL :: advance
   ! !    INTEGER, INTENT(IN), OPTIONAL          :: unit
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    ! Local Defs.
   ! !    CHARACTER(len=:),ALLOCATABLE             :: output_format
   ! !    CHARACTER(len=:),ALLOCATABLE             :: advance_option
   ! !    INTEGER                                  :: unt
   ! !    INTEGER(ord_t)                           :: i_ord
   ! !    INTEGER(bases_t)                         :: i_im
   ! !    INTEGER                                  :: offset, next_offset
   ! !    ! --------------------------------------------------------------------------------------!
   ! !    IF ( PRESENT(unit) ) THEN
   ! !       unt = unit
   ! !    ELSE
   ! !       unt = 6
   ! !    END IF

   ! !    IF ( PRESENT(fmt) ) THEN
   ! !       output_format = '('//trim(fmt)//')'
   ! !    ELSE
   ! !       output_format = '(F10.4)'
   ! !    END IF

   ! !    IF (PRESENT(advance)) THEN
   ! !       advance_option = trim(advance)
   ! !    ELSE
   ! !       advance_option = 'YES'
   ! !    END IF      

   ! !    ! Print real part.
   ! !    CALL pprint(num%r,unit=unt,fmt=output_format,advance='no')
   ! !    WRITE(unt,'(A)',advance='NO') ' ' !<- Adds space.

   ! !    ! Print imaginary coefficients.
   ! !    DO i_ord = 1, num%act_ord
         
   ! !       ! Loop through the imaginary terms
   ! !       DO i_im=num%nnz(i_ord),num%nnz(i_ord+1)
            
   ! !          ! Print imaginary coefficient 
   ! !          WRITE(unt,'(A)',advance='NO') '+ ' 

   ! !          CALL pprint( num%imcoef(i_im), unit=unt, fmt=output_format, advance='no')
             
   ! !          WRITE(unt,'(A)',advance='NO') '*eps(' 
   ! !          WRITE(unt,'(I2,A,I2)',advance='NO') num%base(i_im), ',', i_ord
   ! !          WRITE(unt,'(A)',advance='NO') ') '    !<- Adds space.
      
   ! !       END DO

   ! !    END DO

   ! !    WRITE(unt,'(A)',advance=advance_option) ''
   ! !    !
   ! ! END SUBROUTINE sotin1_pfullprint_s
   ! ! !==========================================================================================!


   !==========================================================================================!
   !> @brief This function prints in a human friendly manner a sotin1_t object.
   !! 
   !! @param[in] num: sotin1_t object to be printed.
   !! @param[in] fmt(optional): Format of the real coefficients to be printed. Default: 'F10.4'
   !! @param[in] unit(optional): Unit to print. Default 6.
   !! @param[in] advance(optional): if 'YES', advance to next line, otherwise sets . Default 'YES'.
   !!
   !******************************************************************************************!
   SUBROUTINE sotin1_pprint_s(num, fmt, unit, advance)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      ! Inputs
      TYPE(sotin1_t), INTENT(IN), TARGET      :: num
      CHARACTER(len=*), INTENT(IN), OPTIONAL  :: fmt
      CHARACTER(len=*), INTENT(IN), OPTIONAL  :: advance
      INTEGER, INTENT(IN), OPTIONAL           :: unit
      ! --------------------------------------------------------------------------------------!
      ! Local Defs.
      CHARACTER(len=:),ALLOCATABLE             :: output_format
      CHARACTER(len=:),ALLOCATABLE             :: advance_option
      INTEGER                                  :: unt
      INTEGER(ord_t)                           :: i_ord
      INTEGER(bases_t)                         :: i_im
      INTEGER                                  :: offset, next_offset
      ! --------------------------------------------------------------------------------------!
         
      ! I assume it will be faster to write to a buffer instead of screen right away.
      ! TODO: Change this to write directly to a buffer then print off to screen.

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
      DO i_ord = 1, num%act_ord
         
         ! Loop through the imaginary terms
         DO i_im=1,num%act_bas
            
            ! Print imaginary coefficient 
            WRITE(unt,'(A)',advance='NO') '+ ' !<- Adds space.

            CALL pprint( num%im(i_im), unit=unt, fmt=output_format, advance='no')
             
            WRITE(unt,'(A)',advance='NO') ' * eps(' 
            WRITE(unt,'(I4)',advance='NO') num%base(i_im)
            WRITE(unt,'(A)',advance='NO') ') '    !<- Adds space.
      
         END DO

      END DO

      WRITE(unt,'(A)',advance=advance_option) ''
      !
   END SUBROUTINE sotin1_pprint_s
   !==========================================================================================!
      


END MODULE sotin1