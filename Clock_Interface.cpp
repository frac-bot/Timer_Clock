#include "Clock_Interface.h"


void Clock_Interface::draw_clock(WINDOW* window, Clock& clock, int color_id) {

    clock.update_dtime();

    auto actual_time = clock.get_time_string();

    getmaxyx(window,win_height,win_width);

    int str_length = strlen(actual_time);

    int pos_x = (win_width - str_length) / 2;
    int pos_y = (win_height / 2);


    werase(window);

    wattron(window, COLOR_PAIR(color_id));

    box(window,0,0);

    mvwprintw(window, 0, 2, " SYSTEM TIME ");
    mvwprintw(window, pos_y, pos_x, "%s", actual_time);

    wrefresh(window);

}
