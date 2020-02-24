
cmake_minimum_required(VERSION 3.15)
<<<<<<< HEAD
project(ClientServer)
=======
project(clientServer)
>>>>>>> 436046722b1befef7ba4d19500f6bfae77e0009e

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientServer main.cpp)
add_executable(server server.c)
add_executable(client client.c)
