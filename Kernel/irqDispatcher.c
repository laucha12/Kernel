#include <time.h>
#include <stdint.h>
#include <keyBoard.h>
#include <naiveConsole.h>
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
