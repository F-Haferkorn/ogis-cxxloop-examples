#include <examples/asciishapes.hpp>

namespace asciishapes
{


void star(){
    putchar('*');
}
void space(){
    putchar(' ');
}

void newline(){
    putchar('\n');
}

// draw a square of stars of size noRows x noColumns
void square(short  noRows, short noColumns)
{
    loop(noRows)
    {
        loop(noColumns)
           star();
        newline();
    }
}
// draw a left-sided triangular of stars of size noRows
void triangular(short noRows)
{
    named_loop_(row,noRows)
    {
        loop(row+1)
			star();
        newline();
    }
}

/////////////////////////////////////////
// draw a left-sided, upside triangular of stars of size noRows
void square_(short  noRows, short noColumns)
{
    loop_(noRows, newline())
        loop_(noColumns)
            star();
}

// draw triagular (same as above),
// but use the loop_() statement that allows additional postfix-operations
void triangular_(short noRows)
{
    named_loop_(row,noRows,newline())
        loop_(row+1)
            star();
}

// draw triagular uspdide, (same as above),
// but use the  loop_() statement that allows additional postfix-operations
void triangular_upside_(short noRows)
{
    named_loop_(row,noRows,newline())
        loop_(noRows-row)
            star();
}




void sandclock(short noRows)
{
    named_loop_(row,noRows,newline())
    {
        loop_(noRows-row-1,space());
        loop(2)
            loop_(row+1)
				star();
    }

    named_loop_(row,noRows,newline())
    {
        loop_(row,space());
        loop(2)
            loop_(noRows-row)
				star();
    }

}



}
