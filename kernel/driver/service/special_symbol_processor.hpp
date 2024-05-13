/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_symbol_processor.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:27:22 by larlena           #+#    #+#             */
/*   Updated: 2024/05/13 15:42:50 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_HPP__

# include "driver/common_interface/special_symbol_processor.hpp"
# include "driver/common_interface/textmode.hpp"

namespace kfs::driver::common {

class SpecialSymbolProcessor : public kfs::driver::interface::ISpecialSymbolProcessor {
public:
	SpecialSymbolProcessor(kfs::driver::interface::ITextMode *textmode) :
	mTextmode(textmode) { }

	kfs::interface::ICommand	*process(const char&) override;
private:
	kfs::driver::interface::ITextMode *mTextmode;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_HPP__