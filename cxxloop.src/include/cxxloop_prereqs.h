#pragma once

#if !defined __cplusplus
#error("the compound group LOOP will not work with C99 or later")
#endif

#ifndef __cpp_has_cpploop
#define __cpp_has_cpploop
#ifndef __cpp_has_cpploop_postops
#define __cpp_has_cpploop_postops
#endif
#endif

///////////////////////////////////////////////////////////////////////////
//////////// PRE-requisites   /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// cpp-macro to generate an unique ID
#ifndef CPPMACRO_UNIQUE_ID
///#define CPPMACRO_UNIQUE_ID
/// CPPMACRO_UNIQUE_ID_LINE##__LINE__##COUNTER##__COUNTER__

#define CPPMACRO_XCAT2(a, b) a##b
#define CPPMACRO_UNIQUE_ID(counter) CPPMACRO_XCAT2(UNIQUE_ID_LOOP_, counter)
#endif

/////////////////////////////////////////////////////////////////////77
// cpp macro to use type of varname and remove const
#include <type_traits>

namespace ogis {

// strip off any of  const, volatile or references (T&, T&&)
/*template<typename Type>
using remove_cvref = typename std::remove_reference<\
    typename std::remove_const<Type>::type>::type;
*/

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
#endif
