#include "./include/naiveConsole.h"

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_ID 6
#define REGS_CANT 16

extern void killProces(int fd);

static void zero_division(long regs[],char fd);
static void invalid_opcode(long regs[],char fd);

static const char *registerNames[REGS_CANT + 1] = {
            "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP", "R8 ", "R9 ", "R10", "R11", "R12", "R13",
            "R14", "R15", "RIP"
    };

static void reportRegs(long regs[], char fd){
	ncPrintAtFD("    -Exception at -> RIP: ", fd);
	ncPrintHexAtFD(regs[REGS_CANT], fd);
	ncPrintAtFD("\n", fd);
	for(int i = 0; i < REGS_CANT; i++){
		ncPrintAtFD("    -", fd);
		ncPrintAtFD(registerNames[i], fd);
		ncPrintAtFD(": ", fd);
		ncPrintHexAtFD(regs[i], fd);
		ncPrintAtFD("\n", fd);
	}
}

void exceptionDispatcher(int exception, long regs[],char * fd) {
	(*fd)--;
	fdClear(*fd);
	switch (exception)
	{
	case ZERO_EXCEPTION_ID:
		zero_division(regs,*fd);
		break;
	
	case INVALID_OPCODE_ID:
		invalid_opcode(regs,*fd);
		break;

	default:
		break;
	}
	killProces(*fd);
	//ncPrintFD0("Falta implementar retorno al proceso/shell");
	//while(1);
}

static void zero_division(long regs[],char fd) {
	ncPrintAtFD("\n-- EXCEPTION - DIVIDE BY ZERO --n",0);
	reportRegs(regs, fd);
}

static void invalid_opcode(long regs[],char fd) {
	ncPrintAtFD("\n-- EXCEPTION - INVALID OPCODE --/n", 0);
	reportRegs(regs, fd);
}