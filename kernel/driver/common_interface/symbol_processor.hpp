/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_processor.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:23:52 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 20:07:16 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_COMMON_INTERFACE_SYMBOL_PROCESSOR_HPP__
# define __KFS_KERNEL_DRIVER_COMMON_INTERFACE_SYMBOL_PROCESSOR_HPP__

# include "common/command.hpp"
# include "utils/stl/tuple.hpp"
# include "utils/stl/algorithm.hpp"

namespace kfs::driver::interface {

class ISymbolProcessor {
public:
	virtual void	process(const char&) = 0;
};

template <size_t it, typename ... Args>
void	find(const char& c, ktl::tuple<Args...> &args) {
	if (ktl::get<it>(args) == c) {
		ktl::get<it>(args) = c;
		ktl::get<it>(args).execute();
		return;
	}
	if constexpr (it != 0) {
		find<it - 1>(c, args);
	}
}

template <typename ... Args>
class SymbolProcessor : public ISymbolProcessor {
public:
	SymbolProcessor() = default;
	SymbolProcessor(const Args& ... args) : mArgs(args...) { }
	SymbolProcessor(Args&& ... args) : mArgs(ktl::move(args)...) { }
	SymbolProcessor(const SymbolProcessor& other) = default;
	SymbolProcessor(SymbolProcessor&& other) = default;


	void	process(const char& c) override {
		find<sizeof...(Args) - 1>(c, mArgs);
	}
private:
	ktl::tuple<Args...>	mArgs;
};

}

#endif // __KFS_KERNEL_DRIVER_COMMON_INTERFACE_SYMBOL_PROCESSOR_HPP__