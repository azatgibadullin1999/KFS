/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:40:48 by larlena           #+#    #+#             */
/*   Updated: 2025/04/15 13:52:28 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_FT_LIBC_H__
# define MALLOC_FT_LIBC_H__

#include <stddef.h>

void *malloc(size_t size);
void free(void *ptr);

#endif	// MALLOC_FT_LIBC_H__
