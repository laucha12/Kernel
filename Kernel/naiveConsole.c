#include <naiveConsole.h>

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static uint8_t * const video = (uint8_t*)0xB8000;
static uint8_t * currentVideoFD0 = (uint8_t*)0xB8000;
static uint8_t * currentVideoFD1 = (uint8_t*)0xB8000;
static uint8_t * currentVideoFD2 = (uint8_t*)0xB8000 + 82;
static int actualFd = 0;

static const uint32_t width = 80;
static const uint32_t height = 25 ;

void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}
void open(int fd){
	actualFd = fd;
}
void close(int fd){
	actualFd = (fd)? 0:1;
	ncClear();
}
void ncPrintChar(char character)
{
		printFD0Char(character);
}
	
void ncPrintFD0(char * string){
	int i;
	for ( i = 0; string[i] != 0; i++)
		printFD0Char(string[i]);
}
void printFD0Char(char character){
	if (character == '\n')
	{
		currentVideoFD0 += COLUMS - ((currentVideoFD0 - video) % COLUMS);
	}else{
		*currentVideoFD0 = character;
		 currentVideoFD0 += 2;
	}
	
	if ((currentVideoFD0 - video) >= 4000)
	{
		resetVideo();
	}
}
void ncPrintFD1(char * string){
	int i;
	for ( i = 0; string[i] != 0; i++)
		printFD1Char(string[i]);
}
void printFD1Char(char character){
	if (character == '\n')
	{
		currentVideoFD1 += OFFSET - ((currentVideoFD1 - video) % OFFSET);
	}else{
		*currentVideoFD1 = character;
		 currentVideoFD1 += 2;
	}

	if (!((currentVideoFD1-video )% OFFSET))
	{
		currentVideoFD1 += OFFSET;
	}
	
	if ((currentVideoFD1 - video) >= 3920)
	{
		resetVideo();
	}
}
void ncPrintFD2(char * string){
	int i;
	for ( i = 0; string[i] != 0; i++)
		printFD2Char(string[i]);
}
void printFD2Char(char character){
	if (character == '\n')
	{
		currentVideoFD2 += OFFSET - ((currentVideoFD2 - video) % OFFSET) ;
	}else{
		*currentVideoFD2 = character;
		 currentVideoFD2 += 2;
	}
	if (!((currentVideoFD2 - video) % OFFSET))
	{
		currentVideoFD2 += OFFSET + 2;
	}
	
	if ((currentVideoFD1 - video) >= 4000)
	{
		resetVideo();
	}
}
void resetVideo(){
	for (int i = 0; i < 3840; i++)
	{
		*(video+i) = *(video+i+COLUMS);
	}
	for (int i = 0; i < OFFSET; i++)
	{
		*(video+3840 + i*2) = ' ';
	}
	if (actualFd)
	{
		currentVideoFD1 = currentVideoFD1 - OFFSET;
		currentVideoFD2 = currentVideoFD1 - OFFSET;
	}else{
	 	currentVideoFD0 = currentVideoFD0 - COLUMS;
	}
	

}

void ncNewline(int FD)
{
	do
	{
		ncPrintChar(' ');
	}
	while((uint64_t)(currentVideoFD0 - video) % (width * 2) != 0);
}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncClear()
{
	int i;

	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	currentVideoFD0 = video;
	currentVideoFD1 = video;
	currentVideoFD2 = video + 82;
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}
