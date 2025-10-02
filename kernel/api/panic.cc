/**
 * @file panic.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 24-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "service/panic/panic.hpp"

extern "C" void kfs_panic() {
	kfs::detail::panic();
}