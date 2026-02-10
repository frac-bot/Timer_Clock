cmake_minimum_required(VERSION 3.28)
project(Timer_tests)

find_package(GTest REQUIRED)

set(SOURCE_FILES
    ../Timer.cpp
    ../Clock.cpp
        test_clock.cpp
)

add_executable(run_tests ${SOURCE_FILES})

target_link_libraries(run_tests
        GTest::gtest
        GTest::gtest_main
        ncurses
)

include(GoogleTest)
gtest_discover_tests(run_tests)



