# ogis-modern-cxx-future-cpp
This REPO is a testbed for future Modern C++ extension based on the 'cpp'


Providing a header only solution of new simple LOOP-compound statements.

	new-keywords: 
		loop(), typed_loop(), named_loop()          plain loop compounds
		loop_(), typed_loop_(), named_loop_()       loop compounds with additional post-loop opertions
	

	uses syntax
		N    		the count of targeted repetitions (a unsigned integral value) ;
		BLOCK;		the statement or statement-block  after the compound statement
		, ...) 		a comma separated list of expressions  
		TYPE		the <type> of the iteration variable
		NAME		the <name> of the iteration variable
		UNIQUE_ID	a auto-generated unqiue id for this loop statement 			
		
	
	Description:
	new compounds				cpp-only implememenation
	+---------------------------------------+----------------------------
	
	loop(N) BLOCK;				for(auto UNIQUE_ID=N; N--;)			BLOCK;						
	typed_loop(TYPE, N) BLOCK;		for(TYPE UNIQUE_ID=N; N--;)			BLOCK;						
	named_loop(NAME, N) BLOCK;  		for(auto NAME=N; N--;)				BLOCK;						
							
							
	new compounds with post-ops..	    	cpp-only implememenation							
	+---------------------------------------+----------------------------
	
	loop_(N, ...) BLOCK;			for(auto UNIQUE_ID=N; N--; __VA_ARGS__)		BLOCK;						
	typed_loop_(TYPE, N, ...) BLOCK;	for(TYPE UNIQUE_ID=N; N--; __VA_ARGS__)		BLOCK;						
	named_loop_(NAME, N, ...)  BLOCK;	for(auto NAME=N; N--; __VA_ARGS__)  		BLOCK;


Examples:
	+-----------------------------------------------------------------------------
	
        float* matrix_copy( float* tgt, float* src, int nbofRows, int nbofColums)
        {
                loop(nbofRows)
                        loop(nbofColums)
            	                *tgt++ = *src++;
		return tgt;
        }

   
        float* matrix_copy( float* tgt, float* src, int nbofRows, int nbofColums, int  stride)
        {
                loop(nbofRows)
                        loop_(nbofColumms, tgt+=stride, src+=stride)
                             	*tgt++ = *src++;
                return tgt;
        }
	
							
