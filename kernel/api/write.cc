/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:26:49 by larlena           #+#    #+#             */
/*   Updated: 2025/03/27 20:45:53 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "service/console/console.hpp"

extern "C" void	putchar(char c) {
	kfs::console::instance().write(c);
}

extern "C" void	putstr(const char *str) {
	kfs::console::instance().write(str);
}
