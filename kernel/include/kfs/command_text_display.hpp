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

#ifndef KFS_KERNEL_DRIVER_SERVICE_COMMAND_TEXT_DISPLAY_HPP
# define KFS_KERNEL_DRIVER_SERVICE_COMMAND_TEXT_DISPLAY_HPP

# include "pattern/command.hpp"
# include <kfs/text_display.hpp>

namespace kfs {

template <typename Child>
class CommandTextDisplay : public pattern::ICommand {
public:
	CommandTextDisplay(char character, kfs::ITextDisplay *text_display) :
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
	kfs::ITextDisplay *_text_display;
	char	_character;
};

} // namespace kfs

#endif // KFS_KERNEL_DRIVER_SERVICE_COMMAND_TEXT_DISPLAY_HPP
