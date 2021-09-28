// Gmsh project created on Fri Apr 14 13:12:50 2017

he = 1.0/15.0; // Element size
hight = 0.1;
r1 = 1.0;
r2 = 1.5;

Point(1) = {     r1,    hight/2.0, 0, he}; // Left up
Point(2) = {     r1,   -hight/2.0, 0, he}; // Center
Point(3) = {     r2,   hight/2.0, 0, he}; // Corner  2
Point(4) = {     r2,  -hight/2.0, 0, he}; // Corner  2




Line(1) = {1, 2};      // Left   - Straight line
Line(2) = {2, 4};      // Bottom - Straight line
Line(3) = {4, 3};      // Right  - Straight line
Line(4) = {3, 1};      // Up     - Straight line


Line Loop(6) = {1,2,3,4};


Plane Surface(8) = {6}; // Generate mesh surface.
//Printf("Hello world");  // Output something to gmsh terminal.



// Define labels for boundaries

Physical Line("inner" ,201) = {1};
Physical Line("outer" ,202) = {3};

// Define regions
Physical Surface("solid",301) = {8};


Transfinite Surface{8};
//Transfinite Line{2,4};
Recombine Surface {8};  Mesh.SecondOrderIncomplete=1;  // To obtain quads.


//Field[1] = AttractorAnisoCurve;
//Field[1].lMaxNormal = 10.0;
//Field[1].lMinNormal = 0.00001;
////Field[1].lMaxNormal = 1.0;
//Field[1].NNodesByEdge = 500;
//Field[1].EdgesList = {2,4};

//Field[2] = AttractorAnisoCurve;
//Field[2].lMaxNormal = 10.0;
//Field[2].lMinNormal = 0.0001;
////Field[2].lMaxNormal = 1.0;
//Field[2].NNodesByEdge = 3;
//Field[2].EdgesList = {1,3};

//Background Field = 1;

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
Save "simpleSquare.msh";


// Command to run it : 
// /Applications/Gmsh.app/Contents/MacOS/gmsh semicircle.geo -