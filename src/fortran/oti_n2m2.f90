!
! A module for basic Hypercomplex algebra operations.
! In particular, OTI algebra with up to m=2 imaginary basis and 
! truncation order n=2
!!
!! @author
!! Mauricio Aristizabal               \n 
!! Universidad EAFIT                  \n 
!! University of Texas at San Antonio \n 
!!

!> Module to manipulate OTI numbers and vector/matrices of OTI numbers.
MODULE otinum_m2n2
  IMPLICIT NONE

  
  INTEGER, PARAMETER :: REAL_KIND = 8
  INTEGER, PARAMETER :: NUM_IM_DIR = 3
  
  ! OTI type. It only contains four
  ! real components, but the main advantage for
  ! defining it as a custom type is the possibility
  ! to write routines and operators for OTI
  ! algebra.
  ! *w the "real" component of the OTI
  ! *x an "imaginary" component of the OTI
  ! *y an "imaginary" component of the OTI
  TYPE otim2n2
     REAL(REAL_KIND) :: r
     ! order 1
     REAL(REAL_KIND) :: e1  ! \epsilon_1
     REAL(REAL_KIND) :: e2  ! \epsilon_2
     ! Order 2
     REAL(REAL_KIND) :: e11 ! \epsilon_1^2
     REAL(REAL_KIND) :: e12 ! \epsilon_1\epsilon_2
     REAL(REAL_KIND) :: e22 ! \epsilon_2^2
  END TYPE otim2n2


! =============================================================================
! =========================== UTSA ADDED PROCEDURES ===========================
! =============================================================================

! Quarternion + scalar operator
INTERFACE operator(+)
   MODULE PROCEDURE qplus , qplusB
END INTERFACE

! Quarternion - scalar operator
INTERFACE operator(-)
   MODULE PROCEDURE qminus, qminusB, qneg
END INTERFACE

! Quarternion / OTI operator
INTERFACE operator(/)
   MODULE PROCEDURE qdivq, qmatDr, qvecDr
END INTERFACE

! Quarternion power operator
INTERFACE operator(**)
   MODULE PROCEDURE qpow
END INTERFACE

INTERFACE MATMUL
  MODULE PROCEDURE  qmatXqmat, &         ! Qmat x Qmat
                    rmatXqmat, qmatXrmat ! Rmat x Qmat, Qmat x Rmat 
                    
END INTERFACE

INTERFACE MATMUL_SUB
  MODULE PROCEDURE qmatXqmat_sub_rr, qmatXqmat_sub_qq
END INTERFACE

INTERFACE operator(*)
  MODULE PROCEDURE qXqmat_proc, rXqmat_proc, qmatXr_proc, qmatXq_proc, &
                   qXqvec_proc, rXqvec_proc, qvecXr_proc, qvecXq_proc, & ! Vector operations.
                   qvecXqvec_proc, qvecXrvec_proc, rvecXqvec_proc,     &  ! elementwise
                   qmatXqmat_proc, qmatXrmat_proc, rmatXqmat_proc
END INTERFACE

INTERFACE operator(+)
  MODULE PROCEDURE qPqmat, rPqmat, qmatPq, qmatPr,  &  ! Mult Matrix times OTI and 
                   qmatPqmat, rmatPqmat, qmatPrmat, &
                   qvecPqvec, qvecPrvec, rvecPqvec
END INTERFACE

INTERFACE operator(-)
  MODULE PROCEDURE qMqmat, rMqmat,  qmatMq, qmatMr, &
                   qmatMrmat, qmatMqmat, rmatMqmat, &
                   qvecMqvec, qvecMrvec, rvecMqvec, &
                   qmatNeg, qvecNeg
END INTERFACE

INTERFACE TRANSPOSE
  MODULE PROCEDURE  qmatTrans_proc
END INTERFACE

INTERFACE ASSIGNMENT (=)
  MODULE PROCEDURE  qASSIGNr, qASSIGNrvec
END INTERFACE

INTERFACE DOT_PRODUCT
  MODULE PROCEDURE  qvecDOTqvec, rvecDOTqvec, qvecDOTrvec 
END INTERFACE

!> @brief      Pretty print 
!> @details    Get an object with time information.
!> @return     returns the time with high precision
!> @par        Code
INTERFACE PPRINT
  MODULE PROCEDURE QPrint,    RPrint,    & ! OTI / real print
                   QmatPrint, RmatPrint, & ! Matrix print
                   QvecPrint, RvecPrint    ! vector prints
END INTERFACE

INTERFACE INIT
  MODULE PROCEDURE QINITr, QvecINITr, QmatINITr, &   ! Initialization  calls
                   QINITq, QvecINITq, QmatINITq
END INTERFACE

INTERFACE MATFOLD
  MODULE PROCEDURE QvecFold_multiple_src, QmatFold_multiple_src
END INTERFACE


! =============================================================================
! =========================== UTSA ADDED PROCEDURES ===========================
! =============================================================================


! Quarternion product operator
INTERFACE operator(*)
   MODULE PROCEDURE qprod
END INTERFACE

! Real / OTI operator
INTERFACE operator(/)
   MODULE PROCEDURE rdivq
END INTERFACE

! Quarternion + OTI operator
INTERFACE operator(+)
   MODULE PROCEDURE qplusq
END INTERFACE

! Quarternion - Quarternion operator
INTERFACE operator(-)
   MODULE PROCEDURE qminusq
END INTERFACE

! Scalar * quarternion operator
INTERFACE operator(*)
   MODULE PROCEDURE qtimes
END INTERFACE

! Quarternion * scalar operator
INTERFACE operator(*)
   MODULE PROCEDURE qtimesB
END INTERFACE

! Quarternion / scalar operator
INTERFACE operator(/)
   MODULE PROCEDURE qdiv
END INTERFACE


CONTAINS
  
  ! =============================================================================
  ! =========================== UTSA ADDED FUNCTIONS ============================
  ! =============================================================================

  !> @brief      Get a starting time.
  !> @details    Get an object with time information.
  !> @return     returns the time with high precision
  !> @par        Code
  SUBROUTINE qmatUNFOLDmat(r,res,shapex,shapey)
    IMPLICIT NONE
         TYPE(otim2n2),    INTENT(IN)           :: r(:,:) 
            INTEGER,    INTENT(IN), OPTIONAL :: shapex 
            INTEGER,    INTENT(IN), OPTIONAL :: shapey
            INTEGER                          :: shapexi 
            INTEGER                          :: shapeyi
            INTEGER                          :: i, j
            INTEGER                          :: minx, miny
            INTEGER                          :: maxx
            INTEGER                          :: maxy
    REAL(REAL_KIND), INTENT(INOUT)           :: res(:,:)

    IF(PRESENT(shapex))THEN
      shapexi = shapex
    ELSE
      shapexi = size(r,1) 
      ! Check if size matches?
    END IF 

    IF(PRESENT(shapey))THEN
      shapeyi = shapey
    ELSE 
      shapeyi = size(r,2) 
      ! Check if size matches?
    END IF  

    !(1,1)
    i = 1
    j = 1
    minx = ((i-1)*shapexi) + 1
    maxx = (( i )*shapexi)
    miny = ((j-1)*shapeyi) + 1
    maxy = (( j )*shapeyi)
    res(minx:maxx,miny:maxy) = r%w

    !(1,2)
    i = 1
    j = 2
    minx = ((i-1)*shapexi) + 1
    maxx = (( i )*shapexi)
    miny = ((j-1)*shapeyi) + 1
    maxy = (( j )*shapeyi)
    res(minx:maxx,miny:maxy) = 0.0d0
    !(1,3)
    i = 1
    j = 3
    minx = ((i-1)*shapexi) + 1
    maxx = (( i )*shapexi)
    miny = ((j-1)*shapeyi) + 1
    maxy = (( j )*shapeyi)
    res(minx:maxx,miny:maxy) = 0.0d0

    !(2,1)
    i = 2
    j = 1
    minx = ((i-1)*shapexi) + 1
    maxx = (( i )*shapexi)
    miny = ((j-1)*shapeyi) + 1
    maxy = (( j )*shapeyi)
    res(minx:maxx,miny:maxy) = r%x
    !(2,2)
    i = 2
    j = 2
    minx = ((i-1)*shapexi) + 1
    maxx = (( i )*shapexi)
    miny = ((j-1)*shapeyi) + 1
    maxy = (( j )*shapeyi)
    res(minx:maxx,miny:maxy) = r%w
    !(2,3)
    i = 2
    j = 3
    minx = ((i-1)*shapexi) + 1
    maxx = (( i )*shapexi)
    miny = ((j-1)*shapeyi) + 1
    maxy = (( j )*shapeyi)
    res(minx:maxx,miny:maxy) = 0.0d0

    !(3,1)
    i = 3
    j = 1
    minx = ((i-1)*shapexi) + 1
    maxx = (( i )*shapexi)
    miny = ((j-1)*shapeyi) + 1
    maxy = (( j )*shapeyi)
    res(minx:maxx,miny:maxy) = r%y
    !(3,2)
    i = 3
    j = 2
    minx = ((i-1)*shapexi) + 1
    maxx = (( i )*shapexi)
    miny = ((j-1)*shapeyi) + 1
    maxy = (( j )*shapeyi)
    res(minx:maxx,miny:maxy) = 0.0d0
    !(3,3)
    i = 3
    j = 3
    minx = ((i-1)*shapexi) + 1
    maxx = (( i )*shapexi)
    miny = ((j-1)*shapeyi) + 1
    maxy = (( j )*shapeyi)
    res(minx:maxx,miny:maxy) = r%w
    
  END SUBROUTINE

  ! Unfold FULL vector form of matrix

  ! Unfold FULL matrix form of vector

  ! Unfold FULL vector form of vector
  

  ! Assignment operator = for OTI
  SUBROUTINE qASSIGNr(res,r)
    REAL(REAL_KIND), INTENT(IN) :: r 
    TYPE(otim2n2), INTENT(OUT)     :: RES

    res%w = r
    res%x = 0.0d0
    res%y = 0.0d0

  END SUBROUTINE

  ! Assignment operator = for OTI
  SUBROUTINE qASSIGNrvec(res,r)
    REAL(REAL_KIND), INTENT(IN) :: r(3) 
    TYPE(otim2n2), INTENT(OUT)     :: RES

    res%w = r(1)
    res%x = r(2)
    res%y = r(3)

  END SUBROUTINE

  ! ! Assignment operator = for OTI
  ! SUBROUTINE qmatASSIGNr(res,r)
  !   REAL(REAL_KIND), INTENT(IN) :: r()
  !   TYPE(otim2n2), INTENT(OUT)     :: RES

  !   res%w = r
  !   res%x = 0.0d0
  !   res%y = 0.0d0
  !   res%z = 0.0d0

  ! END SUBROUTINE

  FUNCTION qvecDOTqvec(q,p) RESULT(res)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN) :: q(:)
    TYPE(otim2n2),   INTENT(IN) :: p(:)
    TYPE(otim2n2)               :: res
    INTEGER :: i

    IF (size(p,1) /= size(q,1)) THEN
      STOP "Invalid shape for dot product of OTI vectors"
    END IF 

    res%w = 0.0d0
    res%x = 0.0d0
    res%y = 0.0d0

    DO i=1,size(q,1)

      res = res + q(i) * p(i)

    END DO

  END FUNCTION

  FUNCTION rvecDOTqvec(q,p) RESULT(res)
    IMPLICIT NONE
    REAL(8),   INTENT(IN)    :: q(:)
    TYPE(otim2n2),   INTENT(IN) :: p(:)
    TYPE(otim2n2)               :: res
    INTEGER :: i

    IF (size(p,1) /= size(q,1)) THEN
      STOP "Invalid shape for dot product of OTI vectors"
    END IF 

    res%w = 0.0d0
    res%x = 0.0d0
    res%y = 0.0d0

    DO i=1,size(q,1)

      res = res + q(i) * p(i)

    END DO
 
  END FUNCTION

  FUNCTION qvecDOTrvec(q,p) RESULT(res)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN) :: q(:)
    REAL(8),   INTENT(IN) :: p(:)
    TYPE(otim2n2)               :: res
    INTEGER :: i

    IF (size(p,1) /= size(q,1)) THEN
      STOP "Invalid shape for dot product of OTI vectors"
    END IF 

    res%w = 0.0d0
    res%x = 0.0d0
    res%y = 0.0d0

    DO i=1,size(q,1)

      res = res + q(i) * p(i)

    END DO


  END FUNCTION


  FUNCTION qmatNeg(q) RESULT(res)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    TYPE(otim2n2)               :: res(SIZE(q,1),SIZE(q,2))

    res%w = -q%w
    res%x = -q%x
    res%y = -q%y

  END FUNCTION

  FUNCTION qvecNeg(q) RESULT(res)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN) :: q(:)
    TYPE(otim2n2)               :: res(SIZE(q,1))

    res%w = -q%w
    res%x = -q%x
    res%y = -q%y

  END FUNCTION

  ! Divide a OTI matrix by real
  ! coefficient
  FUNCTION qmatDr(q,r) RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    REAL(8),   INTENT(IN)    :: r
    TYPE(otim2n2)               :: res(SIZE(q,1),SIZE(q,2))
   
    res%w = q%w/r
    res%x = q%x/r
    res%y = q%y/r

  END FUNCTION

  FUNCTION qvecDr(q,r) RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:)
    REAL(8),   INTENT(IN)    :: r
    TYPE(otim2n2)               :: res(SIZE(q,1))

    res%w = q%w/r
    res%x = q%x/r
    res%y = q%y/r

  END FUNCTION


  ! Mutliply OTI vector with OTI number
  FUNCTION qmatXqmat_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    TYPE(otim2n2),   INTENT(IN) :: p(:,:)
    TYPE(otim2n2)               :: res(SIZE(q,1),SIZE(q,2))

    IF((SIZE(q,1)/= SIZE(p,1)).or.((SIZE(q,2)/= SIZE(p,2))))THEN
      STOP "Invalid shape for elementwise matrix multiplication"
    END IF 

    res%w = q%w*p%w
    res%x = q%w*p%x+q%x*p%w
    res%y = q%w*p%y+q%y*p%w

  END FUNCTION


  ! Mutliply OTI vector with OTI number
  FUNCTION qmatXrmat_proc(p,q) RESULT(res)
    IMPLICIT NONE 
    REAL(8),      INTENT(IN) :: q(:,:)
    TYPE(otim2n2),   INTENT(IN) :: p(:,:)
    TYPE(otim2n2)               :: res(SIZE(q,1),SIZE(q,2))

    IF ((SIZE(q,1)/= SIZE(p,1)).or.((SIZE(q,2)/= SIZE(p,2))) ) THEN
      STOP "Invalid shape for elementwise matrix multiplication"
    END IF 

    res%w = q*p%w
    res%x = q*p%x
    res%y = q*p%y

  END FUNCTION


  ! Mutliply OTI vector with OTI number
  FUNCTION rmatXqmat_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    REAL(8),      INTENT(IN) :: q(:,:)
    TYPE(otim2n2),   INTENT(IN) :: p(:,:)
    TYPE(otim2n2)               :: res(SIZE(q,1),SIZE(q,2))

    IF((SIZE(q,1)/= SIZE(p,1)).or.((SIZE(q,2)/= SIZE(p,2))))THEN
      STOP "Invalid shape for elementwise matrix multiplication"
    END IF 

    res%w = q*p%w
    res%x = q*p%x
    res%y = q*p%y

  END FUNCTION

  ! Mutliply OTI vector with OTI number
  FUNCTION qvecXqvec_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:)
    TYPE(otim2n2),   INTENT(IN) :: p(:)
    TYPE(otim2n2)               :: res(SIZE(q,1))

    IF(SIZE(q,1)/= SIZE(p,1))THEN
      STOP "Invalid shape for elementwise vector multiplication"
    END IF 

    res%w = q%w*p%w
    res%x = q%w*p%x+q%x*p%w
    res%y = q%w*p%y+q%y*p%w

  END FUNCTION


  ! Mutliply OTI vector with OTI number
  FUNCTION qvecXrvec_proc(p,q) RESULT(res)
    IMPLICIT NONE 
    REAL(8),      INTENT(IN) :: q(:)
    TYPE(otim2n2),   INTENT(IN) :: p(:)
    TYPE(otim2n2)               :: res(SIZE(q,1))

    IF(SIZE(q,1)/= SIZE(p,1))THEN
      STOP "Invalid shape for elementwise vector multiplication"
    END IF 

    res%w = q*p%w
    res%x = q*p%x
    res%y = q*p%y

  END FUNCTION


  ! Mutliply OTI vector with OTI number
  FUNCTION rvecXqvec_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    REAL(8),      INTENT(IN) :: q(:)
    TYPE(otim2n2),   INTENT(IN) :: p(:)
    TYPE(otim2n2)               :: res(SIZE(q,1))

    IF(SIZE(q,1)/= SIZE(p,1))THEN
      STOP "Invalid shape for elementwise vector multiplication"
    END IF 

    res%w = q*p%w
    res%x = q*p%x
    res%y = q*p%y

  END FUNCTION


  ! Mutliply OTI matrix with OTI number
  FUNCTION qmatXq_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    TYPE(otim2n2),   INTENT(IN) :: p
    TYPE(otim2n2)               :: res(SIZE(q,1),SIZE(q,2))

    res%w = q%w*p%w
    res%x = q%w*p%x+q%x*p%w
    res%y = q%w*p%y+q%y*p%w

  END FUNCTION

  ! Mutliply OTI vector with OTI number
  FUNCTION qvecXq_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:)
    TYPE(otim2n2),   INTENT(IN) :: p
    TYPE(otim2n2)               :: res(SIZE(q,1))

    res%w = q%w*p%w
    res%x = q%w*p%x+q%x*p%w
    res%y = q%w*p%y+q%y*p%w

  END FUNCTION

  ! Mutliply OTI number with OTI matrix 
  FUNCTION qXqmat_proc(p,q) RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: p
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    TYPE(otim2n2)               :: res(SIZE(q,1),SIZE(q,2))

    res%w = p%w*q%w
    res%x = p%w*q%x+p%x*q%w
    res%y = p%w*q%y+p%y*q%w

  END FUNCTION

  ! Mutliply OTI number with OTI vector 
  FUNCTION qXqvec_proc(p,q) RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: p
    TYPE(otim2n2),   INTENT(IN) :: q(:)
    TYPE(otim2n2)               :: res(SIZE(q,1))

    res%w = p%w*q%w
    res%x = p%w*q%x+p%x*q%w
    res%y = p%w*q%y+p%y*q%w

  END FUNCTION

  ! Mutliply real number with OTI matrix 
  FUNCTION rXqmat_proc(r,q) RESULT(res)
    IMPLICIT NONE 
    REAL(8),   INTENT(IN)    :: r
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    TYPE(otim2n2)               :: res(SIZE(q,1),SIZE(q,2))
    
    res%w = q%w * r
    res%x = q%x * r
    res%y = q%y * r

  END FUNCTION

  ! Mutliply real number with OTI vector 
  FUNCTION rXqvec_proc(r,q) RESULT(res)
    IMPLICIT NONE 
    REAL(8),   INTENT(IN)    :: r
    TYPE(otim2n2),   INTENT(IN) :: q(:)
    TYPE(otim2n2)               :: res(SIZE(q,1))
    
    res%w = q%w * r
    res%x = q%x * r
    res%y = q%y * r

  END FUNCTION

  ! Mutliply OTI matrix with real number
  FUNCTION qmatXr_proc(q,r) RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    REAL(8),   INTENT(IN)    :: r
    TYPE(otim2n2)               :: res(SIZE(q,1),SIZE(q,2))
    
    res%w = q%w * r
    res%x = q%x * r
    res%y = q%y * r

  END FUNCTION

  ! Mutliply OTI matrix with real number
  FUNCTION qvecXr_proc(q,r) RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:)
    REAL(8),   INTENT(IN)    :: r
    TYPE(otim2n2)               :: res(SIZE(q,1))
    
    res%w = q%w * r
    res%x = q%x * r
    res%y = q%y * r

  END FUNCTION


  FUNCTION QvecFold_multiple_src(Wmat, Xmat, Ymat) RESULT(res)
    IMPLICIT NONE
    REAL(KIND=8),   INTENT(IN)  :: Wmat(:)
    REAL(KIND=8),   INTENT(IN)  :: Xmat(:)
    REAL(KIND=8),   INTENT(IN)  :: Ymat(:)
    TYPE(otim2n2)                  :: res(SIZE(Wmat,1))
 
    res%w = Wmat
    res%x = Xmat
    res%y = Ymat

  END FUNCTION


  FUNCTION QmatFold_multiple_src(Wmat, Xmat, Ymat) RESULT(res)
    IMPLICIT NONE
    REAL(KIND=8),   INTENT(IN)  :: Wmat(:,:)
    REAL(KIND=8),   INTENT(IN)  :: Xmat(:,:)
    REAL(KIND=8),   INTENT(IN)  :: Ymat(:,:)
    TYPE(otim2n2)                  :: res(SIZE(Wmat,1),SIZE(Wmat,2))
 
    res%w = Wmat
    res%x = Xmat
    res%y = Ymat

  END FUNCTION


  SUBROUTINE QmatFold(Wmat, Xmat, Ymat, res)
    IMPLICIT NONE
    REAL(KIND=8),   INTENT(IN)  :: Wmat(:)
    REAL(KIND=8),   INTENT(IN)  :: Xmat(:)
    REAL(KIND=8),   INTENT(IN)  :: Ymat(:)
    TYPE(otim2n2), ALLOCATABLE, INTENT(INOUT):: res(:,:)
    TYPE(otim2n2)                :: tmp
    INTEGER :: i, sizew, sizex, sizey, sizez
    

    sizew = SIZE(Wmat,1)
    sizex = SIZE(Xmat,1)
    sizey = SIZE(Ymat,1)

    IF (ALLOCATED(res)) DEALLOCATE( res)
    
    ALLOCATE(res(sizew,1))

    DO i = 1,sizew
      tmp%w = Wmat(i)
      tmp%x = Xmat(i)
      tmp%y = Ymat(i)

      res(i,1) = tmp

    END DO

  END SUBROUTINE



  ! Sum two OTI matrices
  FUNCTION rmatMqmat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q(:,:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      
      IF ((size(p,1) /= size(q,1)).or.(size(p,2) /= size(q,2))) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 

      res%x = -p%x
      res%y = -p%y

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q(i,j) - p(i,j)%w
          
          
        END DO
      END DO

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION rMqmat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      
      res%x = -p%x
      res%y = -p%y

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q - p(i,j)%w
          
          
        END DO
      END DO

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qMqmat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(otim2n2),   INTENT(IN)  :: q
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q%w - p(i,j)%w
          res(i,j)%x = q%x - p(i,j)%x
          res(i,j)%y = q%y - p(i,j)%y

        END DO
      END DO

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qmatMrmat(p,q)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q(:,:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      
      IF ((size(p,1) /= size(q,1)).or.(size(p,2) /= size(q,2))) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 

      res%w = p%w - q
      res%x = p%x
      res%y = p%y

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qmatMr(p,q)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      
      res%x = p%x
      res%y = p%y

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w =  p(i,j)%w - q
          
          
        END DO
      END DO

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qmatMq(p,q)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(otim2n2),   INTENT(IN)  :: q
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = p(i,j)%w - q%w
          res(i,j)%x = p(i,j)%x - q%x
          res(i,j)%y = p(i,j)%y - q%y

        END DO
      END DO

  END FUNCTION

  ! SUBTRACTION of two OTI matrices
  FUNCTION qmatMqmat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(otim2n2),   INTENT(IN)  :: q(:,:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(q,1),size(q,2))
      INTEGER sizeqx, sizeqy, sizepx, sizepy

      sizeqx = size(q,1)
      sizeqy = size(q,2)
      sizepx = size(p,1)
      sizepy = size(p,2)

      IF ((sizeqx /= sizepx).or.(sizeqy /= sizepy)) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 
      
      res%w = q%w - p%w
      res%x = q%x - p%x
      res%y = q%y - p%y

  END FUNCTION


  ! SUBTRACTION of two OTI matrices
  FUNCTION qvecMqvec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(otim2n2),   INTENT(IN)  :: q(:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:)
      TYPE(otim2n2)                :: res(size(q,1))
      INTEGER sizeqx, sizepx

      sizeqx = size(q,1)
      sizepx = size(p,1)

      IF ((sizeqx /= sizepx)) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 
      
      res%w = q%w - p%w
      res%x = q%x - p%x
      res%y = q%y - p%y

  END FUNCTION

  FUNCTION qvecMrvec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(otim2n2),   INTENT(IN)  :: q(:)
      REAL(8),      INTENT(IN)  :: p(:)
      TYPE(otim2n2)                :: res(size(q,1))
      INTEGER sizeqx, sizepx

      sizeqx = size(q,1)
      sizepx = size(p,1)

      IF ((sizeqx /= sizepx)) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 
      
      res%w = q%w - p
      res%x = q%x
      res%y = q%y

  END FUNCTION

  FUNCTION rvecMqvec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q(:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:)
      TYPE(otim2n2)                :: res(size(q,1))
      INTEGER sizeqx, sizepx

      sizeqx = size(q,1)
      sizepx = size(p,1)

      IF ((sizeqx /= sizepx)) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 
      
      res%w = q - p%w
      res%x =   - p%x
      res%y =   - p%y

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION rvecPqvec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q(:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:)
      TYPE(otim2n2)                :: res(size(p,1))
      
      IF ((size(p,1) /= size(q,1))) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 

      res%w = q + p%w
      res%x = p%x
      res%y = p%y

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qvecPrvec(p,q)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q(:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:)
      TYPE(otim2n2)                :: res(size(p,1))
      
      IF ((size(p,1) /= size(q,1))) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 

      res%w = q + p%w
      res%x = p%x
      res%y = p%y

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qvecPqvec(p,q)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(otim2n2),   INTENT(IN)  :: q(:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:)
      TYPE(otim2n2)                :: res(size(p,1))
      
      IF ((size(p,1) /= size(q,1))) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 

      
      res%w = q%w+p%w
      res%x = q%x+p%x
      res%y = q%y+p%y

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION rmatPqmat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q(:,:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      
      IF ((size(p,1) /= size(q,1)).or.(size(p,2) /= size(q,2))) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 
      res%w = q + p%w
      res%x = p%x
      res%y = p%y

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION rPqvec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q
      TYPE(otim2n2),   INTENT(IN)  :: p(:)
      TYPE(otim2n2)                :: res(size(p,1))
      
      res%w = q + p%w
      res%x = p%x
      res%y = p%y

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION rPqmat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      
      res%w = q + p%w
      res%x = p%x
      res%y = p%y

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qPqvec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(otim2n2),   INTENT(IN)  :: q
      TYPE(otim2n2),   INTENT(IN)  :: p(:)
      TYPE(otim2n2)                :: res(size(p,1))
      INTEGER                   :: i
      

      DO i=1,size(p,1)

          res(i)%w = q%w + p(i)%w
          res(i)%x = q%x + p(i)%x
          res(i)%y = q%y + p(i)%y

      END DO

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qPqmat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(otim2n2),   INTENT(IN)  :: q
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q%w + p(i,j)%w
          res(i,j)%x = q%x + p(i,j)%x
          res(i,j)%y = q%y + p(i,j)%y

        END DO
      END DO

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qmatPrmat(p,q)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q(:,:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      
      IF ((size(p,1) /= size(q,1)).or.(size(p,2) /= size(q,2))) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 

      res%x = p%x
      res%y = p%y

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q(i,j) + p(i,j)%w
          
          
        END DO
      END DO

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qmatPr(p,q)&
      RESULT(res)
      IMPLICIT NONE
      REAL(8),   INTENT(IN)     :: q
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      
      res%x = p%x
      res%y = p%y

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q + p(i,j)%w
          
        END DO
      END DO

  END FUNCTION

  ! Sum two OTI matrices
  FUNCTION qmatPq(p,q)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(otim2n2),   INTENT(IN)  :: q
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q%w + p(i,j)%w
          res(i,j)%x = q%x + p(i,j)%x
          res(i,j)%y = q%y + p(i,j)%y

        END DO
      END DO

  END FUNCTION


  ! Sum two OTI matrices
  FUNCTION qmatPqmat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(otim2n2),   INTENT(IN)  :: q(:,:)
      TYPE(otim2n2),   INTENT(IN)  :: p(:,:)
      TYPE(otim2n2)                :: res(size(q,1),size(q,2))
      INTEGER sizeqx, sizeqy, sizepx, sizepy

      sizeqx = size(q,1)
      sizeqy = size(q,2)
      sizepx = size(p,1)
      sizepy = size(p,2)

      IF ((sizeqx /= sizepx).or.(sizeqy /= sizepy)) THEN
        STOP "Invalid shape for adding OTI matrices"
      END IF 

      res%w = q%w + p%w
      res%x = q%x + p%x
      res%y = q%y + p%y

  END FUNCTION



  SUBROUTINE qmatTrans(q,qtrans)!&
    ! RESULT(res)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN)  :: q(:,:)
    TYPE(otim2n2),ALLOCATABLE, INTENT(INOUT) :: qtrans(:,:)
    INTEGER :: i, j, sizeqx, sizeqy
    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)

    IF (ALLOCATED(qtrans)) DEALLOCATE( qtrans)
    ! print*,'trans'
    
    ALLOCATE(qtrans(sizeqy,sizeqx))

    DO i=1,sizeqx
      DO j=1,sizeqy
        qtrans(j,i)= q(i,j)
      END DO
    END DO
    ! print*,'trans'


  END SUBROUTINE


  SUBROUTINE TRANSPOSE_SUB(q,qtrans)!&
    ! RESULT(res)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN)  :: q(:,:)
    TYPE(otim2n2),INTENT(INOUT)  :: qtrans(:,:)
    INTEGER :: i, j,sizeqx ,sizeqy 
    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)

    DO i=1,sizeqx
      DO j=1,sizeqy
        qtrans(j,i)= q(i,j)
      END DO
    END DO

    ! qtrans%w = TRANSPOSE(q%w)
    ! qtrans%x = TRANSPOSE(q%x)
    ! qtrans%y = TRANSPOSE(q%y)
    ! qtrans%z = TRANSPOSE(q%z)
    ! print*,'trans'


  END SUBROUTINE

  FUNCTION qmatTrans_proc(q)&
    RESULT(qtrans)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN)  :: q(:,:)
    TYPE(otim2n2)     :: qtrans(SIZE(q,2),SIZE(q,1))
    INTEGER :: i, j, sizeqx, sizeqy
    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)

    DO i=1,sizeqx
      DO j=1,sizeqy
        qtrans(j,i)= q(i,j)
      END DO
    END DO

  END FUNCTION

  FUNCTION qmatTrans_proc2(q)&
    RESULT(qtrans)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN)  :: q(:,:)
    TYPE(otim2n2)     :: qtrans(SIZE(q,2),SIZE(q,1))
    INTEGER :: i, j, sizeqx, sizeqy
    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)

    qtrans%w = TRANSPOSE(q%w)
    qtrans%x = TRANSPOSE(q%x) 
    qtrans%y = TRANSPOSE(q%y) 

    ! DO i=1,sizeqx
    !   DO j=1,sizeqy
    !     qtrans(j,i)= q(i,j)
    !   END DO
    ! END DO

  END FUNCTION


  SUBROUTINE qmat2rmats(q, res)
      ! RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN)  :: q(:,:)
    REAL(kind=8), ALLOCATABLE :: res(:,:,:)
    TYPE(otim2n2)                :: qtemp
    
    INTEGER sizeqx, sizeqy, i, j, k

    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)

    IF (ALLOCATED(res )) DEALLOCATE( res )

    ALLOCATE( res(sizeqx, sizeqy, NUM_IM_DIR), stat=k )

    ! print *, k
    
    DO i = 1, sizeqx

      DO j = 1, sizeqy
        
        qtemp = q(i,j)
        res(i,j,1) = qtemp%w
        res(i,j,2) = qtemp%x
        res(i,j,3) = qtemp%y

      END DO

    END DO

  END SUBROUTINE


  SUBROUTINE quatXqmat(p,q, res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    TYPE(otim2n2), ALLOCATABLE, INTENT(INOUT)  :: res(:,:)
    TYPE(otim2n2)               :: qtemp
    TYPE(otim2n2), INTENT(IN)   :: p
    INTEGER sizeqx, sizeqy, i, j

    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)
    
    
    ALLOCATE( res(sizeqx ,sizeqy) )
    ! print *, res
    DO i = 1, sizeqx

      DO j = 1, sizeqy

        qtemp = p * q(i,j)
        
        res(i,j) = qtemp

      END DO

    END DO

  END SUBROUTINE

  SUBROUTINE rXqmat(r,q, res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    TYPE(otim2n2), ALLOCATABLE, INTENT(INOUT)  :: res(:,:)
    TYPE(otim2n2)               :: qtemp
    REAL(KIND=8), INTENT(IN) :: r
    INTEGER sizeqx, sizeqy, i, j

    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)
    
    
    ALLOCATE( res(sizeqx ,sizeqy) )
    ! print *, res
    DO i = 1, sizeqx

      DO j = 1, sizeqy
      
        qtemp%w = r     ! Real part
        qtemp%x = 0.0_8 ! Im i
        qtemp%y = 0.0_8 ! Im j

        qtemp = qtemp * q(i,j)
        
        res(i,j) = qtemp

      END DO

    END DO

  END SUBROUTINE


  FUNCTION qmatXrmat(r,q)&
      RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: r(:,:)
    REAL(KIND=8), INTENT(IN) :: q(:,:)
    TYPE(otim2n2)               :: res(SIZE(r,1),SIZE(q,2))
    TYPE(otim2n2)               :: qtemp
    INTEGER sizeqx, sizeqy, sizerx, sizery, i, j, k

    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)
    sizerx = SIZE(r,1)
    sizery = SIZE(r,2)

    ! print *, "size of q: ", sizeqx, sizeqy 
    ! print *, "size of r: ", sizerx, sizery 

    IF (sizery /= sizeqx) THEN
      STOP "Runtime error: " // &
        "dimension of array B incorrect in Matrix Multiplication."
    END IF
    

    DO i = 1, sizerx

      DO j = 1, sizeqy
      
        qtemp%w = 0.0_8 ! Real part
        qtemp%x = 0.0_8 ! Im i
        qtemp%y = 0.0_8 ! Im j

        DO k = 1, sizery

          qtemp = qtemp + q(k,j) * r(i,k)

        END DO
        
        res(i,j) = qtemp

      END DO

    END DO

  END FUNCTION


  FUNCTION rmatXqmat(r,q)&
      RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    REAL(KIND=8), INTENT(IN) :: r(:,:)
    TYPE(otim2n2)               :: res(SIZE(r,1),SIZE(q,2))
    TYPE(otim2n2)               :: qtemp
    INTEGER sizeqx, sizeqy, sizerx, sizery, i, j, k

    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)
    sizerx = SIZE(r,1)
    sizery = SIZE(r,2)

    ! print *, "size of q: ", sizeqx, sizeqy 
    ! print *, "size of r: ", sizerx, sizery 

    IF (sizery /= sizeqx) THEN
      STOP "Runtime error: " // &
        "dimension of array B incorrect in Matrix Multiplication."
    END IF
    
    
    ! ALLOCATE( res(sizeqx ,sizery) )
    ! print *, res
    DO i = 1, sizerx

      DO j = 1, sizeqy
      
        qtemp%w = 0.0_8 ! Real part
        qtemp%x = 0.0_8 ! Im i
        qtemp%y = 0.0_8 ! Im j

        DO k = 1, sizery

          qtemp = qtemp + q(k,j) * r(i,k)

        END DO
        
        res(i,j) = qtemp

      END DO

    END DO

  END FUNCTION


  SUBROUTINE QPrint(q,fmt)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN) :: q
    CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:),ALLOCATABLE :: output_format


    IF (PRESENT(fmt)) THEN
      output_format = '('//trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//')'
    ELSE
      output_format = '(F8.3,F8.3,F8.3)'
    END IF 


    write(*,output_format), &
      q%w,        &
      q%x,        &
      q%y

  END SUBROUTINE

  SUBROUTINE RPrint(q,fmt)
    IMPLICIT NONE
    REAL(8),   INTENT(IN) :: q
    CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:),ALLOCATABLE :: output_format

    IF (PRESENT(fmt)) THEN
      output_format = '('//trim(fmt)//')'
    ELSE
      output_format = '(F8.3)'
    END IF 

    write(*,output_format), &
      q       

  END SUBROUTINE


  SUBROUTINE QmatPrint(q,fmt)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:),ALLOCATABLE :: output_format
    INTEGER  i, j

    IF (PRESENT(fmt)) THEN
      output_format = '(A,I4,A,I4,A,'//trim(fmt)//','// &
                                       trim(fmt)//','// &
                                       trim(fmt)//')'
    ELSE
      output_format = '(A,I4,A,I4,A,F8.3,F8.3,F8.3)'
    END IF 

    DO i=1,SIZE(q,1)
      DO j=1,SIZE(q,2)
        
        write(*,output_format), &
          '(',i,',',j,')', &
          q(i,j)%w,        &
          q(i,j)%x,        &
          q(i,j)%y

      END DO
    END DO

  END SUBROUTINE

  SUBROUTINE RmatPrint(q,fmt)
    IMPLICIT NONE
    REAL(8),   INTENT(IN) :: q(:,:)
    CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:),ALLOCATABLE :: output_format
    INTEGER  i, j

    IF (PRESENT(fmt)) THEN
      output_format = '(A,I4,A,I4,A,'//trim(fmt)//')'
    ELSE
      output_format = '(A,I4,A,I4,A,F8.3)'
    END IF 

    DO i=1,SIZE(q,1)
      DO j=1,SIZE(q,2)
        
        write(*,output_format), &
          '(',i,',',j,')', &
          q(i,j)

      END DO
    END DO

  END SUBROUTINE


  SUBROUTINE QvecPrint(q,fmt)
    IMPLICIT NONE
    TYPE(otim2n2),   INTENT(IN) :: q(:)
    CHARACTER(len=*),  INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:),ALLOCATABLE :: output_format
    INTEGER  i


    IF (PRESENT(fmt)) THEN
      output_format = '(A,I4,A,'//trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//')'
    ELSE
      output_format = '(A,I4,A,F8.3,F8.3,F8.3)'
    END IF 

    DO i=1,SIZE(q,1)
        
        write(*,output_format), &
          '(',i,')', &
          q(i)%w,        &
          q(i)%x,        &
          q(i)%y

    END DO

  END SUBROUTINE

  SUBROUTINE RvecPrint(q, fmt)
    IMPLICIT NONE
    REAL(8),   INTENT(IN) :: q(:)
    CHARACTER(len=*),  INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:),ALLOCATABLE :: output_format
    INTEGER  i

    IF (PRESENT(fmt)) THEN
      output_format = '(A,I4,A,'//trim(fmt)//')'
    ELSE
      output_format = '(A,I4,A,F8.3)'
    END IF  

    DO i=1,SIZE(q,1)
        
        write(*,output_format), &
          '(',i,')', &
          q(i)

    END DO

  END SUBROUTINE


  SUBROUTINE qmatXqmat_sub_rr(r,q,tr,tq,alpha,beta,res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN)     :: q(:,:)
    TYPE(otim2n2)                   :: qtemp
    TYPE(otim2n2),   INTENT(IN)     :: r(:,:)
    TYPE(otim2n2),   INTENT(INOUT)  :: res(:,:)
    CHARACTER(len=1), INTENT(IN) :: tr, tq
    INTEGER                      :: qTflag,rTflag ! Transpose flags.
    REAL(REAL_KIND), INTENT(IN)  :: alpha, beta
    INTEGER sizeqx, sizeqy, sizerx, sizery, i, j, k, ii, jj, kk

    

    IF (tr == 'T') THEN
      sizerx = SIZE(r,2)
      sizery = SIZE(r,1)
      rTflag = 1
    ELSE 
      sizerx = SIZE(r,1)
      sizery = SIZE(r,2)
      rTflag = 0
    END IF 

    IF (tq == 'T') THEN
      sizeqx = SIZE(q,2)
      sizeqy = SIZE(q,1)
      qTflag = 1
    ELSE 
      sizeqx = SIZE(q,1)
      sizeqy = SIZE(q,2)
      qTflag = 0
    END IF 
    
    IF (sizery /= sizeqx) THEN
      STOP "Runtime error: " // &
        "Incorrect dimension of arrays A and B. MATMUL QmatQmat."
    END IF

    IF ( (SIZE(res,1) /= sizerx).or.(SIZE(res,2) /= sizeqy) ) THEN
      STOP "Runtime error: " // &
        "Incorrect dimension of result array. MATMUL QmatQmat."
    END IF

    IF ((rTflag == 0) .and.( qTflag == 0 )) THEN
    
      DO i = 1, sizerx
        DO j = 1, sizeqy
        
          qtemp = 0.0d0 

          DO k = 1, sizery

            qtemp = qtemp + r(i,k) * q(k,j)

          END DO

          res(i,j) = alpha*qtemp + beta*res(i,j)

        END DO
      END DO

    ELSE IF ((rTflag == 1) .and.( qTflag == 0 )) THEN

      DO i = 1, sizerx
        DO j = 1, sizeqy
        
          qtemp = 0.0d0 

          DO k = 1, sizery

            qtemp = qtemp + r(k,i) * q(k,j)

          END DO

          res(i,j) = alpha*qtemp + beta*res(i,j)

        END DO
      END DO

    ELSE IF ((rTflag == 0) .and.( qTflag == 1 )) THEN

      DO i = 1, sizerx
        DO j = 1, sizeqy
        
          qtemp = 0.0d0 

          DO k = 1, sizery

            qtemp = qtemp + r(i,k) * q(j,k)

          END DO

          res(i,j) = alpha*qtemp + beta*res(i,j)

        END DO
      END DO

    ELSE IF ((rTflag == 1) .and.( qTflag == 1 )) THEN

      DO i = 1, sizerx
        DO j = 1, sizeqy
        
          qtemp = 0.0d0 

          DO k = 1, sizery

            qtemp = qtemp + r(k,i) * q(j,k)

          END DO

          res(i,j) = alpha*qtemp + beta*res(i,j)

        END DO
      END DO

    END IF

  END SUBROUTINE

  SUBROUTINE qmatXqmat_sub_qq(r,q,tr,tq,alpha,beta,res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN)     :: q(:,:)
    TYPE(otim2n2)                   :: qtemp
    TYPE(otim2n2),   INTENT(IN)     :: r(:,:)
    TYPE(otim2n2),   INTENT(INOUT)  :: res(:,:)
    CHARACTER(len=1), INTENT(IN) :: tr, tq
    INTEGER                      :: qTflag,rTflag ! Transpose flags.
    TYPE(otim2n2),   INTENT(IN)     :: alpha, beta
    INTEGER sizeqx, sizeqy, sizerx, sizery, i, j, k, ii, jj, kk

    

    IF (tr == 'T') THEN
      sizerx = SIZE(r,2)
      sizery = SIZE(r,1)
      rTflag = 1
    ELSE 
      sizerx = SIZE(r,1)
      sizery = SIZE(r,2)
      rTflag = 0
    END IF 

    IF (tq == 'T') THEN
      sizerx = SIZE(q,2)
      sizery = SIZE(q,1)
      qTflag = 1
    ELSE 
      sizeqx = SIZE(q,1)
      sizeqy = SIZE(q,2)
      qTflag = 0
    END IF 
    
    IF (sizery /= sizeqx) THEN
      STOP "Runtime error: " // &
        "Incorrect dimension of arrays A and B. MATMUL QmatQmat."
    END IF

    IF ( (SIZE(res,1) /= sizerx).or.(SIZE(res,2) /= sizeqy) ) THEN
      STOP "Runtime error: " // &
        "Incorrect dimension of result array. MATMUL QmatQmat."
    END IF

    IF ((rTflag == 0) .and.( qTflag == 0 )) THEN
    
      DO i = 1, sizerx
        DO j = 1, sizeqy
        
          qtemp = 0.0d0 

          DO k = 1, sizery

            qtemp = qtemp + r(i,k) * q(k,j)

          END DO

          res(i,j) = alpha*qtemp + beta*res(i,j)

        END DO
      END DO

    ELSE IF ((rTflag == 1) .and.( qTflag == 0 )) THEN

      DO i = 1, sizerx
        DO j = 1, sizeqy
        
          qtemp = 0.0d0 

          DO k = 1, sizery

            qtemp = qtemp + r(k,i) * q(k,j)

          END DO

          res(i,j) = alpha*qtemp + beta*res(i,j)

        END DO
      END DO

    ELSE IF ((rTflag == 0) .and.( qTflag == 1 )) THEN

      DO i = 1, sizerx
        DO j = 1, sizeqy
        
          qtemp = 0.0d0 

          DO k = 1, sizery

            qtemp = qtemp + r(i,k) * q(j,k)

          END DO

          res(i,j) = alpha*qtemp + beta*res(i,j)

        END DO
      END DO

    ELSE IF ((rTflag == 1) .and.( qTflag == 1 )) THEN

      DO i = 1, sizerx
        DO j = 1, sizeqy
        
          qtemp = 0.0d0 

          DO k = 1, sizery

            qtemp = qtemp + r(k,i) * q(j,k)

          END DO

          res(i,j) = alpha*qtemp + beta*res(i,j)

        END DO
      END DO

    END IF

  END SUBROUTINE


  FUNCTION qmatXqmat(r,q)&
      RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    TYPE(otim2n2)               :: qtemp
    TYPE(otim2n2),   INTENT(IN) :: r(:,:)
    TYPE(otim2n2)               :: res(SIZE(r,1),SIZE(q,2))
    INTEGER sizeqx, sizeqy, sizerx, sizery, i, j, k

    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)

    sizerx = SIZE(r,1)
    sizery = SIZE(r,2)
    
    
    
    IF (sizery /= sizeqx) THEN
      STOP "Runtime error: " // &
        "dimension of array B incorrect in matmul interface."
    END IF

    
    DO i = 1, sizerx

      DO j = 1, sizeqy
      
        qtemp%w = 0.0_8 ! Real part
        qtemp%x = 0.0_8 ! Im i
        qtemp%y = 0.0_8 ! Im j

        DO k = 1, sizery

          qtemp = qtemp + r(i,k) * q(k,j) 

        END DO

        res(i,j) = qtemp

      END DO

    END DO

  END FUNCTION

  FUNCTION qmatXqmat2(r,q)&
      RESULT(res)
    IMPLICIT NONE 
    TYPE(otim2n2),   INTENT(IN) :: q(:,:)
    TYPE(otim2n2)               :: qtemp
    TYPE(otim2n2),   INTENT(IN) :: r(:,:)
    TYPE(otim2n2)               :: res(SIZE(r,1),SIZE(q,2))
    INTEGER sizeqx, sizeqy, sizerx, sizery, i, j, k

    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)

    sizerx = SIZE(r,1)
    sizery = SIZE(r,2)
    
    
    
    IF (sizery /= sizeqx) THEN
      STOP "Runtime error: " // &
        "dimension of array B incorrect in matmul interface."
    END IF

    res%w = MATMUL(r%w,q%w)
    res%x = MATMUL(r%w,q%x)+MATMUL(r%x,q%w)
    res%y = MATMUL(r%w,q%y)+MATMUL(r%y,q%w)

    
    ! DO i = 1, sizerx

    !   DO j = 1, sizeqy
      
    !     qtemp%w = 0.0_8 ! Real part
    !     qtemp%x = 0.0_8 ! Im i
    !     qtemp%y = 0.0_8 ! Im j

    !     DO k = 1, sizery

    !       qtemp = qtemp + r(i,k) * q(k,j) 

    !     END DO

    !     res(i,j) = qtemp

    !   END DO

    ! END DO

  END FUNCTION

  ! Returns the power of a quarternion :math:`\mathbf{q}^n`
  ! component-wise
  ! *q a OTI
  ! *n an integer scalar
  ! *qn q/r
  FUNCTION qpow(q,n) &
       RESULT(qn)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: n
    INTEGER :: i
    TYPE(otim2n2), INTENT(IN) :: q
    TYPE(otim2n2) :: qn
    
    qn%w = 1.0_8
    qn%x = 0.0_8
    qn%y = 0.0_8

    DO i=1,n
      qn = qn*q
    END DO

  END FUNCTION qpow

  ! Returns the quarternion :math:`\mathbf{q}` added by scalar :math:`r`
  ! component-wise
  ! *q a OTI
  ! *r a real scalar
  ! *qn q+r
  FUNCTION qplus(q,r) &
       RESULT(qn)
    IMPLICIT NONE
    double precision, INTENT(IN) :: r
    TYPE(otim2n2), INTENT(IN) :: q
    TYPE(otim2n2) :: qn

    qn%w=q%w+r
    qn%x=q%x
    qn%y=q%y

  END FUNCTION qplus

  ! Returns the quarternion :math:`\mathbf{q}` subtracted by scalar :math:`r`
  ! component-wise
  ! *q a OTI
  ! *r a real scalar
  ! *qn q-r
  FUNCTION qminus(q,r) &
       RESULT(qn)
    IMPLICIT NONE
    double precision, INTENT(IN) :: r
    TYPE(otim2n2), INTENT(IN) :: q
    TYPE(otim2n2) :: qn

    qn%w=q%w-r
    qn%x=q%x
    qn%y=q%y

  END FUNCTION qminus

  FUNCTION qneg(q) RESULT(res)
    IMPLICIT NONE
    TYPE(otim2n2), INTENT(IN) :: q
    TYPE(otim2n2)             :: res

    res%w = -q%w
    res%x = -q%x
    res%y = -q%y

  END FUNCTION

  ! Returns the quarternion :math:`\mathbf{q}` added by scalar :math:`r`
  ! component-wise
  ! *q a OTI
  ! *r a real scalar
  ! *qn q+r
  FUNCTION qplusB(r,q) &
       RESULT(qn)
    IMPLICIT NONE
    double precision, INTENT(IN) :: r
    TYPE(otim2n2), INTENT(IN) :: q
    TYPE(otim2n2) :: qn

    qn%w=q%w+r
    qn%x=q%x
    qn%y=q%y

  END FUNCTION qplusB

  ! Returns the quarternion :math:`\mathbf{q}` subtracted by scalar :math:`r`
  ! component-wise
  ! *q a OTI
  ! *r a real scalar
  ! *qn q-r
  FUNCTION qminusB(r,q) &
       RESULT(qn)
    IMPLICIT NONE
    double precision, INTENT(IN) :: r
    TYPE(otim2n2), INTENT(IN) :: q
    TYPE(otim2n2) :: qn

    qn%w=r-q%w
    qn%x= -q%x
    qn%y= -q%y

  END FUNCTION qminusB



  ! Returns the matrix form of the quarternion 
  ! *q a OTI
  ! *q2mat
  FUNCTION q2mat(q) &
       RESULT(mat)
    IMPLICIT NONE
    TYPE(otim2n2), INTENT(IN):: q
    double precision :: mat(NUM_IM_DIR,NUM_IM_DIR)

    mat(1,1) = q%w
    mat(1,2) = 0.0d0
    mat(1,3) = 0.0d0
    mat(2,1) = q%x
    mat(2,2) = q%w
    mat(2,3) = 0.0d0
    mat(3,1) = q%y
    mat(3,2) = 0.0d0
    mat(3,3) = q%w

  END FUNCTION q2mat

  ! Returns the quarternion inverse of :math:`\mathbf{q}`: :math:`\mathbf{q}^*/||\mathbf{q}||`
  ! *q a OTI
  ! *pdivq inverse of q  
  FUNCTION rdivq(r,q) &
       RESULT(pdivq)
    IMPLICIT NONE
    double precision , INTENT(IN) :: r
    TYPE(otim2n2), INTENT(IN) ::q
    TYPE(otim2n2) :: rq,iq, pdivq
    rq%w = r
    rq%x = 0.0_8
    rq%y = 0.0_8

    iq = otio1n2( 1.0d0/q%w, - q%x/(q%w*q%w) , - q%y/(q%w*q%w) )
    pdivq = rq*iq

  END FUNCTION rdivq

  ! Returns the division of quarternions :math:`\mathbf{p}/\mathbf{q}`: :math:`\mathbf{p}\mathbf{q}^*/||\mathbf{q}||^2`
  ! *p a OTI
  ! *q a OTI
  ! *pdivq p / q  
  FUNCTION qdivq(p,q) &
       RESULT(pdivq)
    IMPLICIT NONE
    TYPE(otim2n2), INTENT(IN) :: p,q
    TYPE(otim2n2) :: iq, pdivq

    iq = otio1n2( 1.0d0/q%w, - q%x/(q%w*q%w) , - q%y/(q%w*q%w) )
    pdivq = p*iq

  END FUNCTION qdivq

  ! INITIALIZATION

  ! Initialize an OTI number value 
  SUBROUTINE QINITr(c,res)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN):: c ! Real coefficient to initialize real coeff only
    TYPE(otim2n2), INTENT(INOUT)  :: res

    res%w = c
    res%x = 0.0d0
    res%y = 0.0d0

  END SUBROUTINE

  ! Initialize an OTI number value 
  SUBROUTINE QvecINITr(c,res)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN):: c ! Real coefficient to initialize real coeff only
    TYPE(otim2n2), INTENT(INOUT)  :: res(:)

    res%w = c
    res%x = 0.0d0
    res%y = 0.0d0

  END SUBROUTINE

  ! Initialize an OTI number value 
  SUBROUTINE QmatINITr(c,res)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN):: c ! Real coefficient to initialize real coeff only
    TYPE(otim2n2), INTENT(INOUT)  :: res(:,:)

    res%w = c
    res%x = 0.0d0
    res%y = 0.0d0

  END SUBROUTINE



  ! Initialize an OTI number value 
  SUBROUTINE qINITq(c,res)
    IMPLICIT NONE
    TYPE(otim2n2), INTENT(IN)     :: c ! Real coefficient to initialize real coeff only
    TYPE(otim2n2), INTENT(INOUT)  :: res

    res%w = c%w
    res%x = c%x
    res%y = c%y

  END SUBROUTINE

  ! Initialize an OTI number value 
  SUBROUTINE qvecINITq(c,res)
    IMPLICIT NONE
    TYPE(otim2n2), INTENT(IN)    :: c ! Real coefficient to initialize real coeff only
    TYPE(otim2n2), INTENT(INOUT) :: res(:)

    res%w = c%w
    res%x = c%x
    res%y = c%y

  END SUBROUTINE

  ! Initialize an OTI number value 
  SUBROUTINE qmatINITq(c,res)
    IMPLICIT NONE
    TYPE(otim2n2), INTENT(IN)    :: c ! Real coefficient to initialize real coeff only
    TYPE(otim2n2), INTENT(INOUT) :: res(:,:)

    res%w = c%w
    res%x = c%x
    res%y = c%y

  END SUBROUTINE









































































  ! =============================================================================
  ! =========================== UTSA ADDED FUNCTIONS ============================
  ! =============================================================================


  ! Returns the quarternion :math:`\mathbf{q}` added by scalar :math:`r`
  ! component-wise
  ! *q a OTI
  ! *r a real scalar
  ! *qn q+r
  FUNCTION qplusq(q,r) &
       RESULT(qn)
    IMPLICIT NONE
    TYPE(otim2n2), INTENT(IN) :: q,r
    TYPE(otim2n2) :: qn

    qn%w=q%w+r%w
    qn%x=q%x+r%x
    qn%y=q%y+r%y

  END FUNCTION qplusq

  ! Returns the quarternion :math:`\mathbf{q}` subtracted by scalar :math:`r`
  ! component-wise
  ! *q a OTI
  ! *r a real scalar
  ! *qn q-r
  FUNCTION qminusq(q,r) &
       RESULT(qn)
    IMPLICIT NONE
    TYPE(otim2n2), INTENT(IN) :: q,r
    TYPE(otim2n2) :: qn

    qn%w=q%w-r%w
    qn%x=q%x-r%x
    qn%y=q%y-r%y

  END FUNCTION qminusq



  ! Returns the quarternion :math:`\mathbf{q}` multiplied by scalar :math:`r`
  ! component-wise
  ! *q a OTI
  ! *r a real scalar
  ! *qn r*q
  FUNCTION qtimes(r,q) &
       RESULT(qn)
    IMPLICIT NONE
    double precision, INTENT(IN) :: r
    TYPE(otim2n2), INTENT(IN) :: q
    TYPE(otim2n2) :: qn

    qn%w=q%w*r
    qn%x=q%x*r
    qn%y=q%y*r

  END FUNCTION qtimes

  ! Returns the quarternion :math:`\mathbf{q}` multiplied by scalar :math:`r`
  ! component-wise
  ! *q a OTI
  ! *r a real scalar
  ! *qn q*r
  FUNCTION qtimesB(q,r) &
       RESULT(qn)
    IMPLICIT NONE
    double precision, INTENT(IN) :: r
    TYPE(otim2n2), INTENT(IN) :: q
    TYPE(otim2n2) :: qn

    qn%w=q%w*r
    qn%x=q%x*r
    qn%y=q%y*r

  END FUNCTION qtimesB


  ! Returns the quarternion :math:`\mathbf{q}` divided by scalar :math:`r`
  ! component-wise
  ! *q a OTI
  ! *r a real scalar
  ! *qn q/r
  FUNCTION qdiv(q,r) &
       RESULT(qn)
    IMPLICIT NONE
    double precision, INTENT(IN) :: r
    TYPE(otim2n2), INTENT(IN) :: q
    TYPE(otim2n2) :: qn

    qn%w=q%w/r
    qn%x=q%x/r
    qn%y=q%y/r

  END FUNCTION qdiv

  ! Returns the quarternion product :math:`\mathbf{q}_1\mathbf{q}_2`
  ! Note that the product is non-commutative:  :math:`\mathbf{q}_1\mathbf{q}_2 \ne \mathbf{q}_2\mathbf{q}_1`
  ! *q1 a OTI
  ! *q2 a OTI
  ! *qn q1*q2
  FUNCTION qprod(q1,q2) &
       RESULT(qn)
    IMPLICIT NONE
    TYPE(otim2n2), INTENT(IN) :: q1, q2
    TYPE(otim2n2) :: qn
    
    qn%w = q1%w*q2%w
    qn%x = q1%w*q2%x+q1%x*q2%w
    qn%y = q1%w*q2%y+q1%y*q2%w

  END FUNCTION qprod

  

 
  ! Returns the oti product  q1*q2 + q3*q4
  FUNCTION qmulsum2(q1,q2,q3,q4) &
       RESULT(qn)
    IMPLICIT NONE
    TYPE(otim2n2), INTENT(IN) :: q1, q2, q3, q4
    TYPE(otim2n2) :: qn
    
    qn%w = q1%w*q2%w+q3%w*q4%w
    qn%x = q1%w*q2%x+q1%x*q2%w+q3%w*q4%x+q3%x*q4%w
    qn%y = q1%w*q2%y+q1%y*q2%w+q3%w*q4%y+q3%y*q4%w

  END FUNCTION qmulsum2





END MODULE otinum_m2n2