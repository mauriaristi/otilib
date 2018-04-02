// Gmsh project created on Fri Apr 14 13:12:50 2017

he = 0.5; // Element size
hight = 20;
width = 40;

Point(1) = {     -hight/2.0,    hight/2.0, 0, he}; // Left up
Point(2) = {     -hight/2.0,   -hight/2.0, 0, he}; // Center
Point(3) = {width-hight/2.0,    hight/2.0, 0, he}; // Corner  2
Point(4) = {width-hight/2.0,   -hight/2.0, 0, he}; // Corner  2



n=4;
npoints_circle = 10;
r = 2.0; // Circle radius
theta = 0.0;

For i In {1:npoints_circle}
  theta = 2.0*Pi*(i-1.0)/(1.0*npoints_circle);
  Point(n+i) = {r*Cos(theta), r*Sin(theta), 0, he};
EndFor


Line(1) = {1, 2};      // Left   - Straight line
Line(2) = {2, 4};      // Bottom - Straight line
Line(3) = {4, 3};      // Right  - Straight line
Line(4) = {3, 1};      // Up     - Straight line


Spline(5) = {5,6,7,8,9,10,11,12,13,14,5}; // Spline line

Line Loop(6) = {1,2,3,4};
Line Loop(7) = {5};


Plane Surface(8) = {6,7}; // Generate mesh surface.
//Printf("Hello world");  // Output something to gmsh terminal.



// Define labels for boundaries
Physical Line("inlet" ,201) = {1};
Physical Line("wall"  ,202) = {2,4};
Physical Line("outlet",203) = {3};
Physical Line("object",204) = {5};


Physical Surface("fluid",301) = {8};


//Transfinite Line {1} = 10;
//Transfinite Line {3} = 10 Using Progression 2;
//Transfinite Line {2} = 100;

//Transfinite Surface {8} = {1,2,3}; // Makes structured mesh.
								   // Important to define three points to do 
								   // the structured thing.

//Recombine Surface {8};  // To obtain quads.
Mesh.ElementOrder = 1;

// Set up binary mesh. 
Mesh.Binary=1;


// Mesh surfaces and lines.
Mesh 2; // 1: 1D
		// 2: 2D -> Contains 1D
		// 3: 3D -> Contains 2D and 1D

//OptimizeMesh "Netgen";  // Does not do anything
//RefineMesh;


// save mesh
Save "pipe.msh";


// Command to run it : 
// /Applications/Gmsh.app/Contents/MacOS/gmsh semicircle.geo -//+

