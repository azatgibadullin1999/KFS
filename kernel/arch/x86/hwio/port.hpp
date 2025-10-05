/**
 * @file port.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_DRIVER_UTILS_PORT_HPP
# define KFS_KERNEL_DRIVER_UTILS_PORT_HPP

# include <cstdint>

namespace kfs::hwio {

namespace detail {
void port_write_byte(uint16_t address, uint8_t value);
uint8_t port_read_byte(uint16_t address);
void port_write_word(uint16_t address, uint16_t value);
uint16_t port_read_word(uint16_t address);
void port_write_double_word(uint16_t address, uint32_t value);
uint32_t port_read_double_word(uint16_t address);
}

template <uint16_t Address, typename Type>
struct Port {
	using value_type = Type;
	void write(value_type value);
	value_type read() const;
};

template <uint16_t Address>
struct Port<Address, uint8_t> {
	using value_type = uint8_t;
	void write(value_type value) {
		detail::port_write_byte(Address, value);
	}
	value_type read() const {
		return detail::port_read_byte(Address);
	}
};

template <uint16_t Address>
struct Port<Address, uint16_t> {
	using value_type = uint16_t;
	void write(value_type value) {
		detail::port_write_word(Address, value);
	}
	value_type read() const {
		return detail::port_read_word(Address);
	}
};

template <uint16_t Address>
struct Port<Address, uint32_t> {
	using value_type = uint16_t;
	void write(value_type value) {
		detail::port_write_double_word(Address, value);
	}
	value_type read() const {
		return detail::port_read_double_word(Address);
	}
};

}

#endif // KFS_KERNEL_DRIVER_UTILS_PORT_HPP
