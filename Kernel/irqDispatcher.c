#include <time.h>
#include <stdint.h>
#include <keyBoard.h>
#include <naiveConsole.h>
static void int_20();
static void int_21();

char * v = (char*)0xB8000 + 79 * 2;
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
	//saveBuffer('c');
}
void int_20() {
	//timer_handler();
}
void syscalls(int fd,const char * buffer,int count,int num){

		if (num == 4)
		{
			if (fd == 1)
			{
				ncPrint(buffer);             // hay que cambiarlo

			}
			if (fd == 2)
			{
				ncPrint(buffer);             // hay que cambiarlo
			}	
		}
		
}
