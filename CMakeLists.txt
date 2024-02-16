cmake_minimum_required(VERSION 3.26)
project(pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(pong main.cpp
        Player/Player.h
        Ball/Ball.h
        RandomEngine.h
        PointCounter/PointCounter.h
        GameHandler/GameHandler.h
        GameHandler/GameHandler.cpp
        EntityHandler/EntityHandler.h
        EntityHandler/EntityHandler.cpp
        Player/player.cpp
        Ball/Ball.cpp
        PointCounter/PointCounter.cpp
        PowerUp/PowerUp.h
        PowerUp/SpeedPowerUp.h
        PowerUp/SlowPowerUp.h
        PowerUp/GrowPowerUp.h
        PowerUp/ShrinkPowerUp.h
        PowerUp/PowerUp.cpp
)

target_link_libraries(pong sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
