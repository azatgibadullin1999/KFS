/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:26:49 by larlena           #+#    #+#             */
/*   Updated: 2024/04/17 14:29:36 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "console.hpp"

extern "C" void	putchar(char c) {
	kfs::ConsoleSingleton::getInstance().write(c);
}

extern "C" void	putstr(const char *str) {
	kfs::ConsoleSingleton::getInstance().write(str);
}
