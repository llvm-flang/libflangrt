#include <complex>
#include "Numerical/Complex.h"

using namespace std;

static inline Complex8 cmplx(complex<double> Value) {
  Complex8 Result = { Value.real(), Value.imag() };
  return Result;
}

static inline Complex4 cmplx(complex<float> Value) {
  Complex4 Result = { Value.real(), Value.imag() };
  return Result;
}

static inline complex<double> generic(double Re, double Im) {
  return complex<double>(Re, Im);
}

static inline complex<float> generic(float Re, float Im) {
  return complex<float>(Re, Im);
}

LIBFLANG_ABI void libflang_cpow(double LHSRe, double LHSIm,
                                double RHSRe, double RHSIm,
                                Complex8 *Result) {
  *Result = cmplx(pow(generic(LHSRe, LHSIm),
                    generic(RHSRe, RHSIm)));
}
LIBFLANG_ABI void libflang_cpowf(float LHSRe, float LHSIm,
                                 float RHSRe, float RHSIm,
                                 Complex4 *Result) {
  *Result = cmplx(pow(generic(LHSRe, LHSIm),
                    generic(RHSRe, RHSIm)));
}

LIBFLANG_ABI void libflang_cpowi(double Re, double Im,
                                 int32_t power,
                                 Complex8 *Result) {
  *Result = cmplx(pow(generic(Re, Im), power));
}
LIBFLANG_ABI void libflang_cpowif(float Re, float Im,
                                  int32_t power,
                                  Complex4 *Result) {
  *Result = cmplx(complex<float>(pow(generic(Re, Im), power)));
}

// intrinsics

LIBFLANG_ABI double libflang_cabs(double Re, double Im) {
  return abs(generic(Re, Im));
}
LIBFLANG_ABI float libflang_cabsf(float Re, float Im) {
  return abs(generic(Re, Im));
}

LIBFLANG_ABI void libflang_csqrt(double Re, double Im,
                                 Complex8 *Result) {
  *Result = cmplx(sqrt(generic(Re, Im)));
}
LIBFLANG_ABI void libflang_csqrtf(float Re, float Im,
                                  Complex4 *Result) {
  *Result = cmplx(sqrt(generic(Re, Im)));
}

LIBFLANG_ABI void libflang_cexp(double Re, double Im,
                                Complex8 *Result) {
  *Result = cmplx(exp(generic(Re, Im)));
}
LIBFLANG_ABI void libflang_cexpf(float Re, float Im,
                                 Complex4 *Result) {
  *Result = cmplx(exp(generic(Re, Im)));
}

LIBFLANG_ABI void libflang_clog(double Re, double Im,
                                Complex8 *Result) {
  *Result = cmplx(log(generic(Re, Im)));
}
LIBFLANG_ABI void libflang_clogf(float Re, float Im,
                                 Complex4 *Result) {
  *Result = cmplx(log(generic(Re, Im)));
}

LIBFLANG_ABI void libflang_csin(double Re, double Im,
                                Complex8 *Result) {
  *Result = cmplx(sin(generic(Re, Im)));
}
LIBFLANG_ABI void libflang_csinf(float Re, float Im,
                                 Complex4 *Result) {
  *Result = cmplx(sin(generic(Re, Im)));
}

LIBFLANG_ABI void libflang_ccos(double Re, double Im,
                                Complex8 *Result) {
  *Result = cmplx(cos(generic(Re, Im)));
}
LIBFLANG_ABI void libflang_ccosf(float Re, float Im,
                                 Complex4 *Result) {
  *Result = cmplx(cos(generic(Re, Im)));
}

LIBFLANG_ABI void libflang_ctan(double Re, double Im,
                                Complex8 *Result) {
  *Result = cmplx(tan(generic(Re, Im)));
}
LIBFLANG_ABI void libflang_ctanf(float Re, float Im,
                                 Complex4 *Result) {
  *Result = cmplx(tan(generic(Re, Im)));
}
