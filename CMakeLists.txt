cmake_minimum_required(VERSION 3.16)
project(521)

set(CMAKE_PREFIX_PATH /usr)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network)
find_package(Marble REQUIRED)

add_executable(521 main.cpp) # Map_And_Navigation/Map_Display.h Map_And_Navigation/Map_Display.cpp)
target_link_libraries(521 Marble Qt5::Widgets Qt5::Network)
