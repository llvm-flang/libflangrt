project(Libflang)
cmake_minimum_required(VERSION 2.8)

# Enable C++ 11
if(NOT MSVC)
  add_definitions(-std=c++11 -fno-exceptions)
endif()

set(libflang_sources)

macro(add_libflang_library name)
  set(srcs ${ARGN})

  if (MODULE)
    set(libkind MODULE)
  elseif (SHARED_LIBRARY)
    set(libkind SHARED)
  else()
    set(libkind)
  endif()
  
  add_library( ${name} ${libkind} ${srcs} )
endmacro(add_libflang_library)

include_directories(include)

add_subdirectory(include)
add_subdirectory(lib)

if (MODULE)
  set(libkind MODULE)
elseif (SHARED_LIBRARY)
  set(libkind SHARED)
else()
  set(libkind)
endif()

add_library(libflang ${libkind} lib/Libflang.cpp
  lib/Core/Core.cpp
  lib/Numerical/Complex.cpp
  lib/Numerical/Integer.cpp
  lib/Strings/Character.cpp
  lib/IO/Write.cpp
  lib/System/System.cpp
)

install(TARGETS libflang
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

# Tests
macro(add_libflang_test name)
  add_executable( ${name} ${ARGN} )
  target_link_libraries( ${name} libflang )
endmacro(add_libflang_test)

add_subdirectory(test)

set(BUG_REPORT_URL "http://llvm.org/bugs/" CACHE STRING
  "Default URL where bug reports are to be submitted.")

