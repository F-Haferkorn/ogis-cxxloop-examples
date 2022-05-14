#include <loop>

template <typename TTgtValuePtr, typename TSrcValuePtr, typename TSizeRows,
          typename TSizeCols, typename TSizeStride>
inline void matrix_copy_w_stride(TTgtValuePtr tgt, TSrcValuePtr src,
                                 TSizeRows nbofRows, TSizeCols nbofColumns,
                                 TSizeStride row_stride) {
  // apply a stride after each row
  loop_postops(nbofRows, tgt += row_stride, src += row_stride)
      loop_postops(nbofColumns, tgt++, src++) *tgt = *src;
}

template <typename TTgtValuePtr, typename TSrcValuePtr, typename TSizeRows,
          typename TSizeCols>
inline void matrix_copy(TTgtValuePtr tgt, TSrcValuePtr src, TSizeRows nbofRows,
                        TSizeCols nbofColums) {
  loop(nbofRows) loop(nbofColums) *tgt++ = *src++;
}

template <typename TTgtValuePtr, typename TValue, typename TSizeRows,
          typename TSizeCols>
inline void matrix_set(TTgtValuePtr *tgt, TValue value, TSizeRows nbofRows,
                       TSizeCols nbofColums) {
  loop(nbofRows) loop(nbofColums) *tgt++ = value;
}

template <typename TTgtValuePtr, typename TSrcValuePtr, typename TSizeRows,
          typename TSizeCols>
inline void matrix_add(TTgtValuePtr tgt, TSrcValuePtr src, TSizeRows nbofRows,
                       TSizeCols nbofColums) {
  loop(nbofRows) loop(nbofColums) *tgt++ += *src++;
}

template <typename TTgtValuePtr, typename TTgtValue, typename TSizeRows,
          typename TSizeCols, typename TSizeStride>
inline void matrix_incr_w_stride(TTgtValuePtr tgt, TTgtValue increment,
                                 TSizeRows nbofRows, TSizeCols nbofColumns,
                                 TSizeStride row_stride) {
  loop_postops(nbofRows, tgt += row_stride) loop(nbofColumns) *tgt++ +=
      increment;
}

// TO BE VALIDATED
/// M=A*B
template <typename TTgtValuePtr, typename TSrcAValuePtr, typename TSrcBValuePtr,
          typename TSizeRows, typename TSizeCols>
inline void matrix_mpy(TTgtValuePtr tgt, TSrcAValuePtr srcA, TSrcBValuePtr srcB,
                       TSizeCols nbofColums, TSizeRows nbofRows) {
  auto pCol = srcA;
  auto pRow = srcB;

  loop(nbofColums * nbofRows)  // for each matrix element
      loop_up_postops(nbofRows, row, pRow = srcB + row * nbofColums)
          loop_postops(nbofColums, pRow += nbofColums) *tgt++ =
              (*pCol++) * (*pRow);
}

template <typename TTgtValuePtr, typename TSrcAValuePtr, typename TSrcBValuePtr,
          typename TSizeCols, typename TSizeRows, typename TIdxCols,
          typename TIdxRows>
inline void matrix_mpy_w_stride(TTgtValuePtr tgtM, TSrcAValuePtr srcA,
                                TSrcBValuePtr srcB, TSizeCols sizeA,
                                TSizeRows sizeB, TIdxCols deltaA = 1,
                                TIdxRows deltaB = 1) {
  auto pA = srcA;
  auto pB = srcB;

  // for each matrix element
  loop(sizeA * sizeB)
      // for each row element
      loop_up_postops(sizeB, row, pB = srcB + deltaB * row * sizeA)
      // multily ans add-up column with row.
      loop_postops(sizeA, pB += sizeA) *tgtM++ = (*pA++) * (*pB);
}
