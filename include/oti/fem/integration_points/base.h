


// Integration points.

int64_t fem_integrationPoints(uint64_t order, int64_t elementType, 
                                darr_t* coords, darr_t* weights);
// ----------------------------------------------------------------------------------------------------



uint64_t fem_addLineIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a,  double w,
                                           darr_t* coords, darr_t* weights);
// ----------------------------------------------------------------------------------------------------



uint64_t fem_addTriangleIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a, double b, double c, double w,
                                           darr_t* coords, darr_t* weights);
// ----------------------------------------------------------------------------------------------------



uint64_t fem_addTetrahedraIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a, double b, double c,  double d, double w,
                                           darr_t* coords, darr_t* weights);
// ----------------------------------------------------------------------------------------------------









int64_t fem_intPts_soti( uint64_t order, int64_t elementType, 
                         fesoti_t*  xi,   fesoti_t*   eta,   fesoti_t* zeta, 
                         fesoti_t* weights, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------








uint64_t fem_addLineIntPts_soti(uint8_t nperm, uint64_t start, double a,  double w,
                                fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta, 
                                fesoti_t* weights, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------







uint64_t fem_addTriangleIntPts_soti(uint8_t nperm, uint64_t start, 
                                    double a, double b, double c, double w,
                                    fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta, 
                                    fesoti_t* weights, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------





uint64_t fem_addTetrahedraIntPts_soti(uint8_t nperm, uint64_t start, 
                                      double a, double b, double c, double d, double w,
                                      fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta, 
                                      fesoti_t* weights, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------





