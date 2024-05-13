/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_stack.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:02:48 by larlena           #+#    #+#             */
/*   Updated: 2024/05/22 13:03:31 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP__

# include "service/shell/interface/command_builtin.hpp"
# include "kernel.hpp"
# include "common/factory.hpp"

extern void	*stack_top;

namespace kfs::shell {

class CommandBuiltinStack :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinStack> {
public:
	ktl::string_view	getName() const {
		return "stack";
	}
	ktl::string_view	getShortDescription() const {
		return "stack - Command prints kernel stack\n";
	}
	ktl::string_view	getFullDescription() const {
		return "da\n";
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
			it -= shift * kfs::atoi(*(mArgs + 1));
		}
		if (*(mArgs + 2)) {
			ite = it - shift * kfs::atoi(*(mArgs + 2));
		}
		
		for (; it > ite; it -= shift) {
			printf("%8x: ", it);
			for (size_t index = -1; index != -(shift + 1); --index) {
				printf("%2p ", it[index]);
				if (index == -(shift / 2)) {
					printf(" ");
				}
			}
			for (size_t index = 1; index != -(shift + 1); --index) {
				if (kfs::isprint(it[index]) && !kfs::isspace(it[index])) {
					printf("%c", it[index]);
				} else {
					printf("%c", '.');
				}
			}
			printf("\n");
		}
		printf("size of stack (divided by %d): %d  |  stack top: %8x\nebp: %8x  |  esp: %8x\n", shift, ((size_t)stack_top - esp) / shift, stack_top, esp, ebp);
		
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP__
