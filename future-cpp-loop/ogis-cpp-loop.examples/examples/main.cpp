#include <iostream>
#include <iomanip>
#include <ostream>
#include <functional>

#include <compound>

#include <examples/asciishapes.hpp>


using namespace asciishapes;


void example_matrix();

int main()
{
    const short noRows =4;

    // example with loop compound-statement
    {
        square(noRows,2*noRows);
        newline();
        triangular(noRows);
        newline();
    }

    // example with loop compound-statement using post expressions
    {
        square_(noRows,2*noRows);
        newline();
        triangular_(noRows);
        newline();
        triangular_upside_(noRows);
        newline();

    }

    // another example with loop compound statmemnt
    {
        sandclock(noRows*3 );
        newline();
    }

    example_matrix();
    return 0;
}
