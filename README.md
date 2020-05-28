# ogis-modern-cxx-future-cpp: #
This GITHUB-REPO is a testbed for a special kind of Modern C++ CORE LANGUAGE  extension.

## Motivation ##
Herein I present the  loop() - COMPOUNDs  related to ITERATION
  - loop(N, ...){}
  - typed_loop(type, N, ...)
  - named_loop_up(id, N, ...){}
  - named_loop_down(id, N,  ..){}


With optional opt-opration expressions. N should be of integral type. 
These new COMPOUNDs can be easily imlemented via the cpp-preprocessor.

### Example:  matrix_copy with stride ###
	template<typename TPtr, typename TRowSize, typename TColSize, typename TStrideSize >
	TPtr matrix_copy( TPtr tgt, TPtr src, TRowSize nRows, TColSize nColumns, TStrideSize stride)
        {
                loop(nRows,  tgt+=stride, src+=stride)  // apply strid eafter each row to tht and src
                        loop(nbofColumms)
                             	*tgt++ = *src++;
                return tgt;
        }

### history ###
in C/C++ there are the well known compound statements.
 - if(<cond>) {} else{}
 - while(<cond>) {}
 - do {} while(<cond>);
 - for(<decl>; <cond>;<expr>) {}
 - switch(<expr>) { case: ... default: ... }

with the related staments
 - break
 - continue.
 
 These compounds have not been changed since the  time of creation K&R-C and ANSI-C.
 
 +----------------------------------------------------------------

 
But was that really all for C++?
One might partly agreed that a 

 	try{
 	} catch(...)   {}
 
 "block" is somehow a compound stament, too.

## Details of the C++ core language Extension ##
### Shortcuts: ###
	{}	the <statement> || <statement-block>  after the compound statement
	rep    	the <count> of targeted repetitions (a unsigned integral value) ;
	type	the <type> of the (hiddden) iteration variable
	name	the <name> of the iteration variable
	, ...) 	an optional comma separated list of post-operations (expressions)
		
## SYNTAX: ##
These compounds iterate ("loop") the trailing block "{}" rep times

	// the  hidden_loop does NOT change <rep> with hidden index id.
	loop(rep){}	// for(auto hidden=rep; hidden-- ; ++hidden){}   
	
	// a hidden_loop, with a type constained  index var.
	typed_loop(type,rep){} 	// for(type hidden=rep; hidden-- ; ++hidden){}   
	
	// loop <block> rep times, 
	// with given index var name counting downwards, until name==0 is reached.
	named_loop_up(name,rep){} 	 // for(auto name=rep; name-- ; ++name){}     
	named_loop_down(name,rep){} 	 // for(auto name=rep; name-- ; ++name){}     

The argument _rep_ is _not_ changed:
The assumption, is that the type of rep  is an integal. 
Any float or enum is not allowed for rep.
	
## EXTENDED_SYNTAX ##
	// each of the above the loop compound statements 
	// can be extened by post-iteration operations
	
	// loop <block> rep times 
	loop(rep){}		
	
	// loop <block> rep times with 1 post-operation op1.
	loop(rep, op1 ){}
	
	// loop <block> rep times with 2 postoperations op1, op2  (more are optional).
	loop(rep, op1, op2){}	

	typed_loop(type,rep, op1, ...)){}	// hidden loop with type constraint on the index variable
	named_loop_up(name, cnt, op1, op2, ...){}   // loop upwards with type "auto" a named index variable .	
	named_loop_down(name, cnt, op1, op2, ...){}   // loop deonwards with type "auto" a named index variable.

## IMPLEMENTATION: ##
These "core level extensions can be implemented using only the cpp-preprocessor 
	
	#pragma once

	#define CPPMACRO_UNIQUE_ID()  CPPMACRO_UNIQUE_ID_##_##LINE##_##__LINE__##_##__COUNTER__

	// count-down: )inverse  loop: =
	#define CPPMACRO_NTIMES_COUNT_UP(type, varName, nbrOfRepetitions, ...) \
    		for (type varName = 0; varName++<nbrOfRepetitions; __VA_ARGS__)

	// regular loop: counting-up
	#define CPPMACRO_NTIMES_COUNT_DOWN(type, varName, nbrOfRepetitions, ...) \
    		for (type varName = nbrOfRepetitions; varName--; __VA_ARGS__)

	/// todo: choose the fatest depending on the machine
	#define CPPMACRO_NTIMES_FAST(type, varName, nbrOfRepetitions, ...) \
    		CPPMACRO_NTIMES_COUNT_UP(type, varName, nbrOfRepetitions, __VA_ARGS__)

	//#define loop(nbrOfRepetitions)  CPPMACRO_NTIMES(auto, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions)
	#define loop(nbrOfRepetitions, ...)                 CPPMACRO_NTIMES_FAST(auto, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)
	#define typed_loop(type, nbrOfRepetitions, ...)     CPPMACRO_NTIMES_FAST(type, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)
	#define named_loop_up(varName, nbrOfRepetitions, ...)  CPPMACRO_NTIMES_COUNT_UP(auto, varName, nbrOfRepetitions, ##__VA_ARGS__)
	#define named_loop_down(varName, nbrOfRepetitions, ...)  CPPMACRO_NTIMES_COUNT_DOWN(auto, varName, nbrOfRepetitions, ##__VA_ARGS__)



Properties of the solution 
 - the current solution is based on the c--preprocessor (cpp) only.	
 - it is a header only solution
	
Creating the hidden index name  
	CPPMACRO_UNIQUE_ID()   generated an unqiue for the hidden index
	
Outcomes for ANSI-C
 - Even if it has been designed for Modern C++ it works also with a plain ANSI-C compiler.
 - It is implementable using the standard 'cpp' c--preprocessor, only,
	

## DISCUSSION ##
 One might argue, loop(){} is is only a plain mapping to a for(;;){} statement.
 
 ### Advantages: ###
 OK, it is all about iterating and it is not a swiss-army knife for all iterations.
 BUT:
 - READability:  It can reduce C/C++ source code size and improve its readability.
 - TEACHability: it will improve the way to teach C/C++  especially for a younger audiencce.
 - ALGORITHMics: It allows/leads the developer(s) to notate code that completely does _NOT depend on the iteration index_.
 - OPTIMIZATION: It opens the way to enhanced optimizations for upciming compiler implementations.

### REMARK on TEACHing C/C++: ###
  - !!! the UK-Government decided to "force" (childern||pupils) form 4-years on to learn how to programm. !!!
  - 2nd grade (7years old) pupils are able to cope wit the concept of PRINTING, LOOPING and generating textual/graphical outputs. But CONDITIONS with the need of using boolean Expressions like AND, OR, NOT are a very hard stuff at  that age. 
  Suggestion:
  - What about starting to teach C++ for pupils with: putc(), loop() and going on with vars and  assignment.
  - Forming them to statements to creating textual outputs on the (screen || printer).
  - Assigning, and the operations add, subtract, multiply, divide and modulo are enough challenging  at that age.
  - and teaching in then next, the 3rd grade: , functions / agrumnet passing & Conditions inklusive Boolean Algebra.
  
  What do you think  ?
   - How far COULD the teaching-level for bachelor students in 2034 of Programming (C/C++) for the the now 4-year old kindergarden children be?
   - Compared to 2020  bachelor students?
  And what would be their favored programming language ???
    
### REMARK on OPTIMIZAtion: ###
The new iterative coumpounds 
 - have less degree of freedom
 - and will give room for futher enhancements of the compiler optimization.
We will see if:
 - it can lead to SHORTER, COMPACTER machine-code as the itearation is SIMPLER.
 - This will definitely apply for large loops with a tiny loop body.
 - This can reduce the _rate of cache-misses_ dramatically.

### Beware of UNINTENDED-USAGE: ###
	YES, in the presented cpp-implementation,
	the underlying itarator index <rep> is not really "hidden" and could be "guessed" by a experienced programmer.

## WORK to to: ##
 - However I  will have to prove, that there are _realworld USE-CASES_,
 - for cases the  described compounds can be applied
 - so that the praised _"unbeatable"_ _compiler_  
 - can be driven to make better/shorer/faster machine code
 - compared to the now-a-days solution for(int i=0; i<rep; ++i){}
  
## CONCLUSion: ##
First experts comments say that it is is a _stony way_ to get the suggested  core-language _compounds_ wil get its way to C/C++. 
But You can take the occasion and try it out yourself. 
It works. Even for plain Ansi-C See the *IMPLEMENTATION* section.

## ADVANCED Reading: ##
	- Teaching programming in the Kindergarden and later:
 	https://www.raspberrypi.org/forums/viewtopic.php?t=762   a news form 2011 
 	https://www.intechopen.com/books/early-childhood-education/evaluating-a-course-for-teaching-advanced-programming-concepts-with-scratch-to-preservice-kindergart


 
	
