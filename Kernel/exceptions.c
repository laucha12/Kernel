#include "./include/naiveConsole.h"

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_ID 6
#define REGS_CANT 16

static void zero_division(long regs[],char fd);
static void invalid_opcode(long regs[],char fd);

static const char *registerNames[REGS_CANT + 1] = {
            "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP", "R8 ", "R9 ", "R10", "R11", "R12", "R13",
            "R14", "R15", "RIP"
    };

void exceptionDispatcher(int exception, long regs[],char * fd) {

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
	ncPrintFD0("Falta implementar retorno al proceso/shell");
	while(1);
}

static void zero_division(long regs[],char fd) {
	ncPrintFD0("\n---------------------------EXCEPTION - DIVIDE BY ZERO---------------------------\n");
	ncPrintFD0("    -Exception at -> RIP: ");
	ncPrintHex(regs[REGS_CANT]);
	ncPrintFD0("\n");
	for(int i = 0; i < REGS_CANT; i++){
		ncPrintFD0("    -");
		ncPrintFD0(registerNames[i]);
		ncPrintFD0(": ");
		ncPrintHex(regs[i]);
		ncPrintFD0("\n");
	}
	ncPrintFD0("--------------------------------------------------------------------------------\n");
}

static void invalid_opcode(long regs[],char fd) {
	ncPrintFD0("\n---------------------------EXCEPTION - INVALID OPCODE---------------------------\n");
	ncPrintFD0("    -Exception at -> RIP: ");
	ncPrintHex(regs[REGS_CANT]);
	ncPrintFD0("\n");
	for(int i = 0; i < REGS_CANT; i++){
		ncPrintFD0("    -");
		ncPrintFD0(registerNames[i]);
		ncPrintFD0(": ");
		ncPrintHex(regs[i]);
		ncPrintFD0("\n");
	}
	ncPrintFD0("--------------------------------------------------------------------------------\n");
}