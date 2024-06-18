PROGRAM basic_scalar

   USE otim1n3

   IMPLICIT NONE

   TYPE(onumm1n3) :: x, f


   x = 3.14d0/2.1d0 + E1

   f = tan(x)

   CALL PPRINT(f)

END PROGRAM basic_scalar