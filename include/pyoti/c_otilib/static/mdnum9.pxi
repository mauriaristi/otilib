cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/mdnum9/scalar/structures.h
  
  ctypedef struct  mdnum9_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
    coeff_t e6;
    coeff_t e7;
    coeff_t e8;
    coeff_t e9;
    coeff_t e12;
    coeff_t e13;
    coeff_t e23;
    coeff_t e14;
    coeff_t e24;
    coeff_t e34;
    coeff_t e15;
    coeff_t e25;
    coeff_t e35;
    coeff_t e45;
    coeff_t e16;
    coeff_t e26;
    coeff_t e36;
    coeff_t e46;
    coeff_t e56;
    coeff_t e17;
    coeff_t e27;
    coeff_t e37;
    coeff_t e47;
    coeff_t e57;
    coeff_t e67;
    coeff_t e18;
    coeff_t e28;
    coeff_t e38;
    coeff_t e48;
    coeff_t e58;
    coeff_t e68;
    coeff_t e78;
    coeff_t e19;
    coeff_t e29;
    coeff_t e39;
    coeff_t e49;
    coeff_t e59;
    coeff_t e69;
    coeff_t e79;
    coeff_t e89;
    coeff_t e123;
    coeff_t e124;
    coeff_t e134;
    coeff_t e234;
    coeff_t e125;
    coeff_t e135;
    coeff_t e235;
    coeff_t e145;
    coeff_t e245;
    coeff_t e345;
    coeff_t e126;
    coeff_t e136;
    coeff_t e236;
    coeff_t e146;
    coeff_t e246;
    coeff_t e346;
    coeff_t e156;
    coeff_t e256;
    coeff_t e356;
    coeff_t e456;
    coeff_t e127;
    coeff_t e137;
    coeff_t e237;
    coeff_t e147;
    coeff_t e247;
    coeff_t e347;
    coeff_t e157;
    coeff_t e257;
    coeff_t e357;
    coeff_t e457;
    coeff_t e167;
    coeff_t e267;
    coeff_t e367;
    coeff_t e467;
    coeff_t e567;
    coeff_t e128;
    coeff_t e138;
    coeff_t e238;
    coeff_t e148;
    coeff_t e248;
    coeff_t e348;
    coeff_t e158;
    coeff_t e258;
    coeff_t e358;
    coeff_t e458;
    coeff_t e168;
    coeff_t e268;
    coeff_t e368;
    coeff_t e468;
    coeff_t e568;
    coeff_t e178;
    coeff_t e278;
    coeff_t e378;
    coeff_t e478;
    coeff_t e578;
    coeff_t e678;
    coeff_t e129;
    coeff_t e139;
    coeff_t e239;
    coeff_t e149;
    coeff_t e249;
    coeff_t e349;
    coeff_t e159;
    coeff_t e259;
    coeff_t e359;
    coeff_t e459;
    coeff_t e169;
    coeff_t e269;
    coeff_t e369;
    coeff_t e469;
    coeff_t e569;
    coeff_t e179;
    coeff_t e279;
    coeff_t e379;
    coeff_t e479;
    coeff_t e579;
    coeff_t e679;
    coeff_t e189;
    coeff_t e289;
    coeff_t e389;
    coeff_t e489;
    coeff_t e589;
    coeff_t e689;
    coeff_t e789;
    coeff_t e1234;
    coeff_t e1235;
    coeff_t e1245;
    coeff_t e1345;
    coeff_t e2345;
    coeff_t e1236;
    coeff_t e1246;
    coeff_t e1346;
    coeff_t e2346;
    coeff_t e1256;
    coeff_t e1356;
    coeff_t e2356;
    coeff_t e1456;
    coeff_t e2456;
    coeff_t e3456;
    coeff_t e1237;
    coeff_t e1247;
    coeff_t e1347;
    coeff_t e2347;
    coeff_t e1257;
    coeff_t e1357;
    coeff_t e2357;
    coeff_t e1457;
    coeff_t e2457;
    coeff_t e3457;
    coeff_t e1267;
    coeff_t e1367;
    coeff_t e2367;
    coeff_t e1467;
    coeff_t e2467;
    coeff_t e3467;
    coeff_t e1567;
    coeff_t e2567;
    coeff_t e3567;
    coeff_t e4567;
    coeff_t e1238;
    coeff_t e1248;
    coeff_t e1348;
    coeff_t e2348;
    coeff_t e1258;
    coeff_t e1358;
    coeff_t e2358;
    coeff_t e1458;
    coeff_t e2458;
    coeff_t e3458;
    coeff_t e1268;
    coeff_t e1368;
    coeff_t e2368;
    coeff_t e1468;
    coeff_t e2468;
    coeff_t e3468;
    coeff_t e1568;
    coeff_t e2568;
    coeff_t e3568;
    coeff_t e4568;
    coeff_t e1278;
    coeff_t e1378;
    coeff_t e2378;
    coeff_t e1478;
    coeff_t e2478;
    coeff_t e3478;
    coeff_t e1578;
    coeff_t e2578;
    coeff_t e3578;
    coeff_t e4578;
    coeff_t e1678;
    coeff_t e2678;
    coeff_t e3678;
    coeff_t e4678;
    coeff_t e5678;
    coeff_t e1239;
    coeff_t e1249;
    coeff_t e1349;
    coeff_t e2349;
    coeff_t e1259;
    coeff_t e1359;
    coeff_t e2359;
    coeff_t e1459;
    coeff_t e2459;
    coeff_t e3459;
    coeff_t e1269;
    coeff_t e1369;
    coeff_t e2369;
    coeff_t e1469;
    coeff_t e2469;
    coeff_t e3469;
    coeff_t e1569;
    coeff_t e2569;
    coeff_t e3569;
    coeff_t e4569;
    coeff_t e1279;
    coeff_t e1379;
    coeff_t e2379;
    coeff_t e1479;
    coeff_t e2479;
    coeff_t e3479;
    coeff_t e1579;
    coeff_t e2579;
    coeff_t e3579;
    coeff_t e4579;
    coeff_t e1679;
    coeff_t e2679;
    coeff_t e3679;
    coeff_t e4679;
    coeff_t e5679;
    coeff_t e1289;
    coeff_t e1389;
    coeff_t e2389;
    coeff_t e1489;
    coeff_t e2489;
    coeff_t e3489;
    coeff_t e1589;
    coeff_t e2589;
    coeff_t e3589;
    coeff_t e4589;
    coeff_t e1689;
    coeff_t e2689;
    coeff_t e3689;
    coeff_t e4689;
    coeff_t e5689;
    coeff_t e1789;
    coeff_t e2789;
    coeff_t e3789;
    coeff_t e4789;
    coeff_t e5789;
    coeff_t e6789;
    coeff_t e12345;
    coeff_t e12346;
    coeff_t e12356;
    coeff_t e12456;
    coeff_t e13456;
    coeff_t e23456;
    coeff_t e12347;
    coeff_t e12357;
    coeff_t e12457;
    coeff_t e13457;
    coeff_t e23457;
    coeff_t e12367;
    coeff_t e12467;
    coeff_t e13467;
    coeff_t e23467;
    coeff_t e12567;
    coeff_t e13567;
    coeff_t e23567;
    coeff_t e14567;
    coeff_t e24567;
    coeff_t e34567;
    coeff_t e12348;
    coeff_t e12358;
    coeff_t e12458;
    coeff_t e13458;
    coeff_t e23458;
    coeff_t e12368;
    coeff_t e12468;
    coeff_t e13468;
    coeff_t e23468;
    coeff_t e12568;
    coeff_t e13568;
    coeff_t e23568;
    coeff_t e14568;
    coeff_t e24568;
    coeff_t e34568;
    coeff_t e12378;
    coeff_t e12478;
    coeff_t e13478;
    coeff_t e23478;
    coeff_t e12578;
    coeff_t e13578;
    coeff_t e23578;
    coeff_t e14578;
    coeff_t e24578;
    coeff_t e34578;
    coeff_t e12678;
    coeff_t e13678;
    coeff_t e23678;
    coeff_t e14678;
    coeff_t e24678;
    coeff_t e34678;
    coeff_t e15678;
    coeff_t e25678;
    coeff_t e35678;
    coeff_t e45678;
    coeff_t e12349;
    coeff_t e12359;
    coeff_t e12459;
    coeff_t e13459;
    coeff_t e23459;
    coeff_t e12369;
    coeff_t e12469;
    coeff_t e13469;
    coeff_t e23469;
    coeff_t e12569;
    coeff_t e13569;
    coeff_t e23569;
    coeff_t e14569;
    coeff_t e24569;
    coeff_t e34569;
    coeff_t e12379;
    coeff_t e12479;
    coeff_t e13479;
    coeff_t e23479;
    coeff_t e12579;
    coeff_t e13579;
    coeff_t e23579;
    coeff_t e14579;
    coeff_t e24579;
    coeff_t e34579;
    coeff_t e12679;
    coeff_t e13679;
    coeff_t e23679;
    coeff_t e14679;
    coeff_t e24679;
    coeff_t e34679;
    coeff_t e15679;
    coeff_t e25679;
    coeff_t e35679;
    coeff_t e45679;
    coeff_t e12389;
    coeff_t e12489;
    coeff_t e13489;
    coeff_t e23489;
    coeff_t e12589;
    coeff_t e13589;
    coeff_t e23589;
    coeff_t e14589;
    coeff_t e24589;
    coeff_t e34589;
    coeff_t e12689;
    coeff_t e13689;
    coeff_t e23689;
    coeff_t e14689;
    coeff_t e24689;
    coeff_t e34689;
    coeff_t e15689;
    coeff_t e25689;
    coeff_t e35689;
    coeff_t e45689;
    coeff_t e12789;
    coeff_t e13789;
    coeff_t e23789;
    coeff_t e14789;
    coeff_t e24789;
    coeff_t e34789;
    coeff_t e15789;
    coeff_t e25789;
    coeff_t e35789;
    coeff_t e45789;
    coeff_t e16789;
    coeff_t e26789;
    coeff_t e36789;
    coeff_t e46789;
    coeff_t e56789;
    coeff_t e123456;
    coeff_t e123457;
    coeff_t e123467;
    coeff_t e123567;
    coeff_t e124567;
    coeff_t e134567;
    coeff_t e234567;
    coeff_t e123458;
    coeff_t e123468;
    coeff_t e123568;
    coeff_t e124568;
    coeff_t e134568;
    coeff_t e234568;
    coeff_t e123478;
    coeff_t e123578;
    coeff_t e124578;
    coeff_t e134578;
    coeff_t e234578;
    coeff_t e123678;
    coeff_t e124678;
    coeff_t e134678;
    coeff_t e234678;
    coeff_t e125678;
    coeff_t e135678;
    coeff_t e235678;
    coeff_t e145678;
    coeff_t e245678;
    coeff_t e345678;
    coeff_t e123459;
    coeff_t e123469;
    coeff_t e123569;
    coeff_t e124569;
    coeff_t e134569;
    coeff_t e234569;
    coeff_t e123479;
    coeff_t e123579;
    coeff_t e124579;
    coeff_t e134579;
    coeff_t e234579;
    coeff_t e123679;
    coeff_t e124679;
    coeff_t e134679;
    coeff_t e234679;
    coeff_t e125679;
    coeff_t e135679;
    coeff_t e235679;
    coeff_t e145679;
    coeff_t e245679;
    coeff_t e345679;
    coeff_t e123489;
    coeff_t e123589;
    coeff_t e124589;
    coeff_t e134589;
    coeff_t e234589;
    coeff_t e123689;
    coeff_t e124689;
    coeff_t e134689;
    coeff_t e234689;
    coeff_t e125689;
    coeff_t e135689;
    coeff_t e235689;
    coeff_t e145689;
    coeff_t e245689;
    coeff_t e345689;
    coeff_t e123789;
    coeff_t e124789;
    coeff_t e134789;
    coeff_t e234789;
    coeff_t e125789;
    coeff_t e135789;
    coeff_t e235789;
    coeff_t e145789;
    coeff_t e245789;
    coeff_t e345789;
    coeff_t e126789;
    coeff_t e136789;
    coeff_t e236789;
    coeff_t e146789;
    coeff_t e246789;
    coeff_t e346789;
    coeff_t e156789;
    coeff_t e256789;
    coeff_t e356789;
    coeff_t e456789;
    coeff_t e1234567;
    coeff_t e1234568;
    coeff_t e1234578;
    coeff_t e1234678;
    coeff_t e1235678;
    coeff_t e1245678;
    coeff_t e1345678;
    coeff_t e2345678;
    coeff_t e1234569;
    coeff_t e1234579;
    coeff_t e1234679;
    coeff_t e1235679;
    coeff_t e1245679;
    coeff_t e1345679;
    coeff_t e2345679;
    coeff_t e1234589;
    coeff_t e1234689;
    coeff_t e1235689;
    coeff_t e1245689;
    coeff_t e1345689;
    coeff_t e2345689;
    coeff_t e1234789;
    coeff_t e1235789;
    coeff_t e1245789;
    coeff_t e1345789;
    coeff_t e2345789;
    coeff_t e1236789;
    coeff_t e1246789;
    coeff_t e1346789;
    coeff_t e2346789;
    coeff_t e1256789;
    coeff_t e1356789;
    coeff_t e2356789;
    coeff_t e1456789;
    coeff_t e2456789;
    coeff_t e3456789;
    coeff_t e12345678;
    coeff_t e12345679;
    coeff_t e12345689;
    coeff_t e12345789;
    coeff_t e12346789;
    coeff_t e12356789;
    coeff_t e12456789;
    coeff_t e13456789;
    coeff_t e23456789;
    coeff_t e123456789;
  # } mdnum9_t;
  
  
  # From ../../../include/oti/static/mdnum9/array/structures.h
  
  ctypedef struct  mdarr9_t : # {
      mdnum9_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } mdarr9_t;
  
  
  # From ../../../include/oti/static/mdnum9/scalar/gauss/structures.h
  
  ctypedef struct  femdnum9_t: # {
      mdnum9_t*  p_data;
      uint64_t    nip;
  # } femdnum9_t;
  
  
  # From ../../../include/oti/static/mdnum9/array/gauss/structures.h
  
  ctypedef struct  femdarr9_t: # {
      mdarr9_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } femdarr9_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/mdnum9/scalar/functions.h
  
  mdnum9_t mdnum9_atanh(mdnum9_t* num);
  void mdnum9_atanh_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_asinh(mdnum9_t* num);
  void mdnum9_asinh_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_acosh(mdnum9_t* num);
  void mdnum9_acosh_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_tanh(mdnum9_t* num);
  void mdnum9_tanh_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_sqrt(mdnum9_t* num);
  void mdnum9_sqrt_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_cbrt(mdnum9_t* num);
  void mdnum9_cbrt_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_cosh(mdnum9_t* num);
  void mdnum9_cosh_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_sinh(mdnum9_t* num);
  void mdnum9_sinh_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_asin(mdnum9_t* num);
  void mdnum9_asin_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_acos(mdnum9_t* num);
  void mdnum9_acos_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_atan(mdnum9_t* num);
  void mdnum9_atan_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_tan(mdnum9_t* num);
  void mdnum9_tan_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_cos(mdnum9_t* num);
  void mdnum9_cos_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_sin(mdnum9_t* num );
  void mdnum9_sin_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_logb(mdnum9_t* num, double base);
  void mdnum9_logb_to(mdnum9_t* num, double base, mdnum9_t* res);
  mdnum9_t mdnum9_log10(mdnum9_t* num);
  void mdnum9_log10_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_log(mdnum9_t* num);
  void mdnum9_log_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_exp(mdnum9_t* num);
  void mdnum9_exp_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_pow(mdnum9_t* num, double e);
  void mdnum9_pow_to(mdnum9_t* num, coeff_t e, mdnum9_t* res);
  
  
  # From ../../../include/oti/static/mdnum9/scalar/base.h
  
  void mdnum9_set_im_o(mdnum9_t* num, imdir_t idx, ord_t order, mdnum9_t* res);
  void mdnum9_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum9_t* res);
  void mdnum9_set_deriv_o(mdnum9_t* num, imdir_t idx, ord_t order, mdnum9_t* res);
  void mdnum9_extract_im_to( imdir_t idx, ord_t order, mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_extract_im(imdir_t idx, ord_t order, mdnum9_t* num);
  mdnum9_t mdnum9_extract_deriv(imdir_t idx, ord_t order, mdnum9_t* num);
  void mdnum9_extract_deriv_to(imdir_t idx, ord_t order, mdnum9_t* num, mdnum9_t* res);
  void mdnum9_get_im_to_o(imdir_t idx, ord_t order, mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_get_im_o(imdir_t idx, ord_t order, mdnum9_t* num);
  void mdnum9_get_im_to_r(imdir_t idx, ord_t order, mdnum9_t* num, coeff_t* res);
  ord_t mdnum9_get_order(mdnum9_t* lhs);
  mdnum9_t mdnum9_get_deriv_o( imdir_t idx, ord_t order, mdnum9_t* num);
  void mdnum9_get_deriv_to( imdir_t idx, ord_t order, mdnum9_t* num, mdnum9_t* res);
  void mdnum9_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum9_t* res);
  mdnum9_t mdnum9_init();
  ndir_t mdnum9_get_ndir_order(ord_t order, mdnum9_t* num);
  ndir_t mdnum9_get_ndir_total(mdnum9_t* num);
  coeff_t* mdnum9_get_order_address(ord_t order, mdnum9_t* num);
  mdnum9_t mdnum9_create_r(  coeff_t lhs);
  void mdnum9_set_r(  coeff_t lhs, mdnum9_t* res);
  void mdnum9_set_o(  mdnum9_t* lhs, mdnum9_t* res);
  mdnum9_t mdnum9_get_order_im(ord_t order, mdnum9_t* lhs);
  void mdnum9_get_order_im_to(ord_t order, mdnum9_t* lhs, mdnum9_t* res);
  coeff_t mdnum9_get_item(imdir_t idx, ord_t order, mdnum9_t* lhs);
  coeff_t mdnum9_get_deriv(imdir_t idx, ord_t order, mdnum9_t* lhs);
  void mdnum9_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum9_t* x);
  mdnum9_t mdnum9_copy(  mdnum9_t* lhs);
  void mdnum9_copy_to(  mdnum9_t* lhs, mdnum9_t* res);
  mdnum9_t mdnum9_taylor_integrate(coeff_t* deltas,mdnum9_t* lhs);
  void mdnum9_taylor_integrate_to(coeff_t* deltas,mdnum9_t* lhs, mdnum9_t* res);
  mdnum9_t mdnum9_truncate_im(imdir_t idx, ord_t order, mdnum9_t* lhs);
  void mdnum9_truncate_im_to(imdir_t idx, ord_t order, mdnum9_t* lhs, mdnum9_t* res);
  void mdnum9_print(  mdnum9_t* lhs);
  imdir_t mdnum9_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/mdnum9/scalar/utils.h
  
  void mdnum9_get_active_bases(mdnum9_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/mdnum9/scalar/algebra.h
  
  mdnum9_t mdnum9_abs(mdnum9_t* num);
  mdnum9_t mdnum9_div_ro(coeff_t num, mdnum9_t* den);
  mdnum9_t mdnum9_div_oo(mdnum9_t* num, mdnum9_t* den);
  mdnum9_t mdnum9_div_or(mdnum9_t* num, coeff_t val);
  void mdnum9_div_ro_to(coeff_t num, mdnum9_t* den, mdnum9_t* res);
  void mdnum9_div_oo_to(mdnum9_t* num, mdnum9_t* den, mdnum9_t* res);
  void mdnum9_div_or_to(mdnum9_t* num, coeff_t val, mdnum9_t* res);
  void mdnum9_abs_to(mdnum9_t* num, mdnum9_t* res);
  mdnum9_t mdnum9_neg(  mdnum9_t* lhs);
  void mdnum9_neg_to(  mdnum9_t* lhs, mdnum9_t* res);
  mdnum9_t mdnum9_sum_oo(  mdnum9_t* lhs,  mdnum9_t* rhs);
  void mdnum9_sum_oo_to(  mdnum9_t* lhs,  mdnum9_t* rhs, mdnum9_t* res);
  mdnum9_t mdnum9_sum_ro(  coeff_t lhs,  mdnum9_t* rhs);
  void mdnum9_sum_ro_to(  coeff_t lhs,  mdnum9_t* rhs, mdnum9_t* res);
  mdnum9_t mdnum9_sub_oo(  mdnum9_t* lhs,  mdnum9_t* rhs);
  void mdnum9_sub_oo_to(  mdnum9_t* lhs,  mdnum9_t* rhs, mdnum9_t* res);
  mdnum9_t mdnum9_sub_ro(  coeff_t lhs,  mdnum9_t* rhs);
  void mdnum9_sub_ro_to(  coeff_t lhs,  mdnum9_t* rhs, mdnum9_t* res);
  mdnum9_t mdnum9_sub_or(  mdnum9_t* lhs,  coeff_t rhs);
  void mdnum9_sub_or_to(  mdnum9_t* lhs,  coeff_t rhs, mdnum9_t* res);
  mdnum9_t mdnum9_mul_oo(  mdnum9_t* lhs,  mdnum9_t* rhs);
  void mdnum9_mul_oo_to(  mdnum9_t* lhs,  mdnum9_t* rhs, mdnum9_t* res);
  mdnum9_t mdnum9_mul_ro(  coeff_t lhs,  mdnum9_t* rhs);
  void mdnum9_mul_ro_to(  coeff_t lhs,  mdnum9_t* rhs, mdnum9_t* res);
  mdnum9_t mdnum9_trunc_mul_oo(  mdnum9_t* lhs,  mdnum9_t* rhs);
  void mdnum9_trunc_mul_oo_to(  mdnum9_t* lhs,  mdnum9_t* rhs, mdnum9_t* res);
  mdnum9_t mdnum9_gem_oo(  mdnum9_t* a,  mdnum9_t* b,  mdnum9_t* c);
  void mdnum9_gem_oo_to(  mdnum9_t* a,  mdnum9_t* b,  mdnum9_t* c, mdnum9_t* res);
  mdnum9_t mdnum9_gem_ro(  coeff_t a,  mdnum9_t* b,  mdnum9_t* c);
  void mdnum9_gem_ro_to(  coeff_t a,  mdnum9_t* b,  mdnum9_t* c, mdnum9_t* res);
  void mdnum9_trunc_gem_oo_to( ord_t ord_lhs,  mdnum9_t* a,  ord_t ord_rhs,  mdnum9_t* b,  mdnum9_t* c, mdnum9_t* res);
  void mdnum9_trunc_sum_oo_to(ord_t order, mdnum9_t* lhs,mdnum9_t* rhs, mdnum9_t* res);
  void mdnum9_trunc_sub_oo_to(ord_t order, mdnum9_t* lhs,mdnum9_t* rhs, mdnum9_t* res);
  mdnum9_t mdnum9_feval(coeff_t* feval_re, mdnum9_t* x);
  void mdnum9_feval_to(coeff_t* feval_re, mdnum9_t* x, mdnum9_t* res);
  
  
  # From ../../../include/oti/static/mdnum9/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum9/scalar/gauss/functions.h
  
  femdnum9_t femdnum9_atanh(    femdnum9_t* num);
  void     femdnum9_atanh_to( femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_asinh(    femdnum9_t* num);
  void     femdnum9_asinh_to( femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_acosh(    femdnum9_t* num);
  void     femdnum9_acosh_to( femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_tanh(     femdnum9_t* num);
  void     femdnum9_tanh_to(  femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_cosh(     femdnum9_t* num);
  void     femdnum9_cosh_to(  femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_sinh(     femdnum9_t* num);
  void     femdnum9_sinh_to(  femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_asin(     femdnum9_t* num);
  void     femdnum9_asin_to(  femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_acos(     femdnum9_t* num);
  void     femdnum9_acos_to(  femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_atan(     femdnum9_t* num);
  void     femdnum9_atan_to(  femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_tan(      femdnum9_t* num);
  void     femdnum9_tan_to(   femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_cos(      femdnum9_t* num);
  void     femdnum9_cos_to(   femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_sin(      femdnum9_t* num);
  void     femdnum9_sin_to(   femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_logb(     femdnum9_t* num, double base);
  void     femdnum9_logb_to(  femdnum9_t* num, double base, femdnum9_t* res);
  femdnum9_t femdnum9_log10(    femdnum9_t* num);
  void     femdnum9_log10_to( femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_log(      femdnum9_t* num);
  void     femdnum9_log_to(   femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_exp(      femdnum9_t* num);
  void     femdnum9_exp_to(   femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_cbrt(     femdnum9_t* num);
  void     femdnum9_cbrt_to(  femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_sqrt(     femdnum9_t* num);
  void     femdnum9_sqrt_to(  femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_pow(      femdnum9_t* num, double e);
  void     femdnum9_pow_to(   femdnum9_t* num, double e, femdnum9_t* res);
  mdnum9_t femdnum9_integrate(       femdnum9_t* num, femdnum9_t* w);
  void      femdnum9_integrate_to(    femdnum9_t* num, femdnum9_t* w, mdnum9_t* res);
  mdnum9_t femdnum9_integrate_f(     femdnum9_t* num, femdnum9_t* w);
  void      femdnum9_integrate_f_to(  femdnum9_t* num, femdnum9_t* w, mdnum9_t* res);
  mdnum9_t femdnum9_integrate_r(       coeff_t num, femdnum9_t* w);
  void      femdnum9_integrate_r_to(    coeff_t num, femdnum9_t* w, mdnum9_t* res);
  mdnum9_t femdnum9_integrate_o(    mdnum9_t* num, femdnum9_t* w);
  void      femdnum9_integrate_o_to( mdnum9_t* num, femdnum9_t* w, mdnum9_t* res);
  
  
  # From ../../../include/oti/static/mdnum9/scalar/gauss/base.h
  
  void     femdnum9_get_order_im_to( ord_t order, femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_get_order_im(    ord_t order, femdnum9_t* num);
  femdnum9_t femdnum9_get_im(    imdir_t idx, ord_t order, femdnum9_t* num);
  void     femdnum9_get_im_to( imdir_t idx, ord_t order, femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_get_deriv(    imdir_t idx, ord_t order, femdnum9_t* num);
  void     femdnum9_get_deriv_to( imdir_t idx, ord_t order, femdnum9_t* num, femdnum9_t* res);
  void femdnum9_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum9_t* num);
  void femdnum9_set_im_o( mdnum9_t* val, imdir_t idx, ord_t order, femdnum9_t* num);
  void femdnum9_set_im_f(  femdnum9_t* val, imdir_t idx, ord_t order, femdnum9_t* num);
  void femdnum9_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum9_t* num);
  void femdnum9_set_deriv_o( mdnum9_t* val, imdir_t idx, ord_t order, femdnum9_t* num);
  void femdnum9_set_deriv_f(  femdnum9_t* val, imdir_t idx, ord_t order, femdnum9_t* num);
  femdnum9_t femdnum9_extract_im(    imdir_t idx, ord_t order, femdnum9_t* num);
  void     femdnum9_extract_im_to( imdir_t idx, ord_t order, femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_extract_deriv(    imdir_t idx, ord_t order, femdnum9_t* num);
  void     femdnum9_extract_deriv_to( imdir_t idx, ord_t order, femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_truncate_im(    imdir_t idx, ord_t order, femdnum9_t* num);
  void     femdnum9_truncate_im_to( imdir_t idx, ord_t order, femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_copy(    femdnum9_t* src);
  void     femdnum9_copy_to( femdnum9_t* src, femdnum9_t* dst);
  void femdnum9_set_r(    coeff_t num, femdnum9_t* res);
  void femdnum9_set_o( mdnum9_t* num, femdnum9_t* res);
  void femdnum9_set_f(  femdnum9_t* num, femdnum9_t* res);
  void femdnum9_set_item_k_r(   coeff_t  num, uint64_t k, femdnum9_t* res);
  void femdnum9_set_item_k_o( mdnum9_t* num, uint64_t k, femdnum9_t* res);
  mdnum9_t femdnum9_get_item_k(   femdnum9_t* num, uint64_t k);
  void      femdnum9_get_item_k_to(femdnum9_t* num, uint64_t k, mdnum9_t* res);
  femdnum9_t femdnum9_zeros(uint64_t nIntPts);
  femdnum9_t femdnum9_createEmpty(uint64_t nIntPts);
  femdnum9_t femdnum9_empty_like(femdnum9_t* arr);
  void femdnum9_free(femdnum9_t* num);
  ord_t femdnum9_get_order( femdnum9_t* num );
  femdnum9_t femdnum9_init();
  
  
  # From ../../../include/oti/static/mdnum9/scalar/gauss/utils.h
  
  void femdnum9_dimCheck(femdnum9_t* arr1,femdnum9_t* arr2);
  void femdnum9_get_active_bases(femdnum9_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum9/scalar/gauss/algebra.h
  
  femdnum9_t femdnum9_neg(   femdnum9_t* num);
  void     femdnum9_neg_to(femdnum9_t* num, femdnum9_t* res);
  femdnum9_t femdnum9_sum_ff(   femdnum9_t* lhs, femdnum9_t* rhs);
  void     femdnum9_sum_ff_to(femdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_sum_of(   mdnum9_t* lhs, femdnum9_t* rhs);
  void     femdnum9_sum_of_to(mdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_sum_rf(   coeff_t lhs, femdnum9_t* rhs);
  void     femdnum9_sum_rf_to(coeff_t lhs, femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_sub_ff(     femdnum9_t* lhs,  femdnum9_t* rhs);
  void     femdnum9_sub_ff_to(  femdnum9_t* lhs,  femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_sub_of(    mdnum9_t* lhs,  femdnum9_t* rhs);
  void     femdnum9_sub_of_to( mdnum9_t* lhs,  femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_sub_fo(     femdnum9_t* lhs, mdnum9_t* rhs);
  void     femdnum9_sub_fo_to(  femdnum9_t* lhs, mdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_sub_rf(       coeff_t lhs,  femdnum9_t* rhs);
  void     femdnum9_sub_rf_to(    coeff_t lhs,  femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_sub_fr(     femdnum9_t* lhs,    coeff_t rhs);
  void     femdnum9_sub_fr_to(  femdnum9_t* lhs,    coeff_t rhs, femdnum9_t* res);
  femdnum9_t femdnum9_mul_ff(   femdnum9_t* lhs, femdnum9_t* rhs);
  void     femdnum9_mul_ff_to(femdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_mul_of(   mdnum9_t* lhs, femdnum9_t* rhs);
  void     femdnum9_mul_of_to(mdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_mul_rf(   coeff_t lhs, femdnum9_t* rhs);
  void     femdnum9_mul_rf_to(coeff_t lhs, femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_div_ff(     femdnum9_t* lhs,  femdnum9_t* rhs);
  void     femdnum9_div_ff_to(  femdnum9_t* lhs,  femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_div_of(    mdnum9_t* lhs,  femdnum9_t* rhs);
  void     femdnum9_div_of_to( mdnum9_t* lhs,  femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_div_fo(     femdnum9_t* lhs, mdnum9_t* rhs);
  void     femdnum9_div_fo_to(  femdnum9_t* lhs, mdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_div_rf(       coeff_t lhs,  femdnum9_t* rhs);
  void     femdnum9_div_rf_to(    coeff_t lhs,  femdnum9_t* rhs, femdnum9_t* res);
  femdnum9_t femdnum9_div_fr(     femdnum9_t* lhs,    coeff_t rhs);
  void     femdnum9_div_fr_to(  femdnum9_t* lhs,    coeff_t rhs, femdnum9_t* res);
  
  
  # From ../../../include/oti/static/mdnum9/array/functions.h
  
  mdarr9_t mdarr9_atanh(   mdarr9_t* arr);
  void    mdarr9_atanh_to(mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_asinh(   mdarr9_t* arr);
  void    mdarr9_asinh_to(mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_acosh(   mdarr9_t* arr);
  void    mdarr9_acosh_to(mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_tanh(    mdarr9_t* arr);
  void    mdarr9_tanh_to( mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_cbrt(    mdarr9_t* arr);
  void    mdarr9_cbrt_to( mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_sqrt(    mdarr9_t* arr);
  void    mdarr9_sqrt_to( mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_cosh(    mdarr9_t* arr);
  void    mdarr9_cosh_to( mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_sinh(    mdarr9_t* arr);
  void    mdarr9_sinh_to( mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_asin(    mdarr9_t* arr);
  void    mdarr9_asin_to( mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_acos(    mdarr9_t* arr);
  void    mdarr9_acos_to( mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_atan(    mdarr9_t* arr);
  void    mdarr9_atan_to( mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_tan(     mdarr9_t* arr);
  void    mdarr9_tan_to(  mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_cos(     mdarr9_t* arr);
  void    mdarr9_cos_to(  mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_sin(     mdarr9_t* arr);
  void    mdarr9_sin_to(  mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_logb(    mdarr9_t* arr, double base);
  void    mdarr9_logb_to( mdarr9_t* arr, double base, mdarr9_t* res);
  mdarr9_t mdarr9_log10(   mdarr9_t* arr);
  void    mdarr9_log10_to(mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_log(     mdarr9_t* arr);
  void    mdarr9_log_to(  mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_exp(     mdarr9_t* arr);
  void    mdarr9_exp_to(  mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_pow(     mdarr9_t* arr, double e);
  void    mdarr9_pow_to(  mdarr9_t* arr, double e, mdarr9_t* res);
  
  
  # From ../../../include/oti/static/mdnum9/array/algebra_elementwise.h
  
  mdarr9_t mdarr9_neg(mdarr9_t* arr);
  void mdarr9_neg_to(mdarr9_t* rhs, mdarr9_t* res);
  mdarr9_t mdarr9_sum_OO(mdarr9_t*   lhs, mdarr9_t* rhs);
  mdarr9_t mdarr9_sum_RO(darr_t*    lhs, mdarr9_t* rhs);
  mdarr9_t mdarr9_sum_oO(mdnum9_t* lhs, mdarr9_t* rhs);
  mdarr9_t mdarr9_sum_rO(coeff_t    lhs, mdarr9_t* rhs);
  void mdarr9_sum_OO_to(mdarr9_t*   lhs, mdarr9_t* rhs, mdarr9_t* res);
  void mdarr9_sum_RO_to(darr_t*    lhs, mdarr9_t* rhs, mdarr9_t* res);
  void mdarr9_sum_oO_to(mdnum9_t* lhs, mdarr9_t* rhs, mdarr9_t* res);
  void mdarr9_sum_rO_to(coeff_t    lhs, mdarr9_t* rhs, mdarr9_t* res);
  void mdarr9_trunc_sum_OO_to(ord_t order, mdarr9_t* arr1, mdarr9_t* arr2, mdarr9_t* res);
  mdarr9_t mdarr9_sub_OO(mdarr9_t*   lhs, mdarr9_t*   rhs);
  mdarr9_t mdarr9_sub_RO(darr_t*    lhs, mdarr9_t*   rhs);
  mdarr9_t mdarr9_sub_OR(mdarr9_t*   lhs, darr_t*    rhs);
  mdarr9_t mdarr9_sub_oO(mdnum9_t* lhs, mdarr9_t*   rhs);
  mdarr9_t mdarr9_sub_Oo(mdarr9_t*   lhs, mdnum9_t* rhs);
  mdarr9_t mdarr9_sub_rO(coeff_t    lhs, mdarr9_t*   rhs);
  mdarr9_t mdarr9_sub_Or(mdarr9_t*   lhs, coeff_t    rhs);
  void mdarr9_sub_OO_to( mdarr9_t*   lhs, mdarr9_t*   rhs, mdarr9_t* res);
  void mdarr9_sub_RO_to( darr_t*    lhs, mdarr9_t*   rhs, mdarr9_t* res);
  void mdarr9_sub_OR_to( mdarr9_t*   lhs, darr_t*    rhs, mdarr9_t* res);
  void mdarr9_sub_oO_to( mdnum9_t* lhs, mdarr9_t*   rhs, mdarr9_t* res);
  void mdarr9_sub_Oo_to( mdarr9_t*   lhs, mdnum9_t* rhs, mdarr9_t* res);
  void mdarr9_sub_rO_to( coeff_t    lhs, mdarr9_t*   rhs, mdarr9_t* res);
  void mdarr9_sub_Or_to( mdarr9_t*   lhs, coeff_t    rhs, mdarr9_t* res);
  void mdarr9_trunc_sub_OO_to(ord_t order, mdarr9_t* arr1, mdarr9_t* arr2, mdarr9_t* res);
  mdarr9_t mdarr9_mul_OO(mdarr9_t*   lhs, mdarr9_t* rhs);
  mdarr9_t mdarr9_mul_RO(darr_t*    lhs, mdarr9_t* rhs);
  mdarr9_t mdarr9_mul_oO(mdnum9_t* lhs, mdarr9_t* rhs);
  mdarr9_t mdarr9_mul_rO(coeff_t    lhs, mdarr9_t* rhs);
  void mdarr9_mul_OO_to(mdarr9_t*   lhs, mdarr9_t* rhs, mdarr9_t* res);
  void mdarr9_mul_RO_to(darr_t*    lhs, mdarr9_t* rhs, mdarr9_t* res);
  void mdarr9_mul_oO_to(mdnum9_t* lhs, mdarr9_t* rhs, mdarr9_t* res);
  void mdarr9_mul_rO_to(coeff_t    lhs, mdarr9_t* rhs, mdarr9_t* res);
  void mdarr9_gem_OO_to(  mdarr9_t* arr1, mdarr9_t* arr2, mdarr9_t* arr3, mdarr9_t* res);
  void mdarr9_gem_oO_to(mdnum9_t* arr1, mdarr9_t* arr2, mdarr9_t* arr3, mdarr9_t* res);
  mdarr9_t mdarr9_div_OO(mdarr9_t*   lhs, mdarr9_t*   rhs);
  mdarr9_t mdarr9_div_OR(mdarr9_t*   lhs, darr_t*    rhs);
  mdarr9_t mdarr9_div_RO(darr_t*    lhs, mdarr9_t*   rhs);
  mdarr9_t mdarr9_div_oO(mdnum9_t* lhs, mdarr9_t*   rhs);
  mdarr9_t mdarr9_div_Oo(mdarr9_t*   lhs, mdnum9_t* rhs);
  mdarr9_t mdarr9_div_rO(coeff_t    lhs, mdarr9_t*   rhs);
  mdarr9_t mdarr9_div_Or(mdarr9_t*   lhs, coeff_t    rhs);
  void mdarr9_div_OO_to(mdarr9_t*   lhs, mdarr9_t*   rhs, mdarr9_t* res);
  void mdarr9_div_RO_to(darr_t*    lhs, mdarr9_t*   rhs, mdarr9_t* res);
  void mdarr9_div_OR_to(mdarr9_t*   lhs, darr_t*    rhs, mdarr9_t* res);
  void mdarr9_div_oO_to(mdnum9_t* lhs, mdarr9_t*   rhs, mdarr9_t* res);
  void mdarr9_div_Oo_to(mdarr9_t*   lhs, mdnum9_t* rhs, mdarr9_t* res);
  void mdarr9_div_rO_to(coeff_t    lhs, mdarr9_t*   rhs, mdarr9_t* res);
  void mdarr9_div_Or_to(mdarr9_t*   lhs, coeff_t    rhs, mdarr9_t* res);
  
  
  # From ../../../include/oti/static/mdnum9/array/base.h
  
  void    mdarr9_taylor_integrate_to( coeff_t* deltas, mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_taylor_integrate(    coeff_t* deltas, mdarr9_t* arr);
  void    mdarr9_get_order_im_to( ord_t order, mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_get_order_im(    ord_t order, mdarr9_t* arr);
  void mdarr9_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr9_t* res);
  void mdarr9_set_slice_O( mdarr9_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr9_t* res);
  void mdarr9_set_slice_o( mdnum9_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr9_t* res);
  mdarr9_t mdarr9_get_slice( mdarr9_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void mdarr9_get_slice_to( mdarr9_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr9_t* res);
  mdarr9_t mdarr9_truncate_im(    imdir_t idx, ord_t order, mdarr9_t* arr);
  void    mdarr9_truncate_im_to( imdir_t idx, ord_t order, mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_extract_im(   imdir_t idx, ord_t order, mdarr9_t* arr);
  void    mdarr9_extract_im_to(imdir_t idx, ord_t order, mdarr9_t* arr, mdarr9_t* res);
  darr_t  mdarr9_get_deriv(    imdir_t idx, ord_t order, mdarr9_t* arr);
  void    mdarr9_get_deriv_to( imdir_t idx, ord_t order, mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_get_deriv_o(  imdir_t idx, ord_t order, mdarr9_t* arr);
  mdarr9_t mdarr9_extract_deriv(    imdir_t idx, ord_t order, mdarr9_t* arr);
  void    mdarr9_extract_deriv_to( imdir_t idx, ord_t order, mdarr9_t* arr, mdarr9_t* res);
  darr_t  mdarr9_get_im(   imdir_t idx, ord_t order, mdarr9_t* arr);
  mdarr9_t mdarr9_get_im_o( imdir_t idx, ord_t order, mdarr9_t* arr);
  void    mdarr9_get_im_to(imdir_t idx, ord_t order, mdarr9_t* arr, mdarr9_t* res);
  void    mdarr9_copy_to(mdarr9_t* arr, mdarr9_t* res);
  mdarr9_t mdarr9_copy(mdarr9_t* arr);
  void mdarr9_set_all_r( coeff_t num, mdarr9_t* arr);
  void mdarr9_set_item_i_r( coeff_t num, uint64_t i, mdarr9_t* arr);
  void mdarr9_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, mdarr9_t* arr);
  void mdarr9_set_r(   coeff_t  num,   mdarr9_t* arr);
  void mdarr9_set_o( mdnum9_t* num,   mdarr9_t* arr);
  void mdarr9_set_O(   mdarr9_t* arrin, mdarr9_t* arr);
  void mdarr9_set_all_o( mdnum9_t* src, mdarr9_t* arr);
  void mdarr9_set_item_i_o( mdnum9_t* num, uint64_t i, mdarr9_t* arr);
  void mdarr9_set_item_ij_o( mdnum9_t* num, uint64_t i, uint64_t j, mdarr9_t* arr);
  mdnum9_t mdarr9_get_item_i(    mdarr9_t* arr, uint64_t i);
  void      mdarr9_get_item_i_to( mdarr9_t* arr, uint64_t i,             mdnum9_t* res);
  mdnum9_t mdarr9_get_item_ij(   mdarr9_t* arr, uint64_t i, uint64_t j);
  void      mdarr9_get_item_ij_to(mdarr9_t* arr, uint64_t i, uint64_t j, mdnum9_t* res);
  mdarr9_t mdarr9_init();
  void mdarr9_free(mdarr9_t* arr);
  mdarr9_t mdarr9_empty_like(mdarr9_t* arr);
  mdarr9_t mdarr9_eye(uint64_t nrows);
  mdarr9_t mdarr9_ones(uint64_t nrows, uint64_t ncols);
  mdarr9_t mdarr9_zeros(uint64_t nrows, uint64_t ncols);
  mdarr9_t mdarr9_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/mdnum9/array/utils.h
  
  void mdarr9_dimCheck_OO_elementwise(mdarr9_t* arr1, mdarr9_t* arr2, mdarr9_t* res);
  void mdarr9_dimCheck_RO_elementwise(darr_t*  arr1, mdarr9_t* arr2, mdarr9_t* res);
  void mdarr9_dimCheck_OO_matmul(mdarr9_t* arr1, mdarr9_t* arr2, mdarr9_t* res);
  void mdarr9_dimCheck_RO_matmul(darr_t*  arr1, mdarr9_t* arr2, mdarr9_t* res);
  void mdarr9_dimCheck_OR_matmul(mdarr9_t* arr1, darr_t*  arr2, mdarr9_t* res);
  void mdarr9_dimCheck_O_squareness(mdarr9_t* arr1, mdarr9_t* res);
  void mdarr9_dimCheck_OO_samesize(mdarr9_t* arr1, mdarr9_t* res);
  void mdarr9_dimCheck_RO_samesize(darr_t* arr1, mdarr9_t* res);
  ord_t mdarr9_get_order(mdarr9_t* arr);
  void mdarr9_get_active_bases(mdarr9_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum9/array/algebra_matops.h
  
  mdnum9_t mdarr9_dotproduct_OO(    mdarr9_t* lhs, mdarr9_t* rhs);
  void      mdarr9_dotproduct_OO_to( mdarr9_t* lhs, mdarr9_t* rhs, mdnum9_t* res);
  mdnum9_t mdarr9_dotproduct_RO(     darr_t* lhs, mdarr9_t* rhs);
  void      mdarr9_dotproduct_RO_to(  darr_t* lhs, mdarr9_t* rhs, mdnum9_t* res);
  mdarr9_t mdarr9_matmul_OO(    mdarr9_t* lhs, mdarr9_t* rhs);
  mdarr9_t mdarr9_matmul_OR(    mdarr9_t* lhs,  darr_t* rhs);
  mdarr9_t mdarr9_matmul_RO(     darr_t* lhs, mdarr9_t* rhs);
  void    mdarr9_matmul_OO_to( mdarr9_t* lhs, mdarr9_t* rhs, mdarr9_t* res);
  void    mdarr9_matmul_OR_to( mdarr9_t* lhs,  darr_t* rhs, mdarr9_t* res);
  void    mdarr9_matmul_RO_to(  darr_t* lhs, mdarr9_t* rhs, mdarr9_t* res);
  mdarr9_t mdarr9_transpose(    mdarr9_t* arr1);
  void    mdarr9_transpose_to( mdarr9_t* arr1, mdarr9_t* res);
  mdarr9_t mdarr9_invert(    mdarr9_t* arr1);
  void    mdarr9_invert_to( mdarr9_t* arr1, mdarr9_t* res);
  mdnum9_t mdarr9_det(    mdarr9_t* arr1);
  void      mdarr9_det_to( mdarr9_t* arr1, mdnum9_t* res);
  mdnum9_t mdarr9_norm(    mdarr9_t* arr1);
  void      mdarr9_norm_to( mdarr9_t* arr1,  mdnum9_t* res);
  mdnum9_t mdarr9_pnorm(    mdarr9_t* arr1, coeff_t p);
  void      mdarr9_pnorm_to( mdarr9_t* arr1, coeff_t p, mdnum9_t* res);
  
  
  # From ../../../include/oti/static/mdnum9/array/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum9/array/gauss/functions.h
  
  femdarr9_t femdarr9_atanh(    femdarr9_t* arr);
  void      femdarr9_atanh_to( femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_asinh(    femdarr9_t* arr);
  void      femdarr9_asinh_to( femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_acosh(    femdarr9_t* arr);
  void      femdarr9_acosh_to( femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_tanh(     femdarr9_t* arr);
  void      femdarr9_tanh_to(  femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_sinh(     femdarr9_t* arr);
  void      femdarr9_sinh_to(  femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_cosh(     femdarr9_t* arr);
  void      femdarr9_cosh_to(  femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_atan(     femdarr9_t* arr);
  void      femdarr9_atan_to(  femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_asin(     femdarr9_t* arr);
  void      femdarr9_asin_to(  femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_acos(     femdarr9_t* arr);
  void      femdarr9_acos_to(  femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_tan(      femdarr9_t* arr);
  void      femdarr9_tan_to(   femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_sin(      femdarr9_t* arr);
  void      femdarr9_sin_to(   femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_cos(      femdarr9_t* arr);
  void      femdarr9_cos_to(   femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_logb(     femdarr9_t* arr, double base);
  void      femdarr9_logb_to(  femdarr9_t* arr, double base, femdarr9_t* res);
  femdarr9_t femdarr9_log10(    femdarr9_t* arr);
  void      femdarr9_log10_to( femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_log(      femdarr9_t* arr);
  void      femdarr9_log_to(   femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_exp(      femdarr9_t* arr);
  void      femdarr9_exp_to(   femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_cbrt(     femdarr9_t* arr);
  void      femdarr9_cbrt_to(  femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_sqrt(     femdarr9_t* arr);
  void      femdarr9_sqrt_to(  femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_pow(      femdarr9_t* arr, double e);
  void      femdarr9_pow_to(   femdarr9_t* arr, double e, femdarr9_t* res);
  
  
  # From ../../../include/oti/static/mdnum9/array/gauss/base.h
  
  void      femdarr9_get_order_im_to( ord_t order, femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_get_order_im(    ord_t order, femdarr9_t* arr);
  femdarr9_t femdarr9_get_deriv(   imdir_t idx, ord_t order, femdarr9_t* arr);
  void      femdarr9_get_deriv_to(imdir_t idx, ord_t order, femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_get_im(      imdir_t idx, ord_t order, femdarr9_t* arr);
  void      femdarr9_get_im_to(   imdir_t idx, ord_t order, femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_truncate_im(   imdir_t idx, ord_t order, femdarr9_t* arr);
  void      femdarr9_truncate_im_to(imdir_t idx, ord_t order, femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_copy(   femdarr9_t* src);
  void      femdarr9_copy_to(femdarr9_t* src, femdarr9_t* res);
  femdarr9_t femdarr9_get_im(    imdir_t idx, ord_t order, femdarr9_t* arr);
  void      femdarr9_get_im_to( imdir_t idx, ord_t order, femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_get_deriv(    imdir_t idx, ord_t order, femdarr9_t* arr);
  void      femdarr9_get_deriv_to( imdir_t idx, ord_t order, femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_extract_im(    imdir_t idx, ord_t order, femdarr9_t* arr);
  void      femdarr9_extract_im_to( imdir_t idx, ord_t order, femdarr9_t* arr,  femdarr9_t* res);
  femdarr9_t femdarr9_extract_deriv(    imdir_t idx, ord_t order, femdarr9_t* arr);
  void      femdarr9_extract_deriv_to( imdir_t idx, ord_t order, femdarr9_t* arr, femdarr9_t* res);
  mdarr9_t   femdarr9_get_item_k(  femdarr9_t* arr, uint64_t k);
  femdnum9_t  femdarr9_get_item_ij( femdarr9_t* arr, uint64_t i, uint64_t j);
  mdnum9_t femdarr9_get_item_ijk(femdarr9_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void femdarr9_get_item_ij_to(  femdarr9_t* arr, uint64_t i, uint64_t j,
                                 femdnum9_t* res);
  void femdarr9_get_item_k_to(   femdarr9_t* arr, uint64_t k,
                                  mdarr9_t* res);
  void femdarr9_get_item_ijk_to( femdarr9_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                mdnum9_t* res);
  femdarr9_t femdarr9_get_slice(femdarr9_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      femdarr9_get_slice_to(femdarr9_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr9_t* res);
  void femdarr9_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              femdarr9_t* res);
  void femdarr9_set_item_ij_o(  mdnum9_t* elm, uint64_t i, uint64_t j,
                               femdarr9_t* res);
  void femdarr9_set_item_ij_f(  femdnum9_t* elm, uint64_t i, uint64_t j,
                              femdarr9_t* res);
  void femdarr9_set_item_k_r(    coeff_t  elm, uint64_t k,
                              femdarr9_t* res);
  void femdarr9_set_item_k_o(  mdnum9_t* elm, uint64_t k,
                              femdarr9_t* res);
  void femdarr9_set_item_k_R(    mdarr9_t* elm, uint64_t k,
                            femdarr9_t* res);
  void femdarr9_set_item_k_O(    mdarr9_t* elm, uint64_t k,
                            femdarr9_t* res);
  void femdarr9_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr9_t* res);
  void femdarr9_set_item_ijk_o( mdnum9_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr9_t* res);
  void femdarr9_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr9_t* res);
  void femdarr9_set_slice_o( mdnum9_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr9_t* res);
  void femdarr9_set_slice_f( femdnum9_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr9_t* res);
  void femdarr9_set_slice_O( mdarr9_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr9_t* res);
  void femdarr9_set_slice_F( femdarr9_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr9_t* res);
  void femdarr9_set_all_o( mdnum9_t* num, femdarr9_t* arr );
  void femdarr9_set_all_r(   coeff_t  num, femdarr9_t* arr );
  void femdarr9_set_all_f(  femdnum9_t* num, femdarr9_t* arr );
  void femdarr9_set_r(    coeff_t src, femdarr9_t* res );
  void femdarr9_set_o( mdnum9_t* src, femdarr9_t* res );
  void femdarr9_set_f(  femdnum9_t* src, femdarr9_t* res );
  void femdarr9_set_R(    darr_t* src, femdarr9_t* res );
  void femdarr9_set_O(   mdarr9_t* src, femdarr9_t* res );
  void femdarr9_set_F( femdarr9_t* src, femdarr9_t* res );
  femdarr9_t femdarr9_eye( uint64_t size,  uint64_t nip);
  femdarr9_t femdarr9_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  femdarr9_t femdarr9_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  femdarr9_t femdarr9_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void femdarr9_free(femdarr9_t* arr);
  femdarr9_t femdarr9_init();
  ord_t femdarr9_get_order(femdarr9_t* arr);
  
  
  # From ../../../include/oti/static/mdnum9/array/gauss/utils.h
  
  void femdarr9_dimCheck_FF_samesize(femdarr9_t* arr1, femdarr9_t* arr2, femdnum9_t* res);
  void femdarr9_dimCheck_OF_samesize(  mdarr9_t* arr1, femdarr9_t* arr2, femdnum9_t* res);
  void femdarr9_dimCheck_RF_samesize(   darr_t* arr1, femdarr9_t* arr2, femdnum9_t* res);
  void femdarr9_dimCheck_FF_elementwise(femdarr9_t* arr1, femdarr9_t* arr2, femdarr9_t* res);
  void femdarr9_dimCheck_OF_elementwise(  mdarr9_t* arr1, femdarr9_t* arr2, femdarr9_t* res);
  void femdarr9_dimCheck_RF_elementwise(   darr_t* arr1, femdarr9_t* arr2, femdarr9_t* res);
  void femdarr9_dimCheck_fF_elementwise( femdnum9_t* num1, femdarr9_t* arr2, femdarr9_t* res);
  void femdarr9_dimCheck_Ff_elementwise(femdarr9_t* arr1,  femdnum9_t* num2, femdarr9_t* res);
  void femdarr9_dimCheck_FF_matmul( femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  void femdarr9_dimCheck_OF_matmul(   mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  void femdarr9_dimCheck_RF_matmul(    darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  void femdarr9_dimCheck_FO_matmul( femdarr9_t* lhs,   mdarr9_t* rhs, femdarr9_t* res);
  void femdarr9_dimCheck_FR_matmul( femdarr9_t* lhs,    darr_t* rhs, femdarr9_t* res);
  void femdarr9_dimCheck_F_squareness( femdarr9_t* arr1, femdarr9_t* res);
  void femdarr9_dimCheck_F_transpose( femdarr9_t* arr1, femdarr9_t* res);
  void femdarr9_dimCheck_FfO_integrate(femdarr9_t* arr, femdnum9_t* num,mdarr9_t* res);
  void femdarr9_get_active_bases(femdarr9_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum9/array/gauss/algebra.h
  
  femdarr9_t femdarr9_neg(    femdarr9_t* arr);
  void      femdarr9_neg_to( femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t femdarr9_sum_FF(   femdarr9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_sum_FF_to(femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sum_fF(    femdnum9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_sum_fF_to( femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sum_OF(     mdarr9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_sum_OF_to(  mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sum_RF(      darr_t* lhs, femdarr9_t* rhs);
  void      femdarr9_sum_RF_to(   darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sum_oF(   mdnum9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_sum_oF_to(mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sum_rF(     coeff_t  lhs, femdarr9_t* rhs);
  void      femdarr9_sum_rF_to(  coeff_t  lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_FF(    femdarr9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_sub_FF_to( femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_fF(    femdnum9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_sub_fF_to( femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_Ff(    femdarr9_t* lhs, femdnum9_t* rhs);
  void      femdarr9_sub_Ff_to( femdarr9_t* lhs, femdnum9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_OF(      mdarr9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_sub_OF_to(   mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_FO(    femdarr9_t* lhs,   mdarr9_t* rhs);
  void      femdarr9_sub_FO_to( femdarr9_t* lhs,   mdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_RF(       darr_t* lhs, femdarr9_t* rhs);
  void      femdarr9_sub_RF_to(    darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_FR(    femdarr9_t* lhs,    darr_t* rhs);
  void      femdarr9_sub_FR_to( femdarr9_t* lhs,    darr_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_oF(    mdnum9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_sub_oF_to( mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_Fo(    femdarr9_t* lhs, mdnum9_t* rhs);
  void      femdarr9_sub_Fo_to( femdarr9_t* lhs, mdnum9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_rF(      coeff_t  lhs, femdarr9_t* rhs);
  void      femdarr9_sub_rF_to(    coeff_t lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_sub_Fr(    femdarr9_t* lhs,   coeff_t  rhs);
  void      femdarr9_sub_Fr_to( femdarr9_t* lhs,   coeff_t  rhs, femdarr9_t* res);
  femdarr9_t femdarr9_mul_FF(   femdarr9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_mul_FF_to(femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_mul_fF(    femdnum9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_mul_fF_to( femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_mul_OF(     mdarr9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_mul_OF_to(  mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_mul_RF(      darr_t* lhs, femdarr9_t* rhs);
  void      femdarr9_mul_RF_to(   darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_mul_oF(   mdnum9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_mul_oF_to(mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_mul_rF(     coeff_t  lhs, femdarr9_t* rhs);
  void      femdarr9_mul_rF_to(  coeff_t  lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_FF(    femdarr9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_div_FF_to( femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_fF(     femdnum9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_div_fF_to(  femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_Ff(    femdarr9_t* lhs,  femdnum9_t* rhs);
  void      femdarr9_div_Ff_to( femdarr9_t* lhs,  femdnum9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_OF(      mdarr9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_div_OF_to(   mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_FO(    femdarr9_t* lhs,   mdarr9_t* rhs);
  void      femdarr9_div_FO_to( femdarr9_t* lhs,   mdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_RF(       darr_t* lhs, femdarr9_t* rhs);
  void      femdarr9_div_RF_to(    darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_FR(    femdarr9_t* lhs,    darr_t* rhs);
  void      femdarr9_div_FR_to( femdarr9_t* lhs,    darr_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_oF(    mdnum9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_div_oF_to( mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_Fo(    femdarr9_t* lhs, mdnum9_t* rhs);
  void      femdarr9_div_Fo_to( femdarr9_t* lhs, mdnum9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_rF(      coeff_t  lhs, femdarr9_t* rhs);
  void      femdarr9_div_rF_to(    coeff_t lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_div_Fr(    femdarr9_t* lhs,   coeff_t  rhs);
  void      femdarr9_div_Fr_to( femdarr9_t* lhs,   coeff_t  rhs, femdarr9_t* res);
  mdarr9_t femdarr9_integrate(    femdarr9_t* arr, femdnum9_t* w);
  void    femdarr9_integrate_to( femdarr9_t* arr, femdnum9_t* w, mdarr9_t* res);
  femdnum9_t femdarr9_dotproduct_FF(    femdarr9_t* lhs, femdarr9_t* rhs);
  void     femdarr9_dotproduct_FF_to( femdarr9_t* lhs, femdarr9_t* rhs, femdnum9_t* res);
  femdnum9_t femdarr9_dotproduct_OF(      mdarr9_t* lhs, femdarr9_t* rhs);
  void     femdarr9_dotproduct_OF_to(   mdarr9_t* lhs, femdarr9_t* rhs, femdnum9_t* res);
  femdnum9_t femdarr9_dotproduct_RF(       darr_t* lhs, femdarr9_t* rhs);
  void     femdarr9_dotproduct_RF_to(    darr_t* lhs, femdarr9_t* rhs, femdnum9_t* res);
  femdarr9_t femdarr9_matmul_FF(    femdarr9_t* lhs, femdarr9_t* rhs);
  void      femdarr9_matmul_FF_to( femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_matmul_OF(    mdarr9_t*   lhs, femdarr9_t* rhs);
  void      femdarr9_matmul_OF_to( mdarr9_t*   lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_matmul_FO(    femdarr9_t* lhs, mdarr9_t*   rhs);
  void      femdarr9_matmul_FO_to( femdarr9_t* lhs, mdarr9_t*   rhs, femdarr9_t* res);
  femdarr9_t femdarr9_matmul_RF(    darr_t*    lhs, femdarr9_t* rhs);
  void      femdarr9_matmul_RF_to( darr_t*    lhs, femdarr9_t* rhs, femdarr9_t* res);
  femdarr9_t femdarr9_matmul_FR(    femdarr9_t* lhs, darr_t*    rhs);
  void      femdarr9_matmul_FR_to( femdarr9_t* lhs, darr_t*    rhs, femdarr9_t* res);
  femdnum9_t femdarr9_det(   femdarr9_t* arr);
  void     femdarr9_det_to(femdarr9_t* arr, femdnum9_t* res);
  femdnum9_t femdarr9_norm(     femdarr9_t* arr);
  void     femdarr9_norm_to(  femdarr9_t* arr, femdnum9_t* res);
  femdnum9_t femdarr9_pnorm(    femdarr9_t* arr, coeff_t p);
  void     femdarr9_pnorm_to( femdarr9_t* arr, coeff_t p, femdnum9_t* res);
  femdarr9_t   femdarr9_invert(    femdarr9_t* arr);
  void        femdarr9_invert_to( femdarr9_t* arr, femdarr9_t* res);
  femdarr9_t   femdarr9_transpose(   femdarr9_t* arr);
  void        femdarr9_transpose_to(femdarr9_t* arr, femdarr9_t* res);
  
  