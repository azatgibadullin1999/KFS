/**
 * @file command_press_newline.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESS_NEWLINE_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESS_NEWLINE_HPP__

# include <cstddef>

# include "common/command.hpp"
# include "service/console.hpp"

namespace kfs::shell {

template <typename Container>
class CommandPressNewLineShell final : public kfs::interface::ICommand {
public:
	CommandPressNewLineShell(typename Container::iterator &shared_it, kfs::interface::IConsole *console) :
	_shared_it(shared_it),
	_console(console) { }

	void	execute() override {
		_console->write('\n');
	}
private:
	typename Container::iterator	&_shared_it;
	kfs::interface::IConsole	*_console;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESS_NEWLINE_HPP__
