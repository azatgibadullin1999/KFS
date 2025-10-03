/**
 * @file command_builtin_halt.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP
# define KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP

# include "common/factory.hpp"
# include "service/shell/interface/command_builtin.hpp"

namespace kfs::shell {

class CommandBuiltinHalt :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinHalt> {
public:
	std::string_view	get_name() const {
		return "halt";
	}
	std::string_view	get_short_description() const {
		return "halts system";
	}
	std::string_view	get_full_description() const {
		return "da";
	}
	void		execute() {
		asm volatile ("hlt");
	}
};

}

#endif // KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP
