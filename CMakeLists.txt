cmake_minimum_required(VERSION 3.26)
project(pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(pong main.cpp
        Player.h
        Ball.h)

target_link_libraries(pong sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
