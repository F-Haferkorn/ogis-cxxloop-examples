#pragma once

#define __cpp_has_cpploop 20220301UL
#define __cpp_has_cpploop_postops __cpp_has_cpploop
#define __cpp_has_cpploop_slice __cpp_has_cpploop

#if !defined __cplusplus
#error("the compound group LOOP does not work with any version of C like C99, C11 or others")
#endif

#include "cxxloop.h"
#include "cxxloop_postops.h"
