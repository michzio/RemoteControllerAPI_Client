cmake_minimum_required(VERSION 3.5)
project(RemoteControllerAPI_Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c client.h client.c common/helper.h common/helper.c networking/conn_socket.h networking/conn_socket.c networking/connection.h networking/connection.c)
add_executable(RemoteControllerAPI_Client ${SOURCE_FILES})