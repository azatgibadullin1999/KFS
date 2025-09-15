/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_halt.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:03:01 by larlena           #+#    #+#             */
/*   Updated: 2025/09/14 00:18:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP__

# include <cstdio>

# include "factory.hpp"
# include "interface/command_builtin.hpp"

namespace kfs::shell {

class CommandBuiltinHalt :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinHalt> {
public:
	std::string_view	getName() const {
		return "halt";
	}
	std::string_view	getShortDescription() const {
		return "da\n";
	}
	std::string_view	getFullDescription() const {
		return "da\n";
	}
	void		execute() {
		std::printf("CommandBuiltinHalt\n");
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP__
