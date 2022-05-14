#pragma once



/*
/////////////////////////////////////////////////////////////////////////
//////////// LOOP - without PostOps  ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

SYNTAX: loop[_up|_down][_h|_hh]_postops

loop_postops(rep);
loop_up_postops(rep, id);
loop_down_postops(rep, id)

loop_h_postops(rep)
loop_up_h_postops(rep, id);
loop_down_h_postops(rep, id)

loop_hh_postops(rep)
loop_up_hh_postops(rep, id);
loop_down_hh_postops(rep, id)

*/

#ifdef __cpp_has_cpploop
#ifdef __cpp_has_cpploop_postops

#include "cxxloop_prereqs.h"

///
// ... loop block-statement nbrOfRepetitions-times
#define loop_postops(nbrOfRepetitions, ...)        \
  CPPMACRO_LOOP_POSTOPS(FASTEST, nbrOfRepetitions, \
                        CPPMACRO_UNIQUE_ID(__COUNTER__), __VA_ARGS__)

// ... counting up-wards
#define loop_up_postops(nbrOfRepetitions, indexVarName, ...) \
  CPPMACRO_LOOP_POSTOPS(UP, nbrOfRepetitions, indexVarName, __VA_ARGS__)

// ... counting down-wards
#define loop_down_postops(nbrOfRepetitions, indexVarName, ...) \
  CPPMACRO_LOOP_POSTOPS(DOWN, nbrOfRepetitions, indexVarName, __VA_ARGS__)

///////////////////////// CPPMACRO_LOOP__TYPED, ushort
// ... loop block-statement nbrOfRepetitions-times
#define loop_h_postops(nbrOfRepetitions, ...)                         \
  CPPMACRO_LOOP_TYPED_POSTOPS(FASTEST, nbrOfRepetitions,              \
                              CPPMACRO_UNIQUE_ID(__COUNTER__), short, \
                              __VA_ARGS__)

// ... counting up-wards
#define loop_up_h_postops(nbrOfRepetitions, indexVarName, ...)           \
  CPPMACRO_LOOP_TYPED_POSTOPS(UP, nbrOfRepetitions, indexVarName, short, \
                              __VA_ARGS__)

// ... counting down-wards
#define loop_down_h_postops(nbrOfRepetitions, indexVarName, ...)           \
  CPPMACRO_LOOP_TYPED_POSTOPS(DOWN, nbrOfRepetitions, indexVarName, short, \
                              __VA_ARGS__)

///////////////////////// CPPMACRO_LOOP__TYPED, uchar
// ... loop block-statement nbrOfRepetitions-times
#define loop_hh_postops(nbrOfRepetitions, ...)                       \
  CPPMACRO_LOOP_TYPED_POSTOPS(FASTEST, nbrOfRepetitions,             \
                              CPPMACRO_UNIQUE_ID(__COUNTER__), char, \
                              __VA_ARGS__)

// ... counting up-wards
#define loop_up_hh_postops(nbrOfRepetitions, indexVarName, ...)         \
  CPPMACRO_LOOP_TYPED_POSTOPS(UP, nbrOfRepetitions, indexVarName, char, \
                              __VA_ARGS__)

// ... counting down-wards
#define loop_down_hh_postops(nbrOfRepetitions, indexVarName, ...)         \
  CPPMACRO_LOOP_TYPED_POSTOPS(DOWN, nbrOfRepetitions, indexVarName, char, \
                              __VA_ARGS__)

#endif
#endif
