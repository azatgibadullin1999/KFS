/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_scroll.cc                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:23:30 by larlena           #+#    #+#             */
/*   Updated: 2024/04/17 17:01:36 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_press_scroll.hpp"

namespace kfs::driver::common {

void	CommandPressScroll::execute() {
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
	mTextMode->setCursorPosition(mTextMode->getCurrentRow(), mTextMode->getCurrentColumn() - 1);
}

}
