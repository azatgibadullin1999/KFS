/**
 * @file command_builtin_panic.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP__

#include <exception>
# include <string_view>

# include "service/shell/interface/command_builtin.hpp"
# include "service/panic/panic.hpp"
# include "common/factory.hpp"

namespace kfs::shell {

class CommandBuiltinPanic :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinPanic> {
public:
	std::string_view	getName() const {
		return "panic";
	}
	std::string_view	getShortDescription() const {
		return "calls panic function that stops system";
	}
	std::string_view	getFullDescription() const {
		return "da";
	}
	void		execute() {
		std::terminate();
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP__
