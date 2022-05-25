#include "include/commands.h"
#include "include/commandsEngine.h"
#include "include/lib.h"


#define INVALID_NUMBER_COMMANDS "No ingreso el numero de argumentos validos \n"
#define INVALID_ARGUMENTS "No ingreso el tipo de argumentos validos \n, haga $> man "
#define TIME_BUFFER 50
#define MEM_BUFFER 120



void man(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if(argc != 2) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }
/*
    if(!isLetterString(argv[1])) {
        puts_(INVALID_ARGUMENTS "man", window);
        return;
    }
*/
    puts_("Todavia no tenemos soporte de man :) \n", window);
}

void help(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }

    puts_("La lista de los comandos disponibles es: \n", window);
    commandsEngineDisplayCommands(window);
}

void diaYHora(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }

    char buffer[TIME_BUFFER];
    getTime(buffer);
    puts_(buffer, window);
    puts_("\n", window);
}

void divideByZero(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }
    /*int a = 5 / 0;
    puts_("Continua el programa despues de la excepcion", window);*/
    divideByZeroAsm();
    puts_("Luego de la excepcion continuo con el programa \n", window);
}

void invalidOpCode(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }
    //generateInvalidOpCode();
}

void printMem(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 2) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }

    //verificar es una posicion de memoria valida!

    puts_("La informacion desde la posicion de memoria ", window);
    puts_(argv[1], window);
    newLine(window);

    char buffer[MEM_BUFFER];
    //readMem(buffer, (int *) atoi_((argv[1])));
    
    puts_(buffer, window);
}

extern long * getRegs();

void infoReg(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }

    static const char *registerNames[REGS_CANT] = {
            "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP", "R8 ", "R9 ", "R10", "R11", "R12", "R13",
            "R14", "R15", "RIP"
    };

    puts_("Los registros tienen los valores: \n", window);

    long * buffer = getRegs();

    for(int i = 0; i < REGS_CANT; i++){
        puts_("    -", window);
        puts_(registerNames[i], window);
        puts_(": ", window);
        putHex(buffer[i], window);
        puts_("h\n", window);
    }
    
    puts_("\n", window);
}


void primos(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }

    int num = 0;

    while (1)
        if (isPrime(num))
            putInteger(num, window);
}

void fibonacci(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }

    //Computo los numeros fibonacci con programacion dinamica

    int previousLast = 0, last = 1, current;

    putInteger(previousLast, window);
    newLine(window);

    putInteger(last, window);
    newLine(window);

    while (1) {
        current = last + previousLast;
        previousLast = last;
        last = current;
        putInteger(current, window);
        newLine(window);
    }
}