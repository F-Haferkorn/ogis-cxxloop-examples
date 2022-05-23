#pragma once
#include <iostream>
#include <string>

#define ASSERT_NOTED(as_is, to_be, text)         \
  if (as_is != to_be)                            \
  std::cout << __FILE__ << "\n"                  \
            << __FUNCTION__ << "\t" << std::endl \
            << "\t" << text << "\t" << as_is     \
            << " is NOT the expeted: " << to_be << std::endl

#define ASSERT_COUNTS(as_is, to_be) ASSERT_NOTED(as_is, to_be, "count")

inline void ASSERT_CONDITION(bool condition, const std::string &msg) {
  if (!condition)
    std::cout << __FILE__ << "\n" << __FUNCTION__ << "\t" << msg << std::endl;
  return;
}
