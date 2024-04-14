/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:52:03 by larlena           #+#    #+#             */
/*   Updated: 2024/03/23 21:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_INTERFACE_COMMAND_HPP__
# define __KFS_KERNEL_INTERFACE_COMMAND_HPP__

namespace kfs::interface {

class ICommand {
public:
	virtual void	execute() = 0;
};
	
}

#endif // __KFS_KERNEL_INTERFACE_COMMAND_HPP__