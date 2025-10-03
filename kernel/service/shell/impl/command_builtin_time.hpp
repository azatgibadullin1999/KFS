/**
 * @file command_builtin_time.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_TIME_HPP
# define KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_TIME_HPP

# include <common/factory.hpp>
# include <driver/utils/port.hpp>
# include <service/shell/interface/command_builtin.hpp>

namespace kfs::shell {

class CommandBuiltinTime :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinTime> {
private:
	int _get_update_in_progress_flag() {
		_CMOS_address.write(0x0A);
		return _CMOS_data.read() & 0x80;
	}

	unsigned char _get_RTC_register(int reg) {
		_CMOS_address.write(reg);
		return _CMOS_data.read();
	}
public:
	std::string_view	get_name() const {
		return "time";
	}
	std::string_view	get_short_description() const {
		return "shows current time";
	}
	std::string_view	get_full_description() const {
		return "da";
	}
	void		execute() {
	// NOLINTBEGIN
		int century_register = 0x00;   
		static unsigned char second;
		static unsigned char minute;
		static unsigned char hour;
		static unsigned char day;
		static unsigned char month;
		static unsigned int year;
		unsigned char century;
		unsigned char last_second;
		unsigned char last_minute;
		unsigned char last_hour;
		unsigned char last_day;
		unsigned char last_month;
		unsigned char last_year;
		unsigned char last_century;
		unsigned char registerB;

		// Note: This uses the "read registers until you get the same values twice in a row" technique
		//       to avoid getting dodgy/inconsistent values due to RTC updates

		while (_get_update_in_progress_flag()) { };                // Make sure an update isn't in progress
		second = _get_RTC_register(0x00);
		minute = _get_RTC_register(0x02);
		hour = _get_RTC_register(0x04);
		day = _get_RTC_register(0x07);
		month = _get_RTC_register(0x08);
		year = _get_RTC_register(0x09);
		if(century_register != 0) {
			century = _get_RTC_register(century_register);
		}

		do {
			last_second = second;
			last_minute = minute;
			last_hour = hour;
			last_day = day;
			last_month = month;
			last_year = year;
			last_century = century;	
			while (_get_update_in_progress_flag());           // Make sure an update isn't in progress
			second = _get_RTC_register(0x00);
			minute = _get_RTC_register(0x02);
			hour = _get_RTC_register(0x04);
			day = _get_RTC_register(0x07);
			month = _get_RTC_register(0x08);
			year = _get_RTC_register(0x09);
			if(century_register != 0) {
				century = _get_RTC_register(century_register);
			}
		} while ((last_second != second) || (last_minute != minute) || (last_hour != hour) ||
			 (last_day != day) || (last_month != month) || (last_year != year) ||
			 (last_century != century));

		registerB = _get_RTC_register(0x0B);

		// Convert BCD to binary values if necessary
 
		if (!(registerB & 0x04)) {
			second = (second & 0x0F) + ((second / 16) * 10);
			minute = (minute & 0x0F) + ((minute / 16) * 10);
			hour = ( (hour & 0x0F) + (((hour & 0x70) / 16) * 10) ) | (hour & 0x80);
			day = (day & 0x0F) + ((day / 16) * 10);
			month = (month & 0x0F) + ((month / 16) * 10);
			year = (year & 0x0F) + ((year / 16) * 10);
			if(century_register != 0) {
				century = (century & 0x0F) + ((century / 16) * 10);
			}
		}

		// Convert 12 hour clock to 24 hour clock if necessary

		if (!(registerB & 0x02) && (hour & 0x80)) {
			hour = ((hour & 0x7F) + 12) % 24;
		}

		// Calculate the full (4-digit) year

		if(century_register != 0) {
			year += century * 100;
		} else {
			year += (g_current_year / 100) * 100;
			if(year < g_current_year) year += 100;
		}
		std::printf("%d/%d/%d %d:%d:%d\n", day, month, year, hour, minute, second);
	// NOLINTEND
	}
private:
	inline static const size_t	g_current_year = 2024;
	kfs::driver::utils::PortByte	_CMOS_address = 0x70;
	kfs::driver::utils::PortByte	_CMOS_data = 0x71;
};

}

#endif // KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_TIME_HPP
