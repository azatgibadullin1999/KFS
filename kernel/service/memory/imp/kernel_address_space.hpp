/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_address_space.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:19:04 by larlena           #+#    #+#             */
/*   Updated: 2025/09/27 23:23:35 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <multiboot.h>

#include <service/memory/paging.hpp>
#include <service/memory/address_space.hpp>

namespace kfs {

struct KernelAddressSpace : public AddressSpace {
	KernelAddressSpace();
};

}
