/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_empty.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:41:15 by larlena           #+#    #+#             */
/*   Updated: 2025/09/22 14:08:42 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_EMPTY_HPP__

# include <cstdio>

# include "interface/command_builtin.hpp"
# include "factory.hpp"

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
