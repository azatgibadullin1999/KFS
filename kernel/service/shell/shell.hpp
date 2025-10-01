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

#ifndef __KFS_KERNEL_SERVICE_SHELL_SHELL_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_SHELL_HPP__

# include "../shell.hpp"
# include <array>

namespace kfs {

class Shell : public kfs::interface::IShell {
public:
	typedef std::array<char, 32>		Container;
	typedef std::array<Container::iterator, 8> ContainerOfArgs;
	using IShell::IShell;

	void	process() override;
private:
	inline static const char	enter = '\n';
	Container	mInputStringBuff;
	ContainerOfArgs	mArgs;
	const char	mPromptForInput[6] = "L&D> ";
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_SHELL_HPP__
