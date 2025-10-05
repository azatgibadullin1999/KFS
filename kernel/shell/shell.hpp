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

#ifndef KFS_KERNEL_SERVICE_SHELL_SHELL_HPP
# define KFS_KERNEL_SERVICE_SHELL_SHELL_HPP

# include <array>

# include <kfs/shell.hpp>

namespace kfs {

class Shell : public kfs::IShell {
public:
	typedef std::array<char, 32>		Container;
	typedef std::array<Container::iterator, 8> ContainerOfArgs;
	using IShell::IShell;

	void	process() override;
private:
	Container	_input_string_buff;
	ContainerOfArgs	_args;
	const char	_prompt[6] = "L&D> ";
};

}

#endif // KFS_KERNEL_SERVICE_SHELL_SHELL_HPP
