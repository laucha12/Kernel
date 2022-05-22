/* sampleCodeModule.c */

//#include "./WindowsEngine/Windows.h"
#include "./WindowsEngine/WindowsEngine.h"


char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;
extern void sysWriteTest(int fd,char * pointer);
extern void sysReadTest(char * pointer);
extern void sysTimeTest(char * pointer);
<<<<<<< HEAD
=======
extern void sysOpen(int fd);
extern void sysExit(int fd);

>>>>>>> 46869e9facb873856a1d8eb62290303247a5ea78
int main() {
	//All the following code may be removed 
	*v = 'X';
	*(v+1) = 0x74;

 /*	char date[24];
	sysTimeTest(date);	
	sysWriteTest(date);

<<<<<<< HEAD

	char c[2] ;
	c[1] = 0;
	while (1)
=======
*/
	char c[] = "hola omo te va";
	
	sysOpen(2);
	sysWriteTest(1,c);
	/* while (1)
>>>>>>> 46869e9facb873856a1d8eb62290303247a5ea78
	{		
		sysReadTest(c);
		if (c != 0)
		{
<<<<<<< HEAD
			sysWriteTest(c);
		}
		
	}
*/	
	windowsEngineInitialize();
=======
			sysWriteTest(1,c);
		}
		
	} */
	

	//windowsEngineInitialize();
>>>>>>> 46869e9facb873856a1d8eb62290303247a5ea78

	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;
	return 0xDEADBEEF;
}