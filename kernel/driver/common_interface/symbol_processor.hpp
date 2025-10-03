/**
 * @file symbol_processor.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_DRIVER_COMMON_INTERFACE_SYMBOL_PROCESSOR_HPP
# define KFS_KERNEL_DRIVER_COMMON_INTERFACE_SYMBOL_PROCESSOR_HPP

# include <tuple>
# include <utility>
# include <algorithm>

namespace kfs::driver::interface {

class ISymbolProcessor {
public:
	virtual void	process(const char&) = 0;
};

template <size_t It, typename ... Args>
void	find(const char& c, std::tuple<Args...> &args) {
	if (std::get<It>(args) == c) {
		std::get<It>(args) = c;
		std::get<It>(args).execute();
		return;
	}
	if constexpr (It != 0) {
		find<It - 1>(c, args);
	}
}

template <typename ... Args>
class SymbolProcessor : public ISymbolProcessor {
public:
	SymbolProcessor() = default;
	SymbolProcessor(const Args& ... args) : _args(args...) { }
	SymbolProcessor(Args&& ... args) : _args(std::move(args)...) { }
	SymbolProcessor(const SymbolProcessor& other) = default;
	SymbolProcessor(SymbolProcessor&& other) = default;


	void	process(const char& c) override {
		find<sizeof...(Args) - 1>(c, _args);
	}
private:
	std::tuple<Args...>	_args;
};

}

#endif // KFS_KERNEL_DRIVER_COMMON_INTERFACE_SYMBOL_PROCESSOR_HPP