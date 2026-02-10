#include <gtest/gtest.h>
#include "../Clock.h"

Clock c;
TEST(Clock_format_test, X24_EUR_TEST){

    std::tm time_input = {};
    time_input.tm_year = 126;
    time_input.tm_mon = 1;
    time_input.tm_mday = 9;
    time_input.tm_hour = 17;
    time_input.tm_min = 30;
    time_input.tm_sec = 0;


    c.set_date_format(date_format::EUR);
    c.set_time_format(time_format::X24);

    c.update_dtime(time_input);


    EXPECT_STREQ(c.get_time_string(), "09/02/2026 17:30:00");
}

TEST(Clock_format_test, X12_US_test){

    std::tm time_input = {};
    time_input.tm_year = 126;
    time_input.tm_mon = 1;
    time_input.tm_mday = 9;
    time_input.tm_hour = 17;
    time_input.tm_min = 30;
    time_input.tm_sec = 0;


    c.set_date_format(date_format::US);
    c.set_time_format(time_format::X12);

    c.update_dtime(time_input);


    EXPECT_STREQ(c.get_time_string(), "02/09/2026 05:30:00  PM");
}

TEST(Clock_format_test, X12_ISO_test){

    std::tm time_input = {};
    time_input.tm_year = 126; // inizia a contare da 1900
    time_input.tm_mon = 1;
    time_input.tm_mday = 9;
    time_input.tm_hour = 17;
    time_input.tm_min = 30;
    time_input.tm_sec = 0;

    c.set_date_format(date_format::ISO);
    c.set_time_format(time_format::X12);

    c.update_dtime(time_input);


    EXPECT_STREQ(c.get_time_string(), "2026/02/09 05:30:00  PM");
}


TEST(Clock_test, update_time) {

    c.update_dtime(Clock::now());
    std::string datetime1 = c.get_time_string();
    sleep(1);

    c.update_dtime(Clock::now());
    std::string datetime2 = c.get_time_string();

    EXPECT_NE(datetime1, datetime2);
}


