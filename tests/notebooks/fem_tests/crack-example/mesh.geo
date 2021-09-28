he = 0.05;



Point(1) = {-1.000000,-1.000000, 0.000000, 1.000000*he};
Point(2) = { 1.000000,-1.000000, 0.000000, 1.000000*he};
Point(3) = { 1.000000, 1.000000, 0.000000, 1.000000*he};
Point(4) = {-1.000000, 1.000000, 0.000000, 1.000000*he};
Point(5) = {-1.000000, 0.000000, 0.000000, 1.000000*he};
Point(6) = { 0.000000, 0.000000, 0.000000, 1.000000*he};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 1};
Line(6) = {5, 6};

//+
//Point(13) = {-0.2, 0.2, 0, 2.000000*he};
//+
//Line(13) = {1, 13};
//BSpline(41) = {1, 14, 15, 16, 17, 18, 19, 20, 21, 22,23,24};
//BSpline(42) = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
Line Loop(1) = {1, 2, 3, 4, 5};
Plane Surface(1) = {1};

Line{6} In Surface{1};
// INITIAL MESH
//                         P
//                          ^ ^ ^ ^ ^ ^ ^
//                          | | | | | | | (pg 30)
//                          | | | | | | |
//                         6--------------5
//                         |			  |
//                         |			  |
//                         |	          |
//  (pg 40)                |              |
//               8_________|	          |________3
//            \|O|         7             4        |O|\
//            \|O|                                |O|\ (pg 20)
//            \|O|                     \ ^y       |O|\
//            \|O|                      \|   x    |O|\
//            \|O|_________10            \--->----|O|\
//               9         |             |1       2
//                         |             |
//                         |             |
//                         ^ y           |
//                         |   x         |
//                        11--->---------12
//                         OOOOOOOOOOOOOOO  (pg 10)
//                         ---------------
//                         / / / / / / / /
//+        Crack Mouth
//
Physical Point("Crack",       6) = {6};
Physical Point("Crack_start", 1) = {1};
//+
//+
Physical Line("bottom",10) = {11};
Physical Line("right", 20) = {2};
Physical Line("top",   30) = {5};
Physical Line("left",  40) = {8};
Physical Line("crack_path",100) = {6};

//+
Physical Surface(5) = {1};
Mesh.ElementOrder = 2;
Mesh.SecondOrderIncomplete = 1;
Mesh.SecondOrderLinear     = 1;
Mesh.RecombineAll=0; // 1: Quads
                     // 0: Triangles

Mesh 2;

Plugin(Crack).Dimension=1;                // Dimension of the crack 1: line, 2: surface.
Plugin(Crack).PhysicalGroup=100;          // Physical group that defines the crack itself.
Plugin(Crack).OpenBoundaryPhysicalGroup=1; // If desired, select an edge to be unconnected. Leave 0 for internal cracks. It must be of dimension-1
Plugin(Crack).NormalX=0;
Plugin(Crack).NormalY=0;
Plugin(Crack).NormalZ=1;
Plugin(Crack).Run;

// save mesh
Save "mesh.msh";
