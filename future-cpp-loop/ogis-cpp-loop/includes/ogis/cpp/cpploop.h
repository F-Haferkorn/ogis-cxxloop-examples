#pragma once

#include "cppuniqueid.h"


#if defined CPPCOMPOUND_LOOP_USE_GREATER_THAN_COMPARISON

#define CPPMACRO_COUNTING_DOWN_FORLOOP(type, varName, nbrOfRepetitions, ...) \
    for (type varName = nbrOfRepetitions; varName-->0; __VA_ARGS__)

#else

#define CPPMACRO_COUNTING_DOWN_FORLOOP(type, varName, nbrOfRepetitions, ...) \
    for (type varName = nbrOfRepetitions; varName--; __VA_ARGS__)

#endif


#define TYPED_LOOP_NTIMES_(type, nbrOfRepetitions, ...)  	\
    CPPMACRO_COUNTING_DOWN_FORLOOP(type, CPPMACRO_UNIQUE_ID(REPEAT_INDEX), nbrOfRepetitions, __VA_ARGS__)

#define NAMED_LOOP_NTIMES_(varName, nbrOfRepetitions, ...)  \
    CPPMACRO_COUNTING_DOWN_FORLOOP(auto, varName,  nbrOfRepetitions, __VA_ARGS__)

