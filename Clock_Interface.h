#ifndef TIMER_CLOCK_CLOCK_INTERFACE_H
#define TIMER_CLOCK_CLOCK_INTERFACE_H
#include <ncurses.h>
#include <cstring>
#include "Clock.h"

class Clock_Interface{
public:

    void draw_clock(WINDOW* window, Clock& clock, int color_id);

private:
    int win_height, win_width;
};

#endif //TIMER_CLOCK_CLOCK_INTERFACE_H
