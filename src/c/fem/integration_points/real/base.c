






// ****************************************************************************************************
int64_t fem_intPts_real( uint64_t order, int64_t elementType, 
                         fednum_t*  xi,   fednum_t*   eta,   fednum_t* zeta, 
                         fednum_t* weights){
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

    // Depending on the element type, compute the data.
    if (elementType == elNode){

        // printf("Initializing elNode.\n");
        npoints = 1;
        ndim = 1;
        
        // Create as reals
        *xi      = fednum_zeros( npoints );
        *eta     = fednum_zeros( npoints );
        *zeta    = fednum_zeros( npoints );
        *weights = fednum_zeros( npoints );

        fednum_set_item_k_r( 0.0, 0, xi     );
        fednum_set_item_k_r( 1.0, 0, weights);

    } else if (elementType == elLine){
        // printf("Initializing elLine.\n");

        
        // According to --> 
        // uint64_t nIntPts = (order + 1)/2;
        uint64_t nIntPts = order + 1 ;

        // Line element.
        ndim = 1;
        if (nIntPts <= 1){ // Accepts 0 or 1.
            
            npoints = 1;
            
            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 0.000000000000000;
            w = 2.000000000000000;
            i =  fem_addLineIntPts_real(1, i, a, w, xi, eta, zeta, weights );


        } else if (nIntPts == 2) {

            npoints = 2;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 0.577350269189626;
            w = 1.000000000000000;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);
            

        } else if (nIntPts == 3) {

            npoints = 3;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.888888888888889;
            i =  fem_addLineIntPts_real(1, i, a, w, xi, eta, zeta, weights); 

            a = 0.774596669241483; w = 0.555555555555556;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);


        } else if (nIntPts == 4) {

            npoints = 4;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 

            a = 0.861136311594053; w = 0.347854845137454;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);

            a = 0.339981043584856; w = 0.652145154862546;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);

            

        } else if (nIntPts == 5) {

            npoints = 5;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.568888888888889;
            i =  fem_addLineIntPts_real(1, i, a, w, xi, eta, zeta, weights );

            a = 0.906179845938664; w = 0.236926885056189;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.538469310105683; w = 0.478628670499366;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

        } else if (nIntPts == 6) {

            npoints = 6;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;

            a = 0.932469514203152; w = 0.171324492379170;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.661209386466265; w = 0.360761573048139;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.238619186083197; w = 0.467913934572691;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

        } else if (nIntPts == 7) {

            npoints = 7;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.417959183673469;
            i =  fem_addLineIntPts_real(1, i, a, w, xi, eta, zeta, weights);

            a = 0.949107912342759; w = 0.129484966168870;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);

            a = 0.741531185599394; w = 0.279705391489277;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);

            a = 0.405845151377397; w = 0.381830050505119;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);

        } else if (nIntPts == 8) {

            npoints = 8;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 

            a = 0.960289856497536; w = 0.101228536290376;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.796666477413627; w = 0.222381034453374;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.525532409916329; w = 0.313706645877887;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.183434642495650; w = 0.362683783378362;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

        } else if (nIntPts == 9) {

            npoints = 9;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 

            a = 0.000000000000000; w = 0.362683783378362;
            i =  fem_addLineIntPts_real(1, i, a, w, xi, eta, zeta, weights );

            a = 0.968160239507626; w = 0.101228536290376;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.836031107326636; w = 0.222381034453374;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.613371432700590; w = 0.313706645877887;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.324253423403809; w = 0.362683783378362;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

        } else {    // Order >= 10  

            npoints = 10;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 

            a = 0.973906528517172; w = 0.066671344308688;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.865063366688985; w = 0.149451349150581;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.679409568299024; w = 0.219086362515982;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.433395394129247; w = 0.269266719309996;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.148874338981631; w = 0.295524224714753;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

        }

    } else if (elementType == elLineL){
        // printf("Initializing elLine.\n");

        
        // According to --> 
        // uint64_t nIntPts = (order + 1)/2;
        uint64_t nIntPts = order + 1;

        // Line element.
        ndim = 1;
        if (nIntPts <= 1){ // Accepts 0 or 1.
            
            npoints = 1;
            
            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 0.000000000000000;
            w = 2.000000000000000;
            i =  fem_addLineIntPts_real(1, i, a, w, xi, eta, zeta, weights );


        } else if (nIntPts == 2) {

            npoints = 2;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 1.000000000000000;
            w = 1.000000000000000;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);
            

        } else if (nIntPts == 3) {

            npoints = 3;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 1.3333333333333333;
            i =  fem_addLineIntPts_real(1, i, a, w, xi, eta, zeta, weights); 

            a = 1.000000000000000; w = 0.3333333333333333;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);


        } else if (nIntPts == 4) {

            npoints = 4;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 

            a = 0.447213595499958; w = 0.8333333333333334;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);

            a = 1.000000000000000; w = 0.16666666666666666;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);

            

        } else if (nIntPts == 5) {

            npoints = 5;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 0.0000000000000000; w = 0.7111111111111111;
            i =  fem_addLineIntPts_real(1, i, a, w, xi, eta, zeta, weights );

            a = 0.6546536707079771; w = 0.5444444444444444;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 1.0000000000000000; w = 0.100000000000000;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

        } else if (nIntPts == 6) {

            npoints = 6;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;

            a = 0.2852315164806450; w = 0.5548583770354863;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.7650553239294646; w = 0.378474956297847;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 1.0000000000000000; w = 0.06666666666666667;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

        } else if (nIntPts == 7) {

            npoints = 7;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 0.0000000000; w = 0.4876190476;
            i =  fem_addLineIntPts_real(1, i, a, w, xi, eta, zeta, weights);

            a = 0.4688487934; w = 0.4317453812;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);

            a = 0.8302238962; w = 0.2768260473;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);

            a = 1.0000000000; w = 0.0476190476;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights);

        } else if (nIntPts == 8) {

            npoints = 8;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 

            a = 0.2092992179; w = 0.4124587946;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.5917001814; w = 0.3411226924;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.8717401485; w = 0.2107042271;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 1.0000000000; w = 0.0357142857;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

        } else if (nIntPts == 9) {

            npoints = 9;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 

            a = 0.0000000000; w = 0.3715192743;
            i =  fem_addLineIntPts_real(1, i, a, w, xi, eta, zeta, weights );

            a = 0.3631174638; w = 0.3464285109;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.6771862795; w = 0.2745387125;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.8997579954; w = 0.1654953615;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 1.0000000000; w = 0.0277777777;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

        } else {    // Order >= 10  

            npoints = 10;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 

            a = 0.1652789576; w = 0.3275397611;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.4779249498; w = 0.2920426836;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.7387738651; w = 0.2248893420;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 0.9195339081; w = 0.1333059908;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

            a = 1.0000000000; w = 0.02222222222;
            i =  fem_addLineIntPts_real(2, i, a, w, xi, eta, zeta, weights );

        }

    } else if (elementType == elTriangle){
        
        // printf("Initializing elTriangle.\n");

        // Triangular element .
        ndim = 2;

        if (order <= 1){ // Accepts 0 or 1.

            npoints = 1;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 1.000000000000000; w *= 0.5;
            i = fem_addTriangleIntPts_real(1, i, a, b, c, w, xi, eta, zeta, weights );

        } else if (order == 2){

            npoints = 3;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Points 0, 1, 2
            i = 0; 
            a = 0.666666666666667; b = 0.166666666666667; c = b;
            w = 0.333333333333333; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

        } else if (order == 3){

            npoints = 1+3;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w =-0.562500000000000; w *= 0.5;
            i = fem_addTriangleIntPts_real(1, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.600000000000000; b = 0.200000000000000; c = b;
            w = 0.520833333333333; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

        } else if (order == 4){

            npoints = 3+3;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0;
            a = 0.108103018168070; b = 0.445948490915965; c = b;
            w = 0.223381589678011; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.816847572980459; b = 0.091576213509771; c = b;
            w = 0.109951743655322; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );
            
        } else if (order == 5){

            npoints = 1+3+3;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.225000000000000; w *= 0.5;
            i = fem_addTriangleIntPts_real(1, i, a, b, c, w, xi, eta, zeta, weights );
            
            a = 0.059715871789770; b = 0.470142064105115; c = b;
            w = 0.132394152788506; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.797426985353087; b = 0.101286507323456; c = b;
            w = 0.125939180544827; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            
        } else if (order == 6){

            npoints = 3+3+6;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 

            a = 0.501426509658179; b = 0.249286745170910; c = b;
            w = 0.116786275726379; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.873821971016996; b = 0.063089014491502; c = b;
            w = 0.050844906370207; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.053145049844817; b = 0.310352451033784; c = 0.636502499121399;
            w = 0.082851075618374; w *= 0.5;
            i = fem_addTriangleIntPts_real(6, i, a, b, c, w, xi, eta, zeta, weights );
            
        } else if (order == 7){

            npoints = 1+3+3+6;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w =-0.149570044467682; w *= 0.5;
            i = fem_addTriangleIntPts_real(1, i, a, b, c, w, xi, eta, zeta, weights );
            
            a = 0.479308067841920; b = 0.260345966079040; c = b;
            w = 0.175615257433208; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.869739794195568; b = 0.065130102902216; c = b;
            w = 0.053347235608838; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.048690315425316; b = 0.312865496004874; c = 0.638444188569810;
            w = 0.077113760890257; w *= 0.5;
            i = fem_addTriangleIntPts_real(6, i, a, b, c, w, xi, eta, zeta, weights );
            
        } else if (order == 8){

            npoints = 1+3+3+3+6;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.144315607677787; w *= 0.5;
            i = fem_addTriangleIntPts_real(1, i, a, b, c, w, xi, eta, zeta, weights );
            
            a = 0.081414823414554; b = 0.459292588292723; c = b;
            w = 0.095091634267285; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.658861384496480; b = 0.170569307751760; c = b;
            w = 0.103217370534718; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.898905543365938; b = 0.050547228317031; c = b;
            w = 0.032458497623198; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.008394777409958; b = 0.263112829634638; c = 0.728492392955404;
            w = 0.027230314174435; w *= 0.5;
            i = fem_addTriangleIntPts_real(6, i, a, b, c, w, xi, eta, zeta, weights ); 



        } else if (order == 9){

            npoints = 1+3+3+3+3+6;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.097135796282799; w *= 0.5;
            i = fem_addTriangleIntPts_real(1, i, a, b, c, w, xi, eta, zeta, weights );
            
            a = 0.020634961602525; b = 0.489682519198738; c = b;
            w = 0.031334700227139; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.125820817014127; b = 0.437089591492937; c = b;
            w = 0.077827541004774; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.623592928761935; b = 0.188203535619033; c = b;
            w = 0.079647738927210; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.910540973211095; b = 0.044729513394453; c = b;
            w = 0.025577675658698; w *= 0.5;
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.036838412054736; b = 0.221962989160766; c = 0.741198598784498;
            w = 0.043283539377289; w *= 0.5;
            i = fem_addTriangleIntPts_real(6, i, a, b, c, w, xi, eta, zeta, weights );

        
        } else {

            npoints = 1+3+3+6+6+6;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.090817990382754; w *= 0.5;
            i = fem_addTriangleIntPts_real(1, i, a, b, c, w, xi, eta, zeta, weights );
            
            a = 0.028844733232685; b = 0.485577633383657; c = b;
            w = 0.036725957756467; w *= 0.5;            
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.781036849029926; b = 0.109481575485037; c = b;
            w = 0.045321059435528; w *= 0.5;            
            i = fem_addTriangleIntPts_real(3, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.141707219414880; b = 0.307939838764121; c = 0.550352941820999;
            w = 0.072757916845420; w *= 0.5;
            i = fem_addTriangleIntPts_real(6, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.025003534762686; b = 0.246672560639903; c = 0.728323904597411;
            w = 0.028327242531057; w *= 0.5;
            i = fem_addTriangleIntPts_real(6, i, a, b, c, w, xi, eta, zeta, weights );

            a = 0.009540815400299; b = 0.066803251012200; c = 0.923655933587500;
            w = 0.009421666963733; w *= 0.5;
            i = fem_addTriangleIntPts_real(6, i, a, b, c, w, xi, eta, zeta, weights );

        }


    } else if (elementType == elTetrahedra){

        // Tetrahedral element .
        ndim = 3;

        if (order <= 1){ // Accepts 0 or 1.

            npoints = 1;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.250000000000000; b = a; c = a; d = a;
            w = 1.000000000000000; w /= 6.0;
            i = fem_addTetrahedraIntPts_real(1, i, a, b, c, d, w, xi, eta, zeta, weights );

        } else if (order == 2){

            npoints = 4;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Points 0, 1, 2, 3
            i = 0; 
            a = 0.585410196624969; b = 0.138196601125011; c = b; d = b;
            w = 0.250000000000000; w /= 6.0;
            i = fem_addTetrahedraIntPts_real(4, i, a, b, c, d, w, xi, eta, zeta, weights );

        } else if (order == 3){

            npoints = 1+4;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.250000000000000; b = a; c = a; d = a;
            w =-0.800000000000000; w /= 6.0;
            i = fem_addTetrahedraIntPts_real(1, i, a, b, c, d, w, xi, eta, zeta, weights );

            a = 0.500000000000000; b = 0.166666666666667; c = b; d = b;
            w = 0.450000000000000; w /= 6.0;
            i = fem_addTetrahedraIntPts_real(4, i, a, b, c, d, w, xi, eta, zeta, weights );

        } else if (order == 4){

            npoints = 1+4+6;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.250000000000000; b = a; c = a; d = a;
            w =-0.013155555555556; //w /= 6.0;
            i = fem_addTetrahedraIntPts_real(1, i, a, b, c, d, w, xi, eta, zeta, weights );

            a = 0.785714285714286; b = 0.071428571428571; c = b; d = b;
            w = 0.007622222222222; //w /= 6.0;
            i = fem_addTetrahedraIntPts_real(4, i, a, b, c, d, w, xi, eta, zeta, weights );

            a = 0.399403576166799; b = 0.100596423833201; c = a; d = b;
            w = 0.024888888888889; //w /= 6.0;
            i = fem_addTetrahedraIntPts_real(6, i, a, b, c, d, w, xi, eta, zeta, weights );
        
        } else { // Order >= 5.

            npoints = 1+4+4+6;

            // Create as reals
            *xi      = fednum_zeros( npoints );
            *eta     = fednum_zeros( npoints );
            *zeta    = fednum_zeros( npoints );
            *weights = fednum_zeros( npoints );

            // Point 0
            i = 0; 
            a = 0.250000000000000; b = a; c = a; d = a;
            w = 0.030283678097089; //w /= 6.0;
            i = fem_addTetrahedraIntPts_real(1, i, a, b, c, d, w, xi, eta, zeta, weights );

            a = 0.000000000000000; b = 0.333333333333333; c = b; d = b;
            w = 0.006026785714286; //w /= 6.0;
            i = fem_addTetrahedraIntPts_real(4, i, a, b, c, d, w, xi, eta, zeta, weights );

            a = 0.727272727272727; b = 0.090909090909091; c = b; d = b;
            w = 0.011645249086029; //w /= 6.0;
            i = fem_addTetrahedraIntPts_real(4, i, a, b, c, d, w, xi, eta, zeta, weights );

            a = 0.066550153573664; b = 0.433449846426336; c = a; d = b;
            w = 0.010949141561386; //w /= 6.0;
            i = fem_addTetrahedraIntPts_real(6, i, a, b, c, d, w, xi, eta, zeta, weights );


        }

    } else if (elementType == elQuadrangle){

        fednum_t      xi_tmp;
        fednum_t     eta_tmp;
        fednum_t    zeta_tmp;
        fednum_t weights_tmp;

        coeff_t val_tmp = 0.0;

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;

        ndim = 2;

        // Call the solution for the corresponding 1D line element.
        fem_intPts_real(order, elLine, &xi_tmp, &eta_tmp, &zeta_tmp, &weights_tmp );

        npoints = xi_tmp.nip * xi_tmp.nip;

        // Create as reals
        *xi      = fednum_zeros( npoints );
        *eta     = fednum_zeros( npoints );
        *zeta    = fednum_zeros( npoints );
        *weights = fednum_zeros( npoints );

        for ( i = 0; i < xi_tmp.nip; i++ ){

            // Get the first weight.
            fednum_get_item_k_to(     &xi_tmp, i, &val_tmp ); a      = val_tmp;
            fednum_get_item_k_to(&weights_tmp, i, &val_tmp ); w_tmp1 = val_tmp;

            for ( j = 0; j < xi_tmp.nip; j++ ){

                // Get the second weight.
                fednum_get_item_k_to(     &xi_tmp, j, &val_tmp ); b      = val_tmp;
                fednum_get_item_k_to(&weights_tmp, j, &val_tmp ); w_tmp2 = val_tmp;

                w = w_tmp1 * w_tmp2;
                
                fednum_set_item_k_r( a, xi_tmp.nip * i + j, xi      );
                fednum_set_item_k_r( b, xi_tmp.nip * i + j, eta     );
                fednum_set_item_k_r( w, xi_tmp.nip * i + j, weights );

            }

        }

        fednum_free(      &xi_tmp );
        fednum_free(     &eta_tmp );
        fednum_free(    &zeta_tmp );
        fednum_free( &weights_tmp );

    } else if (elementType == elQuadrangleL){

        fednum_t      xi_tmp;
        fednum_t     eta_tmp;
        fednum_t    zeta_tmp;
        fednum_t weights_tmp;

        coeff_t val_tmp = 0.0;

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;

        ndim = 2;

        // Call the solution for the corresponding 1D line element.
        fem_intPts_real(order, elLineL, &xi_tmp, &eta_tmp, &zeta_tmp, &weights_tmp );

        npoints = xi_tmp.nip * xi_tmp.nip;

        // Create as reals
        *xi      = fednum_zeros( npoints );
        *eta     = fednum_zeros( npoints );
        *zeta    = fednum_zeros( npoints );
        *weights = fednum_zeros( npoints );

        for ( i = 0; i < xi_tmp.nip; i++ ){

            // Get the first weight.
            fednum_get_item_k_to(     &xi_tmp, i, &val_tmp ); a      = val_tmp;
            fednum_get_item_k_to(&weights_tmp, i, &val_tmp ); w_tmp1 = val_tmp;

            for ( j = 0; j < xi_tmp.nip; j++ ){

                // Get the second weight.
                fednum_get_item_k_to(     &xi_tmp, j, &val_tmp ); b      = val_tmp;
                fednum_get_item_k_to(&weights_tmp, j, &val_tmp ); w_tmp2 = val_tmp;

                w = w_tmp1 * w_tmp2;
                
                fednum_set_item_k_r( a, xi_tmp.nip * i + j, xi      );
                fednum_set_item_k_r( b, xi_tmp.nip * i + j, eta     );
                fednum_set_item_k_r( w, xi_tmp.nip * i + j, weights );

            }

        }

        fednum_free(      &xi_tmp );
        fednum_free(     &eta_tmp );
        fednum_free(    &zeta_tmp );
        fednum_free( &weights_tmp );  
        
    } else if (elementType == elHexahedra){

        // printf("Initializing elHexahedra.\n");

        fednum_t      xi_tmp;
        fednum_t     eta_tmp;
        fednum_t    zeta_tmp;
        fednum_t weights_tmp;

        coeff_t val_tmp = 0.0;

        uint64_t k = 0, currentIndex = 0 ;

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;
        double w_tmp3 = 0.0;

        ndim = 3;
        
        // Call the solution for the corresponding 1D line element.
        fem_intPts_real(order, elLine, &xi_tmp, &eta_tmp, &zeta_tmp, &weights_tmp );

        // Go for all possible combinations for 
        npoints = xi_tmp.nip * xi_tmp.nip * xi_tmp.nip;

        // Create as reals
        *xi      = fednum_zeros( npoints );
        *eta     = fednum_zeros( npoints );
        *zeta    = fednum_zeros( npoints );
        *weights = fednum_zeros( npoints );

        for ( i = 0; i < xi_tmp.nip; i++ ){

            // Get the first weight.
            fednum_get_item_k_to(     &xi_tmp, i, &val_tmp ); a      = val_tmp;
            fednum_get_item_k_to(&weights_tmp, i, &val_tmp ); w_tmp1 = val_tmp;

            for ( j = 0; j < xi_tmp.nip; j++ ){

                // Get the second weight.
                fednum_get_item_k_to(     &xi_tmp, j, &val_tmp); b      = val_tmp;
                fednum_get_item_k_to(&weights_tmp, j, &val_tmp); w_tmp2 = val_tmp;

                for ( k = 0; k < xi_tmp.nip; k++ ){

                    // Get the second weight.
                    fednum_get_item_k_to(     &xi_tmp, k, &val_tmp); c      = val_tmp;
                    fednum_get_item_k_to(&weights_tmp, k, &val_tmp); w_tmp3 = val_tmp;

                    w = w_tmp1 * w_tmp2 * w_tmp3;

                    fednum_set_item_k_r( a, currentIndex, xi     );
                    fednum_set_item_k_r( b, currentIndex, eta    );
                    fednum_set_item_k_r( c, currentIndex, zeta   );
                    fednum_set_item_k_r( w, currentIndex, weights);

                    currentIndex += 1;
                }

            }

        }

        fednum_free(      &xi_tmp );
        fednum_free(     &eta_tmp );
        fednum_free(    &zeta_tmp );
        fednum_free( &weights_tmp );
    
    } else if (elementType == elHexahedraL){

        // printf("Initializing elHexahedra.\n");

        fednum_t      xi_tmp;
        fednum_t     eta_tmp;
        fednum_t    zeta_tmp;
        fednum_t weights_tmp;

        coeff_t val_tmp = 0.0;

        uint64_t k = 0, currentIndex = 0 ;

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;
        double w_tmp3 = 0.0;

        ndim = 3;
        
        // Call the solution for the corresponding 1D line element.
        fem_intPts_real(order, elLineL, &xi_tmp, &eta_tmp, &zeta_tmp, &weights_tmp );

        // Go for all possible combinations for 
        npoints = xi_tmp.nip * xi_tmp.nip * xi_tmp.nip;

        // Create as reals
        *xi      = fednum_zeros( npoints );
        *eta     = fednum_zeros( npoints );
        *zeta    = fednum_zeros( npoints );
        *weights = fednum_zeros( npoints );

        for ( i = 0; i < xi_tmp.nip; i++ ){

            // Get the first weight.
            fednum_get_item_k_to(     &xi_tmp, i, &val_tmp ); a      = val_tmp;
            fednum_get_item_k_to(&weights_tmp, i, &val_tmp ); w_tmp1 = val_tmp;

            for ( j = 0; j < xi_tmp.nip; j++ ){

                // Get the second weight.
                fednum_get_item_k_to(     &xi_tmp, j, &val_tmp); b      = val_tmp;
                fednum_get_item_k_to(&weights_tmp, j, &val_tmp); w_tmp2 = val_tmp;

                for ( k = 0; k < xi_tmp.nip; k++ ){

                    // Get the second weight.
                    fednum_get_item_k_to(     &xi_tmp, k, &val_tmp); c      = val_tmp;
                    fednum_get_item_k_to(&weights_tmp, k, &val_tmp); w_tmp3 = val_tmp;

                    w = w_tmp1 * w_tmp2 * w_tmp3;

                    fednum_set_item_k_r( a, currentIndex, xi     );
                    fednum_set_item_k_r( b, currentIndex, eta    );
                    fednum_set_item_k_r( c, currentIndex, zeta   );
                    fednum_set_item_k_r( w, currentIndex, weights);

                    currentIndex += 1;
                }

            }

        }

        fednum_free(      &xi_tmp );
        fednum_free(     &eta_tmp );
        fednum_free(    &zeta_tmp );
        fednum_free( &weights_tmp );
    
    } else if (elementType == elWedge){

        // printf("Initializing elWedge.\n");

        fednum_t      xi_tri_tmp;
        fednum_t     eta_tri_tmp;
        fednum_t    zeta_tri_tmp;
        fednum_t weights_tri_tmp;

        fednum_t      xi_line_tmp;
        fednum_t     eta_line_tmp;
        fednum_t    zeta_line_tmp;
        fednum_t weights_line_tmp;

        sotinum_t val_tmp = soti_init();

        uint64_t currentIndex = 0 ;

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;

        ndim = 3;
        
        // Call the solution for the corresponding 1D line element.
        fem_intPts_real(order, elTriangle, &xi_tri_tmp, &eta_tri_tmp, &zeta_tri_tmp, &weights_tri_tmp);
        fem_intPts_real(order, elLine, &xi_line_tmp, &eta_line_tmp, &zeta_line_tmp, &weights_line_tmp);

        // Go for all possible combinations for 
        npoints = xi_tri_tmp.nip * xi_line_tmp.nip;

        // Create as reals
        *xi      = fednum_zeros( npoints );
        *eta     = fednum_zeros( npoints );
        *zeta    = fednum_zeros( npoints );
        *weights = fednum_zeros( npoints );

        for ( i = 0; i < xi_tri_tmp.nip; i++ ){

            // Get the first weight.
            fednum_get_item_k_to(     &xi_tri_tmp, i, &val_tmp );  a      = val_tmp.re;
            fednum_get_item_k_to(    &eta_tri_tmp, i, &val_tmp );  b      = val_tmp.re;
            fednum_get_item_k_to(&weights_tri_tmp, i, &val_tmp );  w_tmp1 = val_tmp.re;

            for ( j = 0; j < xi_line_tmp.nip; j++ ){

                // Get the second weight.
                fednum_get_item_k_to(     &xi_line_tmp, j, &val_tmp ); c      = val_tmp.re;
                fednum_get_item_k_to(&weights_line_tmp, j, &val_tmp ); w_tmp2 = val_tmp.re;

                w = w_tmp1 * w_tmp2;

                fednum_set_item_k_r( a, currentIndex, xi      );
                fednum_set_item_k_r( b, currentIndex, eta     );
                fednum_set_item_k_r( c, currentIndex, zeta    );
                fednum_set_item_k_r( w, currentIndex, weights );

                currentIndex += 1;
                
            }

        }

        fednum_free(      &xi_tri_tmp );
        fednum_free(     &eta_tri_tmp );
        fednum_free(    &zeta_tri_tmp );
        fednum_free( &weights_tri_tmp );

        fednum_free(      &xi_line_tmp );
        fednum_free(     &eta_line_tmp );
        fednum_free(    &zeta_line_tmp );
        fednum_free( &weights_line_tmp );
    
    } else {

        // Invalid element type entered.
        return OTI_FEM_InvalidElementType;

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t fem_addLineIntPts_real(uint8_t nperm, uint64_t start, double a,  double w,
                                fednum_t* xi, fednum_t* eta, fednum_t* zeta, 
                                fednum_t* weights){
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
        fednum_set_item_k_r( a, i, xi     );
        fednum_set_item_k_r( w, i, weights);

    } else if (nperm == 2){

        // Point 1
        fednum_set_item_k_r(-a, i, xi     );
        fednum_set_item_k_r( w, i, weights);

        // Point 2
        i+= 1; 
        fednum_set_item_k_r( a, i, xi     );
        fednum_set_item_k_r( w, i, weights);

    }

    return i+1;
}   
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
uint64_t fem_addTriangleIntPts_real(uint8_t nperm, uint64_t start, 
                                    double a, double b, double c, double w,
                                    fednum_t* xi, fednum_t* eta, fednum_t* zeta, 
                                    fednum_t* weights){
    /*
    fem_addTriangleIntPts_real( numberOfPermutations,  startPoint, 
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
        fednum_set_item_k_r( b, i, xi      );
        fednum_set_item_k_r( c, i, eta     );
        fednum_set_item_k_r( w, i, weights );

    } else if (nperm == 3){

        // Point 1
        
        fednum_set_item_k_r( b, i, xi      );
        fednum_set_item_k_r( b, i, eta     );
        fednum_set_item_k_r( w, i, weights );

        // Point 2
        i+= 1; 
        fednum_set_item_k_r( a, i, xi      );
        fednum_set_item_k_r( b, i, eta     );
        fednum_set_item_k_r( w, i, weights );

        // Point 3
        i+= 1; 
        fednum_set_item_k_r( b, i, xi      );
        fednum_set_item_k_r( a, i, eta     );
        fednum_set_item_k_r( w, i, weights );

    } else if (nperm == 6){
        
        // Point 1
        fednum_set_item_k_r( b, i, xi      );
        fednum_set_item_k_r( c, i, eta     );
        fednum_set_item_k_r( w, i, weights );

        // Point 2
        i+= 1; 
        fednum_set_item_k_r( c, i, xi      );
        fednum_set_item_k_r( b, i, eta     );
        fednum_set_item_k_r( w, i, weights );

        // Point 3
        i+= 1; 
        fednum_set_item_k_r( a, i, xi      );
        fednum_set_item_k_r( c, i, eta     );
        fednum_set_item_k_r( w, i, weights );

        // Point 4
        i+= 1; 
        fednum_set_item_k_r( c, i, xi      );
        fednum_set_item_k_r( a, i, eta     );
        fednum_set_item_k_r( w, i, weights );

        // Point 5
        i+= 1; 
        fednum_set_item_k_r( a, i, xi      );
        fednum_set_item_k_r( b, i, eta     );
        fednum_set_item_k_r( w, i, weights );

        // Point 6
        i+= 1;
        fednum_set_item_k_r( b, i, xi      );
        fednum_set_item_k_r( a, i, eta     );
        fednum_set_item_k_r( w, i, weights );
    }

    return i+1;
}   
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
uint64_t fem_addTetrahedraIntPts_real(uint8_t nperm, uint64_t start, 
                                      double a, double b, double c, double d, double w,
                                      fednum_t* xi, fednum_t* eta, fednum_t* zeta, 
                                      fednum_t* weights){
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
        fednum_set_item_k_r( a, i, xi     );
        fednum_set_item_k_r( a, i, eta    );
        fednum_set_item_k_r( a, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

    } else if (nperm == 4){

        // Point 1
        fednum_set_item_k_r( a, i, xi     );
        fednum_set_item_k_r( b, i, eta    );
        fednum_set_item_k_r( b, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 2
        i+= 1; 
        fednum_set_item_k_r( b, i, xi     );
        fednum_set_item_k_r( a, i, eta    );
        fednum_set_item_k_r( b, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 3
        i+= 1; 
        fednum_set_item_k_r( b, i, xi     );
        fednum_set_item_k_r( b, i, eta    );
        fednum_set_item_k_r( a, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 4
        i+= 1; 
        fednum_set_item_k_r( b, i, xi     );
        fednum_set_item_k_r( b, i, eta    );
        fednum_set_item_k_r( b, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

    } else if (nperm == 6){
        
        // Point 1
        fednum_set_item_k_r( a, i, xi     );
        fednum_set_item_k_r( a, i, eta    );
        fednum_set_item_k_r( b, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 2
        i+= 1; 
        fednum_set_item_k_r( a, i, xi     );
        fednum_set_item_k_r( b, i, eta    );
        fednum_set_item_k_r( a, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 3
        i+= 1; 
        fednum_set_item_k_r( a, i, xi     );
        fednum_set_item_k_r( b, i, eta    );
        fednum_set_item_k_r( b, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 4
        i+= 1; 
        fednum_set_item_k_r( b, i, xi     );
        fednum_set_item_k_r( a, i, eta    );
        fednum_set_item_k_r( a, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 5
        i+= 1; 
        fednum_set_item_k_r( b, i, xi     );
        fednum_set_item_k_r( a, i, eta    );
        fednum_set_item_k_r( b, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 6
        i+= 1;
        fednum_set_item_k_r( b, i, xi     );
        fednum_set_item_k_r( b, i, eta    );
        fednum_set_item_k_r( a, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

    } else if (nperm == 12){
        
        // Point 1
        fednum_set_item_k_r( a, i, xi     );
        fednum_set_item_k_r( b, i, eta    );
        fednum_set_item_k_r( c, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 2
        i+= 1; 
        fednum_set_item_k_r( b, i, xi     );
        fednum_set_item_k_r( a, i, eta    );
        fednum_set_item_k_r( c, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 3
        i+= 1; 
        fednum_set_item_k_r( a, i, xi     );
        fednum_set_item_k_r( c, i, eta    );
        fednum_set_item_k_r( b, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 4
        i+= 1; 
        fednum_set_item_k_r( c, i, xi     );
        fednum_set_item_k_r( a, i, eta    );
        fednum_set_item_k_r( b, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 5
        i+= 1; 
        fednum_set_item_k_r( b, i, xi     );
        fednum_set_item_k_r( c, i, eta    );
        fednum_set_item_k_r( a, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

        // Point 6
        i+= 1;
        fednum_set_item_k_r( c, i, xi     );
        fednum_set_item_k_r( b, i, eta    );
        fednum_set_item_k_r( a, i, zeta   );
        fednum_set_item_k_r( w, i, weights);

    }

    return i+1;
}   
// ----------------------------------------------------------------------------------------------------




