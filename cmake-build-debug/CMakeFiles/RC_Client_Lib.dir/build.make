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
include CMakeFiles/RC_Client_Lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RC_Client_Lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RC_Client_Lib.dir/flags.make

CMakeFiles/RC_Client_Lib.dir/client.c.o: CMakeFiles/RC_Client_Lib.dir/flags.make
CMakeFiles/RC_Client_Lib.dir/client.c.o: ../client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RC_Client_Lib.dir/client.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib.dir/client.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/client.c

CMakeFiles/RC_Client_Lib.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib.dir/client.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/client.c > CMakeFiles/RC_Client_Lib.dir/client.c.i

CMakeFiles/RC_Client_Lib.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib.dir/client.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/client.c -o CMakeFiles/RC_Client_Lib.dir/client.c.s

CMakeFiles/RC_Client_Lib.dir/client.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib.dir/client.c.o.requires

CMakeFiles/RC_Client_Lib.dir/client.c.o.provides: CMakeFiles/RC_Client_Lib.dir/client.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib.dir/build.make CMakeFiles/RC_Client_Lib.dir/client.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib.dir/client.c.o.provides

CMakeFiles/RC_Client_Lib.dir/client.c.o.provides.build: CMakeFiles/RC_Client_Lib.dir/client.c.o


CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o: CMakeFiles/RC_Client_Lib.dir/flags.make
CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o: ../networking/authentication.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/authentication.c

CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/authentication.c > CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.i

CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/authentication.c -o CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.s

CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o.requires

CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o.provides: CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib.dir/build.make CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o.provides

CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o.provides.build: CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o


CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o: CMakeFiles/RC_Client_Lib.dir/flags.make
CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o: ../networking/client_info.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/client_info.c

CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/client_info.c > CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.i

CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/client_info.c -o CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.s

CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o.requires

CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o.provides: CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib.dir/build.make CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o.provides

CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o.provides.build: CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o


CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o: CMakeFiles/RC_Client_Lib.dir/flags.make
CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o: ../networking/conn_socket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/conn_socket.c

CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/conn_socket.c > CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.i

CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/conn_socket.c -o CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.s

CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o.requires

CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o.provides: CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib.dir/build.make CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o.provides

CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o.provides.build: CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o


CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o: CMakeFiles/RC_Client_Lib.dir/flags.make
CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o: ../networking/connection.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/connection.c

CMakeFiles/RC_Client_Lib.dir/networking/connection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib.dir/networking/connection.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/connection.c > CMakeFiles/RC_Client_Lib.dir/networking/connection.c.i

CMakeFiles/RC_Client_Lib.dir/networking/connection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib.dir/networking/connection.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/connection.c -o CMakeFiles/RC_Client_Lib.dir/networking/connection.c.s

CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o.requires

CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o.provides: CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib.dir/build.make CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o.provides

CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o.provides.build: CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o


CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o: CMakeFiles/RC_Client_Lib.dir/flags.make
CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o: ../networking/datagram_client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/datagram_client.c

CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/datagram_client.c > CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.i

CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/datagram_client.c -o CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.s

CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o.requires

CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o.provides: CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib.dir/build.make CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o.provides

CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o.provides.build: CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o


CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o: CMakeFiles/RC_Client_Lib.dir/flags.make
CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o: ../networking/generic_client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/generic_client.c

CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/generic_client.c > CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.i

CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/generic_client.c -o CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.s

CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o.requires

CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o.provides: CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib.dir/build.make CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o.provides

CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o.provides.build: CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o


CMakeFiles/RC_Client_Lib.dir/networking/service.c.o: CMakeFiles/RC_Client_Lib.dir/flags.make
CMakeFiles/RC_Client_Lib.dir/networking/service.c.o: ../networking/service.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/RC_Client_Lib.dir/networking/service.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib.dir/networking/service.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/service.c

CMakeFiles/RC_Client_Lib.dir/networking/service.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib.dir/networking/service.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/service.c > CMakeFiles/RC_Client_Lib.dir/networking/service.c.i

CMakeFiles/RC_Client_Lib.dir/networking/service.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib.dir/networking/service.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/service.c -o CMakeFiles/RC_Client_Lib.dir/networking/service.c.s

CMakeFiles/RC_Client_Lib.dir/networking/service.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/service.c.o.requires

CMakeFiles/RC_Client_Lib.dir/networking/service.c.o.provides: CMakeFiles/RC_Client_Lib.dir/networking/service.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib.dir/build.make CMakeFiles/RC_Client_Lib.dir/networking/service.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/service.c.o.provides

CMakeFiles/RC_Client_Lib.dir/networking/service.c.o.provides.build: CMakeFiles/RC_Client_Lib.dir/networking/service.c.o


CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o: CMakeFiles/RC_Client_Lib.dir/flags.make
CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o: ../networking/stream_client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o   -c /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/stream_client.c

CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/stream_client.c > CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.i

CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/networking/stream_client.c -o CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.s

CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o.requires:

.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o.requires

CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o.provides: CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o.requires
	$(MAKE) -f CMakeFiles/RC_Client_Lib.dir/build.make CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o.provides.build
.PHONY : CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o.provides

CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o.provides.build: CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o


# Object files for target RC_Client_Lib
RC_Client_Lib_OBJECTS = \
"CMakeFiles/RC_Client_Lib.dir/client.c.o" \
"CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o" \
"CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o" \
"CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o" \
"CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o" \
"CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o" \
"CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o" \
"CMakeFiles/RC_Client_Lib.dir/networking/service.c.o" \
"CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o"

# External object files for target RC_Client_Lib
RC_Client_Lib_EXTERNAL_OBJECTS =

librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/client.c.o
librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o
librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o
librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o
librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o
librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o
librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o
librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/networking/service.c.o
librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o
librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/build.make
librc_client.dylib: ../../networking/output/unix/lib/static/libnetworking.a
librc_client.dylib: ../../common/output/unix/lib/static/libcommon_functions.a
librc_client.dylib: CMakeFiles/RC_Client_Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C shared library librc_client.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RC_Client_Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RC_Client_Lib.dir/build: librc_client.dylib

.PHONY : CMakeFiles/RC_Client_Lib.dir/build

CMakeFiles/RC_Client_Lib.dir/requires: CMakeFiles/RC_Client_Lib.dir/client.c.o.requires
CMakeFiles/RC_Client_Lib.dir/requires: CMakeFiles/RC_Client_Lib.dir/networking/authentication.c.o.requires
CMakeFiles/RC_Client_Lib.dir/requires: CMakeFiles/RC_Client_Lib.dir/networking/client_info.c.o.requires
CMakeFiles/RC_Client_Lib.dir/requires: CMakeFiles/RC_Client_Lib.dir/networking/conn_socket.c.o.requires
CMakeFiles/RC_Client_Lib.dir/requires: CMakeFiles/RC_Client_Lib.dir/networking/connection.c.o.requires
CMakeFiles/RC_Client_Lib.dir/requires: CMakeFiles/RC_Client_Lib.dir/networking/datagram_client.c.o.requires
CMakeFiles/RC_Client_Lib.dir/requires: CMakeFiles/RC_Client_Lib.dir/networking/generic_client.c.o.requires
CMakeFiles/RC_Client_Lib.dir/requires: CMakeFiles/RC_Client_Lib.dir/networking/service.c.o.requires
CMakeFiles/RC_Client_Lib.dir/requires: CMakeFiles/RC_Client_Lib.dir/networking/stream_client.c.o.requires

.PHONY : CMakeFiles/RC_Client_Lib.dir/requires

CMakeFiles/RC_Client_Lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RC_Client_Lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RC_Client_Lib.dir/clean

CMakeFiles/RC_Client_Lib.dir/depend:
	cd /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/michzio/Developer/MyProjects/BachelorDegree/c/client /Users/michzio/Developer/MyProjects/BachelorDegree/c/client /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug /Users/michzio/Developer/MyProjects/BachelorDegree/c/client/cmake-build-debug/CMakeFiles/RC_Client_Lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RC_Client_Lib.dir/depend

