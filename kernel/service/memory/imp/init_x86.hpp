/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_x86.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:19:04 by larlena           #+#    #+#             */
/*   Updated: 2024/07/08 23:03:43 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "arch/x86/gdt_default.hpp"
# include "arch/x86/paging.hpp"

class InitialPageTable : public kfs::x86::PageTableEntry {
public:
	InitialPageTable() noexcept;
};


class InitialPageDirectory : public kfs::x86::PageDirectoryEntry {
public:
	InitialPageDirectory() noexcept;
};

std::pair<kfs::x86::PageDirectoryPointer, kfs::x86::PageTablePointer>	initPaging() noexcept;
