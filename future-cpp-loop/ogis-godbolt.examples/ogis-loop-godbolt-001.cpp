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



template<typename TPtr, typename TRowSize, typename TColSize>
void matrix_copy_w_loop( TPtr tgt, TPtr src, TRowSize nRows, TColSize nColumns)
{
    loop(nRows)
            loop(nColumns)
                   *tgt++ = *src++;
}

template<typename TPtr, typename TRowSize, typename TColSize>
void matrix_copy_w_for( TPtr tgt, TPtr src, TRowSize nRows, TColSize nColumns)
{
    for(int row=0; row<nRows; ++row)
            for(int col=0; col<nColumns; ++col)
                   *tgt++ = *src++;

}


void godbolt_entry();

int godbolt__main()
{
    const char rows=4;
    const char columns=16;

    double source[rows][columns];
    double target[rows][columns];

    matrix_copy_w_for(&target[0][0], &source[0][0],rows,columns);
    matrix_copy_w_loop(&target[0][0], &source[0][0],rows,columns);

    godbolt_entry();
    return 0;

}
