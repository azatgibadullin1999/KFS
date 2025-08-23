/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paging.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:38:43 by larlena           #+#    #+#             */
/*   Updated: 2025/05/05 17:53:06 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_ARCH_PAIGING_HPP__
# define __KFS_KERNEL_ARCH_PAIGING_HPP__

# include "arch/x86/paging.hpp"

namespace kfs::page {
	using namespace kfs::x86::page;
}

#endif // __KFS_KERNEL_ARCH_PAIGING_HPP__
