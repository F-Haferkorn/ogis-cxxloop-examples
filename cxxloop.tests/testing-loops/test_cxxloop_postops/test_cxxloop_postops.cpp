#include <cstdint>
#include <iostream>
#include <loop>

///
#include <loop>

#include "macro.h"

namespace test_cxxloop_postops {
namespace macro {
void test_loop_macro_no_postops() {
  int count = 0;

  count = 0;
  CPPMACRO_NTIMES_UP_POSTOPS(unsigned int, 1000, id, count++, count++) count++;
  ASSERT_COUNTS(count, 3 * 1000);

  count = 0;
  CPPMACRO_NTIMES_DOWN_POSTOPS(unsigned int, 2000, id, count++, count++)
  count++;
  ASSERT_COUNTS(count, 3 * 2000);
}

void test_loop_macro_one_postops() {
  {  // 1 post-expression
    int count = 0;
    CPPMACRO_NTIMES_UP_POSTOPS(int, 1000, id, count++) count++;
    ASSERT_COUNTS(count, 2 * 1000);

    count = 0;
    CPPMACRO_NTIMES_DOWN_POSTOPS(int, 2000, id, count++) count++;
    ASSERT_COUNTS(count, 2 * 2000);
  }
}
void test_loop_macro_two_postops() {
  {  // 2 loop_down
    int count;

    count = 0;
    CPPMACRO_NTIMES_UP_POSTOPS(int, 1000, id, count++, count++) count++;
    ASSERT_COUNTS(count, 3 * 1000);
    count = 0;
    CPPMACRO_NTIMES_DOWN_POSTOPS(int, 2000, id, count++, count++) count++;
    ASSERT_COUNTS(count, 3 * 2000);
  }
}
// namespace macro
void test_loop() {
  macro::test_loop_macro_no_postops();
  macro::test_loop_macro_one_postops();
  macro::test_loop_macro_two_postops();
}
}  // namespace macro
//////////////////////////////////
/// \brief test_loop_postops_reps_const_size_t
namespace reps_size_t {
void test_loop_postops_reps_const_size_t() {
  const size_t rows = 4, columns = 2;
  size_t count = 0;
  loop_up_postops(rows, row, count += 5)
      loop_down_postops(columns, column, count += 5) loop(2) count++;
  ASSERT_COUNTS(count, (rows * 5) + (rows * columns * 5) + rows * columns * 2);
}

void test_loop_postops_reps_size_t() {
  size_t rows = 4, columns = 2, N = 5;
  size_t count = 0;

  loop_up_postops(rows, row, count += 100)
      loop_down_postops(columns, column, count += 10) loop_postops(N, count++);
  ASSERT_COUNTS(count,
                (rows * 100) + (rows * columns * 10) + rows * columns * N * 1);
}

void test_loops() {
  test_loop_postops_reps_size_t();
  test_loop_postops_reps_const_size_t();
}

}  // namespace reps_size_t

//#################### integrals signed
namespace reps_signed {
void test_loop_postops_reps_integral_long_long() {
  long long count = 0;
  size_t rows = 4, columns = 2, N = 5;
  loop_up_postops(4LL, row, count += 100)
      loop_down_postops(2LL, column, count += 10) loop_postops(5LL, count++);
  ASSERT_COUNTS(count,
                (rows * 100) + (rows * columns * 10) + rows * columns * 5);
}

void test_loop_postops_reps_integral_long() {
  size_t count = 0;
  size_t rows = 4, columns = 2, N = 5;
  loop_up_postops(4L, row, count += 100)
      loop_down_postops(2L, column, count += 10) loop_postops(5L, count++);
  ASSERT_COUNTS(count,
                (rows * 100) + (rows * columns * 10) + rows * columns * 5);
}

void test_loop_postops_reps_integral_int() {
  size_t count = 0;
  size_t rows = 4, columns = 2, N = 5;
  loop_up_postops(4, row, count += 100)
      loop_down_postops(2, column, count += 10) loop_postops(5, count++);
  ASSERT_COUNTS(count,
                (rows * 100) + (rows * columns * 10) + rows * columns * 5);
}

void test_loop_postops_reps_integral_short() {
  size_t count = 0;
  size_t rows = 4, columns = 2, N = 5;
  loop_up_postops(4, row, count += 100) loop_hh_postops(2, count += 10)
      loop_postops(5, count++);
  ASSERT_COUNTS(count,
                (rows * 100) + (rows * columns * 10) + rows * columns * 5);
}
void test_loop_postops_reps_integral_char() {
  size_t count = 0;
  size_t rows = 2, columns = 5;
  loop_hh_postops(2, count += 10) loop_hh_postops(5, count++);
  ASSERT_COUNTS(count, (rows * 10) + (rows * columns * 1));
}
void test_loops() {
  test_loop_postops_reps_integral_long_long();
  test_loop_postops_reps_integral_long();
  test_loop_postops_reps_integral_int();
  test_loop_postops_reps_integral_short();
  test_loop_postops_reps_integral_char();
}

}  // namespace reps_signed

//#################### integrals unsigned
namespace reps_unsigned {
void test_loop_postops_reps_integral_unsigned_long_long() {
  long long count = 0;
  size_t rows = 4, columns = 2, N = 5;
  loop_up_postops(4LL, row, count += 100)
      loop_down_postops(2LL, column, count += 10) loop_postops(5LL, count++);
  ASSERT_COUNTS(count,
                (rows * 100) + (rows * columns * 10) + rows * columns * 5);
}

void test_loop_postops_reps_integral_unsigned_long() {
  size_t count = 0;
  size_t rows = 4, columns = 2, N = 5;
  loop_up_postops(4L, row, count += 100)
      loop_down_postops(2L, column, count += 10) loop_postops(5L, count++);
  ASSERT_COUNTS(count,
                (rows * 100) + (rows * columns * 10) + rows * columns * 5);
}

void test_loop_postops_reps_integral_unsigned_int() {
  size_t count = 0;
  size_t rows = 4, columns = 2, N = 5;
  loop_up_postops(4, row, count += 100)
      loop_down_postops(2, column, count += 10) loop_postops(5, count++);
  ASSERT_COUNTS(count,
                (rows * 100) + (rows * columns * 10) + rows * columns * 5);
}

void test_loop_postops_reps_integral_unsigned_short() {
  size_t count = 0;
  size_t rows = 4, columns = 2, N = 5;
  loop_up_postops(4, row, count += 100) loop_hh_postops(2, count += 10)
      loop_postops(5, count++);
  ASSERT_COUNTS(count,
                (rows * 100) + (rows * columns * 10) + rows * columns * 5);
}

void test_loop_postops_reps_integral_unsigned_char() {
  size_t count = 0;
  size_t rows = 2, columns = 5;
  loop_hh_postops(2, count += 10) loop_hh_postops(5, count++);
  ASSERT_COUNTS(count, (rows * 10) + (rows * columns * 1));
}

void test_loops() {
  test_loop_postops_reps_integral_unsigned_long_long();
  test_loop_postops_reps_integral_unsigned_long();
  test_loop_postops_reps_integral_unsigned_int();
  test_loop_postops_reps_integral_unsigned_short();
  test_loop_postops_reps_integral_unsigned_char();
}

}  // namespace reps_unsigned

namespace plain_tests {
void test_loop_010() {
  unsigned int count = 0;
  loop_down(10U, i) count++;
  ASSERT_COUNTS(count, 10);

  loop_up_postops(20, row, count++);
  ASSERT_COUNTS(count, 10 + 20);

  loop_hh_postops(10, count += 100) count++;
  ASSERT_COUNTS(count, 10 + 20 + (10 * (100 + 1)));
}

void test_loop_020_looping_in_single_line() {
  int count = 0;
  loop_up_postops(4, row, count += 1000)
      loop_down_postops(3, column, count += 100) loop_postops(2, count += 10);
  ASSERT_COUNTS(count, 4 * (1000 + 3 * (100 + 2 * 10)));
}

void test_loop_021_loop_up() {  // loop_up
  int count = 0;
  int temp = 0;
  loop_up(4, row) count++;
  if (count != 4)
    printf("%s: iteration count %d: is NOT 4 as expected \n",
           "loop_up(4, row) count++;", count);

  count = 0;
  loop_up_postops(4, row, count += 1000) count++;
  if (count != 4004)
    printf("%s: iteration count %d: is NOT 4004 as expected \n",
           "loop_up(4, row, count += 1000) count++;", count);

  count = 0;
  loop_up_postops(4, row, count += 1000, temp++) count++;
  if (count != 4004)
    printf("%s: iteration count %d: is NOT 4004 as expected \n",
           "loop_up(4, row, count += 1000, temp++) count++;", count);
}

void test_loop_022_loop_down() {
  int count = 0;
  int temp = 0;
  loop_down(3, column) count++;
  if (count != 3)
    printf("%s:  iteration count %d:  is NOT 3 as expected \n",
           "loop_down(3, column) count++;", count);
  count = 0;
  loop_down_postops(3, column, count += 100) count++;
  if (count != 303)
    printf("%s;  iteration count %d: is NOT 303 as expected \n",
           "loop_down_postops(3, column, count += 100) count++;", count);

  count = 0;
  loop_up_postops(3, column, count += 100, temp++) count++;
  if (count != 303)
    printf("%s;  iteration count %d:  is NOT 303 as expected \n",
           "loop_up_postops(column, 3, count += 100) count++;", count);
}

void test_loop_023_typed_loop() {
  int count = 0;
  int temp = 0;
  loop_hh(100) count++;
  ASSERT_COUNTS(count, 100);

  count = 0;
  loop_hh_postops(100, count++) count++;
  ASSERT_COUNTS(count, 200);

  count = 0;

  loop_hh_postops(100, count++, temp++) count++;
  ASSERT_COUNTS(count, 200);
  ASSERT_COUNTS(temp, 100);
}

void test_loop_030() {
  int count = 0;
  loop_postops(4, count += 1000) loop_postops(2, count += 10);
  ASSERT_COUNTS(count, 4 * 1000 + 4 * 2 * 10);
}

void test_loop_040_loop() {
  int count = 0;

  loop_postops(2, count += 10) count++;
  ASSERT_COUNTS(count, 22);

  count = 0;
  loop_postops(2, count += 10, count += 100) count++;
  ASSERT_COUNTS(count, 222);
}
void test_loops() {
  test_loop_010();

  test_loop_020_looping_in_single_line();
  test_loop_021_loop_up();
  test_loop_022_loop_down();
  test_loop_023_typed_loop();

  test_loop_030();

  test_loop_040_loop();
}
}  // namespace plain_tests
void test() {
  macro::test_loop();
  reps_size_t::test_loops();
  reps_signed::test_loops();
  reps_unsigned::test_loops();
  plain_tests::test_loops();
}
}  // namespace test_cxxloop_postops

int main() {
  std::cout << "# testing" << __FILE__ << std::endl;
  test_cxxloop_postops::test();
  std::cout << "... END-of-Test" << std::endl;
  std::cout.flush();
}
