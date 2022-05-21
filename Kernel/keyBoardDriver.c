#include <keyBoard.h>
#define MAXBUFFER 255
static char buffer [MAXBUFFER] = {0};
static unsigned int size = 0;
static unsigned int actualPos = 0;


void saveBuffer(char c){
    buffer[size] = scancodeLToAscii[c];
	size = (size == 254)? 0 : size++;
}
void getBufferChar(char * sysBuffer){
    sysBuffer[0] = buffer[actualPos];
	if(buffer[actualPos] != 0){
		buffer[actualPos] = 0;
		actualPos = (actualPos == 254)? 0 : actualPos++;
	}
}