cmake_minimum_required( VERSION 3.10 )

project( regex_c )

set( CMAKE_CXX_STANDARD 17 )

include_directories(./include)

add_executable( binary ./src/main.cpp ./src/regex_c.cpp)