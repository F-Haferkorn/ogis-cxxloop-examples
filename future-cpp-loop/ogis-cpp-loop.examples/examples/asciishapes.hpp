#pragma once
#include <iostream>

namespace asciishapes
{
    // basic primitives
    inline void star()   { std::cout.put('*');  }       ///< write a single star character '*'
    inline void space()  { std::cout.put(' ');  }       ///< write a single space character ' '
    inline void newline(){ std::cout.put('\n');  }      ///< write a single newline character '\n'

    namespace using_loop{
        void demo();

        // print a forms using new LOOP() compounds

        void square(short  noRows, short noColumns);        // write square with given column and row count.
        void triangular(short noRows);                      // write a left-bounded triangular.
        void triangular_upside(short nofRows);              // write a left-bounded upside-down triangula.

        void centered_triangular(short  nofRows);              // write a centered triangular
        void centered_triangular_upside(short nofRows);       // write a centered triangular standing on the  tip.

        void sandclock(short noRows);                       // write a sandclock.
    }

    namespace using_for{
        void demo();

       // print same asciishapes, but use  classic for(;;) compound
       void square(short  noRows, short noColumns);
       void triangular(short noRows);
       void triangular_upside(short nofRows);

       void centered_triangular(short nofRows);
       void centered_triangular_upside(short nofRows);
       void sandclock(short  noRows);
    }
}
