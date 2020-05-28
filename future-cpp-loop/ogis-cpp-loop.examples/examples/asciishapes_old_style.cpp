#include <examples/asciishapes.hpp>

#include <cstdio>
#include <compound>

namespace asciishapes::old_style
{


// draw a square of stars of size noRows x noColumns
void square(short  noRows, short noColumns)
{
    for(short row=0; row<noRows; ++row)
    {
        for(short col=0; col<noColumns; ++col)
            star();
        newline();
    }
}

////////////////////////////////////////////////////////
// draw a left-sided triangular of stars of size noRows
void triangular(short nofRows)
{
    for(int row=0; row<nofRows; row++)
    {
        for(int col=0; col<row; col++)
            star();
        newline();
    }
}

// draw triagular uspdide, (same as above),
// but use the  loop() statement that allows additional postfix-operations
void triangular_upside(short nofRows)
{
    for(int row=0; row<nofRows; row++)
    {
        for(int col=0; col<nofRows-row; col++)
            star();
        newline();
    }

}

}
