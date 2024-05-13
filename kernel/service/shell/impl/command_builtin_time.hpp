/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builtin_time.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 07:01:32 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 18:42:35 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_TIME_HPP__
# define __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_TIME_HPP__

# include "service/shell/interface/command_builtin.hpp"
# include "common/factory.hpp"
# include "driver/utils/port.hpp"

namespace kfs::shell {

class CommandBuiltinTime :
	public kfs::shell::interface::ICommandBuiltin,
	public kfs::interface::StaticInstanceFactory<CommandBuiltinTime> {
private:
	int get_update_in_progress_flag() {
		mCMOSAddress.write(0x0A);
		return mCMOSData.read() & 0x80;
	}

	unsigned char get_RTC_register(int reg) {
		mCMOSAddress.write(reg);
		return mCMOSData.read();
	}
public:
	ktl::string_view	getName() const {
		return "time";
	}
	ktl::string_view	getShortDescription() const {
		return "time - Command shows current time\n";
	}
	ktl::string_view	getFullDescription() const {
		return "da\n";
	}
	void		execute() {
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

		while (get_update_in_progress_flag());                // Make sure an update isn't in progress
		second = get_RTC_register(0x00);
		minute = get_RTC_register(0x02);
		hour = get_RTC_register(0x04);
		day = get_RTC_register(0x07);
		month = get_RTC_register(0x08);
		year = get_RTC_register(0x09);
		if(century_register != 0) {
			century = get_RTC_register(century_register);
		}

		do {
			last_second = second;
			last_minute = minute;
			last_hour = hour;
			last_day = day;
			last_month = month;
			last_year = year;
			last_century = century;	
			while (get_update_in_progress_flag());           // Make sure an update isn't in progress
			second = get_RTC_register(0x00);
			minute = get_RTC_register(0x02);
			hour = get_RTC_register(0x04);
			day = get_RTC_register(0x07);
			month = get_RTC_register(0x08);
			year = get_RTC_register(0x09);
			if(century_register != 0) {
				century = get_RTC_register(century_register);
			}
		} while ((last_second != second) || (last_minute != minute) || (last_hour != hour) ||
			 (last_day != day) || (last_month != month) || (last_year != year) ||
			 (last_century != century));

		registerB = get_RTC_register(0x0B);

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
			year += (CURRENT_YEAR / 100) * 100;
			if(year < CURRENT_YEAR) year += 100;
		}
		printf("%d/%d/%d %d:%d:%d\n", day, month, year, hour, minute, second);
	}
private:
	inline static const size_t	CURRENT_YEAR = 2024;
	kfs::driver::utils::PortByte	mCMOSAddress = 0x70;
	kfs::driver::utils::PortByte	mCMOSData = 0x71;
};

}

#endif // __KFS_KERNEL_SERVICE_SHELL_IMPL_COMMAND_BUILTIN_TIME_HPP__
