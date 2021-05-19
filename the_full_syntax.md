## Full Syntax of the Compound-Group LOOP ##

This is the full syntax of the Compound-Group LOOP

- see also the [Implementation Details](/the_full_implementation.md)
- see also the [Example Directory](/future-cpp-loop/ogis-cpp-loop.examples/examples)

### Shortcuts: ###
	{}	a single <statement> or a  <statement-block>  after the compound statement
	rep    	the <count> of targeted repetitions (usually a value of integral-type) ;
	type	the <type> of the (hiddden) iteration variable
	name	the <name> of the iteration variable
	, ...) 	an optional comma separated list of post-operations (expressions)

### Basic SYNTAX of the Loop Compound-Group: ###
These compounds iterate ("loop") the trailing block "{}" "rep" times

	/////// below <hidden> is an id with a secret, unique ID created using  a the cpp-macro CPPMACRO_UNIQUE_ID()
	
	// the  hidden_loop does NOT change <rep> and uses a hidden, secret unique-index variable.
	loop(rep){}	                 // for(auto hidden=rep; hidden-- ; ++hidden){}   

	// a typed-loop has a type-constain, but has a hidden index variable, too.
	typed_loop(type,rep){} 	        // for(type hidden=rep; hidden-- ; ++hidden){}   


	// the named_loops_...() are useful, when access to the index variable is needed.
	// the named index variable "name" is counting upwards from 0 to rep-1.
	named_loop_up(name,rep){} 	 // for(auto name=0; name<rep; ++name){}     

	// the named  index variable "name" is  counting downwards, from rep -1 to 0
	named_loop_down(name,rep){} 	 // for(auto name=rep-1; name--; ++name){}     

The argument _rep_ is _not_ changed an in best case should have integral-type:
Any float or enum is not allowed for rep.
Compiler can take advantage when index vars <rep> are of integal-type and fit into ALU-registers.

### EXTENDED_SYNTAX ###
	// each of the above the loop compound statements
	// can be extened by any number of post-iteration operations.

	// loop <block> rep times
	loop(rep){}		

	// loop <block> rep times with 1 post-operation op1.
	loop(rep, op1 ){}

	// loop <block> rep times with 2 postoperations op1, op2  (more are optional).
	loop(rep, op1, op2){}
	
	// all of them may contain trailing post-expressions
	typed_loop(type,rep, op1, ...)){}               // hidden loop with <type> constraint on the index variable
	named_loop_up(name, cnt, op1, op2, ...){}       // loop upwards with type "auto" a named index variable .
	named_loop_down(name, cnt, op1, op2, ...){}     // loop deonwards with type "auto" a named index variable.
	
## using the  FORMAL Syntax ##

 - <nbrOfRepetittions>	the count of iterations performed 
 
 - [, <expression>]...	optional comma separated list  of expressions
 - <indexType>		the type of the indexVariable

 - <expression>		ay C++ expression
 - <statement>		one of 
	- an expression-statement with trailing semicolon like "sinx(x)/x;"
	- a compound-statement  with curly braces  like "\{ \[ \<statement>\ \]... \}"
	- a conditional-compound-statement like 
		- if(\<expression\>) \<statement\>
		- if(\<expression\>) \<statement\> else \<statement\>
		- switch(\<expression\>\{ \<statement\>\}
	- an iterative-compound-statments like
		- for(\<initialization\>; <\expression\>; \<post-expression\>) \<statement\>
		- for(<range-init>:<container> <statement>
		- while(<expression>) <statement>
		- do <statement> while(<expression>);
	
	
since c++17 if(), switch() may have an extra, scoped initialization

## the Compound-Group LOOP is specified as:	
	
	loop(<nbrOfRepetions> [, <expression>]...) <statement>
	typed_loop(<indexType>, <nbrOfRepetions> [, <expression>]...) <statement>
	named_loop_up(<indexVarName>, <nbrOfRepetions>[, <expression>]...) <statement>
	named_loop_down(<indexVarName>, <nbrOfRepetions> [, <expression>]...) <statement>
