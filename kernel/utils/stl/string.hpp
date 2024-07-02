/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:21:56 by larlena           #+#    #+#             */
/*   Updated: 2024/05/04 17:55:21 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_STRING_HPP__
# define __KFS_KERNEL_UTILS_STL_STRING_HPP__

#include "stddef.h"
#include "array.hpp"

namespace ktl {

template <size_t capacity>
class stack_string : public ktl::array<char, capacity> {

};

}

#endif // __KFS_KERNEL_UTILS_STL_STRING_HPP__
