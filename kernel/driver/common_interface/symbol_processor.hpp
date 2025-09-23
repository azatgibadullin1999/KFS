/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_processor.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:23:52 by larlena           #+#    #+#             */
/*   Updated: 2025/09/23 15:40:00 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_COMMON_INTERFACE_SYMBOL_PROCESSOR_HPP__
# define __KFS_KERNEL_DRIVER_COMMON_INTERFACE_SYMBOL_PROCESSOR_HPP__

# include <tuple>
# include <utility>
# include <algorithm>
# include "common/command.hpp"

namespace kfs::driver::interface {

class ISymbolProcessor {
public:
	virtual void	process(const char&) = 0;
};

template <size_t it, typename ... Args>
void	find(const char& c, std::tuple<Args...> &args) {
	if (std::get<it>(args) == c) {
		std::get<it>(args) = c;
		std::get<it>(args).execute();
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
	SymbolProcessor(Args&& ... args) : mArgs(std::move(args)...) { }
	SymbolProcessor(const SymbolProcessor& other) = default;
	SymbolProcessor(SymbolProcessor&& other) = default;


	void	process(const char& c) override {
		find<sizeof...(Args) - 1>(c, mArgs);
	}
private:
	std::tuple<Args...>	mArgs;
};

}

#endif // __KFS_KERNEL_DRIVER_COMMON_INTERFACE_SYMBOL_PROCESSOR_HPP__