// Gmsh project created on Fri Apr 14 13:12:50 2017
                                                                                                   
//                                                                                                 
//          ^         (4)   *                                                                         
//          |          *             *                                                                 
//          |          *                  *                                                              
//          |          *                     *                                                         
//          |          *                        *                                                       
//          |     ^   (2)   *                                                                          
//          |     |              *                *                                                    
//      ro  |     |                                                                                   
//          |     |                   *                                                               
//          |     |                                 *                                                  
//          |     |                     *                                                             
//          | ri  |                                                                                   
//          |     |                                                                                   
//          |     |                      *           *                                                  
//          |     |                                                                                   
//          v     v   (1) (0,0)         (3) *  *  *  * (5)                                                      
//                                                                                                 
//                                                                                                 
//                                                                                
//                                                                                
//                                                                                


he = 1.0/5.0; // Element size

ri = 1.0;
ro = 2.0;






Point(1) = {     0.0,    0.0, 0, he}; // 
Point(2) = {     0.0,     ri, 0, he}; // 
Point(3) = {      ri,    0.0, 0, he}; // As in the sketch above.
Point(4) = {     0.0,     ro, 0, he}; // 
Point(5) = {      ro,    0.0, 0, he}; // 

Circle(1) = { 2,1,3 } ;
Circle(2) = { 5,1,4 } ;


Line(3) = {4, 2}; 
Line(4) = {3, 5}; 


Line Loop(6) = {1,2,3,4};


Ruled Surface(8) = {6}; // Generate mesh surface.
//Printf("Hello world");  // Output something to gmsh terminal.



// Define labels for boundaries

Physical Line("in"    ,201) = {1};
Physical Line("out"   ,202) = {2};
Physical Line("left"  ,203) = {3};
Physical Line("right" ,204) = {4};

// Define regions
Physical Surface("solid",301) = {8};


Transfinite Surface{8}={5,3,2} left;
Recombine Surface {8};  // To obtain quads.

Mesh.ElementOrder = 1;

// Set up binary mesh. 
Mesh.Binary=0;


// Mesh surfaces and lines.
Mesh 2; // 1: 1D
		// 2: 2D -> Contains 1D
		// 3: 3D -> Contains 2D and 1D

//OptimizeMesh "Netgen";  // Does not do anything
//RefineMesh;


// save mesh
Save "cylinder.msh";


// Command to run it : 
// /Applications/Gmsh.app/Contents/MacOS/gmsh semicircle.geo -