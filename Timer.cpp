#include "Timer.h"

Timer::Timer() = default;

void Timer::add_hour(int seconds) {
    if(seconds > 0)
        remaining_seconds += seconds * 3600;
}

void Timer::add_minute(int seconds) {
    if(seconds > 0)
        remaining_seconds += seconds *60;
}

void Timer::add_second(int seconds) {
    if(seconds >0)
        remaining_seconds += seconds;
}

void Timer::start() {

    if(remaining_seconds > 0){
        in_execution = true;
        last_update_time = time(nullptr);// Mi segno che ore sono adesso
    }
}

void Timer::pause() {

    in_execution = false;
}

void Timer::reset() {
    remaining_seconds = 0;
    in_execution = false;
}

void Timer::set_time(int h, int m, int s) {
    remaining_seconds = 0;
    add_hour(h);
    add_minute(m);
    add_second(s);
}

std::string Timer::get_time_string() const {
    int h = remaining_seconds/3600;
    int m = (remaining_seconds %3600)/60;
    int s = remaining_seconds % 60;

    char buffer[80];

    sprintf(buffer, "%02d:%02d:%02d", h,m,s);

    return buffer;
}


void Timer::update_time() {
    if(in_execution && remaining_seconds > 0){ // modificata pe rcontare i seconsi effettivi

        time_t now = time(nullptr);

        if(now > last_update_time){
            int diff = now - last_update_time;
            remaining_seconds -= diff;
            last_update_time = now;

            if(remaining_seconds <= 0) {
                remaining_seconds = 0;
                in_execution = false; // quando il timer va a 0 in_execution = false
            }
        }

    }else {
        in_execution = false;
        return;
    }
}
