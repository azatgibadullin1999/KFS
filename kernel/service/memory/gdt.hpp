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

#ifndef KFS_KERNEL_SERVICE_MEMORY_GDT_HPP
# define KFS_KERNEL_SERVICE_MEMORY_GDT_HPP

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
			_limit_low(limit & 0xFFFF),
			_base_low(base & 0xFFFF),
			_base_middle((base & 0xFF0000) >> 16),
			_access(access),
			_limit_high((limit & 0xF0000) >> 16),
			_other(other & 0xF),
			_base_high((base & 0xFF000000) >> 24) { }
	private:
		uint16_t _limit_low;
		uint16_t _base_low;
		uint8_t _base_middle;
		uint8_t _access;
		uint8_t _limit_high:4;
		uint8_t _other:4;
		uint8_t _base_high;
	};

	class [[gnu::packed]] Register {
	public:
		Register(uint16_t desks_number, uint32_t base) :
			_limit(desks_number * sizeof(Desk)),
			_base(base) { }

		void	move(Desk *desk) const  {
			std::memmove(reinterpret_cast<void *>(_base), desk, _limit);
		}

		void	load() const {
			asm volatile (
			"lgdt (%0)\n\t"
				:
				: "a" (this));
		}
	private:
		uint16_t _limit;
		uint32_t _base;
	};

public:
	template <typename ... Args>
	GlobalDescriptorTable(Register &&reg, Args&& ... args) :
	_desks{std::forward<Args>(args) ...},
	_register(std::forward<Register>(reg)) {
		_register.move(_desks.data());
		_register.load();
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
	std::array<Desk, NumberOfDesks>	_desks;
	Register	_register;
};

} // kfs::x86

#endif // KFS_KERNEL_SERVICE_MEMORY_GDT_HPP
