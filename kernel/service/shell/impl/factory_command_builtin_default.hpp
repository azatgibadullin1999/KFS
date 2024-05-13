/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_command_builtin_default.hpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:14:16 by larlena           #+#    #+#             */
/*   Updated: 2024/05/01 22:25:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_FACTORY_COMMAND_BUILTIN_DEFAULT_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_FACTORY_COMMAND_BUILTIN_DEFAULT_HPP__

# include "service/shell/interface/factory_command_builtin.hpp"
# include "command_builtin_halt.hpp"
# include "command_builtin_help.hpp"
# include "command_builtin_reboot.hpp"
# include "command_builtin_shutdown.hpp"
# include "command_builtin_stack.hpp"
# include "command_builtin_time.hpp"
# include "command_builtin_empty.hpp"

# define LIST_OF_COMMANDS \
kfs::shell::CommandBuiltinReboot, \
kfs::shell::CommandBuiltinShutdown, \
kfs::shell::CommandBuiltinTime, \
kfs::shell::CommandBuiltinStack 

namespace kfs::shell {

class FactoryCommandBuiltinDefault : public kfs::shell::FactoryCommandBuiltin<
	LIST_OF_COMMANDS,
	kfs::shell::CommandBuiltinHelp<LIST_OF_COMMANDS>,
	kfs::shell::CommandBuiltinEmpty
> { };

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_FACTORY_COMMAND_BUILTIN_DEFAULT_HPP__
