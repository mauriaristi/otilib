  ! SUBROUTINE {type_name}_PPRINT_M_R(X, FMT)
  !     IMPLICIT NONE
  !     REAL(DP),INTENT(IN) :: X(:,:)
  !     INTEGER :: I, J
  !     CHARACTER(*),INTENT(IN),OPTIONAL :: FMT
  !     CHARACTER(:),ALLOCATABLE :: out_fmt
      
  !     IF (PRESENT(fmt)) THEN
  !       out_fmt = fmt
  !     ELSE
  !       out_fmt = 'F10.4'
  !     END IF
      
  !     write(*,'(A)',advance='no') "["
      
  !     DO I=1,SIZE(X,1)
        
  !       IF (I == 1) THEN
  !         write(*,'(A)',advance='no') "["
  !       ELSE
  !         write(*,'(A)',advance='no') " ["
  !       END IF 

  !       DO J=1,SIZE(X,2)
          
  !         write(*,'('//trim(out_fmt)//')',advance='no') X(I,J)

  !       END DO
        
  !       write(*,'(A)') "]"
      
  !     END DO

  !     write(*,'(A)') "]"

  ! END SUBROUTINE {type_name}_PPRINT_M_R

  ! SUBROUTINE {type_name}_PPRINT_V_R(X, FMT)
  !     IMPLICIT NONE
  !     REAL(DP),INTENT(IN) :: X(:)
  !     INTEGER :: I
  !     CHARACTER(*),INTENT(IN),OPTIONAL :: FMT
  !     CHARACTER(:),ALLOCATABLE :: out_fmt
      
  !     IF (PRESENT(fmt)) THEN
  !       out_fmt = fmt
  !     ELSE
  !       out_fmt = 'F10.4'
  !     END IF
      
  !     write(*,'(A)',advance='no') "["
      
  !     DO I=1,SIZE(X,1)

  !       write(*,'('//trim(out_fmt)//')',advance='no') X(I)

  !     END DO

  !     write(*,'(A)') "]"

  ! END SUBROUTINE {type_name}_PPRINT_V_R

  ! !***************************************************************************************************! 
  ! !> @brief 2 x 2  matrix inversion.
  ! !!
  ! !! Taken from https://fortranwiki.org/fortran/show/Matrix+inversion
  ! !!
  ! !! @param[in] A: Matrix to be printed.
  ! !! @param[out] B: inverse of A.
  ! !!
  ! !***************************************************************************************************!
  ! PURE FUNCTION Rmatinv2x2(A,det) RESULT(B)

  !   IMPLICIT NONE

  !   REAL(dp), INTENT(IN) :: A(2,2)   !! Matrix
  !   REAL(dp), INTENT(IN), OPTIONAL :: det
  !   REAL(dp)             :: B(2,2)   !! Inverse matrix
  !   REAL(dp)             :: detinv

  !   IF ( PRESENT(det) ) THEN
  !     detinv = 1.0d0 / det
  !   ELSE
  !     ! Calculate the inverse determinant of the matrix
  !     detinv = 1.0d0 / det2x2(A)
  !   END IF

  !   ! Calculate the inverse of the matrix
  !   B(1,1) =  detinv * A(2,2)
  !   B(2,1) = -detinv * A(2,1)
  !   B(1,2) = -detinv * A(1,2)
  !   B(2,2) =  detinv * A(1,1)
  ! END FUNCTION
  ! !===================================================================================================! 
  
  ! !***************************************************************************************************! 
  ! !> @brief 3 x 3  matrix inversion.
  ! !!
  ! !! Taken from https://fortranwiki.org/fortran/show/Matrix+inversion
  ! !!
  ! !! @param[in]  A: Matrix to be printed.
  ! !! @param[out] B: inverse of A.
  ! !!
  ! !***************************************************************************************************!
  ! PURE FUNCTION Rmatinv3x3(A,det) RESULT(B)
      
  !     IMPLICIT NONE

  !     REAL(dp), INTENT(IN) :: A(3,3)   !! Matrix
  !     REAL(dp), INTENT(IN), OPTIONAL :: det
  !     REAL(dp)             :: B(3,3)   !! Inverse matrix
  !     REAL(dp)             :: detinv

  !     IF ( PRESENT(det) ) THEN
  !        detinv = 1.0d0/det
  !     ELSE
  !        ! Calculate the inverse determinant of the matrix
  !        detinv = 1.0d0/det3x3(A)
  !     END IF 

  !     ! Calculate the inverse of the matrix
  !     B(1,1) = + detinv * (A(2,2)*A(3,3) - A(2,3)*A(3,2))
  !     B(2,1) = - detinv * (A(2,1)*A(3,3) - A(2,3)*A(3,1))
  !     B(3,1) = + detinv * (A(2,1)*A(3,2) - A(2,2)*A(3,1))
  !     B(1,2) = - detinv * (A(1,2)*A(3,3) - A(1,3)*A(3,2))
  !     B(2,2) = + detinv * (A(1,1)*A(3,3) - A(1,3)*A(3,1))
  !     B(3,2) = - detinv * (A(1,1)*A(3,2) - A(1,2)*A(3,1))
  !     B(1,3) = + detinv * (A(1,2)*A(2,3) - A(1,3)*A(2,2))
  !     B(2,3) = - detinv * (A(1,1)*A(2,3) - A(1,3)*A(2,1))
  !     B(3,3) = + detinv * (A(1,1)*A(2,2) - A(1,2)*A(2,1))

  !  END FUNCTION
  !  !===================================================================================================! 

  !  !***************************************************************************************************! 
  !  !> @brief 4 x 4  matrix inversion.
  !  !!
  !  !! Taken from https://fortranwiki.org/fortran/show/Matrix+inversion
  !  !!
  !  !! @param[in]  A: Matrix to be printed.
  !  !! @param[in]  det: (optional) Determinant of A.
  !  !! @param[out] B: inverse of A.
  !  !!
  !  !***************************************************************************************************!
  !  PURE FUNCTION Rmatinv4x4(A,det) RESULT(B)
      
  !     IMPLICIT NONE

  !     REAL(dp), INTENT(IN) :: A(4,4)   !! Matrix
  !     REAL(dp), INTENT(IN), OPTIONAL :: det
  !     REAL(dp)             :: B(4,4)   !! Inverse matrix
  !     REAL(dp)             :: di  !! Determinant inverse

  !     ! Calculate the inverse determinant of the matrix
  !     IF ( PRESENT(det) ) THEN
  !        di = 1.0d0/det
  !     ELSE
  !        di = 1.0d0/det4x4(A)
  !     END IF 
      
  !     ! Calculate the inverse of the matrix
  !     B(1,1) = di*(A(2,2)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(2,3)*(A(3,4)*A(4,2)-A(3,2)*A(4,4))+A(2,4)*(A(3,2)*A(4,3)-A(3,3)*A(4,2)))
  !     B(2,1) = di*(A(2,1)*(A(3,4)*A(4,3)-A(3,3)*A(4,4))+A(2,3)*(A(3,1)*A(4,4)-A(3,4)*A(4,1))+A(2,4)*(A(3,3)*A(4,1)-A(3,1)*A(4,3)))
  !     B(3,1) = di*(A(2,1)*(A(3,2)*A(4,4)-A(3,4)*A(4,2))+A(2,2)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(2,4)*(A(3,1)*A(4,2)-A(3,2)*A(4,1)))
  !     B(4,1) = di*(A(2,1)*(A(3,3)*A(4,2)-A(3,2)*A(4,3))+A(2,2)*(A(3,1)*A(4,3)-A(3,3)*A(4,1))+A(2,3)*(A(3,2)*A(4,1)-A(3,1)*A(4,2)))
  !     B(1,2) = di*(A(1,2)*(A(3,4)*A(4,3)-A(3,3)*A(4,4))+A(1,3)*(A(3,2)*A(4,4)-A(3,4)*A(4,2))+A(1,4)*(A(3,3)*A(4,2)-A(3,2)*A(4,3)))
  !     B(2,2) = di*(A(1,1)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(1,3)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(1,4)*(A(3,1)*A(4,3)-A(3,3)*A(4,1)))
  !     B(3,2) = di*(A(1,1)*(A(3,4)*A(4,2)-A(3,2)*A(4,4))+A(1,2)*(A(3,1)*A(4,4)-A(3,4)*A(4,1))+A(1,4)*(A(3,2)*A(4,1)-A(3,1)*A(4,2)))
  !     B(4,2) = di*(A(1,1)*(A(3,2)*A(4,3)-A(3,3)*A(4,2))+A(1,2)*(A(3,3)*A(4,1)-A(3,1)*A(4,3))+A(1,3)*(A(3,1)*A(4,2)-A(3,2)*A(4,1)))
  !     B(1,3) = di*(A(1,2)*(A(2,3)*A(4,4)-A(2,4)*A(4,3))+A(1,3)*(A(2,4)*A(4,2)-A(2,2)*A(4,4))+A(1,4)*(A(2,2)*A(4,3)-A(2,3)*A(4,2)))
  !     B(2,3) = di*(A(1,1)*(A(2,4)*A(4,3)-A(2,3)*A(4,4))+A(1,3)*(A(2,1)*A(4,4)-A(2,4)*A(4,1))+A(1,4)*(A(2,3)*A(4,1)-A(2,1)*A(4,3)))
  !     B(3,3) = di*(A(1,1)*(A(2,2)*A(4,4)-A(2,4)*A(4,2))+A(1,2)*(A(2,4)*A(4,1)-A(2,1)*A(4,4))+A(1,4)*(A(2,1)*A(4,2)-A(2,2)*A(4,1)))
  !     B(4,3) = di*(A(1,1)*(A(2,3)*A(4,2)-A(2,2)*A(4,3))+A(1,2)*(A(2,1)*A(4,3)-A(2,3)*A(4,1))+A(1,3)*(A(2,2)*A(4,1)-A(2,1)*A(4,2)))
  !     B(1,4) = di*(A(1,2)*(A(2,4)*A(3,3)-A(2,3)*A(3,4))+A(1,3)*(A(2,2)*A(3,4)-A(2,4)*A(3,2))+A(1,4)*(A(2,3)*A(3,2)-A(2,2)*A(3,3)))
  !     B(2,4) = di*(A(1,1)*(A(2,3)*A(3,4)-A(2,4)*A(3,3))+A(1,3)*(A(2,4)*A(3,1)-A(2,1)*A(3,4))+A(1,4)*(A(2,1)*A(3,3)-A(2,3)*A(3,1)))
  !     B(3,4) = di*(A(1,1)*(A(2,4)*A(3,2)-A(2,2)*A(3,4))+A(1,2)*(A(2,1)*A(3,4)-A(2,4)*A(3,1))+A(1,4)*(A(2,2)*A(3,1)-A(2,1)*A(3,2)))
  !     B(4,4) = di*(A(1,1)*(A(2,2)*A(3,3)-A(2,3)*A(3,2))+A(1,2)*(A(2,3)*A(3,1)-A(2,1)*A(3,3))+A(1,3)*(A(2,1)*A(3,2)-A(2,2)*A(3,1)))
  !  END FUNCTION
  !  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief 2 x 2  matrix determinant.
  !!
  !!
  !! @param[in] A: Matrix to be printed.
  !! @param[out] B: inverse of A.
  !!
  !***************************************************************************************************!
  PURE FUNCTION {type_name}_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE({type_name}), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE({type_name})             :: det

    ! Calculate the determinant of the matrix
    det = (A(1,1)*A(2,2) - A(1,2)*A(2,1))

  END FUNCTION
  !===================================================================================================! 
  
  !***************************************************************************************************! 
  !> @brief 3 x 3  matrix determinant.
  !!
  !!
  !! @param[in]  A: Matrix to be printed.
  !! @param[out] B: inverse of A.
  !!
  !***************************************************************************************************!
  PURE FUNCTION {type_name}_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE({type_name}), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE({type_name})             :: det

    ! Calculate the inverse determinant of the matrix
    det = (A(1,1)*A(2,2)*A(3,3) - A(1,1)*A(2,3)*A(3,2)&
         - A(1,2)*A(2,1)*A(3,3) + A(1,2)*A(2,3)*A(3,1)&
         + A(1,3)*A(2,1)*A(3,2) - A(1,3)*A(2,2)*A(3,1))

  END FUNCTION
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief 4 x 4  matrix determinant.
  !!
  !!
  !! @param[in]  A: Matrix to be printed.
  !! @param[out] B: inverse of A.
  !!
  !***************************************************************************************************!
  PURE FUNCTION {type_name}_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE({type_name}), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE({type_name})             :: det

    ! Calculate the determinant of the matrix
    det = &
    (A(1,1)*(A(2,2)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(2,3)*(A(3,4)*A(4,2)-A(3,2)*A(4,4))+A(2,4)*(A(3,2)*A(4,3)-A(3,3)*A(4,2)))&
   - A(1,2)*(A(2,1)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(2,3)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(2,4)*(A(3,1)*A(4,3)-A(3,3)*A(4,1)))&
   + A(1,3)*(A(2,1)*(A(3,2)*A(4,4)-A(3,4)*A(4,2))+A(2,2)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(2,4)*(A(3,1)*A(4,2)-A(3,2)*A(4,1)))&
   - A(1,4)*(A(2,1)*(A(3,2)*A(4,3)-A(3,3)*A(4,2))+A(2,2)*(A(3,3)*A(4,1)-A(3,1)*A(4,3))+A(2,3)*(A(3,1)*A(4,2)-A(3,2)*A(4,1))))

  END FUNCTION
  !===================================================================================================! 
   
  !***************************************************************************************************! 
  !> @brief Cross product between two vectors.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  PURE FUNCTION {type_name}_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE({type_name}), DIMENSION (3),INTENT(IN) :: a,b
    TYPE({type_name}), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION {type_name}_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION {type_name}_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE({type_name}), INTENT(IN) :: v(3)
    TYPE({type_name}) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION {type_name}_norm2_3
  !===================================================================================================! 

  ELEMENTAL FUNCTION {type_name}_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      TYPE({type_name}), INTENT(IN) :: Y
      TYPE({type_name}) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION {type_name}_DIVISION_OO

  ELEMENTAL FUNCTION {type_name}_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE({type_name}) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION {type_name}_DIVISION_OR

  ELEMENTAL FUNCTION {type_name}_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE({type_name}), INTENT(IN) :: Y
      TYPE({type_name}) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION {type_name}_DIVISION_RO

  ELEMENTAL FUNCTION {type_name}_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION {type_name}_REAL

  FUNCTION {type_name}_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: X
      TYPE({type_name}) :: RES

      RES = X**0.5_DP

  END FUNCTION {type_name}_SQRT

  FUNCTION {type_name}_MAX(X1,X2) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: X1, X2
                                                
      TYPE({type_name}) :: RES
      RES = X1
      IF (X2>RES) RES = X2  

  END FUNCTION {type_name}_MAX

  FUNCTION {type_name}_MIN(X1,X2) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: X1, X2
                                                
      TYPE({type_name}) :: RES
      RES = X1
      IF (X2<RES) RES = X2

  END FUNCTION {type_name}_MIN

  FUNCTION {type_name}_MAXLOC_R1(ARRAY, MASK, BACK) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:)
      LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1))
      LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
      INTEGER :: RES( RANK( ARRAY ) )
      
      LOGICAL :: MASK_DEF(SIZE(ARRAY,1))
      LOGICAL :: BACK_DEF
      
      ! Assign defaults.
      MASK_DEF = .true.
      BACK_DEF = .false.
      
      IF (PRESENT(MASK)) MASK_DEF = MASK
      IF (PRESENT(BACK)) BACK_DEF = BACK

      RES = MAXLOC(ARRAY%R, MASK = MASK_DEF, BACK = BACK_DEF)

  END FUNCTION {type_name}_MAXLOC_R1

  FUNCTION {type_name}_MAXLOC_R2(ARRAY, MASK, BACK) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:)
      LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1),SIZE(ARRAY,2))
      LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
      INTEGER :: RES( RANK( ARRAY ) )
      
      LOGICAL :: MASK_DEF(SIZE(ARRAY,1),SIZE(ARRAY,2))
      LOGICAL :: BACK_DEF
      
      ! Assign defaults.
      MASK_DEF = .true.
      BACK_DEF = .false.
      
      IF (PRESENT(MASK)) MASK_DEF = MASK
      IF (PRESENT(BACK)) BACK_DEF = BACK
      
      RES = MAXLOC(ARRAY%R, MASK = MASK_DEF, BACK = BACK_DEF)

  END FUNCTION {type_name}_MAXLOC_R2
  
  FUNCTION {type_name}_MAXLOC_R3(ARRAY, MASK, BACK) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:,:)
      LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3))
      LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
      INTEGER :: RES( RANK( ARRAY ) )
      
      LOGICAL :: MASK_DEF(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3))
      LOGICAL :: BACK_DEF
      
      
      ! Assign defaults.
      MASK_DEF = .true.
      BACK_DEF = .false.
      
      IF (PRESENT(MASK)) MASK_DEF = MASK
      IF (PRESENT(BACK)) BACK_DEF = BACK
      
      RES = MAXLOC(ARRAY%R, MASK = MASK_DEF, BACK = BACK_DEF)

  END FUNCTION {type_name}_MAXLOC_R3

  FUNCTION {type_name}_MAXLOC_R4(ARRAY, MASK, BACK) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:,:,:)
      LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3),SIZE(ARRAY,4))
      LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
      INTEGER :: RES( RANK( ARRAY ) )
      
      LOGICAL :: MASK_DEF(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3),SIZE(ARRAY,4))
      LOGICAL :: BACK_DEF
      
      ! Assign defaults.
      MASK_DEF = .true.
      BACK_DEF = .false.
      
      
      IF (PRESENT(MASK)) MASK_DEF = MASK
      IF (PRESENT(BACK)) BACK_DEF = BACK
      

      RES = MAXLOC(ARRAY%R, MASK = MASK_DEF,  BACK = BACK_DEF)

  END FUNCTION {type_name}_MAXLOC_R4

  
  FUNCTION {type_name}_MAXVAL_R1(ARRAY) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:)
      INTEGER :: IDX( RANK( ARRAY ) )
      TYPE({type_name}) :: RES
      

      IDX = MAXLOC(ARRAY)
      RES = ARRAY(IDX(1))

  END FUNCTION {type_name}_MAXVAL_R1

  FUNCTION {type_name}_MAXVAL_R2(ARRAY) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:)
      INTEGER :: IDX( RANK( ARRAY ) )
      TYPE({type_name}) :: RES
      

      IDX = MAXLOC(ARRAY)
      RES = ARRAY(IDX(1),IDX(2))

  END FUNCTION {type_name}_MAXVAL_R2

  FUNCTION {type_name}_MAXVAL_R3(ARRAY) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:,:)
      INTEGER :: IDX( RANK( ARRAY ) )
      TYPE({type_name}) :: RES
      

      IDX = MAXLOC(ARRAY)
      RES = ARRAY(IDX(1),IDX(2),IDX(3))

  END FUNCTION {type_name}_MAXVAL_R3

  FUNCTION {type_name}_MAXVAL_R4(ARRAY) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:,:,:)
      INTEGER :: IDX( RANK( ARRAY ) )
      TYPE({type_name}) :: RES
      

      IDX = MAXLOC(ARRAY)
      RES = ARRAY(IDX(1),IDX(2),IDX(3),IDX(4))

  END FUNCTION {type_name}_MAXVAL_R4


    FUNCTION {type_name}_MINLOC_R1(ARRAY, MASK, BACK) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:)
      LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1))
      LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
      INTEGER :: RES( RANK( ARRAY ) )
      
      LOGICAL :: MASK_DEF(SIZE(ARRAY,1))
      LOGICAL :: BACK_DEF
      
      ! Assign defaults.
      MASK_DEF = .true.
      BACK_DEF = .false.
      
      IF (PRESENT(MASK)) MASK_DEF = MASK
      IF (PRESENT(BACK)) BACK_DEF = BACK

      RES = MINLOC(ARRAY%R, MASK = MASK_DEF, BACK = BACK_DEF)

  END FUNCTION {type_name}_MINLOC_R1

  FUNCTION {type_name}_MINLOC_R2(ARRAY, MASK, BACK) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:)
      LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1),SIZE(ARRAY,2))
      LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
      INTEGER :: RES( RANK( ARRAY ) )
      
      LOGICAL :: MASK_DEF(SIZE(ARRAY,1),SIZE(ARRAY,2))
      LOGICAL :: BACK_DEF
      
      ! Assign defaults.
      MASK_DEF = .true.
      BACK_DEF = .false.
      
      IF (PRESENT(MASK)) MASK_DEF = MASK
      IF (PRESENT(BACK)) BACK_DEF = BACK
      
      RES = MINLOC(ARRAY%R, MASK = MASK_DEF, BACK = BACK_DEF)

  END FUNCTION {type_name}_MINLOC_R2
  
  FUNCTION {type_name}_MINLOC_R3(ARRAY, MASK, BACK) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:,:)
      LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3))
      LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
      INTEGER :: RES( RANK( ARRAY ) )
      
      LOGICAL :: MASK_DEF(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3))
      LOGICAL :: BACK_DEF
      
      
      ! Assign defaults.
      MASK_DEF = .true.
      BACK_DEF = .false.
      
      IF (PRESENT(MASK)) MASK_DEF = MASK
      IF (PRESENT(BACK)) BACK_DEF = BACK
      
      RES = MINLOC(ARRAY%R, MASK = MASK_DEF, BACK = BACK_DEF)

  END FUNCTION {type_name}_MINLOC_R3

  FUNCTION {type_name}_MINLOC_R4(ARRAY, MASK, BACK) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:,:,:)
      LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3),SIZE(ARRAY,4))
      LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
      INTEGER :: RES( RANK( ARRAY ) )
      
      LOGICAL :: MASK_DEF(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3),SIZE(ARRAY,4))
      LOGICAL :: BACK_DEF
      
      ! Assign defaults.
      MASK_DEF = .true.
      BACK_DEF = .false.
      
      
      IF (PRESENT(MASK)) MASK_DEF = MASK
      IF (PRESENT(BACK)) BACK_DEF = BACK
      

      RES = MINLOC(ARRAY%R, MASK = MASK_DEF,  BACK = BACK_DEF)

  END FUNCTION {type_name}_MINLOC_R4



  FUNCTION {type_name}_MINVAL_R1(ARRAY) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:)
      INTEGER :: IDX( RANK( ARRAY ) )
      TYPE({type_name}) :: RES
      

      IDX = MINLOC(ARRAY)
      RES = ARRAY(IDX(1))

  END FUNCTION {type_name}_MINVAL_R1

  FUNCTION {type_name}_MINVAL_R2(ARRAY) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:)
      INTEGER :: IDX( RANK( ARRAY ) )
      TYPE({type_name}) :: RES
      

      IDX = MINLOC(ARRAY)
      RES = ARRAY(IDX(1),IDX(2))

  END FUNCTION {type_name}_MINVAL_R2

  FUNCTION {type_name}_MINVAL_R3(ARRAY) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:,:)
      INTEGER :: IDX( RANK( ARRAY ) )
      TYPE({type_name}) :: RES
      

      IDX = MINLOC(ARRAY)
      RES = ARRAY(IDX(1),IDX(2),IDX(3))

  END FUNCTION {type_name}_MINVAL_R3

  FUNCTION {type_name}_MINVAL_R4(ARRAY) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: ARRAY(:,:,:,:)
      INTEGER :: IDX( RANK( ARRAY ) )
      TYPE({type_name}) :: RES
      

      IDX = MINLOC(ARRAY)
      RES = ARRAY(IDX(1),IDX(2),IDX(3),IDX(4))

  END FUNCTION {type_name}_MINVAL_R4

  ! FUNCTION {type_name}_MAXLOC_DIM_R1(ARRAY, DIM, MASK, KIND, BACK) RESULT(RES)
  !     IMPLICIT NONE
  !     TYPE({type_name}), INTENT(IN) :: ARRAY(:)
  !     INTEGER, INTENT(IN) :: DIM  
  !     LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1))
  !     INTEGER, INTENT(IN), OPTIONAL :: KIND  ! Not used in this case.
  !     LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
  !     INTEGER :: RES( RANK( ARRAY ) )
      
  !     LOGICAL :: MASK_DEF(SIZE(ARRAY,1))
  !     LOGICAL :: BACK_DEF
      
  !     ! Assign defaults.
  !     MASK_DEF = .true.
  !     BACK_DEF = .false.
      
  !     IF (PRESENT(MASK)) MASK_DEF = MASK
  !     IF (PRESENT(BACK)) BACK_DEF = BACK

  !     RES = MAXLOC(ARRAY%R, MASK = MASK_DEF, BACK = BACK_DEF)

  ! END FUNCTION {type_name}_MAXLOC_DIM_R1

  ! FUNCTION {type_name}_MAXLOC_DIM_R2(ARRAY, DIM, MASK, KIND, BACK) RESULT(RES)
  !     IMPLICIT NONE
  !     TYPE({type_name}), INTENT(IN) :: ARRAY(:,:)
  !     INTEGER, INTENT(IN) :: DIM  
  !     LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1),SIZE(ARRAY,2))
  !     INTEGER, INTENT(IN), OPTIONAL :: KIND  ! Not used in this case.
  !     LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
  !     INTEGER :: RES( RANK( ARRAY ) )
      
  !     LOGICAL :: MASK_DEF(SIZE(ARRAY,1),SIZE(ARRAY,2))
  !     LOGICAL :: BACK_DEF
      
  !     ! Assign defaults.
  !     MASK_DEF = .true.
  !     BACK_DEF = .false.
      
  !     IF (PRESENT(MASK)) MASK_DEF = MASK
  !     IF (PRESENT(BACK)) BACK_DEF = BACK
      
  !     RES = MAXLOC(ARRAY%R, DIM, MASK = MASK_DEF, BACK = BACK_DEF)

  ! END FUNCTION {type_name}_MAXLOC_DIM_R2
  
  ! FUNCTION {type_name}_MAXLOC_DIM_R3(ARRAY, DIM, MASK, KIND, BACK) RESULT(RES)
  !     IMPLICIT NONE
  !     TYPE({type_name}), INTENT(IN) :: ARRAY(:,:,:)
  !     INTEGER, INTENT(IN) :: DIM  
  !     LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3))
  !     INTEGER, INTENT(IN), OPTIONAL :: KIND  ! Not used in this case.
  !     LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
  !     INTEGER :: RES( RANK( ARRAY ) )
      
  !     LOGICAL :: MASK_DEF(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3))
  !     LOGICAL :: BACK_DEF
      
      
  !     ! Assign defaults.
  !     MASK_DEF = .true.
  !     BACK_DEF = .false.
      
  !     IF (PRESENT(MASK)) MASK_DEF = MASK
  !     IF (PRESENT(BACK)) BACK_DEF = BACK
      
  !     RES = MAXLOC(ARRAY%R, DIM, MASK = MASK_DEF, BACK = BACK_DEF)

  ! END FUNCTION {type_name}_MAXLOC_DIM_R3

  ! FUNCTION {type_name}_MAXLOC_DIM_R4(ARRAY, DIM, MASK, KIND, BACK) RESULT(RES)
  !     IMPLICIT NONE
  !     TYPE({type_name}), INTENT(IN) :: ARRAY(:,:,:,:)
  !     INTEGER, INTENT(IN) :: DIM  
  !     LOGICAL, INTENT(IN), OPTIONAL :: MASK(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3),SIZE(ARRAY,4))
  !     INTEGER, INTENT(IN), OPTIONAL :: KIND  ! Not used in this case, just for compatibility.
  !     LOGICAL, INTENT(IN), OPTIONAL :: BACK  ! Search from the back
      
  !     INTEGER :: RES( RANK( ARRAY ) )
      
  !     LOGICAL :: MASK_DEF(SIZE(ARRAY,1),SIZE(ARRAY,2),SIZE(ARRAY,3),SIZE(ARRAY,4))
  !     LOGICAL :: BACK_DEF
      
  !     ! Assign defaults.
  !     MASK_DEF = .true.
  !     BACK_DEF = .false.
      
      
  !     IF (PRESENT(MASK)) MASK_DEF = MASK
  !     IF (PRESENT(BACK)) BACK_DEF = BACK
      

  !     RES = MAXLOC(ARRAY%R, DIM, MASK = MASK_DEF, BACK = BACK_DEF)

  ! END FUNCTION {type_name}_MAXLOC_DIM_R4