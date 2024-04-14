/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:27:33 by larlena           #+#    #+#             */
/*   Updated: 2024/03/27 14:29:54 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_INTERFACE_SINGLETON_HPP__
# define __KFS_KERNEL_INTERFACE_SINGLETON_HPP__

namespace kfs::interface {

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

	static SingletonWrapper	&getInstance() {
		static SingletonWrapper	instance;

		return instance;
	}
};

}

#endif // __KFS_KERNEL_INTERFACE_SINGLETON_HPP__