/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_newline.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:16:34 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 18:51:52 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_COMMAND_PRESS_NEWLINE_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_COMMAND_PRESS_NEWLINE_HPP__

# include <stddef.h>
# include "common/command.hpp"
# include "driver/common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandPressNewLine final : public kfs::interface::ICommand {
public:
	CommandPressNewLine(kfs::driver::interface::ITextMode *textMode) :
	mTextMode(textMode) { }

	void	execute() override {
		size_t	column = mTextMode->getCurrentColumn();
		size_t	row = 0;

		if (++column == mTextMode->getColumn()) {
			column = 0;
			mTextMode->clear();
		}
		mTextMode->setCursorPosition(row, column);
	}
private:
	kfs::driver::interface::ITextMode	*mTextMode;
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_COMMAND_PRESS_NEWLINE_HPP__
