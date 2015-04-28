//===--- Write.h - Write implementation -------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBFLANG_IO_WRITE_H
#define LLVM_LIBFLANG_IO_WRITE_H

#include <stdint.h>
#include "Libflang.h"

struct WriteController {
  const char *FormatPtr;
  size_t FormatLength;
  int32_t unit;
  uint32_t flags;
};

LIBFLANG_ABI void libflang_write_start(WriteController *Controller);
LIBFLANG_ABI void libflang_write_integer(WriteController *Controller, const void *Ptr, int32_t Size);
LIBFLANG_ABI void libflang_write_real(WriteController *Controller, const void *Ptr, int32_t Size);
LIBFLANG_ABI void libflang_write_complex(WriteController *Controller, const void *Ptr, int32_t Size);
LIBFLANG_ABI void libflang_write_logical(WriteController *Controller, const void *Ptr, int32_t Size);
LIBFLANG_ABI void libflang_write_character(WriteController *Controller, const char *Ptr, size_t Length);
LIBFLANG_ABI void libflang_write_end(WriteController *Controller);

#endif
