/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_text_display.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:41:55 by larlena           #+#    #+#             */
/*   Updated: 2024/05/21 17:16:23 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_TEXT_DISPLAY_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_TEXT_DISPLAY_HPP__

# include "common/command.hpp"
# include "driver/common_interface/text_display.hpp"

namespace kfs::interface {

template <typename Child>
class CommandTextDisplay : public kfs::interface::ICommand {
public:
	CommandTextDisplay(char character, kfs::driver::interface::ITextDisplay *textDisplay) :
	mTextDisplay(textDisplay),
	mChar(character) { }

	CommandTextDisplay	&operator = (const char &c) noexcept {
		mChar = c;
		return *this;
	}

	bool	operator == (const char &c) const noexcept {
		return mChar == c;
	}

	void	execute() override {
		static_cast<Child *>(this)->execute();
	}

protected:
	kfs::driver::interface::ITextDisplay *mTextDisplay;
	char	mChar;
};

} // namespace kfs::interface

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_TEXT_DISPLAY_HPP__
