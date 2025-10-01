/**
 * @file command_builtin.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP__

# include <algorithm>
# include <string_view>

# include "common/command.hpp"

namespace kfs::shell::interface {

class ICommandBuiltin : public kfs::interface::ICommand {
public:
	virtual ~ICommandBuiltin() { }
	virtual std::string_view	getName() const = 0;
	virtual std::string_view	getShortDescription() const = 0;
	virtual std::string_view	getFullDescription() const = 0;
	ICommandBuiltin	*setArgs(char **args) {
		mArgs = args;
		return this;
	}
protected:
	char **mArgs;
};

static bool operator == (kfs::shell::interface::ICommandBuiltin *lhs, std::string_view rhs) noexcept {
	return lhs->getName() == rhs;
}
static bool operator == (std::string_view lhs, kfs::shell::interface::ICommandBuiltin *rhs) noexcept {
	return rhs == lhs;
}
static bool operator != (kfs::shell::interface::ICommandBuiltin *lhs, std::string_view rhs) noexcept {
	return !(lhs == rhs);
}
static bool operator != (std::string_view lhs, kfs::shell::interface::ICommandBuiltin *rhs) noexcept {
	return !(rhs == lhs);
}

}

#endif // __KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP__
