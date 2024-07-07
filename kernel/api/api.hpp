/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:30:17 by larlena           #+#    #+#             */
/*   Updated: 2024/06/19 13:51:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_API_API_HPP__
# define __KFS_KERNEL_API_API_HPP__

#include <stddef.h>

extern "C" void	putchar(char c);
extern "C" void	putstr(const char *str);
extern "C" void *allocate_pages(size_t num_of_pages);

#endif // __KFS_KERNEL_API_API_HPP__
