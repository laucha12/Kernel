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
 * como un arreglo de caracteres. En el orden definido por la tabla abajo de 
 * este archivo
 */
char * readRegs();


/*

64-bit	32-bit	16-bit	8 high bits of lower 16 bits	8-bit
RAX	EAX	AX	AH	AL	Accumulator
RBX	EBX	BX	BH	BL	Base
RCX	ECX	CX	CH	CL	Counter
RDX	EDX	DX	DH	DL	Data (commonly extends the A register)
RSI	ESI	SI	N/A	SIL	Source index for string operations
RDI	EDI	DI	N/A	DIL	Destination index for string operations
RSP	ESP	SP	N/A	SPL	Stack Pointer
RBP	EBP	BP	N/A	BPL	Base Pointer (meant for stack frames)
R8	R8D	R8W	N/A	R8B	General purpose
R9	R9D	R9W	N/A	R9B	General purpose
R10	R10D	R10W	N/A	R10B	General purpose
R11	R11D	R11W	N/A	R11B	General purpose
R12	R12D	R12W	N/A	R12B	General purpose
R13	R13D	R13W	N/A	R13B	General purpose
R14	R14D	R14W	N/A	R14B	General purpose
R15	R15D	R15W	N/A	R15B	General purpose

*/

#endif