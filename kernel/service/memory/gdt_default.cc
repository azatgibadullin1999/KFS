/**
 * @file gdt_default.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "gdt_default.hpp"

namespace kfs::x86 {

GDTDefault::GDTDefault() : GlobalDescriptorTable(
	Register(GDT_DEFAULT_SIZE, GDT_DEFAULT_BASE),
	Desk(),
	Desk(0x0, 0xFFFF, 0x9B, 0x0D), // kernel code
	Desk(0x0, 0xFFFF, 0x93, 0x0D), // kernel data
	Desk(0x0, 0x0,    0x97, 0x0D), // kernel stack
	Desk(0x0, 0xFFFF, 0xFF, 0x0D), // user code
	Desk(0x0, 0xFFFF, 0xF3, 0x0D), // user data
	Desk(0x0, 0x0,    0xF7, 0x0D)  // user stack
	) { }

}
