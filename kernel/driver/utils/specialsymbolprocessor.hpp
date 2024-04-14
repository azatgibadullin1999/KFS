/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specialsymbolprocessor.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:27:22 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 11:03:58 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_SPECIALSYMBOLPROCESSOR_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_SPECIALSYMBOLPROCESSOR_HPP__

# include "driver/common_interface/specialsymbolprocessor.hpp"
# include "driver/common_interface/textmode.hpp"

namespace kfs::driver::common {

class SpecialSymbolProcessor : public kfs::driver::interface::ISpecialSymbolProcessor {
public:
	SpecialSymbolProcessor(kfs::driver::interface::ITextMode *textmode) :
	mTextmode(textmode) { }

	kfs::interface::ICommand	*process(const char&) const override;
private:
	kfs::driver::interface::ITextMode *mTextmode;
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_SPECIALSYMBOLPROCESSOR_HPP__