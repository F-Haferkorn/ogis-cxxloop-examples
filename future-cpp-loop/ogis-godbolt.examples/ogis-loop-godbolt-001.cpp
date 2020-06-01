// created 2020-05-18
// see: https://godbolt.org/z/NU_Fgt

#define CPPMACRO_UNIQUE_ID() \
    CPPMACRO_UNIQUE_##_##LINE##_##__LINE__##_##__COUNTER__


// count-down: )inverse  loop: =
#define CPPMACRO_NTIMES_COUNT_UP(type, varName, nbrOfRepetitions, ...) \
    for (type varName = 0; varName++<nbrOfRepetitions; __VA_ARGS__)

// regular loop: counting-up
#define CPPMACRO_NTIMES_COUNT_DOWN(type, varName, nbrOfRepetitions, ...) \
    for (type varName = nbrOfRepetitions; varName--; __VA_ARGS__)

/// choose the fatest on your machine
#define CPPMACRO_NTIMES_FAST(type, varName, nbrOfRepetitions, ...) \
    CPPMACRO_NTIMES_COUNT_UP(type, varName, nbrOfRepetitions, __VA_ARGS__)

//#define loop(nbrOfRepetitions)  CPPMACRO_NTIMES(auto, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions)
#define loop(nbrOfRepetitions, ...)                 CPPMACRO_NTIMES_FAST(auto, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)
#define typed_loop(type, nbrOfRepetitions, ...)     CPPMACRO_NTIMES_FAST(type, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ##__VA_ARGS__)
#define named_loop_up(varName, nbrOfRepetitions, ...)  CPPMACRO_NTIMES_COUNT_UP(auto, varName, nbrOfRepetitions, ##__VA_ARGS__)
#define named_loop_down(varName, nbrOfRepetitions, ...)  CPPMACRO_NTIMES_COUNT_DOWN(auto, varName, nbrOfRepetitions, ##__VA_ARGS__)



typedef unsigned char Byte;
void matrix_copy_w_stride(
        double *tgt,
        double *src,
        Byte nbofRows,
        Byte nbofColumns,
        Byte row_stride)
{
    // apply a stride eafter each row
    loop(nbofRows,  tgt+=row_stride, src+=row_stride)
        loop(nbofColumns, tgt++, src++)
            *tgt = *src;

}
void matrix_add_using_While(
        double *tgt,
        double *src,
        Byte nbofRows,
        Byte nbofColumns)
{
    while(nbofRows--)
        while(nbofColumns--)
            *tgt++ += *src++;
}


void godbolt_entry()
{
    const Byte N=10;
    const Byte M=16;
    const Byte stride=4 ;

    double tgt[N][M];
    double src[N][M];

     matrix_copy_w_stride(&tgt[0][0], &src[0][0], N, M-stride, stride);
    

}






