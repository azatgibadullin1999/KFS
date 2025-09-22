/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_stack.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:02:48 by larlena           #+#    #+#             */
/*   Updated: 2025/09/22 14:09:34 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP__

# include <cstdlib>
# include <cctype>

# include "interface/command_builtin.hpp"
# include "factory.hpp"

extern void	*stack_top;

namespace kfs::shell {

class CommandBuiltinStack :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinStack> {
public:
	std::string_view	getName() const {
		return "stack";
	}
	std::string_view	getShortDescription() const {
		return "prints kernel stack";
	}
	std::string_view	getFullDescription() const {
		return "da";
	}
	void		execute() {
		size_t	esp;
		size_t	ebp;
		asm("mov %%esp, %0\t\n" : "=r"(esp));
		asm("mov %%ebp, %0\t\n" : "=r"(ebp));
		unsigned int	shift = 0x10;
		auto	it = reinterpret_cast<uint8_t *>(stack_top);
		auto	ite = reinterpret_cast<uint8_t *>(esp);

		if (*(mArgs + 1)) {
			it -= shift * std::atoi(*(mArgs + 1));
		}
		if (*(mArgs + 2)) {
			ite = it - shift * std::atoi(*(mArgs + 2));
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
		std::printf("size of stack (divided by %d): %d  |  stack top: %8x\nebp: %8x  |  esp: %8x\n", shift, ((size_t)stack_top - esp) / shift, stack_top, esp, ebp);
		
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP__
