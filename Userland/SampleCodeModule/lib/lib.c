#include "lib.h"

/*
 * Recibe una cadena de caracteres y las imprima 
 */
void puts(char * string, Window window){

}

/*
 * Recibe un caracter y lo imprime 
 */
void putc(char c, Window window){

}

/*
 * Recibe una ventana a la cual borrara el ultimo caracter
 */
void deleteChar(Window window){

}

/*
 * Recibe una ventana donde leera el buffer de teclado, y en el caso de no 
 * haber nada, lo esperara, solo retorna caracteres.
char getChar(Window window);
*/

/*
 * Recibe una ventana donde leera el buffer de teclado, y en el caso de no 
 * haber nada, lo esperara.
 */
char getKey(Window window){

}

/*
 * Retorna un entero con la hora del sistema (syscall)
 */
int getHour(){

}

/*
 * Retorna un entero con los minutos del sistema (syscall)
 */
int getMinutes(){

}

/*
 * Retorna un entero con los segundos del sistema (syscall)
 */
int getSeconds(){

}

/*
 * Retorna un entero con el dia del sistema (syscall)
 */
int getDay(){

}

/*
 * Retorna una copia de los primeros 32 bytes desde la posicion de memoria from 
 * como un arreglo de caractres.
 */
char * readMem(int * from){
    
}

/*
 * Retorna una copia de los valores de los registros, 
 * como un arreglo de caracteres. En el orden definido por la tabla abajo de 
 * este archivo
 */
char * readRegs(){
    
}
