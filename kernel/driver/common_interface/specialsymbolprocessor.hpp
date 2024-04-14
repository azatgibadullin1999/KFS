/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specialsymbolprocessor.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:23:52 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 11:05:23 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DIRVER_COMMON_INTERFACE_SPECIALSYMBOLPROCESSOR_HPP__
# define __KFS_KERNEL_DIRVER_COMMON_INTERFACE_SPECIALSYMBOLPROCESSOR_HPP__

# include "common/command.hpp"

namespace kfs::driver::interface {

class ISpecialSymbolProcessor {
public:
	virtual kfs::interface::ICommand	*process(const char&) const = 0;
};

}

#endif // __KFS_KERNEL_DIRVER_COMMON_INTERFACE_SPECIALSYMBOLPROCESSOR_HPP__