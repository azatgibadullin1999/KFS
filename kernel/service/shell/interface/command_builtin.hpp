/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 06:44:56 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 11:35:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_INTERFACE_COMMAND_BUILTIN_HPP__

# include "common/command.hpp"
# include "utils/stl/string_view.hpp"
# include "utils/stl/array.hpp"

namespace kfs::shell::interface {

class ICommandBuiltin : public kfs::interface::ICommand {
public:
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
