/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfs::atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:57:58 by larlena           #+#    #+#             */
/*   Updated: 2024/03/06 12:45:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

int		kfs::atoi(const char *str)
{
	size_t		i;
	int		sign;
	long long	dst;

	dst = 0;
	i = 0;
	sign = 1;
	while (kfs::isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (kfs::isdigit(str[i]))
	{
		dst = dst * 10 + str[i] - '0';
		i++;
	}
	return (dst * sign);
}
