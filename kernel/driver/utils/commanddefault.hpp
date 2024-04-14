/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commanddefault.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:45:49 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 11:04:56 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_COMMANDDEFAULT_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_COMMANDDEFAULT_HPP__

# include "common/command.hpp"
# include "driver/common_interface/textmode.hpp"
# include "utils/libft.h"

namespace kfs::driver::common {

class CommandDefault final : public kfs::interface::ICommand {
public:
	CommandDefault(kfs::driver::interface::ITextMode *textMode) :
	mTextMode(textMode) { }

	CommandDefault	&operator = (const char &c) {
		mCharacter = c;
		return *this;
	}


	void	execute() override {
		if (!ft_isprint(mCharacter))
			return;
		size_t	row = mTextMode->getCurrentRow();
		size_t	column = mTextMode->getCurrentColumn();
		
		mTextMode->write(mCharacter, row, column);
		if (++row == mTextMode->getRow()) {
			row = 0;
			if (++column == mTextMode->getColumn()) {
				column = 0;
				mTextMode->clear();
			}
		}
		mTextMode->setCursorPosition(row, column);
	}
private:
	char	mCharacter;
	kfs::driver::interface::ITextMode *mTextMode;
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_COMMANDDEFAULT_HPP__