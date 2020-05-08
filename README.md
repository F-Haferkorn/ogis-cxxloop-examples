# ogis-modern-cxx-future-cpp #
This GITHUB-REPO is a testbed for a special kind of Modern C++ CORE LANGUAGE  extension.

## Motivation ##
Herein I present a testbed for  COMPOUND stamtenets  related to ITERATION.

in C/C++ there are the well known compound statements.
 - if(<cond>) {} else{}
 - while(<cond>) {}
 - do {} while(<cond>);
 - for(<decl>; <cond>;<expr>) {}
 - switch(<expr>) { case: ... default: ... }

with the related staments
 - break
 - continue.
 
 These compounds have not been changed since the ancient time oc ANSI-C.
 
 +----------------------------------------------------------------
 
But was that really all for C++?

	One might partly agreed that a 

 	try{
 	} catch(...)   {}
 
	"block" is somehow a compound stament, too.

## USED Shortcuts: ##
	{}			the <statement> || <statement-block>  after the compound statement
	rep    			the <count> of targeted repetitions (a unsigned integral value) ;
	type			the <type> of the (hiddden) iteration variable
	name			the <name> of the iteration variable
	, ...) 			an optional comma separated list of post-operations (these are expressions)
		
## BASIC_SYNTAX: ##	
all compounds  loop the trailing block{} _rep times_ and do NOT change _rep_

 	// a hidden_loop that NOT canging <rep> (it is auto typed and the varname is hidden).	// see CPPMACRO_UNIQUE_ID()
	HIDDEN_LOOP(rep){}			// for(auto hidden=rep; hidden-- >0; ++hidden){}   
	
	// a hidden_loop, with a type constained  index var.
	TYPED_LOOP(type,rep){} 			// for(type hidden=rep; hidden-- >0; ++hidden){}   
	
	// loop <block> rep times, with given index var namem counting downwards, until name==0 is reached.
	NAMED_LOOP(name,rep){} 			 // for(auto name=rep; hidden-- >0; ++hidden){}     
	
## EXTENDED_SYNTAX ##
	// the loop compound statements may have additional post-iteration opertions
	
	HIDDEN_LOOP(rep){}			// loop <block> rep times with no post operation.
	HIDDEN_LOOP(rep, op1 ){}		// loop <block> rep times with 1 post-operation op1.
	HIDDEN_LOOP(rep, op1, op2){}		// loop <block> rep times with 2 postoperations op1, op2  (more are optional).

	TYPED_LOOP(type,rep, op1, ...)){}	// hidden loop with type constraint on the index variable
	NAMED_LOOP(name, cnt, op1, op2, ...){}   // loop with type "auto" a named index variable.	

# IMPLEMENTATION: #
    ...
Properties of the solution 
	- the current solution is based on the c--preprocessor (cpp) only.	
	- it is a header only solution
	
Creating the hidden index name  
	CPPMACRO_UNIQUE_ID()   generated an unqiue for the hidden index
	
Outcomes for ANSI-C
	- Even if it has been designed for Modern C++ it works also with a plain ANSI-C compiler.
	- It is implementable using the standard 'cpp' c--preprocessor, only,
	
# UseCases #
### matrix_copy with stride ###
	template<typename TPtr, typename TRow, typename TCol, typename TStride >
	TPtr matrix_copy( TPtr tgt, TPtr src, TRow nbofRows,TCol nbofColums, TStride stride)
        {
                loop(nbofRows,  tgt+=stride, src+=stride)  // apply strid eafter each row to tht and src
                        loop(nbofColumms)
                             	*tgt++ = *src++;
                return tgt;
        }

# DISCUSSION #
 One might argue, loop(){} is is only a plain mapping to a for(;;){} statement.
 
 OK, it is all about iterating and it is not a swiss-army knife for all iterations.
 BUT:
 - READability:  It can reduce C/C++ source code size and improve its readability.
 - TEACHability: it will improve the way to teach C/C++  especially for a younger audiencce.
 - ALGORITHMics: It allows/lead  the developer to notate code that completely does _NOT depend on the iteration index_.
 - OPTIMIZATION: It opens the way to enhanced optimizations for new compiler implementations.

REMMARK on TEACHing C/C++: As far as  know:
  - !!! the UK-Government decided to "force" (childern||pupils) form 4-years on to learn how to programm. !!!
  - 2nd grade (7years old) pupils are able to cope wit the concept of PRINTING, LOOPING and generating textual/graphical outputs.
  - But CONDITIONS with the need of using boolean Expressions like AND, OR, NOT are a very hard stuff at  that age. 
  - What about starting teaching C++ with:  putc(), loop().
  - Forming them to statements to creating textuual outputs on the (screen || printer).
  - Assigning, and the operations add, subtract, multiply, divide and modulo are enough challenging  at that age.
  - and teaching in then next, the 3rd grade: , functions, agrgumnet passing etc. Conditions (Boolean Algebra) 
  
  What do you think  ?
   - How far COULD the teaching-level 
   - in the 1st university lecture of Programming (C/C++) 
   - for the the now 4-year old kindergarden children
   - be 2034?
   - Coared to this years bachelor students?
  And what would be their favored programming language ???
    
REMARK on OPTIMIZAtion:
The new iterative coumpounds 
	- have less degree of freedom
	- and will give room for new way of enhancing the compiler optimization.
We will see if:
 	- it can lead to SHORTER,, COMPACTER machine-code as the itearation is SIMPLER.
	- This can reduce the _rate of cache-misses_ dramatically.

UNINTENDED-USAGE:
	YES, in the presented cpp-implementation,
	the underlying itarator index <rep> is not really "hidden" and could be "guessed" by a experienced programmer.

## OPEN Issues ##
	- However it stil has to be proven, that there are _realworld USE-CASES_,
	- where the praised "unbeatable" _compiler_ 
	- can be driven to make better/shorer/faster
	- in cases  the  described compounds can ba applied.
	- compared to the now-a-days solution for(int i=0; i<rep; ++i){}
  
# CONCLUSion:#
	First comments say that it is is a _stony way_ to get the suggested  core-language _compounds_ wil get its way to C/C++. 
	But You can take the occasion and try it out yourself. 
	It works. Even for plain Ansi-C See the *IMPLEMENTATION* section.

## ADVANCED Reading: ##
	- Teaching programming in the Kindergarden and later:
 	https://www.raspberrypi.org/forums/viewtopic.php?t=762   a news form 2011 
 	https://www.intechopen.com/books/early-childhood-education/evaluating-a-course-for-teaching-advanced-programming-concepts-with-scratch-to-preservice-kindergart


 
	
