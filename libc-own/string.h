/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:09:28 by larlena           #+#    #+#             */
/*   Updated: 2024/12/23 20:45:59 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stddef.h>

void	*memset(void *b, int c, size_t len);
void	bzero(void *s, size_t n);
void	*memcpy(void *dst, const void *src, size_t n);
void	*memccpy(void *dst, const void *src, int c, size_t n);
void	*memmove(void *dst, const void *src, size_t len);
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
void	*memchr(const void *s, int c, size_t n);

#endif // STRING_H