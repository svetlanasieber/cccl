/*
 *  Copyright 2018-2020 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*! \file deprecated.h
 *  \brief Defines the THRUST_DEPRECATED macro
 */

#pragma once

// Internal config header that is only included through thrust/detail/config/config.h

#if defined(_CCCL_IMPLICIT_SYSTEM_HEADER_GCC)
#  pragma GCC system_header
#elif defined(_CCCL_IMPLICIT_SYSTEM_HEADER_CLANG)
#  pragma clang system_header
#elif defined(_CCCL_IMPLICIT_SYSTEM_HEADER_MSVC)
#  pragma system_header
#endif // no system header

#include <thrust/detail/config/compiler.h>
#include <thrust/detail/config/cpp_dialect.h>

#if defined(CUB_IGNORE_DEPRECATED_API) && !defined(THRUST_IGNORE_DEPRECATED_API)
#  define THRUST_IGNORE_DEPRECATED_API
#endif

#ifdef THRUST_IGNORE_DEPRECATED_API
#  define THRUST_DEPRECATED
#elif _CCCL_STD_VER >= 2014
#  define THRUST_DEPRECATED [[deprecated]]
#elif THRUST_HOST_COMPILER == THRUST_HOST_COMPILER_MSVC
#  define THRUST_DEPRECATED __declspec(deprecated)
#elif THRUST_HOST_COMPILER == THRUST_HOST_COMPILER_CLANG
#  define THRUST_DEPRECATED __attribute__((deprecated))
#elif THRUST_HOST_COMPILER == THRUST_HOST_COMPILER_GCC
#  define THRUST_DEPRECATED __attribute__((deprecated))
#else
#  define THRUST_DEPRECATED
#endif
