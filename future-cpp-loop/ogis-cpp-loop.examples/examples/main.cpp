#include <examples/asciishapes.hpp>
#include <examples/matrix.hpp>



using namespace asciishapes;
using namespace ogis::future::loop;




int main()
{
    const short noRows =4;

    // example with loop compound-statement
    {
        old_style::square(noRows,2*noRows);         newline();
        old_style::triangular(noRows);              newline();
        old_style::triangular_upside(noRows);       newline();
    }

    // example with loop compound-statement using post expressions
    {
        square(noRows,2*noRows);         newline();
        triangular(noRows);              newline();
        triangular_upside(noRows);       newline();
    }

    // another example with loop compound statmemnt
    {
        sandclock(noRows*3 );
        newline();
    }

    example_matrix();
    return 0;
}
