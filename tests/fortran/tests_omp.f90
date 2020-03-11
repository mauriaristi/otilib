PROGRAM TESTS_OMP
    
    USE OMP_LIB

    IMPLICIT NONE



    INTEGER :: I=1,J=2,K=3, F(10)

    F = 0

    !$OMP PARALLEL
        print*, "Hello from thread: ",OMP_GET_THREAD_NUM()
        F(OMP_GET_THREAD_NUM()+1) = 3*OMP_GET_THREAD_NUM()
    !$OMP END PARALLEL

    PRINT*, F

    !$OMP PARALLEL SECTIONS
    !$OMP SECTION
        PRINT*, I,OMP_GET_THREAD_NUM()
    !$OMP SECTION
        PRINT*, J,OMP_GET_THREAD_NUM()
    !$OMP SECTION
        PRINT*, K,OMP_GET_THREAD_NUM()
    !$OMP END PARALLEL SECTIONS


! INTEGER :: thread_id, i

! !$OMP PARALLEL PRIVATE(thread_id)

!     thread_id = OMP_GET_THREAD_NUM()

!     DO i=0,OMP_GET_MAX_THREADS()
!         IF (i == thread_id) THEN
!             PRINT *, "Hello from process: ", thread_id
!         END IF
!         !$OMP BARRIER
!     END DO
! !$OMP END PARALLEL




END PROGRAM TESTS_OMP
