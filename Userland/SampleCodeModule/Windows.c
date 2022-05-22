#include "include/Windows.h"
#include "include/lib.h"
#include "include/commandsEngine.h"


void welcomeScreen(Window window){
    puts_("---------------------------------- GDH OS --------------------------------------\n", window);
    char buffer[27];
    getTime(buffer);
    puts_(buffer, window);
    puts_("\n", window);
    puts_("Presione entener para comenzar\n", window);
    puts_("---------------------------------- GDH OS --------------------------------------\n", window);
    char c = -1;
    while((c = getKey(window)) != '\n'){
    
    }
}


void listen(char * command, Window window){
    // Contador de caracteres ingresados por el usuario
    int count = 0;
    // Caracter ingresado por vez
    int c;

    //IMPORANTE CLEAR BUFFER TODO
    //clearKeyboardBuffer();?

    // Se imprime la leyenda que indica el usuario y el dispositivo
    puts_(SHELL_LEGEND, window);

    //Por cada letra, la guardo en el string command y valido que no sea enter, si no, termine con mi comando
    while((c = getKey(window)) != '\n' && count <  MAX_COMMAND_SIZE){
        
        // Si es backspace, borramos la letra
        if(c == '\b'){
            deleteChar(window);
        }else if(c != 0){ // En caso contrario, se agrega la letra al comando y se la imprime en pantalla
            command[count++] = c;
            putc_(c, window);
        }
    }
    command[count++] = 0;
    // El enter ingresado:
    putc_('\n', window);
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
