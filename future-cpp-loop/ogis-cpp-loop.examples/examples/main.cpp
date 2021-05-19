#include "asciishapes.hpp"
#include "matrix.hpp"
#include <vector>

#include <iostream>

void example_matrix();

void ogis_loop_godbolt_example();

void test_loops();

int main() {
  using namespace asciishapes;

  std::cout << "############ asciishapes::using LOOP" << std::endl;
  asciishapes::using_loop::demo(); // demo using  LOOP()  COMPOUNDS

  newline();
  newline();

  std::cout << "############ asciishapes::using FOR" << std::endl;
  asciishapes::using_for::demo(); // demo using  FOR(;;) COMPOUNDS

  // some more realistic examples of matrix operations using the new
  // compound-statements
  example_matrix();

  // validating behaviour of unsigned index variable here (size_t)
  auto v0 = std::vector<int>(0);
  auto v10 = std::vector<int>(10);
  std::cout << "looping empty-vector" << std::endl;
  loop(v0.size()) star();
  newline();

  /*  // does NOT compile
  loop(std::integral_constant<int, 10>::value)
          star();
  */

  std::cout << "looping 10-element--vector" << std::endl;
  named_loop_down(i, v10.size()) star();
  newline();

  unsigned int count = 4;
  named_loop_up(row, count) star();
  newline();

  named_loop_down(row, count) star();
  newline();

  ogis_loop_godbolt_example();
  newline();
  test_loops();

  return 0;
}
