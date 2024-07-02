/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:13:10 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 22:30:36 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
