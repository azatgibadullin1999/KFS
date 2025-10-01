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

	std::string_view	getName() const {
		return "shutdown";
	}
	std::string_view	getShortDescription() const {
		return "power off the system";
	}
	std::string_view	getFullDescription() const {
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
