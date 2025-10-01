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
	static const std::array<char, 6>	spaceChars{'\t', '\v', ' ' , '\n', '\r', '\f'};
	auto&&	it = std::ranges::find_if(str, [&spaceChars](auto &&ch) {
		return std::ranges::find(spaceChars, ch) == spaceChars.end();
	});
	auto&&	argsIt = args.begin();
	auto	ite = it;

	for (; argsIt != args.end() - 1 && it != str.end(); ++argsIt) {
		*argsIt = it;
		it = std::find_first_of(it, str.end(), spaceChars.begin(), spaceChars.end());
		ite = std::find_if(it, str.end(), [&spaceChars](auto &&ch) {
			return std::ranges::find(spaceChars, ch) == spaceChars.end();
		});
		std::fill(it, ite, 0);
		it = ite;
	}
	*--argsIt = nullptr;
	return args;
}

}

void	kfs::Shell::process() {
	static auto&&	factory = kfs::shell::FactoryCommandBuiltinDefault();
	auto&&	sharedIt = mInputStringBuff.begin();
	auto&&	processor = kfs::shell::SymbolProcessorForShell<Container>(mInputStringBuff, sharedIt, mConsole);
	std::fill(mInputStringBuff.begin(), mInputStringBuff.end(), 0);
	std::fill(mArgs.begin(), mArgs.end(), nullptr);

	mConsole->write(mPromptForInput);
	while (*sharedIt != '\n') {
		*sharedIt = mConsole->readBlocking();
		processor.process(*sharedIt);
	}
	mConsole->write('\n');

	mArgs = parse(mArgs, mInputStringBuff);
	factory.process(*mArgs.begin())->setArgs(mArgs.data())->execute();
}
