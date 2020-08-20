

// Not implemented correctly:
void soti_set_im_o(sotinum_t* num, imdir_t idx, ord_t order, sotinum_t* res, dhelpl_t dhl){
    soti_set_item(num-><<<real_str>>>,idx,order,res,dhl);
}
void soti_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, sotinum_t* res, dhelpl_t dhl){
    *res=soti_init();
}
void soti_set_deriv_o(sotinum_t* num, imdir_t idx, ord_t order, sotinum_t* res, dhelpl_t dhl){
    *res=soti_init();
}
void soti_extract_im_to( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    *res=soti_init();
}
sotinum_t soti_extract_im(imdir_t idx, ord_t order, sotinum_t* num,  dhelpl_t dhl){
    sotinum_t res = soti_init();
    return res;
}
sotinum_t soti_extract_deriv(imdir_t idx, ord_t order, sotinum_t* num,  dhelpl_t dhl){
    sotinum_t res = soti_init();
    return res;
}
void soti_extract_deriv_to(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
	*res = soti_init();
}
void soti_get_im_to_o(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    coeff_t rres = soti_get_item(idx, order, num, dhl);
    soti_set_r(rres,res, dhl);
}
sotinum_t soti_get_im_o(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    coeff_t rres = soti_get_item(idx, order, num, dhl);
    sotinum_t res;
    soti_set_r(rres,&res,dhl);
    return res;
}
void soti_get_im_to_r(imdir_t idx, ord_t order, sotinum_t* num, coeff_t* res, dhelpl_t dhl){
    *res = soti_get_item(idx, order, num, dhl);
}














inline ord_t soti_get_order(sotinum_t* lhs){

	return <<<oti_order>>>;

}

sotinum_t soti_get_deriv_o( imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){

    sotinum_t res = soti_init();

    soti_get_deriv_to( idx, order, num, &res, dhl);
    
    return res;

}

void soti_get_deriv_to( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t deriv = soti_get_deriv(idx,order,num,dhl);

    soti_set_r( deriv, res, dhl);

}

void soti_set_im_r(coeff_t num, imdir_t idx, ord_t order, sotinum_t* res, dhelpl_t dhl){

    soti_set_item(num, idx,order,res,dhl);

}




<<<base_src>>>