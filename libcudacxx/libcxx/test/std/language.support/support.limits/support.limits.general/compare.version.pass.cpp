//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// WARNING: This test was generated by generate_feature_test_macro_components.py
// and should not be edited manually.

// <compare>

// Test the feature test macros defined by <compare>

/*  Constant                          Value
    __cpp_lib_three_way_comparison    201711L [C++2a]
*/

#include <compare>
#include "test_macros.h"

#if TEST_STD_VER < 2014

# ifdef __cpp_lib_three_way_comparison
#   error "__cpp_lib_three_way_comparison should not be defined before c++2a"
# endif

#elif TEST_STD_VER == 2014

# ifdef __cpp_lib_three_way_comparison
#   error "__cpp_lib_three_way_comparison should not be defined before c++2a"
# endif

#elif TEST_STD_VER == 2017

# ifdef __cpp_lib_three_way_comparison
#   error "__cpp_lib_three_way_comparison should not be defined before c++2a"
# endif

#elif TEST_STD_VER > 2017

# if !defined(_LIBCUDACXX_VERSION)
#   ifndef __cpp_lib_three_way_comparison
#     error "__cpp_lib_three_way_comparison should be defined in c++2a"
#   endif
#   if __cpp_lib_three_way_comparison != 201711L
#     error "__cpp_lib_three_way_comparison should have the value 201711L in c++2a"
#   endif
# else // _LIBCUDACXX_VERSION
#   ifdef __cpp_lib_three_way_comparison
#     error "__cpp_lib_three_way_comparison should not be defined because it is unimplemented in libc++!"
#   endif
# endif

#endif // TEST_STD_VER > 2017

int main(int, char**) { return 0; }
