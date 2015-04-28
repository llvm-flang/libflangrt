Libflangrt
================================

Libflangrt is a new implementation of the Fortran runtime library.
All of the code in libflangrt is dual licensed under the MIT license
and the UIUC License (a BSD-like license).

Libflangrt was created as a runtime library for flang (the Fortran frontend for
LLVM, https://github.com/hyp/flang) as part of a GSoC 2013.
It is used by flang right now, but it can be used by any other Fortran compiler.

Building Libflangrt
================================

> git clone git://github.com/llvm-flang/libflangrt.git
> cd libflangrt
> mkdir build
> cd build & cmake ../ -DCMAKE_INSTALL_PREFIX=/usr
> cd build & make
> cd build & make install


TODO
================================
- IO, Formatted IO.
- Fortran 90/95 support.
