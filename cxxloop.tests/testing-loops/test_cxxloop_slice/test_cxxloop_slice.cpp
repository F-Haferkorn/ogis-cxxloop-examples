#include <loop>
#include <vector>

#include "macro.h"
namespace test_cxxloop_special {  // namespace test_cxxloop

namespace slice {

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

template <typename T>
void test_loop_slice_plain(T start, int size, int stride) {
  auto be_verbose = 1;

  auto v0 = std::vector<size_t>();

  for (int i = 0; i < size; i++) v0.push_back(start + i * stride);

  if (be_verbose > 0)
    std::cout << "CPPMACRO_SLICE(std::slice(" << int(start) << "," << int(size)
              << "," << stride << "), id) " << std::endl;
  size_t sum = 0, count = 0;
  char tab = '\t';

  auto v1 = std::vector<size_t>();
  loop_slice(start, size, stride, id) {
    v1.push_back(id);
    count++;
    sum += id;
    if (be_verbose > 1)
      std::cout << start << tab << size << tab << id << tab << count << tab
                << sum << std::endl;
  }
  if (count == 0) {
    count = count + 1;
    count = count - 1;
  }

  ASSERT_COUNTS(count, size);
  ASSERT_NOTED(sum, sumup_slice(std::slice(start, size, stride)),
               "summup of ids");
  ASSERT_CONDITION(v0 == v1, "index vars do not match!");
  if (be_verbose > 0 || v0 != v1) {
    std::cout << "v0: ";
    for (auto v : v0) std::cout << v << "\t";
    std::cout << std::endl;

    std::cout << "v1: ";
    for (auto v : v1) std::cout << v << "\t";
    std::cout << std::endl;
  }
}

template <typename T>
void test_loop_slice_postops(T start, int size, int stride) {
  auto be_verbose = 1;

  auto v0 = std::vector<size_t>();

  for (int i = 0; i < size; i++) v0.push_back(start + i * stride);

  if (be_verbose > 0)
    std::cout << "CPPMACRO_SLICE(std::slice(" << int(start) << "," << int(size)
              << "," << stride << "), id) " << std::endl;
  size_t sum = 0, count = 0;
  char tab = '\t';

  auto v1 = std::vector<size_t>();
  loop_slice_postops(start, size, stride, id, count++, count++, count++) {
    v1.push_back(id);
    count++;
    sum += id;
    if (be_verbose > 1)
      std::cout << start << tab << size << tab << id << tab << count << tab
                << sum << std::endl;
  }
  if (count == 0) {
    count = count + 1;
    count = count - 1;
  }

  ASSERT_COUNTS(count, 4 * size);
  ASSERT_NOTED(sum, sumup_slice(std::slice(start, size, stride)),
               "summup of ids");
  ASSERT_CONDITION(v0 == v1, "index vars do not match!");
  if (be_verbose > 0 || v0 != v1) {
    std::cout << "v0: ";
    for (auto v : v0) std::cout << v << "\t";
    std::cout << std::endl;

    std::cout << "v1: ";
    for (auto v : v1) std::cout << v << "\t";
    std::cout << std::endl;
  }
}

template <typename T>
void test_loop_slice_postops2(T start, int size, int stride) {
  bool be_verbose = false;

  if (be_verbose)
    std::cout << "CPPMACRO_SLICE(std::slice(" << int(start) << "," << int(size)
              << "," << stride << "), id) " << std::endl;
  size_t sum = 0, count = 0;
  char tab = '\t';
  loop_slice_postops(start, size, stride, id, count++, count++) {
    count++;
    sum += id;
    if (be_verbose)
      std::cout << start << tab << size << tab << id << tab << count << tab
                << sum << std::endl;
  }

  ASSERT_COUNTS(count, 3 * size);
  ASSERT_NOTED(sum, sumup_slice(std::slice(start, size, stride)),
               "summup of ids");
}

}  // namespace

template <typename T>
void test_loop_slice() {
  int count = 0;
  size_t sum = 0;
  T start = 10;

  auto slice = std::slice();
  loop_slice(10, 1000, 2, id) { count++; }
  ASSERT_COUNTS(count, 1000);

  test_loop_slice_plain<T>(start, 2, 2);
  test_loop_slice_plain<T>(start, 2, 1);
  test_loop_slice_plain<T>(start, 2, -1);
  test_loop_slice_plain<T>(start, 2, 2);

  std::cout << std::endl << "test_loop_slice_postops" << std::endl;
  test_loop_slice_postops<T>(start, 2, 3);
  test_loop_slice_postops<T>(start, 2, 3);
  test_loop_slice_postops<T>(start, 2, -2);
  test_loop_slice_postops<T>(start, 5, 5);
}

void test() {
  /// signed
  test_loop_slice<long long>();
  test_loop_slice<long>();
  test_loop_slice<int>();
  test_loop_slice<short>();
  test_loop_slice<char>();

  /// unsigned
  test_loop_slice<unsigned long long>();
  test_loop_slice<unsigned long>();
  test_loop_slice<unsigned int>();
  test_loop_slice<unsigned short>();
  test_loop_slice<unsigned char>();

  /// const signed
  test_loop_slice<const long long>();
  test_loop_slice<const long>();
  test_loop_slice<const int>();
  test_loop_slice<const short>();
  test_loop_slice<const char>();

  /// const unsigned
  test_loop_slice<const unsigned long long>();
  test_loop_slice<const unsigned long>();
  test_loop_slice<const unsigned int>();
  test_loop_slice<const unsigned short>();
  test_loop_slice<const unsigned char>();

  /// all CPPMACRO_NTIMES_DOWN_*  do not sopport CONST indexTypes!
}

}  // namespace slice
void test() { slice::test(); }
}  // namespace test_cxxloop_special

int main() {
  std::cout << "# testing" << __FILE__ << std::endl;
  test_cxxloop_special::test();
  std::cout << "... END-of-Test" << std::endl;
  std::cout.flush();
}
