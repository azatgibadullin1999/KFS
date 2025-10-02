/**
 * @file panic.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_PANIC_PANIC_HPP__
# define __KFS_KERNEL_SERVICE_PANIC_PANIC_HPP__

namespace kfs {

namespace detail {
[[noreturn]] void panic();
}

struct PanicHandler {
	PanicHandler();
};

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_PANIC_PANIC_HPP__
