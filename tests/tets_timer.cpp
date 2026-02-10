#include <gtest/gtest.h>
#include "../Timer.h"

Timer t;

TEST(timer_test, test_set_time){

    t.set_time(1,5,30);

    std::string time_string = t.get_time_string();

    std::string h = time_string.substr(0, 2);
    std::string m = time_string.substr(3, 2);
    std::string s = time_string.substr(6, 2);

    int hour = std::stoi(h);
    int minutes = std::stoi(m);
    int seconds = std::stoi(s);

    EXPECT_EQ(hour, 1);
    EXPECT_EQ(minutes, 5);
    EXPECT_EQ(seconds, 30);
}

TEST(timer_test, test_update){

    t.set_time(1,0,0);
    t.start();

    sleep(1);

    t.update_time();

    std::string time_string = t.get_time_string();

    EXPECT_STREQ(time_string.c_str(), "00:59:59");
}

TEST(timer_test, test_input){

    t.set_time(0,0,300);
    std::string time_string1 = t.get_time_string();

    EXPECT_STREQ(time_string1.c_str(), "00:05:00");

    t.set_time(1,70,97);
    std::string time_string2 = t.get_time_string();

    EXPECT_STREQ(time_string2.c_str(), "02:11:37");
}

TEST(timer_test, test_in_execution) {

    t.set_time(0, 0, 1);
    t.start();

    EXPECT_TRUE(t.is_in_execution());

    sleep(1);
    t.update_time();

    std::string time_string = t.get_time_string();

    EXPECT_FALSE(t.is_in_execution());
    EXPECT_STREQ(time_string.c_str(), "00:00:00");
}

TEST(timer_test, test_more_reset) {

    t.set_time(0, 0, 1);
    t.start();
    sleep(1);
    t.update_time();
    EXPECT_FALSE(t.is_in_execution());

    t.set_time(0, 0, 2);
    t.start();
    EXPECT_TRUE(t.is_in_execution()); // Deve ripartire!

    sleep(1);
    t.update_time();

    std::string time_string = t.get_time_string();

    EXPECT_STREQ(time_string.c_str(), "00:00:01");
}

TEST(timer_test, test_negative_numbers){

    t.set_time(-10,-30,-4);

    std::string time_string1 = t.get_time_string();
    EXPECT_STREQ(time_string1.c_str(), "00:00:00");

    t.set_time(-2,-4,-67);

    std::string time_string2 = t.get_time_string();
    EXPECT_STREQ(time_string2.c_str(), "00:00:00");

}