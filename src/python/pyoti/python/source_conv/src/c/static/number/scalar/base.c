

// Not implemented correctly:
void {num_func}_set_im_o({num_type}* num, imdir_t idx, ord_t order, {num_type}* res){{
    {num_func}_set_item(num->{real_str},idx,order,res);
}}
void {num_func}_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, {num_type}* res){{
    *res={num_func}_init();
}}
void {num_func}_set_deriv_o({num_type}* num, imdir_t idx, ord_t order, {num_type}* res){{
    *res={num_func}_init();
}}
void {num_func}_extract_im_to( imdir_t idx, ord_t order, {num_type}* num, {num_type}* res){{
    *res={num_func}_init();
}}
{num_type} {num_func}_extract_im(imdir_t idx, ord_t order, {num_type}* num){{
    {num_type} res = {num_func}_init();
    return res;
}}
{num_type} {num_func}_extract_deriv(imdir_t idx, ord_t order, {num_type}* num){{
    {num_type} res = {num_func}_init();
    return res;
}}
void {num_func}_extract_deriv_to(imdir_t idx, ord_t order, {num_type}* num, {num_type}* res){{
	*res = {num_func}_init();
}}
void {num_func}_get_im_to_o(imdir_t idx, ord_t order, {num_type}* num, {num_type}* res){{
    coeff_t rres = {num_func}_get_item(idx, order, num);
    {num_func}_set_r(rres,res);
}}
{num_type} {num_func}_get_im_o(imdir_t idx, ord_t order, {num_type}* num){{
    coeff_t rres = {num_func}_get_item(idx, order, num);
    {num_type} res;
    {num_func}_set_r(rres,&res);
    return res;
}}
void {num_func}_get_im_to_r(imdir_t idx, ord_t order, {num_type}* num, coeff_t* res){{
    *res = {num_func}_get_item(idx, order, num);
}}

inline ord_t {num_func}_get_order({num_type}* lhs){{

	return {oti_order};

}}

{num_type} {num_func}_get_deriv_o( imdir_t idx, ord_t order, {num_type}* num){{

    {num_type} res = {num_func}_init();

    {num_func}_get_deriv_to( idx, order, num, &res);
    
    return res;

}}

void {num_func}_get_deriv_to( imdir_t idx, ord_t order, {num_type}* num, {num_type}* res){{

    coeff_t deriv = {num_func}_get_deriv(idx,order,num);

    {num_func}_set_r( deriv, res);

}}

void {num_func}_set_im_r(coeff_t num, imdir_t idx, ord_t order, {num_type}* res){{

    {num_func}_set_item(num, idx,order,res);

}}

{base_src}