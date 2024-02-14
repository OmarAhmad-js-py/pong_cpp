cmake_minimum_required(VERSION 3.26)
project(pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(pong main.cpp
        Player/Player.h
        Ball/Ball.h
        RandomEngine.h
        PointCounter.h
        GameHandler/GameHandler.h
        GameHandler/GameHandler.cpp
        EntityHandler/EntityHandler.h
        EntityHandler/EntityHandler.cpp
        Player/player.cpp
        Ball/Ball.cpp
        PointCounter.cpp
)

target_link_libraries(pong sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
