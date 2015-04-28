//===-- selected_int_kind.cpp - Test libflang_selected_int_kind -----------===//
//
// The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <assert.h>
#include <iostream>
#include "Core/Core.h"

static bool test(int32_t x, int32_t expected) {
  x = libflang_selected_int_kind(x);
  if(x != expected)
    std::cout << "Error in libflang_selected_int_kind - expected " << expected
              << ", got " << x << std::endl;
  return x != expected;
}

int main() {
  if(test(-2, 1))
    return 1;
  if(test(1,1))
    return 1;
  if(test(7,4))
    return 1;
  if(test(13,8))
    return 1;
  if(test(1000,-1))
    return 1;
  return 0;
}

