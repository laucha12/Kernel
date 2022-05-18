#ifndef COMMANDS_H
#define COMMANDS_H

#include "../WindowsEngine/Windows.h"
#include "../lib/lib.h"

/*
 * Recibe una ventana a la cual imprimir todos los comandos de mi consola
 */
void help(Window window);

/*
 * Recibe una ventana a la cual imprimir la fecha y hora del sistema
 */
void diaYHora(Window window);

/*
 * Recibe una ventana en la cual se producira una excepcion por division por cero
 */
void divideByZero(Window window);
// 1 / 0

/*
 * Recibe una ventana en la cual se producira una excepcion por codigo de operacion invalida
 */
void invalidOpCode(Window window);
// __asm__() o llamar a una funcion de assembler o no se

/*
 * Recibe una ventana en la cual se imprimiran los primeros 32 bytes de la 
 * memoria ram comenzando en la posicion de memoria from.
 */
int printMem(Window window, int * from);

/*
 * Recice una ventana en la cual se imprimira todos los registros y sus valores
 */
int infoReg(Window window);

/*
 * Recibe dos funciones, divide la pantalla en dos e imprime el resultado de cada 
 * funcion en cada pantalla.
 */
void pipe(void * func1, void * func2);

/*
 * Recibe una ventana, donde computara e imprimira los numeros primos ascendentemente
 * partiendo del 3.
 */
void primos(Window window);

/*
 * Recibe una ventana, donde computara e imprimira los numeros de fibonacci, 
 * partiendo del primero.
 */
void fibonacci(Window window);

/*
 * Recibe una ventana, donde imprimira los comandos disponibles para el usuario.
 */
void welcomeScreen(Window window);

#endif