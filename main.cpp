#include <ncurses.h>
#include <memory>
#include "Clock.h"
#include "Clock_Interface.h"



int main() {

    initscr();
    start_color();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    Clock Clock1;
    Clock1.set_date_format(date_format::EUR);
    Clock1.set_time_format(time_format::X24);

    int width = 40;
    int centred = (COLS - width) / 2;
    WINDOW* win_clock = newwin(5, width, 8, centred);

    std::unique_ptr<Clock_Interface> interface = std::make_unique<Clock_Interface>();

    bool running = true;
    while(running) {
        int ch = getch();

        if (ch == 'q') {
            running = false;
        }

        interface->draw_clock(win_clock, Clock1, 1);
        napms(100);
    }

    delwin(win_clock);
    endwin();

    return 0;
}
