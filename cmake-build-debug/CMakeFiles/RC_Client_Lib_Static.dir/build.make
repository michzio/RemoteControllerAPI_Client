# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/michzio/Developer/MyProjects/BachelorDegree/c/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RC_Client_Lib_Static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RC_Client_Lib_Static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RC_Client_Lib_Static.dir/flags.make

CMakeFiles/RC_Client_Lib_Static.dir/client.c.o: CMakeFiles/RC_Client_Lib_Static.dir/flags.make
CMakeFiles/RC_Client_Lib_Static.dir/client.c.o: ../client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RC_Client_Lib_Static.dir/client.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib_Static.dir/client.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/client.c

CMakeFiles/RC_Client_Lib_Static.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib_Static.dir/client.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/client.c > CMakeFiles/RC_Client_Lib_Static.dir/client.c.i

CMakeFiles/RC_Client_Lib_Static.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib_Static.dir/client.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/client.c -o CMakeFiles/RC_Client_Lib_Static.dir/client.c.s

CMakeFiles/RC_Client_Lib_Static.dir/client.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/client.c.o.requires

CMakeFiles/RC_Client_Lib_Static.dir/client.c.o.provides: CMakeFiles/RC_Client_Lib_Static.dir/client.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib_Static.dir/build.make CMakeFiles/RC_Client_Lib_Static.dir/client.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/client.c.o.provides

CMakeFiles/RC_Client_Lib_Static.dir/client.c.o.provides.build: CMakeFiles/RC_Client_Lib_Static.dir/client.c.o


CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o: CMakeFiles/RC_Client_Lib_Static.dir/flags.make
CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o: ../networking/conn_socket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/conn_socket.c

CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/conn_socket.c > CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.i

CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/conn_socket.c -o CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.s

CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o.requires

CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o.provides: CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib_Static.dir/build.make CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o.provides

CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o.provides.build: CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o


CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o: CMakeFiles/RC_Client_Lib_Static.dir/flags.make
CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o: ../networking/connection.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/connection.c

CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/connection.c > CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.i

CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/connection.c -o CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.s

CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o.requires

CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o.provides: CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib_Static.dir/build.make CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o.provides

CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o.provides.build: CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o


CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o: CMakeFiles/RC_Client_Lib_Static.dir/flags.make
CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o: ../networking/datagram_conn.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/datagram_conn.c

CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/datagram_conn.c > CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.i

CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/datagram_conn.c -o CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.s

CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o.requires

CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o.provides: CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib_Static.dir/build.make CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o.provides

CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o.provides.build: CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o


CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o: CMakeFiles/RC_Client_Lib_Static.dir/flags.make
CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o: ../networking/service.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/service.c

CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/service.c > CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.i

CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/service.c -o CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.s

CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o.requires

CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o.provides: CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib_Static.dir/build.make CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o.provides

CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o.provides.build: CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o


CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o: CMakeFiles/RC_Client_Lib_Static.dir/flags.make
CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o: ../networking/stream_conn.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/stream_conn.c

CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/stream_conn.c > CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.i

CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/stream_conn.c -o CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.s

CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o.requires

CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o.provides: CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib_Static.dir/build.make CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o.provides

CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o.provides.build: CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o


# Object files for target RC_Client_Lib_Static
RC_Client_Lib_Static_OBJECTS = \
"CMakeFiles/RC_Client_Lib_Static.dir/client.c.o" \
"CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o" \
"CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o" \
"CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o" \
"CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o" \
"CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o"

# External object files for target RC_Client_Lib_Static
RC_Client_Lib_Static_EXTERNAL_OBJECTS =

librc_client.a: CMakeFiles/RC_Client_Lib_Static.dir/client.c.o
librc_client.a: CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o
librc_client.a: CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o
librc_client.a: CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o
librc_client.a: CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o
librc_client.a: CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o
librc_client.a: CMakeFiles/RC_Client_Lib_Static.dir/build.make
librc_client.a: CMakeFiles/RC_Client_Lib_Static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library librc_client.a"
	$(CMAKE_COMMAND) -P CMakeFiles/RC_Client_Lib_Static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RC_Client_Lib_Static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RC_Client_Lib_Static.dir/build: librc_client.a

.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/build

CMakeFiles/RC_Client_Lib_Static.dir/requires: CMakeFiles/RC_Client_Lib_Static.dir/client.c.o.requires
CMakeFiles/RC_Client_Lib_Static.dir/requires: CMakeFiles/RC_Client_Lib_Static.dir/networking/conn_socket.c.o.requires
CMakeFiles/RC_Client_Lib_Static.dir/requires: CMakeFiles/RC_Client_Lib_Static.dir/networking/connection.c.o.requires
CMakeFiles/RC_Client_Lib_Static.dir/requires: CMakeFiles/RC_Client_Lib_Static.dir/networking/datagram_conn.c.o.requires
CMakeFiles/RC_Client_Lib_Static.dir/requires: CMakeFiles/RC_Client_Lib_Static.dir/networking/service.c.o.requires
CMakeFiles/RC_Client_Lib_Static.dir/requires: CMakeFiles/RC_Client_Lib_Static.dir/networking/stream_conn.c.o.requires

.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/requires

CMakeFiles/RC_Client_Lib_Static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RC_Client_Lib_Static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/clean

CMakeFiles/RC_Client_Lib_Static.dir/depend:
	cd /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/michzio/Developer/MyProjects/BachelorDegree/c/client /Users/michzio/Developer/MyProjects/BachelorDegree/c/client /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles/RC_Client_Lib_Static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RC_Client_Lib_Static.dir/depend

