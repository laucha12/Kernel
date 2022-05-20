#ifndef LIB_H
#define LIB_H

#include "../WindowsEngine/Windows.h"

#define IS_NUM(c)  ((c) >= '0' && (c)<='9')
#define IS_DIGIT(c) (((c) >= 'a' && (c)<='z') || ((c) >= 'A' && (c)<='Z'))

#define NULL 0L //https://www.tutorialspoint.com/c_standard_library/c_macro_null.htm

#define BACKSPACE '\b'
#define ENTER '\n'
#define TAB '   '
#define SPACE ' '
#define PIPE '|'

/*
 * Recibe una cadena de caracteres y las imprima 
 */
void puts(char * string, Window window);

/*
 * Recibe un caracter y lo imprime 
 */
void putc(char c, Window window);

/*
 * Recibe una ventana a la cual borrara el ultimo caracter
 */
void deleteChar(Window window);

/*
 * Recibe una ventana donde leera el buffer de teclado, y en el caso de no 
 * haber nada, lo esperara, solo retorna caracteres.
char getChar(Window window);
*/

/*
 * Recibe una ventana donde leera el buffer de teclado, y en el caso de no 
 * haber nada, lo esperara.
 */
char getKey(Window window);

/*
 * Retorna un entero con la hora del sistema (syscall)
 */
int getHour();

/*
 * Retorna un entero con los minutos del sistema (syscall)
 */
int getMinutes();

/*
 * Retorna un entero con los segundos del sistema (syscall)
 */
int getSeconds();

/*
 * Retorna un entero con el dia del sistema (syscall)
 */
int getDay();

/*
 * Retorna una copia de los primeros 32 bytes desde la posicion de memoria from 
 * como un arreglo de caractres.
 */
char * readMem(int * from);

/*
 * Retorna una copia de los valores de los registros, 
 * como un arreglo de caracteres. En el orden definido por    
 *  {"RIP", "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP",
 *  "R8 ", "R9 ", "R10", "R11", "R12", "R13", "R14", "R15"};
 */
char * readRegs();



#endif