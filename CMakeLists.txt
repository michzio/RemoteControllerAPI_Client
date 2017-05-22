cmake_minimum_required(VERSION 3.6)
project(RemoteControllerAPI_Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES client.h client.c networking/conn_socket.h networking/conn_socket.c networking/connection.h networking/connection.c networking/datagram_client.h networking/datagram_client.c networking/service.h networking/service.c networking/stream_client.h networking/stream_client.c)
set(TEST_SOURCE_FILES test/test_client.h test/test_client.c test/test_transfer.h test/test_transfer.c test/test_transfer_osx.c)

if(CYGWIN)
    # windows cygwin
    message("building for Cygwin")
else()
    # unix
    message("building for Unix")
endif()

# libraries paths
set(NETWORKING_PATH ${CMAKE_SOURCE_DIR}/../networking)
set(COMMON_FUNCTIONS_PATH ${CMAKE_SOURCE_DIR}/../common)
set(COMPARERS_PATH ${CMAKE_SOURCE_DIR}/../comparers)
set(UNIT_TESTS_PATH ${CMAKE_SOURCE_DIR}/../unit_tests)
if(CYGWIN)
    # windows cygwin
    set(NETWORKING_LIB_PATH ${NETWORKING_PATH}/output/windows/lib/static/libnetworking.a)
    set(COMMON_FUNCTIONS_LIB_PATH ${COMMON_FUNCTIONS_PATH}/output/windows/lib/static/libcommon_functions.a)
    set(COMPARERS_LIB_PATH ${COMPARERS_PATH}/output/windows/lib/static/libcomparers.a)
    set(UNIT_TESTS_LIB_PATH ${UNIT_TESTS_PATH}/output/windows/lib/static/libunit_tests.a)
else()
    # unix
    set(NETWORKING_LIB_PATH ${NETWORKING_PATH}/output/unix/lib/static/libnetworking.a)
    set(COMMON_FUNCTIONS_LIB_PATH ${COMMON_FUNCTIONS_PATH}/output/unix/lib/static/libcommon_functions.a)
    set(COMPARERS_LIB_PATH ${COMPARERS_PATH}/output/unix/lib/static/libcomparers.a)
    set(UNIT_TESTS_LIB_PATH ${UNIT_TESTS_PATH}/output/unix/lib/static/libunit_tests.a)
endif()

add_library(RC_Client_Lib SHARED ${SOURCE_FILES})
set_target_properties(RC_Client_Lib PROPERTIES OUTPUT_NAME rc_client_shared)
target_link_libraries(RC_Client_Lib ${NETWORKING_LIB_PATH})
target_link_libraries(RC_Client_Lib ${COMMON_FUNCTIONS_LIB_PATH})

add_library(RC_Client_Lib_Static ${SOURCE_FILES})
set_target_properties(RC_Client_Lib_Static PROPERTIES OUTPUT_NAME rc_client)
target_link_libraries(RC_Client_Lib_Static ${NETWORKING_LIB_PATH})
target_link_libraries(RC_Client_Lib_Static ${COMMON_FUNCTIONS_LIB_PATH})

add_executable(RemoteControllerAPI_Client main.c ${TEST_SOURCE_FILES})
set_target_properties(RemoteControllerAPI_Client PROPERTIES OUTPUT_NAME rc_client)
target_link_libraries(RemoteControllerAPI_Client RC_Client_Lib_Static)
target_link_libraries(RemoteControllerAPI_Client ${COMPARERS_LIB_PATH})
target_link_libraries(RemoteControllerAPI_Client ${UNIT_TESTS_LIB_PATH})

# install targets (executables, shared libraries, static libraries) in current project source directory
add_custom_target(Install_${PROJECT_NAME}
                  $(MAKE) install
                  DEPENDS ${PROJECT_NAME}
                  COMMENT "Installing ${PROJECT_NAME}")

if(CYGWIN)
    # windows cygwin
    set(RUNTIME_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/bin)
    set(LIBRARY_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/lib)
    set(ARCHIVE_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/lib/static)
else()
    # unix
    set(RUNTIME_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/bin)
    set(LIBRARY_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/lib)
    set(ARCHIVE_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/lib/static)
endif()

install(TARGETS RemoteControllerAPI_Client RC_Client_Lib RC_Client_Lib_Static
        RUNTIME DESTINATION ${RUNTIME_DEST_DIR}
        LIBRARY DESTINATION ${LIBRARY_DEST_DIR}
        ARCHIVE DESTINATION ${ARCHIVE_DEST_DIR})
