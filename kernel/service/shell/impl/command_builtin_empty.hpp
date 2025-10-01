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

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP__

# include <cstdio>

# include "service/shell/interface/command_builtin.hpp"
# include "common/factory.hpp"

namespace kfs::shell {

class CommandBuiltinEmpty :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinEmpty> {
public:
	std::string_view	getName() const {
		return "empty";
	}
	std::string_view	getShortDescription() const {
		return "empty";
	}
	std::string_view	getFullDescription() const {
		return "empty";
	}
	void		execute() {
		if (!*mArgs) {
			return ;
		}
		std::printf("There is no command \"%s\", type \"help\" to see the list of commands\n", *mArgs);
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP__
