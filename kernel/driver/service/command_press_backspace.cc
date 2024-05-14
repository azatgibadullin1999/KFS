/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_backspace.cc                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:19:12 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 19:37:40 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_press_backspace.hpp"

namespace kfs::driver::common {

void	CommandPressBackspace::execute() {
	size_t	row = mTextDisplay->getCurrentRow();
	size_t	column = mTextDisplay->getCurrentColumn();

	if (row == 0 && column != 0) {
		column -= 1;
		row = mTextDisplay->getRow();
	}
	row -= 1;
	mTextDisplay->write(' ', row, column);
	mTextDisplay->setCursorPosition(row, column);	
}

}