PROGRAM test_version

    USE oti_version

    IMPLICIT NONE

    CHARACTER(LEN=32) :: rebuilt
    INTEGER           :: packed

    ! The version components must reconstruct the version string.
    WRITE(rebuilt, '(I0,".",I0,".",I0)') OTI_VERSION_MAJOR, OTI_VERSION_MINOR, OTI_VERSION_PATCH

    IF (TRIM(rebuilt) /= OTI_VERSION_STRING) THEN
        WRITE(*,*) "Version test failed: components give ", TRIM(rebuilt), &
                   " but string is ", OTI_VERSION_STRING
        STOP 1
    END IF

    ! The packed version must match the encoding used by the C and Python bindings.
    packed = OTI_VERSION_MAJOR * 10000 + OTI_VERSION_MINOR * 100 + OTI_VERSION_PATCH

    IF (OTI_VERSION_NUMBER /= packed) THEN
        WRITE(*,*) "Version test failed: packed version does not encode the components"
        STOP 1
    END IF

    WRITE(*,*) "Fortran version test passed successfully (OTIlib ", OTI_VERSION_STRING, ")."

END PROGRAM test_version
