/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_backspace.cc                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:19:12 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 19:20:47 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_press_backspace.hpp"

namespace kfs::driver::common {

void	CommandPressBackspace::execute() {
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

}