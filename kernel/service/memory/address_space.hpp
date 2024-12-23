/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_space.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:19:30 by larlena           #+#    #+#             */
/*   Updated: 2024/10/09 12:41:22 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__

# include "arch/paging.hpp"

namespace kfs {

class AddressSpace {
public:
	AddressSpace(kfs::x86::PageDirectoryPointer directory)
	: mDirectory(directory) { }
private:
	kfs::x86::PageDirectoryPointer	mDirectory;
};

}

#endif // __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__
