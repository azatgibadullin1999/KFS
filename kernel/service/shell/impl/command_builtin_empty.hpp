/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_empty.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:41:15 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 17:45:15 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP__

# include "service/shell/interface/command_builtin.hpp"
# include "common/factory.hpp"

namespace kfs::shell {

class CommandBuiltinEmpty :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinEmpty> {
public:
	ktl::string_view	getName() const {
		return "empty";
	}
	ktl::string_view	getShortDescription() const {
		return "empty\n";
	}
	ktl::string_view	getFullDescription() const {
		return "empty\n";
	}
	void		execute() {
		if (!*mArgs) {
			return ;
		}
		printf("There is no command \"%s\", type \"help\" to see the list of commands\n", *mArgs);
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP__
