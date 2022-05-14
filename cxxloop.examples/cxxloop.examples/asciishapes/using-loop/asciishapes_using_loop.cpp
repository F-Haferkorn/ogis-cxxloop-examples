#include "asciishapes_using_loop.hpp"

#include <cstdio>
#include <loop>  //<- use the NEW COMPOUND "

namespace asciishapes {
namespace using_loop {

void demo() {
  using namespace asciishapes;
  const short noRows = 4;

  // examples with LOOP-COMPOUND-statement using post expressions
  {
    square(noRows, 2 * noRows);
    newline();
    triangular(noRows);
    newline();
    triangular_upside(noRows);
    newline();
    centered_triangular(noRows);
    newline();
    centered_triangular_upside(noRows);
    newline();
  }

  // combined example with loop compound statemented
  {
    sandclock(noRows * 3);
    newline();
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
void square(short noRows, short noColumns) {
  loop(noRows) {  // use loop() with/without post-operations
    loop(noColumns) star();
    newline();
  }
}

/*------------------   left-bound triangular (same as above), using postfix-ops
triangular(5);
*
**
***
*****
******

------------------  */
void triangular(short noRows) {
  // using named_loop_up() with post operation.
  loop_up(noRows, row) {
    loop(row + 1) star();
    newline();
  }
}

/*------------------ print simple left-bounded triangular upside down,

triangular_upside(5);

******
*****
***
**
*

------------------  */
void triangular_upside(short nofRows) {
  loop_down(nofRows, row) {  // using named_loop_down() with post operation.
    loop(row + 1)            // print it upside down.
        star();
    newline();
  }
}

/*--------------------- print centred triangular on the bottom,
centered_triangular(4);
    *
   ***
  *****
 *******
*********

---------------------*/
void centered_triangular(short nofRows) {
  loop_up(nofRows, row)  /// using named_loop_up() with post operations
  {
    loop(nofRows - row - 1) space();  // print spaces on the left hand side
    star();
    loop(2) loop(row) star();  // print two time nofRows of row stars
    newline();
  }
}

/******************  print centred triangular on the bottom,        // make it
symmetric.... with noRows

centered_triangular_upside(4);

*********
 *******
  *****
   ***
    *

******************/
void centered_triangular_upside(short nofRows) {
  // using named_loop_down() with a post operations
  loop_up(nofRows, row) {
    loop(row) space();  // print spaces on the left hand side
    star();
    loop(2) loop(nofRows - row - 1) star();  // print two times row-count stars.
    newline();
  }
}

// print centred sand-clock.
void sandclock(short nofRows) {
  centered_triangular_upside(nofRows);
  centered_triangular(nofRows);
}

}  // namespace using_loop
}  // namespace asciishapes
