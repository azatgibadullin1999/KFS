/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:26:49 by larlena           #+#    #+#             */
/*   Updated: 2025/09/13 17:57:10 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "console/console.hpp"

extern "C" {

void	putchar(char c) {
	kfs::console::instance().write(c);
}

void	putstr(const char *str) {
	kfs::console::instance().write(str);
}

}
