#include <sys/time.h>
#include <stdint.h>
#include "stdlib.h"
#include "System/System.h"

// FIXME: windows support.

static timeval programStart;

LIBFLANG_ABI void libflang_sys_init() {
  gettimeofday(&programStart, nullptr);
}

LIBFLANG_ABI void *libflang_malloc(size_t size) {
  return malloc(size);
}

LIBFLANG_ABI void  libflang_free(void *ptr) {
  free(ptr);
}

template<typename T>
static T etime(T *time0, T* time1) {
  timeval stop;
  gettimeofday(&stop, nullptr);
  int64_t diff = stop.tv_usec - programStart.tv_usec;

  *time0 = T(double(diff) / 1000000.0);
  *time1 = T(0.0);
  return *time0 + *time1;
}

LIBFLANG_ABI double libflang_etime(double *time0, double *time1) {
  return etime(time0, time1);
}

LIBFLANG_ABI float libflang_etimef(float *time0, float *time1) {
  return etime(time0, time1);
}
