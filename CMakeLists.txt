cmake_minimum_required(VERSION 3.16)
project(521)

set(CMAKE_PREFIX_PATH /usr)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network)
find_package(Marble REQUIRED)

SET(CMAKE_AUTOMOC ON)

add_executable(521 main.cpp
        marble_map/map_track/map_track.cpp
        marble_map/map_track/map_track.h
        marble_map/amb_sim/amb_sim.cpp
        marble_map/amb_sim/amb_sim.h)
target_link_libraries(521 Marble Qt5::Widgets Qt5::Network)
