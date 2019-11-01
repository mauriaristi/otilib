
// ****************************************************************************************************
void der_r_xy_power(coeff_t x, coeff_t y, ord_t order, coeff_t* derivs){


// ****************************************************************************************************
void der_r_xy_power(coeff_t x, coeff_t y, ord_t order, coeff_t* derivs){

  ord_t i;
  coeff_t xpy,x2,y2,x3,y3,x4,y4,x5,y5;
  coeff_t x6,y6,x7,y7,x8,y8,x9,y9,x10;
  for(i=0;i<=order;i++){
    switch(i){
      case 0:
        //d^0f/dx^0:
        xpy=pow(x,y);
        derivs[0]=xpy;
      case 1:
        //d^1f/dx^1:
        derivs[1]=xpy*y/x;
      case 2:
        //d^2f/dx^2:
        x2=x*x;
        derivs[2]=xpy*y*(y-1.)/x2;
      case 3:
        //d^3f/dx^3:
        y2=y*y;
        x3=x*x2;
        derivs[3]=xpy*y*(y2-3.*y+2.)/x3;
      case 4:
        //d^4f/dx^4:
        y3=y*y2;
        x4=x2*x2;
        derivs[4]=xpy*y*(y3-6.*y2+11.*y-6.)/x4;
      case 5:
        //d^5f/dx^5:
        y4=y2*y2;
        x5=x2*x3;
        derivs[5]=xpy*y*(y4-10.*y3+35.*y2-50.*y+24.)/x5;
      case 6:
        //d^6f/dx^6:
        y5=y2*y3;
        x6=x3*x3;
        derivs[6]=xpy*y*(y5-15.*y4+85.*y3-225.*y2+274.*y-120.)/x6;
      case 7:
        //d^7f/dx^7:
        y6=y3*y3;
        x7=x3*x4;
        derivs[7]=xpy*y*(y6-21.*y5+175.*y4-735.*y3+1624.*y2-1764.*y+720.)/x7;
      case 8:
        //d^8f/dx^8:
        y7=y3*y4;
        x8=x4*x4;
        derivs[8]=xpy*y*(y7-28.*y6+322.*y5-1960.*y4+6769.*y3-13132.*y2+13068.*y-5040.)/x8;
      case 9:
        //d^9f/dx^9:
        y8=y4*y4;
        x9=x4*x5;
        derivs[9]=xpy*y*(y8-36.*y7+546.*y6-4536.*y5+22449.*y4-67284.*y3+118124.*y2-109584.*y+40320.)/x9;
      case 10:
        //d^10f/dx^10:
        y9=y4*y5;
        x10=x5*x5;
        derivs[10]=xpy*y*(y9-45.*y8+870.*y7-9450.*y6+63273.*y5-269325.*y4+723680.*y3-1172700.*y2+1026576.*y-362880.)/x10;
    }
  }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_xy_division(coeff_t x, coeff_t y, ord_t order, coeff_t* derivs){


// ****************************************************************************************************
void der_r_xy_power(coeff_t x, coeff_t y, ord_t order, coeff_t* derivs){


// ****************************************************************************************************
void der_r_xy_power(coeff_t x, coeff_t y, ord_t order, coeff_t* derivs){

  ord_t i;
  coeff_t xpy,x2,y2,x3,y3,x4,y4,x5,y5;
  coeff_t x6,y6,x7,y7,x8,y8,x9,y9,x10;
  for(i=0;i<=order;i++){
    switch(i){
      case 0:
        //d^0f/dx^0:
        xpy=pow(x,y);
        derivs[0]=xpy;
      case 1:
        //d^1f/dx^1:
        derivs[1]=xpy*y/x;
      case 2:
        //d^2f/dx^2:
        x2=x*x;
        derivs[2]=xpy*y*(y-1.)/x2;
      case 3:
        //d^3f/dx^3:
        y2=y*y;
        x3=x*x2;
        derivs[3]=xpy*y*(y2-3.*y+2.)/x3;
      case 4:
        //d^4f/dx^4:
        y3=y*y2;
        x4=x2*x2;
        derivs[4]=xpy*y*(y3-6.*y2+11.*y-6.)/x4;
      case 5:
        //d^5f/dx^5:
        y4=y2*y2;
        x5=x2*x3;
        derivs[5]=xpy*y*(y4-10.*y3+35.*y2-50.*y+24.)/x5;
      case 6:
        //d^6f/dx^6:
        y5=y2*y3;
        x6=x3*x3;
        derivs[6]=xpy*y*(y5-15.*y4+85.*y3-225.*y2+274.*y-120.)/x6;
      case 7:
        //d^7f/dx^7:
        y6=y3*y3;
        x7=x3*x4;
        derivs[7]=xpy*y*(y6-21.*y5+175.*y4-735.*y3+1624.*y2-1764.*y+720.)/x7;
      case 8:
        //d^8f/dx^8:
        y7=y3*y4;
        x8=x4*x4;
        derivs[8]=xpy*y*(y7-28.*y6+322.*y5-1960.*y4+6769.*y3-13132.*y2+13068.*y-5040.)/x8;
      case 9:
        //d^9f/dx^9:
        y8=y4*y4;
        x9=x4*x5;
        derivs[9]=xpy*y*(y8-36.*y7+546.*y6-4536.*y5+22449.*y4-67284.*y3+118124.*y2-109584.*y+40320.)/x9;
      case 10:
        //d^10f/dx^10:
        y9=y4*y5;
        x10=x5*x5;
        derivs[10]=xpy*y*(y9-45.*y8+870.*y7-9450.*y6+63273.*y5-269325.*y4+723680.*y3-1172700.*y2+1026576.*y-362880.)/x10;
    }
  }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_xy_division(coeff_t x, coeff_t y, ord_t order, coeff_t* derivs){

  ord_t i;
  coeff_t;
  for(i=0;i<=order;i++){
    switch(i){
      case 0:
        //d^0f/dx^0:
        derivs[0]=x/y;
      case 1:
        //d^1f/dx^1:
        derivs[1]=1./y;
      case 2:
        //d^2f/dx^2:
        derivs[2]=0;
      case 3:
        //d^3f/dx^3:
        derivs[3]=0;
      case 4:
        //d^4f/dx^4:
        derivs[4]=0;
      case 5:
        //d^5f/dx^5:
        derivs[5]=0;
      case 6:
        //d^6f/dx^6:
        derivs[6]=0;
      case 7:
        //d^7f/dx^7:
        derivs[7]=0;
      case 8:
        //d^8f/dx^8:
        derivs[8]=0;
      case 9:
        //d^9f/dx^9:
        derivs[9]=0;
      case 10:
        //d^10f/dx^10:
        derivs[10]=0;
    }
  }
}
// ----------------------------------------------------------------------------------------------------
