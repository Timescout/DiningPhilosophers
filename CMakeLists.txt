cmake_minimum_required(VERSION 3.22)
project(diningPholosophers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# main project build setup
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/code/source/*.cpp)
add_executable(diningPholosophers ${CMAKE_CURRENT_SOURCE_DIR}/code/main.cpp ${SRC_FILES})
target_include_directories(diningPholosophers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/code/headers)