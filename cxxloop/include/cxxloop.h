#pragma once

#include <type_traits>

#ifndef __cpp_has_cpploop
#define __cpp_has_cpploop

#ifndef __cpp_has_cpploop_postops
#define __cpp_has_cpploop_postops
#endif

#endif

#include "cxxloop_prereqs.h"
/**** syntax:   loop[_up|_down][_h|_hh]_postops(..){};

loop(rep){}
loop_up(rep, id){}
loop_down(rep, id){}

loop_h(rep)
loop_up_h(rep, id){}
loop_down_h(rep, id){}

loop_hh(rep){}
loop_up_hh(rep, id){}
loop_down_hh(rep, id){}

*/
///////////////////////////////////////////////////////////////////////////
//////////// LOOP - without PostOps  ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

#ifdef __cpp_has_cpploop

///////////////// //CPPMACRO_LOOP
///
// ... loop block-statement nbrOfRepetitions-times
#define loop(nbrOfRepetitions) \
  CPPMACRO_LOOP(FASTEST, nbrOfRepetitions, CPPMACRO_UNIQUE_ID(__COUNTER__))

// ... counting up-wards
#define loop_up(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP(UP, nbrOfRepetitions, indexVarName)

// ... counting down-wards
#define loop_down(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP(DOWN, nbrOfRepetitions, indexVarName)

///////////////////////// CPPMACRO_LOOP__TYPED, ushort
// ... loop block-statement nbrOfRepetitions-times
#define loop_h(nbrOfRepetitions)                 \
  CPPMACRO_LOOP_TYPED(FASTEST, nbrOfRepetitions, \
                      CPPMACRO_UNIQUE_ID(__COUNTER__), short)

// ... counting up-wards
#define loop_up_h(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP_TYPED(UP, nbrOfRepetitions, indexVarName, short)

// ... counting down-wards
#define loop_down_h(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP_TYPED(DOWN, nbrOfRepetitions, indexVarName, short)

///////////////////////// CPPMACRO_LOOP__TYPED, uchar
// ... loop block-statement nbrOfRepetitions-times
#define loop_hh(nbrOfRepetitions)                \
  CPPMACRO_LOOP_TYPED(FASTEST, nbrOfRepetitions, \
                      CPPMACRO_UNIQUE_ID(__COUNTER__), char)

// ... counting up-wards
#define loop_up_hh(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP_TYPED(UP, nbrOfRepetitions, indexVarName, char)

// ... counting down-wards
#define loop_down_hh(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP_TYPED(DOWN, nbrOfRepetitions, indexVarName, char)

#endif
