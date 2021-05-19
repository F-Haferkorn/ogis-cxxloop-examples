## Full Implementation Details of the Compound-Group "LOOP" ##

### Necessary Requirements  ###
The cpp-preprocessor must provide:

	#pragma once
	__LINE__		line number required by CPPMACRO_UNIQUE_ID() 	
	__COUNTER__		counter required by CPPMACRO_UNIQUE_ID()
	, ... )			indicates that variadic arguments are at end of MACRO-DEFIITION
	__VA_ARGS__		unfold to the optional variadic argument(s), used for the "post-comparison" expressions.
	,  ##__VA_ARGS__)	like __VA_ARGS__, but unfolds to ")" without the komma if no variadic-arguments is in MACRO call..

This "core-language extension" can be implemented solely using the cpp-preprocessor.

### One-File Implementation for C / C++11 or later ###

	#pragma once

	// this header only file is the implementation of the "COMPOUND-GROUP LOOP

	// prerequisites ////
	// cpp-macro to generate an unique ID
	#ifndef CPPMACRO_UNIQUE_ID
	#define CPPMACRO_UNIQUE_ID() CPPMACRO_UNIQUE_##ID_##LINE##__LINE__##__COUNTER__
	#endif

	// cpp-macro to count upwards (from 0 to nbrOfRepetitions-1)
	#define CPPMACRO_NTIMES_UP(type, varName, reps, ...)                           \
	  for (type varName = 0; varName < reps; varName++, ##__VA_ARGS__)

	// cpp-macro to count downwards (from nbrOfRepetitions-1 to 0)
	#define CPPMACRO_NTIMES_DOWN(indexType, indexVarName, nbrOfRepetitions, ...)   \
	  for (indexType indexVarName = nbrOfRepetitions; indexVarName-- > 0;          \
	       __VA_ARGS__)

	#if defined __cplusplus ///////////////////////////////////////////
	// cpp macro to use type of varname and remove const
	#include <type_traits>
	#define CPPMACRO_DECLTYPE(varname)                                             \
	  typename std::remove_const<decltype(varname)>::type

	#else

	// as "C" cannot detect the type of a varname,
	// this can lead to problems with unsigned varname(s)
	// -> signed/unsigned/ comparison
	#define CPPMACRO_DECLTYPE(varname) int

	#endif

	// apply given type to loop-index variable
	#define typed_loop(indexType, nbrOfRepetitions, ...)                           \
	  CPPMACRO_NTIMES_UP(indexType, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions,        \
			     ##__VA_ARGS__)

	// loop block-statement nbrOfRepetitions-times
	#define loop(nbrOfRepetitions, ...)                                            \
	  CPPMACRO_NTIMES_UP(CPPMACRO_DECLTYPE(nbrOfRepetitions),                      \
			     CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)

	// loop block-statement nbrOfRepetitions-times with index-variable counting
	// upwards
	#define named_loop_up(indexVarName, nbrOfRepetitions, ...)                     \
	  CPPMACRO_NTIMES_UP(CPPMACRO_DECLTYPE(nbrOfRepetitions), indexVarName,        \
			     nbrOfRepetitions, ##__VA_ARGS__)

	// loop block-statement nbrOfRepetitions-times with index-variable counting
	// downwards
	#define named_loop_down(indexVarName, nbrOfRepetitions, ...)                   \
	  CPPMACRO_NTIMES_DOWN(CPPMACRO_DECLTYPE(nbrOfRepetitions), indexVarName,      \
			       nbrOfRepetitions, ##__VA_ARGS__)

