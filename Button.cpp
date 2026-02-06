#include "Button.h"

Button::Button(const std::string& text, int y, int x) :
label(text), pos_y(y), pos_x(x), height(3), width(label.length()+4) {}

void Button::draw(WINDOW* window) {



    mvwaddch(window, pos_y, pos_x,  ACS_ULCORNER);
    mvwaddch(window, pos_y, pos_x + width - 1,  ACS_URCORNER);
    mvwaddch(window, pos_y + height - 1, pos_x,  ACS_LLCORNER);
    mvwaddch(window, pos_y + height - 1, pos_x + width - 1,  ACS_LRCORNER);


    mvwhline(window, pos_y, pos_x + 1, ACS_HLINE, width - 2);
    mvwhline(window, pos_y + height - 1, pos_x + 1, ACS_HLINE, width - 2);


    mvwvline(window, pos_y + 1, pos_x, ACS_VLINE, height - 2);
    mvwvline(window, pos_y + 1, pos_x + width - 1, ACS_VLINE, height - 2);


    int text_x = pos_x + (width - label.length()) / 2;
    int text_y = pos_y + 1;

    mvwprintw(window, text_y, text_x, "%s", label.c_str());


}

