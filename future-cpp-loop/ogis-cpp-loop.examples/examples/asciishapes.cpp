#include <examples/asciishapes.hpp>

#include <cstdio>
#include <compound>

namespace asciishapes
{

void star(){    putchar('*');  }
void space(){   putchar(' ');  }
void newline(){ putchar('\n'); }

// draw a left-sided, upside triangular of stars of size noRows
void square(short  noRows, short noColumns)
{
    loop(noRows, newline())
        loop(noColumns, star())
            ;
}


// draw triagular (same as above),
// but use the loop() statement that allows additional postfix-operations
void triangular(short noRows)
{
    named_loop_up(row,noRows,newline())
        loop(row+1)
            star();
}


// draw triagular uspdide, (same as above),
// but use the  loop() statement that allows additional postfix-operations
void triangular_upside(short nofRows)
{
    named_loop_up(row, nofRows)
    {
        loop(nofRows-row)
            star();
        newline();
    }

}


void triangular_on_the_bottom(int nofRows)
{
    named_loop_up(row, nofRows, newline())
    {
        loop(nofRows-row, space());
        star();
        loop(2)loop(row,star());
    }
}

void triangular_on_the_tip(int nofRows)
{
    named_loop_down(row, nofRows, newline())
    {
        loop(nofRows-row, space())  ;
        star();
        loop(2) loop(row,star());
    }
}


void sandclock(short nofRows)
{
    triangular_on_the_tip(nofRows);
    triangular_on_the_bottom(nofRows);
}
}
