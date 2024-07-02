/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_newline.cc                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:21:56 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 19:37:54 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_press_newline.hpp"

namespace kfs::driver::common {

void	CommandPressNewLine::execute() {
	size_t	column = mTextDisplay->getCurrentColumn();
	size_t	row = 0;

	if (++column == mTextDisplay->getColumn()) {
		column = 0;
		mTextDisplay->clear();
	}
	mTextDisplay->setCursorPosition(row, column);
}

}