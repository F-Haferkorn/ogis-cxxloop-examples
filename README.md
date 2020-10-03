# Introducing the LOOP Compound-Group #
A suggested core-level extension for C/C++ language.

## Overview ##
This github-site is a testbed and discussion-ground for a *C++ core-language extension* based on the *cpp-preprocessor*.
Herein I present my work on the iteration related compound-group **loop()** - 
The syntax is like this

	- loop(rep, ...){}		//    *optional* post-expressions may be used instead of , ...  
	- named_loop_up(id, rep, ...){}
	- named_loop_down(id, rep,  ..){}
	- typed_loop(type, rep, ...)

with 
 - *rep*   the (integral) count or repetitions
 - *{}*    is any  block statement following th ecompound
 - *id*    any valid identificator to access the iteration variable
 - *type*  any valid type-name
 
These new compounds are currently implemented via the cpp-preprocessor.
Except in typed_loop(){}, the iteration variable has the same type as the count of repetitions *rep*

There are *possible problems* in the *current* cpp implemantation when using arguments containing a ",". 
But there is a solution for that.

### Usage Example ###
**matrix_copy_with_stride()**
for more see:: https://github.com/F-Haferkorn/ogis-modern-cxx-future-cpp/tree/master/future-cpp-loop/ogis-cpp-loop.examples/examples

	template<typename TPtr, typename TRowSize, typename TColSize, typename TStrideSize >
	void matrix_copy_with_stride( TPtr tgt, TPtr src, TRowSize nRows, TColSize nColumns, TStrideSize stride)
  	{
		// compiler can mangle the loop-internal integral-types tgt and src in registers inclusive the incrementations
		loop(nRows,  tgt+=stride, src+=stride)  // apply strid eafter each row to tgt and src
			loop(nColumns, tgt++, src++)
				*tgt = *src;
		return;
	}
	
### Demo Implemenation ###
**loop(){}**  can be implented like the folowing 
	
	#define CPPMACRO_UNIQUE_ID()  CPPMACRO_UNIQUE_ID_##_##LINE##_##__LINE__##_##__COUNTER__
	
	#define CPPMACRO_NTIMES_FAST(type, varName, nbrOfRepetitions, ...) \
		for (type varName = nbrOfRepetitions; varName--; __VA_ARGS__)
		
	#define loop(nbrOfRepetitions, ...)  \
		CPPMACRO_NTIMES_FAST(auto, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)

For the related compounds typed_loop(){}, named_loop_up(){},  named_loop_down(){}, see below.

## About Existing Compound-Statements ###
###  ANSI-C Compounds ###
in C/C++ there are the well known *compound statements*.
	
	- if(<cond>) {} else{}
	- while(<cond>) {}
 	- do {} while(<cond>);
 	- for(<decl>; <cond>;<expr>) {}
 	- switch(<expr>) { case: ... default: ... }

with the related staments

	- break
 	- continue

These compounds have not been changed since the  time of creation K&R-C and ANSI-C.

### Non ANSI-C Compounds ##
One might partly agreed that a

  	try{
  	} catch(...)   {}

 "block" is somehow a compound stament, too.

 Is it a LAW-OF-NATURE that there must *never* be ANY (more||other) compound-statments in the future?

## Full Syntax of the Compound Group LOOP ##
have a look to: https://github.com/F-Haferkorn/ogis-modern-cxx-future-cpp/blob/master/the_full_syntax.md

## Full Implementation Details of the Compound Group LOOP ##
have a look to: https://github.com/F-Haferkorn/ogis-modern-cxx-future-cpp/blob/master/the_full_implementation.md

## Full Implementation Details of the Compound Group LOOP ##
### necessary Requirements  ###
The cpp-preprocessor must provide:
	
	__LINE__		line number  used by  CPPMACRO_UNIQUE_ID() 	
	__COUNTER__		counter used by CPPMACRO_UNIQUE_ID() 
	,  ##__VA_ARGS__)	optional variadic-arguments, for the post-comaprison operations

This "core-language extension" can be implemented solely using the cpp-preprocessor.
see here for details:
https://github.com/F-Haferkorn/ogis-modern-cxx-future-cpp/tree/master/future-cpp-loop/ogis-cpp-loop/includes/ogis/cpp

### Implementation ###
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


## Discussion ##
 One might argue, loop(){} is is only a plain mapping to a for(;;){} statement.
 
### Properties of the current implementation  ###
 - the solution *"is ready to rumble"*
 - the solution *is based on the c-preprocessor (cpp) only.*
 - it is a header only solution
 - no changes to any compiler are necesary.
  
Creating the hidden index name
  CPPMACRO_UNIQUE_ID()   generated an unqiue-id for the hidden index

Outcomes for ANSI-C
 - Even if it has been designed for Modern C++ it works also with a plain ANSI-C compiler.
 - It is implementable using solely the standard c-preprocessor (cpp).


### Advantages: ###
 With recent compilers, this is *NOT* slower than thhe *regular* for(;;){} iteration.
 
 The **reduced degree of freedom of the iteration** can be used by the comoiler
 and a compiler can make heavy use of ALU-register operation of DSP-Architectures.
 
 OK, 
 it is all about iterating and it is not a *swiss-army knife for all iterations*.
 BUT:
 - READability:  It can reduce C/C++ source code size and improve its readability.
 - TEACHability: it will improve the way to teach C/C++  especially for a younger audiencce.
 - ALGORITHMics: It allows/leads the developer(s) to notate code that completely does _NOT depend on the iteration index_.
 - OPTIMIZATION: It opens the way to enhanced optimizations for upcoming compiler implementations.
 
### Disadvantages:  ###
 - The underlying itarator index <rep> is not really "hidden" and could be "guessed" by a experienced programmer.
 - The current preprocessor implemantation will break if an argument containing a comma is attached. Adding the new compounds to the core-language would fix that issue.
	
 An Example of an problemartic argumnet, and a possible workaround.


## Remarks ##
### Teachingability of  C/C++ ###
  - ! the UK-Government decided to "force" (childern||pupils) form 4-years on to learn how to programm. !
  - 2nd grade (7years old) pupils CAN cope with the concept of PRINTING, LOOPING and generating textual/graphical outputs. But CONDITIONS with the need of using **boolean Expressions** like AND, OR, NOT are a very hard stuff at that age.
	
  Suggestion:
	
   	- What about starting to teach C++ for pupils inthe **2nd grade** with: putc(), loop() and going on with vars and assignment.
  	- Forming them to statements to creating textual outputs on the (screen || printer).
  	- Assigning, and the operations add, subtract, multiply, divide and modulo are enough challenging  at that age.
  	- and teaching in then next, the **3rd grade** conditions inklusive Boolean Algebra.
		- and in the *following-years* the full power of C/C++  (functions, for(;;){}, ...) 

  What do you think  ?
  	- Seen from the Pont of View: Year 2020
   	- How far COULD the teaching-level for bachelor students in 2034 of Programming (C/C++) for the now 4-year old kindergarden children be?
   	- Compared to nowadays 2020 bachelor students?
  And what would be their favored programming language ?

###  Optimization ###
The new iterative coumpounds
 - have less degree of freedom
 - and will give room for futher enhancements of the compiler optimization.
We will see if:
 - it can lead to SHORTER, COMPACTER machine-code as the itearation is SIMPLER.
 - This will definitely apply for large loops with a tiny loop body.
 - This can reduce the _rate of cache-misses_ dramatically.


## Work still to be done ##
 - However I  will have to prove, that there are _realworld USE-CASES_, for cases the described compounds can be applied
 - so that the praised _"unbeatable"_ _compiler_  can be driven to make better/shorer/faster machine code
 - compared to the now-a-days solution for(int i=0; i<rep; ++i){}
 - stress out the aspekt of teachability 

## Conclusions ##
First experts comments say that it is is a _stony way_ to get the suggested  core-language _compounds_ wil get its way to C/C++.
But You can take the occasion and try it out yourself.
It works. Even for plain Ansi-C.
The preprocessor implementation has problems for arguments containing a comma.

# References #
  - Teaching programming in the Kindergarden and later:
  https://www.raspberrypi.org/forums/viewtopic.php?t=762   a news form 2011
  https://www.intechopen.com/books/early-childhood-education/evaluating-a-course-for-teaching-advanced-programming-concepts-with-scratch-to-preservice-kindergart
  
