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

#ifndef KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP
# define KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP

# include <exception>
# include <string_view>

# include "common/factory.hpp"
# include "service/shell/interface/command_builtin.hpp"

namespace kfs::shell {

class CommandBuiltinPanic :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinPanic> {
public:
	std::string_view	get_name() const {
		return "panic";
	}
	std::string_view	get_short_description() const {
		return "calls panic function that stops system";
	}
	std::string_view	get_full_description() const {
		return "da";
	}
	void		execute() {
		std::terminate();
	}
};

}

#endif // KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP
