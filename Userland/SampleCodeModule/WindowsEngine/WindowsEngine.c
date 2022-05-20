#include "WindowsEngine.h"
#include "Windows.h"

#define MAX_WINDOWS 3

void windowsEngineInitialize(){

    // Creo mi arreglo de ventanas, limitado a la maxima cantidad de ventanas posible
    Window windows[MAX_WINDOWS] = {MAIN_WINDOW};

    // Se inicia mi primera ventan
    windowStart(windows[0]);

}