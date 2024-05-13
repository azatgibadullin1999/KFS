/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:11:34 by larlena           #+#    #+#             */
/*   Updated: 2024/05/26 22:01:58 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP__

# include <stddef.h>
# include "../boot/multiboot.h"

class Memory {
public:
	static Memory	init(multiboot_memory_map_t *addr, size_t len);
private:
};

#endif // __KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP__
