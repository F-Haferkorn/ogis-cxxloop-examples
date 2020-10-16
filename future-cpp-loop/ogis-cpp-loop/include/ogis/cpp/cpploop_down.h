#pragma once

#include <type_traits>

// ATTENTION: reuires a type
// beware of loop(0U) // conversion of type of indexVarName to singned,
// in order to prevnt an unsigned underflow (and gives an UINT_MAX)
#define CPPMACRO_NTIMES_DOWN(declared_type, indexVarName, nbrOfRepetitions, ...) \
    for(std::make_signed<declared_type>::type indexVarName = nbrOfRepetitions ;  --indexVarName >= 0 ;  __VA_ARGS__)         // will stop on index

#define typed_named_loop_down(type, indexVarName, nbrOfRepetitions, ...)  \
     CPPMACRO_NTIMES_DOWN(type, indexVarName, nbrOfRepetitions, ## __VA_ARGS__)



// the compound-statement  named_loop_down() requires different implementation for C and C++
// the problem is getting the type of the iteration variable indexVarName correct
// using  for(auto indexVarName=0;  .. might not match with the type of nbrOfRepetitions
// c++ allows decltype(nbrOfRepetitions)

#if defined __cplusplus


    #define named_loop_down(indexVarName, nbrOfRepetitions, ...)  \
         CPPMACRO_NTIMES_DOWN(decltype(nbrOfRepetitions), indexVarName, nbrOfRepetitions, ## __VA_ARGS__)

//for(std::make_signed<decltype(nbrOfRepetitions)>::type indexVarName = nbrOfRepetitions ;  --indexVarName >= 0 ;  __VA_ARGS__)         // will stop on index
#else  // solution for plain C: use fixed index type as C dows not have keywords: auto or decllype()

    #ifdef INTERNALY_USED_C_LOOP_DOWN_INDEX_TYPE
        #error "ERROR cpploop.h: unexpeceted predefined MACRO: INTERNALY_USED_C_LOOP_DOWN_INDEX_TYPE"

    #endif

    #if  defined USED_C_LOOP_COMPOUND_INDEX_TYPE
        #define INTERNALY_USED_C_LOOP_DOWN_INDEX_TYPE   USED_C_LOOP_COMPOUND_INDEX_TYPE
    #else
        #define INTERNALY_USED_C_LOOP_DOWN_INDEX_TYPE     long
    #endif

     #define named_loop_down(indexVarName, nbrOfRepetitions, ...)  \
         typed_named_loop_down( INTERNALY_USED_C_LOOP_DOWN_INDEX_TYPE, indexVarName, nbrOfRepetitions, ## __VA_ARGS__)


#endif
