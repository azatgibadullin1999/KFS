/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:26:49 by larlena           #+#    #+#             */
/*   Updated: 2025/09/23 15:54:28 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "service/console/console.hpp"

extern "C" {

void	__kfs_putchar(char c) {
	kfs::console::instance().write(c);
}

void	__kfs_puts(const char *str) {
	kfs::console::instance().write(str);
}

}
