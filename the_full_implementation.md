## Full Implementation Details of the Compound-Group "LOOP" ##

### Necessary Requirements  ###
The cpp-preprocessor must provide:
	
	__LINE__		line number required by CPPMACRO_UNIQUE_ID() 	
	__COUNTER__		counter required by CPPMACRO_UNIQUE_ID() 
	, __VA_ARGS__)		non-optional variadic arguments, for the "post-comparison" expressions.
	,  ##__VA_ARGS__)	optional variadic-arguments, for the "post-comparison" expressions

This "core-language extension" can be implemented solely using the cpp-preprocessor.

### One-File Implementation ###

	#pragma once
	/// create an unique symbol id...
	#define CPPMACRO_UNIQUE_ID()  CPPMACRO_UNIQUE_ID_##_##LINE##_##__LINE__##_##__COUNTER__

	// regular loop:                counting-up
	#define CPPMACRO_NTIMES_COUNT_DOWN(type, varName, nbrOfRepetitions, ...) \
    		for (type varName = nbrOfRepetitions; varName--; __VA_ARGS__)

	// inverse loop: 	 	counting-down
	#define CPPMACRO_NTIMES_COUNT_UP(type, varName, nbrOfRepetitions, ...) \
    		for (type varName = 0; varName++<nbrOfRepetitions; __VA_ARGS__)

	/// choose                      the fatest loop depending on the machine
	#define CPPMACRO_NTIMES_FAST(type, varName, nbrOfRepetitions, ...) \
    		CPPMACRO_NTIMES_COUNT_UP(type, varName, nbrOfRepetitions, __VA_ARGS__)
	
	#define loop(nbrOfRepetitions, ...)                      CPPMACRO_NTIMES_FAST(auto, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)
	#define typed_loop(type, nbrOfRepetitions, ...)          CPPMACRO_NTIMES_FAST(type, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)
	#define named_loop_up(varName, nbrOfRepetitions, ...)    CPPMACRO_NTIMES_COUNT_UP(auto, varName, nbrOfRepetitions, ##__VA_ARGS__)
	#define named_loop_down(varName, nbrOfRepetitions, ...)  CPPMACRO_NTIMES_COUNT_DOWN(auto, varName, nbrOfRepetitions, ##__VA_ARGS__)


	
	
 
