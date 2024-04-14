/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:08:01 by larlena           #+#    #+#             */
/*   Updated: 2024/03/23 21:23:05 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_INTERFACE_MEDIATOR_HPP__
# define __KFS_KERNEL_INTERFACE_MEDIATOR_HPP__

# include <stdint.h>

namespace kfs::interface {

class IMediator {
public:
	virtual	void	notify(BaseComponent*, uint8_t event) = 0;
};

class BaseComponent {
public:
	virtual void	setMediator(IMediator* mediator) {
		if (!mediator)
			mMeidator = mediator;
	}

	virtual void	unsetMediator() {
		mMediator = nullptr;
	}
private:
	IMediator	*mMediaotr;
};


} // kfs::interface

#endif // __KFS_KERNEL_INTERFACE_MEDIATOR_HPP__