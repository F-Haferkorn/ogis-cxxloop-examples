#pragma once
#include <iostream>

namespace asciishapes {

///////// basic primitives

inline void star() {
  std::cout.put('*'); ///< write a single star character '*'
}
inline void space() {
  std::cout.put(' '); ///< write a single space character ' '
}
inline void newline() {
  std::cout.put('\n'); ///< write a single newline character '\n'
}

} // namespace asciishapes
