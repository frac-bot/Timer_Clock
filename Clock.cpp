#include "Clock.h"

char Clock::buffer[80]; //va inizializzato qui se lo voglio mantenere static, ma ci sono anche altre soluzioni!



Clock::Clock() : date_f(date_format::EUR) ,time_f(time_format::X24) {}

std::tm Clock::now() {
    std::time_t t = std::time(nullptr);
    return *std::localtime(&t);
}

void Clock::update_dtime() {
    update_dtime(now());
}

void Clock::update_dtime(const std::tm& custom_time) {
    std::string format;

    if(date_f == date_format::EUR)
        format += "%d/%m/%Y ";

    if(date_f == date_format::US)
        format += "%m/%d/%Y ";

    if(date_f == date_format::ISO)
        format += "%Y/%m/%d ";

    if(time_f == time_format::X24)
        format += "%H:%M:%S";

    if(time_f == time_format::X12)
        format += "%I:%M:%S  %p";

    strftime(buffer, sizeof(buffer), format.c_str(), &custom_time);

}