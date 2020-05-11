#ifndef OTI_FEM_BASIS_FUNCTIONS_H
#define OTI_FEM_BASIS_FUNCTIONS_H

// FEM basis Functions.




int64_t fem_basisFunctions_N_QuadSerendP2_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis);
// ----------------------------------------------------------------------------------------------------



int64_t fem_basisFunctions_N_QuadP1_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis);
// ----------------------------------------------------------------------------------------------------



int64_t fem_basisFunctions_N_TriangP2_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis);
// ----------------------------------------------------------------------------------------------------



int64_t fem_basisFunctions_N_TriangP1_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis);
// ----------------------------------------------------------------------------------------------------



int64_t fem_basisFunctions_N_TriangP0_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis);
// ----------------------------------------------------------------------------------------------------



int64_t fem_basisFunctions_N_LineP2_1Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis);
// ----------------------------------------------------------------------------------------------------



int64_t fem_basisFunctions_N_LineP1_1Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis);
// ----------------------------------------------------------------------------------------------------



int64_t fem_basisFunctions_N_PntP0_0Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis);
// ----------------------------------------------------------------------------------------------------



#endif