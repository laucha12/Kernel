#ifndef WINDOWS_ENGINE_H
#define WINDOWS_ENGINE_H

#define MAX_ARGUMENT 20
#define MAX_ARGUMENT_COUNT 20

/*
 * Inicializa el arreglo de windows, con una window del tipo shell
 */
void windowsEngineInitialize(int window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]);

#endif