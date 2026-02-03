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


void Timer::decrement_seconds() {
    if(in_execution && remaining_seconds > 0)
        remaining_seconds--;
    else
        in_execution = false;
}
