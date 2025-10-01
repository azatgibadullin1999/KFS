/**
 * @file command.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_INTERFACE_COMMAND_HPP__
# define __KFS_KERNEL_INTERFACE_COMMAND_HPP__

namespace kfs::interface {

class ICommand {
public:
	virtual ~ICommand() { }
	virtual void	execute() = 0;
};
	
}

#endif // __KFS_KERNEL_INTERFACE_COMMAND_HPP__