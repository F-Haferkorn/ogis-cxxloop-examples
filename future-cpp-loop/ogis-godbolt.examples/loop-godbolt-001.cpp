#pragma once


#define CPPMACRO_UNIQUE_ID()  CPPMACRO_UNIQUE_##LINE##_##__LINE__##_##__COUNTER__

#define CPPMACRO_COUNTING_DOWN_FORLOOP(type, varName, nbrOfRepetitions, ...) \
    for (type varName = nbrOfRepetitions; varName--; __VA_ARGS__)

#define loop(nbrOfRepetitions, ...)  	\
    CPPMACRO_COUNTING_DOWN_FORLOOP(auto, CPPMACRO_UNIQUE_ID(), nbrOfRepetitions, __VA_ARGS__) \


template<typename TPtr, typename TRowSize, typename TColSize, typename TStrideSize >
void matrix_copy_w_loop( TPtr tgt, TPtr src, TRowSize nRows, TColSize nColumns, TStrideSize stride)
{
    loop(nRows)
            loop(nColumns)
                   *tgt++ = *src++;
}

template<typename TPtr, typename TRowSize, typename TColSize, typename TStrideSize >
void matrix_copy_w_for( TPtr tgt, TPtr src, TRowSize nRows, TColSize nColumns, TStrideSize stride)
{
    for(int row=0; row<nRows; ++row)
            for(int col=0; col<nRows; ++col)
                   *tgt++ = *src++;
    
}


void godbolt_entry();

int main()
{
    const char rows=4;
    const char columns=16;
    const char stride = 8;

    double source[rows][columns];
    double target[rows][columns];

    matrix_copy_w_for(&target[0][0], &source[0][0],rows,columns- stride,stride);
    matrix_copy_w_loop(&target[0][0], &source[0][0],rows,columns- stride,stride);
    
    godbolt_entry();

}
