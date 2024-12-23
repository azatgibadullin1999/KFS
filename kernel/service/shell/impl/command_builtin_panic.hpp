/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_panic.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:05:04 by larlena           #+#    #+#             */
/*   Updated: 2024/10/09 11:07:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP__

# include "service/shell/interface/command_builtin.hpp"
# include "common/factory.hpp"
# include "service/panic/panic.hpp"

namespace kfs::shell {

class CommandBuiltinPanic :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinPanic> {
public:
	ktl::string_view	getName() const {
		return "panic";
	}
	ktl::string_view	getShortDescription() const {
		return "panic - Calls panic function that stops system.\n";
	}
	ktl::string_view	getFullDescription() const {
		return "da\n";
	}
	void		execute() {
		panic();
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP__
