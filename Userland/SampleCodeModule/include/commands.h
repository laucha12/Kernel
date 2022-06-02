#ifndef COMMANDS_H
#define COMMANDS_H

#include "argumentsEngine.h"

/*
 * La idea de mi definicion de comandos es que funcionen similar a como el SO maneja la shell, lee todos
 * lo entrado como input despues de su nombre al comando! De esa manera podemos manejar todos los tipos de
 * argumentos de la forma COMANDO ARG1, ARG2, ... ARGN
 *
 * */

#define PIPE_CMD "CMD1 | CMD2 "
#define PIPE_DESCRIPTION "Corre CMD1 a la izquierda y CMD2 a la derecha de la screen. " 
#define PIPE_MORE_INFO   DOUBLE_TAB "Para saber mas utilizar el comando man pipe" 

#define PIPE_MAN DOUBLE_TAB "Una vez divida la pantalla para suspender la pantallas o reanudar: \n" \
                 DOUBLE_TAB DOUBLE_TAB "Suspender pantalla izquierda: presionar 1 \n" \
                 DOUBLE_TAB DOUBLE_TAB "Suspender pantalla derecha: presionar 2 \n" \
                 DOUBLE_TAB DOUBLE_TAB "Reanudar pantalla izquierda: presionar 3 \n" \
                 DOUBLE_TAB DOUBLE_TAB "Reanudar pantalla derecha: presionar 4 \n" \
                 DOUBLE_TAB DOUBLE_TAB "Terminar el pipe: presionar enter \n"





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