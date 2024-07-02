/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:54:03 by larlena           #+#    #+#             */
/*   Updated: 2024/05/04 15:03:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_ARCH_X86_GDT_HPP__
# define __KFS_KERNEL_ARCH_X86_GDT_HPP__

# include <stdint.h>
# include "utils/libft.hpp"
# include "utils/stl/move.hpp"
# include "utils/stl/array.hpp"

namespace kfs::x86 {

template <size_t NumberOfDesks>
class GlobalDescriptorTable {
protected:
	class Desk {
	public:
		Desk() { }

		Desk(uint32_t base, uint32_t limit, uint8_t access, uint8_t other) :
			mLimitLow(limit & 0xFFFF),
			mBaseLow(base & 0xFFFF),
			mBaseMiddle((base & 0xFF0000) >> 16),
			mAccess(access),
			mLimitHigh((limit & 0xF0000) >> 16),
			mOther(other & 0xF),
			mBaseHigh((base & 0xFF000000) >> 24) { }
	private:
		uint16_t mLimitLow;
		uint16_t mBaseLow;
		uint8_t mBaseMiddle;
		uint8_t mAccess;
		uint8_t mLimitHigh:4;
		uint8_t mOther:4;
		uint8_t mBaseHigh;
	} __attribute__((packed));

	class Register {
	public:
		Register(uint16_t numverOfDesks, uint32_t base) :
			mLimit(numverOfDesks * sizeof(Desk)),
			mBase(base) { }

		void	move(Desk *desk) const  {
			kfs::memmove((void *)mBase, desk, mLimit);
		}

		void	load() const {
			asm volatile (
			"lgdt (%0)\n\t"
				:
				: "a" (this));
		}
	private:
		uint16_t mLimit;
		uint32_t mBase;
	} __attribute__ ((packed));

public:
	template <typename ... Args>
	GlobalDescriptorTable(Register &&reg, Args&& ... args) :
	mRegister(ktl::forward<Register>(reg)),
	mDesks{ktl::forward<Args>(args) ...} {
		mRegister.move(mDesks.data());
		mRegister.load();
		asm(
		"movw $0x10, %ax\n\t"
		"movw %ax, %ds\n\t"
		"movw %ax, %es\n\t"
		"movw %ax, %fs\n\t"
		"movw %ax, %gs\n\t"
		"movw %ax, %ss\n\t"
		"ljmp $0x08, $next\n\t"
		"next:\n\t"
		);
	}

private:
	ktl::array<Desk, NumberOfDesks>	mDesks;
	Register	mRegister;
};

} // kfs::x86

#endif // __KFS_KERNEL_ARCH_X86_GDT_HPP__
