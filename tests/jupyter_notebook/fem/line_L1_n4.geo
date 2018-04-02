// Gmsh project created on Mon Nov  6 20:06:06 2017
l=1.0;
Point(1) = {0.00*l, 0, 0, 1.0};
Point(2) = {0.25*l, 0, 0, 1.0};
Point(3) = {0.50*l, 0, 0, 1.0};
Point(4) = {0.75*l, 0, 0, 1.0};
Point(5) = {1.00*l, 0, 0, 1.0};
Line(1)  = {1,  2 };
Line(2)  = {2,  3 };
Line(3)  = {3,  4 };
Line(4)  = {4,  5 };



Physical Point("left", 402) = {1};
Physical Point("right",401) = {5};

Physical Line("domain",501) = {1,2,3,4};
