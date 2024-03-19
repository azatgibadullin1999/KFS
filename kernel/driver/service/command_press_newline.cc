/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_newline.cc                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:21:56 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 19:23:12 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_press_newline.hpp"

namespace kfs::driver::common {

void	CommandPressNewLine::execute() {
	size_t	column = mTextMode->getCurrentColumn();
	size_t	row = 0;

	if (++column == mTextMode->getColumn()) {
		column = 0;
		mTextMode->clear();
	}
	mTextMode->setCursorPosition(row, column);
}

}