#ifndef COMMANDS_ENGINE_H
#define COMMANDS_ENGINE_H


/*
 * Recibe un string con el comando y la mapea a la funcion correspondiente, 
 * que se correra en la ventana recibida como parametros.
 */
void commandsEngineHandle(char * command, Window window);

#endif