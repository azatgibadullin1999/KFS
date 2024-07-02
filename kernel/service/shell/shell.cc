/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:12:42 by larlena           #+#    #+#             */
/*   Updated: 2024/05/14 23:06:02 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.hpp"
#include "symbol_processor.hpp"
#include "impl/factory_command_builtin_default.hpp"

namespace {

template <typename ContainerArgs, typename ContainerStr>
ContainerArgs	&parse(ContainerArgs &args, ContainerStr &str) {
	static const ktl::array<char, 6>	spaceChars{'\t', '\v', ' ' , '\n', '\r', '\f'};
	auto&&	it = ktl::find_first_not_of(str.begin(), str.end(), spaceChars.begin(), spaceChars.end());
	auto&&	argsIt = args.begin();
	auto	ite = it;

	for (; argsIt != args.end() - 1 && it != str.end(); ++argsIt) {
		*argsIt = it;
		it = ktl::find_first_of(it, str.end(), spaceChars.begin(), spaceChars.end());
		ite = ktl::find_first_not_of(it, str.end(), spaceChars.begin(), spaceChars.end());
		ktl::fill(it, ite, 0);
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
	ktl::fill(mInputStringBuff.begin(), mInputStringBuff.end(), 0);
	ktl::fill(mArgs.begin(), mArgs.end(), nullptr);

	mConsole->write(mPromptForInput);
	while (*sharedIt != '\n') {
		*sharedIt = mConsole->readBlocking();
		processor.process(*sharedIt);
	}
	mConsole->write('\n');

	mArgs = parse(mArgs, mInputStringBuff);
	factory.process(*mArgs.begin())->setArgs(mArgs.data())->execute();
}
