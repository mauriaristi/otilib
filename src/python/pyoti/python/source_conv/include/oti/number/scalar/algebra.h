#ifndef OTI_{module_name_upper}_SCALAR_ALGEBRA_H
#define OTI_{module_name_upper}_SCALAR_ALGEBRA_H

{num_type} {num_func}_abs({num_type}* num);
{num_type} {num_func}_div_ro(coeff_t num, {num_type}* den);
{num_type} {num_func}_div_oo({num_type}* num, {num_type}* den);
{num_type} {num_func}_div_or({num_type}* num, coeff_t val);
void {num_func}_div_ro_to(coeff_t num, {num_type}* den, {num_type}* res);
void {num_func}_div_oo_to({num_type}* num, {num_type}* den, {num_type}* res);
void {num_func}_div_or_to({num_type}* num, coeff_t val, {num_type}* res);
void {num_func}_abs_to({num_type}* num, {num_type}* res);

{algebra_include}

#endif