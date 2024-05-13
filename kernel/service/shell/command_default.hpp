/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_default.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:45:49 by larlena           #+#    #+#             */
/*   Updated: 2024/04/28 06:41:58 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_COMMAND_DEFAULT_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_COMMAND_DEFAULT_HPP__

# include "common/command.hpp"
# include "utils/stl/iterator_traits.hpp"
# include "interface/console.hpp"

namespace kfs::shell {

template <typename Container>
class CommandDefaultShell final : public kfs::interface::ICommand {
public:
	CommandDefaultShell(Container &sharedContainer, typename Container::iterator &sharedIt, kfs::interface::IConsole *console) :
	mSharedContainer(sharedContainer),
	mSharedIt(sharedIt),
	mConsole(console) { }

	CommandDefaultShell	&operator = (const char &c) {
		mCharacter = c;
		return *this;
	}

	void	execute() override {
		if (!kfs::isprint(mCharacter) || mSharedIt == (mSharedContainer.end() - 1))
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