#include "include/WindowsEngine.h"
#include "include/Windows.h"
#include "include/argumentsEngine.h"

#define MAX_WINDOWS 3

void windowsEngineInitialize(int window, int argc, char argv[MAX_ARGUMENT_COUNT][MAX_ARGUMENT]){
    // Creo mi arreglo de ventanas, limitado a la maxima cantidad de ventanas posible
    Window windows[MAX_WINDOWS] = {MAIN_WINDOW};

    // Se inicia mi primera ventan
    windowStart(windows[0]);

}