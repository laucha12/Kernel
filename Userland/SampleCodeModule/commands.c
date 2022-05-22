#include "include/commands.h"
#include "include/commandsEngine.h"
#include "include/lib.h"

#define INVALID_NUMBER_COMMANDS "No ingreso el numero de argumentos validos \n"

void man(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    /*if(argc != 2) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }*/  

    puts_("Todavia no tenemos soporte de man :) \n", window);
}

void help(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }

    puts_("La lista de los comandos disponibles es: \n", window);
    //commandsEngineDisplayCommands(window);
}

void diaYHora(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }
    // putInteger(getDay(), window);
    puts_(" : ", window);
    // putInteger(getHour(), window);
}

void divideByZero(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }
    // llamar a funcion en asm
}

void invalidOpCode(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }
    //llamar a funcion en asm
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
}


void infoReg(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }

    static const char *registerNames[] = {
            "RIP", "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP", "R8 ", "R9 ", "R10", "R11", "R12", "R13",
            "R14", "R15"
    };

    puts_("Los registros tienen los valores: ", window);
    // puts_(readRegs(), window);
    puts_("/n", window);
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

    //Computo los numeros fibonacci con programacion
    //dinamica

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

/*
void welcomeScreen(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]) {
    if (argc != 0) {
        puts_(INVALID_NUMBER_COMMANDS, window);
        return;
    }

    puts_("Hola! Bienvenido a GDHOS, aca hay una lista de los comandos que puedes ejecutar: \n", window);
    commandsEngineDisplayCommands(window);
    newLine(window);
    puts_("Para mas informacion de cada comando ejecutar el comando man seguido del comando en cuestion \n", window);
}*/