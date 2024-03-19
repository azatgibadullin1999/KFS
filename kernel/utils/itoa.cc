/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfs::itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:15:42 by larlena           #+#    #+#             */
/*   Updated: 2024/03/10 10:50:40 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

static const char*	alpha = "0123456789abcdefghijklmnopqrstuvw";

static char	*itoa_recursive(long long value, char *str, int base) {
	if (value >= base) {
		str = itoa_recursive(value / base, str, base);
	}
	*str = *(value % base + alpha);
	return ++str;
}

char	*kfs::itoa(long long value, char *str, int base) {
	if (value < 0 && base == 10) {
		str[0] = '-';
		value *= -1;
		*itoa_recursive(value, str + 1, base) = '\0';
	} else  {
		*itoa_recursive(value, str, base) = '\0';
	}
	return (str);
}
