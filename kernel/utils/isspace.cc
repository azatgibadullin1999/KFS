/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfs::isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:41:31 by larlena           #+#    #+#             */
/*   Updated: 2024/03/06 12:44:13 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

int	kfs::isspace(int c) {
	return (c == '\t' || c == '\v' || c == ' ' ||
		c == '\n' || c == '\r' || c == '\f');
}