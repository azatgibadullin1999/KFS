/**
 * @file shell.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "shell.hpp"
#include "symbol_processor.hpp"
#include "impl/factory_command_builtin_default.hpp"

namespace {

template <typename ContainerArgs, typename ContainerStr>
ContainerArgs	&parse(ContainerArgs &args, ContainerStr &str) {
	static const std::array<char, 6>	space_chars{'\t', '\v', ' ' , '\n', '\r', '\f'};
	auto&&	it = std::ranges::find_if(str, [](auto &&ch) {
		return std::ranges::find(space_chars, ch) == space_chars.end();
	});
	auto&&	args_it = args.begin();
	auto	ite = it;

	for (; args_it != args.end() - 1 && it != str.end(); ++args_it) {
		*args_it = it;
		it = std::find_first_of(it, str.end(), space_chars.begin(), space_chars.end());
		ite = std::find_if(it, str.end(), [](auto &&ch) {
			return std::ranges::find(space_chars, ch) == space_chars.end();
		});
		std::fill(it, ite, 0);
		it = ite;
	}
	*--args_it = nullptr;
	return args;
}

}

void	kfs::Shell::process() {
	static auto&&	factory = kfs::shell::FactoryCommandBuiltinDefault();
	auto&&	shared_it = _input_string_buff.begin();
	auto&&	processor = kfs::shell::SymbolProcessorForShell<Container>(_input_string_buff, shared_it, _console);
	std::fill(_input_string_buff.begin(), _input_string_buff.end(), 0);
	std::fill(_args.begin(), _args.end(), nullptr);

	_console->write(mPromptForInput);
	while (*shared_it != '\n') {
		*shared_it = _console->read_blocking();
		processor.process(*shared_it);
	}
	_console->write('\n');

	_args = parse(_args, _input_string_buff);
	factory.process(*_args.begin())->set_args(_args.data())->execute();
}
