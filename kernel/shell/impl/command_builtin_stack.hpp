/**
 * @file command_builtin_stack.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP
# define KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP

# include <cstdlib>
# include <cctype>

# include "pattern/factory.hpp"
# include "../interface/command_builtin.hpp"

extern void	*g_stack_top;

namespace kfs::shell {

class CommandBuiltinStack :
	public kfs::shell::ICommandBuiltin,
	public pattern::StaticInstanceFactory<CommandBuiltinStack> {
public:
	std::string_view	get_name() const {
		return "stack";
	}
	std::string_view	get_short_description() const {
		return "prints kernel stack";
	}
	std::string_view	get_full_description() const {
		return "da";
	}
	void		execute() {
		size_t	esp;
		size_t	ebp;
		asm("mov %%esp, %0\t\n" : "=r"(esp));
		asm("mov %%ebp, %0\t\n" : "=r"(ebp));
		unsigned int	shift = 0x10;
		auto	it = reinterpret_cast<uint8_t *>(g_stack_top);
		auto	ite = reinterpret_cast<uint8_t *>(esp);

		if (*(_args + 1)) {
			it -= shift * std::atoi(*(_args + 1));
		}
		if (*(_args + 2)) {
			ite = it - shift * std::atoi(*(_args + 2));
		}
		
		for (; it > ite; it -= shift) {
			std::printf("%8x: ", it);
			for (size_t index = -1; index != -(shift + 1); --index) {
				std::printf("%2p ", it[index]);
				if (index == -(shift / 2)) {
					std::printf(" ");
				}
			}
			for (size_t index = 1; index != -(shift + 1); --index) {
				if (std::isprint(it[index]) && !std::isspace(it[index])) {
					std::printf("%c", it[index]);
				} else {
					std::printf("%c", '.');
				}
			}
			std::printf("\n");
		}
		std::printf("size of stack (divided by %d): %d  |  stack top: %8x\nebp: %8x  |  esp: %8x\n", shift, ((size_t)g_stack_top - esp) / shift, g_stack_top, esp, ebp);
		
	}
};

}

#endif // KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP
