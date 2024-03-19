/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:01:45 by larlena           #+#    #+#             */
/*   Updated: 2024/04/17 14:44:41 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include "api.hpp"

typedef struct	s_printf {
	va_list		ap;
	size_t		i;
	size_t		str_size;
}			t_printf;

namespace kfs {

int	printf(const char *format, ...);
void	*memset(void *b, int c, size_t len);
void	bzero(void *s, size_t n);
void	*memcpy(void *dst, const void *src, size_t n);
void	*memccpy(void *dst, const void *src, int c, size_t n);
void	*memmove(void *dst, const void *src, size_t len);
void	*memchr(const void *s, int c, size_t n);
int	memcmp(const void *s1, const void *s2, size_t n);
size_t	strlen(const char *s);
size_t	strlcpy(char *dst, const char *src, size_t dstsize);
size_t	strlcat(char *dst, const char *src, size_t dstsize);
char	*strchr(const char *s, int c);
char	*strrchr(const char *s, int c);
char	*strnstr(const char *str1, const char *str2, size_t len);
int	strncmp(const char *str1, const char *str2, size_t n);
char	*itoa(long long value, char *str, int base);
int	atoi(const char *str);
int	isalpha(int c);
int	isdigit(int c);
int	isalnum(int c);
int	isascii(int c);
int	isprint(int c);
int	isspace(int c);
int	toupper(int c);
int	tolower(int c);

}

#endif
