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

#ifndef KFS_KERNEL_SERVICE_CONSOLE_HPP
# define KFS_KERNEL_SERVICE_CONSOLE_HPP

# include "kfs/keyboard.hpp"
# include "kfs/text_display.hpp"
# include "kfs/symbol_processor.hpp"

namespace kfs {

class IConsole {
public:
	IConsole() { }

	IConsole(
	kfs::ITextDisplay		*text_display,
	kfs::ISymbolProcessor	*processor,
	kfs::IKeyboard		*keyboard) :
	_text_display(text_display),
	_processor(processor),
	_keyboard(keyboard) { }

	virtual void	process() = 0;
	virtual void	write(char) = 0;
	virtual void	write(const char *) = 0;
	virtual char	read() = 0;
	virtual char	read_blocking() = 0;

	void	set_text_display(kfs::ITextDisplay *text_display) {
		_text_display = text_display;
	}

	kfs::ITextDisplay*	get_text_display() {
		return _text_display;
	}

	void	set_symbol_processor(kfs::ISymbolProcessor *processor) {
		_processor = processor;
	}
	
	kfs::ISymbolProcessor*	get_symbol_processor() {
		return _processor;
	}

	void	set_keyboard(kfs::IKeyboard *keyboard) {
		_keyboard = keyboard;
	}
	
	kfs::IKeyboard*	get_keyboard() {
		return _keyboard;
	}
protected:
	kfs::ITextDisplay		*_text_display;
	kfs::ISymbolProcessor	*_processor;
	kfs::IKeyboard		*_keyboard;
};

}

#endif // KFS_KERNEL_SERVICE_CONSOLE_HPP
