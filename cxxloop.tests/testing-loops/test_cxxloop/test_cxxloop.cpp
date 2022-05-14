
#include <cassert>
#include <cstdint>
#include <iostream>
#include <loop>

#include "../macro.h"
typedef unsigned short ushort;
typedef unsigned char uchar;

namespace test_cxxloop {
namespace templates_simple {
template <typename T>
void test_loop_macro_up() {
  int count = 0;

  loop_up(10, id) count++;
  ASSERT_COUNTS(count, 10);
}
template <typename T>
void test_loop_macro_down() {
  int count = 0;
  loop_down(20, id) count++;
  ASSERT_COUNTS(count, 20);
}

template <typename T>
void test_loop_macro_fast() {
  int count = 0;
  loop(30) count++;
  ASSERT_COUNTS(count, 30);
}
template <typename T>
void test_loop_simple() {
  int count = 0;
  test_loop_macro_up<T>();
  test_loop_macro_down<T>();
  test_loop_macro_fast<T>();
}
void test() {
  /// signed
  test_loop_simple<long long>();
  test_loop_simple<long>();
  test_loop_simple<int>();
  test_loop_simple<short>();
  test_loop_simple<char>();

  /// unsigned
  test_loop_simple<unsigned long long>();
  test_loop_simple<unsigned long>();
  test_loop_simple<unsigned int>();
  test_loop_simple<unsigned short>();
  test_loop_simple<unsigned char>();

  /// const signed
  test_loop_simple<const long long>();
  test_loop_simple<const long>();
  test_loop_simple<const int>();
  test_loop_simple<const short>();
  test_loop_simple<const char>();

  /// const unsing
  test_loop_simple<const unsigned long long>();
  test_loop_simple<const unsigned long>();
  test_loop_simple<const unsigned int>();
  test_loop_simple<const unsigned short>();
  test_loop_simple<const unsigned char>();
}
}  // namespace templates_simple

//////////////////////////////////
/// \brief test_loop_reps_const_size_t
///
namespace templates {

template <typename T = int>
void test_loop_regular() {
  T rows = 100, columns = 40, N = 3;
  size_t count = 0;

  loop_up(rows, row) loop_down(columns, column) loop(N) count++;
  ASSERT_COUNTS(count, rows * columns * N);
}

template <typename T = int>
void test_loop_reference() {
  T rows_ = 100, columns_ = 40, N_ = 3;
  T &rows = rows_, &columns = columns_, &N = N_;
  int count = 0;
  loop_up(rows, row) loop_down(columns, column) loop(N) count++;
  ASSERT_COUNTS(count, rows * columns * N);
}

template <typename T = char>
void test_loop_rvalue() {
  T &&rows = 100, &&columns = 40, &&N = 4;

  int count = 0;
  loop_up(rows, row) loop_down(columns, column) loop(N) count++;
  ASSERT_COUNTS(count, rows * columns * N);

  count = 0;
  loop_up(T(100), row) loop_down(T(40), column) loop(size_t(4)) count++;
  ASSERT_COUNTS(count, rows * columns * N);
}

template <typename T = int>
void test_loop_expr() {
  T rows = 100, columns = 20, N = 4;
  size_t count = 0;
  loop_up(rows + 1, row) loop_down(columns + 1, column) loop(N + 1) count++;
  ASSERT_COUNTS(count, (rows + 1) * (columns + 1) * (N + 1));
}

template <typename T = char>
void test_loops_templates() {
  test_loop_regular<T>();
  test_loop_reference<T>();
  test_loop_rvalue<T>();
  test_loop_expr<T>();
}

void test() {
  /// signed
  test_loops_templates<long long>();
  test_loops_templates<long>();
  test_loops_templates<int>();
  test_loops_templates<short>();
  test_loops_templates<char>();

  /// unsigned
  test_loops_templates<unsigned long long>();
  test_loops_templates<unsigned long>();
  test_loops_templates<unsigned int>();
  test_loops_templates<unsigned short>();
  test_loops_templates<unsigned char>();

  /// const signe
  test_loops_templates<const long long>();
  test_loops_templates<const long>();
  test_loops_templates<const int>();
  test_loops_templates<const short>();
  test_loops_templates<const char>();

  /// const unsig
  test_loops_templates<const unsigned long long>();
  test_loops_templates<const unsigned long>();
  test_loops_templates<const unsigned int>();
  test_loops_templates<const unsigned short>();
  test_loops_templates<const unsigned char>();
}

}  // namespace templates

////////////////////////////

//#################### integrals signed
namespace integral_signed {
void test_loop_reps_integral_long_long() {
  long long count = 0;
  loop_up(400LL, row) loop_down(20LL, column) loop(5LL) count++;
  ASSERT_COUNTS(count, 400LL * 20LL * 5LL);
}

void test_loop_reps_integral_long() {
  size_t count = 0;
  loop_up(400L, row) loop_down(20L, column) loop(5L) count++;
  ASSERT_COUNTS(count, 400L * 20L * 5L);
}

void test_loop_reps_integral_int() {
  size_t count = 0;
  loop_up(400, row) loop_down(20, column) loop(5L) count++;
  ASSERT_COUNTS(count, 400 * 20 * 5);
}

void test_loop_reps_integral_short() {
  size_t count = 0;
  loop_up(short(400), row) loop_down(short(20), column) loop(short(5L)) count++;
  ASSERT_COUNTS(count, 400L * 20L * 5L);
}

void test_loop_reps_integral_char() {
  size_t count = 0;
  loop_up(char(20), row) loop_down(char(10), column) loop(char(5L)) count++;
  ASSERT_COUNTS(count, 20L * 10L * 5L);
}

void test_loop_reps_integral_h() {
  size_t count = 0;
  loop_up_h(200, row) loop_down_h(20, column) loop_h(5) count++;
  ASSERT_COUNTS(count, 200L * 20L * 5L);
}

void test_loop_reps_integral_hh() {
  size_t count = 0;

  loop_up_hh(20, row) loop_down_hh(10, column) loop_hh(5) count++;
  ASSERT_COUNTS(count, 20L * 10L * 5L);
}

void test() {
  test_loop_reps_integral_long_long();
  test_loop_reps_integral_long();
  test_loop_reps_integral_int();
  test_loop_reps_integral_short();
  test_loop_reps_integral_char();

  test_loop_reps_integral_h();
  test_loop_reps_integral_hh();
}

}  // namespace integral_signed

//#################### integrals unsigned
namespace integral_unsigned {
void test_loop_reps_integral_unsigned_long_long() {
  long long count = 0;

  loop_up(40LL, row) loop_down(20LL, column) loop(5LL) count++;
  ASSERT_COUNTS(count, 40ULL * 20ULL * 5ULL);
}

void test_loop_reps_integral_unsigned_long() {
  size_t count = 0;
  loop_up(40UL, row) loop_down(20UL, column) loop(5UL) count++;
  ASSERT_COUNTS(count, 40L * 20L * 5L);
}

void test_loop_reps_integral_unsigned_int() {
  size_t count = 0;
  loop_up(40U, row) loop_down(20U, column) loop(5U) count++;
  ASSERT_COUNTS(count, 40U * 20U * 5U);
}

void test_loop_reps_integral_unsigned_short() {
  size_t count = 0;
  loop_up(ushort(400), row) loop_hh(ushort(20)) loop(ushort(5)) count++;
  ASSERT_COUNTS(count, 400 * 20 * 5);
}

void test_loop_reps_integral_unsigned_char() {
  size_t count = 0;
  loop_hh(20) loop_hh(uchar(5)) count++;
  ASSERT_COUNTS(count, 20 * 5);
}

void test() {
  test_loop_reps_integral_unsigned_long_long();
  test_loop_reps_integral_unsigned_long();
  test_loop_reps_integral_unsigned_int();
  test_loop_reps_integral_unsigned_short();
  test_loop_reps_integral_unsigned_char();
}

}  // namespace integral_unsigned

void test() {
  templates_simple::test();
  templates::test();
  integral_signed::test();
  integral_unsigned::test();
}

}  // namespace test_cxxloop

int main() {
  std::cout << "# testing" << __FILE__ << std::endl;
  test_cxxloop::test();
  std::cout << "... END-of-Test" << std::endl;
  std::cout.flush();
}
