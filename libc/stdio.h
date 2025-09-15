/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:52:03 by larlena           #+#    #+#             */
/*   Updated: 2025/09/14 00:48:12 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIO_H
# define STDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#define EOF -1

int	printf(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif // STDIO_H
