cmake_minimum_required(VERSION 3.6)
project(RemoteControllerAPI_Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES include/client.h src/client.c include/networking/authentication.h src/networking/authentication.c include/networking/client_info.h src/networking/client_info.c include/networking/conn_socket.h src/networking/conn_socket.c include/networking/connection.h src/networking/connection.c include/networking/datagram_client.h src/networking/datagram_client.c include/networking/generic_client.h src/networking/generic_client.c include/networking/service.h src/networking/service.c include/networking/stream_client.h src/networking/stream_client.c)
set(TEST_SOURCE_FILES test/test_client.h test/test_client.c test/test_transfer.h test/test_transfer.c test/test_transfer_osx.c)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs)
if(CYGWIN)
    # windows cygwin
    message("building for Cygwin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/cygwin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/cygwin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/bin/cygwin)
elseif(APPLE)
    # apple
    message("building for Apple")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/apple)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/apple)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/bin/apple)
else()
    # unix
    message("building for Unix")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/unix)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/unix)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/bin/unix)
endif()

### MAKING LIBRARIES ###
# include current project headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# subprojects paths
set(NETWORKING_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../networking)
set(NETWORKING_BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../networking/outputs)
set(COMMON_FUNCTIONS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../common)
set(COMMON_FUNCTIONS_BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../common/outputs)

# add subprojects
add_subdirectory(   # Specifies the directory of the CMakeLists.txt file.
                    ${NETWORKING_SRC_DIR}
                    # Specifies the directory for the build outputs.
                    ${NETWORKING_BUILD_DIR} )

add_subdirectory(   # Specifies the directory of the CMakeLists.txt file.
                    ${COMMON_FUNCTIONS_SRC_DIR}
                    # Specifies the directory for the build outputs.
                    ${COMMON_FUNCTIONS_BUILD_DIR} )

# include header files of subproject
include_directories(${NETWORKING_SRC_DIR}/include)
include_directories(${COMMON_FUNCTIONS_SRC_DIR}/include)
include_directories(${COMMON_FUNCTIONS_SRC_DIR}/libraries)

# current project shared and static libraries creation
# SHARED
add_library(RC_Client_Lib SHARED ${SOURCE_FILES})
set_target_properties(RC_Client_Lib PROPERTIES OUTPUT_NAME rc_client)
target_link_libraries(RC_Client_Lib Networking_Lib)
target_link_libraries(RC_Client_Lib Common_Functions_Lib)

# STATIC
add_library(RC_Client_Lib_Static ${SOURCE_FILES})
set_target_properties(RC_Client_Lib_Static PROPERTIES OUTPUT_NAME rc_client)
target_link_libraries(RC_Client_Lib_Static Networking_Lib_Static)
target_link_libraries(RC_Client_Lib_Static Common_Functions_Lib_Static)

### MAKING EXECUTABLE ###
# executable's libraries paths
set(UNIT_TESTS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../unit_tests)
set(COMPARERS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../comparers)
if(CYGWIN)
    # windows cygwin
    set(UNIT_TESTS_LIB_PATH ${UNIT_TESTS_SRC_DIR}/outputs/lib/cygwin/libunit_tests.so)
    set(COMPARERS_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/cygwin/libcomparers.so)
elseif(APPLE)
    # apple
    set(UNIT_TESTS_LIB_PATH ${UNIT_TESTS_SRC_DIR}/outputs/lib/apple/libunit_tests.dylib)
    set(COMPARERS_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/apple/libcomparers.dylib)
else()
    # unix
    set(UNIT_TESTS_LIB_PATH ${UNIT_TESTS_SRC_DIR}/outputs/lib/unix/libunit_tests.so)
    set(COMPARERS_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/unix/libcomparers.so)
endif()

# executable's libraries import
add_library(Unit_Test_Lib SHARED IMPORTED)
set_target_properties( Unit_Test_Lib PROPERTIES IMPORTED_LOCATION ${UNIT_TESTS_LIB_PATH} )
add_library(Comparers_Lib SHARED IMPORTED)
set_target_properties( Comparers_Lib PROPERTIES IMPORTED_LOCATION ${COMPARERS_LIB_PATH} )

# executable's libraries include headers
include_directories( ${UNIT_TESTS_SRC_DIR}/include )
include_directories( ${COMPARERS_SRC_DIR}/include )

# current project executable creation
add_executable(RemoteControllerAPI_Client src/main.c include/config.h ${TEST_SOURCE_FILES})
set_target_properties(RemoteControllerAPI_Client PROPERTIES OUTPUT_NAME rc_client)
target_link_libraries(RemoteControllerAPI_Client RC_Client_Lib)
target_link_libraries(RemoteControllerAPI_Client Unit_Test_Lib)
target_link_libraries(RemoteControllerAPI_Client Comparers_Lib)
