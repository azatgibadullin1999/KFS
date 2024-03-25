/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandpressnewline.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:16:34 by larlena           #+#    #+#             */
/*   Updated: 2024/03/25 01:53:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSNEWLINE_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSNEWLINE_HPP__

# include <stddef.h>
# include "../../interface/command.hpp"
# include "../common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandPressNewLine : public kfs::interface::ICommand {
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

#endif // __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSNEWLINE_HPP__
