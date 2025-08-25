/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 06:44:56 by larlena           #+#    #+#             */
/*   Updated: 2025/09/13 16:06:14 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP__

# include "command.hpp"
# include <string_view>
# include <array>

namespace kfs::shell::interface {

class ICommandBuiltin : public kfs::interface::ICommand {
public:
	virtual ~ICommandBuiltin() { }
	virtual ktl::string_view	getName() const = 0;
	virtual ktl::string_view	getShortDescription() const = 0;
	virtual ktl::string_view	getFullDescription() const = 0;
	ICommandBuiltin	*setArgs(char **args) {
		mArgs = args;
		return this;
	}
protected:
	char **mArgs;
};

bool	operator == (ICommandBuiltin *lhs, ktl::string_view rhs) noexcept {
	return lhs->getName() == rhs;
}

bool	operator == (ktl::string_view lhs, ICommandBuiltin *rhs) noexcept {
	return rhs->getName() == lhs;
}

bool	operator != (ICommandBuiltin *lhs, ktl::string_view rhs) noexcept {
	return !(lhs->getName() == rhs);
}

bool	operator != (ktl::string_view lhs, ICommandBuiltin *rhs) noexcept {
	return !(rhs->getName() == lhs);
}

}

#endif // __KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP__
