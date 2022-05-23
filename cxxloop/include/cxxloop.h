#pragma once

#include <type_traits>

#include "cxxloop_prereqs.h"
/**** syntax:   loop[_up|_down][_h|_hh]_postops(...){};

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
  CPPMACRO_LOOP(NTIMES_FASTEST, nbrOfRepetitions, CPPMACRO_UNIQUE_ID(__COUNTER__))

// ... counting up-wards
#define loop_up(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP(NTIMES_UP, nbrOfRepetitions, indexVarName)

// ... counting down-wards
#define loop_down(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP(NTIMES_DOWN, nbrOfRepetitions, indexVarName)

///////////////////////// CPPMACRO_LOOP__TYPED, ushort
// ... loop block-statement nbrOfRepetitions-times
#define loop_h(nbrOfRepetitions)                 \
  CPPMACRO_LOOP_TYPED(NTIMES_FASTEST, nbrOfRepetitions, \
                      CPPMACRO_UNIQUE_ID(__COUNTER__), short)

// ... counting up-wards
#define loop_up_h(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP_TYPED(NTIMES_UP, nbrOfRepetitions, indexVarName, short)

// ... counting down-wards
#define loop_down_h(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP_TYPED(NTIMES_DOWN, nbrOfRepetitions, indexVarName, short)

///////////////////////// CPPMACRO_LOOP__TYPED, uchar
// ... loop block-statement nbrOfRepetitions-times
#define loop_hh(nbrOfRepetitions)                \
  CPPMACRO_LOOP_TYPED(NTIMES_FASTEST, nbrOfRepetitions, \
                      CPPMACRO_UNIQUE_ID(__COUNTER__), char)

// ... counting up-wards
#define loop_up_hh(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP_TYPED(NTIMES_UP, nbrOfRepetitions, indexVarName, char)

// ... counting down-wards
#define loop_down_hh(nbrOfRepetitions, indexVarName) \
  CPPMACRO_LOOP_TYPED(NTIMES_DOWN, nbrOfRepetitions, indexVarName, char)

#endif

#if defined __cpp_has_cpploop_slice
#define loop_slice( start, size, stride, indexVarName) \
  CPPMACRO_SLICED(int , start, size, stride, indexVarName)

#define loop_slice_postops( start, size, stride, indexVarName, ...) \
   CPPMACRO_SLICED_POSTOPS(int , start, size, stride, indexVarName, __VA_ARGS__)

#endif
