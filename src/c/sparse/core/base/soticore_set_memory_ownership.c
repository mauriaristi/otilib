#ifndef OTI_SPARSE_CORE_BASE_SOTICORE_SET_MEMORY_OWNERSHIP_C
#define OTI_SPARSE_CORE_BASE_SOTICORE_SET_MEMORY_OWNERSHIP_C
// *******************************************************************************************************
inline void soticore_set_memory_ownership( soticore_t* num ){

    num->flags[2] =  OTI_memory_is_owned;

}
// -------------------------------------------------------------------------------------------------------
#endif