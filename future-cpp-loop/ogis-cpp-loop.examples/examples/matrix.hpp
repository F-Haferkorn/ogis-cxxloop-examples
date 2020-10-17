#include <loop>

template<typename TTgtValuePtr, typename TSrcValuePtr, typename TSizeRows, typename TSizeCols,typename TSizeStride>
inline void matrix_copy_w_stride(TTgtValuePtr tgt, TSrcValuePtr src, TSizeRows nbofRows, TSizeCols nbofColumns, TSizeStride row_stride)
{
    // apply a stride eafter each row
    loop(nbofRows,  tgt+=row_stride, src+=row_stride)
        loop(nbofColumns, tgt++, src++)
            *tgt = *src;

}

template<typename TTgtValuePtr, typename TSrcValuePtr,  typename TSizeRows, typename TSizeCols>
inline void matrix_copy(TTgtValuePtr tgt, TSrcValuePtr src, TSizeRows nbofRows, TSizeCols nbofColums)
{
    loop(nbofRows) loop(nbofColums) *tgt++ = *src++;
}

template<typename TTgtValuePtr, typename TValue, typename TSizeRows, typename TSizeCols>
inline void matrix_set(TTgtValuePtr* tgt, TValue value, TSizeRows nbofRows, TSizeCols nbofColums)
{
    loop(nbofRows) loop(nbofColums)  *tgt++ = value;
}

template<typename TTgtValuePtr, typename TSrcValuePtr, typename TSizeRows, typename TSizeCols>
inline void matrix_add(TTgtValuePtr tgt, TSrcValuePtr src, TSizeRows nbofRows, TSizeCols nbofColums)
{
    loop(nbofRows)  loop(nbofColums) *tgt++ += *src++;
}

template<typename TTgtValuePtr, typename TTgtValue, typename TSizeRows, typename TSizeCols, typename TSizeStride >
inline void matrix_incr_w_stride(TTgtValuePtr tgt, TTgtValue increment,  TSizeRows nbofRows, TSizeCols nbofColumns, TSizeStride row_stride)
{
    loop(nbofRows,  tgt+=row_stride)
        loop(nbofColumns)
            *tgt++ += increment;
}

