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

# include <stddef.h>
# include <iterator>
# include "common/command.hpp"


namespace kfs::shell {

template <typename Container>
class CommandPressNewLineShell final : public kfs::interface::ICommand {
public:
	CommandPressNewLineShell(typename Container::iterator &sharedIt, kfs::interface::IConsole *console) :
	mSharedIt(sharedIt),
	mConsole(console) { }

	void	execute() override {
		mConsole->write('\n');
	}
private:
	typename Container::iterator	&mSharedIt;
	kfs::interface::IConsole	*mConsole;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESS_NEWLINE_HPP__
