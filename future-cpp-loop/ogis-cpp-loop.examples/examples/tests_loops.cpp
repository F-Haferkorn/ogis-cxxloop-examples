#include <cstdint>

#include <asciiart.hpp>
#include <loop>

using namespace asciishapes;

void test_loop_000() {
  int count = 0;

  { // no post-expression
    count = 0;
    CPPMACRO_NTIMES_UP(unsigned int, id, 1000) count++;
    if (count != 1000)
      printf("%s: iteration count %d' is NOT 1000 as expected\n",
             "CPPMACRO_NTIMES_DOWN(unsigned int, id, 1000) count++;", count);
    count = 0;
    CPPMACRO_NTIMES_DOWN(unsigned int, id, 2000) count++;
    if (count != 2000)
      printf("%s: iteration count %d' is NOT 2000 s expected \n",
             "CPPMACRO_NTIMES_DOWN(unsigned int, id, 2000) count++;", count);
  }
  { // 1 post-expression
    count = 0;
    CPPMACRO_NTIMES_UP(int, id, 1000, count++) count++;
    if (count != 2000)
      printf("%s: iteration count %d' is NOT 2000 s expected \n",
             "CPPMACRO_NTIMES_DOWN(int, id, 1000 count++) count++;", count);
    count = 0;
    CPPMACRO_NTIMES_DOWN(int, id, 2000, count++) count++;
    if (count != 4000)
      printf("%s: iteration count %d' is NOT 4000 as expected \n",
             "CPPMACRO_NTIMES_DOWN(int, id, 2000, count++) count++;", count);
  }

  { // 2 named_loop_down
    int temp = 0;
    count = 0;
    CPPMACRO_NTIMES_UP(int, id, 1000, count++, temp += 1) count++;
    if (count != 2000)
      printf("%s: iteration count %d' is NOT 2000 as expected \n",
             "CPPMACRO_NTIMES_DOWN(int, id, 1000 count++) count++;", count);
    count = 0;
    CPPMACRO_NTIMES_DOWN(int, id, 2000, count++, temp += 1) count++;
    if (count != 4000)
      printf("%s: iteration count %d' is NOT 4000 s expected \n",
             "CPPMACRO_NTIMES_DOWN(int, id, 2000, count++) count++;", count);
  }
}

void test_loop_001() {
  const size_t rows = 4, columns = 2;
  named_loop_up(row, rows, newline()) named_loop_down(column, columns, space())
      loop(2, star());
}

void test_loop_002() {
  named_loop_up(row, 4, newline()) named_loop_down(column, 2, space())
      loop(2, star());
}

void test_loop_010() {
  unsigned int count = 0;
  named_loop_down(i, 10U) count++;
  newline();

  named_loop_up(row, 20, row++) star();
  newline();

  typed_loop(char, 10, count += 100) star();
  newline();
}

void test_loop_020_looping_in_single_line() {
  int count = 0;
  named_loop_up(row, 4, count += 1000) named_loop_down(column, 3, count += 100)
      loop(2, count += 10);
  if (count != 4 * (1000 + 3 * (100 + 2 * 10)))
    printf("%s: iteration count %d: is NOT 5440 as expected",
           "named_loop_up(row, 4, count += 1000) "
           "\t named_loop_down(column, 3, count += 100) "
           "\t loop(2, count += 10)",
           count);
}

void test_loop_021_named_loop_up() { // named_loop_up
  int count = 0;
  int temp = 0;
  named_loop_up(row, 4) count++;
  if (count != 4)
    printf("%s: iteration count %d: is NOT 4 as expected \n",
           "named_loop_up(row, 4) count++;", count);

  count = 0;
  named_loop_up(row, 4, count += 1000) count++;
  if (count != 4004)
    printf("%s: iteration count %d: is NOT 4004 as expected \n",
           "named_loop_up(row, 4, count += 1000) count++;", count);

  count = 0;
  named_loop_up(row, 4, count += 1000, temp++) count++;
  if (count != 4004)
    printf("%s: iteration count %d: is NOT 4004 as expected \n",
           "named_loop_up(row, 4, count += 1000, temp++) count++;", count);
}

void test_loop_022_named_loop_down() {
  int count = 0;
  int temp = 0;
  named_loop_down(column, 3) count++;
  if (count != 3)
    printf("%s:  iteration count %d:  is NOT 3 as expected \n",
           "named_loop_down(column, 3) count++;", count);
  count = 0;
  named_loop_down(column, 3, count += 100) count++;
  if (count != 303)
    printf("%s;  iteration count %d: is NOT 303 as expected \n",
           "named_loop_down(column, 3, count += 100) count++;", count);

  count = 0;
  named_loop_up(column, 3, count += 100, temp++) count++;
  if (count != 303)
    printf("%s;  iteration count %d:  is NOT 303 as expected \n",
           "named_loop_down(column, 3, count += 100) count++;", count);
}

void test_loop_023_typed_loop() {
  int count = 0;
  int temp = 0;
  typed_loop(char, 100) count++;
  if (count != 100)
    printf(" iteration count %d: typed_loop(char, 100) count++; is NOT 100 as "
           "expected \n",
           count);
  count = 0;
  typed_loop(char, 100, count++) count++;
  if (count != 200)
    printf(" iteration count %d: typed_loop(char, 100) count++; is NOT 100 as "
           "expected \n",
           count);
  count = 0;
  typed_loop(char, 100, count++, temp++) count++;
  if (count != 200)
    printf(" iteration count %d: typed_loop(char, 100, count++, temp++) "
           "count++; is NOT 100 as "
           "expected \n",
           count);
}

void test_loop_024_loop() {
  int count = 0;
  int temp = 0;
  loop(2) count++;
  if (count != 2)
    printf(" iteration count %d: loop(2, count += 10) count++; is NOT 22 as "
           "expected \n",
           count);

  count = 0;
  loop(2, count += 10) count++;
  if (count != 22)
    printf(" iteration count %d: loop(2, count += 10) count++; is NOT 22 as "
           "expected \n",
           count);

  count = 0;
  loop(2, count += 10, temp += 100) count++;
  if (count != 22)
    printf(" iteration count %d: loop(2, count += 10,  count += 100) count++; "
           "is NOT 222 as "
           "expected \n",
           count);
}

void test_loop_030() {
  int count = 0;
  loop(4, count += 1000) loop(2, count += 10);
  if (count != 4 * (1000 + 2 * 10))
    printf("iteration count %d:  loop(4) loop(100) count++;  is NOT 4080 as "
           "expected \n",
           count);
}

void test_loop_040_loop() {
  int count = 0;
  int temp = 0;

  count = 0;
  loop(2, count += 10) count++;
  if (count != 22)
    printf(" iteration count %d: loop(2, count += 10) count++; is NOT 22 as "
           "expected \n",
           count);

  count = 0;
  loop(2, count += 10, temp += 100) count++;
  if (count != 22)
    printf(" iteration count %d: loop(2, count += 10,  count += 100) count++; "
           "is NOT 222 as "
           "expected \n",
           count);
}

void test_loops() {

  test_loop_000();
  test_loop_001();
  test_loop_002();

  test_loop_010();

  test_loop_020_looping_in_single_line();
  test_loop_021_named_loop_up();
  test_loop_022_named_loop_down();
  test_loop_023_typed_loop();
  test_loop_024_loop();

  test_loop_030();
}
