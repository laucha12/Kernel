#ifndef WINDOWS_H
#define WINDOWS_H

enum window_ {MAIN_WINDOW = 0, LEFT_WINDOW, RIGHT_WINDOW};
typedef enum window_ Window;


void windowStart(Window windowStart);

#endif