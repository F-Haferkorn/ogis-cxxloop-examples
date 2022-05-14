## AsciiShapes Examples for the  Compound-Group "LOOP" ##

 prints simple ascishapes using LOOP-compounds

- [using_loop](using_loop) : examples using loop(..){} / loop_up(..){} /  loop_down(..){} , etc.
- [using_loop_postops](using_loop_postops) : examples using loop(..){} / loop_up(..){} /  loop_down(..){} , etc.

- [using_for](using_for) : examples using for(;;){}.

- [asciiarts.hpp] : needed primitives to print newline, stars, etc. 

- [asciishapes.hpp](asciishapes.hpp) :  contains a declaration of functions to print simple asciishapes.
- [asciishapes_using_loop.cpp](asciishapes_using_loop.cpp) :
- [asciishapes_using_for.cpp](asciishapes_using_for.cpp) : contains similar functions like ascishapes.cpp, but uses FOR(;;) instead of LOOP()-compounds.

- [matrix_io.hpp](matrix_io.hpp) : Contains functions to print native double 2D-Arrays (matrices like double a[M][N]) of given size N x M.
- [matrix.hpp](matrix.hpp)    : Header-only functions to operate on the matrcies as descrtibed above using LOOP-compounds.  
- [example_matrix.cpp](example_matrix.cpp) : example calls to the functions of  matrix.hpp and matrix_io.hpp. Is invoked by main.cpp.
    
