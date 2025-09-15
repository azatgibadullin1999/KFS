/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_help.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:04:34 by larlena           #+#    #+#             */
/*   Updated: 2025/09/14 00:18:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__

# include <cstdio>

# include "interface/command_builtin.hpp"
# include "factory.hpp"

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
		return "help - Command shows commands and short descriptions.\n";
	}
	std::string_view	getFullDescription() const {
		return "da\n";
	}
	void		execute() {
		std::printf("====================\n");
		(std::printf("%s", Args::create()->getShortDescription()), ...);
		std::printf("====================\n");
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__
