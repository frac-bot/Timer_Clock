#include <ncurses.h>
#include <memory>
#include "Clock.h"
#include "Clock_Interface.h"
#include "Timer.h"


int main() {

    initscr();
    start_color();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    keypad(stdscr, TRUE);

    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, nullptr);

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    //SET ORORLOGIO
    Clock Clock1;
    Clock1.set_date_format(date_format::EUR);
    Clock1.set_time_format(time_format::X24);

    int width = 40;
    int centred = (COLS - width) / 2;
    WINDOW* win_clock = newwin(5, width, 8, centred);

    //SET TIMER
    Timer timer1;
    timer1.set_time(0,0,0);

    int timer_y = 15;

    WINDOW* win_timer = newwin(9, width, 15, centred);
    //INTERFACCIA
    std::unique_ptr<Clock_Interface> interface = std::make_unique<Clock_Interface>();

    bool running = true;
    while(running) {
        int ch = getch();

        if (ch == 'q') {
            running = false;
        }
        Buttons_type action = interface->Timer_input(ch, timer_y, centred);

        if (action == Buttons_type::START_STOP) {
            if (timer1.is_in_execution())
                timer1.pause();
            else
                timer1.start();
        }
        else if (action == Buttons_type::RESET) {
            timer1.reset();
            timer1.set_time(0, 0, 0);
        }else if(action == Buttons_type::SET) {

            timer1.pause();

            mousemask(0, nullptr);
            flushinp();

            nodelay(stdscr, FALSE);
            echo();
            curs_set(1);

            WINDOW *win_input = newwin(8, 30, (LINES - 5) / 2, (COLS - 30) / 2);
            keypad(win_input, TRUE); //per evitare problemi con le frecce
            box(win_input, 0, 0);

            mvwprintw(win_input, 1, 2, "Set Timer:");
            mvwprintw(win_input, 2, 2, "h: ");
            mvwprintw(win_input, 3, 2, "m: ");
            mvwprintw(win_input, 4, 2, "s: ");
            mvwprintw(win_input, 5, 20, "MAX 4ch");
            mvwprintw(win_input, 6, 20, "MAX 100h"); //credo sia inutile un timer con troppe ore.

            wrefresh(win_input);

            int h = 0, m = 0, s = 0;
            mvwscanw(win_input, 2, 4, "%04d", &h);//ore
            mvwscanw(win_input, 3, 4, "%04d", &m);//minuti
            mvwscanw(win_input, 4, 4, "%04d", &s);//secondi
            //limito le cifre lette per evitare problemi con la grandezza di int

            int total_seconds = (h * 3600) + (m * 60) + s;

            int max_limit = 100 * 3600;

            if (total_seconds > max_limit) {
                h = 100;
                m = 0;
                s = 0;
            }else{

                h = total_seconds / 3600;

                int seconds_rem = total_seconds % 3600;

                m = seconds_rem / 60;
                s = seconds_rem % 60;

            }

            timer1.set_time(h, m, s);

            delwin(win_input);
            clear();

            noecho();
            curs_set(0);
            nodelay(stdscr, TRUE);

            mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, nullptr);//serve perche blocco i tasti mentre setto il timer

            refresh();

        }
        timer1.update_time();

        interface->draw_clock(win_clock, Clock1, 1);
        interface->draw_timer(win_timer, timer1, 1);
        napms(100);
    }

    delwin(win_clock);
    delwin(win_timer);
    endwin();

    return 0;
}
