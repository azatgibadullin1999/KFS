/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:31:13 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 18:54:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_INTERFACE_CONSOLE_HPP__
# define __KFS_KERNEL_INTERFACE_CONSOLE_HPP__

# include "driver/common_interface/textmode.hpp"
# include "driver/common_interface/kayboard.hpp"
# include "driver/common_interface/kayboard_decoder.hpp"
# include "driver/common_interface/special_symbol_processor.hpp"
namespace kfs::interface {

class IConsole {
public:
	IConsole(
	kfs::driver::interface::ITextMode		*textmode,
	kfs::driver::interface::ISpecialSymbolProcessor	*processor,
	kfs::driver::interface::IKayboardDecoder	*decoder,
	kfs::driver::interface::IKayboard		*kayboard) :
	mTextmode(textmode),
	mProcessor(processor),
	mDecoder(decoder),
	mKayboard(kayboard) { }

	virtual void	doWork() = 0;
protected:
	kfs::driver::interface::ITextMode		*mTextmode;
	kfs::driver::interface::ISpecialSymbolProcessor	*mProcessor;
	kfs::driver::interface::IKayboardDecoder	*mDecoder;
	kfs::driver::interface::IKayboard		*mKayboard;
};

}

#endif // __KFS_KERNEL_INTERFACE_CONSOLE_HPP__
