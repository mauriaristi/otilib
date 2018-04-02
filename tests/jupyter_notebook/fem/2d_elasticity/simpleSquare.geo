// Gmsh project created on Fri Apr 14 13:12:50 2017

he = 1.0/1.0; // Element size
hight = 4;
width = 20;

Point(1) = {     -width/2.0,    hight/2.0, 0, he}; // Left up
Point(2) = {     -width/2.0,   -hight/2.0, 0, he}; // Center
Point(3) = {width-width/2.0,    hight/2.0, 0, he}; // Corner  2
Point(4) = {width-width/2.0,   -hight/2.0, 0, he}; // Corner  2




Line(1) = {1, 2};      // Left   - Straight line
Line(2) = {2, 4};      // Bottom - Straight line
Line(3) = {4, 3};      // Right  - Straight line
Line(4) = {3, 1};      // Up     - Straight line


Line Loop(6) = {1,2,3,4};


Plane Surface(8) = {6}; // Generate mesh surface.
//Printf("Hello world");  // Output something to gmsh terminal.



// Define labels for boundaries

Physical Line("left"     ,201) = {1};
Physical Line("bottom"   ,202) = {2};
Physical Line("right"    ,203) = {3};
Physical Line("up"       ,204) = {4};

// Define regions
Physical Surface("fluid",301) = {8};


Transfinite Surface{8};
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
Save "simpleSquare.msh";


// Command to run it : 
// /Applications/Gmsh.app/Contents/MacOS/gmsh semicircle.geo -