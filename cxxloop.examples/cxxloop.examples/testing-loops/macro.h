#pragma once
#include <iostream>

#define ASSERT_COUNTS(count, tobe_count)                                  \
  if (count != tobe_count)                                                \
  std::cout << __FUNCTION__ << "\t" << std::endl                          \
            << "\t"                                                       \
            << "count " << count << " is NOT the expeted: " << tobe_count \
            << std::endl

inline void ASSERT_CONDITION(bool condition, const std::string &msg) {
  if (!condition) std::cout << __FUNCTION__ << "\t" << msg << std::endl;
  return;
}
