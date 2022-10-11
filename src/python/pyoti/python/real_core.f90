MODULE master_real_module

    USE iso_fortran_env

    PUBLIC

    INTEGER, PARAMETER :: sp = SELECTED_REAL_KIND(6, 37)
    INTEGER, PARAMETER :: dp = SELECTED_REAL_KIND(15, 307)
    INTEGER, PARAMETER :: qp = SELECTED_REAL_KIND(33, 4931)

    CHARACTER(len=:), ALLOCATABLE :: base_print_format = 'F10.4'
    
    ! *********************************************************************
    INTERFACE PPRINT
        MODULE PROCEDURE real_pprint_m, real_pprint_v
    END INTERFACE
    ! =====================================================================

CONTAINS

    ! *********************************************************************
    SUBROUTINE set_default_print_format()
        ! -----------------------------------------------------------------
        ! -----------------------------------------------------------------
        IMPLICIT NONE
        
        base_print_format = 'F10.4'

    END SUBROUTINE set_default_print_format
    ! =====================================================================

    ! *********************************************************************
    SUBROUTINE set_print_format(fmt)
        ! -----------------------------------------------------------------
        !
        ! -----------------------------------------------------------------
        IMPLICIT NONE
        CHARACTER(*),INTENT(IN)   :: FMT

        
        base_print_format = TRIM(base_print_format)


    END SUBROUTINE set_print_format
    ! =====================================================================

    ! *********************************************************************
    SUBROUTINE real_pprint_m(X, fmt)
        ! -----------------------------------------------------------------

        ! -----------------------------------------------------------------
        IMPLICIT NONE
        REAL(dp),INTENT(IN) :: X(:,:)
        INTEGER :: i, j
        CHARACTER(*),INTENT(IN), OPTIONAL :: fmt
        CHARACTER(:), ALLOCATABLE :: out_fmt

        IF (PRESENT(fmt)) THEN
            out_fmt = fmt
        ELSE
            out_fmt = TRIM(base_print_format)
        END IF

        write(*,'(A)',advance='no') "["

        DO i=1,SIZE(X,1)

            IF (i == 1) THEN
                write(*,'(A)',advance='no') "["
            ELSE
                write(*,'(A)',advance='no') " ["
            END IF 

            DO j=1,SIZE(X,2)
              
                write(*,'('//trim(out_fmt)//')',advance='no') X(i,j)

            END DO

            write(*,'(A)') "]"

        END DO

        write(*,'(A)') "]"

    END SUBROUTINE real_pprint_m
    ! =====================================================================

    ! *********************************************************************
    SUBROUTINE real_pprint_m(X, fmt, unit)
        ! -----------------------------------------------------------------
        ! @brief This function prints to console a matrix of real double 
        !        precision numbers.
        !
        ! @param[in] X:   Rank 2 array of double precision numbers.
        ! @param[in] fmt: [Optional] String with the desired format to 
        !                 print the real values.
        ! @param[in] fmt: [Optional] Unit string to .
        ! Prints to "*"
        ! -----------------------------------------------------------------
        IMPLICIT NONE
        REAL(dp),INTENT(IN) :: X(:,:)
        INTEGER :: i, j
        CHARACTER(*),INTENT(IN),OPTIONAL :: fmt
        CHARACTER(*),INTENT(IN),OPTIONAL :: unit
        CHARACTER(:), ALLOCATABLE :: out_fmt
        CHARACTER(:), ALLOCATABLE :: out_style


        IF (PRESENT(fmt)) THEN
            out_fmt = fmt
        ELSE
            out_fmt = TRIM(base_print_format)
        END IF

        IF (PRESENT(unit)) THEN
            out_unit = unit
        ELSE
            out_unit = OUTPUT_UNIT
        END IF

        write(out_unit,'(A)',advance='no') "["

        DO i = 1, SIZE(X,1)

            IF (i == 1) THEN
                write(out_unit,'(A)',advance='no') "["
            ELSE
                write(out_unit,'(A)',advance='no') " ["
            END IF

            DO j = 1, SIZE(X,2)
              
                write(out_unit,'('//trim(out_fmt)//')',advance='no') X(i,j)

            END DO

            write(out_unit,'(A)') "]"

        END DO

        write(out_unit,'(A)') "]"

    END SUBROUTINE real_pprint_m
    ! =====================================================================

    ! *********************************************************************
    SUBROUTINE real_pprint_v(x, fmt)
        ! -----------------------------------------------------------------
        !
        ! -----------------------------------------------------------------
        IMPLICIT NONE
        REAL(dp),INTENT(IN) :: x(:)
        INTEGER :: i
        CHARACTER(*),INTENT(IN),OPTIONAL :: fmt
        CHARACTER(:),ALLOCATABLE :: out_fmt
      
        IF (PRESENT(fmt)) THEN
            out_fmt = fmt
        ELSE
            out_fmt = 'F10.4'
        END IF
      
        write(*,'(A)',advance='no') "["

        DO i = 1, SIZE(x,1)

            write(*,'('//trim(out_fmt)//')',advance='no') x(i)

        END DO

        write(*,'(A)') "]"

    END SUBROUTINE real_pprint_v
    ! =====================================================================


END MODULE master_real_module