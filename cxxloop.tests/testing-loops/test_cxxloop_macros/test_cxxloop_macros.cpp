#include <iostream>
#include <loop>

#include "../macro.h"

namespace test_cxxloop_macros {
void test_loop_macro_NTIMES() {
  int count = 0;
  using T = int;

  count = 0;
  CPPMACRO_NTIMES_UP(T, 1000, id) count++;
  ASSERT_COUNTS(count, 1000);

  count = 0;
  CPPMACRO_NTIMES_DOWN(T, 2000, id) count++;
  ASSERT_COUNTS(count, 2000);

  count = 0;
  CPPMACRO_NTIMES_FASTEST(T, 3000, id) count++;
  ASSERT_COUNTS(count, 3000);
}

void test_loop_macro_LOOP() {
  int count = 0;

  count = 0;
  CPPMACRO_LOOP(UP, 1000, id) count++;
  ASSERT_COUNTS(count, 1000);

  count = 0;
  CPPMACRO_LOOP(DOWN, 2000, id) count++;
  ASSERT_COUNTS(count, 2000);

  count = 0;
  CPPMACRO_LOOP(FASTEST, 3000, id) count++;
  ASSERT_COUNTS(count, 3000);
}

void test_loop_macro_LOOP_const() {
  int count = 0;
  const int N = 100;
  count = 0;
  CPPMACRO_LOOP(UP, N, id) count++;
  ASSERT_COUNTS(count, N);

  count = 0;
  CPPMACRO_LOOP(DOWN, N, id) count++;
  ASSERT_COUNTS(count, N);

  count = 0;
  CPPMACRO_LOOP(FASTEST, N, id) count++;
  ASSERT_COUNTS(count, N);
}

void test_loop_macro_LOOP_expr() {
  int count = 0;
  const int N = 100;

  count = 0;
  CPPMACRO_LOOP(UP, N + 1, id) count++;
  ASSERT_COUNTS(count, N + 1);

  count = 0;
  CPPMACRO_LOOP(DOWN, N + 1, id) count++;
  ASSERT_COUNTS(count, N + 1);

  count = 0;
  CPPMACRO_LOOP(FASTEST, N + 1, id) count++;
  ASSERT_COUNTS(count, N + 1);
}

void test_loop_macro_LOOP_TYPED_const() {
  int count = 0;
  const int N = 100;

  count = 0;
  CPPMACRO_LOOP_TYPED(UP, N, id, char) count++;
  ASSERT_COUNTS(count, N);

  count = 0;
  CPPMACRO_LOOP_TYPED(DOWN, N, id, char) count++;
  ASSERT_COUNTS(count, N);

  count = 0;
  CPPMACRO_LOOP_TYPED(FASTEST, N, id, char) count++;
  ASSERT_COUNTS(count, N);
}

void test_loop_macro_LOOP_TYPED_expr() {
  int count = 0;
  const int N = 100;

  count = 0;
  CPPMACRO_LOOP_TYPED(UP, N + 1, id, char) count++;
  ASSERT_COUNTS(count, N + 1);

  count = 0;
  CPPMACRO_LOOP_TYPED(DOWN, N + 1, id, char) count++;
  ASSERT_COUNTS(count, N + 1);

  count = 0;
  CPPMACRO_LOOP_TYPED(FASTEST, N + 1, id, char) count++;
  ASSERT_COUNTS(count, N + 1);
}

void test_loop_macro_LOOP_TYPED_char() {
  int count = 0;
  CPPMACRO_LOOP_TYPED(UP, 10, id, char) count++;
  ASSERT_COUNTS(count, 10);

  count = 0;
  CPPMACRO_LOOP_TYPED(DOWN, 20, id, char) count++;
  ASSERT_COUNTS(count, 20);

  count = 0;
  CPPMACRO_LOOP_TYPED(FASTEST, 30, id, char) count++;
  ASSERT_COUNTS(count, 30);
}

void test_loop_macro_LOOP_TYPED_short() {
  int count = 0;

  count = 0;
  CPPMACRO_LOOP_TYPED(UP, 1000, id, short) count++;
  ASSERT_COUNTS(count, 1000);

  count = 0;
  CPPMACRO_LOOP_TYPED(DOWN, 2000, id, short) count++;
  ASSERT_COUNTS(count, 2000);

  count = 0;
  CPPMACRO_LOOP_TYPED(FASTEST, 3000, id, short) count++;
  ASSERT_COUNTS(count, 3000);
}

void test() {
  test_loop_macro_NTIMES();

  test_loop_macro_LOOP();
  test_loop_macro_LOOP_const();
  test_loop_macro_LOOP_TYPED_const();
  test_loop_macro_LOOP_TYPED_char();
  test_loop_macro_LOOP_TYPED_short();
  test_loop_macro_LOOP_TYPED_expr();
}
}  // namespace test_cxxloop_macros
main() {
  std::cout << "# testing" << __FILE__ << std::endl;
  test_cxxloop_macros::test();
  std::cout << "...EOTest" << std::endl;
  std::cout.flush();
}
