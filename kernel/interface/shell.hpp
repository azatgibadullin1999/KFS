/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:08:28 by larlena           #+#    #+#             */
/*   Updated: 2024/04/23 22:10:43 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_INTERFACE_SHELL_HPP__
# define __KFS_KERNEL_INTERFACE_SHELL_HPP__

# include "interface/console.hpp"

namespace kfs::interface {

class IShell {
public:
	IShell(IConsole *console) :
	mConsole(console) { }

	virtual void	process() = 0;
protected:
	IConsole	*mConsole;
};

}

#endif // __KFS_KERNEL_INTERFACE_SHELL_HPP__
