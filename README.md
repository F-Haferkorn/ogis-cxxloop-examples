# Introducing the Compound-Group "LOOP" #

Herein I want to suggest a  **core-level extension** for both the **C** and the **C++** programming language.

This repo contains the implementation for the **compound-group "LOOP"** using the **cpp-preprocessor**,
and wants to open the door to a disussion inside the community.

## Overview ##

This github-site is a testbed and discussion-ground for a *C++ core-language extension* based on the *cpp-preprocessor*.

Herein I present my work on the iteration related compound-group **LOOP**.

The syntax is like this

        // all compounds below allow *optional* post-expressions instead of , ... 
        // and are followed by a block-statement.
        // iterate <rep> times  and uses a hidden, secret unique-index variable.
        - loop(<rep>, ...){}                                   // use an index variable of same type as <rep>
        - typed_loop(<type>, <rep>, ...)                       // use a typed index variable using type <type>
	
        // same as loop, but use the given index variable <id>.
        - named_loop_up(<id>, <rep>, ...){}                     // count id up-wards
        - named_loop_down(<id>, <rep>,  ..){}                   // count id down-wards	
	
with the tokens:
 - **rep**   the count or repetitions. (is likely an integral)
 - **{}**    is any  block statement following th ecompound.
 - **id**    any valid identificator to access the iteration variable.
 - **type**  any valid type-name.
 
These new compounds are currently implemented via the cpp-preprocessor.
Except in typed_loop(){}, the iteration variable has the same type as the count of repetitions *rep*.

### Activation via #include  ### 

All "LOOP" coumpound-statments can be used after an:
 	
	#inclucde <loop>

### Usage Example ###
Here is an example usage for of a matrix-copy uisng a stride-offset fro each row :

	#inclucde <loop>

	template<typename TPtr, typename TRowSize, typename TColSize, typename TStrideSize >
	void matrix_copy_with_stride( TPtr tgt, TPtr src, TRowSize nRows, TColSize nColumns, TStrideSize stride)
  	{
		// compiler can mangle the (integral-typed) loop-internal index-vars and  tgt and src in registers ansd speedup teh loop and incrementation.
		loop(nRows,  tgt+=stride, src+=stride)  // apply stride after each row to tgt and src
			loop(nColumns, tgt++, src++)	// increment after each copy.
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
For A full implementation of all compounds see below.

## About Existing Compound-Statements   ##
have a look at: https://github.com/F-Haferkorn/ogis-modern-cxx-future-cpp/blob/master/the_existing_compounds.md

**Is it a LAW-OF-NATURE that there will NEVER be any other compound-statments in the future?**
 
## Full Syntax ##
have a look to: https://github.com/F-Haferkorn/ogis-modern-cxx-future-cpp/blob/master/the_full_syntax.md

## Full Implementation ##
have a look to: https://github.com/F-Haferkorn/ogis-modern-cxx-future-cpp/blob/master/the_full_implementation.md

## Discussion ##

One might argue, **loop(){}** is is only a plain mapping to a **for(;;){}** statement.

OK, it is all about iterating and it is not a *swiss-army knife for all iterations*.
 
### Properties of the current implementation  ###

 - the solution *"is ready to rumble"*
 - the solution *is based on the c-preprocessor (cpp) only.*
 - it is a header only solution
 - no changes to any compiler are necesary.
 - it creates a hidden index name uinsg the macro  CPPMACRO_UNIQUE_ID()

Outcomes for ANSI-C
 - Even if it has been designed for Modern C++ it works also with a plain ANSI-C compiler.
 - It is implementable using solely the standard c-preprocessor (cpp).


### Advantages: ###

With recent compilers, this is **as fast*** as the **regular** **for(;;){}** iteration.

BUT it has these advantages:
 - **READability**:  It reduces C/C++ source code size and improve its readability.
 - **TEACHability**: it will improve the way to teach C/C++  especially for a younger audiencce.
 - **ALGORITHMics**: It allows/leads the developer(s) to notate code that completely does _NOT depend on the iteration index_.
 - **OPTIMIZATION**: It opens the way to enhanced optimizations for upcoming compiler implementations.
 	- by utilizing the *reduced degree of freedom* of the iteration
	- by using fast ALU-register increment operations of *DSP-Architectures*.
     
### Disadvantages:  ###
- The underlying itarator index <rep> is not really "hidden" and could be "guessed" by a experienced programmer. But this is somehow unlikely.
- The current preprocessor implemantation will break when using an **argument containing a comma** . This happens seldomly, e.g. when an complex template expression is used that contains any comma ','.	

The last "comma related" problem can easily be fixed by surrounding the problematic argumment with regular braces *loop(* **(** argment **)** *)*.
IN CASE:
 - the LOOP-compounds are added to the the core-language this problem would be solved, as no more usage of the cpp-preprocessor is necessary.

## Remarks ##
### Remarks on Compiler Optimization ###
The new iterative coumpounds
 - have less degree of freedom
 - and will give room for futher enhancements of the compiler optimization.
 
We will see if:
 - it can lead to SHORTER, COMPACTER machine-code as the itearation is SIMPLER.
 - This will definitely apply for large loops with a tiny loop body.
 - This can reduce the _rate of cache-misses_ dramatically.

### Remarks on Teachingability of  C/C++ ###
  - ! the UK-Government decided to "force" (childern||pupils) form 4-years on to learn how to programm. !
  - 5th grade (10-years old) pupils **can** cope with the concept of **looping**,  and generating textual outputs via **printing**  something like squares, tiangles, etc.
  - But a simple **for(int i=0; i<n; ++i)**  statement will overwhelm them. 
  Variable *types* and their *Assignemt*,   *conditions* in the form of **boolean expressions** with relations and incrementation is re a very hard stuff at that age.
	
  Suggestion:
	
  - What about starting to teach C/C++ for pupils as early as posisble with: putc(), loop() and going on with vars and assignment.
  - going on to  statements in order to  create textual outputs on the (screen || printer).
  - and lateron assigning, and the operations add, subtract, multiply, divide and modulo are enough challenging  at that age.
  - and teaching them lateron *conditions* inklusive the  *Boolean Algebra*.
  - and in the *following-years* the full power of C/C++  (functions, for(;;){}, ...) 

  What do you think  ?
  - Seen from the Pont of View: Year 2020
  - How far COULD the teaching-level for bachelor students in 2034 of Programming (C/C++) for the now 4-year old kindergarden children be?
  - Compared to nowadays 2020 bachelor students?
  And what would be their favored programming language ?

## Conclusions ##
 - First experts comments say that it is is a _stony way_ to get the suggested  core-language _compounds_ wil get its way to C/C++.
 - But you can take the occasion and try it out yourself. It works. 
 - Even for plain Ansi-C.
 - the issues of READABILITY and TECHABILTY  

Attention: (see  disadvantages)
in the recent preprocessor implementation breaks on arguments containing a comma (like for some  complex template-expressions). 
There is a wouraround for that.

## Work still to be done ####
 - However I  will have to prove, that there are _realworld USE-CASES_, for cases the described compounds can be applied
 - so that the praised _"unbeatable"_ _compiler_  can be driven to make better/shorer/faster machine code
 - compared to the now-a-days solution *for(int i=0; i<rep; ++i){}*
 - stress out the aspekt of teachability.

# References #

 - Teaching programming in the Kindergarden and later:
   	- https://www.raspberrypi.org/forums/viewtopic.php?t=762   a news form 2011
 	- https://www.intechopen.com/books/early-childhood-education/evaluating-a-course-for-teaching-advanced-programming-concepts-with-scratch-to-preservice-kindergart

