cmake_minimum_required(VERSION 3.28)
project(Timer_Clock)

find_package(Curses REQUIRED)

add_executable(Timer_Clock main.cpp
        Timer.cpp
        Timer.h
        Clock.cpp
        Clock.h
        Clock_Interface.cpp
        Clock_Interface.h
        Button.h
        Button.cpp
)

include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(Timer_Clock ${CURSES_LIBRARIES})

add_subdirectory(tests)