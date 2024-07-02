/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_shutdown.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:00:54 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 11:22:08 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_SHUTDOWN_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_SHUTDOWN_HPP__

# include "service/shell/interface/command_builtin.hpp"
# include "driver/utils/port.hpp"
# include "common/factory.hpp"

namespace kfs::shell {

class CommandBuiltinShutdown :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinShutdown> {
public:
	CommandBuiltinShutdown() :
	mPort(0x604) { }

	ktl::string_view	getName() const {
		return "shutdown";
	}
	ktl::string_view	getShortDescription() const {
		return "shutdown - Command to power off the system.\n";
	}
	ktl::string_view	getFullDescription() const {
		return "da\n";
	}
	void		execute() {
		mPort.write(0x2000);
	}
private:
	kfs::driver::utils::PortWord	mPort;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_SHUTDOWN_HPP__
