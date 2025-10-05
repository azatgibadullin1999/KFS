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

#ifndef KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP
# define KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP

# include <string_view>

# include "pattern/command.hpp"

namespace kfs::shell {

class ICommandBuiltin : public pattern::ICommand {
public:
	virtual ~ICommandBuiltin() { }
	virtual std::string_view	get_name() const = 0;
	virtual std::string_view	get_short_description() const = 0;
	virtual std::string_view	get_full_description() const = 0;
	ICommandBuiltin	*set_args(char **args) {
		_args = args;
		return this;
	}
protected:
	char **_args;
};

[[maybe_unused]]
static bool operator == (kfs::shell::ICommandBuiltin *lhs, std::string_view rhs) noexcept {
	return lhs->get_name() == rhs;
}
[[maybe_unused]]
static bool operator == (std::string_view lhs, kfs::shell::ICommandBuiltin *rhs) noexcept {
	return rhs == lhs;
}
[[maybe_unused]]
static bool operator != (kfs::shell::ICommandBuiltin *lhs, std::string_view rhs) noexcept {
	return !(lhs == rhs);
}
[[maybe_unused]]
static bool operator != (std::string_view lhs, kfs::shell::ICommandBuiltin *rhs) noexcept {
	return !(rhs == lhs);
}

}

#endif // KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP
