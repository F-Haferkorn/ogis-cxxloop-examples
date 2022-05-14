## Full Implementation Details of the Compound-Group "LOOP" ##

### Compiler / Cpp-Preprocessor   Requirements  ###

	 
 - full compatibilty with C++11
 
 	- #pragma once
	- , ... )			indicates that variadic arguments are at end of MACRO-DEFIITION
	- __VA_ARGS__		unfold to the optional variadic argument(s), used for the "post-comparison" expressions.

- additional requirements

	- __COUNTER__		counter required by CPPMACRO_UNIQUE_ID()


This "core-language extension" can be implemented solely using the cpp-preprocessor.

### Implementation for C / C++11 or later ###
- [cxxloop_prereqs.h](cxxloop/include/cxxloop_prereqs.h) defining *necessary prerequisites*
- [cxxloop.h](cxxloop/include/cxxloop.h)		defining the *regular loop stuff*
- [cxxloop.h](cxxloop/include/cxxloop_postops.h)  defining the *post-opeartion stuff*


