/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:26:50 by larlena           #+#    #+#             */
/*   Updated: 2024/05/13 15:42:36 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_CONSOLE_HPP__
# define __KFS_KERNEL_CONSOLE_HPP__

# include "interface/console.hpp"
# include "common/singleton.hpp"
namespace kfs {

// namespace {

class Console : public kfs::interface::IConsole {
public:
	using IConsole::IConsole;

	void	process() override;
	void	write(char c) override;
	void	write(const char *str) override;
	char	read() override;
	char	readBlocking() override;
private:
	uint8_t	mScanCodeBuff;
	char	mCharBuff;
};

// }

typedef typename kfs::interface::SingletonWrapper<Console>	ConsoleSingleton;

}

#endif // __KFS_KERNEL_CONSOLE_HPP__