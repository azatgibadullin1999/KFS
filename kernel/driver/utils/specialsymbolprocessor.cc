/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specialsymbolprocessor.cc                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:29:56 by larlena           #+#    #+#             */
/*   Updated: 2024/03/27 15:54:57 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common_interface/keyboard_decoder.hpp"
#include "specialsymbolprocessor.hpp"
#include "commandpressbackspace.hpp"
#include "commandpressnewline.hpp"
#include "commandpressscroll.hpp"
#include "commandpresstab.hpp"
#include "commanddefault.hpp"

namespace kfs::driver::common {

kfs::interface::ICommand	*SpecialSymbolProcessor::process(const char &symbol) const {
	static CommandPressBackspace	comBackspace(mTextmode);
	static CommandPressNewLine	comNewLine(mTextmode);
	static CommandPressScroll	comScroll(mTextmode);
	static CommandPressTab		comTab(mTextmode, 8);
	static CommandDefault		comDefault(mTextmode);

	if (symbol == '\b') {
		return &comBackspace;
	} else if (symbol == '\n') {
		return &comNewLine;
	} else if (symbol == '\t') {
		return &comTab;
	} else if (static_cast<uint8_t>(symbol) == kfs::driver::interface::IKeyboardDecoder::DOWN) {
		return &comScroll;
	}
	comDefault = symbol;
	return &comDefault;
}

}
