#include "include/WindowsEngine.h"
#include "include/Windows.h"
#include "include/argumentsEngine.h"

#define MAX_WINDOWS 3


void windowsEngineInitialize(int window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]){
  
    // Se inicia mi primera ventan
    windowStart(MAIN_WINDOW);

}

void waitProcess(){
    
    char c;

    getKey(MAIN_WINDOW, &c);

    while ( c != '\n'){
    
    if(c == '1')
        sysKillProcess(LEFT_WINDOW);
    else if(c == '2')
        sysKillProcess(RIGHT_WINDOW);;
    if (c == '3')
        sysReloadProcess(LEFT_WINDOW);
    if (c == '4')
        sysReloadProcess(RIGHT_WINDOW);
    
    
    getKey(MAIN_WINDOW, &c);
    }

    sysKillProcess(LEFT_WINDOW);
    sysKillProcess(RIGHT_WINDOW);
    sysClearScreen(LEFT_WINDOW);
    sysClearScreen(RIGHT_WINDOW);
}

void waitProcessPipe(){
    
    char c;
    //leo la key
    getKey(MAIN_WINDOW, &c);

    while ( c != '\n'){
    
    if(c == '1')
        sysKillProcess(LEFT_WINDOW);
    else if(c == '2')
        sysKillProcess(RIGHT_WINDOW);;
    if (c == '3')
        sysReloadProcess(LEFT_WINDOW);
    if (c == '4')
        sysReloadProcess(RIGHT_WINDOW);
    
    
    getKey(MAIN_WINDOW, &c);
    }
    sysKillProcess(LEFT_WINDOW);
    sysKillProcess(RIGHT_WINDOW);
    sysClearScreen(LEFT_WINDOW);
    sysClearScreen(RIGHT_WINDOW);
}



void waitProcessMain(){
    
    char c;
    //leo la key
    getKey(MAIN_WINDOW, &c);

    while ( c != '\n' && SysProcesses()){
        
        if(c == '1')
            sysKillProcess(LEFT_WINDOW);
        if (c == '3')
            sysReloadProcess(LEFT_WINDOW);
            
        getKey(MAIN_WINDOW, &c);
    }
    sysKillProcess(LEFT_WINDOW);
    //sysClearScreen(MAIN_WINDOW);
}