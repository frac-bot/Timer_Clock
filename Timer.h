#ifndef TIMER_CLOCK_TIMER_H
#define TIMER_CLOCK_TIMER_H

class Timer{
public:
    Timer();

    void add_hour(int s);
    void add_minute(int s);
    void add_second(int s);

    void start();
    void pause();
    void reset();
    void set_time(int h, int m, int s);

    void decrement_seconds();

private:
    bool in_execution = false;
    int remaining_seconds = 0;
};

#endif //TIMER_CLOCK_TIMER_H
