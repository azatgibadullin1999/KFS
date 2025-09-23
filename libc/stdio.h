/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:52:03 by larlena           #+#    #+#             */
/*   Updated: 2025/09/23 15:31:40 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBC_STDIO_H__
# define __KFS_LIBC_STDIO_H__

# ifdef __cplusplus
extern "C" {
# endif

#define EOF -1

int printf(const char *format, ...);
int putchar(char ch);
int puts(const char *ch);

# ifdef __cplusplus
}
# endif

#endif // __KFS_LIBC_STDIO_H__
