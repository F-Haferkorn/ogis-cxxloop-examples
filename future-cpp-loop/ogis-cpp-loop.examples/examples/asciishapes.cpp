#include <examples/asciishapes.hpp>

#include <cstdio>

#include <compound>

namespace asciishapes
{

void star()     { putchar('*');  }
void space()    { putchar(' ');  }
void newline()  { putchar('\n'); }

// print a left-bound, upside triangular of stars of size noRows
// use loop() with and without postoperations
void square(short  noRows, short noColumns)
{
    loop(noRows, newline())
        loop(noColumns)
            star();
}

// print a left-bound triagular (same as above), using NO postfix-ops
void triangular(short noRows)
{
    named_loop_up(row, noRows)
        loop(row + 1)
            star();    
}

// print a left-bound triangular upside down, 
// use named_loop_up() with postoperation
void triangular_upside(short nofRows)
{
    named_loop_up(row, nofRows, newline())
        loop(nofRows-row)
            star();
}

// print centered triagular on the bottom, 
// use named_loop_up() with postoperation
void triangular_on_the_bottom(int nofRows)
{
    named_loop_up(row, nofRows, newline())
    {
        loop(nofRows-row, space());     // space on the left had side
        star();
        loop(2)loop(row,star());        // two time nofRows of row stars
    }
}

// print centered triagular on the bottom, 
// use named_loop_down() with postoperation
void triangular_on_the_tip(int nofRows)
{
    named_loop_down(row, nofRows, newline())
    {
        loop(nofRows-row, space())  ;   // print space on the left had side
        star();
        loop(2) loop(row,star());       // two times row-count stars.
    }
}

// print centered sand-clock.
void sandclock(short nofRows)
{
    triangular_on_the_tip(nofRows);
    triangular_on_the_bottom(nofRows);
}

}
