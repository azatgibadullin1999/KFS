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

# include <stddef.h>
# include <iterator>
# include "common/command.hpp"


namespace kfs::shell {

template <typename Container>
class CommandPressBackspaceShell final : public kfs::interface::ICommand {
public:
	CommandPressBackspaceShell(Container &shared_container, typename Container::iterator &shared_it, kfs::interface::IConsole *console) :
	mSharedContainer(shared_container),
	mSharedIt(shared_it),
	mConsole(console) { }

	void	execute() override {
		if (mSharedContainer.begin() == mSharedIt) {
			return ;
		}
		mConsole->write(*mSharedIt);
		*mSharedIt = ' ';
		--mSharedIt;
	}
private:
	Container	&mSharedContainer;
	typename Container::iterator	&mSharedIt;
	kfs::interface::IConsole	*mConsole;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESSBACK_SPACE_HPP__
