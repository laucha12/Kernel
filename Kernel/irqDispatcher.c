#include <stdint.h>
#include <keyBoard.h>
#include <naiveConsole.h>
#include <lib.h>
#include <timeDriver.h>
static void int_20();
static void int_21();

void irqDispatcher(uint64_t irq)
{

	switch (irq)
	{
	case 0:
		// Se llama a la funcion que debera ejecutar
	   //  la interrupcion que se guardo en la posicion 20 del IDT
		int_20();
		break;
	case 1:
		// Se llama a la funcion que debera ejecutar
	   //  la interrupcion que se guardo en la posicion 21 del IDT
		int_21();
		break;
	}
	return;
}

void int_21()
{
	// Llamamos al driver del teclado para que guarde en su buffer
	// la tecla leida desde la interrupcion del mismo
	char c = readKey();
	saveBuffer(c);
	
}

void int_20()
{
	// timer_handler();
}

//Esta funcion lo que hace es recibir el llamado de cualquier 
// syscall
void syscalls(int fd, char *sysBuffer, int count, int num)
{
	switch (num)
	{

	case 120:
		// Si es la syscall 120 se hira al driver de la hora para que le copie
		// en el buffer que formato de dicha hora
		time_syscall(sysBuffer);
		break;

	case 1:
		// Si es la syscall de teclado debemos preguntar para que FD se quiero escribir
		// pues depende eso donde en la pantalla escribimos para cada uno de los casos
		// llamamos al driver de pantalla para que escriba en dicho lugar
		if (fd == 0)
		{
			
			ncPrintFD0(sysBuffer); 
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
		// si se llama a la syscall 0 esta misma es la syscall de read la cual
		// le guardara en el sysBuffer el caracter que hay en el buffer de teclado
		getBufferChar(sysBuffer);
		break;
	case 2:
		// Syscall para abrir un fd
		open(fd);
		break;
	case 3:
		// syscall para cerrar un fd
		close(fd);
		break;
	default:
		break;
	}
}