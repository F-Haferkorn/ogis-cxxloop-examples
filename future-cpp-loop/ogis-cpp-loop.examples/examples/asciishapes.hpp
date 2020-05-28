#pragma once


namespace asciishapes
{
    // basic primitives
    void star();        ///< write a single star ('*')
    void space();       ///< write a single space (' ')
    void newline();     ///< write a single newline )'\n')

    // print a forms using suggested loop() compounds
    void square(short  noRows, short noColumns);
    void triangular(short noRows);
    void triangular_upside(short noRows);

    void triangular_on_the_tip(int nofRows);
    void triangular_on_the_bottom(int nofRows);

    void sandclock(short noRows);


}

namespace asciishapes::old_style{
   // print a forms using old-style for compound
   void square(short  noRows, short noColumns);
   void triangular(short noRows);
   void triangular_upside(short nofRows);
}
