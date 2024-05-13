/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_symbol_processor.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:21:17 by larlena           #+#    #+#             */
/*   Updated: 2024/04/27 23:47:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_SPECIAL_SYBOL_PROCESSOR_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_SPECIAL_SYBOL_PROCESSOR_HPP__

# include "driver/common_interface/special_symbol_processor.hpp"
# include "utils/stl/iterator_traits.hpp"
# include "command_default.hpp"
# include "command_press_backspace.hpp"
# include "command_press_newline.hpp"

namespace kfs::shell {

template <typename Container>
class SpecialSymbolProcessorForShell : public kfs::driver::interface::ISpecialSymbolProcessor {
public:
	SpecialSymbolProcessorForShell(Container &sharedContainer, typename Container::iterator &sharedIt, kfs::interface::IConsole *console) :
		mBackspace(sharedContainer, sharedIt, console),
		mDefault(sharedContainer, sharedIt, console) { }

	kfs::interface::ICommand	*process(const char &symbol) override {
		if (symbol == '\b') {
			return &mBackspace;
		}
		mDefault = symbol;
		return &mDefault;
	}
private:
	CommandPressBackspaceShell<Container>	mBackspace;
	CommandDefaultShell<Container>		mDefault;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_SPECIAL_SYBOL_PROCESSOR_HPP__
