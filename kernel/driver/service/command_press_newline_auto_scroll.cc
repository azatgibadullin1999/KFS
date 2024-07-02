/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_newline_auto_scroll.cc               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:15:19 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 17:23:55 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_press_newline_auto_scroll.hpp"
#include "command_press_scroll.hpp"

namespace kfs::driver::common {

void	CommandPressNewLineAutoScroll::execute() {
	static auto&&	scroll = CommandPressScroll(mTextMode);
	size_t	column = mTextMode->getCurrentColumn();
	size_t	row = 0;

	if (++column == mTextMode->getColumn() - 1) {
		mTextMode->setCursorPosition(row, column);
		scroll.execute();
		row = mTextMode->getCurrentRow();
		column = mTextMode->getCurrentColumn();
	}
	mTextMode->setCursorPosition(row, column);
}

}
