/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specialsymbolprocessor.cc                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:29:56 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 11:03:41 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "driver/common_interface/kayboard_decoder.hpp"
#include "specialsymbolprocessor.hpp"
#include "commandpressbackspace.hpp"
#include "commandpressnewline.hpp"
#include "commandpressscroll.hpp"
#include "commandpresstab.hpp"
#include "commanddefault.hpp"

namespace kfs::driver::common {

kfs::interface::ICommand	*SpecialSymbolProcessor::process(const char &symbol) const {
	static CommandPressBackspace	Backspace(mTextmode);
	static CommandPressNewLine	NewLine(mTextmode);
	static CommandPressScroll	Scroll(mTextmode);
	static CommandPressTab		Tab(mTextmode, 8);
	static CommandDefault		Default(mTextmode);

	if (symbol == '\b') {
		return &Backspace;
	} else if (symbol == '\n') {
		return &NewLine;
	} else if (symbol == '\t') {
		return &Tab;
	} else if (static_cast<uint8_t>(symbol) == kfs::driver::interface::IKayboardDecoder::DOWN) {
		return &Scroll;
	}
	Default = symbol;
	return &Default;
}

}
