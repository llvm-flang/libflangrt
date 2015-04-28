//===-- index.cpp - Test libflang_index_char* -----------------------------===//
//
// The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <assert.h>
#include <string.h>
#include <iostream>
#include "Strings/Character.h"

static bool testIndex(const char *str, const char *substr, size_t expected, bool back = false) {
  auto x = libflang_index_char1(str, strlen(str), substr, strlen(substr),
                                back? 1:0);
  if(x != expected)
    std::cout << "Error in libflang_index - expected " << expected
              << ", got " << x << std::endl;
  return x != expected;
}

int main() {
  if(testIndex("FORTRAN","R",3))
    return 1;
  if(testIndex("FORTRAN","R",5,true))
    return 1;
  if(testIndex("hello","ell",2))
    return 1;
  if(testIndex("hello","ell",2,true))
    return 1;
  if(testIndex("hello","world",0))
    return 1;
  if(testIndex("hello","world",0,true))
    return 1;
  if(testIndex("A","a",0))
    return 1;
  if(testIndex("hell","hello",0))
    return 1;
  if(testIndex("hell","hello",0,true))
    return 1;
  if(testIndex("hello","",1))
    return 1;
  if(testIndex("hello","",6,true))
    return 1;
  return 0;
}

