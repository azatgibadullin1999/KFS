/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.cc                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:09:38 by larlena           #+#    #+#             */
/*   Updated: 2024/05/13 15:43:05 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

static int	ft_parser(const char *format, t_printf *all);
static void	ft_printf_putchar(const char c, t_printf *all);

int	kfs::printf(const char *format, ...) {
	t_printf	all;

	all.i = 0;
	all.str_size = 0;
	va_start(all.ap, format);
	for (all.i = 0, all.str_size = 0; format[all.i]; ++all.i) {
		if (format[all.i] == '%') {
			++all.i;
			ft_parser(format, &all);
		}
		else {
			ft_printf_putchar(format[all.i], &all);
		}
	}
	va_end(all.ap);
	return (all.str_size);
}

static void	ft_str_toupper(char *dst) {
	for (size_t i = 0; dst[i]; ++i) {
		dst[i] = kfs::toupper(dst[i]);
		i++;
	}
}

static void	ft_printf_putstr(const char *str, t_printf *all) {
	size_t	size = kfs::strlen(str);

	all->str_size += size;
	putstr(str);
}

static void	ft_printf_putchar(const char c, t_printf *all) {
	all->str_size += 1;
	putchar(c);
}

static int 	ft_char_types_output(int c, t_printf *all) {
	ft_printf_putchar(c, all);
	return (0);
}

static int	ft_hex_types_output(unsigned int n, int reg, t_printf *all) {
	ft_printf_putstr("0x", all);
	char	buff[sizeof(n) * 8];

	kfs::itoa(n, buff, 16);
	for (int it = (int)all->width.num - kfs::strlen(buff); it > 0; --it) {
		ft_printf_putchar('0', all);
	}
	if (reg) {
		ft_str_toupper(buff);
	}
	ft_printf_putstr(buff, all);
	return (0);
}

static int	ft_percent_output(t_printf *all) {
	ft_printf_putchar('%', all);
	return (0);
}


static int	ft_int_types_output(int n, t_printf *all) {
	char	buff[sizeof(n) + 2];

	kfs::itoa(n, buff, 10);
	for (int it = (int)all->width.num - kfs::strlen(buff); it > 0; --it) {
		ft_printf_putchar('0', all);
	}
	ft_printf_putstr(buff, all);
	return (0);
}

static int	ft_pointer_types_output(void *p, t_printf *all) {
	char	buff[sizeof(p) + 3];

	kfs::itoa((size_t)p, buff, 16);
	for (int it = (int)all->width.num - (int)kfs::strlen(buff); it > 0; --it) {
		ft_printf_putchar('0', all);
	}
	ft_printf_putstr(buff, all);
	return (0);
}

static const char	*ft_check_null(char *str) {
	static const char	null_string[] = "(null)";

	if (!str) {
		return null_string;
	}
	return str;
}

static int	ft_str_types_output(char *str, t_printf *all) {
	ft_printf_putstr(ft_check_null(str), all);
	return 0;
}

static int	ft_unsigned_types_output(unsigned int n, t_printf *all) {
	char	buff[sizeof(n) + 1];

	kfs::itoa(n, buff, 10);
	for (int it = (int)all->width.num - kfs::strlen(buff); it > 0; --it) {
		ft_printf_putchar('0', all);
	}
	ft_printf_putstr(buff, all);
	return (0);
}

static void	ft_parse_width(const char *format, t_printf *all) {
	all->width.num = kfs::atoi(&format[all->i]);
	for (;kfs::isdigit(format[all->i]); ++all->i) { }
}

static void	ft_clean_struct(t_printf *all) {
	all->width.num = 0;
}

static int		ft_parser(const char *format, t_printf *all) {
	ft_clean_struct(all);
	if (kfs::isdigit(format[all->i]))
		ft_parse_width(format, all);
	if (format[all->i] == 'c')
		return (ft_char_types_output(va_arg(all->ap, int), all));
	else if (format[all->i] == 's')
		return (ft_str_types_output(va_arg(all->ap, char *), all));
	else if (format[all->i] == 'p')
		return (ft_pointer_types_output(va_arg(all->ap, void *), all));
	else if (format[all->i] == 'd')
		return (ft_int_types_output(va_arg(all->ap, int), all));
	else if (format[all->i] == 'i')
		return (ft_int_types_output(va_arg(all->ap, int), all));
	else if (format[all->i] == 'u')
		return (ft_unsigned_types_output(va_arg(all->ap, unsigned int), all));
	else if (format[all->i] == 'x')
		return (ft_hex_types_output(va_arg(all->ap, unsigned int), 0, all));
	else if (format[all->i] == 'X')
		return (ft_hex_types_output(va_arg(all->ap, unsigned int), 1, all));
	else if (format[all->i] == '%')
		return (ft_percent_output(all));
	return (1);
}
