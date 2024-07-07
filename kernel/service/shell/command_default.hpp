/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_default.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:45:49 by larlena           #+#    #+#             */
/*   Updated: 2024/06/12 18:10:23 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_COMMAND_DEFAULT_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_COMMAND_DEFAULT_HPP__

# include <iterator>
# include "common/command.hpp"
# include "interface/console.hpp"

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
		if (!isprint(mCharacter) || mSharedIt == (mSharedContainer.end() - 1))
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