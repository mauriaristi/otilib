#ifndef OTI_SPARSE_CORE_BASE_C
#define OTI_SPARSE_CORE_BASE_C
// *******************************************************************************************************
inline void soticore_unset_memory_ownership( soticore_t* num ){

    num->flags[2] =  OTI_memory_not_owned;

}
// -------------------------------------------------------------------------------------------------------
#endif