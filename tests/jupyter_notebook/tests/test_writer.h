#ifndef TEST_WRITER__H
#define TEST_WRITER__H

//  Dependencies
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>

// Scalar
typedef struct {
  // Real
  double r;
  // Order 1
  double e1;
  double e2;
  // Order 2
  double e11;
  double e12;
  double e22;
  // Order 3
  double e111;
  double e112;
  double e122;
  double e222;
  // Order 4
  double e1111;
  double e1112;
  double e1122;
  double e1222;
  double e2222;
  // Order 5
  double e11111;
  double e11112;
  double e11122;
  double e11222;
  double e12222;
  double e22222;
} onumm2n5_t;

// Array
typedef struct {
  // Data
  onumm2n5_t* p_data;
  uint64_t nrows;
  uint64_t ncols;
  uint64_t size ;
} oarrm2n5_t;

// Gauss Scalar
typedef struct {
  // Data
  onumm2n5_t* p_data;
  uint64_t nip;
} feonumm2n5_t;

// Gauss Array
typedef struct {
  // Data
  oarrm2n5_t* p_data;
  uint64_t nrows;
  uint64_t ncols;
  uint64_t size ;
  uint64_t nip  ;
} feoarrm2n5_t;


onumm2n5_t onumm2n5_create_r(  double lhs);
void onumm2n5_print(  onumm2n5_t lhs);
onumm2n5_t onumm2n5_add_oo(  onumm2n5_t lhs,  onumm2n5_t rhs);
onumm2n5_t onumm2n5_add_ro(  double lhs,  onumm2n5_t rhs);
onumm2n5_t onumm2n5_add_or(  onumm2n5_t lhs,  double rhs);
onumm2n5_t onumm2n5_neg(  onumm2n5_t lhs);
onumm2n5_t onumm2n5_sub_oo(  onumm2n5_t lhs,  onumm2n5_t rhs);
onumm2n5_t onumm2n5_sub_ro(  double lhs,  onumm2n5_t rhs);
onumm2n5_t onumm2n5_sub_or(  onumm2n5_t lhs,  double rhs);
onumm2n5_t onumm2n5_mul_oo(  onumm2n5_t lhs,  onumm2n5_t rhs);
onumm2n5_t onumm2n5_mul_ro(  double lhs,  onumm2n5_t rhs);
onumm2n5_t onumm2n5_mul_or(  onumm2n5_t lhs,  double rhs);

#endif