#ifndef LIB_H
#define LIB_H

#include "Windows.h"
#include <stdint.h>

#define IS_DIGIT(c)  ((c) >= '0' && (c)<='9')
#define IS_LETTER(c) (((c) >= 'a' && (c)<='z') || ((c) >= 'A' && (c)<='Z'))

#define MAX_UNSIGNED_LONG_LONG 18446744073709551615l 
#define MAX_INT 2147483647 
#define NULL_ 0L 

#define BACKSPACE '\b'
#define ENTER '\n'
#define TAB '\t'
#define SPACE ' '
#define PIPE '['

#define REGS_CANT 17

#define DOUBLE_TAB "     "

extern void printMemFrom(unsigned long * pos, Window window);

extern void sysWrite(int fd, char * buffer);
extern void sysRead(int fd, char * buffer);
extern void sysTime(char * buffer);
extern void sysOpen(int fd);
extern void sysClose(int fd);
extern void exit();
extern void sysKillProcess(int fd);
extern void sysReadMem(char * buffer, uint8_t * from, int cant);
extern void sysReloadProcess(int PID);
extern void sysClearScreen(int fd);
extern void sysWriteFormat(int fd, char * buffer, char format);
extern void sysGetRegsSnapshot(uint64_t * buffer);
/*
extern void sysRegs(char * buffer);
extern void sysMemFrom(char * buffer, int * from);*/
extern void generateInvalidOpCode();
extern void divideByZeroAsm();
extern int SysProcesses();


/*
 *  VGA text mode: codigos para formato de texto (color y fondo)
 */
/*
 *  VGA text mode: codigos para formato de texto (color y fondo)
 */
#define BLACK 0x0
#define BLUE 0x01
#define GREEN 0x02 
#define CYAN 0x03
#define RED 0x04
#define MAGENTA 0x05
#define BROWN 0x06
#define LIGHT_GRAY 0x07
#define DARK_GRAY 0x08
#define LIGHT_BLUE 0x09
#define LIGHT_GREEN 0x0a
#define LIGHT_CYAN 0x0b
#define LIGHT_RED 0x0c
#define PINK 0x0d
#define YELLOW 0x0e
#define WHITE 0x0f
#define BLACK_BACKGROUND 0x00
#define BLUE_BACKGROUND 0x10
#define GREEN_BACKGROUND 0x20 
#define CYAN_BACKGROUND 0x30
#define RED_BACKGROUND 0x40
#define MAGENTA_BACKGROUND 0x50
#define BROWN_BACKGROUND 0x60
#define LIGHT_GRAY_BACKGROUND 0x70
#define DARK_GRAY_BACKGROUND 0x80
#define LIGHT_BLUE_BACKGROUND 0x90
#define LIGHT_GREEN_BACKGROUND 0xa0
#define LIGHT_CYAN_BACKGROUND 0xb0
#define LIGHT_RED_BACKGROUND 0xc0
#define PINK_BACKGROUND 0xd0
#define YELLOW_BACKGROUND 0xe0
#define WHITE_BACKGROUND 0xf0

/*
 * Devuelve si se genera un overflow al sumar los dos enteros
 */
int integerOverflowAddition(int a, int b);

/*
 * Devuelve si se genera un overflow al sumar los dos unsigned long
 */
int longOverflowAddition(unsigned long long a, unsigned long long b);

int atoi_(char * str);

/*
 * Devuelve el tamanño de una string
 */
int strlen_(const char * s);

/*
 * Devuelve el indice donde substr es una subtring de str, -1 sino existe
 */
int substring(char *str, char *substr);

/*
 * Recibe un texto donde busca el primer indice donde aparece la string patron
 * como una substring. 
 */
int KMP(const char *text, const char *pattern, int textLen, int patternLen);

/*
 * Recibe un entero y lo imprime
 */
void putInteger(unsigned int num, Window window);

/*
 * Recibe dos strings y las compara
 */
int strcmp_(const char * str1, const char * str2);

/*
 * Recibe una string y un tamaño, devuelve verdadero
 * si la string tiene al menos el tamño size. Obs: no uso
 * un strlen ya que puedo llegar una vulnerabilidad desde
 * el punto de overflow.
 */
int isLongerThan(const char * s, int size);

/*
 * Recibe una string y devuelve el indice de la primer letra y
 * despues de la ultima letra. OJO QUE TIENE QUE PODER MODIFICAR A LA STRING
 * NO PUEDE SER UNA STRING LITERAL
 */
int removeTrailingSpaces(char * str);

/*
 * Retorna si el numero es un primo o no
 */
int isPrime(int num);

/*
 * Recibe una window a la cual hacer una nueva linea
 */
void newLine(Window window);

/*
 * Recibe una cadena de caracteres y las imprima 
 */
void puts_(char * string, Window window);

/*
 * Recibe un caracter y lo imprime 
 */
void putc_(char c, Window window);

/*
 * Recibe una cadena de caracteres, su formato y las imprima 
 */
void putsf_(char * string, char format, Window window);

/*
 * Recibe un caracter, su formato y lo imprime
 */
void putcf_(char c, char format, Window window);

void putHex(int num, Window window);

void putBin(int num, Window window);

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
void getKey(Window window, char buffer[1]);

/*
 * Retorna un string con la hora
*/
void getTime(char * buffer);

/*
 * Retorna una copia de los primeros 32 bytes desde la posicion de memoria from 
 * como un arreglo de caractres.
 */
void readMem(char * buffer, uint8_t * from, int cant);

/*
 * Retorna una copia de los valores de los registros, 
 * como un arreglo de caracteres. En el orden definido por    
 *  {"RIP", "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP",
 *  "R8 ", "R9 ", "R10", "R11", "R12", "R13", "R14", "R15"};
 */
void readRegs(long * buffer);

/*
 * Retorna un snapshot de los registros en un momento previo
 * como un arreglo de unit64.
 *  ??ORDEN??{"RIP", "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP",
 *  "R8 ", "R9 ", "R10", "R11", "R12", "R13", "R14", "R15"};
 */
void getRegsSnapshot(uint64_t * buffer);

#endif