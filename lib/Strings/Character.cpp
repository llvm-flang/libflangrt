#include <cstdlib>
#include <cstring>
#include "Strings/Character.h"

template<typename T>
struct CharacterValue {
  T *Ptr;
  size_t Length;

  CharacterValue() {}
  CharacterValue(T *P, size_t Len)
    : Ptr(P), Length(Len) {}

  CharacterValue<T> sliceFrom(size_t Start) const {
    return CharacterValue<T>(Ptr + Start, Length - Start);
  }

  T operator[] (size_t I) const {
    return Ptr[I];
  }
};

static inline
CharacterValue<const char> generic(const char *Ptr, size_t Length) {
  return CharacterValue<const char>(Ptr, Length);
}

static inline
CharacterValue<char> generic(char *Ptr, size_t Length) {
  return CharacterValue<char>(Ptr, Length);
}


/// Returns true if a character is a whitespace
static bool isWhitespace(uint32_t C) {
  return C == ' '; //FIXME
}

template<typename T>
static void fill(const CharacterValue<T> String, const char C = ' ') {
  for(size_t I = 0; I < String.Length; ++I)
    String.Ptr[I] = T(C);
}

template<typename T>
static void assign(const CharacterValue<T> LHS,
                   const CharacterValue<T> RHS) {
  if(LHS.Length <= RHS.Length) {
    memmove(LHS.Ptr, RHS.Ptr, LHS.Length);
    return;
  }
  memmove(LHS.Ptr, RHS.Ptr, RHS.Length);
  fill(LHS.sliceFrom(RHS.Length));
}

template<typename T>
static void concat(CharacterValue<T> Dest,
                   const CharacterValue<T> LHS,
                   const CharacterValue<T> RHS) {
  if(Dest.Length <= LHS.Length) {
    memmove(Dest.Ptr, LHS.Ptr, Dest.Length);
    return;
  }
  memmove(Dest.Ptr, LHS.Ptr, LHS.Length);
  Dest = Dest.sliceFrom(LHS.Length);
  if(Dest.Length <= RHS.Length) {
    memmove(Dest.Ptr, RHS.Ptr, Dest.Length);
    return;
  }
  memmove(Dest.Ptr, RHS.Ptr, RHS.Length);
  fill(Dest.sliceFrom(RHS.Length));
}

template<typename T>
static int32_t compare(const CharacterValue<T> LHS,
                       const CharacterValue<T> RHS) {
  if(LHS.Length < RHS.Length) return -1;
  else if(LHS.Length > RHS.Length) return 1;
  return memcmp(LHS.Ptr, RHS.Ptr, LHS.Length);
}

template<typename T>
static int32_t lexcompare(const CharacterValue<T> LHS,
                          const CharacterValue<T> RHS) {
  return 0;//FIXME
}

template<typename T>
static size_t index(const CharacterValue<T> String,
                    const CharacterValue<T> SubString) {
  if(String.Length < SubString.Length)
    return 0;
  if(!SubString.Length) return 1;

  auto Range = String.Length - SubString.Length;
  for(size_t I = 0; I <= Range; ++I) {
    bool Match = true;
    for(size_t J = 0; J < SubString.Length; ++J) {
      if(String[I+J] != SubString[J]) {
        Match = false;
        break;
      }
    }
    if(Match) return I+1;
  }
  return 0;
}

template<typename T>
static size_t index_reverse(const CharacterValue<T> String,
                            const CharacterValue<T> SubString) {
  if(String.Length < SubString.Length)
    return 0;
  if(!SubString.Length) return String.Length + 1;

  for(size_t I = String.Length - SubString.Length + 1; I != 0; --I) {
    bool Match = true;
    for(size_t J = 0; J < SubString.Length; ++J) {
      if(String[I-1+J] != SubString[J]) {
        Match = false;
        break;
      }
    }
    if(Match) return I;
  }
  return 0;
}

template<typename T>
static size_t lentrim(const CharacterValue<T> String) {
  for(size_t I = String.Length; I > 0; I--) {
    if(isWhitespace(String.Ptr[I-1])) return I;
  }
  return String.Length;
}

// core

LIBFLANG_ABI void libflang_assignment_char1(char *LHS, size_t LHSLength,
                                            char *RHS, size_t RHSLength) {
  assign(generic(LHS, LHSLength), generic(RHS, RHSLength));
}

LIBFLANG_ABI void libflang_concat_char1(char *Dest, size_t DestLength,
                                        char *LHS, size_t LHSLength,
                                        char *RHS, size_t RHSLength) {
  concat(generic(Dest, DestLength),
         generic(LHS, LHSLength), generic(RHS, RHSLength));
}

LIBFLANG_ABI int32_t libflang_compare_char1(const char *LHS, size_t LHSLength,
                                            const char *RHS, size_t RHSLength) {
  return compare(generic(LHS, LHSLength), generic(RHS, RHSLength));
}

// intrinsics

LIBFLANG_ABI int32_t libflang_lexcompare_char1(const char *LHS, size_t LHSLength,
                                               const char *RHS, size_t RHSLength) {
  return lexcompare(generic(LHS, LHSLength), generic(RHS, RHSLength));
}

LIBFLANG_ABI size_t libflang_index_char1(const char *String, size_t Length,
                                         const char *SubString, size_t SubLength,
                                         int32_t Back) {
  return Back == 0? index(generic(String, Length), generic(SubString, SubLength)) :
                    index_reverse(generic(String, Length), generic(SubString, SubLength));
}

LIBFLANG_ABI size_t libflang_lentrim_char1(const char *String, size_t Length) {
  return lentrim(generic(String, Length));
}
