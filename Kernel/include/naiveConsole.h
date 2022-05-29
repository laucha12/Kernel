#ifndef NAIVE_CONSOLE_H
#define NAIVE_CONSOLE_H

#include <stdint.h>
#define COLUMS 160
#define OFFSET 80

/*
 *  VGA text mode: codigos para formato de texto (color y fondo)
 */
#define BLACK 0x0
#define BLUE 0x1
#define GREEN 0x2 
#define CYAN 0x3
#define RED 0x4
#define MAGENTA 0x5
#define BROWN 0x6
#define LIGHT_GRAY 0x7
#define DARK_GRAY 0x8
#define LIGHT_BLUE 0x9
#define LIGHT_GREEN 0xa
#define LIGHT_CYAN 0xb
#define LIGHT_RED 0xc
#define PINK 0xd
#define YELLOW 0xe
#define WHITE 0xf


/*
    Funcion la cual imprime en el FD0 lo que hay en String
    debe estar pues la usa al inicializar el kernel

    Params: const char * string lo que se va a imprimir 
    Retunr: void
*/
void ncPrint(const char * string);
/*
    Funcion la cual va a imprimir un caracter a la vez en FD0

    Params: char caracter
    Return: void
*/
void ncPrintChar(char character);
/*
    Funcion la cual te genera una nueva linea en el FD0

    Params: void
    Return: void
*/
void ncNewline();
/*
    Funcion la cual te imprime un numero decimal

    Params: int value
    Return: void
*/
void ncPrintDec(uint64_t value);
/*
    Funcion la cual te imprime un numero hexa

    Params: int value
    Return: void
*/
void ncPrintHex(uint64_t value);
/*
    Funcion la cual te imprime un numero binario

    Params: int value
    Return: void
*/
void ncPrintBin(uint64_t value);
/*
    Funcion la cual te imprime un numero en cualquier base

    Params: int value, int base
    Return: void
*/
void ncPrintBase(uint64_t value, uint32_t base);
/*
    Funcion la cual borra todo el contenido de la pantalla

    Params: void
    Return: void
*/
void ncClear();

/*
    Funcion la cual borra todo el contenido de la pantalla 
    en un fd determinado.
    
    Params: void
    Return: void
*/
void fdClear(int fd);

/*
    Funcion la cual resetea los FD y limpia la pantalla

    Params: void
    Return: void
*/
void resetVideo();
/*
    Funcion la cual imprime en el FD0 lo que haya en String

    Params: char *
    Return: void
*/

// ---------------------------------------------------
// FD0
// ---------------------------------------------------
void ncPrintFD0(char * string);
/*
    Funcion la cual imprime un char en el FD0

    Params: char *
    Return: void
*/

void ncPrintFD0_Format(char *string, char format);

void ncPrintFD0Char(char character);
/*
    Funcion la cual imprime un char en el FD1

    Params: char *
    Return: void
*/
void ncPrintFD0Char_Format(char character, char format);

// ---------------------------------------------------
// FD1
// ---------------------------------------------------
void ncPrintFD1Char(char character);
/*
    Funcion la cual imprime en el FD1 lo que haya en String

    Params: char *
    Return: void
*/

void ncPrintFD1_Format(char *string, char format);

void ncPrintFD1Char_Format(char character, char format);

void ncPrintFD1(char * string);
/*
    Funcion la cual imprime en el FD2 lo que haya en String

    Params: char *
    Return: void
*/

// ---------------------------------------------------
// FD2
// ---------------------------------------------------
void ncPrintFD2(char * string);
/*
    Funcion la cual imprime en el FD2 lo que haya en String

    Params: char *
    Return: void
*/

void ncPrintFD2_Format(char *string, char format);

void ncPrintFD2Char_Format(char character, char format);

void ncPrintFD2Char(char character);
/* 
    Funcion la cual se fija si es un enter y genera el \n

    Params: char c, int FD
    Return: void
*/

// ---------------------------------------------------
// 
// ---------------------------------------------------
int checkEnter(char c, int FD);
/*
    Funcion la cual hace la sysCall de open

    Params: int Fd
    Return: void
*/
void open(int fd);
/*
    Funcion la cual hace la sysCall de exit

    Params: int Fd
    Return: void
*/
void close(int fd);

#endif