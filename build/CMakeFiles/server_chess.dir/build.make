# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arch/Desktop/Codes/C++/Rasta/final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arch/Desktop/Codes/C++/Rasta/final/build

# Include any dependencies generated for this target.
include CMakeFiles/server_chess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/server_chess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/server_chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server_chess.dir/flags.make

CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.o: CMakeFiles/server_chess.dir/flags.make
CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.o: /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/ServerGame.cpp
CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.o: CMakeFiles/server_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/arch/Desktop/Codes/C++/Rasta/final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.o -MF CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.o.d -o CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.o -c /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/ServerGame.cpp

CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/ServerGame.cpp > CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.i

CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/ServerGame.cpp -o CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.s

CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.o: CMakeFiles/server_chess.dir/flags.make
CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.o: /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/AbstractOnlinePlayer.cpp
CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.o: CMakeFiles/server_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/arch/Desktop/Codes/C++/Rasta/final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.o -MF CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.o.d -o CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.o -c /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/AbstractOnlinePlayer.cpp

CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/AbstractOnlinePlayer.cpp > CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.i

CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/AbstractOnlinePlayer.cpp -o CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.s

CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.o: CMakeFiles/server_chess.dir/flags.make
CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.o: /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/RemotePlayer.cpp
CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.o: CMakeFiles/server_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/arch/Desktop/Codes/C++/Rasta/final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.o -MF CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.o.d -o CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.o -c /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/RemotePlayer.cpp

CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/RemotePlayer.cpp > CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.i

CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/RemotePlayer.cpp -o CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.s

CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.o: CMakeFiles/server_chess.dir/flags.make
CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.o: /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/LocalPlayer.cpp
CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.o: CMakeFiles/server_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/arch/Desktop/Codes/C++/Rasta/final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.o -MF CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.o.d -o CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.o -c /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/LocalPlayer.cpp

CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/LocalPlayer.cpp > CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.i

CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/LocalPlayer.cpp -o CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.s

CMakeFiles/server_chess.dir/sources/online/main-server.cpp.o: CMakeFiles/server_chess.dir/flags.make
CMakeFiles/server_chess.dir/sources/online/main-server.cpp.o: /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/main-server.cpp
CMakeFiles/server_chess.dir/sources/online/main-server.cpp.o: CMakeFiles/server_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/arch/Desktop/Codes/C++/Rasta/final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server_chess.dir/sources/online/main-server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_chess.dir/sources/online/main-server.cpp.o -MF CMakeFiles/server_chess.dir/sources/online/main-server.cpp.o.d -o CMakeFiles/server_chess.dir/sources/online/main-server.cpp.o -c /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/main-server.cpp

CMakeFiles/server_chess.dir/sources/online/main-server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server_chess.dir/sources/online/main-server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/main-server.cpp > CMakeFiles/server_chess.dir/sources/online/main-server.cpp.i

CMakeFiles/server_chess.dir/sources/online/main-server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server_chess.dir/sources/online/main-server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arch/Desktop/Codes/C++/Rasta/final/sources/online/main-server.cpp -o CMakeFiles/server_chess.dir/sources/online/main-server.cpp.s

# Object files for target server_chess
server_chess_OBJECTS = \
"CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.o" \
"CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.o" \
"CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.o" \
"CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.o" \
"CMakeFiles/server_chess.dir/sources/online/main-server.cpp.o"

# External object files for target server_chess
server_chess_EXTERNAL_OBJECTS =

server_chess: CMakeFiles/server_chess.dir/sources/online/ServerGame.cpp.o
server_chess: CMakeFiles/server_chess.dir/sources/online/AbstractOnlinePlayer.cpp.o
server_chess: CMakeFiles/server_chess.dir/sources/online/RemotePlayer.cpp.o
server_chess: CMakeFiles/server_chess.dir/sources/online/LocalPlayer.cpp.o
server_chess: CMakeFiles/server_chess.dir/sources/online/main-server.cpp.o
server_chess: CMakeFiles/server_chess.dir/build.make
server_chess: sources/libCommonFiles.a
server_chess: CMakeFiles/server_chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/arch/Desktop/Codes/C++/Rasta/final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable server_chess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_chess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server_chess.dir/build: server_chess
.PHONY : CMakeFiles/server_chess.dir/build

CMakeFiles/server_chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server_chess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server_chess.dir/clean

CMakeFiles/server_chess.dir/depend:
	cd /home/arch/Desktop/Codes/C++/Rasta/final/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arch/Desktop/Codes/C++/Rasta/final /home/arch/Desktop/Codes/C++/Rasta/final /home/arch/Desktop/Codes/C++/Rasta/final/build /home/arch/Desktop/Codes/C++/Rasta/final/build /home/arch/Desktop/Codes/C++/Rasta/final/build/CMakeFiles/server_chess.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/server_chess.dir/depend
