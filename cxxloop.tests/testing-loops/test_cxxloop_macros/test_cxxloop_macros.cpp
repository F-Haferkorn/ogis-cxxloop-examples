#include <iostream>
#include <loop>

#include "../macro.h"

namespace test_cxxloop_macros {
namespace {

long long sumup_slice(std::slice slice) {
  size_t sum = 0;
  auto id = slice.start();
  loop_postops(slice.size(), id += slice.stride()) { sum += id; }
  return sum;
}
size_t sumup_slice(size_t start, size_t size, size_t stride) {
  auto slice = std::slice(start, size, stride);
  return sumup_slice(slice);
}

void test_loop_macro_slice_base(size_t start, size_t size, size_t stride) {
  // std::cout << "CPPMACRO_SLICE(std::slice(" << start << "," << size << ","
  //         << stride << "), id) " << std::endl;
  size_t sum = 0, count = 0;
  CPPMACRO_SLICED(int, start, size, stride, id) {
    count++;
    sum += id;
  }
  ASSERT_COUNTS(count, size);
  ASSERT_NOTED(sum, sumup_slice(std::slice(start, size, stride)),
               "summup of ids");
}
}  // namespace

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

void test_loop_macro_SLICE() {
  int count = 0;
  size_t sum = 0;
  using T = int;

  CPPMACRO_SLICED(int, 10, 1000, 2, id) { count++; }
  ASSERT_COUNTS(count, 1000);

  test_loop_macro_slice_base(0, 10, 2);
  test_loop_macro_slice_base(10, 10, 5);
}

void test_loop_macro_LOOP() {
  int count = 0;

  count = 0;
  CPPMACRO_LOOP(NTIMES_UP, 1000, id) count++;
  ASSERT_COUNTS(count, 1000);

  count = 0;
  CPPMACRO_LOOP(NTIMES_DOWN, 2000, id) count++;
  ASSERT_COUNTS(count, 2000);

  count = 0;
  CPPMACRO_LOOP(NTIMES_FASTEST, 3000, id) count++;
  ASSERT_COUNTS(count, 3000);
}

void test_loop_macro_LOOP_const() {
  int count = 0;
  const int N = 100;
  count = 0;
  CPPMACRO_LOOP(NTIMES_UP, N, id) count++;
  ASSERT_COUNTS(count, N);

  count = 0;
  CPPMACRO_LOOP(NTIMES_DOWN, N, id) count++;
  ASSERT_COUNTS(count, N);

  count = 0;
  CPPMACRO_LOOP(NTIMES_FASTEST, N, id) count++;
  ASSERT_COUNTS(count, N);
}

void test_loop_macro_LOOP_expr() {
  int count = 0;
  const int N = 100;

  count = 0;
  CPPMACRO_LOOP(NTIMES_UP, N + 1, id) count++;
  ASSERT_COUNTS(count, N + 1);

  count = 0;
  CPPMACRO_LOOP(NTIMES_DOWN, N + 1, id) count++;
  ASSERT_COUNTS(count, N + 1);

  count = 0;
  CPPMACRO_LOOP(NTIMES_FASTEST, N + 1, id) count++;
  ASSERT_COUNTS(count, N + 1);
}

void test_loop_macro_LOOP_TYPED_const() {
  int count = 0;
  const int N = 100;

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_UP, N, id, char) count++;
  ASSERT_COUNTS(count, N);

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_DOWN, N, id, char) count++;
  ASSERT_COUNTS(count, N);

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_FASTEST, N, id, char) count++;
  ASSERT_COUNTS(count, N);
}

void test_loop_macro_LOOP_TYPED_expr() {
  int count = 0;
  const int N = 100;

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_UP, N + 1, id, char) count++;
  ASSERT_COUNTS(count, N + 1);

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_DOWN, N + 1, id, char) count++;
  ASSERT_COUNTS(count, N + 1);

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_FASTEST, N + 1, id, char) count++;
  ASSERT_COUNTS(count, N + 1);
}

void test_loop_macro_LOOP_TYPED_char() {
  int count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_UP, 10, id, char) count++;
  ASSERT_COUNTS(count, 10);

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_DOWN, 20, id, char) count++;
  ASSERT_COUNTS(count, 20);

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_FASTEST, 30, id, char) count++;
  ASSERT_COUNTS(count, 30);
}

void test_loop_macro_LOOP_TYPED_short() {
  int count = 0;

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_UP, 1000, id, short) count++;
  ASSERT_COUNTS(count, 1000);

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_DOWN, 2000, id, short) count++;
  ASSERT_COUNTS(count, 2000);

  count = 0;
  CPPMACRO_LOOP_TYPED(NTIMES_FASTEST, 3000, id, short) count++;
  ASSERT_COUNTS(count, 3000);
}

void test() {
  test_loop_macro_NTIMES();

  test_loop_macro_SLICE();

  test_loop_macro_LOOP();
  test_loop_macro_LOOP_const();
  test_loop_macro_LOOP_TYPED_const();
  test_loop_macro_LOOP_TYPED_char();
  test_loop_macro_LOOP_TYPED_short();
  test_loop_macro_LOOP_TYPED_expr();
}
}  // namespace test_cxxloop_macros
int main() {
  std::cout << "# testing" << __FILE__ << std::endl;
  test_cxxloop_macros::test();
  std::cout << "...EOTest" << std::endl;
  std::cout.flush();
}
