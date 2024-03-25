/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:41:15 by larlena           #+#    #+#             */
/*   Updated: 2024/03/23 14:01:38 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KERNEL_DRIVER_COMMON_INTERFACES_CONSOLE_HPP__
# define __KERNEL_DRIVER_COMMON_INTERFACES_CONSOLE_HPP__

# include "keyboard.hpp"

namespace kfs::driver::interface {

class IConsole {
public:
	virtual void	write() = 0;
protected:
private:
};

}

#endif // __KERNEL_DRIVER_COMMON_INTERFACES_CONSOLE_HPP__
