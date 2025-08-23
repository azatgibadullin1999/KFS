/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_x86.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:19:04 by larlena           #+#    #+#             */
/*   Updated: 2025/04/04 14:52:31 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "arch/x86/paging.hpp"

namespace kfs::x86::page::initial {

std::pair<page::Directory::Pair, page::Table::Pair>	init_paging() noexcept;

}
