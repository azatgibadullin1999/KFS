/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_newline.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:16:34 by larlena           #+#    #+#             */
/*   Updated: 2024/04/27 23:08:02 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESS_NEWLINE_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_COMMAND_PRESS_NEWLINE_HPP__

# include <stddef.h>
# include "common/command.hpp"
# include "utils/stl/iterator_traits.hpp"


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
