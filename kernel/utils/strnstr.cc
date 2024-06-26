/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfs::strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:47:55 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 16:53:04 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

char	*kfs::strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str1[i] && i <= len)
	{
		j = 0;
		while (i < len && str1[i] && str2[j] && (str1[i] == str2[j]))
		{
			i++;
			j++;
		}
		if (str2[j] == '\0')
			return ((char *)&str1[i - j]);
		i = i - j;
		i++;
	}
	return (NULL);
}
