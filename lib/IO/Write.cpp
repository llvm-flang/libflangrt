#include <stdio.h>
#include <string.h>
#include "IO/Write.h"

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

static void InvalidSizeError(WriteController *Controller, int32_t Size) {
  // FIXME
}

template<typename T>
static T getValue(const void *Ptr) {
  return *(reinterpret_cast<const T*>(Ptr));
}

template<typename T>
static T getValue(const void *Ptr,size_t I) {
  return (reinterpret_cast<const T*>(Ptr))[I];
}

static int getIntValue(WriteController *Controller, const void *Ptr, int32_t Size) {
  switch(Size) {
  case 1:
    return getValue<int8_t>(Ptr);
  case 2:
    return getValue<int16_t>(Ptr);
  case 4:
    return getValue<int32_t>(Ptr);
  case 8:
    return int(getValue<int64_t>(Ptr));
  default:
    InvalidSizeError(Controller, Size);
    break;
  }
  return 0;
}

static FILE *getFilePtr(WriteController *Controller) {
  return stdout;
}

class Buffer {
  enum {
    kStorageSize = 128
  };
  size_t Offset;
  char Storage[kStorageSize];

public:
  Buffer() : Offset(0) {}

  template <typename T>
  void Print(const char *FMT, T Value) {
    auto Remaining = size_t(kStorageSize)-Offset;
    if(Remaining)
      Offset += snprintf(Storage + Offset, Remaining, FMT, Value);
  }

  void Write(WriteController *Controller) {
    fwrite(Storage, 1, Offset, getFilePtr(Controller));
  }
};

template <typename T>
static inline void SmallPrintf(WriteController *Controller, const char *FMT, T Value) {
  Buffer Buf;
  Buf.Print(FMT, Value);
  Buf.Write(Controller);
}

template <typename T1, typename T2>
static inline void SmallPrintf(WriteController *Controller, const char *FMT1, T1 Value1, const char *FMT2, T2 Value2) {
  Buffer Buf;
  Buf.Print(FMT1, Value1);
  Buf.Print(FMT2, Value2);
  Buf.Write(Controller);
}

LIBFLANG_ABI void libflang_write_start(WriteController *Controller) {

}

LIBFLANG_ABI void libflang_write_integer(WriteController *Controller, const void *Ptr, int32_t Size) {
  SmallPrintf(Controller, "%i", getIntValue(Controller, Ptr, Size));
}

LIBFLANG_ABI void libflang_write_real(WriteController *Controller, const void *Ptr, int32_t Size) {
  switch(Size) {
  case 4:
    SmallPrintf(Controller, "%g", getValue<float>(Ptr));
    break;
  case 8:
    SmallPrintf(Controller, "%g", getValue<double>(Ptr));
    break;
  default:
    InvalidSizeError(Controller, Size);
    break;
  }
}

LIBFLANG_ABI void libflang_write_complex(WriteController *Controller, const void *Ptr, int32_t Size) {
  switch(Size) {
  case 4:
    SmallPrintf(Controller, "(%g, ", getValue<float>(Ptr), "%g)", getValue<float>(Ptr,1));
    break;
  case 8:
    SmallPrintf(Controller, "(%g, ", getValue<double>(Ptr), "%g)", getValue<double>(Ptr,1));
    break;
  default:
    InvalidSizeError(Controller, Size);
    break;
  }
}

LIBFLANG_ABI void libflang_write_logical(WriteController *Controller, const void *Ptr, int32_t Size) {
  SmallPrintf(Controller, "%s", getIntValue(Controller, Ptr, Size) != 0? "true" : "false");
}

LIBFLANG_ABI void libflang_write_character(WriteController *Controller, const char *Ptr, size_t Length) {
  fwrite(Ptr, 1, Length, getFilePtr(Controller));
}

LIBFLANG_ABI void libflang_write_end(WriteController *Controller) {
  fwrite("\n", 1, 1, getFilePtr(Controller));
}
