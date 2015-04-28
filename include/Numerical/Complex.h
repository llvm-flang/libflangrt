//===--- Complex.h - Complex numbers library --------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBFLANG_NUMERICAL_COMPLEX_H
#define LLVM_LIBFLANG_NUMERICAL_COMPLEX_H

#include "Libflang.h"

struct Complex4 {
  float Re, Im;
};

struct Complex8 {
  double Re, Im;
};

LIBFLANG_ABI void libflang_cpow(double LHSRe, double LHSIm,
                                double RHSRe, double RHSIm,
                                Complex8 *Result);
LIBFLANG_ABI void libflang_cpowf(float LHSRe, float LHSIm,
                                 float RHSRe, float RHSIm,
                                 Complex4 *Result);

LIBFLANG_ABI void libflang_cpowi(double Re, double Im,
                                 int32_t power, Complex8 *Result);
LIBFLANG_ABI void libflang_cpowif(float Re, float Im,
                                  int32_t power, Complex4 *Result);

// intrinsics

LIBFLANG_ABI double libflang_cabs(double Re, double Im);
LIBFLANG_ABI float  libflang_cabsf(float Re, float Im);

LIBFLANG_ABI void libflang_csqrt(double Re, double Im,
                                 Complex8 *Result);
LIBFLANG_ABI void libflang_csqrtf(float Re, float Im,
                                  Complex4 *Result);

LIBFLANG_ABI void libflang_cexp(double Re, double Im,
                                Complex8 *Result);
LIBFLANG_ABI void libflang_cexpf(float Re, float Im,
                                 Complex4 *Result);

LIBFLANG_ABI void libflang_clog(double Re, double Im,
                                Complex8 *Result);
LIBFLANG_ABI void libflang_clogf(float Re, float Im,
                                 Complex4 *Result);

LIBFLANG_ABI void libflang_csin(double Re, double Im,
                                Complex8 *Result);
LIBFLANG_ABI void libflang_csinf(float Re, float Im,
                                 Complex4 *Result);

LIBFLANG_ABI void libflang_ccos(double Re, double Im,
                                Complex8 *Result);
LIBFLANG_ABI void libflang_ccosf(float Re, float Im,
                                 Complex4 *Result);

LIBFLANG_ABI void libflang_ctan(double Re, double Im,
                                Complex8 *Result);
LIBFLANG_ABI void libflang_ctanf(float Re, float Im,
                                 Complex4 *Result);

#endif
