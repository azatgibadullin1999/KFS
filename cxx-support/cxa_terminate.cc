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

terminate_handler __terminate;

}

terminate_handler set_terminate(terminate_handler func) noexcept {
	__terminate = func;
	return __terminate;
}

terminate_handler get_terminate() noexcept {
	return __terminate;
}

void terminate() noexcept {
	__terminate();
}

}  // std
