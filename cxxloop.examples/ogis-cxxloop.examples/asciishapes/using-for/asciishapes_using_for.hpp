#pragma once

#include "../asciiart.hpp"

namespace asciishapes {
namespace using_for {

void demo();

// print same asciishapes, but use  classic for(;;) compound
void square(short noRows, short noColumns);
void triangular(short noRows);
void triangular_upside(short nofRows);

void centered_triangular(short nofRows);
void centered_triangular_upside(short nofRows);
void sandclock(short noRows);
}  // namespace using_for
}  // namespace asciishapes
