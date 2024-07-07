//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef __KFS_LIBCPP_PORTED___TYPE_TRAITS_DISJUNCTION_H__
# define __KFS_LIBCPP_PORTED___TYPE_TRAITS_DISJUNCTION_H__

#include <__type_traits/integral_constant.hpp>

namespace std {

template <bool>
struct _OrImpl;

template <>
struct _OrImpl<true> {
  template <class _Res, class _First, class... _Rest>
  using _Result =
      typename _OrImpl<!bool(_First::value) && sizeof...(_Rest) != 0>::template _Result<_First, _Rest...>;
};

template <>
struct _OrImpl<false> {
  template <class _Res, class...>
  using _Result = _Res;
};

// _Or always performs lazy evaluation of its arguments.
//
// However, `_Or<_Pred...>` itself will evaluate its result immediately (without having to
// be instantiated) since it is an alias, unlike `disjunction<_Pred...>`, which is a struct.
// If you want to defer the evaluation of `_Or<_Pred...>` itself, use `_Lazy<_Or, _Pred...>`
// or `disjunction<_Pred...>` directly.
template <class... _Args>
using _Or = typename _OrImpl<sizeof...(_Args) != 0>::template _Result<false_type, _Args...>;

template <class... _Args>
struct disjunction : _Or<_Args...> {};

template <class... _Args>
inline constexpr bool disjunction_v = _Or<_Args...>::value;

}

#endif // __KFS_LIBCPP_PORTED___TYPE_TRAITS_DISJUNCTION_H__
