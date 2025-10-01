/**
 * @file factory.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_COMMON_COMMAND_HPP__
# define __KFS_KERNEL_COMMON_COMMAND_HPP__

namespace kfs::interface {

template <typename T>
class IFactory {
public:
	typedef T			value_type;
	typedef value_type&		reference;
	typedef const value_type&	const_reference;
	typedef value_type*		pointer;
	typedef const value_type*	const_pointer;

	virtual pointer	create() = 0;
};

template <typename T>
class StaticInstanceFactory {
public:
	typedef T			value_type;
	typedef value_type&		reference;
	typedef const value_type&	const_reference;
	typedef value_type*		pointer;
	typedef const value_type*	const_pointer;

	static pointer	create() {
		static value_type instance;

		return &instance;
	}
};

}

#endif // __KFS_KERNEL_COMMON_COMMAND_HPP__
