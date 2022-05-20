#include "../WindowsEngine/Windows.h"
#include "../WindowsEngine/WindowsEngine.h"
#include "../lib/lib.h"

void commandsEngineHandle(char * command, Window window){

    //chequeo default de NULL
    if(command == NULL || window == NULL) return;

    //chequeo es un comando valido
    if(!isValidCommand(command)) puts("Invalid command, please try again", window);

    //chequeo si es comando especial de pipe
    else if(isPipeCommand(command)) commandsEngineRunPipe(command, window);

    //le digo al engine de comandos que lo corra en la window
    else    commandsEngineRun(command, window);
}


static void commandsEngineRunPipe(char * command, Window window) {

}

static void commandsEngineRun(char * command, Window window);


static int isPipeCommand(char * command) {

    //La definicion de pipe command es "ABC | XYZ" donde
    //ABC, XYZ son comandos validos.

    if(command == NULL) return 0;

    int i = 0;

    //busco el indice dentro de la string del pipe
    while(command[i] != PIPE  && command[i] != NULL) i++;

    if(command[i] != NULL) 
        return isValidCommandTo(command, 0) && isValidCommandFrom(command, i + 1);

    return 0;
}

static int isValidCommand(char * command) {

    //chequeo default de NULL (se podria incluir
    //en ultimo return como "return command != NULL")
    if(command == NULL) return 0;

    for(int i = 0; command[i] != NULL; i++)
        if(command[i] != PIPE && command[i] != SPACE && command[i] != TAB && !IS_LETTER(command[i]))
            return 0;
    
    return 1;
}