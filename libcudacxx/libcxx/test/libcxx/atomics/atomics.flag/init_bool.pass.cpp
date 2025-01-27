//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads

// <atomic>

// struct atomic_flag

// TESTING EXTENSION atomic_flag(bool)

#include <atomic>
#include <cassert>

#include "test_macros.h"

// Ensure that static initialization happens; this is PR#37226
extern std::atomic_flag global;
struct X { X() { global.test_and_set(); }};
X x;
std::atomic_flag global = ATOMIC_FLAG_INIT;

int main(int, char**)
{
    assert(global.test_and_set() == 1);
    {
        std::atomic_flag f(false);
        assert(f.test_and_set() == 0);
    }
    {
        std::atomic_flag f(true);
        assert(f.test_and_set() == 1);
    }

  return 0;
}
