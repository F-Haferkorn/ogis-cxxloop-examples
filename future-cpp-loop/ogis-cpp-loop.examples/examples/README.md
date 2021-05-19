## Simple Examples for the  Compound-Group "LOOP" ##

- [main.cpp](main.cpp)
    is the main entry point.

- [asciishapes.hpp](ascishapes.hpp)
    contains a declaration of functions to print simple asciishapes.
- [asciishapes.cpp](ascishapes.cpp)
    prints simple ascishapes using LOOP-compounds.
- [asciishapes_old_sytle](ascishapes_old_sytle)
  contains similar functions like ascishapes.cpp, but uses FOR(;;) instead of LOOP()-compounds.

- [matrix_io.hpp](matrix_io.hpp)
    contains functions to print native double 2D-Arrays (matrices like double a[M][N]) of given size N x M.
- [matrix.hpp](matrix.hpp)
    header-only functions to operate on the matrcies as descrtibed above using LOOP-compounds.  
- [example_matrix.cpp](example_matrix.cpp)
    example calls to the functions of  matrix.hpp and matrix_io.hpp.
    is invoked by main.cpp.
