/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_default_auto_scroll.cc                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:37:16 by larlena           #+#    #+#             */
/*   Updated: 2025/09/13 17:35:59 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>

#include "command_press_scroll.hpp"
#include "command_default_auto_scroll.hpp"

namespace kfs::driver::common {

void	CommandDefaultAutoScroll::execute() {
	static auto&&	scroll = CommandPressScroll(0, mTextDisplay);
	if (!std::isprint(mChar))
			return;
	size_t	row = mTextDisplay->getCurrentRow();
	size_t	column = mTextDisplay->getCurrentColumn();
		
	mTextDisplay->write(mChar, row, column);
	if (++row == mTextDisplay->getRow()) {
		row = 0;
		if (++column == mTextDisplay->getColumn() - 1) {
			mTextDisplay->setCursorPosition(row, column);
			scroll.execute();
			row = mTextDisplay->getCurrentRow();
			column = mTextDisplay->getCurrentColumn();
		}
	}
	mTextDisplay->setCursorPosition(row, column);
}

}
