/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandpresstab.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:17:56 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 11:15:32 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSTAB_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSTAB_HPP__

# include <stdint.h>
# include <stddef.h>
# include "common/command.hpp"
# include "driver/common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandPressTab final : public kfs::interface::ICommand {
public:
	CommandPressTab(kfs::driver::interface::ITextMode *textMode, size_t tabSize) :
	mTextMode(textMode),
	mTabSize(tabSize) { }

	void	execute() override {
		auto&&	currentRow = mTextMode->getCurrentRow();
		auto&&	cursorPositionByRow = currentRow + (mTabSize - (currentRow % mTabSize));

		mTextMode->setCursorPosition(cursorPositionByRow, mTextMode->getCurrentColumn());
	}

private:
	kfs::driver::interface::ITextMode *mTextMode;
	size_t	mTabSize;
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSTAB_HPP__
