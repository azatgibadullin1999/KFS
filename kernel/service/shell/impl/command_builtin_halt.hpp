/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_halt.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:03:01 by larlena           #+#    #+#             */
/*   Updated: 2025/09/23 15:52:14 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP__

# include <cstdio>

# include "common/factory.hpp"
# include "service/shell/interface/command_builtin.hpp"

namespace kfs::shell {

class CommandBuiltinHalt :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinHalt> {
public:
	std::string_view	getName() const {
		return "halt";
	}
	std::string_view	getShortDescription() const {
		return "halts system";
	}
	std::string_view	getFullDescription() const {
		return "da";
	}
	void		execute() {
		asm volatile (
		"hlt"
		);
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP__
