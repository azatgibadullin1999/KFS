/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_scroll.cc                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:23:30 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 19:38:03 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_press_scroll.hpp"

namespace kfs::driver::common {

void	CommandPressScroll::execute() {
	if (mTextDisplay->getCurrentColumn() == 0)
		return ;
	for (size_t y = 0; y < mTextDisplay->getColumn() - 1; ++y) {
		for (size_t x = 0; x < mTextDisplay->getRow(); ++x) {
			mTextDisplay->write(mTextDisplay->read(x, y + 1), x, y);
		}
	}
	for (size_t y = mTextDisplay->getColumn() - 1; y < mTextDisplay->getColumn(); ++y) {
		for (size_t x = 0; x < mTextDisplay->getRow(); ++x) {
			mTextDisplay->write(' ', x, y);
		}
	}
	mTextDisplay->setCursorPosition(mTextDisplay->getCurrentRow(), mTextDisplay->getCurrentColumn() - 1);
}

}
