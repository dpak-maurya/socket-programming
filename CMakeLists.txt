cmake_minimum_required(VERSION 3.15)
project(Assign1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assign1 main.cpp)
add_executable(server server.c)
add_executable(client client.c)