/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_help.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:04:34 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 11:22:08 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__

# include "service/shell/interface/command_builtin.hpp"
# include "common/factory.hpp"

namespace kfs::shell {

template <typename ... Args>
class CommandBuiltinHelp :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinHelp<Args ...>> {
public:
	ktl::string_view	getName() const {
		return "help";
	}
	ktl::string_view	getShortDescription() const {
		return "help - Command shows commands and short descriptions.\n";
	}
	ktl::string_view	getFullDescription() const {
		return "da\n";
	}
	void		execute() {
		printf("====================\n");
		(printf("%s", Args::create()->getShortDescription()), ...);
		printf("====================\n");
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_HELP_HPP__
