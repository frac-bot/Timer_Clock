#ifndef TIMER_CLOCK_BUTTON_H
#define TIMER_CLOCK_BUTTON_H
#include <string>
#include <curses.h>
class Button{
public:
    Button(const std::string& text, int y, int x);

    void draw(WINDOW *window);

    bool is_selected() const{
        return selected;
    }

   bool is_clicked(int mouse_y, int mouse_x, int win_abs_y, int win_abs_x) const;

private:
    std::string label;
    int pos_y, pos_x;
    int width,height;
    bool selected;
};

#endif //TIMER_CLOCK_BUTTON_H
