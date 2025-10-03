/**
 * @file command_builtin_empty.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP
# define KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP

# include <cstdio>

# include "common/factory.hpp"
# include "service/shell/interface/command_builtin.hpp"

namespace kfs::shell {

class CommandBuiltinEmpty :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinEmpty> {
public:
	std::string_view	get_name() const {
		return "empty";
	}
	std::string_view	get_short_description() const {
		return "empty";
	}
	std::string_view	get_full_description() const {
		return "empty";
	}
	void		execute() {
		if (!*_args) {
			return ;
		}
		std::printf("There is no command \"%s\", type \"help\" to see the list of commands\n", *_args);
	}
};

}

#endif // KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP
