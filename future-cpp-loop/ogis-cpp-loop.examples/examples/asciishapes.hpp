#pragma once

namespace asciishapes
{
    // basic primitives
    void star();        ///< write a single star ('*')
    void space();       ///< write a single space (' ')
    void newline();     ///< write a single newline )'\n')

    // print a forms using suggested loop() compounds
    void square(short  noRows, short noColumns);        // write square with given column and row count.
    void triangular(short noRows);                      // write a left-bounded triangular.
    void triangular_upside(short nofRows);               // write a left-bounded upside-down triangula.

    void triangular_on_the_tip(int nofRows);            // write a triangular standing on the  tip.
    void triangular_on_the_bottom(int nofRows);         // write a triangular standing on the  bottom.

    void sandclock(short noRows);                       // write a sandclock.
}

namespace asciishapes::old_style{
   // print a forms using old-style for compound
   void square(short  noRows, short noColumns);
   void triangular(short noRows);
   void triangular_upside(short nofRows);
}
