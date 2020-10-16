#pragma once

#include "cppuniqueid.h"

/////////////////////////////////////////////
#define CPPMACRO_NTIMES_UP(type, indexVarName, nbrOfRepetitions, ...) \
    for(type indexVarName = 0; indexVarName<nbrOfRepetitions;indexVarName++, ##__VA_ARGS__)

///////////////////////////////////////////
#define typed_loop(type, nbrOfRepetitions, ...)     \
    CPPMACRO_NTIMES_UP(type, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ## __VA_ARGS__)

#define typed_named_loop_up(type, indexVarName, nbrOfRepetitions, ...)  \
    CPPMACRO_NTIMES_UP(type, indexVarName, nbrOfRepetitions, ##__VA_ARGS__)


// the compounds loop() / named_loop_up() require different implementation for C and C++
// the problem is getting the type of the iteration variable indexVarName correct
// using  for(auto indexVarName=0;  .. might not match with the type of nbrOfRepetitions
// as only C++11 and later allows auto or decltype(nbrOfRepetitions)

#if defined __cplusplus

#define loop(nbrOfRepetitions, ...)   \
        typed_loop( decltype(nbrOfRepetitions), nbrOfRepetitions, ##__VA_ARGS__)

    #define named_loop_up(indexVarName, nbrOfRepetitions, ...)   \
        typed_named_loop_up( decltype(nbrOfRepetitions), indexVarName, nbrOfRepetitions, ##__VA_ARGS__)

#else  // solution for plain C: use fixed index type as C dows not have keywords: auto or decllype()

    #ifdef INTERNALY_USED_C_LOOP_UP_COMPOUND_INDEX_TYPE
        #error "ERROR: cpploop.h: unexpeceted predefined MACRO: INTERNALY_USED_C_LOOP_UP_COMPOUND_INDEX_TYPE"
    #endif

   #if  defined USED_C_LOOP_COMPOUND_INDEX_TYPE
        #define INTERNALY_USED_C_LOOP_UP_COMPOUND_INDEX_TYPE   USED_C_LOOP_COMPOUND_INDEX_TYPE
    #else
        #define INTERNALY_USED_C_LOOP_UP_COMPOUND_INDEX_TYPE   long
    #endif

    #define loop(nbrOfRepetitions, ...)   \
        typed_loop( INTERNALY_USED_C_LOOP_UP_COMPOUND_INDEX_TYPE , nbrOfRepetitions, ##__VA_ARGS__)

    #define named_loop_up(indexVarName, nbrOfRepetitions, ...)   \
        typed_named_loop_up( INTERNALY_USED_C_LOOP_UP_COMPOUND_INDEX_TYPE , indexVarName, nbrOfRepetitions, ##__VA_ARGS__)


#endif
