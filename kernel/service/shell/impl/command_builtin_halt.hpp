/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_halt.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:03:01 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 11:22:08 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP__

# include "service/shell/interface/command_builtin.hpp"
# include "common/factory.hpp"

namespace kfs::shell {

class CommandBuiltinHalt :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinHalt> {
public:
	ktl::string_view	getName() const {
		return "halt";
	}
	ktl::string_view	getShortDescription() const {
		return "da\n";
	}
	ktl::string_view	getFullDescription() const {
		return "da\n";
	}
	void		execute() {
		printf("CommandBuiltinHalt\n");
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HALT_HPP__
