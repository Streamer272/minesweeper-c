cmake_minimum_required(VERSION 3.22)
project(minesweeper C)

set(CMAKE_C_STANDARD 23)

add_executable(minesweeper
    src/main.c
    src/field.h src/field.c
    src/term.h src/term.c)

target_link_libraries(minesweeper PRIVATE m)
install(TARGETS minesweeper DESTINATION /usr/local/bin)
