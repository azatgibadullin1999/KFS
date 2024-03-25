/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandpresstab.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:17:56 by larlena           #+#    #+#             */
/*   Updated: 2024/03/25 01:53:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSTAB_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSTAB_HPP__

# include <stdint.h>
# include <stddef.h>
# include "../../interface/command.hpp"
# include "../common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandPressTab : public kfs::interface::ICommand {
public:
	CommandPressTab(kfs::driver::interface::ITextMode *textMode, size_t tabSize) :
	mTextMode(textMode),
	mTabSize(tabSize) { }

	void	execute() override {
		auto&&	currentRow = mTextMode->getCurrentRow();

		mTextMode->setCursorPosition(currentRow + (mTabSize - (currentRow % mTabSize)), mTextMode->getCurrentColumn());
	}

private:
	kfs::driver::interface::ITextMode *mTextMode;
	size_t	mTabSize;
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSTAB_HPP__
