#include <iostream>
#include <iomanip>


#include <examples/matrix.hpp>
#include <examples/matrix_io.hpp>

namespace ogis::future::loop{


void example_matrix()
{
    using namespace ::ogis::future::loop;

    int  A[4][3]={{0,1,2},{10,11,12},{20,21,22},{30,31,32}};
    float  B[4*3]={};
    double C[4*3]={};

    int *a=&A[0][0];


    std::cout<<std::endl<<"A"<<std::endl;
    matrix_print(a, 4,3);

    std::cout<<std::endl<<"B"<<std::endl;
    matrix_print(B, 4,3);


    std::cout<<std::endl<<"C"<<std::endl;
    matrix_set  (C,1.1,     4,3);
    matrix_print(C,         4,3);

    std::cout<<std::endl<<"C+=a"<<std::endl;
    matrix_add  (C,a,       4,3);
    matrix_print(C,         4,3);

    std::cout<<std::endl<<"B=C"<<std::endl;
    matrix_copy (B,C,       4,3);
    matrix_print(B,         4,3);

    std::cout<<std::endl<<"C+=B"<<std::endl;
    matrix_add  (C,B,       4,3);
    matrix_print(C,         4,3);

}

}
