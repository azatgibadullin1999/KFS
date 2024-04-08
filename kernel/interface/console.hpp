/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:31:13 by larlena           #+#    #+#             */
/*   Updated: 2024/03/27 17:36:28 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_INTERFACE_CONSOLE_HPP__
# define __KFS_KERNEL_INTERFACE_CONSOLE_HPP__

# include "../driver/common_interface/textmode.hpp"
// # include "../driver/common_interface/keyboard.hpp"
# include "../driver/common_interface/keyboard_decoder.hpp"
# include "../driver/common_interface/specialsymbolprocessor.hpp"
namespace kfs::interface {

class IConsole {
public:
	IConsole(
	kfs::driver::interface::ITextMode		*textmode,
	kfs::driver::interface::ISpecialSymbolProcessor	*processor,
	kfs::driver::interface::IKeyboardDecoder	*decoder,
	kfs::driver::interface::IKayboard		*keyboard) :
	mTextmode(textmode),
	mProcessor(processor),
	mDecoder(decoder),
	mKeyboard(keyboard) { }

	virtual void	doWork() = 0;
protected:
	kfs::driver::interface::ITextMode		*mTextmode;
	kfs::driver::interface::ISpecialSymbolProcessor	*mProcessor;
	kfs::driver::interface::IKeyboardDecoder	*mDecoder;
	kfs::driver::interface::IKayboard		*mKeyboard;
};

}

#endif // __KFS_KERNEL_INTERFACE_CONSOLE_HPP__
