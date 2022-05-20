/* sampleCodeModule.c */

char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;
extern void sysWriteTest(char * pointer);
extern void sysReadTest(char * pointer);
extern void sysTimeTest(char * pointer);
int main() {
	//All the following code may be removed 
	*v = 'X';
	*(v+1) = 0x74;
	
	char buffer[2] = "a";
	sysWriteTest(buffer);

	/*char date[24];
	sysTimeTest(date);	

	for(int i = 0; date[i] != 0; i++){
		sysWriteTest(date[i]);
	}

	char c[2] ;
	c[1] = 0;
	while (1)
	{		
		sysReadTest(c);
		if (c != 0)
		{
			sysWriteTest(c);
		}
		
	}
	*/


	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;
	return 0xDEADBEEF;
}