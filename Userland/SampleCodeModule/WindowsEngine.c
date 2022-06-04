#include "include/WindowsEngine.h"


void windowsEngineInitialize(Window window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]){
  
    // Se inicia mi primera ventan
    windowStart(MAIN_WINDOW);

}

void windowsEngineDisplayControls(Window window) {

    //obs. se podria modalurisar con los define pero no nos dio el tiempo

     putsf_(" Sistema de ventanas:                                      \n"
            "   - Suspender ventana principal o izquierda: PRESIONAR 1  \n"
            "   - Reanudar  ventana principal o izquierda: PRESIONAR 3  \n"
            "   - Suspender ventana derecha :              PRESIONAR 2  \n"
            "   - Reanudar  vventana derecha:              PRESIONAR 4  \n"
            "   - Para matar cualquier proceso:            ENTER        "
     , MAGENTA_BACKGROUND | WHITE, window);
    
}

void waitProcess(){
    
    char c;

    getKey(MAIN_WINDOW, &c);

    while ( c != '\n') {
    
    if(c == LEFT_WINDOW_SUSPEND)
        sysKillProcess(LEFT_WINDOW);
    else if(c == RIGHT_WINDOW_SUSPEND)
        sysKillProcess(RIGHT_WINDOW);;
    if (c == RESUME_LEFT_WINDOW)
        sysReloadProcess(LEFT_WINDOW);
    if (c == RESUME_RIGHT_WINDOW)
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
    
    if(c == LEFT_WINDOW_SUSPEND)
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
        
        if(c == MAIN_WINDOW_SUSPEND)
            sysKillProcess(LEFT_WINDOW);
        if (c == '3')
            sysReloadProcess(LEFT_WINDOW);
            
        getKey(MAIN_WINDOW, &c);
    }
    sysKillProcess(LEFT_WINDOW);
    //sysClearScreen(MAIN_WINDOW);
}