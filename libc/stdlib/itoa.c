/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:15:42 by larlena           #+#    #+#             */
/*   Updated: 2024/03/10 10:50:40 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char*	alpha = "0123456789abcdefghijklmnopqrstuvw";

static char *itoa_recursive(long long value, char *it, int base) {
	if (value >= base) {
		it = itoa_recursive(value / base, it, base);
	}
	*it = alpha[value % base];
	return ++it;
}

char *itoa(long long value, char *str, int base) {
	char *local = str;
	if (value < 0 && base == 10) {
		*local = '-';
		++local;
		value *= -1;
	}
	*itoa_recursive(value, local, base) = '\0';
	return (str);
}

static char *uitoa_recursive(unsigned long long value, char *it, unsigned int base) {
	if (value >= base) {
		it = uitoa_recursive(value / base, it, base);
	}
	*it = alpha[value % base];
	return ++it;
}

char *uitoa(unsigned long long value, char *str, unsigned int base) {
	*uitoa_recursive(value, str, base) = '\0';
	return (str);
}
