PROGRAM  test

    use sparse_oti


    TYPE(sotinum) :: x


    x = (3.5d0 +  eps(1,order=2) )* 8.0d0

    CALL PPRINT(x)


END PROGRAM test