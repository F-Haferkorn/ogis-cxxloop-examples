#include "asciishapes.hpp"
#include <cstdio>

//<- using the  old-style FOR(;;) COMPOUND "loop"

namespace asciishapes { namespace using_for {

void demo()
{
    using namespace asciishapes;
    const short noRows =4;

    // examples with regular FORLOOP-COMPOUND-statement.
    {
        square(noRows,2*noRows);                newline();
        triangular(noRows);                     newline();
        triangular_upside(noRows);              newline();
        centered_triangular(noRows);            newline();
        centered_triangular_upside(noRows);     newline();

    }

    // another example with loop compound statmemnt
    {
        sandclock(noRows*3 );
        newline();
    }
}

/*------------------  print simple square of stars

square(5,15);
***************
***************
***************
***************
***************

------------------*/


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

/*------------------   print simple (left-sided ) triangular of stars of size noRows
trianglar(5);
*
**
***
*****
******

------------------  */
void triangular(short nofRows)
{
    for(short row=0; row<nofRows; row++)
    {
        for(short col=0; col<row+1; col++)
            star();
        newline();
    }
}


////////////////////////////////////////////////////////
/* draw a simple lef-bounded triangular upside down of stars of size noRows
triangular_upside(5);

******
*****
***
**
*

------------------  */
void triangular_upside(short nofRows)
{
    for(short row=0; row<nofRows; row++)
    {
        for(short col=0; col<nofRows-row; col++)
            star();
        newline();
    }
}



/*--------------------- print centered triagular on the bottom,
centered_triangular(4);
    *
   ***
  *****
 *******
*********
// using plain for(;;) statement.
---------------------*/
void centered_triangular(short nofRows)
{
    for(short row=0; row<nofRows; row++)
    {
        // draw space on the left hand side
        for(short hidden1=0; hidden1<nofRows-row-1; hidden1++)
            space();
        star(); // draw at least 1 start at  the center

        // two time nofRows of row stars
        for(short  hidden2=0; hidden2<2*row; hidden2++)
            star();
        newline();
    }
}

/******************  print centered triagular on the bottom,        // make it symmetric.... with noRows

centered_triangular_upside(4);

*********
 *******
  *****
   ***
    *

******************/
// using plain for(;;) statement.
void centered_triangular_upside(short nofRows)
{
    for(short row=0; row<nofRows; row++)
    {
        for(short temp1=0; temp1<row; temp1++)
            space();

        star();

        for(short col=0; col<2*(nofRows-row-1); col++)
            star();
        newline();
    }
}


// print centered sand-clock.
void sandclock(short nofRows)
{
    centered_triangular_upside(nofRows);
    centered_triangular(nofRows);
}



} }
