

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
