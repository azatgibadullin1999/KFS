/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:27:33 by larlena           #+#    #+#             */
/*   Updated: 2025/03/27 19:29:03 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_INTERFACE_SINGLETON_HPP__
# define __KFS_KERNEL_INTERFACE_SINGLETON_HPP__

# include <utility>
// # include <memory>

namespace kfs::interface {

template <typename WrappedClass>
class singleton_wrapper final : public WrappedClass {
private:
	singleton_wrapper() { }
public:
	~singleton_wrapper() { }
	singleton_wrapper(const singleton_wrapper &inst) = delete;
	singleton_wrapper(singleton_wrapper &&inst) = delete;
	singleton_wrapper	&operator = (const singleton_wrapper &inst) = delete;
	singleton_wrapper	&operator = (singleton_wrapper &&inst) = delete;

	static singleton_wrapper	&instance() {
		static singleton_wrapper	instance;

		return instance;
	}
};

// template <typename WrappedClass>
// class DynamicSingletonWrapper final : public WrappedClass {
// private:
// 	DynamicSingletonWrapper() = default;
// public:
// 	// static std::unique_ptr<DynamicSingletonWrapper>	instance;
// 	static DynamicSingletonWrapper*	instance;
// 	template <typename ... Args>
// 	DynamicSingletonWrapper(Args ... args)
// 	: WrappedClass{std::forward<Args>(args) ...} { }
// 	~DynamicSingletonWrapper() { }

// 	DynamicSingletonWrapper(const DynamicSingletonWrapper &inst) = delete;
// 	DynamicSingletonWrapper(DynamicSingletonWrapper &&inst) = delete;
// 	DynamicSingletonWrapper	&operator = (const DynamicSingletonWrapper &inst) = delete;
// 	DynamicSingletonWrapper	&operator = (DynamicSingletonWrapper &&inst) = delete;

// 	static DynamicSingletonWrapper	&instance() {
// 		return *DynamicSingletonWrapper::instance;
// 	}

// 	template <typename ... Args>
// 	static void	init(Args... args) {
// 		static bool isInitialized = 0;
// 		if (isInitialized) {
// 			return;
// 		}
// 		// DynamicSingletonWrapper::instance = std::make_unique<DynamicSingletonWrapper>(std::forward<Args>(args) ...);
// 		DynamicSingletonWrapper::instance = new DynamicSingletonWrapper(std::forward<Args>(args) ...);
// 		isInitialized = 1;
// 	}
// };

// template<typename WrappedClass>
// DynamicSingletonWrapper<WrappedClass>* DynamicSingletonWrapper<WrappedClass>::instance = nullptr;

}

#endif // __KFS_KERNEL_INTERFACE_SINGLETON_HPP__