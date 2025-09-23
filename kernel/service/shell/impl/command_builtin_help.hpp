/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_help.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:04:34 by larlena           #+#    #+#             */
/*   Updated: 2025/09/23 15:52:37 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__

# include <cstdio>

# include "service/shell/interface/command_builtin.hpp"
# include "common/factory.hpp"

namespace kfs::shell {

template <typename ... Args>
class CommandBuiltinHelp :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinHelp<Args ...>> {
public:
	std::string_view	getName() const {
		return "help";
	}
	std::string_view	getShortDescription() const {
		return "shows commands and short descriptions";
	}
	std::string_view	getFullDescription() const {
		return "da";
	}
	void		execute() {
		std::printf("====================\n");
		(std::printf("%s - %s\n", Args::create()->getName().data(), Args::create()->getShortDescription().data()), ...);
		std::printf("====================\n");
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__
