#define CPPMACRO_UNIQUE_ID()  CPPMACRO_UNIQUE_##LINE##_##__LINE__##_##__COUNTER__

/////////////////////////////////////////////
#define CPPMACRO_NTIMES_UP(type, indexVarName, nbrOfRepetitions, ...) \
    for(type indexVarName = 0; indexVarName<nbrOfRepetitions;indexVarName++, ##__VA_ARGS__)

///////////////////////////////////////////
#define typed_loop(type, nbrOfRepetitions, ...)     \
    CPPMACRO_NTIMES_UP(type, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, ## __VA_ARGS__)

#define typed_named_loop_up(type, indexVarName, nbrOfRepetitions, ...)  \
    CPPMACRO_NTIMES_UP(type, indexVarName, nbrOfRepetitions, ##__VA_ARGS__)

#if defined __cplusplus
    #define loop(nbrOfRepetitions, ...)   \
        typed_loop( decltype(nbrOfRepetitions), nbrOfRepetitions, ##__VA_ARGS__)

    #define named_loop_up(indexVarName, nbrOfRepetitions, ...)   \
        typed_named_loop_up( decltype(nbrOfRepetitions), indexVarName, nbrOfRepetitions, ##__VA_ARGS__)
#endif


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






