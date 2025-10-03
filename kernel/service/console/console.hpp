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

#ifndef KFS_KERNEL_CONSOLE_HPP
# define KFS_KERNEL_CONSOLE_HPP

# include "service/console.hpp"
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
	char	read_blocking() override;
private:
	uint8_t	_scan_code_buff;
	char	_char_buff;
};

// }

typedef typename kfs::interface::SingletonWrapper<Console>	console;

}

#endif // KFS_KERNEL_CONSOLE_HPP