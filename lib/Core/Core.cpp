#include <cstdlib>
#include "Core/Core.h"

LIBFLANG_ABI void libflang_stop() {
  exit(0);
}

LIBFLANG_ABI int32_t libflang_selected_int_kind(int32_t Range) {
  if(Range <= 2)
    return 1;
  else if(Range <= 4)
    return 2;
  else if(Range <= 9)
    return 4;
  else if(Range <= 18)
    return 8;
  // NB: add Range <= 38 for Int16
  return -1;
}
