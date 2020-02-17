#include <compound>

namespace ogis::future::loop{

    template<typename TTgtValuePtr, typename TSrcValuePtr, typename TSizeRows, typename TSizeCols,typename TSizeStride>
    inline void matrix_copy_w_stride(TTgtValuePtr tgt, TSrcValuePtr src, TSizeRows nbofRows, TSizeCols nbofColumms, TSizeStride stride)
    {
        loop(nbofRows)
            loop_(nbofColumms, tgt+=stride, src+=stride)
                *tgt++ = *src++;
    }

    template<typename TTgtValuePtr, typename TSrcValuePtr,  typename TSizeRows, typename TSizeCols>
    inline void matrix_copy(TTgtValuePtr tgt, TSrcValuePtr src, TSizeRows nbofRows, TSizeCols nbofColums)
    {
        loop(nbofRows)
            loop(nbofColums)
                *tgt++ = *src++;
    }

    template<typename TTgtValuePtr, typename TValue, typename TSizeRows, typename TSizeCols>
    inline void matrix_set(TTgtValuePtr* tgt, TValue value, TSizeRows nbofRows, TSizeCols nbofColums)
    {
        loop(nbofRows)
            loop(nbofColums)
                *tgt++ = value;
    }

    template<typename TTgtValuePtr, typename TSrcValuePtr, typename TSizeRows, typename TSizeCols>
    inline void matrix_add(TTgtValuePtr tgt, TSrcValuePtr src, TSizeRows nbofRows, TSizeCols nbofColums)
    {
        loop(nbofRows)
            loop(nbofColums)
                *tgt++ += *src++;
    }

}
