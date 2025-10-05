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

#ifndef PATTERN_COMMAND_HPP
# define PATTERN_COMMAND_HPP

namespace pattern {

class ICommand {
public:
	virtual ~ICommand() { }
	virtual void	execute() = 0;
};
	
}

#endif // PATTERN_COMMAND_HPP