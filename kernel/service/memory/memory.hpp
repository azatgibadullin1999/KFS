/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:11:34 by larlena           #+#    #+#             */
/*   Updated: 2025/09/27 16:25:40 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP__

# include <stddef.h>
# include "multiboot.h"

namespace kfs {

class Memory {
public:
	static Memory	init(multiboot_memory_map_t *addr, size_t len, multiboot_elf_section_header_table_t *elfsh);
private:
};

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP__
