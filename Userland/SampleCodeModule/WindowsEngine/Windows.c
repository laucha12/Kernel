#include "Windows.h"
#include "../CommandsEngine/commands.h"
#include "../CommandsEngine/commandsEngine.h"

void listen(char * command, Window window){
    
    int count = 0;
    int c;

    printShellLegend(window);

    while((c = getKey(window)) != '\n' && count <  MAX_COMMAND_SIZE){
        if(c == '\b'){
            command[count++] = c;
            putc(c, window);
        }
    }
}


void windowStart(Window window){
    char command[MAX_COMMAND_SIZE];
    welcomeScreen(window);

    while(1){
        listen(command, window);
        commandsEngineHandle(command, window);
    }
}