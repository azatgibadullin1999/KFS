/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_tab.cc                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:25:22 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 19:38:06 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_press_tab.hpp"

namespace kfs::driver::common {

void	CommandPressTab::execute() {
	auto&&	currentRow = mTextDisplay->getCurrentRow();
	auto&&	newCursorPositionByRow = currentRow + (mTabSize - (currentRow % mTabSize));

	mTextDisplay->setCursorPosition(newCursorPositionByRow, mTextDisplay->getCurrentColumn());
}

}
