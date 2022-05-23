
#include <cassert>
#include <cstdint>
#include <iostream>
#include <loop>

#include "../macro.h"
typedef unsigned short ushort;
typedef unsigned char uchar;

namespace test_cxxloop_templates {

namespace NTIMES {
template <typename T>
void test_ntimes_macro_up() {
  int count = 0;

  CPPMACRO_NTIMES_UP(T, 10, id) count++;
  ASSERT_COUNTS(count, 10);
}
template <typename T>
void test_ntimes_macro_down() {
  int count = 0;
  CPPMACRO_NTIMES_DOWN(T, 20, id) count++;
  ASSERT_COUNTS(count, 20);
}

template <typename T>
void test_ntimes_macro_fast() {
  int count = 0;
  CPPMACRO_NTIMES_FASTEST(T, 30, id) count++;
  ASSERT_COUNTS(count, 30);
}
template <typename T>
void test_ntimes_macro() {
  int count = 0;
  test_ntimes_macro_up<T>();
  test_ntimes_macro_down<T>();
  test_ntimes_macro_fast<T>();
}
void test() {
  /// signed
  test_ntimes_macro<long long>();
  test_ntimes_macro<long>();
  test_ntimes_macro<int>();
  test_ntimes_macro<short>();
  test_ntimes_macro<char>();

  /// unsigned
  test_ntimes_macro<unsigned long long>();
  test_ntimes_macro<unsigned long>();
  test_ntimes_macro<unsigned int>();
  test_ntimes_macro<unsigned short>();
  test_ntimes_macro<unsigned char>();

  /// all CPPMACRO_NTIMES_DOWN_*  do not sopport CONST indexTypes!
}
}  // namespace NTIMES

namespace LOOP {
template <typename T>
void test_loop_macro_up() {
  int count = 0;

  CPPMACRO_LOOP(NTIMES_UP, 10, id) count++;
  ASSERT_COUNTS(count, 10);
}
template <typename T>
void test_loop_macro_down() {
  int count = 0;
  CPPMACRO_LOOP(NTIMES_DOWN, 20, id) count++;
  ASSERT_COUNTS(count, 20);
}

template <typename T>
void test_loop_macro_fast() {
  int count = 0;
  CPPMACRO_LOOP(NTIMES_FASTEST, 30, id) count++;
  ASSERT_COUNTS(count, 30);
}
template <typename T>
void test_loop_macro() {
  int count = 0;
  test_loop_macro_up<T>();
  test_loop_macro_down<T>();
  test_loop_macro_fast<T>();
}
void test() {
  /// signed
  test_loop_macro<long long>();
  test_loop_macro<long>();
  test_loop_macro<int>();
  test_loop_macro<short>();
  test_loop_macro<char>();

  /// unsigned
  test_loop_macro<unsigned long long>();
  test_loop_macro<unsigned long>();
  test_loop_macro<unsigned int>();
  test_loop_macro<unsigned short>();
  test_loop_macro<unsigned char>();

  /// const signe
  test_loop_macro<const long long>();
  test_loop_macro<const long>();
  test_loop_macro<const int>();
  test_loop_macro<const short>();
  test_loop_macro<const char>();

  /// const unsig
  test_loop_macro<const unsigned long long>();
  test_loop_macro<const unsigned long>();
  test_loop_macro<const unsigned int>();
  test_loop_macro<const unsigned short>();
  test_loop_macro<const unsigned char>();
}
}  // namespace LOOP

namespace BASIC {
namespace plain {

template <typename T>
void test_basic_macro_plain_postops() {
  int count = 0;
  T N = 10;
  loop_postops(N, count += 2) count++;
  ASSERT_COUNTS(count, 3 * N);

  count = 0;
  loop_h_postops(N, count += 2) count++;
  ASSERT_COUNTS(count, 3 * N);

  count = 0;
  loop_hh_postops(N, count += 2) count++;
  ASSERT_COUNTS(count, 3 * N);
}

template <typename T>
void test() {
  test_basic_macro_plain_postops<T>();
}
}  // namespace plain
namespace up {

template <typename T>
void test_basic_macro_up_postops() {
  int count = 0;
  T N = 10;

  loop_up_postops(N, id, count++) count++;
  ASSERT_COUNTS(count, 2 * N);

  count = 0;
  loop_up_h_postops(N, id, count++) count++;
  ASSERT_COUNTS(count, 2 * N);

  count = 0;
  loop_up_hh_postops(N, id, count++) count++;
  ASSERT_COUNTS(count, 2 * N);
}

template <typename T>
void test() {
  test_basic_macro_up_postops<T>();
}
}  // namespace up

namespace down {

template <typename T>
void test_basic_macro_down_postops() {
  int count = 0;
  T N = 10;

  loop_down_postops(N, id, count++) count++;
  ASSERT_COUNTS(count, 2 * N);

  count = 0;
  loop_down_h_postops(N, id, count++) count++;
  ASSERT_COUNTS(count, 2 * N);

  count = 0;
  loop_down_hh_postops(N, id, count++) count++;
  ASSERT_COUNTS(count, 2 * N);
}

template <typename T>
void test() {
  test_basic_macro_down_postops<T>();
}
}  // namespace down

template <typename T>
void test_basic() {
  up::test<T>();
  down::test<T>();
}

void test() {
  /// signed
  test_basic<long long>();
  test_basic<long>();
  test_basic<int>();
  test_basic<short>();
  test_basic<char>();

  /// unsigned
  test_basic<unsigned long long>();
  test_basic<unsigned long>();
  test_basic<unsigned int>();
  test_basic<unsigned short>();
  test_basic<unsigned char>();

  /// const signe
  test_basic<const long long>();
  test_basic<const long>();
  test_basic<const int>();
  test_basic<const short>();
  test_basic<const char>();

  /// const unsig
  test_basic<const unsigned long long>();
  test_basic<const unsigned long>();
  test_basic<const unsigned int>();
  test_basic<const unsigned short>();
  test_basic<const unsigned char>();
}

}  // namespace BASIC

//////////////////////////////////
/// \brief test_loop_reps_const_size_t
///
namespace templates {

template <typename T>
void test_loop_regular() {
  T rows = 100, columns = 40, N = 3;
  size_t count = 0;

  loop_up(rows, row) loop_down(columns, column) loop(N) count++;
  ASSERT_COUNTS(count, rows * columns * N);
}

template <typename T>
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

template <typename T>
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

namespace SCOPE {

template <typename T>
void test_scope_regular() {
  T rows = 100, columns = 40;
  size_t count = 0;

  loop_up(rows, row) loop_up(columns, col) count +=
      row > 0 ? (col > 0 ? 1 : 0) : 0;
  ASSERT_COUNTS(count, (rows - 1) * (columns - 1));
}

template <typename T>
void test_scope_reference() {
  T rows_ = 100, columns_ = 40;
  T &rows = rows_, &columns = columns_;
  int count = 0;
  loop_up(rows, row) loop_up(columns, col) count +=
      row > 0 ? (col > 0 ? 1 : 0) : 0;
  ASSERT_COUNTS(count, (rows - 1) * (columns - 1));
}

template <typename T = char>
void test_scope_rvalue() {
  T &&rows = 100, &&columns = 40;

  int count = 0;
  loop_up(rows, row) loop_up(columns, col) count +=
      row > 0 ? (col > 0 ? 1 : 0) : 0;
  ASSERT_COUNTS(count, (rows - 1) * (columns - 1));

  count = 0;
  loop_up(100, row) loop_up(40, col) count += row > 0 ? (col > 0 ? 1 : 0) : 0;
  ASSERT_COUNTS(count, (rows - 1) * (columns - 1));
}

template <typename T>
void test_scope_expr() {
  T rows = 100, columns = 20, N = 4;
  size_t count = 0;
  loop_up(rows + 1, row) loop_down(columns + 1, col) count +=
      row > 0 ? (col > 0 ? 1 : 0) : 0;
  ASSERT_COUNTS(count, (rows + 1 - 1) * (columns + 1 - 1));
}

template <typename T = char>
void test_loop_scopes() {
  test_scope_regular<T>();
  test_scope_reference<T>();
  test_scope_rvalue<T>();
  test_scope_expr<T>();
}

void test() {
  /// signed
  test_loop_scopes<long long>();
  test_loop_scopes<long>();
  test_loop_scopes<int>();
  test_loop_scopes<short>();
  test_loop_scopes<char>();

  /// unsigned
  test_loop_scopes<unsigned long long>();
  test_loop_scopes<unsigned long>();
  test_loop_scopes<unsigned int>();
  test_loop_scopes<unsigned short>();
  test_loop_scopes<unsigned char>();

  /// const signed
  test_loop_scopes<const long long>();
  test_loop_scopes<const long>();
  test_loop_scopes<const int>();
  test_loop_scopes<const short>();
  test_loop_scopes<const char>();

  /// const  unsigned
  test_loop_scopes<const unsigned long long>();
  test_loop_scopes<const unsigned long>();
  test_loop_scopes<const unsigned int>();
  test_loop_scopes<const unsigned short>();
  test_loop_scopes<const unsigned char>();
}

////////////////////////////

void test_loops() {
  NTIMES::test();
  LOOP::test();
  templates::test();
  SCOPE::test();
}

}  // namespace SCOPE

void test() {
  NTIMES::test();
  LOOP::test();
  BASIC::test();
  templates::test();
  SCOPE::test();
}

}  // namespace test_cxxloop_templates

int main() {
  std::cout << "# testing" << __FILE__ << std::endl;
  test_cxxloop_templates::test();

  std::cout << "... END-of-Test" << std::endl;
  std::cout.flush();
}
