//===--- System.h - The system library  -------------------------*- C++ -*-===//
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

LIBFLANG_ABI void  libflang_sys_init();

LIBFLANG_ABI void *libflang_malloc(size_t size);
LIBFLANG_ABI void  libflang_free(void *ptr);

LIBFLANG_ABI double libflang_etime(double *time0, double *time1);
LIBFLANG_ABI float  libflang_etimef(float *time0, float *time1);

#endif
