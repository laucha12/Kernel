
#ifndef COMMANDSENGINE_ARGUMENTSENGINE_H
#define COMMANDSENGINE_ARGUMENTSENGINE_H

#include "lib.h"

#define MAX_ARGUMENT 20
#define MAX_ARGUMENT_COUNT 20

#define ARGUMENT_LENGTH_EXCEEDED_MSG ""
#define ARGUMENT_COUNT_EXCEEDED_MSG ""

/*
 * Recibe una string con los argumentos recibos al haber llamado el comando
 * asi como una array de strings a la cual copiar los argumentos. Devuelve
 * el numero de argumentos que se leyeron a args.
 * */

int argumentsEngineHandle(Window window, char *arguments, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

#endif
