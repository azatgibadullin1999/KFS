/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_symbol_processor.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:23:52 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 18:46:49 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DIRVER_COMMON_INTERFACE_SPECIAL_SYMBOL_PROCESSOR_HPP__
# define __KFS_KERNEL_DIRVER_COMMON_INTERFACE_SPECIAL_SYMBOL_PROCESSOR_HPP__

# include "common/command.hpp"

namespace kfs::driver::interface {

class ISpecialSymbolProcessor {
public:
	virtual kfs::interface::ICommand	*process(const char&) const = 0;
};

}

#endif // __KFS_KERNEL_DIRVER_COMMON_INTERFACE_SPECIAL_SYMBOL_PROCESSOR_HPP__