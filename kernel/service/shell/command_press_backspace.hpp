/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_backspace.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:47:48 by larlena           #+#    #+#             */
/*   Updated: 2024/05/03 18:43:42 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESSBACK_SPACE_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESSBACK_SPACE_HPP__

# include <stddef.h>
# include "common/command.hpp"
# include "utils/stl/iterator_traits.hpp"


namespace kfs::shell {

template <typename Container>
class CommandPressBackspaceShell final : public kfs::interface::ICommand {
public:
	CommandPressBackspaceShell(Container &sharedContainer, typename Container::iterator &sharedIt, kfs::interface::IConsole *console) :
	mSharedContainer(sharedContainer),
	mSharedIt(sharedIt),
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
