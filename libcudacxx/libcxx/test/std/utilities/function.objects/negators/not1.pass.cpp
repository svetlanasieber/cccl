//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <functional>

// not1

#define _LIBCUDACXX_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS
#define _LIBCUDACXX_ENABLE_CXX20_REMOVED_NEGATORS
#define _LIBCUDACXX_DISABLE_DEPRECATION_WARNINGS

#include <functional>
#include <cassert>

#include "test_macros.h"

int main(int, char**)
{
    typedef std::logical_not<int> F;
    assert(std::not1(F())(36));
    assert(!std::not1(F())(0));

  return 0;
}
