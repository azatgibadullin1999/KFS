/**
 * @file singleton.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef PATTERN_SINGLETON_HPP
# define PATTERN_SINGLETON_HPP

namespace pattern {

template <typename WrappedClass>
class SingletonWrapper final : public WrappedClass {
private:
	SingletonWrapper() { }
public:
	~SingletonWrapper() { }
	SingletonWrapper(const SingletonWrapper &inst) = delete;
	SingletonWrapper(SingletonWrapper &&inst) = delete;
	SingletonWrapper	&operator = (const SingletonWrapper &inst) = delete;
	SingletonWrapper	&operator = (SingletonWrapper &&inst) = delete;

	static SingletonWrapper	&instance() {
		static SingletonWrapper	instance;

		return instance;
	}
};

}

#endif // PATTERN_SINGLETON_HPP