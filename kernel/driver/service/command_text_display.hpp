/**
 * @file command_text_display.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_TEXT_DISPLAY_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_TEXT_DISPLAY_HPP__

# include "common/command.hpp"
# include "driver/common_interface/text_display.hpp"

namespace kfs::interface {

template <typename Child>
class CommandTextDisplay : public kfs::interface::ICommand {
public:
	CommandTextDisplay(char character, kfs::driver::interface::ITextDisplay *text_display) :
	_text_display(text_display),
	_character(character) { }

	CommandTextDisplay	&operator = (const char &c) noexcept {
		_character = c;
		return *this;
	}

	bool	operator == (const char &c) const noexcept {
		return _character == c;
	}

	void	execute() override {
		static_cast<Child *>(this)->execute();
	}

protected:
	kfs::driver::interface::ITextDisplay *_text_display;
	char	_character;
};

} // namespace kfs::interface

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_TEXT_DISPLAY_HPP__
