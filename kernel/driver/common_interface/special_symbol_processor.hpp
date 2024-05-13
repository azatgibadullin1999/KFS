/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_symbol_processor.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:23:52 by larlena           #+#    #+#             */
/*   Updated: 2024/05/13 15:42:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DIRVER_COMMON_INTERFACE_SPECIAL_SYMBOL_PROCESSOR_HPP__
# define __KFS_KERNEL_DIRVER_COMMON_INTERFACE_SPECIAL_SYMBOL_PROCESSOR_HPP__

# include "common/command.hpp"

namespace kfs::driver::interface {

class ISpecialSymbolProcessor {
public:
	virtual kfs::interface::ICommand	*process(const char&) = 0;
};

}

#endif // __KFS_KERNEL_DIRVER_COMMON_INTERFACE_SPECIAL_SYMBOL_PROCESSOR_HPP__