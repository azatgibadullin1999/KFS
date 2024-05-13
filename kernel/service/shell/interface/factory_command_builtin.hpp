/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory_command_builtin.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:30:51 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 16:17:31 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_FACTORY_COMMAND_BUILTIN_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_FACTORY_COMMAND_BUILTIN_HPP__

# include "utils/stl/array.hpp"
# include "utils/stl/algorithm.hpp"
# include "utils/stl/string_view.hpp"
# include "utils/libft.hpp"
# include "command_builtin.hpp"

namespace kfs::shell {

template <typename ... Args>
class FactoryCommandBuiltin {
	using Container = ktl::array<kfs::shell::interface::ICommandBuiltin *, sizeof ... (Args)>;
public:
	FactoryCommandBuiltin() :
	mArray{static_cast<kfs::shell::interface::ICommandBuiltin *>(Args::create()) ...} { }

	kfs::shell::interface::ICommandBuiltin	*process(ktl::string_view command) {
		return *ktl::find(mArray.begin(), mArray.end() - 1, command);
	}
private:
	Container	mArray;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_FACTORY_COMMAND_BUILTIN_HPP__
