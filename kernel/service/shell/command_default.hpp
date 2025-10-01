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

#ifndef __KFS_KERNEL_SERVICE_SHELL_COMMAND_DEFAULT_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_COMMAND_DEFAULT_HPP__

# include <cctype>

# include "common/command.hpp"
# include "../console.hpp"

namespace kfs::shell {

template <typename Container>
class CommandDefaultShell final : public kfs::interface::ICommand {
public:
	CommandDefaultShell(Container &sharedContainer, typename Container::iterator &sharedIt, kfs::interface::IConsole *console) :
	mSharedContainer(sharedContainer),
	mConsole(console),
	mSharedIt(sharedIt) { }

	CommandDefaultShell	&operator = (const char &c) {
		mCharacter = c;
		return *this;
	}

	void	execute() override {
		if (!std::isprint(mCharacter) || mSharedIt == (mSharedContainer.end() - 1))
			return;
		*mSharedIt = mCharacter;
		mConsole->write(mCharacter);
		++mSharedIt;
	}
private:
	char	mCharacter;
	Container	&mSharedContainer;
	kfs::interface::IConsole	*mConsole;
	typename Container::iterator	&mSharedIt;

};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_COMMAND_DEFAULT_HPP__