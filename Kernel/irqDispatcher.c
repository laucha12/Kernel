#include <time.h>
#include <stdint.h>
#include <keyBoard.h>
#include <naiveConsole.h>
#define MAXBUFFER 255
static void int_20();
static void int_21();
static char buffer [MAXBUFFER];
static int size = 0;
static int actualPos = 0;

void irqDispatcher(uint64_t irq) {
		ncPrintChar('H');

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
	ncPrintChar(scancodeLToAscii[readKey()]);
	buffer[size] = scancodeLToAscii[readKey()];
	size = (size == 254)? 0 : size++;
	
}
void int_20() {
	//timer_handler();
}
void syscalls(int fd,char * sysBuffer,int count,int num){

		switch (num)
		{
		case 1:
			if (fd == 1)
			{
				ncPrint(sysBuffer);             // hay que cambiarlo

			}
			if (fd == 2)
			{
				ncPrint(sysBuffer);             // hay que cambiarlo
			}	
			break;
		case 0:
			*sysBuffer = buffer[actualPos];
			actualPos = (actualPos == 254)? 0 : actualPos++;
			break;
		default:
			break;
		}
			
		
		
}
