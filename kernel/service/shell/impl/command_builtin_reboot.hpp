/**
 * @file command_builtin_reboot.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_REBOOT_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_REBOOT_HPP__

# include "common/factory.hpp"
# include "service/shell/interface/command_builtin.hpp"

namespace kfs::shell {

class CommandBuiltinReboot :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinReboot> {
public:
	std::string_view	get_name() const {
		return "reboot";
	}
	std::string_view	get_short_description() const {
		return "restarts the system";
	}
	std::string_view	get_full_description() const {
		return "da";
	}
	void		execute() {
		asm("jmp 0xFFFF\n\t");
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_REBOOT_HPP__
