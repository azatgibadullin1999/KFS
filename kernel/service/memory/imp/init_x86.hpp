/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_x86.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:19:04 by larlena           #+#    #+#             */
/*   Updated: 2024/06/16 16:53:09 by larlena          ###   ########.fr       */
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

class InitialPaging {
public:
	InitialPaging() noexcept;
};
