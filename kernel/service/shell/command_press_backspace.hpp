/**
 * @file command_press_backspace.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESSBACK_SPACE_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESSBACK_SPACE_HPP__

# include <cstddef>

# include "common/command.hpp"
# include "service/console.hpp"


namespace kfs::shell {

template <typename Container>
class CommandPressBackspaceShell final : public kfs::interface::ICommand {
public:
	CommandPressBackspaceShell(Container &shared_container, typename Container::iterator &shared_it, kfs::interface::IConsole *console) :
	_shared_container(shared_container),
	_shared_it(shared_it),
	_console(console) { }

	void	execute() override {
		if (_shared_container.begin() == _shared_it) {
			return ;
		}
		_console->write(*_shared_it);
		*_shared_it = ' ';
		--_shared_it;
	}
private:
	Container	&_shared_container;
	typename Container::iterator	&_shared_it;
	kfs::interface::IConsole	*_console;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESSBACK_SPACE_HPP__
