
#include <cassert>
#include <cstdint>
#include <iostream>
#include <loop>

#include "../macro.h"
typedef unsigned short ushort;
typedef unsigned char uchar;

#include <type_traits>

#define IS_SAME_TYPE(base_type, tgt_type) \
  std::is_same<base_type, tgt_type>::value
namespace test_cxxloop_ttraits {
namespace unsigendness_to_char {

void ttraits_copy_unsigendness_to_char_t_signed() {
  ASSERT_CONDITION(IS_SAME_TYPE(ogis::copy_unsigendness_to_char_t<int>, char),
                   "copy_unsigendness_to_char_t<int > is not "
                   "char");
}
void ttraits_copy_unsigendness_to_char_t_unsigned() {
  ASSERT_CONDITION(IS_SAME_TYPE(ogis::copy_unsigendness_to_char_t<unsigned int>,
                                unsigned char),
                   "copy_unsigendness_to_char_t<unsigned int > is not "
                   "unsiged char");
}

void test() {
  ttraits_copy_unsigendness_to_char_t_signed();
  ttraits_copy_unsigendness_to_char_t_unsigned();
}

}  // namespace unsigendness_to_char
namespace unsigendness_to_short {
void ttraits_copy_unsigendness_to_short_t_signed() {
  ASSERT_CONDITION(IS_SAME_TYPE(ogis::copy_unsigendness_to_short_t<int>, short),
                   "copy_unsigendness_to_short_t<int > is not "
                   "unsiged short");
}
void ttraits_copy_unsigendness_to_short_t_unsigned() {
  ASSERT_CONDITION(
      IS_SAME_TYPE(ogis::copy_unsigendness_to_short_t<unsigned int>,
                   unsigned short),
      "copy_unsigendness_to_short_t<unsigned int > is not "
      "unsiged short");
}
void test() {
  ttraits_copy_unsigendness_to_short_t_signed();
  ttraits_copy_unsigendness_to_short_t_unsigned();
}

}  // namespace unsigendness_to_short

namespace remove_cvreference {
void ttraits_remove_cvreference_plain() {
  ASSERT_CONDITION(IS_SAME_TYPE(ogis::remove_cvref_t<int>, int),
                   "remove_cvreferencet<int > is not "
                   "int");
}
void ttraits_remove_cvreference_volatile() {
  ASSERT_CONDITION(IS_SAME_TYPE(ogis::remove_cvref_t<volatile int>, int),
                   "remove_cvref_t<volatile int > is not "
                   "int");
}
void ttraits_remove_cvreference_reference() {
  ASSERT_CONDITION(IS_SAME_TYPE(ogis::remove_cvref_t<int &>, int),
                   "remove_cvref_t<int &> is not "
                   "int");
}

void ttraits_remove_cvreference_rvalue() {
  ASSERT_CONDITION(IS_SAME_TYPE(ogis::remove_cvref_t<int &&>, int),
                   "remove_cvref_t<int &&> is not "
                   "int");
}

void ttraits_remove_cvreference_const_rvalue() {
  ASSERT_CONDITION(IS_SAME_TYPE(ogis::remove_cvref_t<const int &&>, int),
                   "remove_cvref_t<const int &&> is not "
                   "int");
}

void ttraits_remove_cvreference_const_reference() {
  ASSERT_CONDITION(IS_SAME_TYPE(ogis::remove_cvref_t<const int &>, int),
                   "remove_cvref_t<const int &> is not "
                   "int");
}

void ttraits_remove_cvreference_const_ref_volatile() {
  ASSERT_CONDITION(
      IS_SAME_TYPE(ogis::remove_cvref_t<const volatile int &>, int),
      "remove_cvref_t<const volatile int&> is not "
      "int");
}

void ttraits_remove_cvreference_const_volatile() {
  ASSERT_CONDITION(IS_SAME_TYPE(ogis::remove_cvref_t<const volatile int>, int),
                   "remove_cvref_t<const volatile int> is not "
                   "int");
}

void test() {
  ttraits_remove_cvreference_plain();
  ttraits_remove_cvreference_volatile();
  ttraits_remove_cvreference_reference();
  ttraits_remove_cvreference_rvalue();
  ttraits_remove_cvreference_const_ref_volatile();
  ttraits_remove_cvreference_const_volatile();
}

}  // namespace remove_cvreference

void test() {
  unsigendness_to_char::test();
  unsigendness_to_short::test();
  remove_cvreference::test();
}
}  // namespace test_cxxloop_ttraits

int main() {
  std::cout << "# testing" << __FILE__ << std::endl;
  test_cxxloop_ttraits::test();
  std::cout << "... END-of-Test" << std::endl;
  std::cout.flush();
}
