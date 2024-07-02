/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_symbol_processor_auto_scroll.hpp           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:31:34 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 17:32:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_AUTO_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_AUTO_SCROLL_HPP__

# include "driver/common_interface/special_symbol_processor.hpp"
# include "driver/common_interface/textmode.hpp"

namespace kfs::driver::common {

class SpecialSymbolProcessorAutoScroll : public kfs::driver::interface::ISpecialSymbolProcessor {
public:
	SpecialSymbolProcessorAutoScroll(kfs::driver::interface::ITextMode *textmode) :
	mTextmode(textmode) { }

	kfs::interface::ICommand	*process(const char&) override;
private:
	kfs::driver::interface::ITextMode *mTextmode;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_AUTO_SCROLL_HPP__
