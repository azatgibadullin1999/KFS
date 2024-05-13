/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:00:20 by larlena           #+#    #+#             */
/*   Updated: 2024/05/04 15:03:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_SHELL_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_SHELL_HPP__

# include "interface/shell.hpp"
# include "utils/stl/array.hpp"

namespace kfs {

class Shell : public kfs::interface::IShell {
public:
	typedef ktl::array<char, 32>		Container;
	typedef ktl::array<Container::iterator, 8> ContainerOfArgs;
	using IShell::IShell;

	void	process() override;
private:
	inline static const char	enter = '\n';
	Container	mInputStringBuff;
	ContainerOfArgs	mArgs;
	const char	mPromptForInput[6] = "L&D> ";
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_SHELL_HPP__
