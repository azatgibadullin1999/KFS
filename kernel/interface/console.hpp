/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:31:13 by larlena           #+#    #+#             */
/*   Updated: 2024/07/11 14:20:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_INTERFACE_CONSOLE_HPP__
# define __KFS_KERNEL_INTERFACE_CONSOLE_HPP__

# include "driver/common_interface/text_display.hpp"
# include "driver/common_interface/keyboard.hpp"
# include "driver/common_interface/symbol_processor.hpp"
namespace kfs::interface {

class IConsole {
public:
	IConsole() { }

	IConsole(
	kfs::driver::interface::ITextDisplay		*textDisplay,
	kfs::driver::interface::ISymbolProcessor	*processor,
	kfs::driver::interface::IKeyboard		*keyboard) :
	mTextDisplay(textDisplay),
	mProcessor(processor),
	mKeyboard(keyboard) { }

	virtual void	process() = 0;
	virtual void	write(char) = 0;
	virtual void	write(const char *) = 0;
	virtual char	read() = 0;
	virtual char	readBlocking() = 0;

	void	setTextDisplay(kfs::driver::interface::ITextDisplay *textDisplay) {
		mTextDisplay = textDisplay;
	}

	kfs::driver::interface::ITextDisplay*	getTextDisplay() {
		return mTextDisplay;
	}

	void	setSymbolProcessor(kfs::driver::interface::ISymbolProcessor *processor) {
		mProcessor = processor;
	}
	
	kfs::driver::interface::ISymbolProcessor*	getSymbolProcessor() {
		return mProcessor;
	}

	void	setKeyboard(kfs::driver::interface::IKeyboard *keyboard) {
		mKeyboard = keyboard;
	}
	
	kfs::driver::interface::IKeyboard*	getKeyboard() {
		return mKeyboard;
	}
protected:
	kfs::driver::interface::ITextDisplay		*mTextDisplay;
	kfs::driver::interface::ISymbolProcessor	*mProcessor;
	kfs::driver::interface::IKeyboard		*mKeyboard;
};

}

#endif // __KFS_KERNEL_INTERFACE_CONSOLE_HPP__
