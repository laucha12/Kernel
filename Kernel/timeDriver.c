#include <time.h>
#include <stdint.h>
#include <timeDriver.h>

int bcd_decimal(uint8_t hex)
{
	// sacar los assert!
    (((hex & 0xF0) >> 4) < 10);  // More significant nybble is valid
    ((hex & 0x0F) < 10);         // Less significant nybble is valid
    int dec = ((hex & 0xF0) >> 4) * 10 + (hex & 0x0F);
    return dec;
}     

void convert_weekday(char * buffer, int weekday){
	switch(weekday){
		case 1:
			buffer[0] = 'M';
			buffer[1] = 'O';
			buffer[2] = 'N';
			break;
		case 2:
			buffer[0] = 'T';
			buffer[1] = 'U';
			buffer[2] = 'E';
			break;
		case 3:
			buffer[0] = 'W';
			buffer[1] = 'E';
			buffer[2] = 'D';
			break;
		case 4:
			buffer[0] = 'T';
			buffer[1] = 'H';
			buffer[2] = 'R';
			break;
		case 5:
			buffer[0] = 'F';
			buffer[1] = 'R';
			buffer[2] = 'I';
			break;
		case 6:
			buffer[0] = 'S';
			buffer[1] = 'A';
			buffer[2] = 'T';
			break;
		case 7:
			buffer[0] = 'S';
			buffer[1] = 'U';
			buffer[2] = 'N';
			break;
		default:
			buffer[0] = '-';
			buffer[1] = '-';
			buffer[2] = '-';
			break;
	}
}

void time_syscall(char * buffer){
	int seconds = bcd_decimal(get_rtc_seconds());
	int minutes = bcd_decimal(get_rtc_minutes());
	int hours = bcd_decimal(get_rtc_hours());
	int weekday = bcd_decimal(get_rtc_weekday());
	int day = bcd_decimal(get_rtc_day());
	int month = bcd_decimal(get_rtc_month());
	int year = bcd_decimal(get_rtc_year());
	
	convert_weekday(buffer, weekday);
	buffer[3] = ' ';
	itoa(buffer + 4, day, 2);
	buffer[6] = '/';
	itoa(buffer + 7, month, 2);
	buffer[9] = '/';
	itoa(buffer + 10, year, 4);
	buffer[14] = ' ';
	itoa(buffer + 15, hours, 2);
	buffer[17] = ':';
	itoa(buffer + 18, minutes, 2);
	buffer[20] = ':';
	itoa(buffer + 21, seconds, 2);
	buffer[23] = '\0';

}