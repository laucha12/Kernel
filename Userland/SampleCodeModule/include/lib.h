#ifndef LIB_H
#define LIB_H

#include "Windows.h"

#define IS_DIGIT(c)  ((c) >= '0' && (c)<='9')
#define IS_LETTER(c) (((c) >= 'a' && (c)<='z') || ((c) >= 'A' && (c)<='Z'))

#define NULL_ 0L //https://www.tutorialspoint.com/c_standard_library/c_macro_null.htm

#define BACKSPACE '\b'
#define ENTER '\n'
#define TAB '\t'
#define SPACE ' '
#define PIPE '|'

int strlen_(const char * s);

int substring(char *str, char *substr);

int KMP(const char *text, const char *pattern, int textLen, int patternLen);

/*
 * Recibe un entero y lo imprime
 */
void putInteger(int num, Window window);

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
 * Retorna un string con la hora
*/
void getTime(char * buffer);

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