/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_stack.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:02:48 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 21:26:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP__

# include "service/shell/interface/command_builtin.hpp"
# include "common/factory.hpp"

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
		auto&&	addr = reinterpret_cast<uint8_t *>(ebp);
		size_t	limit = ebp - esp;
		unsigned int	shift = 0x10;
		
		for (size_t it = 0; it < limit; it += shift) {
			printf("%8x: ", &addr[it]);
			for (size_t iti = 0; iti != shift; ++iti) {
				printf("%2p ", addr[it + iti]);
			}
			for (size_t iti = 0; iti != shift; ++iti) {
				if (kfs::isprint(addr[it + iti]) && !kfs::isspace(addr[it + iti])) {
					printf("%c", addr[it + iti]);
				} else {
					printf("%c", '.');
				}
			}
			printf("\n");
		}
		
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_STACK_HPP__
