/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_newline_auto_scroll.cc               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:15:19 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 19:37:49 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_press_newline_auto_scroll.hpp"
#include "command_press_scroll.hpp"

namespace kfs::driver::common {

void	CommandPressNewLineAutoScroll::execute() {
	static auto&&	scroll = CommandPressScroll(0, mTextDisplay);
	size_t	column = mTextDisplay->getCurrentColumn();
	size_t	row = 0;

	if (++column == mTextDisplay->getColumn() - 1) {
		mTextDisplay->setCursorPosition(row, column);
		scroll.execute();
		row = mTextDisplay->getCurrentRow();
		column = mTextDisplay->getCurrentColumn();
	}
	mTextDisplay->setCursorPosition(row, column);
}

}
