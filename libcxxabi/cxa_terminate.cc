//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//
// This file implements the functionality associated with the terminate_handler,
// unexpected_handler, and new_handler.
//===----------------------------------------------------------------------===//

#include <exception>

namespace std {

namespace {
terminate_handler __terminate_fn;
}

_LIBCPP_EXPORTED_FROM_ABI terminate_handler set_terminate(terminate_handler func) _NOEXCEPT {
	__terminate_fn = func;
	return __terminate_fn;
}

_LIBCPP_EXPORTED_FROM_ABI terminate_handler get_terminate() _NOEXCEPT {
	return __terminate_fn;
}

[[noreturn]]
_LIBCPP_NORETURN _LIBCPP_EXPORTED_FROM_ABI void terminate() _NOEXCEPT {
	__terminate_fn();
}

}  // std

_LIBCPP_BEGIN_NAMESPACE_STD

_LIBCPP_NORETURN _LIBCPP_AVAILABILITY_VERBOSE_ABORT _LIBCPP_OVERRIDABLE_FUNC_VIS
_LIBCPP_ATTRIBUTE_FORMAT(__printf__, 1, 2) void __libcpp_verbose_abort(const char* __format, ...) {
	__terminate_fn();
}

_LIBCPP_END_NAMESPACE_STD
