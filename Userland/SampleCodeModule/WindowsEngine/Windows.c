#include "Windows.h"
#include "../CommandsEngine/commands.h"
#include "../CommandsEngine/commandsEngine.h"

void listen(char * command, Window window){
    // Contador de caracteres ingresados por el usuario
    int count = 0;
    // Caracter ingresado por vez
    int c;

    //IMPORANTE CLEAR BUFFER TODO

    // Se imprime la leyenda que indica el usuario y el dispositivo
    printShellLegend(window);

    //Por cada letra, la guardo en el string command y valido que no sea enter, si no, termine con mi comando
    while((c = getKey(window)) != '\n' && count <  MAX_COMMAND_SIZE){
        
        // Si es backspace, borramos la letra
        if(c == '\b'){
            deleteChar(window);
        }else{ // En caso contrario, se agrega la letra al comando y se la imprime en pantalla
            command[count++] = c;
            putc(c, window);
        }
    }
}


void windowStart(Window window){
    //Se imprime un mensaje de bienvenida al iniciar la ventana
    welcomeScreen(window);

    // Arreglo de caracteres donde tendre mi comando
    char command[MAX_COMMAND_SIZE];


    while(1){
        //Se escucha lo que el usuario escriba hasta el enter
        listen(command, window);
        //Se pasa el comando, y este decidira que hacer con tal comando, si es que es valido.
        commandsEngineHandle(command, window);
    }
}