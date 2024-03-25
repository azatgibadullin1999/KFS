/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandpressbackspace.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:47:48 by larlena           #+#    #+#             */
/*   Updated: 2024/03/25 14:50:18 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSBACKSPACE_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSBACKSPACE_HPP__

# include <stddef.h>
# include "../../interface/command.hpp"
# include "../common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandPressBackspace : public kfs::interface::ICommand {
public:
	CommandPressBackspace(kfs::driver::interface::ITextMode *textMode) :
	mTextMode(textMode) { }

	void	execute() override {
		size_t	row = mTextMode->getCurrentRow();
		size_t	column = mTextMode->getCurrentColumn();
	
		if (row == 0 && column != 0) {
			column -= 1;
			row = mTextMode->getRow();
		}
		row -= 1;
		mTextMode->write(' ', row, column);
		mTextMode->setCursorPosition(row, column);
	}
private:
	kfs::driver::interface::ITextMode *mTextMode;
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSBACKSPACE_HPP__
