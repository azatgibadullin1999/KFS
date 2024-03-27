/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:26:50 by larlena           #+#    #+#             */
/*   Updated: 2024/03/27 15:58:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_CONSOLE_HPP__
# define __KFS_KERNEL_CONSOLE_HPP__

# include "interface/console.hpp"

namespace kfs {

class Console : kfs::interface::IConsole {
public:
	using IConsole::IConsole;

	void	doWork() override;
private:
	uint8_t	mScanCodeBuff;
	char	mCharBuff;
};

}

#endif // __KFS_KERNEL_CONSOLE_HPP__