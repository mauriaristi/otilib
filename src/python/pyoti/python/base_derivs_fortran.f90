  PURE FUNCTION DER_R_COS( X ) RESULT(DERIVS)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER+1)
      REAL(DP), INTENT(IN) :: X
      INTEGER :: I
      INTEGER :: S
      INTEGER :: SIGN
      
      SIGN = 1
      S = 0

      DO I = 1,TORDER+1
      
          IF (S == 0) THEN
              DERIVS(I) = SIGN * COS(X)
          ELSE
              SIGN = SIGN * (-1);
              DERIVS(I) = SIGN * SIN(X)
          END IF 
      
          S = MOD((S+1),2)
       
      END DO

  END FUNCTION DER_R_COS

  PURE FUNCTION DER_R_SIN( X ) RESULT(DERIVS)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER+1)
      REAL(DP), INTENT(IN) :: X
      INTEGER :: I
      INTEGER :: S 
      INTEGER :: SIGN 
      
      SIGN = -1
      S = 1
      DO I = 1,TORDER+1
      
          IF (S == 0) THEN
              DERIVS(I) = SIGN * COS(X)
          ELSE
              SIGN = SIGN * (-1)
              DERIVS(I) = SIGN * SIN(X)
          END IF 
      
          S = MOD((S+1),2)
       
      END DO

  END FUNCTION DER_R_SIN

  PURE FUNCTION DER_R_LOG( X ) RESULT (DERIVS)
      IMPLICIT NONE  
      REAL(DP) :: DERIVS(TORDER+1)
      REAL(DP), INTENT(IN) :: X

      INTEGER :: SIGN 
      REAL(DP):: FACTOR 
      INTEGER :: I    

      SIGN = -1
      FACTOR = 1.0_DP

      DERIVS(1) = LOG(X)

      DO I = 2,TORDER +1
                   
          DERIVS(I) = FACTOR * SIGN**(I+1) / (X**I)
          FACTOR    = FACTOR * I
          
      END DO

  END FUNCTION DER_R_LOG

  PURE FUNCTION DER_R_EXP( X ) RESULT (DERIVS)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER+1)
      REAL(DP), INTENT(IN) :: X
      REAL(DP) :: VAL 
      INTEGER I

      VAL = EXP(X)

      DO I=1,TORDER+1
          DERIVS(I) = VAL
      END DO

  END FUNCTION DER_R_EXP

  PURE FUNCTION DER_R_POW( X, E ) RESULT (DERIVS)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: X ! Value
      REAL(DP), INTENT(IN) :: E ! Exponent
      REAL(DP) :: DERIVS(TORDER+1)
      REAL(DP) :: POWER_I 
      REAL(DP) :: X0 
      INTEGER  :: FLAG 
      REAL(DP) :: FACTOR
      INTEGER  ::  I
      
      POWER_I = E
      X0 = X
      FLAG = 0
      FACTOR = 1.0_DP

      DO I=1, TORDER+1
          IF( POWER_I /= 0.0_DP) THEN
              DERIVS(I) = FACTOR * ( X0 ** POWER_I )
              FACTOR = FACTOR*POWER_I
              POWER_I = POWER_I - 1
          ELSE
              IF (FLAG == 0 ) THEN
                  DERIVS(I) = FACTOR
                  FLAG = 1
              ELSE
                  DERIVS(I) = 0.0_DP
              END IF 
          END IF 
      END DO
  END FUNCTION DER_R_POW

  FUNCTION {type_name}_SIN(X) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      TYPE({type_name}) :: RES

      DERIVS = DER_R_SIN( X%R )

      RES = FEVAL(X,DERIVS)

  END FUNCTION {type_name}_SIN

  FUNCTION {type_name}_COS(X) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      TYPE({type_name}) :: RES

      DERIVS = DER_R_COS( X%R )

      RES = FEVAL(X,DERIVS)

  END FUNCTION {type_name}_COS

  FUNCTION {type_name}_LOG(X) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      TYPE({type_name}) :: RES

      DERIVS = DER_R_LOG( X%R )

      RES = FEVAL(X,DERIVS)

  END FUNCTION {type_name}_LOG

  FUNCTION {type_name}_EXP(X) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      TYPE({type_name}) :: RES

      DERIVS = DER_R_EXP( X%R )

      RES = FEVAL(X,DERIVS)

  END FUNCTION {type_name}_EXP

  FUNCTION {type_name}_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: X
      TYPE({type_name}) :: RES

      RES = X**0.5_DP

  END FUNCTION {type_name}_SQRT

  FUNCTION {type_name}_POW(X,E) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      TYPE({type_name}) :: RES

      DERIVS = DER_R_POW( X%R, E )

      RES = FEVAL(X,DERIVS)

  END FUNCTION {type_name}_POW

  FUNCTION {type_name}_POW_R4(X,E) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      REAL(4), INTENT(IN) :: E
      TYPE({type_name}) :: RES

      DERIVS = DER_R_POW( X%R, E )

      RES = FEVAL(X,DERIVS)

  END FUNCTION {type_name}_POW_R4

  FUNCTION {type_name}_POW_I8(X,E) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      INTEGER(8), INTENT(IN) :: E
      TYPE({type_name}) :: RES

      DERIVS = DER_R_POW( X%R, REAL(E,DP) )

      RES = FEVAL(X,DERIVS)

  END FUNCTION {type_name}_POW_I8

  FUNCTION {type_name}_POW_I4(X,E) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      INTEGER(4), INTENT(IN) :: E
      TYPE({type_name}) :: RES

      DERIVS = DER_R_POW( X%R, REAL(E,DP) )

      RES = FEVAL(X,DERIVS)

  END FUNCTION {type_name}_POW_I4


  FUNCTION {type_name}_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      TYPE({type_name}), INTENT(IN) :: Y
      TYPE({type_name}) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION {type_name}_DIVISION_OO

  FUNCTION {type_name}_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE({type_name}), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE({type_name}) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION {type_name}_DIVISION_OR

  FUNCTION {type_name}_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
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

  SUBROUTINE {type_name}_PPRINT_M_R(X, FMT)
      IMPLICIT NONE
      REAL(DP),INTENT(IN) :: X(:,:)
      INTEGER :: I, J
      CHARACTER(*),INTENT(IN),OPTIONAL :: FMT
      CHARACTER(:),ALLOCATABLE :: out_fmt
      
      IF (PRESENT(fmt)) THEN
        out_fmt = fmt
      ELSE
        out_fmt = 'F10.4'
      END IF
      
      write(*,'(A)',advance='no') "["
      
      DO I=1,SIZE(X,1)
        
        IF (I == 1) THEN
          write(*,'(A)',advance='no') "["
        ELSE
          write(*,'(A)',advance='no') " ["
        END IF 

        DO J=1,SIZE(X,2)
          
          write(*,'('//trim(out_fmt)//')',advance='no') X(I,J)

        END DO
        
        write(*,'(A)') "]"
      
      END DO

      write(*,'(A)') "]"

  END SUBROUTINE {type_name}_PPRINT_M_R

  SUBROUTINE {type_name}_PPRINT_V_R(X, FMT)
      IMPLICIT NONE
      REAL(DP),INTENT(IN) :: X(:)
      INTEGER :: I
      CHARACTER(*),INTENT(IN),OPTIONAL :: FMT
      CHARACTER(:),ALLOCATABLE :: out_fmt
      
      IF (PRESENT(fmt)) THEN
        out_fmt = fmt
      ELSE
        out_fmt = 'F10.4'
      END IF
      
      write(*,'(A)',advance='no') "["
      
      DO I=1,SIZE(X,1)

        write(*,'('//trim(out_fmt)//')',advance='no') X(I)

      END DO

      write(*,'(A)') "]"

  END SUBROUTINE {type_name}_PPRINT_V_R
