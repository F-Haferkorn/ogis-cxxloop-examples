#include <iostream>
#include <iomanip>


#include <examples/matrix.hpp>
#include <examples/matrix_io.hpp>

namespace ogis::future::loop{


void example_matrix()
{
    using namespace ::ogis::future::loop;
    const int N=4;      // nbr-of rows
    const int M=10;      // nbr-of columns

    int  A[N][M]={};
    int B[N*M]={};
    int C[N*M]={};

    int *a=&A[0][0];
    matrix_set  (a, 1,   N, M);

    std::cout<<std::endl<<"A"<<std::endl;
    matrix_print(a, N, M);

    std::cout<<std::endl<<"B"<<std::endl;
    matrix_print(B, N, M);


    std::cout<<std::endl<<"C"<<std::endl;
    matrix_set  (C,2,     N, M);
    matrix_print(C,         N, M);

    loop(2)
    {
        std::cout<<std::endl<<"C+=A"<<std::endl;
        matrix_add  (C,a,       N, M);
        matrix_print(C,         N, M);
    }



    std::cout<<std::endl<<"B=C"<<std::endl;
    matrix_copy (B,C,       N, M);
    matrix_print(B,         N, M);

    std::cout<<std::endl<<"C+=B"<<std::endl;
    matrix_add  (C,B,       N, M);
    matrix_print(C,         N, M);
    {
        int n=N/2;
        int m=M/2;
        std::cout<<std::endl<<"C[0:"<<n-1<<"][0:"<<m-1<<"]+=1"<<std::endl;
        matrix_incr_w_stride(C, n, m,M-m);
        matrix_print(C,         N, M);
    }
    {

        int n=N/2+1;
        int m=M/2;
        std::cout<<std::endl<<"C[0:"<<n-1<<"][0:"<<m-1<<"]+=1"<<std::endl;
        matrix_incr_w_stride(C, n, m, M-m);
        matrix_print(C,         N, M);
    }


}

}
