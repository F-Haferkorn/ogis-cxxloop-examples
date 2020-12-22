#pragma once

///////// the loop-compound statements
	
#include "cppuniqueid.h"

/////// 	// prerequisites
// counting up
#define CPPMACRO_NTIMES_UP(type, indexVarName, nbrOfRepetitions, ...) \
    for(type indexVarName = 0; indexVarName<nbrOfRepetitions; indexVarName++, ##__VA_ARGS__)

///////
// counting down
// CPPMACRO_NTIMES_DOWN:
// - requires signed "indexType" for indexVarName, 
//    in order to beware of underflow and neverending loops for unsigned "indexType"
//    the compound Mmacro PPMACRO_NTIMES_DOWN  requires a signed "indexType"
// - The problem is retriving the indexType for  the iteration variable indexVarName correct.
//     using a simple for(auto indexVarName=0;  .. might not match with the type of nbrOfRepetitions
// - C++ allows decltype(nbrOfRepetitions)

#define CPPMACRO_NTIMES_DOWN(indexType, indexVarName, nbrOfRepetitions, ...) \
		for(indexType indexVarName = nbrOfRepetitions ;  --indexVarName >= 0 ;  __VA_ARGS__)         // will stop on index

//////// typed_llp is the same for C and C++.
#define typed_loop(indexType, nbrOfRepetitions, ...)     \
		CPPMACRO_NTIMES_UP(indexType, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)

// The compounds: loop(){} / named_loop_up(){} named_loop_down(){} 
// require different implementations for C and C++.
// The issue is to retrieve the type of the iteration variable indexVarName correctly.
// C++	: 	only C++11 and later allows "decltype(nbrOfRepetitions)".
// C	:	The indexType defaults to a simple type "int", 
// 			but can may be adapted defining LOOP_COMPOUND_C_INDEX_TYPE with a !signed! type.

#if defined __cplusplus		///////////////////////////////////////////

	#define loop(nbrOfRepetitions, ...)   \
		 CPPMACRO_NTIMES_UP( decltype(nbrOfRepetitions), \
			CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)
	
    #define named_loop_up(indexVarName, nbrOfRepetitions, ...)   \
        CPPMACRO_NTIMES_UP( decltype(nbrOfRepetitions), \
			indexVarName, nbrOfRepetitions, ##__VA_ARGS__)
	
	// REMARK: looping down from nbrOfRepetitions-1 down to 0 with a final indexVarName of -1.
	// It requires a signed indexType comparison 
	// and in order to prevent an unsigned underflow depends on signdness.
	// Unsigned types (size_t) will lead to underflow 
	// and wrappes around to something like UINT_MAX.
	//
	// The loop haswill  terminated at a signed comparison at  indexVarName>=0 
	// so sigdness is definitly required!
	
	#include <type_traits>	
	#define named_loop_down(indexVarName, nbrOfRepetitions, ...)   \
        CPPMACRO_NTIMES_DOWN( std::make_signed<decltype(nbrOfRepetitions)>::type, \
			indexVarName, nbrOfRepetitions, ##__VA_ARGS__)
	
#else  // solution for plain C: use fixed index type as C dows not have keywords: auto or decllype()

	// SimplyNo decltype() available  uses int as type of index variable. 
	// this type may ba adapted may be adapted here.
    #ifndef LOOP_COMPOUND_C_INDEX_TYPE		// must be signed
		#define LOOP_COMPOUND_C_INDEX_TYPE   int
    #endif
	
	/// constraint : type behind LOOP_COMPOUND_C_INDEX_TYPE must be signed!
    #define loop(nbrOfRepetitions, ...)   \
		 CPPMACRO_NTIMES_UP( LOOP_COMPOUND_C_INDEX_TYPE , CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)	
	
	#define named_loop_down(nbrOfRepetitions, ...)   \
		CPPMACRO_NTIMES_DOWN( LOOP_COMPOUND_C_INDEX_TYPE, nbrOfRepetitions, ##__VA_ARGS__)
	
	#define named_loop_up(indexVarName, nbrOfRepetitions, ...)   \
        CPPMACRO_NTIMES_UP( LOOP_COMPOUND_C_INDEX_TYPE, indexVarName, nbrOfRepetitions, ##__VA_ARGS__)
#endif
