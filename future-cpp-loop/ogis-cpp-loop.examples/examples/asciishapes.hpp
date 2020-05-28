#pragma once


namespace asciishapes
{
    // basic primitives
    void star();        ///< write a single star ('*')
    void space();       ///< write a single space (' ')
    void newline();     ///< write a single newline )'\n')

 namespace old_style{
    // print a forms using old-style for compound
    void square(short  noRows, short noColumns);
    void triangular(short noRows);
    void triangular_upside(short nofRows);
}

    // print a forms using suggested loop() compounds
    void triangular(short noRows);
    void triangular_upside(short noRows);
    void square(short  noRows, short noColumns);
    void sandclock(short noRows);


}
