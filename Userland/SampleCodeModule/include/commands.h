#ifndef COMMANDS_H
#define COMMANDS_H

#include "argumentsEngine.h"

/*
 * La idea de mi definicion de comandos es que funcionen similar a como el SO maneja la shell, lee todos
 * lo entrado como input despues de su nombre al comando! De esa manera podemos manejar todos los tipos de
 * argumentos de la forma COMANDO ARG1, ARG2, ... ARGN
 *
 * */

void printUnos(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe un comando como unico argumento e imprime informacion sobre sus parametros
 * opcionales entre otros, analogo al comando man de linux.
 */

#define MAN_DESCRIPTION "Recibe un comando y imprime su documentacion"

void man(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana a la cual imprimir todos los comandos de mi consola
 */
#define HELP_DESCRIPTION "Recibe una ventana a la cual imprimir todos los comandos"

void help(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana a la cual imprimir la fecha y hora del sistema
 */
#define DIA_Y_HORA_DESCRIPTION "Imprime la fecha y hora del sistema"

void diaYHora(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana en la cual se producira una excepcion por division por cero
 */
#define DIVIDE_BY_ZERO_DESCRIPTION "Hace una division por cero"

void divideByZero(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana en la cual se producira una excepcion por codigo de operacion invalida
 */
#define INVALID_OPCODE_DESCRIPTION "Hace una operacion de codigo invalido "

void invalidOpCode(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana en la cual se imprimiran los primeros 32 bytes de la 
 * memoria ram comenzando en la posicion de memoria from.
 */
#define PRINT_MEM_DESCRIPTION "Recibe una posicion de memoria de donde imprimir 32 bytes"

void printMem(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recice una ventana en la cual se imprimira todos los registros y sus valores
 */
#define INFO_REG_DESCRIPTION "Imprime todos los registros y sus valores"

void infoReg(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana, donde computara e imprimira los numeros primos ascendentemente
 * partiendo del 3.
 */
#define PRIMOS_DESCRIPTION "Imprime numeros primos"

void primos(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana, donde computara e imprimira los numeros de fibonacci, 
 * partiendo del primero.
 */
#define FIBONACCI_DESCRIPTION "Imprime numeros fibonacci"

void fibonacci(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

/*
 * Recibe una ventana, donde computara e imprimira los numeros de fibonacci, 
 * partiendo del primero.
 */
#define CLEAR_DESCRIPTION "Limpia la pantalla"

void clear(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

#endif