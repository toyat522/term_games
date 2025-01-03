cmake_minimum_required(VERSION 3.10)
project(snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/apple.cpp
    src/element.cpp
    src/game.cpp
    src/snake.cpp
    src/main.cpp
)

add_executable(snake ${SOURCES})

target_link_libraries(snake ncursesw)
