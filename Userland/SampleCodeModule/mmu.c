#include "include/mmu.h"

void getTime(char * buffer){
    sysTime(buffer);
}

extern void getRegs(long * buffer);

void getRegsSnapshot(uint64_t * buffer){
    sysGetRegsSnapshot(buffer);
}