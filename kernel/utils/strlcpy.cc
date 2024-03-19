/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfs::strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:33:36 by larlena           #+#    #+#             */
/*   Updated: 2020/11/09 16:50:09 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

size_t	kfs::strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (dstsize == 0)
		return (kfs::strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (kfs::strlen(src));
}
