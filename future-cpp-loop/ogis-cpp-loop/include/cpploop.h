#pragma once

///////// the loop-compound statements

#ifndef CPPMACRO_UNIQUE_ID
#define CPPMACRO_UNIQUE_ID() CPPMACRO_UNIQUE_##ID_##LINE##__LINE__##__COUNTER__
#endif

// prerequisites
///////// counting up
#define CPPMACRO_NTIMES_UP(type, varName, reps, ...)                           \
  for (type varName = 0; varName < reps; varName++, ##__VA_ARGS__)

///////// counting down
#define CPPMACRO_NTIMES_DOWN(indexType, indexVarName, nbrOfRepetitions, ...)   \
  for (indexType indexVarName = nbrOfRepetitions; indexVarName-- > 0;          \
       __VA_ARGS__)

#if defined __cplusplus ///////////////////////////////////////////

#include <type_traits>
#define CPP_DECLTYPE(varname)                                                  \
  typename std::remove_const<decltype(varname)>::type

#else

// as "C" cannot detect the type of a varname,
// this can lead to problems with unsigned varname(s)
#define CPP_DECLTYPE(varname) int

#endif

#define typed_loop(indexType, nbrOfRepetitions, ...)                           \
  CPPMACRO_NTIMES_UP(indexType, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions,        \
                     ##__VA_ARGS__)

#define loop(nbrOfRepetitions, ...)                                            \
  CPPMACRO_NTIMES_UP(CPP_DECLTYPE(nbrOfRepetitions), CPPMACRO_UNIQUE_ID(),     \
                     nbrOfRepetitions, ##__VA_ARGS__)

#define named_loop_up(indexVarName, nbrOfRepetitions, ...)                     \
  CPPMACRO_NTIMES_UP(CPP_DECLTYPE(nbrOfRepetitions), indexVarName,             \
                     nbrOfRepetitions, ##__VA_ARGS__)

#define named_loop_down(indexVarName, nbrOfRepetitions, ...)                   \
  CPPMACRO_NTIMES_DOWN(CPP_DECLTYPE(nbrOfRepetitions), indexVarName,           \
                       nbrOfRepetitions, ##__VA_ARGS__)

// REMARK: looping down from nbrOfRepetitions-1 down to 0 with a final
// indexVarName of -1. It requires a signed indexType comparison and in order to
// prevent an unsigned underflow depends on signedness. Unsigned types (size_t)
// will lead to underflow and wraps around to something like UINT_MAX.
