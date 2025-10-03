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

#ifndef KFS_KERNEL_SERVICE_PANIC_PANIC_HPP
# define KFS_KERNEL_SERVICE_PANIC_PANIC_HPP

namespace kfs {

namespace detail {
[[noreturn]] void panic();
}

struct PanicHandler {
	PanicHandler();
};

} // namespace kfs

#endif // KFS_KERNEL_SERVICE_PANIC_PANIC_HPP
