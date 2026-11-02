// fem basis functions (include/oti/fem/basis_functions.h). Phase 6a (PLAN-ndarray.md): the darr_t
// arguments are read and written through borrowed ndarr_t views (nd_from_darr(ND_DARR_BORROW),
// include/oti/real/ndarray/compat_darr.h); errors are OTI_OK / OTI_ERR_* statuses (contracts 4.1),
// never the legacy enum oti_errors, never printf / exit(). The public signatures are unchanged.
// File-static prefix: femb_.

#include "oti/real/ndarray.h"
#include "oti/real/ndarray/compat_darr.h"


// *******************************************************************************************************
// Borrowed views of the coordinates (ncoords x >= ndim) and of the result (>= basisId + 1 rows x
// >= ncoords columns) of one basis function, with the checks the legacy darr_get / darr_set did by
// exit(): an unknown basisId is OTI_ERR_INDEX, a coords array with fewer than ndim columns is
// OTI_ERR_SHAPE, a result without row basisId or without ncoords columns is OTI_ERR_INDEX.
static int64_t femb_views(int64_t basisId, int64_t nbasis, int64_t ndim, darr_t* coords,
                          darr_t* evalBasis, ndarr_t* c, ndarr_t* e){

    int st;

    if (basisId < 0 || basisId >= nbasis){
        return OTI_ERR_INDEX;
    }
    nd_init_empty(c);
    nd_init_empty(e);
    st = nd_from_darr(NULL, coords, ND_DARR_BORROW, c);
    if (st == OTI_OK){
        st = nd_from_darr(NULL, evalBasis, ND_DARR_BORROW, e);
    }
    if (st != OTI_OK){
        return st;
    }
    if (c->shape[1] < ndim){
        return OTI_ERR_SHAPE;
    }
    if (e->shape[0] <= basisId || e->shape[1] < c->shape[0]){
        return OTI_ERR_INDEX;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Coordinate k of point i.
static inline double femb_get(const ndarr_t* c, int64_t i, int64_t k){

    return nd_f64(c)[i * c->strides[0] + k * c->strides[1]];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// evalBasis(row, col) = v.
static inline void femb_set(ndarr_t* e, int64_t row, int64_t col, double v){

    nd_f64(e)[row * e->strides[0] + col * e->strides[1]] = v;

}
// -------------------------------------------------------------------------------------------------------







// ****************************************************************************************************
int64_t fem_basisFunctions_N_QuadSerendP2_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis){
    /*
    fem_basisFunctions_N_QuadSerendP2_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the serendipity 2D element.


    NODE NUMBERING:

                           (3)* *(6)* *(2) 
                            *           *
                            *           *
                           (7)         (5)
                            *           *
                            *           *
                           (0)* *(4)* *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, ..., 8. (N1, ..., N8)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN    , derNa  , derNaa
                        derNb   , derNab , derNbb
                        derNc   , derNac , 
                        derNbc  , derNcc ,  
                        

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     (ncoords x ndim) array with the  data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    SOURCE:
        
        -> http://www.pckingsford.com/cykchee/phd/chD.pdf

    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    int64_t i, ncoords, st;
    ndarr_t c, e;
    double xi, eta, evalBasis_i=0.0;

    // Borrowed ndarray views of coords and evalBasis (Phase 6a); basisId and the shapes are checked
    // (statuses instead of the legacy codes and exit()).
    st = femb_views(basisId, 8, 2, coords, evalBasis, &c, &e);
    if (st != OTI_OK){
        return st;
    }
    ncoords = c.shape[0];

    for(i=0; i<ncoords; i++){

        xi  = femb_get(&c, i, 0);
        eta = femb_get(&c, i, 1);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0-xi)*(1.0-eta)*(1.+xi+eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(-1.+eta)*(2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(-1.+xi)*(xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.-eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.-xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(1-2.*xi-2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0+xi)*(1.0-eta)*(1.-xi+eta);  

            }else if (basisDer == derNa){

                evalBasis_i = 0.25*(-1.+eta)*(-2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.25*(1.+xi)*(-xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.-eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(-1-2.*xi+2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0+xi)*(1.0+eta)*(1.-xi-eta);  

            }else if (basisDer == derNa){

                evalBasis_i = 0.25*(1.+eta)*(2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.25*(1.+xi)*(xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(1+2.*xi+2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 3){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0-xi)*(1.0+eta)*(1.+xi-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.+eta)*(-2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(-1.+xi)*(-xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.-xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(-1+2.*xi-2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  else if (basisId == 4){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = xi*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.5*(1.+xi)*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = (eta - 1.); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNab){

                evalBasis_i = xi; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 5){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0+xi)*(1.0+eta)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =-0.5*(1.+eta)*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -eta*(1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNbb){

                evalBasis_i = -(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = -eta; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 6){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i =-xi*(1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.5*(1.+xi)*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = -(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNab){

                evalBasis_i =-xi; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 7){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+eta)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.5*(1.+eta)*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  eta*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNbb){

                evalBasis_i = (xi-1.); 

            }else if (basisDer == derNab){

                evalBasis_i = eta; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }

        femb_set(&e, basisId, i, evalBasis_i);

    }

    return OTI_OK;

}   
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
int64_t fem_basisFunctions_N_QuadP1_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis){
    /*
    fem_basisFunctions_N_QuadP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:

                           (3)* * * * *(2) 
                            *           *
                            *           *
                            *           *
                            *           *
                            *           *
                           (0)* * * * *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    int64_t i, ncoords, st;
    ndarr_t c, e;
    double xi, eta, evalBasis_i=0.0;
    
    // Borrowed ndarray views of coords and evalBasis (Phase 6a); basisId and the shapes are checked
    // (statuses instead of the legacy codes and exit()).
    st = femb_views(basisId, 4, 2, coords, evalBasis, &c, &e);
    if (st != OTI_OK){
        return st;
    }
    ncoords = c.shape[0];

    for(i=0; i<ncoords; i++){

        xi  = femb_get(&c, i, 0);
        eta = femb_get(&c, i, 1);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0-xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.0-eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(1.0-xi); 

            }else if (basisDer == derNab){

                evalBasis_i =  0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0+xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.25*(1.0-eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(1.0+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = -0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0+xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.25*(1.0+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  0.25*(1.0+xi); 

            }else if (basisDer == derNab){

                evalBasis_i =  0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 3){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0-xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.0+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  0.25*(1.0-xi); 

            }else if (basisDer == derNab){ 

                evalBasis_i = -0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        femb_set(&e, basisId, i, evalBasis_i);

    }

    return OTI_OK;

}   
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t fem_basisFunctions_N_TriangP2_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis){
    /*
    fem_basisFunctions_N_TriangP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the P1 2D element.

    
    NODE NUMBERING:

    (2)
     * *
     *   * 
    (5)   (4) 
     *       *
     *         *
    (0)* *(3)* *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. 
                       For this case, id = 0,1,2,3,4 or 5. (N1, N2, N3, N4, N5, N6)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.



    */ 
    // ************************************************************************************************

    int64_t i, ncoords, st;
    ndarr_t c, e;
    double xi, eta, evalBasis_i=0.0;
    
    // Borrowed ndarray views of coords and evalBasis (Phase 6a); basisId and the shapes are checked
    // (statuses instead of the legacy codes and exit()).
    st = femb_views(basisId, 6, 2, coords, evalBasis, &c, &e);
    if (st != OTI_OK){
        return st;
    }
    ncoords = c.shape[0];

    

    for(i=0; i<ncoords; i++){
        
        xi  = femb_get(&c, i, 0);
        eta = femb_get(&c, i, 1);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){
            // N1
            // Detect which derivative is being computed
            if (basisDer == derN){
                
                evalBasis_i = 2.*pow(eta,2.)+4.*eta*xi - 3.*eta + 2.*pow(xi,2.)-3.*xi+ 1.; 

            } else if (basisDer == derNa){

                evalBasis_i = 4.*eta + 4.*xi - 3.; 

            } else if (basisDer == derNb){

                evalBasis_i = 4.*eta + 4.*xi - 3.; 

            } else if (basisDer == derNaa){

                evalBasis_i = 4.; 

            }  else if (basisDer == derNab){

                evalBasis_i = 4.; 

            }  else if (basisDer == derNbb){

                evalBasis_i = 4.; 

            } else {

                evalBasis_i = 0.0;  // dN1/d everything else.
                
            }

        } else if (basisId == 1){
            // N2
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 2.*pow(xi,2.0)-xi; // N2 = xi

            }else if (basisDer == derNa){

                evalBasis_i = 4.*xi-1.; 

            } else if (basisDer == derNaa){

                evalBasis_i = 4.; 

            } else{

                evalBasis_i = 0.0;

            }

        } else if (basisId == 2){
            // N3
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 2.*pow(eta,2.0)-eta; 

            }else if (basisDer == derNb){

                evalBasis_i = 4.*eta-1.; 

            } else if (basisDer == derNbb){

                evalBasis_i = 4.; 

            } else{

                evalBasis_i = 0.0; // dN1/deta = 0.0 and everything else (if asked).

            }

        } else if (basisId == 3){
            // N4
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = - 4.*eta*xi - 4.*pow(xi,2.0) + 4.*xi; 

            }else if (basisDer == derNa){

                evalBasis_i =  - 4.*eta - 8.*xi + 4.; 

            } else if (basisDer == derNaa){

                evalBasis_i = -8.; 

            }else if (basisDer == derNb){

                evalBasis_i = - 4.*xi; 

            } else if (basisDer == derNab){

                evalBasis_i = -4.; 

            } else{

                evalBasis_i = 0.0; 

            }

        } else if (basisId == 4){
            // N5
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 4.*eta*xi ; 

            }else if (basisDer == derNa){

                evalBasis_i =  4.*eta ; 

            }else if (basisDer == derNb){

                evalBasis_i = 4.*xi; 

            } else if (basisDer == derNab){

                evalBasis_i = 4.; 

            } else{

                evalBasis_i = 0.0; 

            }

        }else if (basisId == 5){
            // N6
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = - 4.*eta*xi - 4.*pow(eta,2.0) + 4.*eta; 

            }else if (basisDer == derNb){

                evalBasis_i =  - 4.*xi - 8.*eta + 4.; 

            } else if (basisDer == derNbb){

                evalBasis_i = -8.; 

            }else if (basisDer == derNa){

                evalBasis_i = - 4.*eta; 

            } else if (basisDer == derNab){

                evalBasis_i = -4.; 

            } else{

                evalBasis_i = 0.0; 

            }

        }  

        femb_set(&e, basisId, i, evalBasis_i);

    }

    return OTI_OK;

}   
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
int64_t fem_basisFunctions_N_TriangP1_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis){
    /*
    fem_basisFunctions_N_TriangP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the P1 2D element.


    NODE NUMBERING:

                           (2)
                            * *
                            *   * 
                            *     *  
                            *       *
                            *         *
                           (0)* * * * *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1 or 2. (N1, N2, N3)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    int64_t i, ncoords, st;
    ndarr_t c, e;
    double xi, eta, evalBasis_i=0.0;
    
    // Borrowed ndarray views of coords and evalBasis (Phase 6a); basisId and the shapes are checked
    // (statuses instead of the legacy codes and exit()).
    st = femb_views(basisId, 3, 2, coords, evalBasis, &c, &e);
    if (st != OTI_OK){
        return st;
    }
    ncoords = c.shape[0];

    for(i=0; i<ncoords; i++){

        xi  = femb_get(&c, i, 0);
        eta = femb_get(&c, i, 1);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 1.0-xi-eta; // N1 = 1-xi-eta

            }else if (basisDer == derNa){

                evalBasis_i = -1.0; // dN1/dxi  = 1.0

            }else if (basisDer == derNb){

                evalBasis_i = -1.0; // dN1/deta  = 1.0

            } else{

                evalBasis_i = 0.0;  // dN1/d everything else.
                
            }

        } else if (basisId == 1){
            
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = xi; // N2 = xi

            }else if (basisDer == derNa){

                evalBasis_i = 1.0; // dN2/dxi  = 1.0

            } else{

                evalBasis_i = 0.0; // dN2/deta = 0.0 and everything else (if asked).

            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = eta; // N3 = eta

            }else if (basisDer == derNb){

                evalBasis_i = 1.0; // dN3/deta  = 1.0

            } else{

                evalBasis_i = 0.0; // dN3/dxi = 0.0 and everything else.
                
            }

        } 

        femb_set(&e, basisId, i, evalBasis_i);

    }

    return OTI_OK;

}   
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t fem_basisFunctions_N_TriangP0_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis){
    /*
    fem_basisFunctions_N_TriangP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the P1 2D element.

    NODE NUMBERING:
                            
                     *                    |           *
                     * *                  |           * *
                     *   *                            *   * 
                     *     *         <-- o r -->      *     *  
                     *  (0)  *                        *       *
                     *         *          |           *         *
                     * * * * * * *        |          (0)* * * * * *

    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0. (N1)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab     

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    int64_t i, ncoords, st;
    ndarr_t c, e;
    double  evalBasis_i=0.0;
    
    
    // Borrowed ndarray views of coords and evalBasis (Phase 6a); basisId and the shapes are checked
    // (statuses instead of the legacy codes and exit()).
    st = femb_views(basisId, 2, 0, coords, evalBasis, &c, &e);
    if (st != OTI_OK){
        return st;
    }
    ncoords = c.shape[0];

    
    for(i=0; i<ncoords; i++){
                    
        // Detect which derivative is being computed
        if (basisDer == derN){

            evalBasis_i = 1.0; // N1 = xi

        } else{

            evalBasis_i = 0.0; // everything else (if asked).

        }

        femb_set(&e, basisId, i, evalBasis_i);

    }

    return OTI_OK;

}   
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t fem_basisFunctions_N_LineP2_1Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis){
    /*
    fem_basisFunctions_N_LineP2_1Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:


                           (0)* *(2)* *(1)



    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [    xi_1   ],
                         [    xi_2   ],
                             ... 
                         [ xi_ncoord,] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    int64_t i, ncoords, st;
    ndarr_t c, e;
    double xi, evalBasis_i=0.0;
    
    // Borrowed ndarray views of coords and evalBasis (Phase 6a); basisId and the shapes are checked
    // (statuses instead of the legacy codes and exit()).
    st = femb_views(basisId, 3, 1, coords, evalBasis, &c, &e);
    if (st != OTI_OK){
        return st;
    }
    ncoords = c.shape[0];

    for(i=0; i<ncoords; i++){

        xi = femb_get(&c, i, 0);
        
        // Detect which basis function is being computed: N1, N2
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.5*xi*(1.0-xi);

            }else if (basisDer == derNa){

                evalBasis_i = -0.5+xi;

            }else if (basisDer == derNaa){

                evalBasis_i = 1.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.5*xi*(1.0+xi); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.5+xi; 

            }else if (basisDer == derNaa){

                evalBasis_i = 1.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = (1.0-xi*xi); 

            }else if (basisDer == derNa){

                evalBasis_i = -2.0*xi; 

            }else if (basisDer == derNaa){

                evalBasis_i = -2.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        femb_set(&e, basisId, i, evalBasis_i);

    }

    return OTI_OK;

}   
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
int64_t fem_basisFunctions_N_LineP1_1Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis){
    /*
    fem_basisFunctions_N_LineP1_1Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:


                           (0)* * * * *(1)



    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [    xi_1   ],
                         [    xi_2   ],
                             ... 
                         [ xi_ncoord,] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    int64_t i, ncoords, st;
    ndarr_t c, e;
    double xi, evalBasis_i=0.0;
    
    // Borrowed ndarray views of coords and evalBasis (Phase 6a); basisId and the shapes are checked
    // (statuses instead of the legacy codes and exit()).
    st = femb_views(basisId, 2, 1, coords, evalBasis, &c, &e);
    if (st != OTI_OK){
        return st;
    }
    ncoords = c.shape[0];

    for(i=0; i<ncoords; i++){

        xi = femb_get(&c, i, 0);
        
        // Detect which basis function is being computed: N1, N2
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.5*(1.0-xi);

            }else if (basisDer == derNa){

                evalBasis_i = -0.5;

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.5*(1.0+xi); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.5; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        femb_set(&e, basisId, i, evalBasis_i);

    }

    return OTI_OK;

}   
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t fem_basisFunctions_N_PntP0_0Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                              void* other_data, darr_t* evalBasis){
    /*
    fem_basisFunctions_N_PntP0_0Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:


                           (0)



    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [    xi_1   ],
                         [    xi_2   ],
                             ... 
                         [ xi_ncoord,] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    int64_t i, ncoords, st;
    ndarr_t c, e;
    double evalBasis_i=0.0;
    
    // Borrowed ndarray views of coords and evalBasis (Phase 6a); basisId and the shapes are checked
    // (statuses instead of the legacy codes and exit()).
    st = femb_views(basisId, 1, 0, coords, evalBasis, &c, &e);
    if (st != OTI_OK){
        return st;
    }
    ncoords = c.shape[0];

    for(i=0; i<ncoords; i++){
        
        // Detect which basis function is being computed: N1, N2
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 1.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        femb_set(&e, basisId, i, evalBasis_i);

    }

    return OTI_OK;

}   
// ----------------------------------------------------------------------------------------------------




// ----------------------------------------------------------------------------------------------------
// -------------------------------     END OTIFEM FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------


