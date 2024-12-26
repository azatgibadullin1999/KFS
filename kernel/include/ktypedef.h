/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ktypedef.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:16:38 by larlena           #+#    #+#             */
/*   Updated: 2024/12/24 20:34:52 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_INCLUDE_H__
# define __KFS_KERNEL_INCLUDE_H__

#include <cstdint>

using phys_addr_t = std::uint32_t;
using virt_addr_t = std::uint32_t;
using addr_t = std::uint32_t;

#endif // __KFS_KERNEL_INCLUDE_H__
