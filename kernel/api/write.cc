/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:26:49 by larlena           #+#    #+#             */
/*   Updated: 2025/09/22 00:34:43 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "console/console.hpp"

extern "C" {

void	__kfs_putchar(char c) {
	kfs::console::instance().write(c);
}

void	__kfs_puts(const char *str) {
	kfs::console::instance().write(str);
}

}
