#include"test_writer.h"

onumm2n5_t onumm2n5_create_r(  double lhs){

  onumm2n5_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  res.e12 = 0.0;
  res.e22 = 0.0;
  // Order 3;
  res.e111 = 0.0;
  res.e112 = 0.0;
  res.e122 = 0.0;
  res.e222 = 0.0;
  // Order 4;
  res.e1111 = 0.0;
  res.e1112 = 0.0;
  res.e1122 = 0.0;
  res.e1222 = 0.0;
  res.e2222 = 0.0;
  // Order 5;
  res.e11111 = 0.0;
  res.e11112 = 0.0;
  res.e11122 = 0.0;
  res.e11222 = 0.0;
  res.e12222 = 0.0;
  res.e22222 = 0.0;

  return res;

}

void onumm2n5_print(  onumm2n5_t lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs.r);
  //  Order 1;
  printf(" + %.8g * e1",lhs.e1);
  printf(" + %.8g * e2",lhs.e2);
  //  Order 2;
  printf(" + %.8g * e11",lhs.e11);
  printf(" + %.8g * e12",lhs.e12);
  printf(" + %.8g * e22",lhs.e22);
  //  Order 3;
  printf(" + %.8g * e111",lhs.e111);
  printf(" + %.8g * e112",lhs.e112);
  printf(" + %.8g * e122",lhs.e122);
  printf(" + %.8g * e222",lhs.e222);
  //  Order 4;
  printf(" + %.8g * e1111",lhs.e1111);
  printf(" + %.8g * e1112",lhs.e1112);
  printf(" + %.8g * e1122",lhs.e1122);
  printf(" + %.8g * e1222",lhs.e1222);
  printf(" + %.8g * e2222",lhs.e2222);
  //  Order 5;
  printf(" + %.8g * e11111",lhs.e11111);
  printf(" + %.8g * e11112",lhs.e11112);
  printf(" + %.8g * e11122",lhs.e11122);
  printf(" + %.8g * e11222",lhs.e11222);
  printf(" + %.8g * e12222",lhs.e12222);
  printf(" + %.8g * e22222",lhs.e22222);
  printf("\n");

}

onumm2n5_t onumm2n5_add_oo(  onumm2n5_t lhs,  onumm2n5_t rhs){
  onumm2n5_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs.r + rhs.r;
  // Order 1
  res.e1 = lhs.e1 + rhs.e1;
  res.e2 = lhs.e2 + rhs.e2;
  // Order 2
  res.e11 = lhs.e11 + rhs.e11;
  res.e12 = lhs.e12 + rhs.e12;
  res.e22 = lhs.e22 + rhs.e22;
  // Order 3
  res.e111 = lhs.e111 + rhs.e111;
  res.e112 = lhs.e112 + rhs.e112;
  res.e122 = lhs.e122 + rhs.e122;
  res.e222 = lhs.e222 + rhs.e222;
  // Order 4
  res.e1111 = lhs.e1111 + rhs.e1111;
  res.e1112 = lhs.e1112 + rhs.e1112;
  res.e1122 = lhs.e1122 + rhs.e1122;
  res.e1222 = lhs.e1222 + rhs.e1222;
  res.e2222 = lhs.e2222 + rhs.e2222;
  // Order 5
  res.e11111 = lhs.e11111 + rhs.e11111;
  res.e11112 = lhs.e11112 + rhs.e11112;
  res.e11122 = lhs.e11122 + rhs.e11122;
  res.e11222 = lhs.e11222 + rhs.e11222;
  res.e12222 = lhs.e12222 + rhs.e12222;
  res.e22222 = lhs.e22222 + rhs.e22222;

  return res;

}

onumm2n5_t onumm2n5_add_ro(  double lhs,  onumm2n5_t rhs){
  onumm2n5_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs.r;
  // Order 1;
  res.e1 =  + rhs.e1;
  res.e2 =  + rhs.e2;
  // Order 2;
  res.e11 =  + rhs.e11;
  res.e12 =  + rhs.e12;
  res.e22 =  + rhs.e22;
  // Order 3;
  res.e111 =  + rhs.e111;
  res.e112 =  + rhs.e112;
  res.e122 =  + rhs.e122;
  res.e222 =  + rhs.e222;
  // Order 4;
  res.e1111 =  + rhs.e1111;
  res.e1112 =  + rhs.e1112;
  res.e1122 =  + rhs.e1122;
  res.e1222 =  + rhs.e1222;
  res.e2222 =  + rhs.e2222;
  // Order 5;
  res.e11111 =  + rhs.e11111;
  res.e11112 =  + rhs.e11112;
  res.e11122 =  + rhs.e11122;
  res.e11222 =  + rhs.e11222;
  res.e12222 =  + rhs.e12222;
  res.e22222 =  + rhs.e22222;

  return res;

}

onumm2n5_t onumm2n5_add_or(  onumm2n5_t lhs,  double rhs){
  onumm2n5_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs.r + rhs;
  // Order 1;
  res.e1 = lhs.e1;
  res.e2 = lhs.e2;
  // Order 2;
  res.e11 = lhs.e11;
  res.e12 = lhs.e12;
  res.e22 = lhs.e22;
  // Order 3;
  res.e111 = lhs.e111;
  res.e112 = lhs.e112;
  res.e122 = lhs.e122;
  res.e222 = lhs.e222;
  // Order 4;
  res.e1111 = lhs.e1111;
  res.e1112 = lhs.e1112;
  res.e1122 = lhs.e1122;
  res.e1222 = lhs.e1222;
  res.e2222 = lhs.e2222;
  // Order 5;
  res.e11111 = lhs.e11111;
  res.e11112 = lhs.e11112;
  res.e11122 = lhs.e11122;
  res.e11222 = lhs.e11222;
  res.e12222 = lhs.e12222;
  res.e22222 = lhs.e22222;

  return res;

}

onumm2n5_t onumm2n5_neg(  onumm2n5_t lhs){
  onumm2n5_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs.r;
  // Order 1;
  res.e1 = -lhs.e1;
  res.e2 = -lhs.e2;
  // Order 2;
  res.e11 = -lhs.e11;
  res.e12 = -lhs.e12;
  res.e22 = -lhs.e22;
  // Order 3;
  res.e111 = -lhs.e111;
  res.e112 = -lhs.e112;
  res.e122 = -lhs.e122;
  res.e222 = -lhs.e222;
  // Order 4;
  res.e1111 = -lhs.e1111;
  res.e1112 = -lhs.e1112;
  res.e1122 = -lhs.e1122;
  res.e1222 = -lhs.e1222;
  res.e2222 = -lhs.e2222;
  // Order 5;
  res.e11111 = -lhs.e11111;
  res.e11112 = -lhs.e11112;
  res.e11122 = -lhs.e11122;
  res.e11222 = -lhs.e11222;
  res.e12222 = -lhs.e12222;
  res.e22222 = -lhs.e22222;

  return res;
}

onumm2n5_t onumm2n5_sub_oo(  onumm2n5_t lhs,  onumm2n5_t rhs){
  onumm2n5_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs.r - rhs.r;
  // Order 1
  res.e1 = lhs.e1 - rhs.e1;
  res.e2 = lhs.e2 - rhs.e2;
  // Order 2
  res.e11 = lhs.e11 - rhs.e11;
  res.e12 = lhs.e12 - rhs.e12;
  res.e22 = lhs.e22 - rhs.e22;
  // Order 3
  res.e111 = lhs.e111 - rhs.e111;
  res.e112 = lhs.e112 - rhs.e112;
  res.e122 = lhs.e122 - rhs.e122;
  res.e222 = lhs.e222 - rhs.e222;
  // Order 4
  res.e1111 = lhs.e1111 - rhs.e1111;
  res.e1112 = lhs.e1112 - rhs.e1112;
  res.e1122 = lhs.e1122 - rhs.e1122;
  res.e1222 = lhs.e1222 - rhs.e1222;
  res.e2222 = lhs.e2222 - rhs.e2222;
  // Order 5
  res.e11111 = lhs.e11111 - rhs.e11111;
  res.e11112 = lhs.e11112 - rhs.e11112;
  res.e11122 = lhs.e11122 - rhs.e11122;
  res.e11222 = lhs.e11222 - rhs.e11222;
  res.e12222 = lhs.e12222 - rhs.e12222;
  res.e22222 = lhs.e22222 - rhs.e22222;

  return res;

}

onumm2n5_t onumm2n5_sub_ro(  double lhs,  onumm2n5_t rhs){
  onumm2n5_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs.r;
  // Order 1;
  res.e1 =  - rhs.e1;
  res.e2 =  - rhs.e2;
  // Order 2;
  res.e11 =  - rhs.e11;
  res.e12 =  - rhs.e12;
  res.e22 =  - rhs.e22;
  // Order 3;
  res.e111 =  - rhs.e111;
  res.e112 =  - rhs.e112;
  res.e122 =  - rhs.e122;
  res.e222 =  - rhs.e222;
  // Order 4;
  res.e1111 =  - rhs.e1111;
  res.e1112 =  - rhs.e1112;
  res.e1122 =  - rhs.e1122;
  res.e1222 =  - rhs.e1222;
  res.e2222 =  - rhs.e2222;
  // Order 5;
  res.e11111 =  - rhs.e11111;
  res.e11112 =  - rhs.e11112;
  res.e11122 =  - rhs.e11122;
  res.e11222 =  - rhs.e11222;
  res.e12222 =  - rhs.e12222;
  res.e22222 =  - rhs.e22222;

  return res;

}

onumm2n5_t onumm2n5_sub_or(  onumm2n5_t lhs,  double rhs){
  onumm2n5_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs.r - rhs;
  // Order 1;
  res.e1 = lhs.e1;
  res.e2 = lhs.e2;
  // Order 2;
  res.e11 = lhs.e11;
  res.e12 = lhs.e12;
  res.e22 = lhs.e22;
  // Order 3;
  res.e111 = lhs.e111;
  res.e112 = lhs.e112;
  res.e122 = lhs.e122;
  res.e222 = lhs.e222;
  // Order 4;
  res.e1111 = lhs.e1111;
  res.e1112 = lhs.e1112;
  res.e1122 = lhs.e1122;
  res.e1222 = lhs.e1222;
  res.e2222 = lhs.e2222;
  // Order 5;
  res.e11111 = lhs.e11111;
  res.e11112 = lhs.e11112;
  res.e11122 = lhs.e11122;
  res.e11222 = lhs.e11222;
  res.e12222 = lhs.e12222;
  res.e22222 = lhs.e22222;

  return res;

}

onumm2n5_t onumm2n5_mul_oo(  onumm2n5_t lhs,  onumm2n5_t rhs){
  onumm2n5_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs.r * rhs.r;
  // Order 1;
  res.e1 = lhs.r * rhs.e1 + lhs.e1 * rhs.r;
  res.e2 = lhs.r * rhs.e2 + lhs.e2 * rhs.r;
  // Order 2;
  res.e11 = lhs.r * rhs.e11 + lhs.e11 * rhs.r + lhs.e1 * rhs.e1;
  res.e12 = lhs.r * rhs.e12 + lhs.e12 * rhs.r + lhs.e1 * rhs.e2 
          + lhs.e2 * rhs.e1;
  res.e22 = lhs.r * rhs.e22 + lhs.e22 * rhs.r + lhs.e2 * rhs.e2;
  // Order 3;
  res.e111 = lhs.r * rhs.e111 + lhs.e111 * rhs.r + lhs.e1 * rhs.e11;
  res.e112 = lhs.r * rhs.e112 + lhs.e112 * rhs.r + lhs.e1 * rhs.e12 
           + lhs.e2 * rhs.e11;
  res.e122 = lhs.r * rhs.e122 + lhs.e122 * rhs.r + lhs.e1 * rhs.e22 
           + lhs.e2 * rhs.e12;
  res.e222 = lhs.r * rhs.e222 + lhs.e222 * rhs.r + lhs.e2 * rhs.e22;
  // Order 4;
  res.e1111 = lhs.r * rhs.e1111 + lhs.e1111 * rhs.r + lhs.e1 * rhs.e111 
            + lhs.e11 * rhs.e11;
  res.e1112 = lhs.r * rhs.e1112 + lhs.e1112 * rhs.r + lhs.e1 * rhs.e112 
            + lhs.e2 * rhs.e111 + lhs.e11 * rhs.e12 + lhs.e12 * rhs.e11;
  res.e1122 = lhs.r * rhs.e1122 + lhs.e1122 * rhs.r + lhs.e1 * rhs.e122 
            + lhs.e2 * rhs.e112 + lhs.e11 * rhs.e22 + lhs.e12 * rhs.e12 
            + lhs.e22 * rhs.e11;
  res.e1222 = lhs.r * rhs.e1222 + lhs.e1222 * rhs.r + lhs.e1 * rhs.e222 
            + lhs.e2 * rhs.e122 + lhs.e12 * rhs.e22 + lhs.e22 * rhs.e12;
  res.e2222 = lhs.r * rhs.e2222 + lhs.e2222 * rhs.r + lhs.e2 * rhs.e222 
            + lhs.e22 * rhs.e22;
  // Order 5;
  res.e11111 = lhs.r * rhs.e11111 + lhs.e11111 * rhs.r + lhs.e1 * rhs.e1111 
             + lhs.e11 * rhs.e111;
  res.e11112 = lhs.r * rhs.e11112 + lhs.e11112 * rhs.r + lhs.e1 * rhs.e1112 
             + lhs.e2 * rhs.e1111 + lhs.e11 * rhs.e112 + lhs.e12 * rhs.e111;
  res.e11122 = lhs.r * rhs.e11122 + lhs.e11122 * rhs.r + lhs.e1 * rhs.e1122 
             + lhs.e2 * rhs.e1112 + lhs.e11 * rhs.e122 + lhs.e12 * rhs.e112 
             + lhs.e22 * rhs.e111;
  res.e11222 = lhs.r * rhs.e11222 + lhs.e11222 * rhs.r + lhs.e1 * rhs.e1222 
             + lhs.e2 * rhs.e1122 + lhs.e11 * rhs.e222 + lhs.e12 * rhs.e122 
             + lhs.e22 * rhs.e112;
  res.e12222 = lhs.r * rhs.e12222 + lhs.e12222 * rhs.r + lhs.e1 * rhs.e2222 
             + lhs.e2 * rhs.e1222 + lhs.e12 * rhs.e222 + lhs.e22 * rhs.e122;
  res.e22222 = lhs.r * rhs.e22222 + lhs.e22222 * rhs.r + lhs.e2 * rhs.e2222 
             + lhs.e22 * rhs.e222;

  return res;

}

onumm2n5_t onumm2n5_mul_ro(  double lhs,  onumm2n5_t rhs){
  onumm2n5_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs.r;
  // Order 1;
  res.e1 = lhs * rhs.e1;
  res.e2 = lhs * rhs.e2;
  // Order 2;
  res.e11 = lhs * rhs.e11;
  res.e12 = lhs * rhs.e12;
  res.e22 = lhs * rhs.e22;
  // Order 3;
  res.e111 = lhs * rhs.e111;
  res.e112 = lhs * rhs.e112;
  res.e122 = lhs * rhs.e122;
  res.e222 = lhs * rhs.e222;
  // Order 4;
  res.e1111 = lhs * rhs.e1111;
  res.e1112 = lhs * rhs.e1112;
  res.e1122 = lhs * rhs.e1122;
  res.e1222 = lhs * rhs.e1222;
  res.e2222 = lhs * rhs.e2222;
  // Order 5;
  res.e11111 = lhs * rhs.e11111;
  res.e11112 = lhs * rhs.e11112;
  res.e11122 = lhs * rhs.e11122;
  res.e11222 = lhs * rhs.e11222;
  res.e12222 = lhs * rhs.e12222;
  res.e22222 = lhs * rhs.e22222;

  return res;

}

onumm2n5_t onumm2n5_mul_or(  onumm2n5_t lhs,  double rhs){
  onumm2n5_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs.r * rhs;
  // Order 1;
  res.e1 = lhs.e1 * rhs;
  res.e2 = lhs.e2 * rhs;
  // Order 2;
  res.e11 = lhs.e11 * rhs;
  res.e12 = lhs.e12 * rhs;
  res.e22 = lhs.e22 * rhs;
  // Order 3;
  res.e111 = lhs.e111 * rhs;
  res.e112 = lhs.e112 * rhs;
  res.e122 = lhs.e122 * rhs;
  res.e222 = lhs.e222 * rhs;
  // Order 4;
  res.e1111 = lhs.e1111 * rhs;
  res.e1112 = lhs.e1112 * rhs;
  res.e1122 = lhs.e1122 * rhs;
  res.e1222 = lhs.e1222 * rhs;
  res.e2222 = lhs.e2222 * rhs;
  // Order 5;
  res.e11111 = lhs.e11111 * rhs;
  res.e11112 = lhs.e11112 * rhs;
  res.e11122 = lhs.e11122 * rhs;
  res.e11222 = lhs.e11222 * rhs;
  res.e12222 = lhs.e12222 * rhs;
  res.e22222 = lhs.e22222 * rhs;

  return res;

}

