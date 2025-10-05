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

#ifndef KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP
# define KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP

# include <cstdio>

# include "pattern/factory.hpp"
# include "../interface/command_builtin.hpp"

namespace kfs::shell {

template <typename ... Args>
class CommandBuiltinHelp :
	public kfs::shell::ICommandBuiltin,
	public pattern::StaticInstanceFactory<CommandBuiltinHelp<Args ...>> {
public:
	std::string_view	get_name() const {
		return "help";
	}
	std::string_view	get_short_description() const {
		return "shows commands and short descriptions";
	}
	std::string_view	get_full_description() const {
		return "da";
	}
	void		execute() {
		std::printf("====================\n");
		(std::printf("%s - %s\n", Args::create()->get_name().data(), Args::create()->get_short_description().data()), ...);
		std::printf("====================\n");
	}
};

}

#endif // KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP
