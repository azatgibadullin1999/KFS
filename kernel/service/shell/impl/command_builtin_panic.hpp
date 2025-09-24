/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_panic.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:05:04 by larlena           #+#    #+#             */
/*   Updated: 2025/09/23 19:29:13 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP__

#include <exception>
# include <string_view>

# include "service/shell/interface/command_builtin.hpp"
# include "service/panic/panic.hpp"
# include "common/factory.hpp"

namespace kfs::shell {

class CommandBuiltinPanic :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinPanic> {
public:
	std::string_view	getName() const {
		return "panic";
	}
	std::string_view	getShortDescription() const {
		return "calls panic function that stops system";
	}
	std::string_view	getFullDescription() const {
		return "da";
	}
	void		execute() {
		std::terminate();
	}
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_PANIC_HPP__
