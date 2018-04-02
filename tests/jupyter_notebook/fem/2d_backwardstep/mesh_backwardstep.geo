// Gmsh project 
//            <-------------------------------------- L1 ----------------------------------->         
//         ^  1 --------------------------------------------------------------------------- 2 ^ 
//         |  |                                                                             | |       
//         |  |                                                                             | |       
//    h_in |  |                                                                             | |       
//         |  |<------- L2 ------->                                                         | |  
//         v  6 ------------------ 5 (0,0)                                                  | | h_out
//                               ^ |                                                        | |      
//                       h_step  | |                                                        | |      
//                               v 4 ------------------------------------------------------ 3 v     
//                                
//                                
//                                                                                                
//                                                                                                
//                                                                                                


//he_1 = 20.0/500.0; // Element size
//he_2 = 20.0/ 20.0;

he_1 = 20.0/ 90.0; // Element size
he_2 = 20.0/500.0;


L1     = 20.0;
L2     =  2.0;
h_in   =  1.0;
h_step =  0.5;



Point(1) = {   -L2,    h_in, 0, he_1}; 
Point(2) = { L1-L2,    h_in, 0, he_1}; 
Point(3) = { L1-L2, -h_step, 0, he_1}; 
Point(4) = {   0.0, -h_step, 0, he_2}; 
Point(5) = {   0.0,     0.0, 0, he_2}; 
Point(6) = {   -L2,     0.0, 0, he_1}; 





Line(1) = {1, 6};      
Line(2) = {6, 5};      
Line(3) = {5, 4};      
Line(4) = {4, 3};
Line(5) = {3, 2};
Line(6) = {2, 1};      


Line Loop(7) = {1,2,3,4,5,6};


Plane Surface(8) = {7}; // Generate mesh surface.
//Printf("Hello world");  // Output something to gmsh terminal.



// Define labels for boundaries

Physical Line("inlet"       ,201) = {1};
Physical Line("bottom_wall" ,202) = {2,3,4};
Physical Line("outlet"      ,203) = {5};
Physical Line("top_wall"    ,204) = {6};



// Define regions
Physical Surface("fluid",301) = {8};

//Transfinite Line{1,2,3,4,5,6}
//Transfinite Surface{8}={4,3,2,1};
//Recombine Surface {8};  // To obtain quads.
Mesh.ElementOrder = 2;

// Set up binary mesh. 
Mesh.Binary=0;


// Mesh surfaces and lines.
Mesh 2; // 1: 1D
		// 2: 2D -> Contains 1D
		// 3: 3D -> Contains 2D and 1D

//OptimizeMesh "Netgen";  // Does not do anything
//RefineMesh;


// save mesh
Save "mesh_backwardstep.msh";


// Command to run it : 
// /Applications/Gmsh.app/Contents/MacOS/gmsh semicircle.geo -