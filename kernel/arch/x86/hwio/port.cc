/**
 * @file port.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "port.hpp"

namespace kfs::hwio::detail {

void port_write_byte(uint16_t address, uint8_t value) {
	asm volatile (
	"outb %0, %1\n\t"
		:
		: "a" (value), "Nd" (address));
}
uint8_t port_read_byte(uint16_t address) {
	uint8_t ret;
	asm volatile (
	"inb %1, %0\n\t"
		: "=a" (ret)
		: "Nd" (address));
	return ret;
}
void port_write_word(uint16_t address, uint16_t value) {
	asm volatile (
	"outw %0, %1\n\t"
		:
		: "a" (value), "Nd" (address));
}
uint16_t port_read_word(uint16_t address) {
	uint16_t ret;
	asm volatile (
	"inw %1, %0\n\t"
		: "=a" (ret)
		: "Nd" (address));
	return ret;
}
void port_write_double_word(uint16_t address, uint32_t value) {
	asm volatile (
	"outdw %0, %1\n\t"
		:
		: "a" (value), "Nd" (address));
}
uint32_t port_read_double_word(uint16_t address) {
	uint32_t ret;
	asm volatile (
	"indw %1, %0\n\t"
		: "=a" (ret)
		: "Nd" (address));
	return ret;
}

}
