//===-- ipow.cpp - Test libflang_pow_i*_i* --------------------------------===//
//
// The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <assert.h>
#include <iostream>
#include "Numerical/Integer.h"

static bool testPowI4(int32_t x, int32_t y, int32_t expected) {
  x = libflang_pow_i4_i4(x, y);
  if(x != expected)
    std::cout << "Error in libflang_pow_i4_i4 - expected " << expected
              << ", got " << x << std::endl;
  return x != expected;
}

int main() {
  if(testPowI4(2,2,4))
    return 1;
  if(testPowI4(3,3,27))
    return 1;
  if(testPowI4(4,1,4))
    return 1;
  if(testPowI4(5,0,1))
    return 1;
  if(testPowI4(6,-1,0))
    return 1;
  if(testPowI4(-1,2,1))
    return 1;
  if(testPowI4(-1,-1,0))
    return 1;
  if(testPowI4(1000,2,1000000))
    return 1;
  if(testPowI4(1000,3,1000000000))
    return 1;
  return 0;
}
