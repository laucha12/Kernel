
#ifndef KEYBOARD_H_
#define KEYBOARD_H_
/* 
    Funcion la cual recibe un caracter gracias a una interrupcion de teclado
    y lo guarda en el buffer

    Argumentos: char c 
    Return: void
*/
void saveBuffer(char c);
/* 
    Funcion la cual lee desde la memoria de teclado la tecla
    que fue apretada

    Argumentos:
    Return: la tecla que fue apretada en hexa
*/
extern char readKey();
/*
    Tabla la cual segun el valor que se ingresa devuelve el 
    valor en ascii
*/
static char scancodeLToAscii[] = {

      0,   27, '1', '2', '3', '4', '5', '6', '7', '8', '9',  '0', '-', '=',
   '\b', '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',  '[', ']',
   '\n',    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
      0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',    0, '*',
      0,  ' ',   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,   0,
      0,    0,   0,   0, '-',   0,   0,   0, '+',   0,   0,   0,    0,   0,
      0,    0,   0,   0,   0,   0

};
#endif