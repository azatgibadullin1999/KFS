/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_space.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:19:30 by larlena           #+#    #+#             */
/*   Updated: 2025/03/28 15:07:46 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__

# include "arch/paging.hpp"

namespace kfs {

struct AddressSpace {
	kfs::x86::page::Directory	directory;
};

}

#endif // __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__
