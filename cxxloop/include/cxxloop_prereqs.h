#pragma once

#ifndef __cpp_has_cpploop
#define __cpp_has_cpploop
#define __cpp_has_cpploop_postops
#define __cpp_has_cpploop_slice
#endif

#ifdef __cpp_has_cpploop
///////////////////////////////////////////////////////////////////////////
//////////// PRE-requisites   /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

#if !defined __cplusplus
#error("the compound group LOOP will not work with C99 or later")
#endif

// cpp-macro to generate an unique ID
#ifndef CPPMACRO_UNIQUE_ID
#define CPPMACRO_XCAT2(a, b) a##b
#define CPPMACRO_UNIQUE_ID(counter) CPPMACRO_XCAT2(UNIQUE_ID_LOOP_, counter)
#endif

/////////////////////////////////////////////////////////////////////77
// cpp macro to use type of varname and remove const
#include <type_traits>

namespace ogis {

template <typename Type>
using remove_cvref_t =
    typename std::remove_cv<typename std::remove_reference<Type>::type>::type;

template <typename BaseType, typename TgtType>
using copy_signedness_from_basetype_t =
    typename std::conditional<std::is_unsigned<BaseType>::value,
                              typename std::make_unsigned<TgtType>::type,
                              TgtType>::type;

template <typename BaseType>
using copy_unsigendness_to_char_t =
    copy_signedness_from_basetype_t<BaseType, char>;

template <typename BaseType>
using copy_unsigendness_to_short_t =
    copy_signedness_from_basetype_t<BaseType, short>;

}  // namespace ogis
// //:CPPMACRO_NTIMES_*

//////////////////////////////
//////// NTIMES
//////////////////////////////

// //:CPPMACRO_NTIMES_[UP|DOWN|FASTEST]
// cpp-macro to count upwards (from 0 to nbrOfRepetitions-1)
#define CPPMACRO_NTIMES_UP(indexType, nbrOfRepetitions, indexVarName) \
  for (indexType indexVarName = static_cast<indexType>(0);            \
       indexVarName < static_cast<indexType>(nbrOfRepetitions); indexVarName++)

// cpp-macro to count downwards (from nbrOfRepetitions-1 to 0)
#define CPPMACRO_NTIMES_DOWN(indexType, nbrOfRepetitions, indexVarName)   \
  for (indexType indexVarName = static_cast<indexType>(nbrOfRepetitions); \
       indexVarName-- != 0;)

// cpp-macro to count in any direction (preferring fastetst counting downwards)
#define CPPMACRO_NTIMES_FASTEST(indexType, nbrOfRepetitions, indexVarName) \
    CPPMACRO_NTIMES_DOWN(indexType, nbrOfRepetitions, indexVarName)

//////////////////////////////
// //:CPPMACRO_LOOP[_TYPED]_POSTOPS
#define CPPMACRO_LOOP(TAG, nbrOfRepetitions, indexVarName)                    \
  CPPMACRO_##TAG(typename ogis::remove_cvref_t<decltype((nbrOfRepetitions))>, \
                 nbrOfRepetitions, indexVarName)

#define CPPMACRO_LOOP_TYPED(TAG, nbrOfRepetitions, indexVarName, type)  \
  CPPMACRO_##TAG(                                                       \
      typename ogis::copy_unsigendness_to_##type##_t<                            \
          typename ogis::remove_cvref_t<decltype((nbrOfRepetitions))>>, \
      nbrOfRepetitions, indexVarName)

//////////////////////////////
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
#define CPPMACRO_LOOP_POSTOPS(TAG, nbrOfRepetitions, indexVarName, ...) \
  CPPMACRO_##TAG##_POSTOPS(                                             \
      typename ogis::remove_cvref_t<decltype((nbrOfRepetitions))>,      \
      nbrOfRepetitions, indexVarName, __VA_ARGS__)

#define CPPMACRO_LOOP_TYPED_POSTOPS(TAG, nbrOfRepetitions, indexVarName, type, \
                                    ...)                                       \
  CPPMACRO_##TAG##_POSTOPS(                                                    \
      ogis::copy_unsigendness_to_##type##_t<                                   \
          typename ogis::remove_cvref_t<decltype((nbrOfRepetitions))>>,        \
      nbrOfRepetitions, indexVarName, __VA_ARGS__)

#endif

#if defined __cpp_has_cpploop_slice

#include <valarray>

//:CPPMACRO_SLICES
// cpp-macro looping slice(start, size, step )
#define DUMMY_CPPMACRO_SLICE(slice, index)                       \
  for (size_t index = slice.start(),                             \
              __cppmacro_loop_##index##_index_limit =            \
                  slice.start() + slice.size() * slice.stride(); \
       index < __cppmacro_loop_##index##_index_limit; index += slice.stride())

#define CPPMACRO_SLICED(indexType, start, size, stride, indexVarName)        \
  for (indexType                                                             \
           indexVarName = start,                                             \
           __cppmacro_loop_##indexVarName##_limit = start + size * stride;   \
       (stride > 0) ? indexVarName < __cppmacro_loop_##indexVarName##_limit  \
                    : indexVarName > __cppmacro_loop_##indexVarName##_limit; \
       indexVarName += stride)

#define CPPMACRO_SLICED_POSTOPS(indexType, start, size, stride, indexVarName, \
                                ...)                                          \
  for (indexType                                                              \
           indexVarName = start,                                              \
           __cppmacro_loop_##indexVarName##_limit = start + size * stride;    \
       (stride > 0) ? indexVarName < __cppmacro_loop_##indexVarName##_limit   \
                    : indexVarName > __cppmacro_loop_##indexVarName##_limit;  \
       indexVarName += stride, __VA_ARGS__)

#endif

#endif
