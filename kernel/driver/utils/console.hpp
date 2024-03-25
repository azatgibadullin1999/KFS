/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:46:27 by larlena           #+#    #+#             */
/*   Updated: 2024/03/23 21:22:52 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_CONSOLE_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_CONSOLE_HPP__

# include "../../interface/mediator.hpp"

namespace kfs::driver::common {

class Console : public kfs::interface::IMediator {
	void	notify(kfs::interface::BaseComponent *component, uint8_t event) override; 
}

};

#endif // __KFS_KERNEL_DRIVER_UTILS_CONSOLE_HPP__
