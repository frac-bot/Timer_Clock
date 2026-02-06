#include "Clock_Interface.h"

Clock_Interface::Clock_Interface() :
start_stop_button(std::make_unique<Button>("START_STOP", 5,5)), reset_button(std::make_unique<Button>("RESET",5,25)) {}

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

void Clock_Interface::draw_timer(WINDOW *window, Timer &timer, int color_id) {

    getmaxyx(window, win_height,win_width);
    werase(window);
    wattron(window, COLOR_PAIR(color_id));


    box(window,0,0);
    mvwprintw(window, 0, 2, " TIMER ");

    std::string actual_time = timer.get_time_string();

    int text_x = (win_width - actual_time.length()) / 2;

    wattron(window,A_BOLD);
    mvwprintw(window,2,text_x, "%s", actual_time.c_str());

    wattroff(window, A_BOLD);


    start_stop_button->draw(window);
    reset_button->draw(window);

    wattroff(window, COLOR_PAIR(color_id));
    wrefresh(window);

}