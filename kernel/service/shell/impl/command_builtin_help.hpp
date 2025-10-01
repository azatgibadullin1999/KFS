/**
 * @file command_builtin_help.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__

# include <cstdio>

# include "service/shell/interface/command_builtin.hpp"
# include "common/factory.hpp"

namespace kfs::shell {

template <typename ... Args>
class CommandBuiltinHelp :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinHelp<Args ...>> {
public:
	std::string_view	getName() const {
		return "help";
	}
	std::string_view	getShortDescription() const {
		return "shows commands and short descriptions";
	}
	std::string_view	getFullDescription() const {
		return "da";
	}
	void		execute() {
		std::printf("====================\n");
		(std::printf("%s - %s\n", Args::create()->getName().data(), Args::create()->getShortDescription().data()), ...);
		std::printf("====================\n");
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__
