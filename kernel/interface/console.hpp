/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:31:13 by larlena           #+#    #+#             */
/*   Updated: 2024/05/13 15:42:58 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_INTERFACE_CONSOLE_HPP__
# define __KFS_KERNEL_INTERFACE_CONSOLE_HPP__

# include "driver/common_interface/textmode.hpp"
# include "driver/common_interface/keyboard.hpp"
# include "driver/common_interface/keyboard_decoder.hpp"
# include "driver/common_interface/special_symbol_processor.hpp"
namespace kfs::interface {

class IConsole {
public:
	IConsole() { }

	IConsole(
	kfs::driver::interface::ITextMode		*textmode,
	kfs::driver::interface::ISpecialSymbolProcessor	*processor,
	kfs::driver::interface::IKeyboardDecoder	*decoder,
	kfs::driver::interface::IKeyboard		*keyboard) :
	mTextmode(textmode),
	mProcessor(processor),
	mDecoder(decoder),
	mKeyboard(keyboard) { }

	virtual void	process() = 0;
	virtual void	write(char) = 0;
	virtual void	write(const char *) = 0;
	virtual char	read() = 0;
	virtual char	readBlocking() = 0;

	void	setTextmode(kfs::driver::interface::ITextMode *textmode) {
		mTextmode = textmode;
	}

	void	setSpecialSymbolProcessor(kfs::driver::interface::ISpecialSymbolProcessor *processor) {
		mProcessor = processor;
	}

	void	setKeyboardDecoder(kfs::driver::interface::IKeyboardDecoder *decoder) {
		mDecoder = decoder;
	}

	void	setKeyboard(kfs::driver::interface::IKeyboard *keyboard) {
		mKeyboard = keyboard;
	}
protected:
	kfs::driver::interface::ITextMode		*mTextmode;
	kfs::driver::interface::ISpecialSymbolProcessor	*mProcessor;
	kfs::driver::interface::IKeyboardDecoder	*mDecoder;
	kfs::driver::interface::IKeyboard		*mKeyboard;
};

}

#endif // __KFS_KERNEL_INTERFACE_CONSOLE_HPP__
