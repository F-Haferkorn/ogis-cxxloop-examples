## Full Implementation Details of the Compound-Group "LOOP" ##

### Necessary Requirements  ###
The cpp-preprocessor must provide:
	
	#pragma once
	__LINE__		line number required by CPPMACRO_UNIQUE_ID() 	
	__COUNTER__		counter required by CPPMACRO_UNIQUE_ID() 
	, __VA_ARGS__)		non-optional variadic arguments, for the "post-comparison" expressions.
	,  ##__VA_ARGS__)	optional variadic-arguments, for the "post-comparison" expressions

This "core-language extension" can be implemented solely using the cpp-preprocessor.

### One-File Implementation ###
	#pragma once

	#include "cppuniqueid.h"


	#define CPPMACRO_NTIMES_DOWN(type, varName, nbrOfRepetitions, ...) \
	    for (type varName = nbrOfRepetitions; varName--; __VA_ARGS__)

	#define loop(nbrOfRepetitions, ...)                 \
	    CPPMACRO_NTIMES_DOWN(auto, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ## __VA_ARGS__)

	#define typed_loop(type, nbrOfRepetitions, ...)     \
	    CPPMACRO_NTIMES_DOWN(type, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ## __VA_ARGS__)

	#define named_loop_down(varName, nbrOfRepetitions, ...)  \
	    CPPMACRO_NTIMES_DOWN(auto, varName, nbrOfRepetitions, ## __VA_ARGS__)

	#if  defined __cplusplus
	// this loop-compound is provided for C++, only.
	#define named_loop_up(varName, nbrOfRepetitions, ...)  \
	    for(decltype(nbrOfRepetitions) varName = 0; varName<nbrOfRepetitions;varName++, ##__VA_ARGS__)
	#endif
	
 
