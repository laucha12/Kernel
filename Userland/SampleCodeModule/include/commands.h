#ifndef COMMANDS_H
#define COMMANDS_H

#include "argumentsEngine.h"

/*
 * La idea de mi definicion de comandos es que funcionen similar a como el SO maneja la shell, lee todos
 * lo entrado como input despues de su nombre al comando! De esa manera podemos manejar todos los tipos de
 * argumentos de la forma COMANDO ARG1, ARG2, ... ARGN
 *
 * */

/*
 * Recibe un comando como unico argumento e imprime informacion sobre sus parametros
 * opcionales entre otros, analogo al comando man de linux.
 */

#define MAN_DESCRIPTION "Es"

void man(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana a la cual imprimir todos los comandos de mi consola
 */
#define HELP_DESCRIPTION "Es"

void help(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana a la cual imprimir la fecha y hora del sistema
 */
#define DIA_Y_HORA_DESCRIPTION "This commands displays the d"

void diaYHora(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana en la cual se producira una excepcion por division por cero
 */
#define DIVIDE_BY_ZERO_DESCRIPTION ""

void divideByZero(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana en la cual se producira una excepcion por codigo de operacion invalida
 */
#define INVALID_OPCODE_DESCRIPTION ""

void invalidOpCode(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana en la cual se imprimiran los primeros 32 bytes de la 
 * memoria ram comenzando en la posicion de memoria from.
 */
#define PRINT_MEM_DESCRIPTION ""

void printMem(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recice una ventana en la cual se imprimira todos los registros y sus valores
 */
#define INFO_REG_DESCRIPTION ""

void infoReg(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana, donde computara e imprimira los numeros primos ascendentemente
 * partiendo del 3.
 */
#define PRIMOS_DESCRIPTION ""

void primos(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana, donde computara e imprimira los numeros de fibonacci, 
 * partiendo del primero.
 */
#define FIBONACCI_DESCRIPTION ""

void fibonacci(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana, donde imprimira los comandos disponibles para el usuario.
 */
//#define WELCOME_SCREEN_DESCRIPTION ""

//void welcomeScreen(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

#endif