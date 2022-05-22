#include "include/lib.h"
#include "include/Windows.h"


extern void sysWrite(int fd, char * buffer);
extern void sysRead(int fd, char * buffer);
extern void sysTime(char * buffer);


/*
 * Recibe una cadena de caracteres y las imprima 
 */
void puts_(char * string, Window window){
    sysWrite(window, string);
}

int strlen_(const char *str) {
    const char *s;

    for (s = str; *s; ++s);
    return (int) (s - str);
}


int KMP(const char *text, const char *pattern, int textLen, int patternLen) {
    // base case 1: pattern is NULL or empty
    if (*pattern == '\0' || patternLen == 0) return 0;

    // base case 2: text is NULL, or text's length is less than that of pattern's
    if (*text == '\0' || patternLen > textLen) return -1;

    // next[i] stores the index of the next best partial match
    int next[patternLen + 1];

    for (int i = 0; i < patternLen + 1; i++) {
        next[i] = 0;
    }

    for (int i = 1; i < patternLen; i++) {
        int j = next[i + 1];

        while (j > 0 && pattern[j] != pattern[i]) {
            j = next[j];
        }

        if (j > 0 || pattern[j] == pattern[i]) {
            next[i + 1] = j + 1;
        }
    }

    for (int i = 0, j = 0; i < textLen; i++) {
        if (*(text + i) == *(pattern + j)) {
            if (++j == patternLen) return i - j + 1;
        } else if (j > 0) {
            j = next[j];
            i--;    // since `i` will be incremented in the next iteration
        }
    }

    return -1;
}


int substring(char *str, char *substr) {
    return KMP(str, substr, strlen_(str), strlen_(substr));
}


int isLongerThan(const char *s, int size) {

    for (int i = 0; i < size; i++)
        if (s[i] == NULL_)
            return 0;

    return 1;
}

int removeTrailingSpaces(char *str) {

    //variable para recorrer toda la string
    int i = 0;

    //borro todos los caracteres (si o si mis comandos
    //comienzan con una letra)
    while (str[i] != NULL_ && !IS_LETTER(str[i])) i++;

    //almaceno el indice del primer caracter letra
    int start = i;

    //defino un indice para mantener el indice
    //del ultimo caracter que no es una letra
    int lastLetterIdx = start;

    //Voy por todos los caracteres manteniendo el indice
    //del ultimo digito o letra (recordar que puedo recibir
    //numeros como parametros)
    while (str[i++] != NULL_)
        if (IS_LETTER(str[i]) || IS_DIGIT(str[i]))
            lastLetterIdx = i;

    //como ya lei un comando entero lo seteo, defino el final de mi string
    str[lastLetterIdx + 1] = '\0';

    return start;
}


void putInteger(int num, Window window) {
    char strInverse[10], numToStr[11];
    int strLen = 0;

    for (; num > 0; num /= 10, strLen++) {
        int unit = num % 10;
        strInverse[strLen] = unit + 0x30;
    }

    for (int i = strLen; i > 0; i--) {
        numToStr[strLen - i] = strInverse[i - 1];
    }

    numToStr[strLen] = '\0';

    puts_(numToStr, window);
}

int isPrime(int num) {
    int i;

    for (i = 2; i <= num - 1; i++)
        if (num % i == 0)
            return 0;

    return i == num;
}

void newLine(Window window) {
    putc_(ENTER, window);
}

int strcmp_(const char *str1, const char *str2) {

    if (str1 == NULL_ || str2 == NULL_) return -1;//exit("Se compararon strings NULLS");

    const unsigned char *p1 = (const unsigned char *) str1;
    const unsigned char *p2 = (const unsigned char *) str2;

    while (*p1 && *p1 == *p2) ++p1, ++p2;

    return (*p1 > *p2) - (*p2 > *p1);
}

/*
 * Recibe un caracter y lo imprime 
 */
void putc_(char c, Window window){
    char character[2] = {c, 0};
    sysWrite(window, character);
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
    char buffer[2] = {0};
    sysRead(window, buffer);
    return buffer[0];
}

/*
 * Retorna un entero con la hora del sistema (syscall)
 */
int getHour(){
    return 1;
}

/*
 * Retorna un entero con los minutos del sistema (syscall)
 */
int getMinutes(){
return 1;
}

/*
 * Retorna un entero con los segundos del sistema (syscall)
 */
int getSeconds(){
return 1;
}

/*
 * Retorna un entero con el dia del sistema (syscall)
 */
int getDay(){
return 1;
}

void getTime(char * buffer){
    sysTime(buffer);
}

/*
 * Retorna una copia de los primeros 32 bytes desde la posicion de memoria from 
 * como un arreglo de caractres.
 */
char * readMem(int * from){
    return 1;
}

/*
 * Retorna una copia de los valores de los registros, 
 * como un arreglo de caracteres. En el orden definido por la tabla abajo de 
 * este archivo
 */
char * readRegs(){
    return 1;
}
