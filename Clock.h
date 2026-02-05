#ifndef TIMER_CLOCK_CLOCK_H
#define TIMER_CLOCK_CLOCK_H
#include <ctime>
#include <string>
#include <ncurses.h>

enum class date_format { US,EUR,ISO };
enum class time_format { X12,X24 };

class Clock{
public:
    Clock();

    static std::tm now();

    void update_dtime(); //overloading
    void update_dtime(const std::tm& custom_time);

    void set_date_format(date_format format){
        date_f = format;
    }

    void set_time_format(time_format format){
        time_f = format;
    }

    const char* get_time_string() const {
        return buffer;
    }

private:
    static char buffer[80];
    date_format date_f;
    time_format time_f;
};

#endif //TIMER_CLOCK_CLOCK_H
