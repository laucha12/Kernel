#include <time.h>
#include <stdint.h>
#include <timeDriver.h>

int bcd_decimal(uint8_t hex)
{
	// sacar los assert!
	(((hex & 0xF0) >> 4) < 10); // More significant nybble is valid
	((hex & 0x0F) < 10);		// Less significant nybble is valid
	int dec = ((hex & 0xF0) >> 4) * 10 + (hex & 0x0F);
	return dec;
}


void time_syscall(char *buffer)
{
	int seconds = bcd_decimal(get_rtc_seconds());
	int minutes = bcd_decimal(get_rtc_minutes());
	int hours = bcd_decimal(get_rtc_hours());
	int weekday = bcd_decimal(get_rtc_weekday());
	int day = bcd_decimal(get_rtc_day());
	int month = bcd_decimal(get_rtc_month());
	int year = bcd_decimal(get_rtc_year());


	itoa(buffer, day, 2);
	buffer[2] = '/';
	itoa(buffer + 3, month, 2);
	buffer[5] = '/';
	itoa(buffer + 6, year, 2);
	buffer[8] = ' ';
	itoa(buffer + 9, hours, 2);
	buffer[11] = ':';
	itoa(buffer + 12, minutes, 2);
	buffer[14] = ':';
	itoa(buffer + 15, seconds, 2);
	buffer[17] = ' ';
	buffer[18] = 'U';
	buffer[19] = 'T';
	buffer[20] = 'C';		
	buffer[21] = '\0';		
}