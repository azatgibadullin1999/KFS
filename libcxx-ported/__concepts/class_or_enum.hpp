/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_or_enum.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:33:37 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_CLASS_OR_ENUM_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_CLASS_OR_ENUM_HPP__

# include <__type_traits/is_class.hpp>
# include <__type_traits/is_enum.hpp>
# include <__type_traits/is_union.hpp>
# include <__type_traits/remove_cvref.hpp>

namespace std {

template <class _Tp>
concept __class_or_enum = is_class_v<_Tp> || is_union_v<_Tp> || is_enum_v<_Tp>;

// Work around Clang bug https://llvm.org/PR52970
// TODO: remove this workaround once libc++ no longer has to support Clang 13 (it was fixed in Clang 14).
template <class _Tp>
concept __workaround_52970 = is_class_v<__remove_cvref_t<_Tp>> || is_union_v<__remove_cvref_t<_Tp>>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_CLASS_OR_ENUM_HPP__
