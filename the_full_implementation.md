## Full Implementation Details of the Compound-Group "LOOP" ##

### Compiler / Cpp-Preprocessor   Requirements  ###

	 
 - full compatibilty with C++11
 
 	#pragma once
	, ... )			indicates that variadic arguments are at end of MACRO-DEFIITION
	__VA_ARGS__		unfold to the optional variadic argument(s), used for the "post-comparison" expressions.

- additional requirements

	__COUNTER__		counter required by CPPMACRO_UNIQUE_ID()


This "core-language extension" can be implemented solely using the cpp-preprocessor.

### Implementation for C / C++11 or later ###

cxxloop_preqs.h

	// cpp-macro to generate an unique ID
	#ifndef CPPMACRO_UNIQUE_ID
	#define CPPMACRO_XCAT2(a, b) a##b
	#define CPPMACRO_UNIQUE_ID(counter) CPPMACRO_XCAT2(UNIQUE_ID_LOOP_, counter)
	#endif

	/////////////////////////////////////////////////////////////////////77
	// cpp macro to use type of varname and remove const
	#include <type_traits>

	namespace ogis {

	// strip off any of  const, volatile or references (T&, T&&)
	template <typename Type>
	using remove_cvref_t =
	    typename std::remove_cv<typename std::remove_reference<Type>::type>::type;

	template <typename BaseType, typename TgtType>
	using copy_unsigendness_conditional_t =
	    typename std::conditional<std::is_unsigned<BaseType>::value,
				      typename std::make_unsigned<TgtType>::type,
				      TgtType>::type;

	template <typename BaseType>
	using copy_unsigendness_to_char_t =
	    copy_unsigendness_conditional_t<BaseType, char>;

	template <typename BaseType>
	using copy_unsigendness_to_short_t =
	    copy_unsigendness_conditional_t<BaseType, short>;

	}  // namespace ogis
	// //:CPPMACRO_NTIMES_*

	#ifdef __cpp_has_cpploop
	// //:CPPMACRO_NTIMES_[UP|DOWN|FASTEST]
	// cpp-macro to count upwards (from 0 to nbrOfRepetitions-1)
	#define CPPMACRO_NTIMES_UP(indexType, nbrOfRepetitions, indexVarName) \
	  for (indexType indexVarName = static_cast<indexType>(0);            \
	       indexVarName < nbrOfRepetitions; indexVarName++)

	// cpp-macro to count downwards (from nbrOfRepetitions-1 to 0)
	#define CPPMACRO_NTIMES_DOWN(indexType, nbrOfRepetitions, indexVarName)   \
	  for (indexType indexVarName = static_cast<indexType>(nbrOfRepetitions); \
	       indexVarName-- > 0;)

	#define CPPMACRO_NTIMES_FASTEST(indexType, nbrOfRepetitions, indexVarName) \
	  for (indexType indexVarName = static_cast<indexType>(nbrOfRepetitions);  \
	       indexVarName-- > 0;)


	//////////////////////////////
	// //:CPPMACRO_LOOP[_TYPED]_POSTOPS
	#define CPPMACRO_LOOP(direction, nbrOfRepetitions, indexVarName)   \
	  CPPMACRO_NTIMES_##direction(                                     \
	      typename ogis::remove_cvref_t<decltype((nbrOfRepetitions))>, \
	      nbrOfRepetitions, indexVarName)

	#define CPPMACRO_LOOP_TYPED(direction, nbrOfRepetitions, indexVarName, type) \
	  CPPMACRO_NTIMES_##direction(                                               \
	      ogis::copy_unsigendness_to_##type##_t<                                 \
		  typename ogis::remove_cvref_t<decltype((nbrOfRepetitions))>>,      \
	      nbrOfRepetitions, indexVarName)

	//////// POSTOPS
	//////////////////////////////
	#ifdef __cpp_has_cpploop_postops
	// //:CPPMACRO_NTIMES_[UP|DOWN|FASTEST]_POSTOPS
	// cpp-macro to count upwards (from 0 to nbrOfRepetitions-1)
	#define CPPMACRO_NTIMES_UP_POSTOPS(indexType, nbrOfRepetitions, indexVarName, \
					   ...)                                       \
	  for (indexType indexVarName = static_cast<indexType>(0);                    \
	       indexVarName < nbrOfRepetitions; indexVarName++, __VA_ARGS__)

	// cpp-macro to count downwards (from nbrOfRepetitions-1 to 0)
	#define CPPMACRO_NTIMES_DOWN_POSTOPS(indexType, nbrOfRepetitions,         \
					     indexVarName, ...)                   \
	  for (indexType indexVarName = static_cast<indexType>(nbrOfRepetitions); \
	       indexVarName-- > 0; __VA_ARGS__)

	#define CPPMACRO_NTIMES_FASTEST_POSTOPS(indexType, nbrOfRepetitions,      \
						indexVarName, ...)                \
	  for (indexType indexVarName = static_cast<indexType>(nbrOfRepetitions); \
	       indexVarName-- > 0; __VA_ARGS__)

	// //:CPPMACRO_LOOP[_TYPED]_POSTOPS
	#define CPPMACRO_LOOP_POSTOPS(direction, nbrOfRepetitions, indexVarName, ...) \
	  CPPMACRO_NTIMES_##direction##_POSTOPS(                                      \
	      typename ogis::remove_cvref_t<decltype((nbrOfRepetitions))>,            \
	      nbrOfRepetitions, indexVarName, __VA_ARGS__)

	#define CPPMACRO_LOOP_TYPED_POSTOPS(direction, nbrOfRepetitions, indexVarName, \
					    type, ...)                                 \
	  CPPMACRO_NTIMES_##direction##_POSTOPS(                                       \
	      ogis::copy_unsigendness_to_##type##_t<                                   \
		  typename ogis::remove_cvref_t<decltype((nbrOfRepetitions))>>,        \
	      nbrOfRepetitions, indexVarName, __VA_ARGS__)

	#endif
	
cxxloop.h
 
 	#pragma once

	#include <type_traits>

	#ifdef __cpp_has_cpploop

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

	/ ... loop block-statement nbrOfRepetitions-times
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

cxxloop_postops.h

	/********************
	loop[_up|_down][_h|_hh]_postops

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
	///////////////////////////////////////////////////////////////////////////
	//////////// LOOP - without PostOps  ////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////

	///////////////// //CPPMACRO_LOOP
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
