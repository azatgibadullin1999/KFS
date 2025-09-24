/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:20:16 by larlena           #+#    #+#             */
/*   Updated: 2025/09/24 19:03:18 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace kfs {

namespace detail {
void panic();
}

struct PanicHandler {
	PanicHandler();
};

} // namespace kfs
