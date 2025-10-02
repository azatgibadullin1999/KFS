/**
 * @file shell.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_SHELL_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_HPP__

# include <service/console.hpp>

namespace kfs::interface {

class IShell {
public:
	IShell(IConsole *console) :
	_console(console) { }

	virtual void	process() = 0;
protected:
	IConsole	*_console;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_HPP__
