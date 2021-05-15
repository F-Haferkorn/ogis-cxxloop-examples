#include <cstdint>

#include <asciiart.hpp>
#include <loop>

using namespace asciishapes;

void misc_000() {
  int count = 0;

  CPPMACRO_NTIMES_UP(int, id, 1000, count++) count++;
  CPPMACRO_NTIMES_UP(int, id2, 100) count++;
}

void misc_001() {
  const size_t rows = 4, columns = 2;
  named_loop_up(row, rows, newline()) named_loop_down(column, columns, space())
      loop(2, star());
}

void misc_002() {
  named_loop_up(row, 4, newline()) named_loop_down(column, 2, space())
      loop(2, star());
}

void misc_010() {
  unsigned int count = 0;
  named_loop_down(i, 10U) count++;
  newline();

  named_loop_up(row, 20, row++) star();
  newline();

  typed_loop(char, 10, count += 100) star();
  newline();
}

void misc_020() {
  int count = 0;
  named_loop_up(row, 4, count += 1000) named_loop_down(column, 3, count += 100)
      loop(2, count += 10) count++;
  if (count != 4322)
    printf("iteration count %d' is NOT 4322 as expected \n", count);
}

void misc_021() {
  int count = 0;
  named_loop_up(row, 4, count += 1000) count++;
  if (count != 4004)
    printf("iteration count %d' is NOT 4004 as expected \n", count);
}

void misc_022() {
  int count = 0;
  named_loop_down(column, 3, count += 100) count++;
  if (count != 303)
    printf("iteration count %d' is NOT 303 as expected \n", count);
}

void misc_023() {
  int count = 0;
  loop(2, count += 10) count++;
  if (count != 22)
    printf("iteration count %d' is NOT 22 as expected \n", count);
}

void misc_024() {
  int count = 0;
  typed_loop(char, 100) count++;
  if (count != 100)
    printf("iteration count %d' is NOT 100 as expected \n", count);
}

void test_misc() {
  misc_001();
  misc_002();

  misc_010();

  misc_021();
  misc_022();
  misc_022();
  misc_023();
  misc_024();
}
