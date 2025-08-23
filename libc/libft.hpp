/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:01:45 by larlena           #+#    #+#             */
/*   Updated: 2024/12/23 20:23:39 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// # include <stdarg.h>
// # include <stddef.h>
// # include <api.hpp>

extern "C" int	printf(const char *format, ...);
extern "C" void	*memset(void *b, int c, size_t len);
extern "C" void	bzero(void *s, size_t n);
extern "C" void	*memcpy(void *dst, const void *src, size_t n);
extern "C" void	*memccpy(void *dst, const void *src, int c, size_t n);
extern "C" void	*memmove(void *dst, const void *src, size_t len);
extern "C" int	memcmp(const void *s1, const void *s2, size_t n);
extern "C" size_t	strlen(const char *s);
extern "C" size_t	strlcpy(char *dst, const char *src, size_t dstsize);
extern "C" size_t	strlcat(char *dst, const char *src, size_t dstsize);
extern "C" char	*strchr(const char *s, int c);
extern "C" char	*strrchr(const char *s, int c);
extern "C" char	*strnstr(const char *str1, const char *str2, size_t len);
extern "C" int	strncmp(const char *str1, const char *str2, size_t n);
extern "C" char	*itoa(long long value, char *str, int base);
extern "C" int	atoi(const char *str);
extern "C" int	isalpha(int c);
extern "C" int	isdigit(int c);
extern "C" int	isalnum(int c);
extern "C" int	isascii(int c);
extern "C" int	isprint(int c);
extern "C" int	isspace(int c);
extern "C" int	toupper(int c);
extern "C" int	tolower(int c);
extern "C" void	*memchr(const void *s, int c, size_t n);

#endif
