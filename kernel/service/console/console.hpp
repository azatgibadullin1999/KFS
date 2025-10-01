/**
 * @file console.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_CONSOLE_HPP__
# define __KFS_KERNEL_CONSOLE_HPP__

# include "../console.hpp"
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

typedef typename kfs::interface::singleton_wrapper<Console>	console;

}

#endif // __KFS_KERNEL_CONSOLE_HPP__