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

#ifndef __KFS_KERNEL_INTERFACE_SHELL_HPP__
# define __KFS_KERNEL_INTERFACE_SHELL_HPP__

# include "console.hpp"

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
