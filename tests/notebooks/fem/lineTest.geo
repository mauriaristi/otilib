// Gmsh project created on Mon Nov  6 20:06:06 2017
l=1.0;
Point(1) = {0.00*l, 0, 0, 1.0};
Point(2) = {0.10*l, 0, 0, 1.0};
Point(3) = {0.20*l, 0, 0, 1.0};
Point(4) = {0.30*l, 0, 0, 1.0};
Point(5) = {0.40*l, 0, 0, 1.0};
Point(6) = {0.50*l, 0, 0, 1.0};
Point(7) = {0.60*l, 0, 0, 1.0};
Point(8) = {0.70*l, 0, 0, 1.0};
Point(9) = {0.80*l, 0, 0, 1.0};
Point(10) = {0.90*l, 0, 0, 1.0};
Point(11) = {1.00*l, 0, 0, 1.0};
Line(1)  = {1,  2 };
Line(2)  = {2,  3 };
Line(3)  = {3,  4 };
Line(4)  = {4,  5 };
Line(5)  = {5,  6 };
Line(6)  = {6,  7 };
Line(7)  = {7,  8 };
Line(8)  = {8,  9 };
Line(9)  = {9,  10};
Line(10) = {10, 11};


Physical Point("left", 402) = {1};
Physical Point("right",401) = {11};

Physical Line("domain",501) = {1,2,3,4,5,6,7,8,9,10};
