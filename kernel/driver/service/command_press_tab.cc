/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_tab.cc                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:25:22 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 19:26:28 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_press_tab.hpp"

namespace kfs::driver::common {

void	CommandPressTab::execute() {
	auto&&	currentRow = mTextMode->getCurrentRow();
	auto&&	newCursorPositionByRow = currentRow + (mTabSize - (currentRow % mTabSize));

	mTextMode->setCursorPosition(newCursorPositionByRow, mTextMode->getCurrentColumn());
}

}
