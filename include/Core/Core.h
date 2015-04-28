//===--- Core.h - Core library  --------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBFLANG_CORE_H
#define LLVM_LIBFLANG_CORE_H

#include "Libflang.h"
#include <stdint.h>

LIBFLANG_ABI void libflang_stop();

LIBFLANG_ABI int32_t libflang_selected_int_kind(int32_t Range);

#endif
