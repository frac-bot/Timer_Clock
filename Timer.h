#ifndef TIMER_CLOCK_TIMER_H
#define TIMER_CLOCK_TIMER_H
#include <string>
#include <ctime>

class Timer{
public:
    Timer();

    void add_hour(int s);
    void add_minute(int s);
    void add_second(int s);

    void start(time_t custom_time = 0);
    void pause();
    void reset();
    void set_time(int h, int m, int s);

    bool is_in_execution() const {
        return in_execution;
    }

    std::string get_time_string() const;

    void update_time(time_t custom_time = 0);

private:
    bool in_execution = false;
    int remaining_seconds = 0;
    time_t last_update_time;
};

#endif //TIMER_CLOCK_TIMER_H
