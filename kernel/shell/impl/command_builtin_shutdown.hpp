/**
 * @file command_builtin_shutdown.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_SHUTDOWN_HPP
# define KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_SHUTDOWN_HPP

# include "pattern/factory.hpp"
# include "../driver/utils/port.hpp"
# include "../interface/command_builtin.hpp"

namespace kfs::shell {

class CommandBuiltinShutdown :
	public kfs::shell::ICommandBuiltin,
	public pattern::StaticInstanceFactory<CommandBuiltinShutdown> {
public:
	CommandBuiltinShutdown() :
	_port(0x604) { }

	std::string_view	get_name() const {
		return "shutdown";
	}
	std::string_view	get_short_description() const {
		return "power off the system";
	}
	std::string_view	get_full_description() const {
		return "da\n";
	}
	void		execute() {
		_port.write(0x2000);
	}
private:
	kfs::driver::utils::PortWord	_port;
};

}

#endif // KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_SHUTDOWN_HPP
