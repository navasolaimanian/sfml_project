cmake_minimum_required(VERSION 3.0)
project(game)
set(CMAKE_CXX_STANDARD 11)
add_executable(app src/main.cpp src/input.cpp src/print.cpp src/game.cpp)
# set(SOURCES 
# 	src/main.cpp
# 	src/Map.cpp
# 	src/Pacman.cpp
# 	src/Menu.cpp
# 	src/Ghost.cpp
# 	src/Collision.cpp
# )
include_directories(include)
target_link_libraries(app sfml-window sfml-system sfml-graphics)
