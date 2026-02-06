#ifndef TIMER_CLOCK_CLOCK_INTERFACE_H
#define TIMER_CLOCK_CLOCK_INTERFACE_H
#include <ncurses.h>
#include <cstring>
#include <memory>
#include "Clock.h"
#include "Timer.h"
#include "Button.h"

class Clock_Interface{
public:
    Clock_Interface();

    void draw_clock(WINDOW* window, Clock& clock, int color_id);

    void draw_timer(WINDOW *window, Timer& timer, int color_id);
private:
    int win_height, win_width;

    std::unique_ptr<Button> start_stop_button;
    std::unique_ptr<Button> reset_button;
};

#endif //TIMER_CLOCK_CLOCK_INTERFACE_H
