#include "include/commands.h"
#include "include/commandsEngine.h"
#include "include/lib.h"

#define INVALID_ARGUMENT_NUMBER "No ingreso el numero de argumentos validos \n"
#define INVALID_ARGUMENTS "No ingreso el tipo de argumentos validos \n"
#define TIME_BUFFER 50
#define MEM_BUFFER 120

void printUnos(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    int i = 0;
    while(1) {
        if(!(i % 100000)) puts_("1", MAIN_WINDOW);
        i++;
    }
    exit();
}

void man(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if(argc != 2) {
        puts_(INVALID_ARGUMENT_NUMBER, window);
        exit();
        return;
    }

    int found = 0;

    for(int i = 0; i < commandsCount && !found; i++) {
        if(strcmp_(argv[1], commands[i].name) == 0) {
            printCommand(window, commands[i].name, commands[i].description);
            found = 1;
        }
    }
    
    //hago un chequeo a mano porque solo tengo un comando especial,
    //sino haria otro for para los especiales
    if(strcmp_(argv[1], "pipe") == 0) {
        printCommand(window, PIPE_CMD, PIPE_DESCRIPTION);
        putsf_(PIPE_MAN, MAGENTA, window);
        found = 1;
    }

    if(!found) 
        puts_("No se encontro el comando, intente de nuevo \n", window);
    
    exit();
}

void help(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_ARGUMENT_NUMBER, window);
        exit();
        return;
    }

    puts_("La lista de los comandos disponibles es: \n", window);
    commandsEngineDisplayCommands(window);

    exit();
}

void diaYHora(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_ARGUMENT_NUMBER, window);
        exit();
        return;
    }

    char buffer[TIME_BUFFER];
    getTime(buffer);
    puts_(buffer, window);
    puts_("\n", window);
    exit();

}

void divideByZero(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_ARGUMENT_NUMBER, window);
        exit();
        return;
    }
    puts_("Intentamos dividir por cero...", window);
    divideByZeroAsm();
    puts_("Luego de la excepcion continuo con el programa \n", window);
    exit();
}

void invalidOpCode(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_ARGUMENT_NUMBER, window);
        exit();
        return;
    }
    puts_("Intentamos un invalid op code...", window);
    generateInvalidOpCode();
    puts_("Luego de la excepcion continuo con el programa \n", window);
    exit();
}

void printMem(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {

    if (argc != 2) {
        puts_(INVALID_ARGUMENT_NUMBER, window);
        exit();
        return;
    }

    //verificar es una posicion de memoria valida!

    puts_("La informacion desde la posicion de memoria ", window);
    puts_(argv[1], window);
    newLine(window);

    char buffer[MEM_BUFFER];
    readMem(buffer, (int *) atoi_((argv[1])), 32);

    for(int i = 0; i < 32; i++){
        putHex(buffer[i], window);
        puts_("|",window);

    }
    
    puts_(buffer, window);
    newLine(window);
    exit();
}

extern long * getRegs();

void infoReg(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_ARGUMENT_NUMBER, window);
        exit();
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
    exit();
}


void primos(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_ARGUMENT_NUMBER, window);
        exit();
        return;
    }

    int num = 0;

    while (1) {
        if (isPrime(num)) {
            putInteger(num, window);
            newLine(window);
        }
        num++;
    }

    exit();
}

void fibonacci(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_ARGUMENT_NUMBER, window);
        exit();
        return;
    }

    //Para el mejor manejo de overflow podriamos almacenar los numeros como strings,
    //definiendo digamos 300 digitos, y asi poder evitar cualquier tipo de overflow.
    //como manejo

    /*
    BigInt previousToLast[BIG_INT_SIZE];
    initBigInt(previousToLast);
    putBigInt(previousToLast, window);
    newLine(window);
    
    BigInt last[BIG_INT_SIZE];
    initBigInt(last);
    putBigInt(last, window);
    newLine(window);

    BigInt current[BIG_INT_SIZE];
    initBigInt(current);


    while(!bigIntOverflow(previousToLast, last)) {
        addBigIntInto(previousToLast, last, current);
        copyBigIntTo(last, previousToLast);
        copyBigIntTo(current, last);
        putBigInt(current, window);
        newLine(window);
    }

    if(bigIntOverflow(previousToLast, last)) 
        puts_("Se corta el fibonacci porque se hubiese generado un overflow", window);
    */

    long previousToLast = 0;
    putInteger(previousToLast, window);
    newLine(window);
    
    long last = 1;
    putInteger(last, window);
    newLine(window);

    long current, i = 2;

    while(!integerOverflowAddition(last, current)) {
        current = last + previousToLast;
        previousToLast = last;
        last = current;
        putInteger(current, window);
        newLine(window);
    }

    if(integerOverflowAddition(last, current)) 
        puts_("Se corta el fibonacci porque se hubiese generado un overflow \n", window);


    exit();
}

void clear(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]){
    if (!(argc == 0 || argc == 1 || argc == 2)) {
        puts_(INVALID_ARGUMENT_NUMBER, window);
        exit();
        return;
    }
    sysClearScreen(window);
    exit();
}