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
CMAKE_BINARY_DIR = /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/server-test3.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/server-test3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server-test3.dir/flags.make

CMakeFiles/server-test3.dir/Sources/server-test3.cc.o: CMakeFiles/server-test3.dir/flags.make
CMakeFiles/server-test3.dir/Sources/server-test3.cc.o: ../Sources/server-test3.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server-test3.dir/Sources/server-test3.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server-test3.dir/Sources/server-test3.cc.o -c /home/gaosm/Downloads/dev-1/inforefiner-model/Sources/server-test3.cc

CMakeFiles/server-test3.dir/Sources/server-test3.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server-test3.dir/Sources/server-test3.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaosm/Downloads/dev-1/inforefiner-model/Sources/server-test3.cc > CMakeFiles/server-test3.dir/Sources/server-test3.cc.i

CMakeFiles/server-test3.dir/Sources/server-test3.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server-test3.dir/Sources/server-test3.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaosm/Downloads/dev-1/inforefiner-model/Sources/server-test3.cc -o CMakeFiles/server-test3.dir/Sources/server-test3.cc.s

CMakeFiles/server-test3.dir/Lib/Slog.cc.o: CMakeFiles/server-test3.dir/flags.make
CMakeFiles/server-test3.dir/Lib/Slog.cc.o: ../Lib/Slog.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server-test3.dir/Lib/Slog.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server-test3.dir/Lib/Slog.cc.o -c /home/gaosm/Downloads/dev-1/inforefiner-model/Lib/Slog.cc

CMakeFiles/server-test3.dir/Lib/Slog.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server-test3.dir/Lib/Slog.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaosm/Downloads/dev-1/inforefiner-model/Lib/Slog.cc > CMakeFiles/server-test3.dir/Lib/Slog.cc.i

CMakeFiles/server-test3.dir/Lib/Slog.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server-test3.dir/Lib/Slog.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaosm/Downloads/dev-1/inforefiner-model/Lib/Slog.cc -o CMakeFiles/server-test3.dir/Lib/Slog.cc.s

CMakeFiles/server-test3.dir/model/Abnormal.cc.o: CMakeFiles/server-test3.dir/flags.make
CMakeFiles/server-test3.dir/model/Abnormal.cc.o: ../model/Abnormal.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server-test3.dir/model/Abnormal.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server-test3.dir/model/Abnormal.cc.o -c /home/gaosm/Downloads/dev-1/inforefiner-model/model/Abnormal.cc

CMakeFiles/server-test3.dir/model/Abnormal.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server-test3.dir/model/Abnormal.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaosm/Downloads/dev-1/inforefiner-model/model/Abnormal.cc > CMakeFiles/server-test3.dir/model/Abnormal.cc.i

CMakeFiles/server-test3.dir/model/Abnormal.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server-test3.dir/model/Abnormal.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaosm/Downloads/dev-1/inforefiner-model/model/Abnormal.cc -o CMakeFiles/server-test3.dir/model/Abnormal.cc.s

CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.o: CMakeFiles/server-test3.dir/flags.make
CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.o: ../model/LightGBMPredict.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.o -c /home/gaosm/Downloads/dev-1/inforefiner-model/model/LightGBMPredict.cc

CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaosm/Downloads/dev-1/inforefiner-model/model/LightGBMPredict.cc > CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.i

CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaosm/Downloads/dev-1/inforefiner-model/model/LightGBMPredict.cc -o CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.s

CMakeFiles/server-test3.dir/model/LinearRegression.cc.o: CMakeFiles/server-test3.dir/flags.make
CMakeFiles/server-test3.dir/model/LinearRegression.cc.o: ../model/LinearRegression.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server-test3.dir/model/LinearRegression.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server-test3.dir/model/LinearRegression.cc.o -c /home/gaosm/Downloads/dev-1/inforefiner-model/model/LinearRegression.cc

CMakeFiles/server-test3.dir/model/LinearRegression.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server-test3.dir/model/LinearRegression.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaosm/Downloads/dev-1/inforefiner-model/model/LinearRegression.cc > CMakeFiles/server-test3.dir/model/LinearRegression.cc.i

CMakeFiles/server-test3.dir/model/LinearRegression.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server-test3.dir/model/LinearRegression.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaosm/Downloads/dev-1/inforefiner-model/model/LinearRegression.cc -o CMakeFiles/server-test3.dir/model/LinearRegression.cc.s

CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.o: CMakeFiles/server-test3.dir/flags.make
CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.o: ../Pool/ThreadPool.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.o -c /home/gaosm/Downloads/dev-1/inforefiner-model/Pool/ThreadPool.cc

CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaosm/Downloads/dev-1/inforefiner-model/Pool/ThreadPool.cc > CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.i

CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaosm/Downloads/dev-1/inforefiner-model/Pool/ThreadPool.cc -o CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.s

CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.o: CMakeFiles/server-test3.dir/flags.make
CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.o: ../dict/dynamic_dict.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.o -c /home/gaosm/Downloads/dev-1/inforefiner-model/dict/dynamic_dict.cc

CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaosm/Downloads/dev-1/inforefiner-model/dict/dynamic_dict.cc > CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.i

CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaosm/Downloads/dev-1/inforefiner-model/dict/dynamic_dict.cc -o CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.s

CMakeFiles/server-test3.dir/dict/global_data.cc.o: CMakeFiles/server-test3.dir/flags.make
CMakeFiles/server-test3.dir/dict/global_data.cc.o: ../dict/global_data.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/server-test3.dir/dict/global_data.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server-test3.dir/dict/global_data.cc.o -c /home/gaosm/Downloads/dev-1/inforefiner-model/dict/global_data.cc

CMakeFiles/server-test3.dir/dict/global_data.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server-test3.dir/dict/global_data.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaosm/Downloads/dev-1/inforefiner-model/dict/global_data.cc > CMakeFiles/server-test3.dir/dict/global_data.cc.i

CMakeFiles/server-test3.dir/dict/global_data.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server-test3.dir/dict/global_data.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaosm/Downloads/dev-1/inforefiner-model/dict/global_data.cc -o CMakeFiles/server-test3.dir/dict/global_data.cc.s

# Object files for target server-test3
server__test3_OBJECTS = \
"CMakeFiles/server-test3.dir/Sources/server-test3.cc.o" \
"CMakeFiles/server-test3.dir/Lib/Slog.cc.o" \
"CMakeFiles/server-test3.dir/model/Abnormal.cc.o" \
"CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.o" \
"CMakeFiles/server-test3.dir/model/LinearRegression.cc.o" \
"CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.o" \
"CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.o" \
"CMakeFiles/server-test3.dir/dict/global_data.cc.o"

# External object files for target server-test3
server__test3_EXTERNAL_OBJECTS =

bin/server-test3: CMakeFiles/server-test3.dir/Sources/server-test3.cc.o
bin/server-test3: CMakeFiles/server-test3.dir/Lib/Slog.cc.o
bin/server-test3: CMakeFiles/server-test3.dir/model/Abnormal.cc.o
bin/server-test3: CMakeFiles/server-test3.dir/model/LightGBMPredict.cc.o
bin/server-test3: CMakeFiles/server-test3.dir/model/LinearRegression.cc.o
bin/server-test3: CMakeFiles/server-test3.dir/Pool/ThreadPool.cc.o
bin/server-test3: CMakeFiles/server-test3.dir/dict/dynamic_dict.cc.o
bin/server-test3: CMakeFiles/server-test3.dir/dict/global_data.cc.o
bin/server-test3: CMakeFiles/server-test3.dir/build.make
bin/server-test3: /usr/local/lib/lib_lightgbm.so
bin/server-test3: /usr/lib/python3.6/config-3.6m-x86_64-linux-gnu/libpython3.6.so
bin/server-test3: /usr/lib/python3.6/config-3.6m-x86_64-linux-gnu/libpython3.6m.so
bin/server-test3: CMakeFiles/server-test3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable bin/server-test3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server-test3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server-test3.dir/build: bin/server-test3
.PHONY : CMakeFiles/server-test3.dir/build

CMakeFiles/server-test3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server-test3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server-test3.dir/clean

CMakeFiles/server-test3.dir/depend:
	cd /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gaosm/Downloads/dev-1/inforefiner-model /home/gaosm/Downloads/dev-1/inforefiner-model /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release /home/gaosm/Downloads/dev-1/inforefiner-model/cmake-build-release/CMakeFiles/server-test3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server-test3.dir/depend

