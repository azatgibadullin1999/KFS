/**
 * @file factory_command_builtin.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_SHELL_FACTORY_COMMAND_BUILTIN_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_FACTORY_COMMAND_BUILTIN_HPP__

# include <array>
# include <algorithm>
# include <string_view>

# include "command_builtin.hpp"

namespace kfs::shell {

template <typename ... Args>
class FactoryCommandBuiltin {
	using Container = std::array<kfs::shell::interface::ICommandBuiltin *, sizeof ... (Args)>;
public:
	FactoryCommandBuiltin() :
	_array{static_cast<kfs::shell::interface::ICommandBuiltin *>(Args::create()) ...} { }

	kfs::shell::interface::ICommandBuiltin	*process(std::string_view command) {
		return *std::find(_array.begin(), _array.end() - 1, command);
	}
private:
	Container	_array;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_FACTORY_COMMAND_BUILTIN_HPP__
