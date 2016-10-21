cmake_minimum_required(VERSION 3.5)
project(RemoteControllerAPI_Client)

# OS X Cocoa libraries including
find_library(APPLICATION_SERVICES_LIBRARY ApplicationServices )
mark_as_advanced(APPLICATION_SERVICES_LIBRARY)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES client.h client.c networking/conn_socket.h networking/conn_socket.c networking/connection.h networking/connection.c networking/datagram_conn.h networking/datagram_conn.c networking/service.h networking/service.c networking/stream_conn.h networking/stream_conn.c)
set(TEST_SOURCE_FILES test/test_client.h test/test_client.c test/test_transfer.h test/test_transfer.c)

# libraries paths
set(NETWORKING_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/networking)
set(COMMON_FUNCTIONS_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/common)
set(COMPARERS_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/comparers)
set(UNIT_TESTS_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/unit_tests)

add_library(RC_Client_Lib SHARED ${SOURCE_FILES})
set_target_properties(RC_Client_Lib PROPERTIES OUTPUT_NAME rc_client_shared)
target_link_libraries(RC_Client_Lib ${APPLICATION_SERVICES_LIBRARY})
target_link_libraries(RC_Client_Lib ${NETWORKING_PATH}/libnetworking.a)
target_link_libraries(RC_Client_Lib ${COMMON_FUNCTIONS_PATH}/libcommon_functions.a)

add_library(RC_Client_Lib_Static ${SOURCE_FILES})
set_target_properties(RC_Client_Lib_Static PROPERTIES OUTPUT_NAME rc_client)
target_link_libraries(RC_Client_Lib_Static ${APPLICATION_SERVICES_LIBRARY})
target_link_libraries(RC_Client_Lib_Static ${NETWORKING_PATH}/libnetworking.a)
target_link_libraries(RC_Client_Lib_Static ${COMMON_FUNCTIONS_PATH}/libcommon_functions.a)

add_executable(RemoteControllerAPI_Client main.c ${TEST_SOURCE_FILES})
target_link_libraries(RemoteControllerAPI_Client RC_Client_Lib_Static)
target_link_libraries(RemoteControllerAPI_Client ${COMPARERS_PATH}/libcomparers.a)
target_link_libraries(RemoteControllerAPI_Client ${UNIT_TESTS_PATH}/libunit_tests.a)