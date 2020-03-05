module mod
  IMPLICIT NONE
  integer i
  integer :: x(4)
  real, dimension(2,3) :: a
  
  type dual
    real*8 re
    real*8 e1
  end type 

  ! real, allocatable, dimension(:,:) :: b 
contains
  subroutine faa
    IMPLICIT NONE
    integer :: k=35 
    print*, "k=",k
  end subroutine faa

  subroutine foo
    IMPLICIT NONE
    integer :: k
    print*, "i=",i
    print*, "x=[",x,"]"
    print*, "a=["
    print*, "[",a(1,1),",",a(1,2),",",a(1,3),"]"
    print*, "[",a(2,1),",",a(2,2),",",a(2,3),"]"
    print*, "]"
    print*, "Setting a(1,2)=a(1,2)+3"
    CALL faa()
    a(1,2) = a(1,2)+3
  end subroutine foo

  subroutine print_dual(a,b)
    IMPLICIT NONE
    real*8, intent(in) :: a
    real*8, intent(in) :: b
    TYPE(dual) :: x
    x%re = a
    x%e1 = b

    print*, "re: ",x%re," , ",x%e1

  end subroutine print_dual
end module mod