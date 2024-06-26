// Absolute value
// ****************************************************************************************************
{num_type} {num_func}_abs({num_type}* num){{
    
    {num_type} res;
    {num_func}_abs_to( num, &res);
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_abs_to({num_type}* num, {num_type}* res){{

    if (num->{real_str} < 0){{        
        {num_func}_neg_to(num,res);
    }} else {{
        {num_func}_copy_to(num,res);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// Division.
// ****************************************************************************************************
{num_type} {num_func}_div_oo({num_type}* num, {num_type}* den){{

    {num_type} res;
    {num_func}_div_oo_to(num,den,&res);    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_div_oo_to({num_type}* num, {num_type}* den, {num_type}* res){{

    {num_type} inv = {num_func}_pow( den, -1);    
    {num_func}_mul_oo_to( num, &inv, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {num_func}_div_ro(coeff_t num, {num_type}* den){{

    {num_type} res;
    {num_func}_div_ro_to(num,den,&res);    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_div_ro_to(coeff_t num, {num_type}* den, {num_type}* res){{
    
    {num_type} inv = {num_func}_pow( den, -1);
    {num_func}_mul_ro_to(num,&inv,res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {num_func}_div_or({num_type}* num, coeff_t den){{

    {num_type} res;
    {num_func}_div_or_to(num,den,&res);    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_div_or_to({num_type}* num, coeff_t den, {num_type}* res){{

    {num_func}_mul_ro_to(1.0/val, den, res);

}}
// ----------------------------------------------------------------------------------------------------