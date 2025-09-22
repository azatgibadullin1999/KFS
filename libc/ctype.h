/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:21:44 by larlena           #+#    #+#             */
/*   Updated: 2025/09/22 00:45:50 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBC_CTYPE_H__
# define __KFS_LIBC_CTYPE_H__

#ifdef __cplusplus
extern "C" {
#endif

int isalpha(int c);
int isdigit(int c);
int isalnum(int c);
int isascii(int c);
int isprint(int c);
int isspace(int c);
int toupper(int c);
int tolower(int c);

#ifdef __cplusplus
}
#endif

#endif // __KFS_LIBC_CTYPE_H__