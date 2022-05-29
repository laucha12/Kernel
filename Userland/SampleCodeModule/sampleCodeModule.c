/* sampleCodeModule.c */

#include "include/WindowsEngine.h"
#include "include/commandsEngine.h"
#include "include/lib.h"

#define MAX_ARGUMENT 20
#define MAX_ARGUMENT_COUNT 20

char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;
extern void sysWriteTest(int fd,char * pointer);
extern void sysReadTest(char * pointer);
extern void sysTimeTest(char * pointer);
extern void sysOpen(int fd);
extern void sysExit(int fd);
extern void loadSO(CommandPtr func, Window window, int argc,  char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

int main() {
	//All the following code may be removed 
	*v = 'X';
	*(v+1) = 0x74;

 /*	char date[24];
	sysTimeTest(date);	
	sysWriteTest(date);

*/
	/*char c[] = "hola omo te va";
	
	sysOpen(2);
	sysWriteTest(1,c);*/

/*	while (1){		
		sysReadTest(c);
		if (c != 0) {
			sysWriteTest(1,c);
		}

	} */

	char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT];
	loadSO(windowsEngineInitialize, MAIN_WINDOW, 0, argv);


	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;
	return 0xDEADBEEF;
}