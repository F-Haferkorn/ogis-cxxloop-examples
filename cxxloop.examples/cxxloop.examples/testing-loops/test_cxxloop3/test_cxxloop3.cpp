#include <loop>

#include "macro.h"

namespace cxxloop3 {
void test_loop_macro() {
  int count = 0;
  {  // no post-expression
    count = 0;

    CPPMACRO_NTIMES_UP(unsigned int, 1000, id) count++;
    ASSERT_COUNTS(count, 1000);

    count = 0;
    CPPMACRO_NTIMES_DOWN(unsigned int, 2000, id) count++;
    ASSERT_COUNTS(count, 1000);
  }
}

void test_loop_const() {
  int count = 0;
  const size_t rows = 4, columns = 2, N = 5;
  loop_up(rows, row) {
    loop_down(columns, column) {
      loop(N) { count++; }
      count += 10;
    }
    count += 100;
  }
  ASSERT_COUNTS(count, 425);
}

void test_loop_002() {
  size_t count = 0;
  loop_up(4, row) {
    loop_down(2, column) {
      loop(5) { count++; }
      count += 10;
    }
    count += 100;
  }
  ASSERT_COUNTS(count, 425);
}

void test_loop_simple() {
  unsigned int count = 0;
  loop_down(10U, i) count++;
  ASSERT_COUNTS(count, 10);

  loop_up(20, row) { count++; }
  ASSERT_COUNTS(count, 20);

  loop_hh(4) loop_hh(10U) count++;
  ASSERT_COUNTS(count, 40);
}

void test_loop_simple2() {
  int count = 0;
  loop_up(4, row) {
    loop_down(3, column) {
      loop(2) count += 10;
      count += 100;
    }
    count += 1000;
  }
  ASSERT_COUNTS(count, 4 * (1000 + 3 * (100 + 2 * 10)));
}

void test_loop_021_loop_up() {  // loop_up
  int count = 0;
  int temp = 0;
  loop_up(4, row) count++;
  ASSERT_COUNTS(count, 4);

  count = 0;
  loop_up(4, row) {
    count++;
    count += 1000;
  }
  ASSERT_COUNTS(count, 4004);
  count = 0;
  loop_up(4, row) {
    count++;
    count += 1000;
    temp++;
  }
  ASSERT_COUNTS(count, 4004);
}

void test_loop_022_loop_down() {
  int count = 0;
  int temp = 0;
  loop_down(3, column) count++;
  ASSERT_COUNTS(count, 3);

  count = 0;
  loop_down(3, column) {
    count++;
    count += 100;
  }
  ASSERT_COUNTS(count, 303);

  count = 0;
  loop_up(3, column) {
    count++;
    count += 100;
    temp++;
  }
  ASSERT_COUNTS(count, 303);
}

void test_loop_030() {
  int count = 0;
  unsigned int M = 4;
  int N = 100;
  loop(M) loop(N) count++;
  ASSERT_COUNTS(count, static_cast<int>(M) * N);
}

void test_loops() {
  test_loop_macro();

  test_loop_const();

  test_loop_010();

  test_loop_020_up_down();
  test_loop_021_loop_up();
  test_loop_022_loop_down();
  test_loop_030();
}
