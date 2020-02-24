
cmake_minimum_required(VERSION 3.15)
project(ClientServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientServer main.cpp)
add_executable(server server.c)
add_executable(client client.c)
