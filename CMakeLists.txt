cmake_minimum_required(VERSION 3.5)
project(RemoteControllerAPI_Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c client.h client.c common/address_helper.h common/address_helper.c networking/conn_socket.h networking/conn_socket.c networking/connection.h networking/connection.c networking/stream.h networking/stream.c networking/service.h networking/service.c common/io_helper.h common/io_helper.c)
add_executable(RemoteControllerAPI_Client ${SOURCE_FILES})