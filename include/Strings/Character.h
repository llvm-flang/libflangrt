//===--- Character.h - Character library  ------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBFLANG_STRINGS_CHARACTER_H
#define LLVM_LIBFLANG_STRINGS_CHARACTER_H

#include <stdint.h>
#include "Libflang.h"


LIBFLANG_ABI void libflang_assignment_char1(char *LHS, size_t LHSLength,
                                            char *RHS, size_t RHSLength);
LIBFLANG_ABI void libflang_concat_char1(char *Dest, size_t DestLength,
                                        char *LHS, size_t LHSLength,
                                        char *RHS, size_t RHSLength);
LIBFLANG_ABI int32_t libflang_compare_char1(const char *LHS, size_t LHSLength,
                                            const char *RHS, size_t RHSLength);

// intrinsics

LIBFLANG_ABI int32_t libflang_lexcompare_char1(const char *LHS, size_t LHSLength,
                                               const char *RHS, size_t RHSLength);

LIBFLANG_ABI size_t libflang_index_char1(const char *String, size_t Length,
                                         const char *SubString, size_t SubLength,
                                         int32_t Back);

LIBFLANG_ABI size_t libflang_lentrim_char1(const char *String, size_t Length);

#endif
