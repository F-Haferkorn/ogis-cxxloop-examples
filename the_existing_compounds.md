## About Existing Compound-Statements   ##

### ANSI-C Compound-Statements from the very beginning ###
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

### Early C++ Compound-Statements ##

There is a the try-catch block compound stament, too.

  	try{ /* throw ....*/ } catch(...)   {}

### New Compound-Statements in C++17 ###

	- if(<declaration>;  <condition>) {} else{}               // if-init
	- switch(<declaration>;  <index>) { case.... default: }   // switch-init

**Is it a LAW-OF-NATURE that there will NEVER be any other compound-statments in the future?**
