! ============================================================================================!
!> This module includes a sparse implementation of the Order truncated
!! imaginary numbers for FORTRAN.
!!
!! Author: Mauricio Aristizabal Cano, PhD.
!! Initial date:   Oct-19-2023
!! Last modified:  Nov-02-2023
!!
! ============================================================================================!
MODULE static_oti
   ! -----------------------------------------------------------------------------------------!
   USE real_utils
   USE master_parameters
   ! USE otilib_core
   ! -----------------------------------------------------------------------------------------!
   IMPLICIT NONE
   ! -----------------------------------------------------------------------------------------!
   PRIVATE
   ! -----------------------------------------------------------------------------------------!
   INTEGER, PARAMETER, PRIVATE :: ord_t   = 1  ! TODO This should go in a core Module.
   INTEGER, PARAMETER, PRIVATE :: imdir_t = 8
   INTEGER, PARAMETER, PRIVATE :: bases_t = 8
   INTEGER, PARAMETER, PRIVATE :: nnz_t   = 8
   !
   INTEGER(ord_t),   PARAMETER, PRIVATE ::  max_n = 3  !< Max. Imag. order supported.
   INTEGER(bases_t), PARAMETER, PRIVATE ::  max_m = 4  !< Max. num. basis supported.
   INTEGER(imdir_t), PARAMETER, DIMENSION(max_n)   ::  ndir_order = [ 4, 10, 20 ]
   INTEGER(imdir_t), PARAMETER, PRIVATE            ::  max_ndir = 34 !< Max. im. dirs supportd.
   INTEGER(imdir_t), PARAMETER, DIMENSION(max_n+1) ::  ndir_order_cum = [ 1, 5, 15, 35 ]
   ! -----------------------------------------------------------------------------------------!
   TYPE sotinum
     REAL(dp)         :: r               !<- Real coefficient.
     REAL(dp)         :: im(max_ndir)    !<- Imaginary coefficients. (data)
     INTEGER(imdir_t) :: imdir(max_ndir) !<- Imaginary direction indices. (indices)
     INTEGER(nnz_t)   :: nnz(max_n+1)    !<- Actual number of non-zero coefficients per order.
     INTEGER(ord_t)   :: act_ord         !<- Actual order of the number.
     INTEGER(ord_t)   :: order           !<- Truncation order of the number.
   END TYPE sotinum
   ! -----------------------------------------------------------------------------------------!
   INTERFACE pprint
      MODULE PROCEDURE sotinum_pprint_s!, sotinum_pprint_v, sotinum_pprint_m
   END INTERFACE
   PUBLIC pprint

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE sotinum_assign_r ! Real, elemental
      ! sotinum_assign_i ! Integer
   END INTERFACE
   PUBLIC ASSIGNMENT(=)

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE sotinum_add_oo_ss ! Scalar addition OTI - OTI
      MODULE PROCEDURE sotinum_add_ro_ss ! Scalar addition R   - OTI
      MODULE PROCEDURE sotinum_add_or_ss ! Scalar addition OTI - R  
   END INTERFACE
   PUBLIC OPERATOR(+)

   INTERFACE eps
      MODULE PROCEDURE sotinum_epsilon_i     ! Create sotinum from integer 
      ! MODULE PROCEDURE sotinum_epsilon_2i     ! Create sotinum from two integers
      ! MODULE PROCEDURE sotinum_epsilon_imdir ! Create sotinum from imdir
      ! MODULE PROCEDURE sotinum_epsilon_list  ! Create sotinum from list representing IMDIR
   END INTERFACE
   PUBLIC eps
   ! -----------------------------------------------------------------------------------------!

   CONTAINS

   !==========================================================================================!
   !> @brief This function assigns a real number to an OTI number object.
   !! 
   !! res = rhs
   !!
   !! @param[inout] res: otinum structure.
   !! @param[in] rhs: Right hand side of the operation.
   !!
   !******************************************************************************************!
   SUBROUTINE sotinum_assign_r(res,rhs)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      REAL(dp), INTENT(IN) :: rhs
      TYPE(sotinum), INTENT(OUT) :: res
      ! --------------------------------------------------------------------------------------!
      ! Real
      res%r = rhs
      ! No need to initialize imaginary directions. These are controlled by the 
      res%nnz = 0
      res%act_ord = 0
      res%order  = 0
      !
   END SUBROUTINE sotinum_assign_r
   !==========================================================================================!

   !==========================================================================================!
   !>
   !!
   !!
   !******************************************************************************************!
   FUNCTION sotinum_add_oo_ss(lhs,rhs) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      TYPE(sotinum), INTENT(IN) :: lhs
      TYPE(sotinum), INTENT(IN) :: rhs
      TYPE(sotinum)             :: res
      INTEGER(ord_t)   :: i_ord, i_lhs_ord, i_rhs_ord
      INTEGER(imdir_t) :: i_lhs_nnz, i_rhs_nnz
      ! --------------------------------------------------------------------------------------!

      res = zero

      res%act_ord = MAX(lhs%act_ord,rhs%act_ord)
      res%order   = MAX(lhs%order,rhs%order) 
      
      DO i_ord = 1,res%act_ord
         
         IF (i_ord<=rhs%act_ord) THEN
            ! Get number of non-zeros in the number.
            i_nnz = num%nnz(i_ord)
         ELSE 

         END IF 
            
         
         offset      = ndir_order_cum(i_ord)
         next_offset = ndir_order_cum(i_ord+1)-1
         
         ! Get pointers to coefficients to be printed.
         p_im    => num%im(    offset : next_offset )
         p_imdir => num%imdir( offset : next_offset )
         
         ! Loop through the imaginary terms
         DO i_im=1,i_nnz
            
                  
         END DO

      END DO


   END FUNCTION sotinum_add_oo_ss
   !==========================================================================================!

   !==========================================================================================!
   !>
   !!
   !!
   !******************************************************************************************!
   FUNCTION sotinum_epsilon_i(base,order) RESULT (res)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      INTEGER, INTENT(IN) :: base
      INTEGER, INTENT(IN),OPTIONAL :: order
      INTEGER(ord_t)      :: i_ord
      TYPE(sotinum)       :: res
      ! --------------------------------------------------------------------------------------!

      res = zero

      IF ( PRESENT(order) ) THEN
         i_ord = order
      ELSE
         i_ord = 1
      END IF

      IF (base <= max_m) THEN
         
         res%im(1) = one 
         res%imdir(1) = base
         res%nnz(1) = 1
         res%act_ord=1
         res%order=i_ord

      END IF


   END FUNCTION sotinum_epsilon_i
   !==========================================================================================!

   ! !==========================================================================================!
   ! !>
   ! !!
   ! !!
   ! !******************************************************************************************!
   ! FUNCTION sotinum_epsilon_2i(idx,ordin,order) RESULT (res)
   !    ! --------------------------------------------------------------------------------------!
   !    IMPLICIT NONE
   !    ! --------------------------------------------------------------------------------------!
   !    INTEGER, INTENT(IN) :: idx
   !    INTEGER, INTENT(IN) :: ordin
   !    INTEGER, INTENT(IN),OPTIONAL :: order
   !    INTEGER(ord_t)      :: i_ord
   !    INTEGER(imdir_t)    :: i_idx
   !    TYPE(sotinum)       :: res
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
   !       res%order        = i_ord

   !    END IF


   ! END FUNCTION sotinum_epsilon_2i
   ! !==========================================================================================!

   !==========================================================================================!
   !>
   !!
   !!
   !******************************************************************************************!
   SUBROUTINE sotinum_pprint_s(num, fmt, unit, advance)
      ! --------------------------------------------------------------------------------------!
      IMPLICIT NONE
      ! --------------------------------------------------------------------------------------!
      ! Inputs
      TYPE(sotinum), INTENT(IN), TARGET      :: num
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
      INTEGER(imdir_t)                         :: i_nnz
      REAL(dp), POINTER, DIMENSION(:)          :: p_im
      INTEGER(imdir_t), POINTER, DIMENSION(:)  :: p_imdir
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
      
      DO i_ord=1,num%act_ord
         
         ! Get number of non-zeros in the number.
         i_nnz = num%nnz(i_ord)
         
         offset      = ndir_order_cum(i_ord)
         next_offset = ndir_order_cum(i_ord+1)-1
         ! Get pointers to coefficients to be printed.
         p_im    => num%im(    offset : next_offset )
         p_imdir => num%imdir( offset : next_offset )
         
         ! Loop through the imaginary terms
         DO i_im=1,i_nnz
            
            ! Print imaginary coefficient 
            WRITE(unt,'(A)',advance='NO') '+' !<- Adds space.

            CALL pprint( p_im(i_im), unit=unt, fmt=output_format, advance='no')
            
            ! 
            WRITE(unt,'(A)',advance='NO') '*eps(' !<- Adds space.
            
            ! 
            ! CALL pprint( -(p_imdir(i_im),i_ord), unit=unt, fmt=output_format )
            
            WRITE(unt,'(I2,A,I2)',advance='NO') p_imdir(i_im), ',', i_ord
            
            
            WRITE(unt,'(A)',advance='NO') ') ' !<- Adds space.
      
         END DO

      END DO

      WRITE(unt,'(A)',advance=advance_option) ''
      !
   END SUBROUTINE sotinum_pprint_s
   !==========================================================================================!
      


END MODULE static_oti