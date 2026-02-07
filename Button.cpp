#include "Button.h"

Button::Button(const std::string& text, int y, int x) :
label(text), pos_y(y), pos_x(x), height(3), width(label.length()+4) {}

void Button::draw(WINDOW* window) {

    //ANGOLI
    mvwaddch(window, pos_y, pos_x,  ACS_ULCORNER);
    mvwaddch(window, pos_y, pos_x + width - 1,  ACS_URCORNER);
    mvwaddch(window, pos_y + height - 1, pos_x,  ACS_LLCORNER);
    mvwaddch(window, pos_y + height - 1, pos_x + width - 1,  ACS_LRCORNER);

    //LINEE ORIZZONTALI
    mvwhline(window, pos_y, pos_x + 1, ACS_HLINE, width - 2);
    mvwhline(window, pos_y + height - 1, pos_x + 1, ACS_HLINE, width - 2);

    //LINEEE VERTICALI
    mvwvline(window, pos_y + 1, pos_x, ACS_VLINE, height - 2);
    mvwvline(window, pos_y + 1, pos_x + width - 1, ACS_VLINE, height - 2);

    int text_x = pos_x + (width - label.length()) / 2; //posizione testo
    int text_y = pos_y + 1; //posizione testo

    mvwprintw(window, text_y, text_x, "%s", label.c_str());
}

bool Button::is_clicked(int mouse_y, int mouse_x, int win_abs_y, int win_abs_x) {

    int button_abs_y = win_abs_y + pos_y;
    int button_abs_x = win_abs_x + pos_x;


    bool clicked_y = (mouse_y >= button_abs_y) && (mouse_y < button_abs_y + height);
    bool clicked_x = (mouse_x >= button_abs_x) && (mouse_x < button_abs_x + width);

    return (clicked_y && clicked_x);
}

