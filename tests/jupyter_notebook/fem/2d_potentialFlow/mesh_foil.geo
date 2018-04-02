// Gmsh project created on Fri Apr 14 13:12:50 2017

he = 0.5; // Element size
hight = 10;
width = 10;

Point(1) = {     -width/2.0,    hight/2.0, 0, he}; // Left up
Point(2) = {     -width/2.0,   -hight/2.0, 0, he}; // Center
Point(3) = {width-width/2.0,    hight/2.0, 0, he}; // Corner  2
Point(4) = {width-width/2.0,   -hight/2.0, 0, he}; // Corner  2



n=4;
npoints_circle = 30;
rot_theta = Pi/4.0;

t = 0.0;
y = 0.0;
he2 = 0.01;
theta = 0.0;
r = 0.0;
tx = 0.0;
ty = 0.0;
px = 0.0;
py = 0.0;
x2y2 = 0.0;


For i In {1:npoints_circle}
  
  px = (i-1.0)/(1.0*npoints_circle);
  py = Sqrt(px)*0.17735-0.075597*px-0.212836*px*px+0.17363*px*px*px-0.06254*px*px*px*px;
  
  
  r = Sqrt( px*px + py*py );
  theta = Atan2(py,px);

  tx = r*Cos(theta-rot_theta);
  ty = r*Sin(theta-rot_theta);


  Point(n+i) = {tx, ty, 0, he2};
EndFor

n=4+npoints_circle;

Printf("npoints 1 %d", n);
For i In {1:npoints_circle}
  
  px = (npoints_circle-i)/(1.0*npoints_circle);
  py = -(Sqrt(px)*0.17735-0.075597*px-0.212836*px*px+0.17363*px*px*px-0.06254*px*px*px*px);
  

  r = Sqrt( px*px + py*py );
  theta = Atan2(py,px);

  tx = r*Cos(theta-rot_theta);
  ty = r*Sin(theta-rot_theta);


  Point(n+i) = {tx, ty, 0, he2};


EndFor


n=4+2*npoints_circle+1;
r = 1.0;
theta = 0.0;

tx = r*Cos(theta-rot_theta);
ty = r*Sin(theta-rot_theta);
Point(n) = {tx, ty, 0, he2};

Printf("npoints 2 %d",n);

Line(1) = {1, 2};      // Left   - Straight line
Line(2) = {2, 4};      // Bottom - Straight line
Line(3) = {4, 3};      // Right  - Straight line
Line(4) = {3, 1};      // Up     - Straight line


Spline(5) = {65,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,65}; // Spline line
//Spline(6) = {}; // Spline line

Line Loop(7) = {1,2,3,4};
Line Loop(8) = {5};


Plane Surface(8) = {7,8}; // Generate mesh surface.



// Define labels for boundaries
Physical Line("right" ,201) = {1};
Physical Line("left"  ,202) = {2};
Physical Line("bottom",203) = {3};
Physical Line("top" ,204)   = {4};
Physical Line("foil",2053)     = {5};


Physical Surface("fluid",301) = {8};


//Transfinite Line {1} = 10;
//Transfinite Line {3} = 10 Using Progression 2;
//Transfinite Line {2} = 100;

//Transfinite Surface {8} = {1,2,3}; // Makes structured mesh.
								   // Important to define three points to do 
								   // the structured thing.

//Recombine Surface {8};  // To obtain quads.
//Mesh.ElementOrder = 1;

// Set up binary mesh. 
//Mesh.Binary=1;


// Mesh surfaces and lines.
//Mesh 2; // 1: 1D
		// 2: 2D -> Contains 1D
		// 3: 3D -> Contains 2D and 1D

//OptimizeMesh "Netgen";  // Does not do anything
//RefineMesh;


// save mesh
//Save "pipe.msh";


// Command to run it : 
// /Applications/Gmsh.app/Contents/MacOS/gmsh semicircle.geo -//+

