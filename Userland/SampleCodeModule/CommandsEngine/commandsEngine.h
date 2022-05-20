#ifndef COMMANDS_ENGINE_H
#define COMMANDS_ENGINE_H

/*

La idea de este engine es poder manejar el mapeo de una input del usuario a la lista de comandos 
definidas por el SO.

Primero chequeamos el formato de lo ingresado como comando es valido. Luego manejamos el caso especial
donde nuestro comando es el pipe (que toma parametros), y por ultimo llamamos al comando run que va a 
encargarse de buscar el comando en la tabla de comandos disponibles y llamar a la funcion, imprimiendo
el resultado a su ventana correspondiente (esto ultima a traves del window engine)

*/

/*
 * Recibe un string como un supuesto comando y la mapea a la funcion correspondiente, 
 * que se correra en la ventana recibida como parametro.
 */
void commandsEngineHandle(char * command, Window window);

/*
 * Recibe un comando formato valido y una ventana a imprimirlo
 */
static void commandsEngineRun(char * command, Window window);


/*
 * Recibe un comando pipe de formato valido y una ventana a imprimirlo
 */
static void commandsEngineRunPipe(char * command, Window window);


/*
 * Recibe una string y verifica que no contiene caracteres excepto del alfabeto, 
 * el simbolo PIPE, asi como espacios y tabs. Define lo que es un comando con
 * un formato valido
 */
static int isValidCommand(char * command);

/*
 * Recibe un comando de formato valido y devuelve si es o no el comando pipe
 */
static int isPipeCommand(char * command);

#endif