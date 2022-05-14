## Full Syntax of the Compound-Group LOOP ##

This is the syntax of the Compound-Group LOOP

To be honest, this is not thefull story of the syntax some more twaeks ware needed to use  a indexVar-type,
which is not *const*, *volatile*, *reference* or *rvalue*

- see also the [Implementation Details](/the_full_implementation.md)
- see also the [Example Directory](/cxxloop.examples/)

### Shortcuts: ###
	{}	a single <statement> or a  <statement-block>  after the compound statement
	rep    	the <count> of targeted repetitions (usually a value of integral-type) ;
	id     the name of theindexed iteration variable, if not hidden.
	, ...) 	an optional comma separated list of post-operations (expressions)

### Basic SYNTAX of the Loop Compound-Group: ###
These compounds iterate ("loop") the trailing block "{}" "rep" times.

	/////// below <hidden> is an id with a secret, unique ID created using  a the cpp-macro CPPMACRO_UNIQUE_ID()
	
	// the  hidden_loop does NOT change <rep> and uses a hidden, secret unique-index variable.
	loop(rep){}	                 // for(auto hidden=rep; hidden-- ; ++hidden){}   

	// a typed-loop has a type-constain, but has a hidden index variable, too.
	loop_h(rep){} 	        // for(short hiddden=rep, hidden-->0 ; ){}   
	loop_hh(rep){} 	        // for(char hiddden=rep, hidden-->0 ; ){}   

	// the loop_up/down() iterations are useful, when access to the index variable is needed.
	
	// the named index variable "name" is counting upwards from 0 to rep-1.
	loop_up(rep, id){} 	 // for(auto    id=0; id<rep;  id++){}   // looping up  
	loop_up_h(rep, id){} 	 // for(short 	id=0; id<rep ; id++){}   // looping with indexCar type "short"
	loop_up_hh(rep, id){} 	 // for(char 	id=0; id<rep ; id++){}   // looping with indexCar type "char"

	// the named  index variable "name" is  counting downwards, from rep -1 to 0
	loop_down(rep, id){} 	 // for(auto    id=rep; id--; ){}     	// looping up 
	loop_down_h(rep, id){} 	 // for(short 	id=rep; id--; ){}   	// looping with indexCar type "short"
	loop_down_hh(rep, id){}  // for(char 	id=rep; id--; ){}   	// looping with indexxCar type "char"
	
The argument _rep_ is _not_ changed an in best case should have integral-type:
Any float or enum is not allowed for rep.
Compiler can take advantage when index vars <rep> are of integal-type and fit into ALU-registers.
for anobymous loop-indexVars is an id with a secret, unique ID created using  a the cpp-macro CPPMACRO_UNIQUE_ID(__COUNTER__)

### SYNTAX WITH POST-OPERATIONS ###
The use of post-operations (C-expressions is supported via usage of  the suffix "_postops", too. 
	
	loop_**postops**(rep, postop1, ... ){}	                    

	// a typed-loop has a type-constain, but has a hidden index variable, too.
	loop_h_postops(rep, postop1, ... ){}	                    
	loop_hh_postops(rep, postop1, ... ){}	                    

	// the loop_up/down() iterations are useful, when access to the index variable is needed.
	
	// the named index variable "id" is counting upwards from 0 to rep-1.
	loop_up_postops(rep, postop1, ... ){}	                    	
	loop_up_h_postops(rep, id, postop1, ... ){}
	loop_up_hh_postops(rep, id, postop1, ... ){}

	// the named  index variable "id" is  counting downwards, from rep -1 to 0
	loop_down_postops(rep, postop1, ... ){}	                    	
	loop_down_h_postops(rep, id, postop1, ... ){}
	loop_down_hh_postops(rep, id, postop1, ... ){}
	
# FORMAL Spezification # 
	
## Using a FORMAL Syntax like ##	

	 <nbrOfRepetittions>	the count of iterations performed 

	 [, <expression>]...	optional comma separated list  of expressions
	 <indexType>		the type of the indexVariable
	 <indexVarName>		the Identifier (name) of the Index Variable

	 <expression>		ay C++ expression
	 <statement>		one of 
		- an expression-statement with trailing semicolon like sinx(x)/x;
		- a compound-statement  with curly braces  like { [ <statement> ]...}
		- an iterative-compound-statments like
			- for(<initialization>; <expression>; <post-expression>) <statement>
			- for(<range-init> : <container> <statement>
			- while(<expression>) <statement>
			- do <statement> while(<expression>);
		- a conditional-compound-statement like 
			- if(<expression>) <statement> [ else <statement>] 
			- switch(<expression> { <statement>}
		- extended conditional-compound-statement (since C++17  if(), switch() allow an extra, scoped initialization)
			- if(<initialization>; expression>) <statement> [ else <statement>] 
			- switch(<initialization>; <expression> { <statement>}

