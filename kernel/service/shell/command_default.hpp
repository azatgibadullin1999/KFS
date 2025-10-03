/**
 * @file command_default.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_SERVICE_SHELL_COMMAND_DEFAULT_HPP
# define KFS_KERNEL_SERVICE_SHELL_COMMAND_DEFAULT_HPP

# include <cctype>

# include "common/command.hpp"
# include "service/console.hpp"

namespace kfs::shell {

template <typename Container>
class CommandDefaultShell final : public kfs::interface::ICommand {
public:
	CommandDefaultShell(Container &shared_container, typename Container::iterator &shared_it, kfs::interface::IConsole *console)
	: _character{ }
	, _shared_container{ shared_container }
	, _console{ console }
	, _shared_it{ shared_it } { }

	CommandDefaultShell	&operator = (const char &c) {
		_character = c;
		return *this;
	}

	void	execute() override {
		if (!std::isprint(_character) || _shared_it == (_shared_container.end() - 1)) {
			return;
		}
		*_shared_it = _character;
		_console->write(_character);
		++_shared_it;
	}
private:
	char	_character;
	Container	&_shared_container;
	kfs::interface::IConsole	*_console;
	typename Container::iterator	&_shared_it;

};

}

#endif // KFS_KERNEL_SERVICE_SHELL_COMMAND_DEFAULT_HPP