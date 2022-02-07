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

  FUNCTION {type_name}_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE({type_name}), INTENT(IN) :: X
      TYPE({type_name}) :: RES

      RES = X**0.5_DP

  END FUNCTION {type_name}_SQRT