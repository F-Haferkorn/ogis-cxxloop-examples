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
                       TSizeRows nbofRows, TSizeCols nbofColums) {
  auto B = srcB;

  loop(nbofRows) loop_postops(nbofColums, srcA++, srcB += columns) *tgt++ =
      (*srcA) * (*srcB2);
}

template <typename TTgtValuePtr, typename TSrcAValuePtr, typename TSrcBValuePtr,
          typename TSizeCols, typename TSizeRows, typename TIdxCols,
          typename TIdxRows>
inline void matrix_mpy_w_stride(TTgtValuePtr tgtM, TSrcAValuePtr srcA,
                                TSrcBValuePtr srcB, SizeCols sizeA,
                                TSizeRows sizeB, TIdxCols deltaA = 1,
                                TIdxRows deltaB = 1) {
  loop_postops(nbofRows, srcB += deltaB * sizeA) loop_postops(
      nbofColums, srcA += deltaA, srcB += sizeA) *tgt++ = (*srcA) * (*srcB);
}
