#include <stdint.h>
#include <keyBoard.h>
#include <naiveConsole.h>
#include <lib.h>
#include <timeDriver.h>
static void int_20();
static void int_21();

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
		saveBuffer(c);
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
			getBufferChar(sysBuffer);
<<<<<<< HEAD
=======
			break;
		case 2:
			open(fd);
			break;
		case 3:
			close(fd);
>>>>>>> 46869e9facb873856a1d8eb62290303247a5ea78
			break;
		default:
			break;
		}
		
}