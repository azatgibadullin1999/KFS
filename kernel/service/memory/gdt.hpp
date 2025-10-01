/**
 * @file gdt.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_GDT_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_GDT_HPP__

# include <array>
# include <utility>
# include <cstring>
# include <cstdint>

namespace kfs::x86 {

template <size_t NumberOfDesks>
class GlobalDescriptorTable {
protected:
	class [[gnu::packed]] Desk {
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
	};

	class [[gnu::packed]] Register {
	public:
		Register(uint16_t numverOfDesks, uint32_t base) :
			mLimit(numverOfDesks * sizeof(Desk)),
			mBase(base) { }

		void	move(Desk *desk) const  {
			std::memmove((void *)mBase, desk, mLimit);
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
	};

public:
	template <typename ... Args>
	GlobalDescriptorTable(Register &&reg, Args&& ... args) :
	mDesks{std::forward<Args>(args) ...},
	mRegister(std::forward<Register>(reg)) {
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
	std::array<Desk, NumberOfDesks>	mDesks;
	Register	mRegister;
};

} // kfs::x86

#endif // __KFS_KERNEL_SERVICE_MEMORY_GDT_HPP__
