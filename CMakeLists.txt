cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp)

target_link_libraries(untitled sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
