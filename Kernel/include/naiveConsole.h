#ifndef NAIVE_CONSOLE_H
#define NAIVE_CONSOLE_H

#include <stdint.h>
#define COLUMS 160
#define OFFSET 80
// hacer bien los comments
void ncPrint(const char * string);
void ncPrintChar(char character);
void ncNewline();
void ncPrintDec(uint64_t value);
void ncPrintHex(uint64_t value);
void ncPrintBin(uint64_t value);
void ncPrintBase(uint64_t value, uint32_t base);
void ncClear();

void resetVideo();
void ncPrintFD0(char * string);
void printFD0Char(char character);
void printFD1Char(char character);
void ncPrintFD1(char * string);
void ncPrintFD2(char * string);
void printFD2Char(char character);
int checkEnter(char c, int FD);

void open(int fd);
void close(int fd);

#endif