#pragma once

#include "cpploop.h"


#define named_loop_(varName, nbrOfRepetitions, ...)              \
    NAMED_LOOP_NTIMES_(varName, nbrOfRepetitions,__VA_ARGS__)

#define typed_loop_(type, nbrOfRepetitions,...)  	\
    TYPED_LOOP_NTIMES_(type, nbrOfRepetitions, __VA_ARGS__)

#define named_loop(name, nbrOfRepetitions)      named_loop_(name, nbrOfRepetitions)
#define typed_loop(type, nbrOfRepetitions)      typed_loop_(type, nbrOfRepetitions)

#define loop(nbrOfRepetitions)                  typed_loop(auto, nbrOfRepetitions)
#define loop_(nbrOfRepetitions, ...)            typed_loop_(auto, nbrOfRepetitions, __VA_ARGS__)





