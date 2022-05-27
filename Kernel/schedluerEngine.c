
#include "include/schedluerEngine.h"
#include <naiveConsole.h>
#include <interrupts.h>

void switchContext(long * contextHolder, long * contextOwner) {
    pushContext(contextHolder, contextOwner);
    *contextOwner = nextProcess(contextOwner);
    popContext(contextHolder, contextOwner);
    return;
}

long  nextProcess(long * contextOwner ) {
    //Aca planteamos el algoritmo de schedluing, en si implementamos el mas simple
    //el Round Robin. La clave del while este es que siempre voy a a tener un proceso
    //corriendo, la shell (funciona como nuestro proceso idle)

    long  next =  (*contextOwner + 1) % processesRunning;
    while(!procesos[next].flagRunning) next =  ((*contextOwner) + 1) % processesRunning;
    return next;
}

static void pushContext(long * contextHolder, long  contextOwner){
    for (int i = 0; i < 17; i++)
        procesos[(int)contextOwner].context.registers[i] = contextHolder[i];
    
}
static void popContext(long * contextHolder, long  contextOwner){
    for (int i = 0; i < 17; i++)
       contextHolder[i] = procesos[(int)contextOwner].context.registers[i];
}

void exitProces(long * contextHolder,long * contextOwner){
    procesos[(int)(*contextOwner)].flagRunning = 0;
    processesRunning -= 1;
    switchContext(contextHolder,contextOwner);
    ncPrintFD0("se exiteo un proceso \n");
}

void loadProces(long * contextHolder){
    if (processesRunning == MAX_PROCESSES) return;
    pushContext(contextHolder, processesRunning);
    procesos[processesRunning].context.registers[RSP] = procesos[processesRunning].stackFrame;
    popContext(contextHolder,0) ;
    if(processesRunning == SHELL) {
     } 
}
