/**
 * @file factory_command_builtin_default.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_SERVICE_SHELL_IMPL_FACTORY_COMMAND_BUILTIN_DEFAULT_HPP
# define KFS_KERNEL_SERVICE_SHELL_IMPL_FACTORY_COMMAND_BUILTIN_DEFAULT_HPP

# include "service/shell/interface/factory_command_builtin.hpp"

# include "command_builtin_halt.hpp"
# include "command_builtin_help.hpp"
# include "command_builtin_reboot.hpp"
# include "command_builtin_shutdown.hpp"
# include "command_builtin_stack.hpp"
# include "command_builtin_time.hpp"
# include "command_builtin_empty.hpp"
# include "command_builtin_panic.hpp"

# define LIST_OF_COMMANDS \
kfs::shell::CommandBuiltinReboot, \
kfs::shell::CommandBuiltinShutdown, \
kfs::shell::CommandBuiltinTime, \
kfs::shell::CommandBuiltinStack, \
kfs::shell::CommandBuiltinPanic, \
kfs::shell::CommandBuiltinHalt

namespace kfs::shell {

class FactoryCommandBuiltinDefault : public kfs::shell::FactoryCommandBuiltin<
	LIST_OF_COMMANDS,
	kfs::shell::CommandBuiltinHelp<LIST_OF_COMMANDS>,
	kfs::shell::CommandBuiltinEmpty
> { };

}

#endif // KFS_KERNEL_SERVICE_SHELL_IMPL_FACTORY_COMMAND_BUILTIN_DEFAULT_HPP
