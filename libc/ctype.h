/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:21:44 by larlena           #+#    #+#             */
/*   Updated: 2025/09/13 17:50:54 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTYPE_H
# define CTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

int	isalpha(int c);
int	isdigit(int c);
int	isalnum(int c);
int	isascii(int c);
int	isprint(int c);
int	isspace(int c);
int	toupper(int c);
int	tolower(int c);

#ifdef __cplusplus
}
#endif

#endif // CTYPE_H