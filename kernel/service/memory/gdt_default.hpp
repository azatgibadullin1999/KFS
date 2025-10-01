/**
 * @file gdt_default.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_GDT_DEFAULT_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_GDT_DEFAULT_HPP__

#define GDT_DEFAULT_BASE	0x00000800
#define GDT_DEFAULT_SIZE	7

# include "gdt.hpp"

namespace kfs::x86 {

class GDTDefault : public kfs::x86::GlobalDescriptorTable<GDT_DEFAULT_SIZE> {
public:
	GDTDefault();
};

}

#endif // __KFS_KERNEL_SERVICE_MEMORY_GDT_DEFAULT_HPP__