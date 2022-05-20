#include <time.h>
#include <stdint.h>
#include <keyBoard.h>
#include <naiveConsole.h>
#include <lib.h>

#define MAXBUFFER 255

static void int_20();
static void int_21();

static char buffer [MAXBUFFER] = {0};
static unsigned int size = 0;
static unsigned int actualPos = 0;

void irqDispatcher(uint64_t irq) {

	switch (irq) {
		case 0:
			int_20();
			break;
		case 1:
			int_21();
			break;
	}
	return;
}

void int_21(){
	char c = readKey();
	if (c > 0)
	{
		buffer[size] = scancodeLToAscii[c];
		size = (size == 254)? 0 : size++;
	}
}

void int_20() {
	//timer_handler();
}

void syscalls(int fd,char * sysBuffer,int count,int num){

		switch (num)
		{
		
		case 120:
			time_syscall(sysBuffer);
			break;

		case 1:
			if (fd == 0)
			{
				ncPrintFD0(sysBuffer);             // hay que cambiarlo a la del 

			}
			if (fd == 1)
			{
				ncPrintFD1(sysBuffer);
			}
			if (fd == 2)
			{
				ncPrintFD2(sysBuffer);
			}
				
			break;
		case 0:
			sysBuffer[0] = buffer[actualPos];
			if(buffer[actualPos] != 0){
				buffer[actualPos] = 0;
				actualPos = (actualPos == 254)? 0 : actualPos++;
			}
			break;
		default:
			break;
		}
		
}

// Funciones de libasm.asm
extern int get_rtc_seconds();
extern int get_rtc_minutes();
extern int get_rtc_hours();
extern int get_rtc_weekday();
extern int get_rtc_day();
extern int  get_rtc_month();
extern int get_rtc_year();

int bcd_decimal(uint8_t hex)
{
	// sacar los assert!
    assert(((hex & 0xF0) >> 4) < 10);  // More significant nybble is valid
    assert((hex & 0x0F) < 10);         // Less significant nybble is valid
    int dec = ((hex & 0xF0) >> 4) * 10 + (hex & 0x0F);
    return dec;
}     

void convert_weekday(char * buffer, int weekday){
	switch(weekday){
		case 1:
			buffer = "MON";
			break;
		case 2:
			buffer = "TUE";
			break;
		case 3:
			buffer = "WED";
			break;
		case 4:
			buffer = "THR";
			break;
		case 5:
			buffer = "FRI";
			break;
		case 6:
			buffer = "SAT";
			break;
		case 7:
			buffer = "SUN";
			break;
		default:
			buffer = "---";
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

