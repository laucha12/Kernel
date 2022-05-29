#ifndef NAIVE_CONSOLE_H
#define NAIVE_CONSOLE_H

#include <stdint.h>
#define COLUMS 160
#define OFFSET 80
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
void ncPrintFD0(char * string);
/*
    Funcion la cual imprime un char en el FD0

    Params: char *
    Return: void
*/
void printFD0Char(char character);
/*
    Funcion la cual imprime un char en el FD1

    Params: char *
    Return: void
*/
void printFD1Char(char character);
/*
    Funcion la cual imprime en el FD1 lo que haya en String

    Params: char *
    Return: void
*/
void ncPrintFD1(char * string);
/*
    Funcion la cual imprime en el FD2 lo que haya en String

    Params: char *
    Return: void
*/
void ncPrintFD2(char * string);
/*
    Funcion la cual imprime en el FD2 lo que haya en String

    Params: char *
    Return: void
*/
void printFD2Char(char character);
/* 
    Funcion la cual se fija si es un enter y genera el \n

    Params: char c, int FD
    Return: void
*/
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