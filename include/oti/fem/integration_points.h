#ifndef OTI_FEM_INTEGRATION_POINTS_H
#define OTI_FEM_INTEGRATION_POINTS_H

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





#endif