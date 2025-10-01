/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt_default.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:07:43 by larlena           #+#    #+#             */
/*   Updated: 2024/04/23 15:32:58 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gdt_default.hpp"

namespace kfs::x86 {

GDTDefault::GDTDefault() : GlobalDescriptorTable(
	Register(GDT_DEFAULT_SIZE, GDT_DEFAULT_BASE),
	Desk(),
	Desk(0x0, 0xFFFF, 0x9B, 0x0D), // kernel code
	Desk(0x0, 0xFFFF, 0x93, 0x0D), // kernel data
	Desk(0x0, 0x0,    0x97, 0x0D), // kernel stack
	Desk(0x0, 0xFFFF, 0xFF, 0x0D), // user code
	Desk(0x0, 0xFFFF, 0xF3, 0x0D), // user data
	Desk(0x0, 0x0,    0xF7, 0x0D)  // user stack
	) { }

}
