int64_t fem_intPts_soti( uint64_t order, int64_t elementType, 
                         fesoti_t*  xi,   fesoti_t*   eta,   fesoti_t* zeta, 
                         fesoti_t* weights, dhelpl_t dhl);



uint64_t fem_addLineIntPts_soti(uint8_t nperm, uint64_t start, double a,  double w,
                                fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta, 
                                fesoti_t* weights, dhelpl_t dhl);

uint64_t fem_addTriangleIntPts_soti(uint8_t nperm, uint64_t start, 
                                    double a, double b, double c, double w,
                                    fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta, 
                                    fesoti_t* weights, dhelpl_t dhl);

uint64_t fem_addTetrahedraIntPts_soti(uint8_t nperm, uint64_t start, 
                                      double a, double b, double c, double d, double w,
                                      fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta, 
                                      fesoti_t* weights, dhelpl_t dhl);























// ****************************************************************************************************
int64_t fem_intPts_soti( uint64_t order, int64_t elementType, 
                         fesoti_t*  xi,   fesoti_t*   eta,   fesoti_t* zeta, 
                         fesoti_t* weights, dhelpl_t dhl){
    /*
    fem_integrationPoints(uint64_t order, int64_t elementType, double* coords) 

    Define the coordinates and weights for integration according to the type of element and 
    order of evaluation sought.

    INPUTS:

        -> order:    Order of integration.


        -> elementType:  Geometric Type of element. 
                         It can be: elLine, elTriangle, elQuadrangle,
                         elTetrahedra or elHexahedra.
    OUTPUTS: 
        
        -> xi :  Coordinates to evaluate the integral.
        -> eta:  Coordinates to evaluate the integral.
        -> zeta: Coordinates to evaluate the integral.

        -> weights: Weights to evaluate the integral.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    uint64_t i,j;
    uint64_t npoints, ndim;
    double a=0.0, b=0.0, c=0.0, d=0.0, w=0.0; 

    // Check if the elementType given is ok.
    if ( elementType < elNode || elementType > elHexahedra ){
        
        return OTI_FEM_InvalidElementType;
    }

    // Depending on the element type, compute the data.
    if (elementType == elNode){

        // printf("Initializing elNode.\n");
        npoints = 1;
        ndim = 1;
        
        // Create as reals
        *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
        *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
        *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
        *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

        fesoti_set_item_k_r( 0.0, 0, xi,      dhl);
        fesoti_set_item_k_r( 1.0, 0, weights, dhl);

    } else if (elementType == elLine){
        // printf("Initializing elLine.\n");

        
        // According to --> 
        // uint64_t nIntPts = (order + 1)/2;
        uint64_t nIntPts = order ;

        // Line element.
        ndim = 1;
        if (nIntPts <= 1){ // Accepts 0 or 1.
            
            npoints = 1;
            
            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0;
            a = 0.000000000000000;
            w = 2.000000000000000;
            i =  fem_addLineIntPts_soti(1, i, a, w, xi, eta, zeta, weights, dhl);


        } else if (nIntPts == 2) {

            npoints = 2;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0;
            a = 0.577350269189626;
            w = 1.000000000000000;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);
            

        } else if (nIntPts == 3) {

            npoints = 3;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.888888888888889;
            i =  fem_addLineIntPts_soti(1, i, a, w, xi, eta, zeta, weights, dhl); 

            a = 0.774596669241483; w = 0.555555555555556;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);


        } else if (nIntPts == 4) {

            npoints = 4;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 

            a = 0.861136311594053; w = 0.347854845137454;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.339981043584856; w = 0.652145154862546;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            

        } else if (nIntPts == 5) {

            npoints = 5;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.568888888888889;
            i =  fem_addLineIntPts_soti(1, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.906179845938664; w = 0.236926885056189;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.538469310105683; w = 0.478628670499366;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

        } else if (nIntPts == 6) {

            npoints = 6;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0;

            a = 0.932469514203152; w = 0.171324492379170;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.661209386466265; w = 0.360761573048139;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.238619186083197; w = 0.467913934572691;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

        } else if (nIntPts == 7) {

            npoints = 7;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.417959183673469;
            i =  fem_addLineIntPts_soti(1, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.949107912342759; w = 0.129484966168870;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.741531185599394; w = 0.279705391489277;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.405845151377397; w = 0.381830050505119;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

        } else if (nIntPts == 8) {

            npoints = 8;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 

            a = 0.960289856497536; w = 0.101228536290376;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.796666477413627; w = 0.222381034453374;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.525532409916329; w = 0.313706645877887;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.183434642495650; w = 0.362683783378362;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

        } else if (nIntPts == 9) {

            npoints = 9;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 

            a = 0.000000000000000; w = 0.362683783378362;
            i =  fem_addLineIntPts_soti(1, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.968160239507626; w = 0.101228536290376;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.836031107326636; w = 0.222381034453374;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.613371432700590; w = 0.313706645877887;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.324253423403809; w = 0.362683783378362;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

        } else {    // Order >= 10  

            npoints = 10;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 

            a = 0.973906528517172; w = 0.066671344308688;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.865063366688985; w = 0.149451349150581;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.679409568299024; w = 0.219086362515982;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.433395394129247; w = 0.269266719309996;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

            a = 0.148874338981631; w = 0.295524224714753;
            i =  fem_addLineIntPts_soti(2, i, a, w, xi, eta, zeta, weights, dhl);

        }

    } else if (elementType == elTriangle){
        
        // printf("Initializing elTriangle.\n");

        // Triangular element .
        ndim = 2;

        if (order <= 1){ // Accepts 0 or 1.

            npoints = 1;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 1.000000000000000; w *= 0.5;
            i = fem_addTriangleIntPts_soti(1, i, a, b, c, w, xi, eta, zeta, weights, dhl);

        } else if (order == 2){

            npoints = 3;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Points 0, 1, 2
            i = 0; 
            a = 0.666666666666667; b = 0.166666666666667; c = b;
            w = 0.333333333333333; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

        } else if (order == 3){

            npoints = 1+3;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w =-0.562500000000000; w *= 0.5;
            i = fem_addTriangleIntPts_soti(1, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.600000000000000; b = 0.200000000000000; c = b;
            w = 0.520833333333333; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

        } else if (order == 4){

            npoints = 3+3;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0;
            a = 0.108103018168070; b = 0.445948490915965; c = b;
            w = 0.223381589678011; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.816847572980459; b = 0.091576213509771; c = b;
            w = 0.109951743655322; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);
            
        } else if (order == 5){

            npoints = 1+3+3;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.225000000000000; w *= 0.5;
            i = fem_addTriangleIntPts_soti(1, i, a, b, c, w, xi, eta, zeta, weights, dhl);
            
            a = 0.059715871789770; b = 0.470142064105115; c = b;
            w = 0.132394152788506; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.797426985353087; b = 0.101286507323456; c = b;
            w = 0.125939180544827; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            
        } else if (order == 6){

            npoints = 3+3+6;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 

            a = 0.501426509658179; b = 0.249286745170910; c = b;
            w = 0.116786275726379; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.873821971016996; b = 0.063089014491502; c = b;
            w = 0.050844906370207; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.053145049844817; b = 0.310352451033784; c = 0.636502499121399;
            w = 0.082851075618374; w *= 0.5;
            i = fem_addTriangleIntPts_soti(6, i, a, b, c, w, xi, eta, zeta, weights, dhl);
            
        } else if (order == 7){

            npoints = 1+3+3+6;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w =-0.149570044467682; w *= 0.5;
            i = fem_addTriangleIntPts_soti(1, i, a, b, c, w, xi, eta, zeta, weights, dhl);
            
            a = 0.479308067841920; b = 0.260345966079040; c = b;
            w = 0.175615257433208; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.869739794195568; b = 0.065130102902216; c = b;
            w = 0.053347235608838; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.048690315425316; b = 0.312865496004874; c = 0.638444188569810;
            w = 0.077113760890257; w *= 0.5;
            i = fem_addTriangleIntPts_soti(6, i, a, b, c, w, xi, eta, zeta, weights, dhl);
            
        } else if (order == 8){

            npoints = 1+3+3+3+6;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.144315607677787; w *= 0.5;
            i = fem_addTriangleIntPts_soti(1, i, a, b, c, w, xi, eta, zeta, weights, dhl);
            
            a = 0.081414823414554; b = 0.459292588292723; c = b;
            w = 0.095091634267285; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.658861384496480; b = 0.170569307751760; c = b;
            w = 0.103217370534718; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.898905543365938; b = 0.050547228317031; c = b;
            w = 0.032458497623198; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.008394777409958; b = 0.263112829634638; c = 0.728492392955404;
            w = 0.027230314174435; w *= 0.5;
            i = fem_addTriangleIntPts_soti(6, i, a, b, c, w, xi, eta, zeta, weights, dhl); 



        } else if (order == 9){

            npoints = 1+3+3+3+3+6;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.097135796282799; w *= 0.5;
            i = fem_addTriangleIntPts_soti(1, i, a, b, c, w, xi, eta, zeta, weights, dhl);
            
            a = 0.020634961602525; b = 0.489682519198738; c = b;
            w = 0.031334700227139; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.125820817014127; b = 0.437089591492937; c = b;
            w = 0.077827541004774; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.623592928761935; b = 0.188203535619033; c = b;
            w = 0.079647738927210; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.910540973211095; b = 0.044729513394453; c = b;
            w = 0.025577675658698; w *= 0.5;
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.036838412054736; b = 0.221962989160766; c = 0.741198598784498;
            w = 0.043283539377289; w *= 0.5;
            i = fem_addTriangleIntPts_soti(6, i, a, b, c, w, xi, eta, zeta, weights, dhl);

        
        } else {

            npoints = 1+3+3+6+6+6;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.090817990382754; w *= 0.5;
            i = fem_addTriangleIntPts_soti(1, i, a, b, c, w, xi, eta, zeta, weights, dhl);
            
            a = 0.028844733232685; b = 0.485577633383657; c = b;
            w = 0.036725957756467; w *= 0.5;            
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.781036849029926; b = 0.109481575485037; c = b;
            w = 0.045321059435528; w *= 0.5;            
            i = fem_addTriangleIntPts_soti(3, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.141707219414880; b = 0.307939838764121; c = 0.550352941820999;
            w = 0.072757916845420; w *= 0.5;
            i = fem_addTriangleIntPts_soti(6, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.025003534762686; b = 0.246672560639903; c = 0.728323904597411;
            w = 0.028327242531057; w *= 0.5;
            i = fem_addTriangleIntPts_soti(6, i, a, b, c, w, xi, eta, zeta, weights, dhl);

            a = 0.009540815400299; b = 0.066803251012200; c = 0.923655933587500;
            w = 0.009421666963733; w *= 0.5;
            i = fem_addTriangleIntPts_soti(6, i, a, b, c, w, xi, eta, zeta, weights, dhl);

        }


    } else if (elementType == elTetrahedra){

        // Tetrahedral element .
        ndim = 3;

        if (order <= 1){ // Accepts 0 or 1.

            npoints = 1;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.250000000000000; b = a; c = a; d = a;
            w = 1.000000000000000; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(1, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);

        } else if (order == 2){

            npoints = 4;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Points 0, 1, 2, 3
            i = 0; 
            a = 0.585410196624969; b = 0.138196601125011; c = b; d = b;
            w = 0.250000000000000; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(4, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);

        } else if (order == 3){

            npoints = 1+4;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.250000000000000; b = a; c = a; d = a;
            w =-0.800000000000000; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(1, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);

            a = 0.500000000000000; b = 0.166666666666667; c = b; d = b;
            w = 0.450000000000000; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(4, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);

        } else if (order == 4){

            npoints = 1+4+6;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.250000000000000; b = a; c = a; d = a;
            w =-0.013155555555556; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(1, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);

            a = 0.785714285714286; b = 0.071428571428571; c = b; d = b;
            w = 0.007622222222222; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(4, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);

            a = 0.399403576166799; b = 0.100596423833201; c = a; d = b;
            w = 0.024888888888889; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(6, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);
        
        } else { // Order >= 5.

            npoints = 1+4+4+6;

            // Create as reals
            *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
            *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

            // Point 0
            i = 0; 
            a = 0.250000000000000; b = a; c = a; d = a;
            w = 0.030283678097089; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(1, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);

            a = 0.000000000000000; b = 0.333333333333333; c = b; d = b;
            w = 0.006026785714286; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(4, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);

            a = 0.727272727272727; b = 0.090909090909091; c = b; d = b;
            w = 0.011645249086029; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(4, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);

            a = 0.066550153573664; b = 0.433449846426336; c = a; d = b;
            w = 0.010949141561386; w /= 6.0;
            i = fem_addTetrahedraIntPts_soti(6, i, a, b, c, d, w, xi, eta, zeta, weights, dhl);


        }

    } else if (elementType == elQuadrangle){

        fesoti_t      xi_tmp;
        fesoti_t     eta_tmp;
        fesoti_t    zeta_tmp;
        fesoti_t weights_tmp;

        sotinum_t val_tmp = soti_init();

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;

        ndim = 2;

        // Call the solution for the corresponding 1D line element.
        fem_intPts_soti(order, elLine, &xi_tmp, &eta_tmp, &zeta_tmp, &weights_tmp, dhl);

        npoints = xi_tmp.nip * xi_tmp.nip;

        // Create as reals
        *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
        *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
        *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
        *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

        for ( i = 0; i < xi_tmp.nip; i++ ){

            // Get the first weight.
            fesoti_get_item_k_to(     &xi_tmp, i, &val_tmp, dhl); a      = val_tmp.re;
            fesoti_get_item_k_to(&weights_tmp, i, &val_tmp, dhl); w_tmp1 = val_tmp.re;

            for ( j = 0; j < xi_tmp.nip; j++ ){

                // Get the second weight.
                fesoti_get_item_k_to(     &xi_tmp, j, &val_tmp, dhl); b      = val_tmp.re;
                fesoti_get_item_k_to(&weights_tmp, j, &val_tmp, dhl); w_tmp2 = val_tmp.re;

                w = w_tmp1 * w_tmp2;
                
                fesoti_set_item_k_r( a, xi_tmp.nip * i + j, xi,      dhl);
                fesoti_set_item_k_r( b, xi_tmp.nip * i + j, eta,     dhl);
                fesoti_set_item_k_r( w, xi_tmp.nip * i + j, weights, dhl);

            }

        }

        fesoti_free(      &xi_tmp );
        fesoti_free(     &eta_tmp );
        fesoti_free(    &zeta_tmp );
        fesoti_free( &weights_tmp );

        
        
    } else if (elementType == elHexahedra){

        // printf("Initializing elHexahedra.\n");

        fesoti_t      xi_tmp;
        fesoti_t     eta_tmp;
        fesoti_t    zeta_tmp;
        fesoti_t weights_tmp;

        sotinum_t val_tmp = soti_init();

        uint64_t k = 0, currentIndex = 0 ;

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;
        double w_tmp3 = 0.0;

        ndim = 3;
        
        // Call the solution for the corresponding 1D line element.
        fem_intPts_soti(order, elLine, &xi_tmp, &eta_tmp, &zeta_tmp, &weights_tmp, dhl);

        // Go for all possible combinations for 
        npoints = xi_tmp.nip * xi_tmp.nip * xi_tmp.nip;

        // Create as reals
        *xi      = fesoti_zeros_bases( npoints, 0, 0, dhl);
        *eta     = fesoti_zeros_bases( npoints, 0, 0, dhl);
        *zeta    = fesoti_zeros_bases( npoints, 0, 0, dhl);
        *weights = fesoti_zeros_bases( npoints, 0, 0, dhl);

        for ( i = 0; i < xi_tmp.nip; i++ ){

            // Get the first weight.
            fesoti_get_item_k_to(     &xi_tmp, i, &val_tmp, dhl); a      = val_tmp.re;
            fesoti_get_item_k_to(&weights_tmp, i, &val_tmp, dhl); w_tmp1 = val_tmp.re;

            for ( j = 0; j < xi_tmp.nip; j++ ){

                // Get the second weight.
                fesoti_get_item_k_to(     &xi_tmp, j, &val_tmp, dhl); b      = val_tmp.re;
                fesoti_get_item_k_to(&weights_tmp, j, &val_tmp, dhl); w_tmp2 = val_tmp.re;

                for ( k = 0; k < xi_tmp.nip; k++ ){

                    // Get the second weight.
                    fesoti_get_item_k_to(     &xi_tmp, k, &val_tmp, dhl); c      = val_tmp.re;
                    fesoti_get_item_k_to(&weights_tmp, k, &val_tmp, dhl); w_tmp3 = val_tmp.re;

                    w = w_tmp1 * w_tmp2 * w_tmp3;

                    fesoti_set_item_k_r( a, currentIndex, xi,      dhl);
                    fesoti_set_item_k_r( b, currentIndex, eta,     dhl);
                    fesoti_set_item_k_r( c, currentIndex, zeta,    dhl);
                    fesoti_set_item_k_r( w, currentIndex, weights, dhl);

                    currentIndex += 1;
                }

            }

        }

        fesoti_free(      &xi_tmp );
        fesoti_free(     &eta_tmp );
        fesoti_free(    &zeta_tmp );
        fesoti_free( &weights_tmp );
    
    } else {

        return OTI_FEM_NotImplemented;

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t fem_addLineIntPts_soti(uint8_t nperm, uint64_t start, double a,  double w,
                                fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta, 
                                fesoti_t* weights, dhelpl_t dhl){
    /*
    Permutations of the .


    INPUTS:

        -> numberOfPermutations: Number of permutations for the selected point. (1, 3 or 6)

        -> startPoint: Index of the starting point in the 

        -> a: Coordinate 

        -> w: Weight for this point

        -> coords:  ( ncoords x 1 ) Array to write the coordinates. Must come allocated.

        -> weights: ( ncoords x 1 ) Array to write the weights. Must come allocated.
    
    OUTPUTS: 

        -> Position after last element added. (startPoint + numberOfPermutations). Current positionAdded position

    */ 
    // ************************************************************************************************
    uint64_t i = start;

    if (nperm == 1){
        
        // Point 1
        fesoti_set_item_k_r( a, i, xi     , dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

    } else if (nperm == 2){

        // Point 1
        fesoti_set_item_k_r(-a, i, xi     , dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 2
        i+= 1; 
        fesoti_set_item_k_r( a, i, xi     , dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

    }

    return i+1;
}   
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
uint64_t fem_addTriangleIntPts_soti(uint8_t nperm, uint64_t start, 
                                    double a, double b, double c, double w,
                                    fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta, 
                                    fesoti_t* weights, dhelpl_t dhl){
    /*
    fem_addTriangleIntPts_soti( numberOfPermutations,  startPoint, 
                                        a, b,  c,  w,
                                        coords, weights)

    Permutations of the .


    INPUTS:

        -> numberOfPermutations: Number of permutations for the selected point. (1, 3 or 6)

        -> startPoint: Index of the starting point in the 

        -> a: Area coordinate 1

        -> b: Area coordinate 2

        -> c: Area coordinate 3

        -> w: Weight for this configuration                      

        -> coords:  ( ncoords x 2 ) Array to write the coordinates. Must come allocated.

        -> weights: ( ncoords x 1 ) Array to write the weights. Must come allocated.
    
    OUTPUTS: 

        -> Position after last element added. (startPoint + numberOfPermutations). Current positionAdded position

    */ 
    // ************************************************************************************************
    uint64_t i=start;

    if (nperm == 1){
        
        // Point 1
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( c, i, eta,     dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

    } else if (nperm == 3){

        // Point 1
        
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 2
        i+= 1; 
        fesoti_set_item_k_r( a, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 3
        i+= 1; 
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( a, i, eta,     dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

    } else if (nperm == 6){
        
        // Point 1
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( c, i, eta,     dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 2
        i+= 1; 
        fesoti_set_item_k_r( c, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 3
        i+= 1; 
        fesoti_set_item_k_r( a, i, xi,      dhl);
        fesoti_set_item_k_r( c, i, eta,     dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 4
        i+= 1; 
        fesoti_set_item_k_r( c, i, xi,      dhl);
        fesoti_set_item_k_r( a, i, eta,     dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 5
        i+= 1; 
        fesoti_set_item_k_r( a, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 6
        i+= 1;
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( a, i, eta,     dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);
    }

    return i+1;
}   
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
uint64_t fem_addTetrahedraIntPts_soti(uint8_t nperm, uint64_t start, 
                                      double a, double b, double c, double d, double w,
                                      fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta, 
                                      fesoti_t* weights, dhelpl_t dhl){
    /*
    INPUTS:

        -> numberOfPermutations: Number of permutations for the selected point. (1, 4 or 6)

        -> startPoint: Index of the starting point in the 

        -> a: Volume coordinate 1

        -> b: Volume coordinate 2

        -> c: Volume coordinate 3

        -> d: Volume coordinate 4

        -> w: Weight for this configuration                      

        -> coords:  ( ncoords x 3 ) Array to write the coordinates. Must come allocated.

        -> weights: ( ncoords x 1 ) Array to write the weights. Must come allocated.
    
    OUTPUTS: 

        -> Position after last element added. (startPoint + numberOfPermutations). Current positionAdded position

    */ 
    // ************************************************************************************************
    uint64_t i=start;

    if (nperm == 1){
        // Point 1
        fesoti_set_item_k_r( a, i, xi,      dhl);
        fesoti_set_item_k_r( a, i, eta,     dhl);
        fesoti_set_item_k_r( a, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

    } else if (nperm == 4){

        // Point 1
        fesoti_set_item_k_r( a, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( b, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 2
        i+= 1; 
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( a, i, eta,     dhl);
        fesoti_set_item_k_r( b, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 3
        i+= 1; 
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( a, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 4
        i+= 1; 
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( b, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

    } else if (nperm == 6){
        
        // Point 1
        fesoti_set_item_k_r( a, i, xi,      dhl);
        fesoti_set_item_k_r( a, i, eta,     dhl);
        fesoti_set_item_k_r( b, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 2
        i+= 1; 
        fesoti_set_item_k_r( a, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( a, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 3
        i+= 1; 
        fesoti_set_item_k_r( a, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( b, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 4
        i+= 1; 
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( a, i, eta,     dhl);
        fesoti_set_item_k_r( a, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 5
        i+= 1; 
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( a, i, eta,     dhl);
        fesoti_set_item_k_r( b, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 6
        i+= 1;
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( a, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

    } else if (nperm == 12){
        
        // Point 1
        fesoti_set_item_k_r( a, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( c, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 2
        i+= 1; 
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( a, i, eta,     dhl);
        fesoti_set_item_k_r( c, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 3
        i+= 1; 
        fesoti_set_item_k_r( a, i, xi,      dhl);
        fesoti_set_item_k_r( c, i, eta,     dhl);
        fesoti_set_item_k_r( b, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 4
        i+= 1; 
        fesoti_set_item_k_r( c, i, xi,      dhl);
        fesoti_set_item_k_r( a, i, eta,     dhl);
        fesoti_set_item_k_r( b, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 5
        i+= 1; 
        fesoti_set_item_k_r( b, i, xi,      dhl);
        fesoti_set_item_k_r( c, i, eta,     dhl);
        fesoti_set_item_k_r( a, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

        // Point 6
        i+= 1;
        fesoti_set_item_k_r( c, i, xi,      dhl);
        fesoti_set_item_k_r( b, i, eta,     dhl);
        fesoti_set_item_k_r( a, i, zeta,    dhl);
        fesoti_set_item_k_r( w, i, weights, dhl);

    }

    return i+1;
}   
// ----------------------------------------------------------------------------------------------------




