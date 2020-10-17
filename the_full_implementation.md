## Full Implementation Details of the Compound-Group "LOOP" ##

### Necessary Requirements  ###
The cpp-preprocessor must provide:
	
	#pragma once
	__LINE__		line number required by CPPMACRO_UNIQUE_ID() 	
	__COUNTER__		counter required by CPPMACRO_UNIQUE_ID() 
	, __VA_ARGS__)		non-optional variadic arguments, for the "post-comparison" expressions.
	,  ##__VA_ARGS__)	optional variadic-arguments, for the "post-comparison" expressions

This "core-language extension" can be implemented solely using the cpp-preprocessor.

### One-File Implementation for >=C++11  ###

	#pragma once
	
	#define CPPMACRO_UNIQUE_ID()  CPPMACRO_UNIQUE_##ID_##LINE##_##__LINE__##_##__COUNTER__

        /////////////////////////////////////////////
        #define CPPMACRO_NTIMES_UP(type, indexVarName, nbrOfRepetitions, ...) \
             for(type indexVarName = 0; indexVarName<nbrOfRepetitions;indexVarName++, ##__VA_ARGS__)

        ///////////////////////////////////////////
        #define typed_loop(type, nbrOfRepetitions, ...)     \
             CPPMACRO_NTIMES_UP(type, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ## __VA_ARGS__)

       #define typed_named_loop_up(type, indexVarName, nbrOfRepetitions, ...)  \
             CPPMACRO_NTIMES_UP(type, indexVarName, nbrOfRepetitions, ##__VA_ARGS__)

       ////////// the LOOP COMPOUND-Group as cpp macros ////////////////////////////////////////////////////////////
       #define loop(nbrOfRepetitions, ...)   \
             typed_loop( decltype(nbrOfRepetitions), nbrOfRepetitions, ##__VA_ARGS__)

       #define named_loop_up(indexVarName, nbrOfRepetitions, ...)   \
             typed_named_loop_up( decltype(nbrOfRepetitions), indexVarName, nbrOfRepetitions, ##__VA_ARGS__)

       // LOOPing_DOWN is more difficult. 
       // It can lead to infinite loops due to underflows of possible unsigned index-types.
       // so a signed type index variable is forced using "std::make_signed<>::type"
       #define CPPMACRO_NTIMES_DOWN(declared_type, indexVarName, nbrOfRepetitions, ...) \
             for(std::make_signed<declared_type>::type indexVarName = nbrOfRepetitions ;  --indexVarName >= 0 ;  __VA_ARGS__)         // will stop on index
           
      #define named_loop_down(indexVarName, nbrOfRepetitions, ...)  \
             CPPMACRO_NTIMES_DOWN(decltype(nbrOfRepetitions), indexVarName, nbrOfRepetitions, ## __VA_ARGS__)
