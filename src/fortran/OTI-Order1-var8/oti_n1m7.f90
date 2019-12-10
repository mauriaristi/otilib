
MODULE octonions
  IMPLICIT NONE

  
  INTEGER, PARAMETER :: REAL_KIND = 8
  
  ! The quarternion type. It only contains four
  ! real components, but the main advantage for
  ! defining it as a custom type is the possibility
  ! to write routines and operators for quaternion
  ! algebra.
  ! *w the "real" component of the quaternion
  ! *x an "imaginary" component of the quaternion
  ! *y an "imaginary" component of the quaternion
  ! *z an "imaginary" component of the quaternion
  TYPE octn
    REAL(REAL_KIND) :: w
    REAL(REAL_KIND) :: x
    REAL(REAL_KIND) :: y
    REAL(REAL_KIND) :: z
    REAL(REAL_KIND) :: a
    REAL(REAL_KIND) :: b
    REAL(REAL_KIND) :: c
    REAL(REAL_KIND) :: d
  END TYPE octn




!> Octonion + scalar operator
INTERFACE operator(+)
   MODULE PROCEDURE oplus , oplusB
END INTERFACE

!> Octonion - scalar operator
INTERFACE operator(-)
   MODULE PROCEDURE ominus, ominusB, oneg
END INTERFACE

!> Octonion / Quaternion operator
INTERFACE operator(/)
   MODULE PROCEDURE odivo, omatDr, ovecDr
END INTERFACE

!> Octonion power operator
INTERFACE operator(**)
   MODULE PROCEDURE opow
END INTERFACE

INTERFACE MATMUL_SUB
  
END INTERFACE

!> Matrix multiplication though MATMUL
INTERFACE MATMUL
  MODULE PROCEDURE  omatXomat, &         ! Qmat x Qmat
                    rmatXomat, omatXrmat ! Rmat x Qmat, Qmat x Rmat 
END INTERFACE

! Elementwise multiplication and scalar-vector/matrix multiplication
INTERFACE operator(*)
  MODULE PROCEDURE oXomat_proc, rXomat_proc, omatXr_proc, omatXo_proc, &
                   oXovec_proc, rXovec_proc, ovecXr_proc, ovecXo_proc, & ! Vector operations.
                   ovecXovec_proc, ovecXrvec_proc, rvecXovec_proc,     & ! elementwise
                   omatXomat_proc, omatXrmat_proc, rmatXomat_proc
END INTERFACE

! Elementwise addition and scalar-vector/matrix addition
INTERFACE operator(+)
  MODULE PROCEDURE oPomat, rPomat, omatPo, omatPr,  &  ! Mult Matrix times quaternion and 
                   omatPomat, rmatPomat, omatPrmat, &
                   ovecPovec, ovecPrvec, rvecPovec
END INTERFACE

! Elementwise subtraction and scalar-vector/matrix subtraction
INTERFACE operator(-)
  MODULE PROCEDURE oMomat, rMomat,  omatMo, omatMr, &
                   omatMrmat, omatMomat, rmatMomat, &
                   ovecMovec, ovecMrvec, rvecMovec, &
                   omatNeg, ovecNeg
END INTERFACE

! Matrix Transpose.
INTERFACE TRANSPOSE
  MODULE PROCEDURE  omatTrans_proc
END INTERFACE

INTERFACE ASSIGNMENT (=)
  MODULE PROCEDURE  oASSIGNr
END INTERFACE

! Vector dot product.
INTERFACE DOT_PRODUCT
  MODULE PROCEDURE  ovecDOTovec, rvecDOTovec, ovecDOTrvec 
END INTERFACE

! Pretty printing for: Real and quaternion derived types (also array types).
INTERFACE PPRINT
  MODULE PROCEDURE OPrint,    RPrint,    & ! Quaternion / real print
                   OmatPrint, RmatPrint, & ! Matrix print
                   OvecPrint, RvecPrint    ! vector prints
END INTERFACE

INTERFACE INIT
  MODULE PROCEDURE OINITr, OvecINITr, OmatINITr, &   ! Initialization  calls
                   OINITo, OvecINITo, OmatINITo
END INTERFACE

INTERFACE MATFOLD
  MODULE PROCEDURE OmatFold_multiple_src, OvecFold_multiple_src
END INTERFACE




! Quarternion product operator
INTERFACE operator(.qp.)
   MODULE PROCEDURE oprod
END INTERFACE

! Quarternion product operator
INTERFACE operator(*)
   MODULE PROCEDURE oprod
END INTERFACE

! Real / Quaternion operator
INTERFACE operator(/)
   MODULE PROCEDURE rdivo
END INTERFACE

! Quarternion + Quaternion operator
INTERFACE operator(+)
   MODULE PROCEDURE opluso
END INTERFACE

! Quarternion - Quarternion operator
INTERFACE operator(-)
   MODULE PROCEDURE ominuso
END INTERFACE

! Quarternion norm operator
INTERFACE operator(.norm.)
   MODULE PROCEDURE onorm
END INTERFACE

! Quarternion conjugate operator
INTERFACE operator(.c.)
   MODULE PROCEDURE oconj
END INTERFACE

! Quarternion conjugate operator
INTERFACE operator(.conj.)
   MODULE PROCEDURE oconj
END INTERFACE

! Quarternion inverse operator
INTERFACE operator(.inv.)
   MODULE PROCEDURE oinv
END INTERFACE

! Scalar * quarternion operator
INTERFACE operator(*)
   MODULE PROCEDURE otimes
END INTERFACE

! Quarternion * scalar operator
INTERFACE operator(*)
   MODULE PROCEDURE otimesB
END INTERFACE

! Quarternion / scalar operator
INTERFACE operator(/)
   MODULE PROCEDURE odiv
END INTERFACE













CONTAINS
  
    ! Assignment operator = for quaternion
  SUBROUTINE oASSIGNr(res,r)
    REAL(REAL_KIND), INTENT(IN) :: r 
    TYPE(octn), INTENT(OUT)     :: RES

    res%w = r
    res%x = 0.0d0
    res%y = 0.0d0
    res%z = 0.0d0
    res%a = 0.0d0
    res%b = 0.0d0
    res%c = 0.0d0
    res%d = 0.0d0

  END SUBROUTINE

  FUNCTION ovecDOTovec(q,p) RESULT(res)
    IMPLICIT NONE
    TYPE(octn),   INTENT(IN) :: q(:)
    TYPE(octn),   INTENT(IN) :: p(:)
    TYPE(octn)               :: res
    INTEGER :: i

    IF (size(p,1) /= size(q,1)) THEN
      STOP "Invalid shape for dot product of quaternion vectors"
    END IF 

    res%w = 0.0d0
    res%x = 0.0d0
    res%y = 0.0d0
    res%z = 0.0d0
    res%a = 0.0d0
    res%b = 0.0d0
    res%c = 0.0d0
    res%d = 0.0d0

    DO i=1,size(q,1)

      res = res + q(i) * p(i)

    END DO

  END FUNCTION

  FUNCTION rvecDOTovec(q,p) RESULT(res)
    IMPLICIT NONE
    REAL(REAL_KIND),   INTENT(IN)    :: q(:)
    TYPE(octn),   INTENT(IN) :: p(:)
    TYPE(octn)               :: res
    INTEGER :: i

    IF (size(p,1) /= size(q,1)) THEN
      STOP "Invalid shape for dot product of quaternion vectors"
    END IF 

    res%w = 0.0d0
    res%x = 0.0d0
    res%y = 0.0d0
    res%z = 0.0d0
    res%a = 0.0d0
    res%b = 0.0d0
    res%c = 0.0d0
    res%d = 0.0d0

    DO i=1,size(q,1)

      res = res + q(i) * p(i)

    END DO
 
  END FUNCTION

  FUNCTION ovecDOTrvec(q,p) RESULT(res)
    IMPLICIT NONE
    TYPE(octn),   INTENT(IN) :: q(:)
    REAL(REAL_KIND),   INTENT(IN) :: p(:)
    TYPE(octn)               :: res
    INTEGER :: i

    IF (size(p,1) /= size(q,1)) THEN
      STOP "Invalid shape for dot product of quaternion vectors"
    END IF 

    res%w = 0.0d0
    res%x = 0.0d0
    res%y = 0.0d0
    res%z = 0.0d0
    res%a = 0.0d0
    res%b = 0.0d0
    res%c = 0.0d0
    res%d = 0.0d0

    DO i=1,size(q,1)

      res = res + q(i) * p(i)

    END DO


  END FUNCTION


  FUNCTION omatNeg(q) RESULT(res)
    IMPLICIT NONE
    TYPE(octn),   INTENT(IN) :: q(:,:)
    TYPE(octn)               :: res(SIZE(q,1),SIZE(q,2))

    res%w = -q%w
    res%x = -q%x
    res%y = -q%y
    res%z = -q%z
    res%a = -q%a
    res%b = -q%b
    res%c = -q%c
    res%d = -q%d

  END FUNCTION

  FUNCTION ovecNeg(q) RESULT(res)
    IMPLICIT NONE
    TYPE(octn),   INTENT(IN) :: q(:)
    TYPE(octn)               :: res(SIZE(q,1))

    res%w = -q%w
    res%x = -q%x
    res%y = -q%y
    res%z = -q%z
    res%a = -q%a
    res%b = -q%b
    res%c = -q%c
    res%d = -q%d

  END FUNCTION

  ! Divide a Quaternion matrix by real
  ! coefficient
  FUNCTION omatDr(q,r) RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: q(:,:)
    REAL(REAL_KIND),   INTENT(IN)    :: r
    TYPE(octn)               :: res(SIZE(q,1),SIZE(q,2))
   
    res%w = q%w/r
    res%x = q%x/r
    res%y = q%y/r
    res%z = q%z/r
    res%a = q%a/r
    res%b = q%b/r
    res%c = q%c/r
    res%d = q%d/r

  END FUNCTION

  FUNCTION ovecDr(q,r) RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: q(:)
    REAL(REAL_KIND),   INTENT(IN)    :: r
    TYPE(octn)               :: res(SIZE(q,1))

    res%w = q%w/r
    res%x = q%x/r
    res%y = q%y/r
    res%z = q%z/r
    res%a = q%a/r
    res%b = q%b/r
    res%c = q%c/r
    res%d = q%d/r

  END FUNCTION


  ! Mutliply quaternion vector with quaternion number
  FUNCTION omatXomat_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: q(:,:)
    TYPE(octn),   INTENT(IN) :: p(:,:)
    TYPE(octn)               :: res(SIZE(q,1),SIZE(q,2))

    IF((SIZE(q,1)/= SIZE(p,1)).or.((SIZE(q,2)/= SIZE(p,2))))THEN
      STOP "Invalid shape for elementwise matrix multiplication"
    END IF 

    res%w = q%w*p%w 
    res%x = q%w*p%x + q%x*p%w 
    res%y = q%w*p%y + q%y*p%w 
    res%z = q%w*p%z + q%z*p%w 
    res%a = q%w*p%a + q%a*p%w 
    res%b = q%w*p%b + q%b*p%w 
    res%c = q%w*p%c + q%c*p%w
    res%d = q%w*p%d + q%d*p%w

  END FUNCTION


  ! Mutliply quaternion vector with quaternion number
  FUNCTION omatXrmat_proc(p,q) RESULT(res)
    IMPLICIT NONE 
    REAL(REAL_KIND),INTENT(IN) :: q(:,:)
    TYPE(octn),   INTENT(IN) :: p(:,:)
    TYPE(octn)               :: res(SIZE(q,1),SIZE(q,2))

    IF ((SIZE(q,1)/= SIZE(p,1)).or.((SIZE(q,2)/= SIZE(p,2))) ) THEN
      STOP "Invalid shape for elementwise matrix multiplication"
    END IF 

    res%w = q*p%w
    res%x = q*p%x
    res%y = q*p%y
    res%z = q*p%z
    res%a = q*p%a
    res%b = q*p%b
    res%c = q*p%c
    res%d = q*p%d

  END FUNCTION


  ! Mutliply quaternion vector with quaternion number
  FUNCTION rmatXomat_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    REAL(REAL_KIND),INTENT(IN) :: q(:,:)
    TYPE(octn),   INTENT(IN)   :: p(:,:)
    TYPE(octn)                 :: res(SIZE(q,1),SIZE(q,2))

    IF((SIZE(q,1)/= SIZE(p,1)).or.((SIZE(q,2)/= SIZE(p,2))))THEN
      STOP "Invalid shape for elementwise matrix multiplication"
    END IF 

    res%w = q*p%w
    res%x = q*p%x
    res%y = q*p%y
    res%z = q*p%z
    res%a = q*p%a
    res%b = q*p%b
    res%c = q*p%c
    res%d = q*p%d

  END FUNCTION

  ! Mutliply quaternion vector with quaternion number
  FUNCTION ovecXovec_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: q(:)
    TYPE(octn),   INTENT(IN) :: p(:)
    TYPE(octn)               :: res(SIZE(q,1))

    IF(SIZE(q,1)/= SIZE(p,1))THEN
      STOP "Invalid shape for elementwise vector multiplication"
    END IF 

    res%w = q%w*p%w 
    res%x = q%w*p%x + q%x*p%w  
    res%y = q%w*p%y + q%y*p%w 
    res%z = q%w*p%z + q%z*p%w 
    res%a = q%w*p%a + q%a*p%w 
    res%b = q%w*p%b + q%b*p%w 
    res%c = q%w*p%c + q%c*p%w 
    res%d = q%w*p%d + q%d*p%w

  END FUNCTION


  ! Mutliply quaternion vector with quaternion number
  FUNCTION ovecXrvec_proc(p,q) RESULT(res)
    IMPLICIT NONE 
    REAL(REAL_KIND),      INTENT(IN) :: q(:)
    TYPE(octn),   INTENT(IN) :: p(:)
    TYPE(octn)               :: res(SIZE(q,1))

    IF(SIZE(q,1)/= SIZE(p,1))THEN
      STOP "Invalid shape for elementwise vector multiplication"
    END IF 

    res%w = q*p%w
    res%x = q*p%x
    res%y = q*p%y
    res%z = q*p%z
    res%a = q*p%a
    res%b = q*p%b
    res%c = q*p%c
    res%d = q*p%d

  END FUNCTION


  ! Mutliply quaternion vector with quaternion number
  FUNCTION rvecXovec_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    REAL(REAL_KIND),      INTENT(IN) :: q(:)
    TYPE(octn),   INTENT(IN) :: p(:)
    TYPE(octn)               :: res(SIZE(q,1))

    IF(SIZE(q,1)/= SIZE(p,1))THEN
      STOP "Invalid shape for elementwise vector multiplication"
    END IF 

    res%w = q*p%w
    res%x = q*p%x
    res%y = q*p%y
    res%z = q*p%z
    res%a = q*p%a
    res%b = q*p%b
    res%c = q*p%c
    res%d = q*p%d

  END FUNCTION


  ! Mutliply quaternion matrix with quaternion number
  FUNCTION omatXo_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: q(:,:)
    TYPE(octn),   INTENT(IN) :: p
    TYPE(octn)               :: res(SIZE(q,1),SIZE(q,2))

    res%w = q%w*p%w 
    res%x = q%w*p%x + q%x*p%w 
    res%y = q%w*p%y + q%y*p%w 
    res%z = q%w*p%z + q%z*p%w 
    res%a = q%w*p%a + q%a*p%w 
    res%b = q%w*p%b + q%b*p%w 
    res%c = q%w*p%c + q%c*p%w 
    res%d = q%w*p%d + q%d*p%w

  END FUNCTION

  ! Mutliply quaternion vector with quaternion number
  FUNCTION ovecXo_proc(q,p) RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: q(:)
    TYPE(octn),   INTENT(IN) :: p
    TYPE(octn)               :: res(SIZE(q,1))

    res%w = q%w*p%w 
    res%x = q%w*p%x + q%x*p%w 
    res%y = q%w*p%y + q%y*p%w 
    res%z = q%w*p%z + q%z*p%w 
    res%a = q%w*p%a + q%a*p%w 
    res%b = q%w*p%b + q%b*p%w 
    res%c = q%w*p%c + q%c*p%w 
    res%d = q%w*p%d + q%d*p%w

  END FUNCTION

  ! Mutliply quaternion number with quaternion matrix 
  FUNCTION oXomat_proc(p,q) RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: p
    TYPE(octn),   INTENT(IN) :: q(:,:)
    TYPE(octn)               :: res(SIZE(q,1),SIZE(q,2))

    res%w = q%w*p%w 
    res%x = q%w*p%x + q%x*p%w 
    res%y = q%w*p%y + q%y*p%w 
    res%z = q%w*p%z + q%z*p%w 
    res%a = q%w*p%a + q%a*p%w 
    res%b = q%w*p%b + q%b*p%w 
    res%c = q%w*p%c + q%c*p%w 
    res%d = q%w*p%d + q%d*p%w


  END FUNCTION

  ! Mutliply quaternion number with quaternion vector 
  FUNCTION oXovec_proc(p,q) RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: p
    TYPE(octn),   INTENT(IN) :: q(:)
    TYPE(octn)               :: res(SIZE(q,1))

    res%w = q%w*p%w 
    res%x = q%w*p%x + q%x*p%w 
    res%y = q%w*p%y + q%y*p%w 
    res%z = q%w*p%z + q%z*p%w 
    res%a = q%w*p%a + q%a*p%w 
    res%b = q%w*p%b + q%b*p%w 
    res%c = q%w*p%c + q%c*p%w 
    res%d = q%w*p%d + q%d*p%w

  END FUNCTION

  ! Mutliply real number with quaternion matrix 
  FUNCTION rXomat_proc(r,q) RESULT(res)
    IMPLICIT NONE 
    REAL(REAL_KIND),   INTENT(IN)    :: r
    TYPE(octn),   INTENT(IN) :: q(:,:)
    TYPE(octn)               :: res(SIZE(q,1),SIZE(q,2))

    res%w = q%w*r
    res%x = q%x*r
    res%y = q%y*r
    res%z = q%z*r
    res%a = q%a*r
    res%b = q%b*r
    res%c = q%c*r
    res%d = q%d*r

  END FUNCTION

  ! Mutliply real number with quaternion vector 
  FUNCTION rXovec_proc(r,q) RESULT(res)
    IMPLICIT NONE 
    REAL(REAL_KIND),   INTENT(IN)    :: r
    TYPE(octn),   INTENT(IN) :: q(:)
    TYPE(octn)               :: res(SIZE(q,1))
    
    res%w = q%w*r
    res%x = q%x*r
    res%y = q%y*r
    res%z = q%z*r
    res%a = q%a*r
    res%b = q%b*r
    res%c = q%c*r
    res%d = q%d*r

  END FUNCTION

  ! Mutliply quaternion matrix with real number
  FUNCTION omatXr_proc(q,r) RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: q(:,:)
    REAL(REAL_KIND),   INTENT(IN)    :: r
    TYPE(octn)               :: res(SIZE(q,1),SIZE(q,2))
    
    res%w = q%w*r
    res%x = q%x*r
    res%y = q%y*r
    res%z = q%z*r
    res%a = q%a*r
    res%b = q%b*r
    res%c = q%c*r
    res%d = q%d*r

  END FUNCTION

  ! Mutliply quaternion matrix with real number
  FUNCTION ovecXr_proc(q,r) RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: q(:)
    REAL(REAL_KIND),   INTENT(IN)    :: r
    TYPE(octn)               :: res(SIZE(q,1))
    
    res%w = q%w*r
    res%x = q%x*r
    res%y = q%y*r
    res%z = q%z*r
    res%a = q%a*r
    res%b = q%b*r
    res%c = q%c*r
    res%d = q%d*r

  END FUNCTION






























  FUNCTION OvecFold_multiple_src(           &
                    Wmat, Xmat, Ymat, Zmat, &
                    Amat, Bmat, Cmat, Dmat) & 
    RESULT(res)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN) :: Wmat(:)
    REAL(REAL_KIND), INTENT(IN) :: Xmat(:)
    REAL(REAL_KIND), INTENT(IN) :: Ymat(:)
    REAL(REAL_KIND), INTENT(IN) :: Zmat(:)
    REAL(REAL_KIND), INTENT(IN) :: Amat(:)
    REAL(REAL_KIND), INTENT(IN) :: Bmat(:)
    REAL(REAL_KIND), INTENT(IN) :: Cmat(:)
    REAL(REAL_KIND), INTENT(IN) :: Dmat(:)
    TYPE(octn)                  :: res(SIZE(Wmat,1))
    
    res%w = Wmat
    res%x = Xmat
    res%y = Ymat
    res%z = Zmat
    res%a = Amat
    res%b = Bmat
    res%c = Cmat
    res%d = Dmat
    
  END FUNCTION




  FUNCTION OmatFold_multiple_src(           &
                    Wmat, Xmat, Ymat, Zmat, &
                    Amat, Bmat, Cmat, Dmat) & 
    RESULT(res)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN) :: Wmat(:,:)
    REAL(REAL_KIND), INTENT(IN) :: Xmat(:,:)
    REAL(REAL_KIND), INTENT(IN) :: Ymat(:,:)
    REAL(REAL_KIND), INTENT(IN) :: Zmat(:,:)
    REAL(REAL_KIND), INTENT(IN) :: Amat(:,:)
    REAL(REAL_KIND), INTENT(IN) :: Bmat(:,:)
    REAL(REAL_KIND), INTENT(IN) :: Cmat(:,:)
    REAL(REAL_KIND), INTENT(IN) :: Dmat(:,:)
    TYPE(octn)                  :: res(SIZE(Wmat,1),SIZE(Wmat,2))
    
    res%w = Wmat
    res%x = Xmat
    res%y = Ymat
    res%z = Zmat
    res%a = Amat
    res%b = Bmat
    res%c = Cmat
    res%d = Dmat
    
  END FUNCTION

  FUNCTION OmatFold_single_src_nold(Umat) & 
    RESULT(res)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN) :: Umat(:,:)  ! Unfolded matrix
    TYPE(octn)                  :: res(SIZE(Umat,1)/8,SIZE(Umat,2)/8)
    INTEGER :: sizex
    

    IF (MODULO(SIZE(Umat,1),8) /= 0) THEN
      STOP "Invalid dimension of Matrix to be unfolded into Octonion."
    END IF

    sizex = SIZE(Umat,1) /8

    res%w = Umat(         1 : sizex  , 1 : sizex )
    res%x = Umat(   sizex+1 : sizex*2, 1 : sizex )
    res%y = Umat( 2*sizex+1 : sizex*3, 1 : sizex )
    res%z = Umat( 3*sizex+1 : sizex*4, 1 : sizex )
    res%a = Umat( 4*sizex+1 : sizex*5, 1 : sizex )
    res%b = Umat( 5*sizex+1 : sizex*6, 1 : sizex )
    res%c = Umat( 6*sizex+1 : sizex*7, 1 : sizex )
    res%d = Umat( 7*sizex+1 : sizex*8, 1 : sizex )
    
  END FUNCTION


  ! FUNCTION OmatFold_single_src(Umat, ldx, ldy, offsetx, offsety) & 
  !   RESULT(res)
  !   IMPLICIT NONE
  !   REAL(REAL_KIND), INTENT(IN) :: Umat(:,:)  ! Unfolded matrix Umat(dim1:dim2).
  !   INTEGER, INTENT(IN)         :: ldx        ! size 1 of folded matrix
  !   INTEGER, INTENT(IN)         :: ldy        ! size 2 of folded matrix 
  !   INTEGER, INTENT(IN)         :: offsetx    ! Offset: offsetx = dim1-ldx (>0)
  !   INTEGER, INTENT(IN)         :: offsety    ! Offset: offsetx = dim1-ldx (>0)
  !   TYPE(octn),                 :: res(ldx,ldy)
  !   INTEGER :: startx, sizex, starty, sizey 

  !   startx = 
  !   sizex  = 
  !   starty = 
  !   sizey  = 


  !   res%w = Umat(         1 : sizex  , 1 : sizex )
  !   res%x = Umat(   sizex+1 : sizex*2, 1 : sizex )
  !   res%y = Umat( 2*sizex+1 : sizex*3, 1 : sizex )
  !   res%z = Umat( 3*sizex+1 : sizex*4, 1 : sizex )
  !   res%a = Umat( 4*sizex+1 : sizex*5, 1 : sizex )
  !   res%b = Umat( 5*sizex+1 : sizex*6, 1 : sizex )
  !   res%c = Umat( 6*sizex+1 : sizex*7, 1 : sizex )
  !   res%d = Umat( 7*sizex+1 : sizex*8, 1 : sizex )
    
  ! END FUNCTION



  ! Sum two quaternion matrices
  FUNCTION rmatMomat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q(:,:)
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      
      IF ((size(p,1) /= size(q,1)).or.(size(p,2) /= size(q,2))) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 

      res%x = -p%x
      res%y = -p%y
      res%z = -p%z
      res%a = -p%a
      res%b = -p%b
      res%c = -p%c
      res%d = -p%d

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q(i,j) - p(i,j)%w
          
        END DO
      END DO

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION rMomat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      
      res%x = -p%x
      res%y = -p%y
      res%z = -p%z
      res%a = -p%a
      res%b = -p%b
      res%c = -p%c
      res%d = -p%d

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q - p(i,j)%w

        END DO
      END DO

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION oMomat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(octn),   INTENT(IN)  :: q
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q%w - p(i,j)%w
          res(i,j)%x = q%x - p(i,j)%x
          res(i,j)%y = q%y - p(i,j)%y
          res(i,j)%z = q%z - p(i,j)%z
          res(i,j)%a = q%a - p(i,j)%a
          res(i,j)%b = q%b - p(i,j)%b
          res(i,j)%c = q%c - p(i,j)%c
          res(i,j)%d = q%d - p(i,j)%d

        END DO
      END DO

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION omatMrmat(p,q)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q(:,:)
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      
      IF ((size(p,1) /= size(q,1)).or.(size(p,2) /= size(q,2))) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 

      res%w = p%w - q
      res%x = p%x
      res%y = p%y
      res%z = p%z
      res%a = p%a
      res%b = p%b
      res%c = p%c
      res%d = p%d

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION omatMr(p,q)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      
      res%x = p%x
      res%y = p%y
      res%z = p%z
      res%a = p%a
      res%b = p%b
      res%c = p%c
      res%d = p%d

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w =  p(i,j)%w - q

        END DO
      END DO

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION omatMo(p,q)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(octn),   INTENT(IN)  :: q
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = p(i,j)%w - q%w
          res(i,j)%x = p(i,j)%x - q%x
          res(i,j)%y = p(i,j)%y - q%y
          res(i,j)%z = p(i,j)%z - q%z
          res(i,j)%a = p(i,j)%a - q%a
          res(i,j)%b = p(i,j)%b - q%b
          res(i,j)%c = p(i,j)%c - q%c
          res(i,j)%d = p(i,j)%d - q%d

        END DO
      END DO

  END FUNCTION

  ! SUBTRACTION of two quaternion matrices
  FUNCTION omatMomat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(octn),   INTENT(IN)  :: q(:,:)
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(q,1),size(q,2))
      INTEGER sizeqx, sizeqy, sizepx, sizepy

      sizeqx = size(q,1)
      sizeqy = size(q,2)
      sizepx = size(p,1)
      sizepy = size(p,2)

      IF ((sizeqx /= sizepx).or.(sizeqy /= sizepy)) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 
      
      res%w = q%w - p%w
      res%x = q%x - p%x
      res%y = q%y - p%y
      res%z = q%z - p%z
      res%a = q%a - p%a 
      res%b = q%b - p%b
      res%c = q%c - p%c
      res%d = q%d - p%d

  END FUNCTION


  ! SUBTRACTION of two quaternion matrices
  FUNCTION ovecMovec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(octn),   INTENT(IN)  :: q(:)
      TYPE(octn),   INTENT(IN)  :: p(:)
      TYPE(octn)                :: res(size(q,1))
      INTEGER sizeqx, sizepx

      sizeqx = size(q,1)
      sizepx = size(p,1)

      IF ((sizeqx /= sizepx)) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 
      
      res%w = q%w - p%w
      res%x = q%x - p%x
      res%y = q%y - p%y
      res%z = q%z - p%z
      res%a = q%a - p%a 
      res%b = q%b - p%b
      res%c = q%c - p%c
      res%d = q%d - p%d

  END FUNCTION

  FUNCTION ovecMrvec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(octn),   INTENT(IN)  :: q(:)
      REAL(REAL_KIND),      INTENT(IN)  :: p(:)
      TYPE(octn)                :: res(size(q,1))
      INTEGER sizeqx, sizepx

      sizeqx = size(q,1)
      sizepx = size(p,1)

      IF ((sizeqx /= sizepx)) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 
      
      res%w = q%w - p
      res%x = q%x
      res%y = q%y
      res%z = q%z
      res%a = q%a 
      res%b = q%b 
      res%c = q%c 
      res%d = q%d 

  END FUNCTION

  FUNCTION rvecMovec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q(:)
      TYPE(octn),   INTENT(IN)  :: p(:)
      TYPE(octn)                :: res(size(q,1))
      INTEGER sizeqx, sizepx

      sizeqx = size(q,1)
      sizepx = size(p,1)

      IF ((sizeqx /= sizepx)) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 
      
      res%w = q - p%w
      res%x =   - p%x
      res%y =   - p%y
      res%z =   - p%z
      res%a =   - p%a
      res%b =   - p%b
      res%c =   - p%c
      res%d =   - p%d

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION rvecPovec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q(:)
      TYPE(octn),   INTENT(IN)  :: p(:)
      TYPE(octn)                :: res(size(p,1))
      
      IF ((size(p,1) /= size(q,1))) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 

      res%w = q + p%w
      res%x = p%x
      res%y = p%y
      res%z = p%z
      res%a = p%a
      res%b = p%b
      res%c = p%c
      res%d = p%d

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION ovecPrvec(p,q)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q(:)
      TYPE(octn),   INTENT(IN)  :: p(:)
      TYPE(octn)                :: res(size(p,1))
      
      IF ((size(p,1) /= size(q,1))) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 

      res%w = q + p%w
      res%x = p%x
      res%y = p%y
      res%z = p%z
      res%a = p%a
      res%b = p%b
      res%c = p%c
      res%d = p%d

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION ovecPovec(p,q)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(octn),   INTENT(IN)  :: q(:)
      TYPE(octn),   INTENT(IN)  :: p(:)
      TYPE(octn)                :: res(size(p,1))
      
      IF ((size(p,1) /= size(q,1))) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 

      res%w = q%w + p%w
      res%x = q%x + p%x
      res%y = q%y + p%y
      res%z = q%z + p%z
      res%a = q%a + p%a
      res%b = q%b + p%b
      res%c = q%c + p%c
      res%d = q%d + p%d

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION rmatPomat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q(:,:)
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      
      IF ((size(p,1) /= size(q,1)).or.(size(p,2) /= size(q,2))) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 
      res%w = q + p%w
      res%x =     p%x
      res%y =     p%y
      res%z =     p%z
      res%a =     p%a
      res%b =     p%b
      res%c =     p%c
      res%d =     p%d

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION rPovec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q
      TYPE(octn),   INTENT(IN)  :: p(:)
      TYPE(octn)                :: res(size(p,1))
      
      res%w = q + p%w
      res%x = p%x
      res%y = p%y
      res%z = p%z
      res%a = p%a
      res%b = p%b
      res%c = p%c
      res%d = p%d

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION rPomat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      
      res%w = q + p%w
      res%x = p%x
      res%y = p%y
      res%z = p%z
      res%a = p%a
      res%b = p%b
      res%c = p%c
      res%d = p%d

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION oPovec(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(octn),   INTENT(IN)  :: q
      TYPE(octn),   INTENT(IN)  :: p(:)
      TYPE(octn)                :: res(size(p,1))
      INTEGER                   :: i
      

      DO i=1,size(p,1)

          res(i)%w = q%w + p(i)%w
          res(i)%x = q%x + p(i)%x
          res(i)%y = q%y + p(i)%y
          res(i)%z = q%z + p(i)%z
          res(i)%a = q%a + p(i)%a
          res(i)%b = q%b + p(i)%b
          res(i)%c = q%c + p(i)%c
          res(i)%d = q%d + p(i)%d

      END DO

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION oPomat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(octn),   INTENT(IN)  :: q
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q%w + p(i,j)%w
          res(i,j)%x = q%x + p(i,j)%x
          res(i,j)%y = q%y + p(i,j)%y
          res(i,j)%z = q%z + p(i,j)%z
          res(i,j)%a = q%a + p(i,j)%a
          res(i,j)%b = q%b + p(i,j)%b
          res(i,j)%c = q%c + p(i,j)%c
          res(i,j)%d = q%d + p(i,j)%d

        END DO
      END DO

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION omatPrmat(p,q)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q(:,:)
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      
      IF ((size(p,1) /= size(q,1)).or.(size(p,2) /= size(q,2))) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 

      res%x = p%x
      res%y = p%y
      res%z = p%z
      res%a = p%a
      res%b = p%b
      res%c = p%c
      res%d = p%d

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q(i,j) + p(i,j)%w
          
          
        END DO
      END DO

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION omatPr(p,q)&
      RESULT(res)
      IMPLICIT NONE
      REAL(REAL_KIND),   INTENT(IN)     :: q
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      
      res%x = p%x
      res%y = p%y
      res%z = p%z
      res%a = p%a
      res%b = p%b
      res%c = p%c
      res%d = p%d

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q + p(i,j)%w
          
        END DO
      END DO

  END FUNCTION

  ! Sum two quaternion matrices
  FUNCTION omatPo(p,q)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(octn),   INTENT(IN)  :: q
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(p,1),size(p,2))
      INTEGER                   :: i, j
      

      DO i=1,size(p,1)
        DO j=1,size(p,2)

          res(i,j)%w = q%w + p(i,j)%w
          res(i,j)%x = q%x + p(i,j)%x
          res(i,j)%y = q%y + p(i,j)%y
          res(i,j)%z = q%z + p(i,j)%z
          res(i,j)%a = q%a + p(i,j)%a
          res(i,j)%b = q%b + p(i,j)%b
          res(i,j)%c = q%c + p(i,j)%c
          res(i,j)%d = q%d + p(i,j)%d

        END DO
      END DO

  END FUNCTION


  ! Sum two quaternion matrices
  FUNCTION omatPomat(q,p)&
      RESULT(res)
      IMPLICIT NONE
      TYPE(octn),   INTENT(IN)  :: q(:,:)
      TYPE(octn),   INTENT(IN)  :: p(:,:)
      TYPE(octn)                :: res(size(q,1),size(q,2))
      INTEGER sizeqx, sizeqy, sizepx, sizepy

      sizeqx = size(q,1)
      sizeqy = size(q,2)
      sizepx = size(p,1)
      sizepy = size(p,2)

      IF ((sizeqx /= sizepx).or.(sizeqy /= sizepy)) THEN
        STOP "Invalid shape for adding quaternion matrices"
      END IF 

      res%w = q%w + p%w
      res%x = q%x + p%x
      res%y = q%y + p%y
      res%z = q%z + p%z
      res%a = q%a + p%a
      res%b = q%b + p%b
      res%c = q%c + p%c
      res%d = q%d + p%d

  END FUNCTION


  FUNCTION omatTrans_proc(q)&
    RESULT(qtrans)
    IMPLICIT NONE
    TYPE(octn),   INTENT(IN)  :: q(:,:)
    TYPE(octn)                :: qtrans(SIZE(q,2),SIZE(q,1))
    INTEGER :: i, j, sizeqx, sizeqy
    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)

    DO i=1,sizeqx
      DO j=1,sizeqy
        qtrans(j,i)= q(i,j)
      END DO
    END DO
  END FUNCTION


  FUNCTION omat2rmats(q) &
      RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN)  :: q(:,:)
    REAL(kind=8)              :: res(SIZE(q,1),SIZE(q,2),8)
    TYPE(octn)                :: qtemp
    
    INTEGER sizeqx, sizeqy, i, j

    sizeqx = SIZE(q,1)
    sizeqy = SIZE(q,2)

    ! print *, k
    
    DO i = 1, sizeqx

      DO j = 1, sizeqy
        
        qtemp = q(i,j)
        res(i,j,1) = qtemp%w
        res(i,j,2) = qtemp%x
        res(i,j,3) = qtemp%y
        res(i,j,4) = qtemp%z
        res(i,j,5) = qtemp%a
        res(i,j,6) = qtemp%b
        res(i,j,7) = qtemp%c
        res(i,j,8) = qtemp%d

      END DO

    END DO

  END FUNCTION





  FUNCTION omatXrmat(r,q)&
      RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: r(:,:)
    REAL(KIND=8), INTENT(IN) :: q(:,:)
    TYPE(octn)               :: res(SIZE(r,1),SIZE(q,2))
    TYPE(octn)               :: qtemp
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
      
        qtemp%w = 0.0_8 
        qtemp%x = 0.0_8 
        qtemp%y = 0.0_8 
        qtemp%z = 0.0_8 
        qtemp%a = 0.0_8 
        qtemp%b = 0.0_8 
        qtemp%c = 0.0_8 
        qtemp%d = 0.0_8 

        DO k = 1, sizery

          qtemp = qtemp + r(i,k) * q(k,j)

        END DO
        
        res(i,j) = qtemp

      END DO

    END DO

  END FUNCTION


  FUNCTION rmatXomat(r,q)&
      RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: q(:,:)
    REAL(KIND=8), INTENT(IN) :: r(:,:)
    TYPE(octn)               :: res(SIZE(r,1),SIZE(q,2))
    TYPE(octn)               :: qtemp
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
      
        qtemp%w = 0.0_8 
        qtemp%x = 0.0_8 
        qtemp%y = 0.0_8 
        qtemp%z = 0.0_8 
        qtemp%a = 0.0_8 
        qtemp%b = 0.0_8 
        qtemp%c = 0.0_8 
        qtemp%d = 0.0_8

        DO k = 1, sizery

          qtemp = qtemp + q(k,j) * r(i,k)

        END DO
        
        res(i,j) = qtemp

      END DO

    END DO

  END FUNCTION







  FUNCTION omatXomat(r,q)&
      RESULT(res)
    IMPLICIT NONE 
    TYPE(octn),   INTENT(IN) :: q(:,:)
    TYPE(octn)               :: qtemp
    TYPE(octn),   INTENT(IN) :: r(:,:)
    TYPE(octn)               :: res(SIZE(r,1),SIZE(q,2))
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
      
        qtemp%w = 0.0_8 
        qtemp%x = 0.0_8 
        qtemp%y = 0.0_8 
        qtemp%z = 0.0_8 
        qtemp%a = 0.0_8 
        qtemp%b = 0.0_8 
        qtemp%c = 0.0_8 
        qtemp%d = 0.0_8

        DO k = 1, sizery

          qtemp = qtemp + r(i,k) * q(k,j) 

        END DO

        res(i,j) = qtemp

      END DO

    END DO

  END FUNCTION

  !
  ! Returns the quarternion :math:`\mathbf{q}` added by scalar :math:`r`
  ! component-wise
  ! *q a quaternion
  ! *r a real scalar
  ! *qn q+r
  FUNCTION oplus(q,r) &
       RESULT(qn)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN) :: r
    TYPE(octn), INTENT(IN) :: q
    TYPE(octn) :: qn

    qn%w = q%w + r
    qn%x = q%x 
    qn%y = q%y 
    qn%z = q%z 
    qn%a = q%a 
    qn%b = q%b 
    qn%c = q%c 
    qn%d = q%d 

  END FUNCTION oplus

  ! Returns the quarternion :math:`\mathbf{q}` subtracted by scalar :math:`r`
  ! component-wise
  ! *q a quaternion
  ! *r a real scalar
  ! *qn q-r
  FUNCTION ominus(q,r) &
       RESULT(qn)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN) :: r
    TYPE(octn), INTENT(IN) :: q
    TYPE(octn) :: qn

    qn%w = q%w - r
    qn%x = q%x 
    qn%y = q%y 
    qn%z = q%z 
    qn%a = q%a  
    qn%b = q%b  
    qn%c = q%c  
    qn%d = q%d  

  END FUNCTION ominus

  FUNCTION oneg(q) RESULT(res)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN) :: q
    TYPE(octn)             :: res

    res%w = -q%w
    res%x = -q%x
    res%y = -q%y
    res%z = -q%z
    res%a = -q%a 
    res%b = -q%b 
    res%c = -q%c 
    res%d = -q%d 

  END FUNCTION

  ! Returns the quarternion :math:`\mathbf{q}` added by scalar :math:`r`
  ! component-wise
  ! *q a quaternion
  ! *r a real scalar
  ! *qn q+r
  FUNCTION oplusB(r,q) &
       RESULT(qn)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN) :: r
    TYPE(octn), INTENT(IN) :: q
    TYPE(octn) :: qn

    qn%w=q%w+r
    qn%x=q%x
    qn%y=q%y
    qn%z=q%z
    qn%a=q%a 
    qn%b=q%b 
    qn%c=q%c 
    qn%d=q%d 

  END FUNCTION oplusB































  ! ================================================================
  ! =============== ARITHMETIC OPERATIONS OCTONIONS ================
  ! ================================================================

  ! Returns the quarternion inverse of :math:`\mathbf{q}`: :math:`\mathbf{q}^*/||\mathbf{q}||`
  ! *q a quaternion
  ! *pdivq inverse of q  
  FUNCTION rdivo(r,q) &
       RESULT(pdivq)
    IMPLICIT NONE
    REAL(REAL_KIND) , INTENT(IN) :: r
    TYPE(octn), INTENT(IN) ::q
    TYPE(octn) :: rq,iq, pdivq
    rq = r
    
    iq = octn(      1.0d0/q%w, -q%x/(q%w*q%w), -q%y/(q%w*q%w), -q%z/(q%w*q%w),&
               -q%a/(q%w*q%w), -q%b/(q%w*q%w), -q%c/(q%w*q%w), -q%d/(q%w*q%w))
    pdivq = rq*iq

  END FUNCTION rdivo

  ! Returns the division of quarternions :math:`\mathbf{p}/\mathbf{q}`: :math:`\mathbf{p}\mathbf{q}^*/||\mathbf{q}||^2`
  ! *p a quaternion
  ! *q a quaternion
  ! *pdivq p / q  
  FUNCTION odivo(p,q) &
       RESULT(pdivq)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN) :: p,q
    TYPE(octn) :: iq, pdivq

    iq = octn(      1.0d0/q%w, -q%x/(q%w*q%w), -q%y/(q%w*q%w), -q%z/(q%w*q%w),&
               -q%a/(q%w*q%w), -q%b/(q%w*q%w), -q%c/(q%w*q%w), -q%d/(q%w*q%w))
    pdivq = p*iq

  END FUNCTION odivo

  ! Returns the power of a quarternion :math:`\mathbf{q}^n`
  ! component-wise
  ! *q a quaternion
  ! *n an integer scalar
  ! *qn q/r
  FUNCTION opow(o,n) &
       RESULT(on)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: n
    INTEGER :: i
    TYPE(octn), INTENT(IN) :: o
    TYPE(octn) :: on
    
    on%w = 1.0_8
    on%x = 0.0_8
    on%y = 0.0_8
    on%z = 0.0_8
    on%a = 0.0_8
    on%b = 0.0_8
    on%c = 0.0_8
    on%d = 0.0_8

    DO i=1,n
      on = on*o
    END DO

  END FUNCTION opow

  ! MISCELANEOUS FUNCTIONS

  ! Returns the squared quarternion norm of :math:`\mathbf{q}`: :math:`||\mathbf{q}||^2 = w^2+x^2+y^2+z^2`
  ! *q a quaternion
  ! *norm the norm of q **2
  FUNCTION onorm2(o) &
       RESULT(norm)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN):: o
    REAL(REAL_KIND) :: norm

    norm =  o%w*o%w + &
            o%x*o%x + &
            o%y*o%y + &
            o%z*o%z + &
            o%a*o%a + &
            o%b*o%b + &
            o%c*o%c + &
            o%d*o%d    

  END FUNCTION onorm2

  ! Returns the matrix form of the quarternion 
  ! *q a quaternion
  ! *q2mat
  FUNCTION o2mat(o) &
       RESULT(mat)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN):: o
    REAL(REAL_KIND) :: mat(8,8)
                

    mat(1,1) =  o%w
    mat(2,1) =  o%x
    mat(3,1) =  o%y
    mat(4,1) =  o%z
    mat(5,1) =  o%a
    mat(6,1) =  o%b
    mat(7,1) =  o%c
    mat(8,1) =  o%d

    mat(1,2) = 0.0d0
    mat(2,2) =  o%w
    mat(3,2) = 0.0d0
    mat(4,2) = 0.0d0
    mat(5,2) = 0.0d0
    mat(6,2) = 0.0d0
    mat(7,2) = 0.0d0
    mat(8,2) = 0.0d0

    mat(1,3) = 0.0d0
    mat(2,3) = 0.0d0
    mat(3,3) =  o%w
    mat(4,3) = 0.0d0
    mat(5,3) = 0.0d0
    mat(6,3) = 0.0d0
    mat(7,3) = 0.0d0
    mat(8,3) = 0.0d0

    mat(1,4) = 0.0d0
    mat(2,4) = 0.0d0
    mat(3,4) = 0.0d0
    mat(4,4) =  o%w
    mat(5,4) = 0.0d0
    mat(6,4) = 0.0d0
    mat(7,4) = 0.0d0
    mat(8,4) = 0.0d0

    mat(1,5) = 0.0d0
    mat(2,5) = 0.0d0
    mat(3,5) = 0.0d0
    mat(4,5) = 0.0d0
    mat(5,5) =  o%w
    mat(6,5) = 0.0d0
    mat(7,5) = 0.0d0
    mat(8,5) = 0.0d0

    mat(1,6) = 0.0d0
    mat(2,6) = 0.0d0
    mat(3,6) = 0.0d0
    mat(4,6) = 0.0d0
    mat(5,6) = 0.0d0
    mat(6,6) =  o%w
    mat(7,6) = 0.0d0
    mat(8,6) = 0.0d0

    mat(1,7) = 0.0d0
    mat(2,7) = 0.0d0
    mat(3,7) = 0.0d0
    mat(4,7) = 0.0d0
    mat(5,7) = 0.0d0
    mat(6,7) = 0.0d0
    mat(7,7) =  o%w
    mat(8,7) = 0.0d0

    mat(1,8) = 0.0d0
    mat(2,8) = 0.0d0
    mat(3,8) = 0.0d0
    mat(4,8) = 0.0d0
    mat(5,8) = 0.0d0
    mat(6,8) = 0.0d0
    mat(7,8) = 0.0d0
    mat(8,8) =  o%w

  END FUNCTION o2mat

  





! ================================================================
! =================   PRETTY PRINTING FUNCTIONS ==================
! ================================================================


  SUBROUTINE RPrint(q,fmt)
    IMPLICIT NONE
    REAL(REAL_KIND),   INTENT(IN) :: q
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


  SUBROUTINE RmatPrint(q,fmt)
    IMPLICIT NONE
    REAL(REAL_KIND),   INTENT(IN) :: q(:,:)
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






SUBROUTINE OPrint(q,fmt)
    IMPLICIT NONE
    TYPE(octn),   INTENT(IN) :: q
    CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:),ALLOCATABLE :: output_format


    IF (PRESENT(fmt)) THEN
      output_format = '('//trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//')'
    ELSE
      output_format = '(F8.3,F8.3,F8.3,F8.3,F8.3,F8.3,F8.3,F8.3)'
    END IF 


    write(*,output_format), &
      q%w,        &
      q%x,        &
      q%y,        &
      q%z,        &
      q%a,        &
      q%b,        &
      q%c,        &
      q%d

  END SUBROUTINE


  SUBROUTINE OmatPrint(q,fmt)
    IMPLICIT NONE
    TYPE(octn),   INTENT(IN) :: q(:,:)
    CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:),ALLOCATABLE :: output_format
    INTEGER  i, j

    IF (PRESENT(fmt)) THEN
      output_format = '(A,I4,A,I4,A,'//trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//')'
    ELSE
      output_format = '(A,I4,A,I4,A,F8.3,F8.3,F8.3,F8.3,F8.3,F8.3,F8.3,F8.3)'
    END IF

    DO i=1,SIZE(q,1)
      DO j=1,SIZE(q,2)
        
        write(*,output_format), &
          '(',i,',',j,')', &
          q(i,j)%w,        &
          q(i,j)%x,        &
          q(i,j)%y,        &
          q(i,j)%z,        &
          q(i,j)%a,        &
          q(i,j)%b,        &
          q(i,j)%c,        &
          q(i,j)%d

      END DO
    END DO

  END SUBROUTINE

  SUBROUTINE OvecPrint(q,fmt)
    IMPLICIT NONE
    TYPE(octn),   INTENT(IN) :: q(:)
    CHARACTER(len=*),  INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:),ALLOCATABLE :: output_format
    INTEGER  i


    IF (PRESENT(fmt)) THEN
      output_format = '(A,I4,A,'//trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//','// &
                                  trim(fmt)//')'
    ELSE
      output_format = '(A,I4,A,F8.3,F8.3,F8.3,F8.3,F8.3,F8.3,F8.3,F8.3)'
    END IF 

    DO i=1,SIZE(q,1)
        
        write(*,output_format), &
          '(',i,')', &
          q(i)%w,        &
          q(i)%x,        &
          q(i)%y,        &
          q(i)%z,        &
          q(i)%a,        &
          q(i)%b,        &
          q(i)%c,        &
          q(i)%d

    END DO

  END SUBROUTINE

  SUBROUTINE RvecPrint(q, fmt)
    IMPLICIT NONE
    REAL(REAL_KIND),   INTENT(IN) :: q(:)
    CHARACTER(len=16),  INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:),ALLOCATABLE :: output_format
    INTEGER  i

    IF (PRESENT(fmt)) THEN
      output_format = '(A,I4,A,'//trim(fmt)//')'
    ELSE
      output_format = '(A,I4,A,F8.3,F8.3,F8.3,F8.3)'
    END IF  

    DO i=1,SIZE(q,1)
        
        write(*,output_format), &
          '(',i,')', &
          q(i)

    END DO

  END SUBROUTINE


  ! Returns the quarternion :math:`\mathbf{q}` added by scalar :math:`r`
  ! component-wise
  ! *q a quaternion
  ! *r a real scalar
  ! *qn q+r
  FUNCTION opluso(o,p) &
       RESULT(on)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN) :: o,p
    TYPE(octn) :: on

    on%w = o%w + p%w
    on%x = o%x + p%x
    on%y = o%y + p%y
    on%z = o%z + p%z
    on%a = o%a + p%a
    on%b = o%b + p%b
    on%c = o%c + p%c
    on%d = o%d + p%d

  END FUNCTION opluso

  ! Returns the quarternion :math:`\mathbf{q}` subtracted by scalar :math:`r`
  ! component-wise
  ! *q a quaternion
  ! *r a real scalar
  ! *qn q-r
  FUNCTION ominuso(o,p) &
       RESULT(on)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN) :: o,p
    TYPE(octn) :: on

    on%w = o%w - p%w
    on%x = o%x - p%x
    on%y = o%y - p%y
    on%z = o%z - p%z
    on%a = o%a - p%a
    on%b = o%b - p%b
    on%c = o%c - p%c
    on%d = o%d - p%d

  END FUNCTION ominuso

 

  ! Returns the quarternion :math:`\mathbf{q}` subtracted by scalar :math:`r`
  ! component-wise
  ! *q a quaternion
  ! *r a real scalar
  ! *qn q-r
  FUNCTION ominusB(r,o) &
       RESULT(on)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN) :: r
    TYPE(octn), INTENT(IN) :: o
    TYPE(octn) :: on

    on%w = r - o%w
    on%x =   - o%x
    on%y =   - o%y
    on%z =   - o%z
    on%a =   - o%a
    on%b =   - o%b
    on%c =   - o%c
    on%d =   - o%d

  END FUNCTION ominusB


  
  ! Returns the quarternion :math:`\mathbf{q}` multiplied by scalar :math:`r`
  ! component-wise
  ! *q a quaternion
  ! *r a real scalar
  ! *qn r*q
  FUNCTION otimes(r,o) &
       RESULT(on)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN) :: r
    TYPE(octn), INTENT(IN) :: o
    TYPE(octn) :: on

    on%w = o%w*r
    on%x = o%x*r
    on%y = o%y*r
    on%z = o%z*r
    on%a = o%a*r
    on%b = o%b*r
    on%c = o%c*r
    on%d = o%d*r

  END FUNCTION otimes

  ! Returns the quarternion :math:`\mathbf{q}` multiplied by scalar :math:`r`
  ! component-wise
  ! *q a quaternion
  ! *r a real scalar
  ! *qn q*r
  FUNCTION otimesB(o,r) &
       RESULT(on)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN) :: r
    TYPE(octn), INTENT(IN) :: o
    TYPE(octn) :: on

    on%w = o%w*r
    on%x = o%x*r
    on%y = o%y*r
    on%z = o%z*r
    on%a = o%a*r
    on%b = o%b*r
    on%c = o%c*r
    on%d = o%d*r

  END FUNCTION otimesB


  ! Returns the quarternion :math:`\mathbf{q}` divided by scalar :math:`r`
  ! component-wise
  ! *q a quaternion
  ! *r a real scalar
  ! *qn q/r
  FUNCTION odiv(o,r) &
       RESULT(on)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN) :: r
    TYPE(octn), INTENT(IN) :: o
    TYPE(octn) :: on

    on%w = o%w/r
    on%x = o%x/r
    on%y = o%y/r
    on%z = o%z/r
    on%a = o%a/r
    on%b = o%b/r
    on%c = o%c/r
    on%d = o%d/r

  END FUNCTION odiv

  ! Returns the quarternion product :math:`\mathbf{q}_1\mathbf{q}_2`
  ! Note that the product is non-commutative:  :math:`\mathbf{q}_1\mathbf{q}_2 \ne \mathbf{q}_2\mathbf{q}_1`
  ! *q1 a quaternion
  ! *q2 a quaternion
  ! *qn q1*q2
  FUNCTION oprod(o1,o2) &
       RESULT(on)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN) :: o1, o2
    TYPE(octn) :: on
    
    on%w = o1%w*o2%w 
    on%x = o1%w*o2%x + o1%x*o2%w 
    on%y = o1%w*o2%y + o1%y*o2%w 
    on%z = o1%w*o2%z + o1%z*o2%w 
    on%a = o1%w*o2%a + o1%a*o2%w 
    on%b = o1%w*o2%b + o1%b*o2%w 
    on%c = o1%w*o2%c + o1%c*o2%w 
    on%d = o1%w*o2%d + o1%d*o2%w
                                          

  END FUNCTION oprod

  ! Returns the quarternion conjugate of :math:`\mathbf{q}`: :math:`\mathbf{q}^* = w+x\mathbf{i}+y\mathbf{j}+z\mathbf{k} \to w-x\mathbf{i}-y\mathbf{j}-z\mathbf{k}`
  ! *q a quaternion
  ! *cq conjugate of q
  FUNCTION oconj(o) &
       RESULT(co)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN) :: o
    TYPE(octn) :: co

    co%w =  o%w
    co%x = -o%x
    co%y = -o%y
    co%z = -o%z
    co%a = -o%a
    co%b = -o%b
    co%c = -o%c
    co%d = -o%d

  END FUNCTION oconj

  ! Returns the quarternion norm of :math:`\mathbf{q}`: :math:`||\mathbf{q}|| = \sqrt{w^2+x^2+y^2+z^2}`
  ! *q a quaternion
  ! *norm the norm of q
  FUNCTION onorm(o) &
       RESULT(norm)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN):: o
    REAL(REAL_KIND) :: norm

    norm = sqrt(o%w*o%w + &
                o%x*o%x + &
                o%y*o%y + &
                o%z*o%z + &
                o%a*o%a + &
                o%b*o%b + &
                o%c*o%c + &
                o%d*o%d    )

  END FUNCTION onorm

  ! Returns the quarternion inverse of :math:`\mathbf{q}`: :math:`\mathbf{q}^*/||\mathbf{q}||`
  ! *q a quaternion
  ! *iq inverse of q  
  FUNCTION oinv(o) &
       RESULT(io)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN) :: o
    TYPE(octn) :: io

    io = oconj(o)/onorm(o)

  END FUNCTION oinv






  ! INITIALIZATION

  ! Initialize an octonion number value 
  SUBROUTINE OINITr(c,res)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN):: c ! Real coefficient to initialize real coeff only
    TYPE(octn), INTENT(INOUT)  :: res

    res%w = c
    res%x = 0.0d0
    res%y = 0.0d0
    res%z = 0.0d0
    res%a = 0.0d0
    res%b = 0.0d0
    res%c = 0.0d0
    res%d = 0.0d0

  END SUBROUTINE

  ! Initialize an octonion number value 
  SUBROUTINE OvecINITr(c,res)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN):: c ! Real coefficient to initialize real coeff only
    TYPE(octn), INTENT(INOUT)  :: res(:)

    res%w = c
    res%x = 0.0d0
    res%y = 0.0d0
    res%z = 0.0d0
    res%a = 0.0d0
    res%b = 0.0d0
    res%c = 0.0d0
    res%d = 0.0d0

  END SUBROUTINE

  ! Initialize an octonion number value 
  SUBROUTINE OmatINITr(c,res)
    IMPLICIT NONE
    REAL(REAL_KIND), INTENT(IN):: c ! Real coefficient to initialize real coeff only
    TYPE(octn), INTENT(INOUT)  :: res(:,:)

    res%w = c
    res%x = 0.0d0
    res%y = 0.0d0
    res%z = 0.0d0
    res%a = 0.0d0
    res%b = 0.0d0
    res%c = 0.0d0
    res%d = 0.0d0

  END SUBROUTINE



  ! Initialize an octonion number value 
  SUBROUTINE OINITo(c,res)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN)     :: c ! Real coefficient to initialize real coeff only
    TYPE(octn), INTENT(INOUT)  :: res

    res%w = c%w
    res%x = c%x
    res%y = c%y
    res%z = c%z
    res%a = c%a
    res%b = c%b
    res%c = c%c
    res%d = c%d

  END SUBROUTINE

  ! Initialize an octonion number value 
  SUBROUTINE OvecINITo(c,res)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN)    :: c ! Real coefficient to initialize real coeff only
    TYPE(octn), INTENT(INOUT) :: res(:)

    res%w = c%w
    res%x = c%x
    res%y = c%y
    res%z = c%z
    res%a = c%a
    res%b = c%b
    res%c = c%c
    res%d = c%d

  END SUBROUTINE

  ! Initialize an octonion number value 
  SUBROUTINE OmatINITo(c,res)
    IMPLICIT NONE
    TYPE(octn), INTENT(IN)    :: c ! Real coefficient to initialize real coeff only
    TYPE(octn), INTENT(INOUT) :: res(:,:)

    res%w = c%w
    res%x = c%x
    res%y = c%y
    res%z = c%z
    res%a = c%a
    res%b = c%b
    res%c = c%c
    res%d = c%d

  END SUBROUTINE

END MODULE octonions
