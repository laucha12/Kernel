
#include "include/schedluerEngine.h"
#include <naiveConsole.h>
#include <interrupts.h>



void initialiseContextSchedluerEngine() {
    for (int i = 0; i < MAX_PROCESSES; i++) procesos[i].flagRunning = 0;
}

int toSwitch() {
    // Aca implementamos la manera mas basica de switchear los procesos 
    // en base a los timer ticks. El mismo numbero de timer ticks para
    // todos los procesos. En si aca se podria crear una tabla adicional
    // con los timer tick que cada comando deberia esperar para ser
    //switcheado
    
    ticks++;

    if(ticks == TICKS) {
        ticks = 0;
        return 1;
    }

    return 0;
}

void switchContext(long * contextHolder, char * contextOwner) {
    
    if(!toSwitch()) return;

    if(processesRunning == 0) return;
    pushContext(contextHolder, *contextOwner);
    *contextOwner = nextProcess(contextOwner);
    popContext(contextHolder, *contextOwner);
    return;
}



char  nextProcess(char * contextOwner ) {
    //Aca planteamos el algoritmo de schedluing, en si implementamos el mas simple
    //el Round Robin. La clave del while este es que siempre voy a a tener un proceso
    //corriendo, la shell (funciona como nuestro proceso idle)

    char  next =  (*contextOwner + 1) % MAX_PROCESSES;
    while(!procesos[next].flagRunning) {
        next =  (next +  1) % MAX_PROCESSES;
    }
    return next;
}

static void pushContext(long * contextHolder, char  contextOwner){
    for (int i = 0; i < 18; i++)
        procesos[(int)contextOwner].context.registers[i] = contextHolder[i];
    
}
static void popContext(long * contextHolder, char  contextOwner){
    for (int i = 0; i < 18; i++)
       contextHolder[i] = procesos[(int)contextOwner].context.registers[i];
}

int exitProces(long * contextHolder,char * contextOwner){
    procesos[(int)(*contextOwner)].flagRunning = 0;
    processesRunning -= 1;
    *contextOwner = nextProcess(contextOwner);
    popContext(contextHolder, *contextOwner);
    return processesRunning - 1;

}
int killProces(int pid){
    if(procesos[pid].flagRunning){
    procesos[pid].flagRunning = 0;
    processesRunning -= 1;
    }
    return processesRunning - 1;

}
int reloadProcess(int pid){
    if(!procesos[pid].flagRunning){
        procesos[pid].flagRunning = 1;
        processesRunning += 1;
    }
    return processesRunning - 1;
}
void loadFirstContext(long * contextHolder){
    if (processesRunning == MAX_PROCESSES) return;
    pushContext(contextHolder, processesRunning);
    procesos[processesRunning].context.registers[RSP] = (procesos[processesRunning].stackFrame + MAX_STACK -1);
    procesos[processesRunning].flagRunning = 1;
    popContext(contextHolder, processesRunning);
    processesRunning += 1;
}