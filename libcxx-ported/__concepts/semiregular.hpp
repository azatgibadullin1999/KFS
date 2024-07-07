/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semiregular.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:19:59 by larlena           #+#    #+#             */
/*   Updated: 2024/06/01 00:20:59 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_SEMIREGULAR_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_SEMIREGULAR_HPP__

# include <__concepts/constructible.hpp>
# include <__concepts/copyable.hpp>

namespace std {

// [concept.object]

template <class _Tp>
concept semiregular = copyable<_Tp> && default_initializable<_Tp>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_SEMIREGULAR_HPP__
