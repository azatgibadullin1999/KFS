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

#ifndef KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESS_NEWLINE_HPP
# define KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESS_NEWLINE_HPP

# include <cstddef>

# include "pattern/command.hpp"
# include <kfs/console.hpp>

namespace kfs::shell {

template <typename Container>
class CommandPressNewLineShell final : public pattern::ICommand {
public:
	CommandPressNewLineShell(typename Container::iterator &shared_it, kfs::IConsole *console) :
	_shared_it(shared_it),
	_console(console) { }

	void	execute() override {
		_console->write('\n');
	}
private:
	typename Container::iterator	&_shared_it;
	kfs::IConsole	*_console;
};

}

#endif // KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESS_NEWLINE_HPP
