#include "asciishapes.hpp"
#include <cstdio>

#include <loop>         //<- use the NEW COMPOUND "loop"

namespace asciishapes { namespace  using_loop {

void demo()
{
    using namespace asciishapes;
    const short noRows =4;

    // examples with LOOP-COMPOUND-statement using post expressions
    {
        square(noRows,2*noRows);                newline();
        triangular(noRows);                     newline();
        triangular_upside(noRows);              newline();
        centered_triangular(noRows);            newline();
        centered_triangular_upside(noRows);     newline();
    }

    // combined example with loop compound statmemnt
    {
        sandclock(noRows*3 );    newline();
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


// print a left-bound, upside triangular of stars of size noRows
void square(short  noRows, short noColumns)
{
    loop(noRows, newline())             // use loop() with/without postoperations
        loop(noColumns)
            star();
}

/*------------------   left-bound triangular (same as above), using postfix-ops
trianglar(5);
*
**
***
*****
******

------------------  */
void triangular(short noRows)
{
    named_loop_up(row, noRows, newline())         // using named_loop_up() with postoperation.
        loop(row + 1)
            star();
}

/*------------------ print simple lef-bounded triangular upside down,

triangular_upside(5);

******
*****
***
**
*

------------------  */
void triangular_upside(short nofRows)
{
    named_loop_down(row, nofRows, newline())      // using named_loop_down() with postoperation.
        loop(row+1)                                 // print it upside down.
            star();
}

/*--------------------- print centered triagular on the bottom,
centered_triangular(4);
    *
   ***
  *****
 *******
*********

---------------------*/
void centered_triangular(short  nofRows)
{
    named_loop_up(row, nofRows, newline())   /// using named_loop_up() with postoperations
    {
        loop(nofRows-row-1) space();     // print spaces on the left hand side
        star();
        loop(2)loop(row)    star();        // print two time nofRows of row stars
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
void centered_triangular_upside(short nofRows)
{
    named_loop_up(row, nofRows, newline())      // using named_loop_down() with a postoperations
    {
        loop(row) space() ;                     // print spaces on the left hand side
        star();
        loop(2) loop(nofRows-row-1) star();     // print two times row-count stars.

    }

}

// print centered sand-clock.
void sandclock(short nofRows)
{
    centered_triangular_upside(nofRows);
    centered_triangular(nofRows);
}

} }
