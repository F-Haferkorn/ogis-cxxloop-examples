#include <loop>

#include "macro.h"
namespace test_cxxloop_typed {  // namespace test_cxxloop
namespace loop_hh {
namespace plain {
void test_loop_hh() {
  int count = 0;
  int Mval = 100;
  int &Mref = Mval;
  int &&Mrval = Mval / 4;

  count = 0;
  loop_hh(Mval) count++;

  count = 0;
  loop_hh(Mval) loop_hh(Mval) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_hh(Mval) loop_hh(Mval) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_hh(Mref) loop_hh(Mref) loop_hh(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_hh(Mrval) loop_hh(Mrval) loop_hh(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}
void test_loop_hh_const() {
  int count = 0;
  const int Mval = 100;
  const int &Mref = Mval;
  const int &&Mrval = Mval / 4;

  count = 0;
  loop_hh(Mval) loop_hh(Mval) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_hh(Mval) loop_hh(Mval) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_hh(Mref) loop_hh(Mref) loop_hh(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_hh(Mrval) loop_hh(Mrval) loop_hh(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}

void test() {
  test_loop_hh();
  test_loop_hh_const();
}
}  // namespace plain

namespace up {
void test_loop_hh() {
  int count = 0;
  int Mval = 100;
  int &Mref = Mval;
  int &Mrval = Mval;

  count = 0;
  loop_up_hh(Mval, up) loop_down_hh(Mval, down) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_up_hh(Mval, up) loop_down_hh(Mval, down) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_up_hh(Mref, up) loop_down_hh(Mref, down) loop_hh(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_up_hh(Mrval, up) loop_down_hh(Mrval, down) loop_hh(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}

void test_loop_hh_const() {
  int count = 0;
  const int Mval = 100;
  const int &Mref = Mval;
  const int &Mrval = Mval;

  count = 0;
  loop_up_hh(Mval, up) loop_down_hh(Mval, down) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_up_hh(Mval, up) loop_down_hh(Mval, down) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_up_hh(Mref, up) loop_down_hh(Mref, down) loop_hh(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_up_hh(Mrval, up) loop_down_hh(Mrval, down) loop_hh(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}

void test() {
  test_loop_hh();
  test_loop_hh_const();
}

}  // namespace up
namespace down {
void test_loop_hh() {
  int count = 0;
  int Mval = 100;
  int &Mref = Mval;
  int &Mrval = Mval;

  count = 0;
  loop_down_hh(Mval, up) loop_down_hh(Mval, down) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_down_hh(Mval, up) loop_down_hh(Mval, down) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_down_hh(Mref, up) loop_down_hh(Mref, down) loop_hh(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_down_hh(Mrval, up) loop_down_hh(Mrval, down) loop_hh(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}

void test_loop_hh_const() {
  int count = 0;
  const int Mval = 100;
  const int &Mref = Mval;
  const int &Mrval = Mval;

  count = 0;
  loop_down_hh(Mval, up) loop_down_hh(Mval, down) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_down_hh(Mval, up) loop_down_hh(Mval, down) loop_hh(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_down_hh(Mref, up) loop_down_hh(Mref, down) loop_hh(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_down_hh(Mrval, up) loop_down_hh(Mrval, down) loop_hh(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}

void test() {
  test_loop_hh();
  test_loop_hh_const();
}

}  // namespace down
void test() {
  plain::test();
  up::test();
  down::test();
}

}  // namespace loop_hh
namespace loop_h {
namespace plain {
void test_loop_h() {
  int count = 0;
  int Mval = 100;
  int &Mref = Mval;
  int &&Mrval = Mval / 4;

  count = 0;
  loop_h(Mval) count++;

  count = 0;
  loop_h(Mval) loop_h(Mval) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_h(Mval) loop_h(Mval) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_h(Mref) loop_h(Mref) loop_h(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_h(Mrval) loop_h(Mrval) loop_h(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}
void test_loop_h_const() {
  int count = 0;
  const int Mval = 100;
  const int &Mref = Mval;
  const int &&Mrval = Mval / 4;

  count = 0;
  loop_h(Mval) loop_h(Mval) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_h(Mval) loop_h(Mval) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_h(Mref) loop_h(Mref) loop_h(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_h(Mrval) loop_h(Mrval) loop_h(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}
void test() {
  test_loop_h();
  test_loop_h_const();
}

}  // namespace plain

namespace up {
void test_loop_h() {
  int count = 0;
  int Mval = 100;
  int &Mref = Mval;
  int &Mrval = Mval;

  count = 0;
  loop_up_h(Mval, up) loop_down_h(Mval, down) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_up_h(Mval, up) loop_down_h(Mval, down) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_up_h(Mref, up) loop_down_h(Mref, down) loop_h(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_up_h(Mrval, up) loop_down_h(Mrval, down) loop_h(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}

void test_loop_h_const() {
  int count = 0;
  const int Mval = 100;
  const int &Mref = Mval;
  const int &Mrval = Mval;

  count = 0;
  loop_up_h(Mval, up) loop_down_h(Mval, down) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_up_h(Mval, up) loop_down_h(Mval, down) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_up_h(Mref, up) loop_down_h(Mref, down) loop_h(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_up_h(Mrval, up) loop_down_h(Mrval, down) loop_h(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}

void test() {
  test_loop_h();
  test_loop_h_const();
}

}  // namespace up
namespace down {
void test_loop_h() {
  int count = 0;
  int Mval = 100;
  int &Mref = Mval;
  int &Mrval = Mval;

  count = 0;
  loop_down_h(Mval, up) loop_down_h(Mval, down) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_down_h(Mval, up) loop_down_h(Mval, down) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_down_h(Mref, up) loop_down_h(Mref, down) loop_h(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_down_h(Mrval, up) loop_down_h(Mrval, down) loop_h(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}

void test_loop_h_const() {
  int count = 0;
  const int Mval = 100;
  const int &Mref = Mval;
  const int &Mrval = Mval;

  count = 0;
  loop_down_h(Mval, up) loop_down_h(Mval, down) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_down_h(Mval, up) loop_down_h(Mval, down) loop_h(Mval) count++;
  ASSERT_COUNTS(count, Mval * Mval * Mval);

  count = 0;
  loop_down_h(Mref, up) loop_down_h(Mref, down) loop_h(Mref) count++;
  ASSERT_COUNTS(count, Mref * Mref * Mref);

  count = 0;
  loop_down_h(Mrval, up) loop_down_h(Mrval, down) loop_h(Mrval) count++;
  ASSERT_COUNTS(count, Mrval * Mrval * Mrval);
}

void test() {
  test_loop_h();
  test_loop_h_const();
}

}  // namespace down

void test() {
  plain::test();
  up::test();
  down::test();
}

}  // namespace loop_h
void test() {
  loop_h::test();
  loop_hh::test();
}
}  // namespace test_cxxloop_typed

int main() {
  std::cout << "# testing" << __FILE__ << std::endl;
  test_cxxloop_typed::test();
  std::cout << "... END-of-Test" << std::endl;
  std::cout.flush();
}
