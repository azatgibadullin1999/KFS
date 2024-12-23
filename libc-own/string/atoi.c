/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:57:58 by larlena           #+#    #+#             */
/*   Updated: 2024/03/06 12:45:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		atoi(const char *str)
{
	size_t		it = 0;
	int		sign = 1;
	long long	dst = 0;

	while (isspace(str[it]))
		it++;
	if (str[it] == '-' || str[it] == '+') {
		if (str[it] == '-')
			sign = -1;
		it++;
	}
	while (isdigit(str[it])) {
		dst = dst * 10 + str[it] - '0';
		it++;
	}
	return (dst * sign);
}
