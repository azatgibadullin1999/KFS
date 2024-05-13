/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_default_auto_scroll.cc                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:37:16 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 17:12:07 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_default_auto_scroll.hpp"
#include "command_press_scroll.hpp"

namespace kfs::driver::common {

void	CommandDefaultAutoScroll::execute() {
	static auto&&	scroll = CommandPressScroll(mTextMode);
	if (!kfs::isprint(mCharacter))
			return;
	size_t	row = mTextMode->getCurrentRow();
	size_t	column = mTextMode->getCurrentColumn();
		
	mTextMode->write(mCharacter, row, column);
	if (++row == mTextMode->getRow()) {
		row = 0;
		if (++column == mTextMode->getColumn() - 1) {
			mTextMode->setCursorPosition(row, column);
			scroll.execute();
			row = mTextMode->getCurrentRow();
			column = mTextMode->getCurrentColumn();
		}
	}
	mTextMode->setCursorPosition(row, column);
}

}
