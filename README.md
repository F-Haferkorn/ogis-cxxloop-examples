[THE orignal GITHUB REPOSITORY](https://github.com/F-Haferkorn/ogis-modern-cxx-future-cpp/)

# Introducing the Compound-Group "LOOP" #

Herein I want to suggest an  **extension** for the **C++** programming language.

This repo contains the implementation for the **compound-group "LOOP"** using the **cpp-preprocessor**,
and wants to open the door to a discussion within the C++-community.

## Public Talks  ##
 - [Videos with Slides](./talks/README.md)

## The Idea ##

- Introduce new compound-statement **loop(){}**
- to reduce the  **DEGREES OF FREEDOM** of the **for(;;){}** compound statement
- in order to allow **simple forms of iterations**.

Example:

        // copy a 4x10 array
        loop(4)                         // iterate over 4 rows.  
           loop(10)                     // iterate over 10 columns.
              *tgt++  =   *src++ ;      // copy *source to *target.


## Overview ##

This github.com-site is a testbed and discussion-ground for a *C++ core-language extension* based on the *cpp-preprocessor*.

Herein I present my work on the iteration related compound-group **LOOP**.

The syntax is like this:

        // all compounds below allow *optional* post-expressions instead of ", ... )"
        // and are followed by a block-statement "{}".
        // iterate <rep> times  and uses a hidden, secret unique-index variable.
        - loop(<rep>, ...){}                                    // use an index variable of same type as <rep>
        - typed_loop(<type>, <rep>, ...){}                      // use a typed index variable using type <type>

        // same as loop, but use the given index variable <id>.
        - named_loop_up(<id>, <rep>, ...){}                     // count id up-wards
        - named_loop_down(<id>, <rep>,  ..){}                   // count id down-wards	!!! here occur some problems.. see below.

with the tokens:
 - **rep**   the count or repetitions. (is likely an integral)
 - **{}**    is any  block statement following the compound. (may be a single statement).
 - **id**    any valid identificator to access the iteration variable.
 - **type**  any valid type-name.

These new compounds are currently implemented via the cpp-preprocessor.
Except in typed_loop(){}, the iteration variable has the same type as the count of repetitions *rep*.

### Activation via #include  ###

All "LOOP" compound-statments can be used after an:

	#include <loop>

### Usage Example ###
Here is an example usage for of a matrix-copy using a stride-offset from each row :

	#include <loop>

	template<typename TPtr, typename TRowSize, typename TColSize, typename TStrideSize >
	void matrix_copy_with_stride( TPtr tgt, TPtr src, TRowSize nRows, TColSize nColumns, TStrideSize stride)
  	{
		loop(nRows,  tgt+=stride, src+=stride)  // apply stride after each row to tgt and src
			loop(nColumns, tgt++, src++)	// increment after each copy.
				*tgt = *src;
		return;
	}


### Demo Implemenation ###

**loop(){}**  can be implemented like the following

	#define CPPMACRO_UNIQUE_ID()  \
		CPPMACRO_UNIQUE_ID_##_##LINE##_##__LINE__##_##__COUNTER__

        #define CPPMACRO_NTIMES_UP(type, indexVarName, nbrOfRepetitions, ...) \     
                 for(type indexVarName = 0; indexVarName<nbrOfRepetitions;indexVarName++, ##__VA_ARGS__)

        #define loop(nbrOfRepetitions, ...)   \
                   CPPMACRO_NTIMES_UP( decltype(nbrOfRepetitions), CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)

## About Existing Compound-Statements   ##
see this [file](./the_existing_compounds.md).

**Is it a LAW-OF-NATURE that there will NEVER be any other compound-statements in the future?**

## Full Syntax ##
For the full syntax of the related compounds typed_loop(){}, named_loop_up(){},  named_loop_down(){}
have a look at this [file](./the_full_syntax.md).

## Description of the Full Implementation ##
A description of the implementation have can be found
[here](./the_full_implementation.md).

### The Code Examples ###

You find  full C++ header-only implementation of the **Compound-Group "LOOP"**"
[here](./future-cpp-loop/ogis-cpp-loop/include).

There are also *Qt-Creator* and *VisualStudio 2019* **project files** in this
[directory](./future-cpp-loop).

For more matrix-examples ave a look at
[this example](./future-cpp-loop/ogis-cpp-loop.examples/examples/matrix.hpp).



## Discussion ##

One might argue, **loop(){}** is only a plain mapping to a **for(;;){}** statement.

OK, it is all about iterating and it is not a *swiss-army knife for all iterations*.

### Properties of the current implementation  ###

 - the solution *"is ready to rumble"*
 - the solution *is based on the c-preprocessor (cpp) only.*
 - it is a header only solution
 - no changes to any compiler are necessary.
 - it creates a hidden index name using the macro  CPPMACRO_UNIQUE_ID()

Outcomes for ANSI-C
 - Even if it has been designed for Modern C++ it works also with a plain ANSI-C compiler (using long as the type of the index variable)
 - It is implementable using solely the standard c-preprocessor (cpp).


### Advantages: ###

With recent compilers, this is **as fast** as the **regular** **for(;;){}** iteration.

BUT it has these advantages:
 - **READability**:  It reduces C++ source code size and improve its readability.
 - **TEACHability**: it will improve the way to teach C++  especially for a younger audience.
 - **ALGORITHMics**: It allows/leads the developer(s) to notate code that completely does _NOT depend on the iteration index_.
 - **OPTIMIZATION**: It opens the way to enhanced optimizations for upcoming compiler implementations.
 	- by utilizing the *reduced degree of freedom* of the iteration
	- by using fast ALU-register increment operations of *DSP-Architectures*.

### Disadvantages:  ###
- The underlying itarator index <rep> is not really "hidden" and could be "guessed" by a experienced programmer. But this is somehow unlikely.

#### looping plain enum types is insane and does not work ####
This code does NOT  work

	#e.g. MinGW32 has this error: cannot decrement expression of enum type '(anonymous enum at ....)
	enum {RED, GREEN, BLUE} rgb=BLUE;
 	loop(rgb)
	      do_something();


#### Compilation caveat: Problematic use of  tempate arguments **with comma** ####
The preprocessor implemantation will break when using an **argument containing a comma** .
This happens seldomly, e.g. when an complex template expression is used that contains any comma ','.

While this does not work due the comma in the template **std::integral_constant<int, 10>::value**

    auto count = std::integral_constant<int, 10>::value;
    loop(count) do_something();

    loop(std::integral_constant<int, 10>::value)   /// !pwnng compiler error at Kommma (,)
          do_something();

**Embracing** the argument **with regular braces** solves the problem:
This works:

    loop( (std::integral_constant<int, 10>::value) )  
          do_something();

Adding the LOOP-compounds to the core-language would fix this problem, as cpp-preprocessor would not be invoked any longer.


## Remarks ##

### Remarks on Compiler Optimization ###
The new iterative compounds
 - have less degree of freedom
 - and will give room for further enhancements of the compiler optimization.

We will see if:
 - it can lead to SHORTER, COMPACTER machine-code as the iteration is SIMPLER.
 - This will definitely apply for large loops with a tiny loop body.
 - This can reduce the _rate of cache-misses_ dramatically.

### Remarks on Teachingability of  C++ ###
  - ! the UK-Government decided to "force" (childern||pupils) form 4-years on to learn how to programm. !
  - 5th grade (10-years old) pupils **can** cope with the concept of **looping**,  and generating textual outputs via **printing**  something like squares, triangles, etc.
  - But a simple **for(int i=0; i<n; ++i)**  statement will overwhelm them.
   The principle of variables, *types*, their *assignment*,   *conditions* in the form of **boolean expressions** with relations and incrementation is a very hard stuff at that age.

  Suggestion:

  - What about starting to teach C/C++ for pupils as early as possible with: putc(), loop() and going on with variables and assignment.
  - going on to  statements in order to  create textual outputs on the (screen || printer).
  - and later on assigning, and the operations add, subtract, multiply, divide and modulo are enough challenging  at that age.
  - and teaching them later on *conditions* inclusive the  *Boolean Algebra*.
  - and in the *following-years* the full power of C/C++  (functions, for(;;){}, ...)

  What do you think  ?
  - Seen from the Point of View: Year 2020
  - How far COULD the teaching-level for bachelor students in 2034 of Programming (C/C++) for the now 4-year old kindergarden kids be?
  - Compared to nowadays 2020 bachelor students?
  And what would be their favored programming language ?

## Conclusions ##
 - First experts comments say that it is a _stony way_ to get the suggested  core-language _compounds_ will get its way to C/C++.
 - But you can take the occasion and try it out yourself.
 - There is a solution for plain ANSI-C.
 - The issues of READABILITY and TECHABILTY are the main arguments.

Attention: (see  disadvantages)
in the recent preprocessor implementation breaks on arguments containing a comma (like for some  complex template-expressions).
There is a workaround for that.

# References #

 - Teaching programming in the kindergarden and later:
   	- https://www.raspberrypi.org/forums/viewtopic.php?t=762   a news form 2011
 	- https://www.intechopen.com/books/early-childhood-education/evaluating-a-course-for-teaching-advanced-programming-concepts-with-scratch-to-preservice-kindergart
 - Machine Code supported  Loops
 	- TMS320C6x: "Software Pipelined Loops"
       		-  TMS320C64x/C64x+ DSP CPU and Instruction Set ; Chapter 7 Software Pipelined Loop (SPLOOP) Buffer;
		   https://www.ti.com/lit/ug/spru732j/spru732j.pdf
       		-  C64x+ Code savings;
		   http://e2e.ti.com/cfs-file/__key/communityserver-discussions-components-files/343/2746.sploop_5F00_details.pdf
 - Excessive post-operation incrementing
	- ADSP-218x: Data Address Generators
		- https://www.analog.com/media/en/technical-documentation/data-sheets/ADSP-218XN_SERIES.pdf

			
