


// Integration points.






int64_t fem_intPts_real( uint64_t order, int64_t elementType, 
                         fednum_t*  xi,   fednum_t*   eta,   fednum_t* zeta, 
                         fednum_t* weights );
// ----------------------------------------------------------------------------------------------------








uint64_t fem_addLineIntPts_real(uint8_t nperm, uint64_t start, double a,  double w,
                                fednum_t* xi, fednum_t* eta, fednum_t* zeta, 
                                fednum_t* weights );
// ----------------------------------------------------------------------------------------------------







uint64_t fem_addTriangleIntPts_real(uint8_t nperm, uint64_t start, 
                                    double a, double b, double c, double w,
                                    fednum_t* xi, fednum_t* eta, fednum_t* zeta, 
                                    fednum_t* weights );
// ----------------------------------------------------------------------------------------------------





uint64_t fem_addTetrahedraIntPts_real(uint8_t nperm, uint64_t start, 
                                      double a, double b, double c, double d, double w,
                                      fednum_t* xi, fednum_t* eta, fednum_t* zeta, 
                                      fednum_t* weights );
// ----------------------------------------------------------------------------------------------------





