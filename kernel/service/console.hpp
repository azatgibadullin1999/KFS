/**
 * @file console.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_CONSOLE_HPP__
# define __KFS_KERNEL_SERVICE_CONSOLE_HPP__

# include "driver/common_interface/keyboard.hpp"
# include "driver/common_interface/text_display.hpp"
# include "driver/common_interface/symbol_processor.hpp"

namespace kfs::interface {

class IConsole {
public:
	IConsole() { }

	IConsole(
	kfs::driver::interface::ITextDisplay		*text_display,
	kfs::driver::interface::ISymbolProcessor	*processor,
	kfs::driver::interface::IKeyboard		*keyboard) :
	_text_display(text_display),
	_processor(processor),
	_keyboard(keyboard) { }

	virtual void	process() = 0;
	virtual void	write(char) = 0;
	virtual void	write(const char *) = 0;
	virtual char	read() = 0;
	virtual char	read_blocking() = 0;

	void	set_text_display(kfs::driver::interface::ITextDisplay *text_display) {
		_text_display = text_display;
	}

	kfs::driver::interface::ITextDisplay*	get_text_display() {
		return _text_display;
	}

	void	set_symbol_processor(kfs::driver::interface::ISymbolProcessor *processor) {
		_processor = processor;
	}
	
	kfs::driver::interface::ISymbolProcessor*	get_symbol_processor() {
		return _processor;
	}

	void	set_keyboard(kfs::driver::interface::IKeyboard *keyboard) {
		_keyboard = keyboard;
	}
	
	kfs::driver::interface::IKeyboard*	get_keyboard() {
		return _keyboard;
	}
protected:
	kfs::driver::interface::ITextDisplay		*_text_display;
	kfs::driver::interface::ISymbolProcessor	*_processor;
	kfs::driver::interface::IKeyboard		*_keyboard;
};

}

#endif // __KFS_KERNEL_SERVICE_CONSOLE_HPP__
