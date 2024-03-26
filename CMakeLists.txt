cmake_minimum_required(VERSION 3.25)

project(linkIT)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(linkIT SHARED src/signal.cpp)

target_include_directories(linkIT PUBLIC include)
