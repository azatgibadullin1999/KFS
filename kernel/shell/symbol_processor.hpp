/**
 * @file symbol_processor.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_SERVICE_SHELL_SYBOL_PROCESSOR_HPP
# define KFS_KERNEL_SERVICE_SHELL_SYBOL_PROCESSOR_HPP

# include "command_default.hpp"
# include "command_press_backspace.hpp"

namespace kfs::shell {

template <typename Container>
class SymbolProcessorForShell : public kfs::ISymbolProcessor {
public:
	SymbolProcessorForShell(Container &shared_container, typename Container::iterator &shared_it, kfs::IConsole *console) :
		_backspace(shared_container, shared_it, console),
		_default(shared_container, shared_it, console) { }

	void	process(const char &symbol) override {
		if (symbol == '\b') {
			_backspace.execute();
		} else {
			_default = symbol;
			_default.execute();
		}
	}
private:
	CommandPressBackspaceShell<Container>	_backspace;
	CommandDefaultShell<Container>		_default;
};

}

#endif // KFS_KERNEL_SERVICE_SHELL_SYBOL_PROCESSOR_HPP
