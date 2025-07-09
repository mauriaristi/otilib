PROGRAM ex3_static_m1n2

   USE otim1n2

   IMPLICIT NONE

   TYPE(onumm1n2) :: x, f
   TYPE(onumm1n2) :: y

   TYPE(onumm1n2) :: M(2)

   REAL(8) :: Mr(2)
   
   x = 3.14d0/2.1d0 + E1

   f = tan(x)

   CALL PPRINT(f)

   x = 4.0d0 + E1
   y = x ** 2.0d0

   CALL PPRINT(y)


   ! =====================================================================================================
   WRITE(*,*) "output: ", y==x

   M(1) = x
   M(2) = y

   CALL PPRINT(M)
   WRITE(*,*) " ============================================== "

   WRITE(*,*) "output M==y: "
   WRITE(*,*) M == y

   WRITE(*,*) "output M==y%r: "
   WRITE(*,*) M == y%r

   WRITE(*,*) "output y%r == M "
   WRITE(*,*)  y%r == M

   WRITE(*,*) " ============================================== "
   WRITE(*,*) "output M/=y: "
   WRITE(*,*) M /= y

   WRITE(*,*) "output M/=y%r: "
   WRITE(*,*) M /= y%r

   WRITE(*,*) "output y%r /= M "
   WRITE(*,*)  y%r /= M

   WRITE(*,*) " ============================================== "
   y = 13.5d0
   WRITE(*,*) "output M>=y: "
   WRITE(*,*) M >= y

   WRITE(*,*) "output M>=y%r: "
   WRITE(*,*) M >= y%r

   WRITE(*,*) "output y%r >= M "
   WRITE(*,*)  y%r >= M

   ! =====================================================================================================

   Mr = M%r
   
   
   WRITE(*,*) " ============================================== "

   CALL PPRINT(Mr)

   WRITE(*,*) "output Mr==y%r: "
   WRITE(*,*) Mr == y%r


   WRITE(*,*) "output Mr/=y%r: "
   WRITE(*,*) Mr /= y%r


   WRITE(*,*) " ============================================== "

   CALL PPRINT(Mr)

   WRITE(*,*) "output MAXLOC(Mr) "
   WRITE(*,*) MAXLOC(Mr)


   WRITE(*,*) "output  MAXLOC(M) "
   WRITE(*,*) MAXLOC(M)
   
   ! =====================================================================================================

   WRITE(*,*) " ============================================== "

   CALL PPRINT(Mr)

   WRITE(*,*) "output MAXVAL(Mr) "
   WRITE(*,*) MAXVAL(Mr)


   WRITE(*,*) "output  MAXVAL(M) "
   WRITE(*,*) MAXVAL(M)

   WRITE(*,*) " ============================================== "

   CALL PPRINT(Mr)

   WRITE(*,*) "output MINVAL(Mr) "
   WRITE(*,*) MINVAL(Mr)


   WRITE(*,*) "output  MINVAL(M) "
   WRITE(*,*) MINVAL(M)

END PROGRAM ex3_static_m1n2