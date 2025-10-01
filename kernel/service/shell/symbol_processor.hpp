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

#ifndef __KFS_KERNEL_SERVICE_SHELL_SPECIAL_SYBOL_PROCESSOR_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_SPECIAL_SYBOL_PROCESSOR_HPP__

# include "command_default.hpp"
# include "command_press_backspace.hpp"
# include "symbol_processor.hpp"

namespace kfs::shell {

template <typename Container>
class SymbolProcessorForShell : public kfs::driver::interface::ISymbolProcessor {
public:
	SymbolProcessorForShell(Container &sharedContainer, typename Container::iterator &sharedIt, kfs::interface::IConsole *console) :
		mBackspace(sharedContainer, sharedIt, console),
		mDefault(sharedContainer, sharedIt, console) { }

	void	process(const char &symbol) override {
		if (symbol == '\b') {
			mBackspace.execute();
		} else {
			mDefault = symbol;
			mDefault.execute();
		}
	}
private:
	CommandPressBackspaceShell<Container>	mBackspace;
	CommandDefaultShell<Container>		mDefault;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_SPECIAL_SYBOL_PROCESSOR_HPP__
