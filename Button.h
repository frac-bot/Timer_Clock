#ifndef TIMER_CLOCK_BUTTON_H
#define TIMER_CLOCK_BUTTON_H
#include <string>
#include <curses.h>
class Button{
public:
    Button(const std::string& text, int y, int x);

    void draw(WINDOW *window);

    void select();
    void deselect();

private:
    std::string label;
    int pos_y, pos_x;
    int width,height;
};

#endif //TIMER_CLOCK_BUTTON_H
