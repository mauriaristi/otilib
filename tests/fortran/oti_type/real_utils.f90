!*******************************************************************************************************!
!> @brief This module contains types and subroutines to simplify handling of real matrix and vector 
!!        operations.
!! 
!! @author Mauricio Aristizabal Cano, University of Texas at San Antonio
!*******************************************************************************************************!
MODULE real_utils
   !---------------------------------------------------------------------------------------------------! 
   USE master_parameters
   IMPLICIT NONE
   !---------------------------------------------------------------------------------------------------! 
   INTERFACE PPRINT
     MODULE PROCEDURE RmatPrint, RvecPrint, Rprint,IPrint, ImatPrint, IvecPrint
   END INTERFACE
   
   !---------------------------------------------------------------------------------------------------! 
   ! Matrix Determinant overloads.
   !---------------------------------------------------------------------------------------------------! 

   INTERFACE det2x2
     MODULE PROCEDURE Rdet2x2
   END INTERFACE

   INTERFACE det3x3
     MODULE PROCEDURE Rdet3x3
   END INTERFACE

   INTERFACE det4x4
     MODULE PROCEDURE Rdet4x4
   END INTERFACE

   !---------------------------------------------------------------------------------------------------! 
   ! Matrix inverse overloads.
   !---------------------------------------------------------------------------------------------------! 

   INTERFACE inv2x2
     MODULE PROCEDURE Rmatinv2x2
   END INTERFACE

   INTERFACE inv3x3
     MODULE PROCEDURE Rmatinv3x3
   END INTERFACE

   INTERFACE inv4x4
     MODULE PROCEDURE Rmatinv4x4
   END INTERFACE

   !---------------------------------------------------------------------------------------------------! 
   ! Other Linalg Operations overloads.
   !---------------------------------------------------------------------------------------------------! 

   INTERFACE norm2_3
     MODULE PROCEDURE Rnorm2_3
   END INTERFACE

   INTERFACE cross3
     MODULE PROCEDURE Rcross3
   END INTERFACE

   INTERFACE interp1D
     MODULE PROCEDURE Rinterp1D
   END INTERFACE

   INTERFACE Inxn
     MODULE PROCEDURE RInxn
   END INTERFACE

   INTERFACE VectorToMatrix
     MODULE PROCEDURE RVectorToMatrix
   END INTERFACE

   INTERFACE MatrixToVector
     MODULE PROCEDURE RMatrixToVector
   END INTERFACE

   INTERFACE FrobeniusProduct
     MODULE PROCEDURE RFrobeniusProduct
   END INTERFACE


   !---------------------------------------------------------------------------------------------------! 

CONTAINS

   !***************************************************************************************************! 
   !> @brief 2 x 2  matrix inversion.
   !!
   !! Taken from https://fortranwiki.org/fortran/show/Matrix+inversion
   !!
   !! @param[in] A: Matrix to be printed.
   !! @param[out] B: inverse of A.
   !!
   !***************************************************************************************************!
   PURE FUNCTION Rmatinv2x2(A,det) RESULT(B)

      IMPLICIT NONE

      REAL(dp), INTENT(IN) :: A(2,2)   !! Matrix
      REAL(dp), INTENT(IN), OPTIONAL :: det
      REAL(dp)             :: B(2,2)   !! Inverse matrix
      REAL(dp)             :: detinv

      IF ( PRESENT(det) ) THEN
         detinv = one/det
      ELSE
         ! Calculate the inverse determinant of the matrix
         detinv = one/(A(1,1)*A(2,2) - A(1,2)*A(2,1))
      END IF

      ! Calculate the inverse of the matrix
      B(1,1) =  detinv * A(2,2)
      B(2,1) = -detinv * A(2,1)
      B(1,2) = -detinv * A(1,2)
      B(2,2) =  detinv * A(1,1)
   END FUNCTION
   !===================================================================================================! 
   
   !***************************************************************************************************! 
   !> @brief 3 x 3  matrix inversion.
   !!
   !! Taken from https://fortranwiki.org/fortran/show/Matrix+inversion
   !!
   !! @param[in]  A: Matrix to be printed.
   !! @param[out] B: inverse of A.
   !!
   !***************************************************************************************************!
   PURE FUNCTION Rmatinv3x3(A,det) RESULT(B)
      
      IMPLICIT NONE

      REAL(dp), INTENT(IN) :: A(3,3)   !! Matrix
      REAL(dp), INTENT(IN), OPTIONAL :: det
      REAL(dp)             :: B(3,3)   !! Inverse matrix
      REAL(dp)             :: detinv

      IF ( PRESENT(det) ) THEN
         detinv = one/det
      ELSE
         ! Calculate the inverse determinant of the matrix
         detinv = one/(A(1,1)*A(2,2)*A(3,3) - A(1,1)*A(2,3)*A(3,2)&
                       - A(1,2)*A(2,1)*A(3,3) + A(1,2)*A(2,3)*A(3,1)&
                       + A(1,3)*A(2,1)*A(3,2) - A(1,3)*A(2,2)*A(3,1))
      END IF 

      ! Calculate the inverse of the matrix
      B(1,1) = + detinv * (A(2,2)*A(3,3) - A(2,3)*A(3,2))
      B(2,1) = - detinv * (A(2,1)*A(3,3) - A(2,3)*A(3,1))
      B(3,1) = + detinv * (A(2,1)*A(3,2) - A(2,2)*A(3,1))
      B(1,2) = - detinv * (A(1,2)*A(3,3) - A(1,3)*A(3,2))
      B(2,2) = + detinv * (A(1,1)*A(3,3) - A(1,3)*A(3,1))
      B(3,2) = - detinv * (A(1,1)*A(3,2) - A(1,2)*A(3,1))
      B(1,3) = + detinv * (A(1,2)*A(2,3) - A(1,3)*A(2,2))
      B(2,3) = - detinv * (A(1,1)*A(2,3) - A(1,3)*A(2,1))
      B(3,3) = + detinv * (A(1,1)*A(2,2) - A(1,2)*A(2,1))

   END FUNCTION
   !===================================================================================================! 

   !***************************************************************************************************! 
   !> @brief 4 x 4  matrix inversion.
   !!
   !! Taken from https://fortranwiki.org/fortran/show/Matrix+inversion
   !!
   !! @param[in]  A: Matrix to be printed.
   !! @param[in]  det: (optional) Determinant of A.
   !! @param[out] B: inverse of A.
   !!
   !***************************************************************************************************!
   PURE FUNCTION Rmatinv4x4(A,det) RESULT(B)
      
      IMPLICIT NONE

      REAL(dp), INTENT(IN) :: A(4,4)   !! Matrix
      REAL(dp), INTENT(IN), OPTIONAL :: det
      REAL(dp)             :: B(4,4)   !! Inverse matrix
      REAL(dp)             :: di  !! Determinant inverse

      ! Calculate the inverse determinant of the matrix
      IF ( PRESENT(det) ) THEN
         di = one/det
      ELSE
         di = &
    one/(A(1,1)*(A(2,2)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(2,3)*(A(3,4)*A(4,2)-A(3,2)*A(4,4))+A(2,4)*(A(3,2)*A(4,3)-A(3,3)*A(4,2)))&
         - A(1,2)*(A(2,1)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(2,3)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(2,4)*(A(3,1)*A(4,3)-A(3,3)*A(4,1)))&
         + A(1,3)*(A(2,1)*(A(3,2)*A(4,4)-A(3,4)*A(4,2))+A(2,2)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(2,4)*(A(3,1)*A(4,2)-A(3,2)*A(4,1)))&
         - A(1,4)*(A(2,1)*(A(3,2)*A(4,3)-A(3,3)*A(4,2))+A(2,2)*(A(3,3)*A(4,1)-A(3,1)*A(4,3))+A(2,3)*(A(3,1)*A(4,2)-A(3,2)*A(4,1))))
      END IF 
      
      ! Calculate the inverse of the matrix
      B(1,1) = di*(A(2,2)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(2,3)*(A(3,4)*A(4,2)-A(3,2)*A(4,4))+A(2,4)*(A(3,2)*A(4,3)-A(3,3)*A(4,2)))
      B(2,1) = di*(A(2,1)*(A(3,4)*A(4,3)-A(3,3)*A(4,4))+A(2,3)*(A(3,1)*A(4,4)-A(3,4)*A(4,1))+A(2,4)*(A(3,3)*A(4,1)-A(3,1)*A(4,3)))
      B(3,1) = di*(A(2,1)*(A(3,2)*A(4,4)-A(3,4)*A(4,2))+A(2,2)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(2,4)*(A(3,1)*A(4,2)-A(3,2)*A(4,1)))
      B(4,1) = di*(A(2,1)*(A(3,3)*A(4,2)-A(3,2)*A(4,3))+A(2,2)*(A(3,1)*A(4,3)-A(3,3)*A(4,1))+A(2,3)*(A(3,2)*A(4,1)-A(3,1)*A(4,2)))
      B(1,2) = di*(A(1,2)*(A(3,4)*A(4,3)-A(3,3)*A(4,4))+A(1,3)*(A(3,2)*A(4,4)-A(3,4)*A(4,2))+A(1,4)*(A(3,3)*A(4,2)-A(3,2)*A(4,3)))
      B(2,2) = di*(A(1,1)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(1,3)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(1,4)*(A(3,1)*A(4,3)-A(3,3)*A(4,1)))
      B(3,2) = di*(A(1,1)*(A(3,4)*A(4,2)-A(3,2)*A(4,4))+A(1,2)*(A(3,1)*A(4,4)-A(3,4)*A(4,1))+A(1,4)*(A(3,2)*A(4,1)-A(3,1)*A(4,2)))
      B(4,2) = di*(A(1,1)*(A(3,2)*A(4,3)-A(3,3)*A(4,2))+A(1,2)*(A(3,3)*A(4,1)-A(3,1)*A(4,3))+A(1,3)*(A(3,1)*A(4,2)-A(3,2)*A(4,1)))
      B(1,3) = di*(A(1,2)*(A(2,3)*A(4,4)-A(2,4)*A(4,3))+A(1,3)*(A(2,4)*A(4,2)-A(2,2)*A(4,4))+A(1,4)*(A(2,2)*A(4,3)-A(2,3)*A(4,2)))
      B(2,3) = di*(A(1,1)*(A(2,4)*A(4,3)-A(2,3)*A(4,4))+A(1,3)*(A(2,1)*A(4,4)-A(2,4)*A(4,1))+A(1,4)*(A(2,3)*A(4,1)-A(2,1)*A(4,3)))
      B(3,3) = di*(A(1,1)*(A(2,2)*A(4,4)-A(2,4)*A(4,2))+A(1,2)*(A(2,4)*A(4,1)-A(2,1)*A(4,4))+A(1,4)*(A(2,1)*A(4,2)-A(2,2)*A(4,1)))
      B(4,3) = di*(A(1,1)*(A(2,3)*A(4,2)-A(2,2)*A(4,3))+A(1,2)*(A(2,1)*A(4,3)-A(2,3)*A(4,1))+A(1,3)*(A(2,2)*A(4,1)-A(2,1)*A(4,2)))
      B(1,4) = di*(A(1,2)*(A(2,4)*A(3,3)-A(2,3)*A(3,4))+A(1,3)*(A(2,2)*A(3,4)-A(2,4)*A(3,2))+A(1,4)*(A(2,3)*A(3,2)-A(2,2)*A(3,3)))
      B(2,4) = di*(A(1,1)*(A(2,3)*A(3,4)-A(2,4)*A(3,3))+A(1,3)*(A(2,4)*A(3,1)-A(2,1)*A(3,4))+A(1,4)*(A(2,1)*A(3,3)-A(2,3)*A(3,1)))
      B(3,4) = di*(A(1,1)*(A(2,4)*A(3,2)-A(2,2)*A(3,4))+A(1,2)*(A(2,1)*A(3,4)-A(2,4)*A(3,1))+A(1,4)*(A(2,2)*A(3,1)-A(2,1)*A(3,2)))
      B(4,4) = di*(A(1,1)*(A(2,2)*A(3,3)-A(2,3)*A(3,2))+A(1,2)*(A(2,3)*A(3,1)-A(2,1)*A(3,3))+A(1,3)*(A(2,1)*A(3,2)-A(2,2)*A(3,1)))
   END FUNCTION
   !===================================================================================================! 

   !***************************************************************************************************! 
   !> @brief 2 x 2  matrix determinant.
   !!
   !!
   !! @param[in] A: Matrix to be printed.
   !! @param[out] B: inverse of A.
   !!
   !***************************************************************************************************!
   PURE FUNCTION Rdet2x2(A) RESULT(det)

      IMPLICIT NONE

      REAL(dp), INTENT(IN) :: A(2,2)   !! Matrix
      REAL(dp)             :: det

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
   PURE FUNCTION Rdet3x3(A) RESULT(det)
      
      IMPLICIT NONE

      REAL(dp), INTENT(IN) :: A(3,3)   !! Matrix
      REAL(dp)             :: det

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
   PURE FUNCTION Rdet4x4(A) RESULT(det)
      
      IMPLICIT NONE

      REAL(dp), INTENT(IN) :: A(4,4)   !! Matrix
      REAL(dp)             :: det

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
   PURE FUNCTION Rcross3(a,b) RESULT(v)
      
      IMPLICIT NONE 

      REAL(dp), DIMENSION (3),INTENT(IN) :: a,b
      REAL(dp), DIMENSION (3) :: v
      
      v(1) = a(2) * b(3) - a(3) * b(2)
      v(2) = a(3) * b(1) - a(1) * b(3)
      v(3) = a(1) * b(2) - a(2) * b(1)

   END FUNCTION Rcross3
   !===================================================================================================! 

   !***************************************************************************************************! 
   !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
   !!
   !! @param[in] a: Vector of 3 reals (rank 1).
   !! @param[in] b: Vector of 3 reals (rank 1).
   !!
   !***************************************************************************************************!
   PURE FUNCTION Rnorm2_3(v) RESULT(n)
      
      IMPLICIT NONE 

      REAL(dp), INTENT(IN) :: v(3)
      REAL(dp) :: n
      
      n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

   END FUNCTION Rnorm2_3
   !===================================================================================================! 


   !***************************************************************************************************! 
   !> @brief Pretty print a real scalar.
   !!
   !! @param[in] val: Value to be printed.
   !! @param[in] fmt: Format to print every element in the array.
   !!
   !***************************************************************************************************! 
   SUBROUTINE RPrint(val,fmt, unit, advance)
      IMPLICIT NONE
      REAL(dp),   INTENT(IN) :: val
      CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
      INTEGER, INTENT(IN), OPTIONAL :: unit
      CHARACTER(len=*), INTENT(IN), OPTIONAL :: advance
      CHARACTER(len=:),ALLOCATABLE :: output_format
      CHARACTER(len=:),ALLOCATABLE :: adv
      INTEGER  i, j
      INTEGER :: unt
      !-------------------------------------------------------------------------------------------------!
      
      IF ( PRESENT(unit) ) THEN
         unt = unit
      ELSE
         unt = 6 ! Default print unit for most systems.
      END IF 

      IF (PRESENT(fmt)) THEN
         output_format = '('//trim(fmt)//')'
      ELSE
         output_format = '(F10.4)'
      END IF

      IF (PRESENT(advance)) THEN
         adv = trim(advance)
      ELSE
         adv = 'YES'
      END IF

      write(unt,output_format, advance=adv) val

   END SUBROUTINE
   !===================================================================================================! 

   !***************************************************************************************************! 
   !> @brief Pretty print a real matrix.
   !!
   !! @param[in] arr: Matrix to be printed.
   !! @param[in] fmt: Format to print every element in the array.
   !!
   !***************************************************************************************************! 
   SUBROUTINE RmatPrint(arr,fmt,unit)
      IMPLICIT NONE
      REAL(dp),   INTENT(IN) :: arr(:,:)
      CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
      INTEGER, INTENT(IN), OPTIONAL :: unit
      CHARACTER(len=:),ALLOCATABLE :: output_format
      INTEGER  i, j
      INTEGER :: unt
      !-------------------------------------------------------------------------------------------------!
      
      IF ( PRESENT(unit) ) THEN
         unt = unit
      ELSE
         unt = 6 ! Default print unit for most systems.
      END IF 

      IF (PRESENT(fmt)) THEN
         output_format = '('//trim(fmt)//')'
      ELSE
         output_format = '(F10.4)'
      END IF 

      write(unt,'(A)',advance="no") "["

      DO i=1,SIZE(arr,1)

         IF (I /= 1) THEN
            write(unt,'(A)',advance="no") " "   
         END IF 
         write(unt,'(A)',advance="no") "["

         DO j=1,SIZE(arr,2)
           
            write(unt,output_format,advance="no") &
              arr(i,j)

            write(unt,"(A)",advance="no") ", "

         END DO

         IF (I /= SIZE(arr,1)) THEN
            write(unt,'(A)') "]"
         ELSE
            write(unt,'(A)',advance="no") "]"   
         END IF 

      END DO
      
      write(unt,'(A)') "]"

   END SUBROUTINE
   !===================================================================================================! 
   
   !***************************************************************************************************! 
   !> @brief Pretty print a real vector.
   !!
   !! @param[in] arr: Vector to be printed.
   !! @param[in] fmt: Format to print every element in the array.
   !!
   !***************************************************************************************************! 
   SUBROUTINE RvecPrint(arr,fmt, unit)
      IMPLICIT NONE
      REAL(dp),   INTENT(IN) :: arr(:)
      CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
      INTEGER, INTENT(IN), OPTIONAL :: unit
      CHARACTER(len=:),ALLOCATABLE :: output_format
      INTEGER  i, j
      INTEGER :: unt
      !-------------------------------------------------------------------------------------------------!
      
      IF ( PRESENT(unit) ) THEN
         unt = unit
      ELSE
         unt = 6 ! Default print unit for most systems.
      END IF 

      IF (PRESENT(fmt)) THEN
         output_format = '('//trim(fmt)//')'
      ELSE
         output_format = '(F10.4)'
      END IF 

      write(unt,'(A)',advance="no") "["
      
      DO i=1,SIZE(arr,1)
         write(unt,output_format,advance="no") arr(i)
         write(unt,"(A)",advance="no") ", "
      END DO
      write(unt,'(A)') "]"

   END SUBROUTINE
   !===================================================================================================! 

   !***************************************************************************************************! 
   !> @brief Pretty print a integer scalar.
   !!
   !! @param[in] val: Value to be printed.
   !! @param[in] fmt: Format to print every element in the array.
   !!
   !***************************************************************************************************! 
   SUBROUTINE IPrint(val,fmt,unit)
      IMPLICIT NONE
      INTEGER,   INTENT(IN) :: val
      CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
      INTEGER, INTENT(IN), OPTIONAL :: unit
      CHARACTER(len=:),ALLOCATABLE :: output_format
      INTEGER :: unt
      !-------------------------------------------------------------------------------------------------!
      
      IF ( PRESENT(unit) ) THEN
         unt = unit
      ELSE
         unt = 6 ! Default print unit for most systems.
      END IF 

      IF (PRESENT(fmt)) THEN
         output_format = '('//trim(fmt)//')'
      ELSE
         output_format = '(I8)'
      END IF

      write(unt,output_format) val

   END SUBROUTINE
   !===================================================================================================! 

   !***************************************************************************************************! 
   !> @brief Pretty print a integer matrix.
   !!
   !! @param[in] arr: Matrix to be printed.
   !! @param[in] fmt: Format to print every element in the array.
   !!
   !***************************************************************************************************! 
   SUBROUTINE ImatPrint(arr,fmt,unit)
      IMPLICIT NONE
      INTEGER,   INTENT(IN) :: arr(:,:)
      CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
      INTEGER, INTENT(IN), OPTIONAL :: unit
      CHARACTER(len=:),ALLOCATABLE :: output_format
      INTEGER  i, j
      INTEGER :: unt
      !-------------------------------------------------------------------------------------------------!
      
      IF ( PRESENT(unit) ) THEN
         unt = unit
      ELSE
         unt = 6 ! Default print unit for most systems.
      END IF 

      IF (PRESENT(fmt)) THEN
         output_format = '('//trim(fmt)//')'
      ELSE
         output_format = '(I8)'
      END IF 

      write(unt,'(A)',advance="no") "["

      DO i=1,SIZE(arr,1)

         IF (I /= 1) THEN
            write(unt,'(A)',advance="no") " "   
         END IF 
         write(unt,'(A)',advance="no") "["

         DO j=1,SIZE(arr,2)
           
            write(unt,output_format,advance="no") &
              arr(i,j)

            write(unt,"(A)",advance="no") ", "

         END DO

         IF (I /= SIZE(arr,1)) THEN
            write(*,'(A)') "]"
         ELSE
            write(*,'(A)',advance="no") "]"   
         END IF 

      END DO
      
      write(unt,'(A)') "]"

   END SUBROUTINE
   !===================================================================================================! 
   
   !***************************************************************************************************! 
   !> @brief Pretty print a integer vector.
   !!
   !! @param[in] arr: Vector to be printed.
   !! @param[in] fmt: Format to print every element in the array.
   !!
   !***************************************************************************************************! 
   SUBROUTINE IvecPrint(arr,fmt,unit)
      IMPLICIT NONE
      INTEGER,   INTENT(IN) :: arr(:)
      CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
      INTEGER, INTENT(IN), OPTIONAL :: unit
      CHARACTER(len=:),ALLOCATABLE :: output_format
      INTEGER  i, j
      INTEGER :: unt
      !-------------------------------------------------------------------------------------------------!
      
      IF ( PRESENT(unit) ) THEN
         unt = unit
      ELSE
         unt = 6 ! Default print unit for most systems.
      END IF 

      IF (PRESENT(fmt)) THEN
         output_format = '('//trim(fmt)//')'
      ELSE
         output_format = '(I8)'
      END IF 

      WRITE(unt,'(A)',advance="no") "["
      
      DO i=1,SIZE(arr,1)
         WRITE(unt,output_format,advance='no') arr(i)
         WRITE(unt,'(A)',advance="no") ", "
      END DO
      WRITE(unt,'(A)') "]"

   END SUBROUTINE
   !===================================================================================================! 



   !***************************************************************************************************! 
   !> @brief Interpolation in 1D. xData MUST be in ascending order with no repeated entries.
   !!
   !! @param[in] xData: x-values of data in existance.
   !! @param[in] yData: y-values of data in existance.
   !! @param[in] x: Value to interpolate.
   !!
   !***************************************************************************************************! 
   FUNCTION Rinterp1D(xData,yData,x) RESULT(y)
      
      IMPLICIT NONE
      
      REAL(dp),   INTENT(IN) :: xData(:)
      REAL(dp),   INTENT(IN) :: yData( SIZE(xData) )
      REAL(dp),   INTENT(IN) :: x
      REAL(dp)               :: y ! Result.
      REAL(dp)               :: m
      INTEGER :: N, start, finish , range, mid 

      N = SIZE(xData)

      start = 1
      finish = N
      mid = (start + finish) / 2

      ! First check bounds
      IF ( x <= xData(start) ) THEN
         
         y =  yData(start)

      ELSEIF ( x >= xData(finish) ) THEN
         
         y =  yData(finish)

      ELSE
         
         range = finish - start

         ! Loop to find correct index.
         DO WHILE( range > 1 ) 
            
            IF (x > xData(mid)) THEN
              start = mid 
            ELSE 
              finish = mid
            END IF

            range = finish - start
            mid = (start + finish)/2

         END DO

         m = (yData(mid+1)-yData(mid)) / ( xData(mid+1)-xData(mid)) ! Line region slope.
         y = m * ( x - xData(mid) )  + yData(mid)

      END IF 


   END FUNCTION
   !===================================================================================================! 

   !===================================================================================================! 

   !***************************************************************************************************! 
   !> @brief identity matrix rXr.
   !!
   !!
   !***************************************************************************************************!
   FUNCTION RInxn(r) RESULT(I)
      
      IMPLICIT NONE 

      INTEGER,   INTENT(IN)  :: r
      REAL(dp) :: I(r,r)
      INTEGER  :: j

      I = zero
      DO j = 1,r 
         I(j,j) = one
      END DO
      
   END FUNCTION
   !===================================================================================================! 

   !***************************************************************************************************! 
   !> @brief turn a tensor in vector notation to matrix notation.
   !!
   !!
   !***************************************************************************************************!
   PURE FUNCTION RVectorToMatrix(v) RESULT(T)
      
      IMPLICIT NONE 
      
      REAL(dp),   INTENT(IN)  :: v(6)
      REAL(dp) :: T(3,3)

      T(1,1) = v(1);  T(1,2) = v(4);  T(1,3) = v(6)
      T(2,1) = v(4);  T(2,2) = v(2);  T(2,3) = v(5)
      T(3,1) = v(6);  T(3,2) = v(5);  T(3,3) = v(3)
      
   END FUNCTION RVectorToMatrix
   !===================================================================================================! 

   !***************************************************************************************************! 
   !> @brief turn a tensor in matrix notation to vector notation.
   !!
   !!
   !***************************************************************************************************!
   PURE FUNCTION RMatrixToVector(T) RESULT(v)
      
      IMPLICIT NONE 
      
      REAL(dp),   INTENT(IN) :: T(3,3)
      REAL(dp) :: v(6)

      v(1) = T(1,1) 
      v(4) = T(2,1);  v(2) = T(2,2);
      v(6) = T(3,1);  v(5) = T(3,2);  v(3) = T(3,3)
      
   END FUNCTION RMatrixToVector
   !===================================================================================================! 

   !***************************************************************************************************! 
   !> @brief Compute the Frobenius product between two 3x3 tensors
   !!
   !!             res = A : B
   !!
   !! @param[in] A: 3x3 real tensor.
   !! @param[in] B: 3x3 real tensor.
   !!
   !***************************************************************************************************!
   PURE FUNCTION RFrobeniusProduct(A,B) RESULT(res)
      
      IMPLICIT NONE 
      
      REAL(dp), INTENT(IN) :: A(3,3), B(3,3)
      REAL(dp) :: res

      res = A(1,1)*B(1,1) + A(1,2)*B(1,2) + A(1,3)*B(1,3) + &
            A(2,1)*B(2,1) + A(2,2)*B(2,2) + A(2,3)*B(2,3) + &
            A(3,1)*B(3,1) + A(3,2)*B(3,2) + A(3,3)*B(3,3) 
      
   END FUNCTION RFrobeniusProduct
   !===================================================================================================! 

END MODULE real_utils