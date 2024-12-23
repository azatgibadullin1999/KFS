/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:30:17 by larlena           #+#    #+#             */
/*   Updated: 2024/12/23 20:15:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_API_API_HPP__
# define __KFS_KERNEL_API_API_HPP__

# include <stddef.h>

void	putchar(char c);
void	putstr(const char *str);
void	*allocate_pages(size_t num_of_pages);

#endif // __KFS_KERNEL_API_API_HPP__
