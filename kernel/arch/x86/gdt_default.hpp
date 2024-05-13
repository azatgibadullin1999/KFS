/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt_default.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:07:39 by larlena           #+#    #+#             */
/*   Updated: 2024/04/16 13:10:31 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_ARCH_X86_GDT_DEFAULT_HPP__
# define __KFS_KERNEL_ARCH_X86_GDT_DEFAULT_HPP__

#define GDT_DEFAULT_BASE	0x00000800
#define GDT_DEFAULT_SIZE	7

# include "gdt.hpp"

namespace kfs::x86 {

class GDTDefault : public kfs::x86::GlobalDescriptorTable<GDT_DEFAULT_SIZE> {
public:
	GDTDefault();
};

}

#endif // __KFS_KERNEL_ARCH_X86_GDT_DEFAULT_HPP__