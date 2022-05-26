#include <keyBoard.h>
#include <naiveConsole.h>
#include <stdint.h>
#define MAXBUFFER 255
static char buffer[]  = "HOLA";
static unsigned int size = 0;
static unsigned int actualPos = 0;
static uint8_t *keyMap[] = {scancodeLToAscii, scancodeUToAscii};
#define LEFT_SHIFT 0x2A
#define RIGHT_SHIFT 0x36
static char keyMapRow = 0;

void saveBuffer(char code)
{
	ncPrintFD0("ACA");
	if (code < 0x80 && code > 0)
	{ // Key pressed
		if (code == LEFT_SHIFT || code == RIGHT_SHIFT)
		{
			keyMapRow |= 0x01;
		}
		else if (keyMap[keyMapRow][code] != 0)
		{
			buffer[size] = keyMap[keyMapRow][code];
			size = (size == 254) ? 0 : size++;
		}
	}
	else
	{  
		 // Key released
		code -= 0x80;
		if (code == LEFT_SHIFT || code == RIGHT_SHIFT)
		{
			keyMapRow = 0;
		}
	}
}
void getBufferChar(char *sysBuffer)
{

	sysBuffer[0] = buffer[actualPos];
	if (buffer[actualPos] != 0)
	{
		buffer[actualPos] = 0;
		actualPos = (actualPos == 254) ? 0 : (actualPos+1);
	}
}