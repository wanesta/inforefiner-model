# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /home/gaosm/Downloads/cmake-3.22.1/bin/cmake

# The command to remove a file.
RM = /home/gaosm/Downloads/cmake-3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gaosm/Downloads/dev-1/inforefiner-model

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug

# Include any dependencies generated for this target.
include LOGLIB/CMakeFiles/Slog_static.dir/depend.make
# Include the progress variables for this target.
include LOGLIB/CMakeFiles/Slog_static.dir/progress.make

# Include the compile flags for this target's objects.
include LOGLIB/CMakeFiles/Slog_static.dir/flags.make

LOGLIB/CMakeFiles/Slog_static.dir/Slog.cc.o: LOGLIB/CMakeFiles/Slog_static.dir/flags.make
LOGLIB/CMakeFiles/Slog_static.dir/Slog.cc.o: ../Lib/Slog.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object LOGLIB/CMakeFiles/Slog_static.dir/Slog.cc.o"
	cd /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug/LOGLIB && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Slog_static.dir/Slog.cc.o -c /home/gaosm/Downloads/dev-1/inforefiner-model/Lib/Slog.cc

LOGLIB/CMakeFiles/Slog_static.dir/Slog.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Slog_static.dir/Slog.cc.i"
	cd /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug/LOGLIB && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaosm/Downloads/dev-1/inforefiner-model/Lib/Slog.cc > CMakeFiles/Slog_static.dir/Slog.cc.i

LOGLIB/CMakeFiles/Slog_static.dir/Slog.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Slog_static.dir/Slog.cc.s"
	cd /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug/LOGLIB && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaosm/Downloads/dev-1/inforefiner-model/Lib/Slog.cc -o CMakeFiles/Slog_static.dir/Slog.cc.s

# Object files for target Slog_static
Slog_static_OBJECTS = \
"CMakeFiles/Slog_static.dir/Slog.cc.o"

# External object files for target Slog_static
Slog_static_EXTERNAL_OBJECTS =

LOGLIB/libSlog.a: LOGLIB/CMakeFiles/Slog_static.dir/Slog.cc.o
LOGLIB/libSlog.a: LOGLIB/CMakeFiles/Slog_static.dir/build.make
LOGLIB/libSlog.a: LOGLIB/CMakeFiles/Slog_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libSlog.a"
	cd /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug/LOGLIB && $(CMAKE_COMMAND) -P CMakeFiles/Slog_static.dir/cmake_clean_target.cmake
	cd /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug/LOGLIB && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Slog_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
LOGLIB/CMakeFiles/Slog_static.dir/build: LOGLIB/libSlog.a
.PHONY : LOGLIB/CMakeFiles/Slog_static.dir/build

LOGLIB/CMakeFiles/Slog_static.dir/clean:
	cd /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug/LOGLIB && $(CMAKE_COMMAND) -P CMakeFiles/Slog_static.dir/cmake_clean.cmake
.PHONY : LOGLIB/CMakeFiles/Slog_static.dir/clean

LOGLIB/CMakeFiles/Slog_static.dir/depend:
	cd /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gaosm/Downloads/dev-1/inforefiner-model /home/gaosm/Downloads/dev-1/inforefiner-model/Lib /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug/LOGLIB /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-debug/LOGLIB/CMakeFiles/Slog_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : LOGLIB/CMakeFiles/Slog_static.dir/depend

