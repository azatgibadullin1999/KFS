/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_scroll.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:51:01 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 18:52:07 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_COMMAND_PRESS_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_COMMAND_PRESS_SCROLL_HPP__

# include "common/command.hpp"
# include "driver/common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandPressScroll final : public kfs::interface::ICommand {
public:
	CommandPressScroll(kfs::driver::interface::ITextMode *textMode) :
	mTextMode(textMode) { }

	void	execute() override {
		if (mTextMode->getCurrentColumn() == 0)
			return ;
		for (size_t y = 0; y < mTextMode->getColumn() - 1; ++y) {
			for (size_t x = 0; x < mTextMode->getRow(); ++x) {
				mTextMode->write(mTextMode->read(x, y + 1), x, y);
			}
		}
		for (size_t y = mTextMode->getColumn() - 1; y < mTextMode->getColumn(); ++y) {
			for (size_t x = 0; x < mTextMode->getRow(); ++x) {
				mTextMode->write(' ', x, y);
			}
		}
		
	}
private:
	kfs::driver::interface::ITextMode *mTextMode;
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_COMMAND_PRESS_SCROLL_HPP__
