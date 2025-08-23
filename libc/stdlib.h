/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:58:13 by larlena           #+#    #+#             */
/*   Updated: 2024/07/06 16:44:41 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDLIB_H
# define STDLIB_H

# include <stddef.h>

extern "C" void	*malloc(size_t);
extern "C" void	free(void *);

#endif // STDLIB_H