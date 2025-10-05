/**
 * @file kernel_address_space.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <multiboot.h>

#include "../address_space.hpp"

namespace kfs {

struct KernelAddressSpace : public AddressSpace {
	KernelAddressSpace();
};

}
