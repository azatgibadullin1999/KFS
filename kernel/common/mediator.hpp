/**
 * @file mediator.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

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
			mMediator = mediator;
	}

	virtual void	unsetMediator() {
		mMediator = nullptr;
	}
private:
	IMediator	*mMediator;
};


} // kfs::interface

#endif // __KFS_KERNEL_INTERFACE_MEDIATOR_HPP__