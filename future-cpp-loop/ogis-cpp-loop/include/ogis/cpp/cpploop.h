#pragma once

#include "cppuniqueid.h"

// count-down: inverse  loop
#define CPPMACRO_NTIMES_COUNT_UP(type, varName, nbrOfRepetitions, ...) \
    for (type varName = 0; varName<nbrOfRepetitions;varName++, ##__VA_ARGS__)

// regular loop: counting-up
#define CPPMACRO_NTIMES_COUNT_DOWN(type, varName, nbrOfRepetitions, ...) \
    for (type varName = nbrOfRepetitions-1;varName>=0; varName--, ##__VA_ARGS__)

/// choose the fatest on your machine
#define CPPMACRO_NTIMES(type, varName, nbrOfRepetitions, ...) \
    for (type varName = 0; varName++<nbrOfRepetitions; __VA_ARGS__)

//#define loop(nbrOfRepetitions)  CPPMACRO_NTIMES(auto, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions)
#define loop(nbrOfRepetitions, ...)                 CPPMACRO_NTIMES(auto, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)
#define typed_loop(type, nbrOfRepetitions, ...)     CPPMACRO_NTIMES(type, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)
#define named_loop_up(varName, nbrOfRepetitions, ...)  CPPMACRO_NTIMES_COUNT_UP(auto, varName, nbrOfRepetitions, ##__VA_ARGS__)
#define named_loop_down(varName, nbrOfRepetitions, ...)  CPPMACRO_NTIMES_COUNT_DOWN(auto, varName, nbrOfRepetitions, ##__VA_ARGS__)

