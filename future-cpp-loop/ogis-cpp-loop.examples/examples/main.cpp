#include "asciishapes.hpp"
#include "matrix.hpp"
#include <vector>

#include <iostream>


void example_matrix();

int main()
{
    using namespace asciishapes;

    std::cout<<"############ asciishapes::using_LOOP"<<std::endl;
    asciishapes::using_loop::demo();        // demo using  LOOP()  COMPOUNDS

    newline();   newline();

    std::cout<<"############ asciishapes::using_FOR"<<std::endl;
    asciishapes::using_for::demo();         // demo using  FOR(;;) COMPOUNDS

    // some more realistic axamples of matrix operations using the new conmound-statements
    example_matrix();


    // validating behaviour of unsiged index var here (size_t)
    auto v0 = std::vector<int>(0);
    auto v10 = std::vector<int>(10);
    std::cout<<"looping empty-vector"<<std::endl;
    loop(v0.size())
            star();
    newline();

    std::cout<<"looping 10-elemet--vector"<<std::endl;
    named_loop_down(i, v10.size())
            star();
    newline();

    unsigned int count=4;

    named_loop_up(row, count)           star();
    newline();

    named_loop_down(row, count)           star();
    newline();


    return 0;
}
