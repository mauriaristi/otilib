#include"test_writer.h"

onumm2n5_t onumm2n5_init(){

  onumm2n5_t res;

  // Init function
  // Real;
  res.r = 0.0;
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

void onumm2n5_set_r_to(  double lhs, onumm2n5_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  // Order 2;
  res->e11 = 0.0;
  res->e12 = 0.0;
  res->e22 = 0.0;
  // Order 3;
  res->e111 = 0.0;
  res->e112 = 0.0;
  res->e122 = 0.0;
  res->e222 = 0.0;
  // Order 4;
  res->e1111 = 0.0;
  res->e1112 = 0.0;
  res->e1122 = 0.0;
  res->e1222 = 0.0;
  res->e2222 = 0.0;
  // Order 5;
  res->e11111 = 0.0;
  res->e11112 = 0.0;
  res->e11122 = 0.0;
  res->e11222 = 0.0;
  res->e12222 = 0.0;
  res->e22222 = 0.0;

}

void onumm2n5_set_o_to(  onumm2n5_t* lhs, onumm2n5_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  // Order 3;
  res->e111 = lhs->e111;
  res->e112 = lhs->e112;
  res->e122 = lhs->e122;
  res->e222 = lhs->e222;
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  // Order 5;
  res->e11111 = lhs->e11111;
  res->e11112 = lhs->e11112;
  res->e11122 = lhs->e11122;
  res->e11222 = lhs->e11222;
  res->e12222 = lhs->e12222;
  res->e22222 = lhs->e22222;

}

double onumm2n5_get_item(imdir_t idx, ord_t order, onumm2n5_t* lhs){

  double res;

  // Get Imaginary coefficient.
  res = 0.0;
  // Real;
  switch (order){
    case 0:
      res = lhs->r;
      break;
    case 1:
      switch (idx){
        case 0:
          res = lhs->e1;
          break;
        case 1:
          res = lhs->e2;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0:
          res = lhs->e11;
          break;
        case 1:
          res = lhs->e12;
          break;
        case 2:
          res = lhs->e22;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          res = lhs->e111;
          break;
        case 1:
          res = lhs->e112;
          break;
        case 2:
          res = lhs->e122;
          break;
        case 3:
          res = lhs->e222;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0:
          res = lhs->e1111;
          break;
        case 1:
          res = lhs->e1112;
          break;
        case 2:
          res = lhs->e1122;
          break;
        case 3:
          res = lhs->e1222;
          break;
        case 4:
          res = lhs->e2222;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0:
          res = lhs->e11111;
          break;
        case 1:
          res = lhs->e11112;
          break;
        case 2:
          res = lhs->e11122;
          break;
        case 3:
          res = lhs->e11222;
          break;
        case 4:
          res = lhs->e12222;
          break;
        case 5:
          res = lhs->e22222;
          break;
      }
      break;
  }
  return res;

}

onumm2n5_t onumm2n5_copy(  onumm2n5_t* lhs){

  onumm2n5_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  // Order 2;
  res.e11 = lhs->e11;
  res.e12 = lhs->e12;
  res.e22 = lhs->e22;
  // Order 3;
  res.e111 = lhs->e111;
  res.e112 = lhs->e112;
  res.e122 = lhs->e122;
  res.e222 = lhs->e222;
  // Order 4;
  res.e1111 = lhs->e1111;
  res.e1112 = lhs->e1112;
  res.e1122 = lhs->e1122;
  res.e1222 = lhs->e1222;
  res.e2222 = lhs->e2222;
  // Order 5;
  res.e11111 = lhs->e11111;
  res.e11112 = lhs->e11112;
  res.e11122 = lhs->e11122;
  res.e11222 = lhs->e11222;
  res.e12222 = lhs->e12222;
  res.e22222 = lhs->e22222;

  return res;

}

void onumm2n5_copy_to(  onumm2n5_t* lhs, onumm2n5_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  // Order 3;
  res->e111 = lhs->e111;
  res->e112 = lhs->e112;
  res->e122 = lhs->e122;
  res->e222 = lhs->e222;
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  // Order 5;
  res->e11111 = lhs->e11111;
  res->e11112 = lhs->e11112;
  res->e11122 = lhs->e11122;
  res->e11222 = lhs->e11222;
  res->e12222 = lhs->e12222;
  res->e22222 = lhs->e22222;

}

void onumm2n5_print(  onumm2n5_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  //  Order 2;
  printf(" %+.8g*e11",lhs->e11);
  printf(" %+.8g*e12",lhs->e12);
  printf(" %+.8g*e22",lhs->e22);
  //  Order 3;
  printf(" %+.8g*e111",lhs->e111);
  printf(" %+.8g*e112",lhs->e112);
  printf(" %+.8g*e122",lhs->e122);
  printf(" %+.8g*e222",lhs->e222);
  //  Order 4;
  printf(" %+.8g*e1111",lhs->e1111);
  printf(" %+.8g*e1112",lhs->e1112);
  printf(" %+.8g*e1122",lhs->e1122);
  printf(" %+.8g*e1222",lhs->e1222);
  printf(" %+.8g*e2222",lhs->e2222);
  //  Order 5;
  printf(" %+.8g*e11111",lhs->e11111);
  printf(" %+.8g*e11112",lhs->e11112);
  printf(" %+.8g*e11122",lhs->e11122);
  printf(" %+.8g*e11222",lhs->e11222);
  printf(" %+.8g*e12222",lhs->e12222);
  printf(" %+.8g*e22222",lhs->e22222);
  printf("\n");

}

onumm2n5_t onumm2n5_neg(  onumm2n5_t* lhs){

  onumm2n5_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  res.e2 = -lhs->e2;
  // Order 2;
  res.e11 = -lhs->e11;
  res.e12 = -lhs->e12;
  res.e22 = -lhs->e22;
  // Order 3;
  res.e111 = -lhs->e111;
  res.e112 = -lhs->e112;
  res.e122 = -lhs->e122;
  res.e222 = -lhs->e222;
  // Order 4;
  res.e1111 = -lhs->e1111;
  res.e1112 = -lhs->e1112;
  res.e1122 = -lhs->e1122;
  res.e1222 = -lhs->e1222;
  res.e2222 = -lhs->e2222;
  // Order 5;
  res.e11111 = -lhs->e11111;
  res.e11112 = -lhs->e11112;
  res.e11122 = -lhs->e11122;
  res.e11222 = -lhs->e11222;
  res.e12222 = -lhs->e12222;
  res.e22222 = -lhs->e22222;

  return res;

}

void onumm2n5_neg_to(  onumm2n5_t* lhs, onumm2n5_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  res->e2 = -lhs->e2;
  // Order 2;
  res->e11 = -lhs->e11;
  res->e12 = -lhs->e12;
  res->e22 = -lhs->e22;
  // Order 3;
  res->e111 = -lhs->e111;
  res->e112 = -lhs->e112;
  res->e122 = -lhs->e122;
  res->e222 = -lhs->e222;
  // Order 4;
  res->e1111 = -lhs->e1111;
  res->e1112 = -lhs->e1112;
  res->e1122 = -lhs->e1122;
  res->e1222 = -lhs->e1222;
  res->e2222 = -lhs->e2222;
  // Order 5;
  res->e11111 = -lhs->e11111;
  res->e11112 = -lhs->e11112;
  res->e11122 = -lhs->e11122;
  res->e11222 = -lhs->e11222;
  res->e12222 = -lhs->e12222;
  res->e22222 = -lhs->e22222;

}

onumm2n5_t onumm2n5_add_oo(  onumm2n5_t* lhs,  onumm2n5_t* rhs){
  onumm2n5_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  res.e2 = lhs->e2 + rhs->e2;
  // Order 2
  res.e11 = lhs->e11 + rhs->e11;
  res.e12 = lhs->e12 + rhs->e12;
  res.e22 = lhs->e22 + rhs->e22;
  // Order 3
  res.e111 = lhs->e111 + rhs->e111;
  res.e112 = lhs->e112 + rhs->e112;
  res.e122 = lhs->e122 + rhs->e122;
  res.e222 = lhs->e222 + rhs->e222;
  // Order 4
  res.e1111 = lhs->e1111 + rhs->e1111;
  res.e1112 = lhs->e1112 + rhs->e1112;
  res.e1122 = lhs->e1122 + rhs->e1122;
  res.e1222 = lhs->e1222 + rhs->e1222;
  res.e2222 = lhs->e2222 + rhs->e2222;
  // Order 5
  res.e11111 = lhs->e11111 + rhs->e11111;
  res.e11112 = lhs->e11112 + rhs->e11112;
  res.e11122 = lhs->e11122 + rhs->e11122;
  res.e11222 = lhs->e11222 + rhs->e11222;
  res.e12222 = lhs->e12222 + rhs->e12222;
  res.e22222 = lhs->e22222 + rhs->e22222;

  return res;

}

void onumm2n5_add_oo_to(  onumm2n5_t* lhs,  onumm2n5_t* rhs, onumm2n5_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  res->e2 = lhs->e2 + rhs->e2;
  // Order 2
  res->e11 = lhs->e11 + rhs->e11;
  res->e12 = lhs->e12 + rhs->e12;
  res->e22 = lhs->e22 + rhs->e22;
  // Order 3
  res->e111 = lhs->e111 + rhs->e111;
  res->e112 = lhs->e112 + rhs->e112;
  res->e122 = lhs->e122 + rhs->e122;
  res->e222 = lhs->e222 + rhs->e222;
  // Order 4
  res->e1111 = lhs->e1111 + rhs->e1111;
  res->e1112 = lhs->e1112 + rhs->e1112;
  res->e1122 = lhs->e1122 + rhs->e1122;
  res->e1222 = lhs->e1222 + rhs->e1222;
  res->e2222 = lhs->e2222 + rhs->e2222;
  // Order 5
  res->e11111 = lhs->e11111 + rhs->e11111;
  res->e11112 = lhs->e11112 + rhs->e11112;
  res->e11122 = lhs->e11122 + rhs->e11122;
  res->e11222 = lhs->e11222 + rhs->e11222;
  res->e12222 = lhs->e12222 + rhs->e12222;
  res->e22222 = lhs->e22222 + rhs->e22222;

}

onumm2n5_t onumm2n5_add_ro(  double lhs,  onumm2n5_t* rhs){
  onumm2n5_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  res.e2 =  + rhs->e2;
  // Order 2;
  res.e11 =  + rhs->e11;
  res.e12 =  + rhs->e12;
  res.e22 =  + rhs->e22;
  // Order 3;
  res.e111 =  + rhs->e111;
  res.e112 =  + rhs->e112;
  res.e122 =  + rhs->e122;
  res.e222 =  + rhs->e222;
  // Order 4;
  res.e1111 =  + rhs->e1111;
  res.e1112 =  + rhs->e1112;
  res.e1122 =  + rhs->e1122;
  res.e1222 =  + rhs->e1222;
  res.e2222 =  + rhs->e2222;
  // Order 5;
  res.e11111 =  + rhs->e11111;
  res.e11112 =  + rhs->e11112;
  res.e11122 =  + rhs->e11122;
  res.e11222 =  + rhs->e11222;
  res.e12222 =  + rhs->e12222;
  res.e22222 =  + rhs->e22222;

  return res;

}

void onumm2n5_add_ro_to(  double lhs,  onumm2n5_t* rhs, onumm2n5_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  res->e2 =  + rhs->e2;
  // Order 2;
  res->e11 =  + rhs->e11;
  res->e12 =  + rhs->e12;
  res->e22 =  + rhs->e22;
  // Order 3;
  res->e111 =  + rhs->e111;
  res->e112 =  + rhs->e112;
  res->e122 =  + rhs->e122;
  res->e222 =  + rhs->e222;
  // Order 4;
  res->e1111 =  + rhs->e1111;
  res->e1112 =  + rhs->e1112;
  res->e1122 =  + rhs->e1122;
  res->e1222 =  + rhs->e1222;
  res->e2222 =  + rhs->e2222;
  // Order 5;
  res->e11111 =  + rhs->e11111;
  res->e11112 =  + rhs->e11112;
  res->e11122 =  + rhs->e11122;
  res->e11222 =  + rhs->e11222;
  res->e12222 =  + rhs->e12222;
  res->e22222 =  + rhs->e22222;

}

onumm2n5_t onumm2n5_sub_oo(  onumm2n5_t lhs,  onumm2n5_t* rhs){
  onumm2n5_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs.r - rhs->r;
  // Order 1
  res.e1 = lhs.e1 - rhs->e1;
  res.e2 = lhs.e2 - rhs->e2;
  // Order 2
  res.e11 = lhs.e11 - rhs->e11;
  res.e12 = lhs.e12 - rhs->e12;
  res.e22 = lhs.e22 - rhs->e22;
  // Order 3
  res.e111 = lhs.e111 - rhs->e111;
  res.e112 = lhs.e112 - rhs->e112;
  res.e122 = lhs.e122 - rhs->e122;
  res.e222 = lhs.e222 - rhs->e222;
  // Order 4
  res.e1111 = lhs.e1111 - rhs->e1111;
  res.e1112 = lhs.e1112 - rhs->e1112;
  res.e1122 = lhs.e1122 - rhs->e1122;
  res.e1222 = lhs.e1222 - rhs->e1222;
  res.e2222 = lhs.e2222 - rhs->e2222;
  // Order 5
  res.e11111 = lhs.e11111 - rhs->e11111;
  res.e11112 = lhs.e11112 - rhs->e11112;
  res.e11122 = lhs.e11122 - rhs->e11122;
  res.e11222 = lhs.e11222 - rhs->e11222;
  res.e12222 = lhs.e12222 - rhs->e12222;
  res.e22222 = lhs.e22222 - rhs->e22222;

  return res;

}

void onumm2n5_sub_oo_to(  onumm2n5_t lhs,  onumm2n5_t* rhs, onumm2n5_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs.r - rhs->r;
  // Order 1
  res->e1 = lhs.e1 - rhs->e1;
  res->e2 = lhs.e2 - rhs->e2;
  // Order 2
  res->e11 = lhs.e11 - rhs->e11;
  res->e12 = lhs.e12 - rhs->e12;
  res->e22 = lhs.e22 - rhs->e22;
  // Order 3
  res->e111 = lhs.e111 - rhs->e111;
  res->e112 = lhs.e112 - rhs->e112;
  res->e122 = lhs.e122 - rhs->e122;
  res->e222 = lhs.e222 - rhs->e222;
  // Order 4
  res->e1111 = lhs.e1111 - rhs->e1111;
  res->e1112 = lhs.e1112 - rhs->e1112;
  res->e1122 = lhs.e1122 - rhs->e1122;
  res->e1222 = lhs.e1222 - rhs->e1222;
  res->e2222 = lhs.e2222 - rhs->e2222;
  // Order 5
  res->e11111 = lhs.e11111 - rhs->e11111;
  res->e11112 = lhs.e11112 - rhs->e11112;
  res->e11122 = lhs.e11122 - rhs->e11122;
  res->e11222 = lhs.e11222 - rhs->e11222;
  res->e12222 = lhs.e12222 - rhs->e12222;
  res->e22222 = lhs.e22222 - rhs->e22222;

}

onumm2n5_t onumm2n5_sub_ro(  double lhs,  onumm2n5_t* rhs){
  onumm2n5_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  res.e2 =  - rhs->e2;
  // Order 2;
  res.e11 =  - rhs->e11;
  res.e12 =  - rhs->e12;
  res.e22 =  - rhs->e22;
  // Order 3;
  res.e111 =  - rhs->e111;
  res.e112 =  - rhs->e112;
  res.e122 =  - rhs->e122;
  res.e222 =  - rhs->e222;
  // Order 4;
  res.e1111 =  - rhs->e1111;
  res.e1112 =  - rhs->e1112;
  res.e1122 =  - rhs->e1122;
  res.e1222 =  - rhs->e1222;
  res.e2222 =  - rhs->e2222;
  // Order 5;
  res.e11111 =  - rhs->e11111;
  res.e11112 =  - rhs->e11112;
  res.e11122 =  - rhs->e11122;
  res.e11222 =  - rhs->e11222;
  res.e12222 =  - rhs->e12222;
  res.e22222 =  - rhs->e22222;

  return res;

}

void onumm2n5_sub_ro_to(  double lhs,  onumm2n5_t* rhs, onumm2n5_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  res->e2 =  - rhs->e2;
  // Order 2;
  res->e11 =  - rhs->e11;
  res->e12 =  - rhs->e12;
  res->e22 =  - rhs->e22;
  // Order 3;
  res->e111 =  - rhs->e111;
  res->e112 =  - rhs->e112;
  res->e122 =  - rhs->e122;
  res->e222 =  - rhs->e222;
  // Order 4;
  res->e1111 =  - rhs->e1111;
  res->e1112 =  - rhs->e1112;
  res->e1122 =  - rhs->e1122;
  res->e1222 =  - rhs->e1222;
  res->e2222 =  - rhs->e2222;
  // Order 5;
  res->e11111 =  - rhs->e11111;
  res->e11112 =  - rhs->e11112;
  res->e11122 =  - rhs->e11122;
  res->e11222 =  - rhs->e11222;
  res->e12222 =  - rhs->e12222;
  res->e22222 =  - rhs->e22222;

}

onumm2n5_t onumm2n5_sub_or(  onumm2n5_t* lhs,  double rhs){
  onumm2n5_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  // Order 2;
  res.e11 = lhs->e11;
  res.e12 = lhs->e12;
  res.e22 = lhs->e22;
  // Order 3;
  res.e111 = lhs->e111;
  res.e112 = lhs->e112;
  res.e122 = lhs->e122;
  res.e222 = lhs->e222;
  // Order 4;
  res.e1111 = lhs->e1111;
  res.e1112 = lhs->e1112;
  res.e1122 = lhs->e1122;
  res.e1222 = lhs->e1222;
  res.e2222 = lhs->e2222;
  // Order 5;
  res.e11111 = lhs->e11111;
  res.e11112 = lhs->e11112;
  res.e11122 = lhs->e11122;
  res.e11222 = lhs->e11222;
  res.e12222 = lhs->e12222;
  res.e22222 = lhs->e22222;

  return res;

}

void onumm2n5_sub_or_to(  onumm2n5_t* lhs,  double rhs, onumm2n5_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  // Order 3;
  res->e111 = lhs->e111;
  res->e112 = lhs->e112;
  res->e122 = lhs->e122;
  res->e222 = lhs->e222;
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  // Order 5;
  res->e11111 = lhs->e11111;
  res->e11112 = lhs->e11112;
  res->e11122 = lhs->e11122;
  res->e11222 = lhs->e11222;
  res->e12222 = lhs->e12222;
  res->e22222 = lhs->e22222;

}

onumm2n5_t onumm2n5_mul_oo(  onumm2n5_t* lhs,  onumm2n5_t* rhs){
  onumm2n5_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res.e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  // Order 2;
  res.e11 = lhs->r * rhs->e11 + lhs->e11 * rhs->r + lhs->e1 * rhs->e1;
  res.e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;
  res.e22 = lhs->r * rhs->e22 + lhs->e22 * rhs->r + lhs->e2 * rhs->e2;
  // Order 3;
  res.e111 = lhs->r * rhs->e111 + lhs->e111 * rhs->r + lhs->e1 * rhs->e11 
           + lhs->e11 * rhs->e1;
  res.e112 = lhs->r * rhs->e112 + lhs->e112 * rhs->r + lhs->e1 * rhs->e12 
           + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 + lhs->e11 * rhs->e2;
  res.e122 = lhs->r * rhs->e122 + lhs->e122 * rhs->r + lhs->e1 * rhs->e22 
           + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 + lhs->e12 * rhs->e2;
  res.e222 = lhs->r * rhs->e222 + lhs->e222 * rhs->r + lhs->e2 * rhs->e22 
           + lhs->e22 * rhs->e2;
  // Order 4;
  res.e1111 = lhs->r * rhs->e1111 + lhs->e1111 * rhs->r + lhs->e1 * rhs->e111 
            + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  res.e1112 = lhs->r * rhs->e1112 + lhs->e1112 * rhs->r + lhs->e1 * rhs->e112 
            + lhs->e112 * rhs->e1 + lhs->e2 * rhs->e111 + lhs->e111 * rhs->e2 
            + lhs->e11 * rhs->e12 + lhs->e12 * rhs->e11;
  res.e1122 = lhs->r * rhs->e1122 + lhs->e1122 * rhs->r + lhs->e1 * rhs->e122 
            + lhs->e122 * rhs->e1 + lhs->e2 * rhs->e112 + lhs->e112 * rhs->e2 
            + lhs->e11 * rhs->e22 + lhs->e12 * rhs->e12 + lhs->e22 * rhs->e11;
  res.e1222 = lhs->r * rhs->e1222 + lhs->e1222 * rhs->r + lhs->e1 * rhs->e222 
            + lhs->e222 * rhs->e1 + lhs->e2 * rhs->e122 + lhs->e122 * rhs->e2 
            + lhs->e12 * rhs->e22 + lhs->e22 * rhs->e12;
  res.e2222 = lhs->r * rhs->e2222 + lhs->e2222 * rhs->r + lhs->e2 * rhs->e222 
            + lhs->e222 * rhs->e2 + lhs->e22 * rhs->e22;
  // Order 5;
  res.e11111 = lhs->r * rhs->e11111 + lhs->e11111 * rhs->r + lhs->e1 * rhs->e1111 
             + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 + lhs->e111 * rhs->e11;
  res.e11112 = lhs->r * rhs->e11112 + lhs->e11112 * rhs->r + lhs->e1 * rhs->e1112 
             + lhs->e1112 * rhs->e1 + lhs->e2 * rhs->e1111 + lhs->e1111 * rhs->e2 
             + lhs->e11 * rhs->e112 + lhs->e112 * rhs->e11 + lhs->e12 * rhs->e111 
             + lhs->e111 * rhs->e12;
  res.e11122 = lhs->r * rhs->e11122 + lhs->e11122 * rhs->r + lhs->e1 * rhs->e1122 
             + lhs->e1122 * rhs->e1 + lhs->e2 * rhs->e1112 + lhs->e1112 * rhs->e2 
             + lhs->e11 * rhs->e122 + lhs->e122 * rhs->e11 + lhs->e12 * rhs->e112 
             + lhs->e112 * rhs->e12 + lhs->e22 * rhs->e111 + lhs->e111 * rhs->e22;
  res.e11222 = lhs->r * rhs->e11222 + lhs->e11222 * rhs->r + lhs->e1 * rhs->e1222 
             + lhs->e1222 * rhs->e1 + lhs->e2 * rhs->e1122 + lhs->e1122 * rhs->e2 
             + lhs->e11 * rhs->e222 + lhs->e222 * rhs->e11 + lhs->e12 * rhs->e122 
             + lhs->e122 * rhs->e12 + lhs->e22 * rhs->e112 + lhs->e112 * rhs->e22;
  res.e12222 = lhs->r * rhs->e12222 + lhs->e12222 * rhs->r + lhs->e1 * rhs->e2222 
             + lhs->e2222 * rhs->e1 + lhs->e2 * rhs->e1222 + lhs->e1222 * rhs->e2 
             + lhs->e12 * rhs->e222 + lhs->e222 * rhs->e12 + lhs->e22 * rhs->e122 
             + lhs->e122 * rhs->e22;
  res.e22222 = lhs->r * rhs->e22222 + lhs->e22222 * rhs->r + lhs->e2 * rhs->e2222 
             + lhs->e2222 * rhs->e2 + lhs->e22 * rhs->e222 + lhs->e222 * rhs->e22;

  return res;

}

void onumm2n5_mul_oo_to(  onumm2n5_t* lhs,  onumm2n5_t* rhs, onumm2n5_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res->e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  // Order 2;
  res->e11 = lhs->r * rhs->e11 + lhs->e11 * rhs->r + lhs->e1 * rhs->e1;
  res->e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;
  res->e22 = lhs->r * rhs->e22 + lhs->e22 * rhs->r + lhs->e2 * rhs->e2;
  // Order 3;
  res->e111 = lhs->r * rhs->e111 + lhs->e111 * rhs->r + lhs->e1 * rhs->e11 
           + lhs->e11 * rhs->e1;
  res->e112 = lhs->r * rhs->e112 + lhs->e112 * rhs->r + lhs->e1 * rhs->e12 
           + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 + lhs->e11 * rhs->e2;
  res->e122 = lhs->r * rhs->e122 + lhs->e122 * rhs->r + lhs->e1 * rhs->e22 
           + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 + lhs->e12 * rhs->e2;
  res->e222 = lhs->r * rhs->e222 + lhs->e222 * rhs->r + lhs->e2 * rhs->e22 
           + lhs->e22 * rhs->e2;
  // Order 4;
  res->e1111 = lhs->r * rhs->e1111 + lhs->e1111 * rhs->r + lhs->e1 * rhs->e111 
            + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  res->e1112 = lhs->r * rhs->e1112 + lhs->e1112 * rhs->r + lhs->e1 * rhs->e112 
            + lhs->e112 * rhs->e1 + lhs->e2 * rhs->e111 + lhs->e111 * rhs->e2 
            + lhs->e11 * rhs->e12 + lhs->e12 * rhs->e11;
  res->e1122 = lhs->r * rhs->e1122 + lhs->e1122 * rhs->r + lhs->e1 * rhs->e122 
            + lhs->e122 * rhs->e1 + lhs->e2 * rhs->e112 + lhs->e112 * rhs->e2 
            + lhs->e11 * rhs->e22 + lhs->e12 * rhs->e12 + lhs->e22 * rhs->e11;
  res->e1222 = lhs->r * rhs->e1222 + lhs->e1222 * rhs->r + lhs->e1 * rhs->e222 
            + lhs->e222 * rhs->e1 + lhs->e2 * rhs->e122 + lhs->e122 * rhs->e2 
            + lhs->e12 * rhs->e22 + lhs->e22 * rhs->e12;
  res->e2222 = lhs->r * rhs->e2222 + lhs->e2222 * rhs->r + lhs->e2 * rhs->e222 
            + lhs->e222 * rhs->e2 + lhs->e22 * rhs->e22;
  // Order 5;
  res->e11111 = lhs->r * rhs->e11111 + lhs->e11111 * rhs->r + lhs->e1 * rhs->e1111 
             + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 + lhs->e111 * rhs->e11;
  res->e11112 = lhs->r * rhs->e11112 + lhs->e11112 * rhs->r + lhs->e1 * rhs->e1112 
             + lhs->e1112 * rhs->e1 + lhs->e2 * rhs->e1111 + lhs->e1111 * rhs->e2 
             + lhs->e11 * rhs->e112 + lhs->e112 * rhs->e11 + lhs->e12 * rhs->e111 
             + lhs->e111 * rhs->e12;
  res->e11122 = lhs->r * rhs->e11122 + lhs->e11122 * rhs->r + lhs->e1 * rhs->e1122 
             + lhs->e1122 * rhs->e1 + lhs->e2 * rhs->e1112 + lhs->e1112 * rhs->e2 
             + lhs->e11 * rhs->e122 + lhs->e122 * rhs->e11 + lhs->e12 * rhs->e112 
             + lhs->e112 * rhs->e12 + lhs->e22 * rhs->e111 + lhs->e111 * rhs->e22;
  res->e11222 = lhs->r * rhs->e11222 + lhs->e11222 * rhs->r + lhs->e1 * rhs->e1222 
             + lhs->e1222 * rhs->e1 + lhs->e2 * rhs->e1122 + lhs->e1122 * rhs->e2 
             + lhs->e11 * rhs->e222 + lhs->e222 * rhs->e11 + lhs->e12 * rhs->e122 
             + lhs->e122 * rhs->e12 + lhs->e22 * rhs->e112 + lhs->e112 * rhs->e22;
  res->e12222 = lhs->r * rhs->e12222 + lhs->e12222 * rhs->r + lhs->e1 * rhs->e2222 
             + lhs->e2222 * rhs->e1 + lhs->e2 * rhs->e1222 + lhs->e1222 * rhs->e2 
             + lhs->e12 * rhs->e222 + lhs->e222 * rhs->e12 + lhs->e22 * rhs->e122 
             + lhs->e122 * rhs->e22;
  res->e22222 = lhs->r * rhs->e22222 + lhs->e22222 * rhs->r + lhs->e2 * rhs->e2222 
             + lhs->e2222 * rhs->e2 + lhs->e22 * rhs->e222 + lhs->e222 * rhs->e22;

}

onumm2n5_t onumm2n5_mul_ro(  double lhs,  onumm2n5_t* rhs){
  onumm2n5_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  res.e2 = lhs * rhs->e2;
  // Order 2;
  res.e11 = lhs * rhs->e11;
  res.e12 = lhs * rhs->e12;
  res.e22 = lhs * rhs->e22;
  // Order 3;
  res.e111 = lhs * rhs->e111;
  res.e112 = lhs * rhs->e112;
  res.e122 = lhs * rhs->e122;
  res.e222 = lhs * rhs->e222;
  // Order 4;
  res.e1111 = lhs * rhs->e1111;
  res.e1112 = lhs * rhs->e1112;
  res.e1122 = lhs * rhs->e1122;
  res.e1222 = lhs * rhs->e1222;
  res.e2222 = lhs * rhs->e2222;
  // Order 5;
  res.e11111 = lhs * rhs->e11111;
  res.e11112 = lhs * rhs->e11112;
  res.e11122 = lhs * rhs->e11122;
  res.e11222 = lhs * rhs->e11222;
  res.e12222 = lhs * rhs->e12222;
  res.e22222 = lhs * rhs->e22222;

  return res;

}

void onumm2n5_mul_ro_to(  double lhs,  onumm2n5_t* rhs, onumm2n5_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  res->e2 = lhs * rhs->e2;
  // Order 2;
  res->e11 = lhs * rhs->e11;
  res->e12 = lhs * rhs->e12;
  res->e22 = lhs * rhs->e22;
  // Order 3;
  res->e111 = lhs * rhs->e111;
  res->e112 = lhs * rhs->e112;
  res->e122 = lhs * rhs->e122;
  res->e222 = lhs * rhs->e222;
  // Order 4;
  res->e1111 = lhs * rhs->e1111;
  res->e1112 = lhs * rhs->e1112;
  res->e1122 = lhs * rhs->e1122;
  res->e1222 = lhs * rhs->e1222;
  res->e2222 = lhs * rhs->e2222;
  // Order 5;
  res->e11111 = lhs * rhs->e11111;
  res->e11112 = lhs * rhs->e11112;
  res->e11122 = lhs * rhs->e11122;
  res->e11222 = lhs * rhs->e11222;
  res->e12222 = lhs * rhs->e12222;
  res->e22222 = lhs * rhs->e22222;

}

onumm2n5_t onumm2n5_trunc_mul_oo(  onumm2n5_t* lhs,  onumm2n5_t* rhs){
  onumm2n5_t res;

  res = onumm2n5_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e11 =  + lhs->e1 * rhs->e1;
  res.e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res.e22 =  + lhs->e2 * rhs->e2;
  // Order 3;
  res.e111 =  + lhs->e1 * rhs->e11 + lhs->e11 * rhs->e1;
  res.e112 =  + lhs->e1 * rhs->e12 + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 
           + lhs->e11 * rhs->e2;
  res.e122 =  + lhs->e1 * rhs->e22 + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 
           + lhs->e12 * rhs->e2;
  res.e222 =  + lhs->e2 * rhs->e22 + lhs->e22 * rhs->e2;
  // Order 4;
  res.e1111 =  + lhs->e1 * rhs->e111 + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  res.e1112 =  + lhs->e1 * rhs->e112 + lhs->e112 * rhs->e1 + lhs->e2 * rhs->e111 
            + lhs->e111 * rhs->e2 + lhs->e11 * rhs->e12 + lhs->e12 * rhs->e11;
  res.e1122 =  + lhs->e1 * rhs->e122 + lhs->e122 * rhs->e1 + lhs->e2 * rhs->e112 
            + lhs->e112 * rhs->e2 + lhs->e11 * rhs->e22 + lhs->e12 * rhs->e12 
            + lhs->e22 * rhs->e11;
  res.e1222 =  + lhs->e1 * rhs->e222 + lhs->e222 * rhs->e1 + lhs->e2 * rhs->e122 
            + lhs->e122 * rhs->e2 + lhs->e12 * rhs->e22 + lhs->e22 * rhs->e12;
  res.e2222 =  + lhs->e2 * rhs->e222 + lhs->e222 * rhs->e2 + lhs->e22 * rhs->e22;
  // Order 5;
  res.e11111 =  + lhs->e1 * rhs->e1111 + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 
             + lhs->e111 * rhs->e11;
  res.e11112 =  + lhs->e1 * rhs->e1112 + lhs->e1112 * rhs->e1 + lhs->e2 * rhs->e1111 
             + lhs->e1111 * rhs->e2 + lhs->e11 * rhs->e112 + lhs->e112 * rhs->e11 
             + lhs->e12 * rhs->e111 + lhs->e111 * rhs->e12;
  res.e11122 =  + lhs->e1 * rhs->e1122 + lhs->e1122 * rhs->e1 + lhs->e2 * rhs->e1112 
             + lhs->e1112 * rhs->e2 + lhs->e11 * rhs->e122 + lhs->e122 * rhs->e11 
             + lhs->e12 * rhs->e112 + lhs->e112 * rhs->e12 + lhs->e22 * rhs->e111 
             + lhs->e111 * rhs->e22;
  res.e11222 =  + lhs->e1 * rhs->e1222 + lhs->e1222 * rhs->e1 + lhs->e2 * rhs->e1122 
             + lhs->e1122 * rhs->e2 + lhs->e11 * rhs->e222 + lhs->e222 * rhs->e11 
             + lhs->e12 * rhs->e122 + lhs->e122 * rhs->e12 + lhs->e22 * rhs->e112 
             + lhs->e112 * rhs->e22;
  res.e12222 =  + lhs->e1 * rhs->e2222 + lhs->e2222 * rhs->e1 + lhs->e2 * rhs->e1222 
             + lhs->e1222 * rhs->e2 + lhs->e12 * rhs->e222 + lhs->e222 * rhs->e12 
             + lhs->e22 * rhs->e122 + lhs->e122 * rhs->e22;
  res.e22222 =  + lhs->e2 * rhs->e2222 + lhs->e2222 * rhs->e2 + lhs->e22 * rhs->e222 
             + lhs->e222 * rhs->e22;

  return res;

}

void onumm2n5_trunc_mul_oo_to(  onumm2n5_t* lhs,  onumm2n5_t* rhs, onumm2n5_t* res){
   (*res) = onumm2n5_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e11 =  + lhs->e1 * rhs->e1;
  res->e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res->e22 =  + lhs->e2 * rhs->e2;
  // Order 3;
  res->e111 =  + lhs->e1 * rhs->e11 + lhs->e11 * rhs->e1;
  res->e112 =  + lhs->e1 * rhs->e12 + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 
           + lhs->e11 * rhs->e2;
  res->e122 =  + lhs->e1 * rhs->e22 + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 
           + lhs->e12 * rhs->e2;
  res->e222 =  + lhs->e2 * rhs->e22 + lhs->e22 * rhs->e2;
  // Order 4;
  res->e1111 =  + lhs->e1 * rhs->e111 + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  res->e1112 =  + lhs->e1 * rhs->e112 + lhs->e112 * rhs->e1 + lhs->e2 * rhs->e111 
            + lhs->e111 * rhs->e2 + lhs->e11 * rhs->e12 + lhs->e12 * rhs->e11;
  res->e1122 =  + lhs->e1 * rhs->e122 + lhs->e122 * rhs->e1 + lhs->e2 * rhs->e112 
            + lhs->e112 * rhs->e2 + lhs->e11 * rhs->e22 + lhs->e12 * rhs->e12 
            + lhs->e22 * rhs->e11;
  res->e1222 =  + lhs->e1 * rhs->e222 + lhs->e222 * rhs->e1 + lhs->e2 * rhs->e122 
            + lhs->e122 * rhs->e2 + lhs->e12 * rhs->e22 + lhs->e22 * rhs->e12;
  res->e2222 =  + lhs->e2 * rhs->e222 + lhs->e222 * rhs->e2 + lhs->e22 * rhs->e22;
  // Order 5;
  res->e11111 =  + lhs->e1 * rhs->e1111 + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 
             + lhs->e111 * rhs->e11;
  res->e11112 =  + lhs->e1 * rhs->e1112 + lhs->e1112 * rhs->e1 + lhs->e2 * rhs->e1111 
             + lhs->e1111 * rhs->e2 + lhs->e11 * rhs->e112 + lhs->e112 * rhs->e11 
             + lhs->e12 * rhs->e111 + lhs->e111 * rhs->e12;
  res->e11122 =  + lhs->e1 * rhs->e1122 + lhs->e1122 * rhs->e1 + lhs->e2 * rhs->e1112 
             + lhs->e1112 * rhs->e2 + lhs->e11 * rhs->e122 + lhs->e122 * rhs->e11 
             + lhs->e12 * rhs->e112 + lhs->e112 * rhs->e12 + lhs->e22 * rhs->e111 
             + lhs->e111 * rhs->e22;
  res->e11222 =  + lhs->e1 * rhs->e1222 + lhs->e1222 * rhs->e1 + lhs->e2 * rhs->e1122 
             + lhs->e1122 * rhs->e2 + lhs->e11 * rhs->e222 + lhs->e222 * rhs->e11 
             + lhs->e12 * rhs->e122 + lhs->e122 * rhs->e12 + lhs->e22 * rhs->e112 
             + lhs->e112 * rhs->e22;
  res->e12222 =  + lhs->e1 * rhs->e2222 + lhs->e2222 * rhs->e1 + lhs->e2 * rhs->e1222 
             + lhs->e1222 * rhs->e2 + lhs->e12 * rhs->e222 + lhs->e222 * rhs->e12 
             + lhs->e22 * rhs->e122 + lhs->e122 * rhs->e22;
  res->e22222 =  + lhs->e2 * rhs->e2222 + lhs->e2222 * rhs->e2 + lhs->e22 * rhs->e222 
             + lhs->e222 * rhs->e22;

}

onumm2n5_t onumm2n5_gem_oo(  onumm2n5_t* a,  onumm2n5_t* b,  onumm2n5_t* c){
  onumm2n5_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res.e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  // Order 2;
  res.e11 = c->e11 + a->r * b->e11 + a->e11 * b->r + a->e1 * b->e1;
  res.e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;
  res.e22 = c->e22 + a->r * b->e22 + a->e22 * b->r + a->e2 * b->e2;
  // Order 3;
  res.e111 = c->e111 + a->r * b->e111 + a->e111 * b->r + a->e1 * b->e11;
  res.e112 = c->e112 + a->r * b->e112 + a->e112 * b->r + a->e1 * b->e12 
           + a->e2 * b->e11;
  res.e122 = c->e122 + a->r * b->e122 + a->e122 * b->r + a->e1 * b->e22 
           + a->e2 * b->e12;
  res.e222 = c->e222 + a->r * b->e222 + a->e222 * b->r + a->e2 * b->e22;
  // Order 4;
  res.e1111 = c->e1111 + a->r * b->e1111 + a->e1111 * b->r + a->e1 * b->e111 
            + a->e11 * b->e11;
  res.e1112 = c->e1112 + a->r * b->e1112 + a->e1112 * b->r + a->e1 * b->e112 
            + a->e2 * b->e111 + a->e11 * b->e12 + a->e12 * b->e11;
  res.e1122 = c->e1122 + a->r * b->e1122 + a->e1122 * b->r + a->e1 * b->e122 
            + a->e2 * b->e112 + a->e11 * b->e22 + a->e12 * b->e12 
            + a->e22 * b->e11;
  res.e1222 = c->e1222 + a->r * b->e1222 + a->e1222 * b->r + a->e1 * b->e222 
            + a->e2 * b->e122 + a->e12 * b->e22 + a->e22 * b->e12;
  res.e2222 = c->e2222 + a->r * b->e2222 + a->e2222 * b->r + a->e2 * b->e222 
            + a->e22 * b->e22;
  // Order 5;
  res.e11111 = c->e11111 + a->r * b->e11111 + a->e11111 * b->r + a->e1 * b->e1111 
             + a->e11 * b->e111;
  res.e11112 = c->e11112 + a->r * b->e11112 + a->e11112 * b->r + a->e1 * b->e1112 
             + a->e2 * b->e1111 + a->e11 * b->e112 + a->e12 * b->e111;
  res.e11122 = c->e11122 + a->r * b->e11122 + a->e11122 * b->r + a->e1 * b->e1122 
             + a->e2 * b->e1112 + a->e11 * b->e122 + a->e12 * b->e112 
             + a->e22 * b->e111;
  res.e11222 = c->e11222 + a->r * b->e11222 + a->e11222 * b->r + a->e1 * b->e1222 
             + a->e2 * b->e1122 + a->e11 * b->e222 + a->e12 * b->e122 
             + a->e22 * b->e112;
  res.e12222 = c->e12222 + a->r * b->e12222 + a->e12222 * b->r + a->e1 * b->e2222 
             + a->e2 * b->e1222 + a->e12 * b->e222 + a->e22 * b->e122;
  res.e22222 = c->e22222 + a->r * b->e22222 + a->e22222 * b->r + a->e2 * b->e2222 
             + a->e22 * b->e222;

  return res;

}

void onumm2n5_gem_oo_to(  onumm2n5_t* a,  onumm2n5_t* b,  onumm2n5_t* c, onumm2n5_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res->e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  // Order 2;
  res->e11 = c->e11 + a->r * b->e11 + a->e11 * b->r + a->e1 * b->e1;
  res->e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;
  res->e22 = c->e22 + a->r * b->e22 + a->e22 * b->r + a->e2 * b->e2;
  // Order 3;
  res->e111 = c->e111 + a->r * b->e111 + a->e111 * b->r + a->e1 * b->e11;
  res->e112 = c->e112 + a->r * b->e112 + a->e112 * b->r + a->e1 * b->e12 
           + a->e2 * b->e11;
  res->e122 = c->e122 + a->r * b->e122 + a->e122 * b->r + a->e1 * b->e22 
           + a->e2 * b->e12;
  res->e222 = c->e222 + a->r * b->e222 + a->e222 * b->r + a->e2 * b->e22;
  // Order 4;
  res->e1111 = c->e1111 + a->r * b->e1111 + a->e1111 * b->r + a->e1 * b->e111 
            + a->e11 * b->e11;
  res->e1112 = c->e1112 + a->r * b->e1112 + a->e1112 * b->r + a->e1 * b->e112 
            + a->e2 * b->e111 + a->e11 * b->e12 + a->e12 * b->e11;
  res->e1122 = c->e1122 + a->r * b->e1122 + a->e1122 * b->r + a->e1 * b->e122 
            + a->e2 * b->e112 + a->e11 * b->e22 + a->e12 * b->e12 
            + a->e22 * b->e11;
  res->e1222 = c->e1222 + a->r * b->e1222 + a->e1222 * b->r + a->e1 * b->e222 
            + a->e2 * b->e122 + a->e12 * b->e22 + a->e22 * b->e12;
  res->e2222 = c->e2222 + a->r * b->e2222 + a->e2222 * b->r + a->e2 * b->e222 
            + a->e22 * b->e22;
  // Order 5;
  res->e11111 = c->e11111 + a->r * b->e11111 + a->e11111 * b->r + a->e1 * b->e1111 
             + a->e11 * b->e111;
  res->e11112 = c->e11112 + a->r * b->e11112 + a->e11112 * b->r + a->e1 * b->e1112 
             + a->e2 * b->e1111 + a->e11 * b->e112 + a->e12 * b->e111;
  res->e11122 = c->e11122 + a->r * b->e11122 + a->e11122 * b->r + a->e1 * b->e1122 
             + a->e2 * b->e1112 + a->e11 * b->e122 + a->e12 * b->e112 
             + a->e22 * b->e111;
  res->e11222 = c->e11222 + a->r * b->e11222 + a->e11222 * b->r + a->e1 * b->e1222 
             + a->e2 * b->e1122 + a->e11 * b->e222 + a->e12 * b->e122 
             + a->e22 * b->e112;
  res->e12222 = c->e12222 + a->r * b->e12222 + a->e12222 * b->r + a->e1 * b->e2222 
             + a->e2 * b->e1222 + a->e12 * b->e222 + a->e22 * b->e122;
  res->e22222 = c->e22222 + a->r * b->e22222 + a->e22222 * b->r + a->e2 * b->e2222 
             + a->e22 * b->e222;

}

onumm2n5_t onumm2n5_gem_ro(  double a,  onumm2n5_t* b,  onumm2n5_t* c){
  onumm2n5_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  res.e2 = c->e2 + a * b->e2;
  // Order 2;
  res.e11 = c->e11 + a * b->e11;
  res.e12 = c->e12 + a * b->e12;
  res.e22 = c->e22 + a * b->e22;
  // Order 3;
  res.e111 = c->e111 + a * b->e111;
  res.e112 = c->e112 + a * b->e112;
  res.e122 = c->e122 + a * b->e122;
  res.e222 = c->e222 + a * b->e222;
  // Order 4;
  res.e1111 = c->e1111 + a * b->e1111;
  res.e1112 = c->e1112 + a * b->e1112;
  res.e1122 = c->e1122 + a * b->e1122;
  res.e1222 = c->e1222 + a * b->e1222;
  res.e2222 = c->e2222 + a * b->e2222;
  // Order 5;
  res.e11111 = c->e11111 + a * b->e11111;
  res.e11112 = c->e11112 + a * b->e11112;
  res.e11122 = c->e11122 + a * b->e11122;
  res.e11222 = c->e11222 + a * b->e11222;
  res.e12222 = c->e12222 + a * b->e12222;
  res.e22222 = c->e22222 + a * b->e22222;

  return res;

}

void onumm2n5_gem_ro_to(  double a,  onumm2n5_t* b,  onumm2n5_t* c, onumm2n5_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  res->e2 = c->e2 + a * b->e2;
  // Order 2;
  res->e11 = c->e11 + a * b->e11;
  res->e12 = c->e12 + a * b->e12;
  res->e22 = c->e22 + a * b->e22;
  // Order 3;
  res->e111 = c->e111 + a * b->e111;
  res->e112 = c->e112 + a * b->e112;
  res->e122 = c->e122 + a * b->e122;
  res->e222 = c->e222 + a * b->e222;
  // Order 4;
  res->e1111 = c->e1111 + a * b->e1111;
  res->e1112 = c->e1112 + a * b->e1112;
  res->e1122 = c->e1122 + a * b->e1122;
  res->e1222 = c->e1222 + a * b->e1222;
  res->e2222 = c->e2222 + a * b->e2222;
  // Order 5;
  res->e11111 = c->e11111 + a * b->e11111;
  res->e11112 = c->e11112 + a * b->e11112;
  res->e11122 = c->e11122 + a * b->e11122;
  res->e11222 = c->e11222 + a * b->e11222;
  res->e12222 = c->e12222 + a * b->e12222;
  res->e22222 = c->e22222 + a * b->e22222;

}

onumm2n5_t onumm2n5_feval(double* feval_re, onumm2n5_t* x){

  onumm2n5_t res;

  // feval function
  //  Definitions
  double factor=1, coef = 0;
  onumm2n5_t tmp1, tmp2, deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm2n5_set_r_to(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm2n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm2n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm2n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm2n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm2n5_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm2n5_feval_to(double* feval_re, onumm2n5_t* x, onumm2n5_t* res){

  // feval function
  //  Definitions
  double factor=1, coef = 0;
  onumm2n5_t tmp1, tmp2, deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm2n5_set_r_to(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm2n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm2n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm2n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm2n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm2n5_gem_ro_to( coef, &deltax_power, res, res);

}

