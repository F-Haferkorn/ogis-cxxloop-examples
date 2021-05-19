// this is a goodbolt example for the "COMPOUND-GROUP LOOP

// this is a goodbolt example for the "COMPOUND-GROUP LOOP

// prerequisites ////
// generate an unique ID
#ifndef CPPMACRO_UNIQUE_ID
#define CPPMACRO_UNIQUE_ID() CPPMACRO_UNIQUE_##ID_##LINE##__LINE__##__COUNTER__
#endif

///////// cpp-macro to count upwards (from 0 to nbrOfRepetitions-1)
#define CPPMACRO_NTIMES_UP(type, varName, reps, ...)                           \
  for (type varName = 0; varName < reps; varName++, ##__VA_ARGS__)

#if defined __cplusplus ///////////////////////////////////////////

#include <type_traits>
#define CPP_DECLTYPE(varname)                                                  \
  typename std::remove_const<decltype(varname)>::type

#else

// as "C" cannot detect the type of a varname,
// this can lead to problems with unsigned varname(s)
// -> signed/unsigned/ comparison
#define CPP_DECLTYPE(varname) int

#endif
// loop block-statement nbrOfRepetitions-times
#define loop(nbrOfRepetitions, ...)                                            \
  CPPMACRO_NTIMES_UP(CPP_DECLTYPE(nbrOfRepetitions), CPPMACRO_UNIQUE_ID(),     \
                     nbrOfRepetitions, ##__VA_ARGS__)

typedef unsigned char Byte;
void matrix_set_folded(double *tgt, double value, Byte nbofRows, Byte nbofColumns) {
  // apply a stride after each row
  loop(nbofRows*nbofColumns, tgt++) *tgt = value;
}

typedef unsigned char Byte;
void matrix_set(double *tgt, double value, Byte nbofRows, Byte nbofColumns) {
  // apply a stride after each row
  loop(nbofRows) loop(nbofColumns, tgt++) *tgt = value;
}


template <typename TPtr, typename TRowSize, typename TColSize>
void matrix_increase_w_loop(TPtr tgt, TPtr src, TRowSize nRows,
                            TColSize nColumns) {
  loop(nRows) loop(nColumns) *tgt++ += *src++;
}

template <typename TPtr, typename TRowSize, typename TColSize>
void matrix_increase_w_for(TPtr tgt, TPtr src, TRowSize nRows,
                           TColSize nColumns) {
  for (int row = 0; row < nRows; ++row)
    for (int col = 0; col < nColumns; ++col)
      *tgt++ += *src++;
}

typedef unsigned char Byte;
void matrix_copy_loop_w_stride(double *tgt, double *src, Byte nbofRows,
                               Byte nbofColumns, Byte row_stride) {
  // apply a stride after each row
  loop(nbofRows, tgt += row_stride, src += row_stride)
      loop(nbofColumns, tgt++, src++) *tgt = *src;
}

typedef unsigned char Byte;
void matrix_copy_loop_w_for(double *tgt, double *src, Byte nbofRows,
                            Byte nbofColumns, Byte row_stride) {
  // apply a stride after each row
  for (int i = 0; i < nbofRows; ++i) {
    for (int j = 0; j < nbofColumns; ++j) {
      *tgt = *src;
      tgt++;
      src++;
    }
    tgt += row_stride;
    src += row_stride;
  }
}
