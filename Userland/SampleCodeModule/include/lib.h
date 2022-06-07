#ifndef LIB_H
#define LIB_H

/**/
#include "vga.h"

/**/
#include "syscalls.h"

#include "math.h"

#include "mmu.h"

#include "stdio.h"

#include "string.h"

#define IS_DIGIT(c)  ((c) >= '0' && (c)<='9')
#define IS_LETTER(c) (((c) >= 'a' && (c)<='z') || ((c) >= 'A' && (c)<='Z'))

#define MAX_UNSIGNED_LONG_LONG 18446744073709551615l 
#define MAX_INT 2147483647 
#define NULL_ 0L 

#endif