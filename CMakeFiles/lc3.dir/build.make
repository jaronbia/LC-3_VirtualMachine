# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jaronb/Projects/LC-3_VirtualMachine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jaronb/Projects/LC-3_VirtualMachine

# Include any dependencies generated for this target.
include CMakeFiles/lc3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lc3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lc3.dir/flags.make

CMakeFiles/lc3.dir/src/Buffer.cpp.o: CMakeFiles/lc3.dir/flags.make
CMakeFiles/lc3.dir/src/Buffer.cpp.o: src/Buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaronb/Projects/LC-3_VirtualMachine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lc3.dir/src/Buffer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lc3.dir/src/Buffer.cpp.o -c /Users/jaronb/Projects/LC-3_VirtualMachine/src/Buffer.cpp

CMakeFiles/lc3.dir/src/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc3.dir/src/Buffer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaronb/Projects/LC-3_VirtualMachine/src/Buffer.cpp > CMakeFiles/lc3.dir/src/Buffer.cpp.i

CMakeFiles/lc3.dir/src/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc3.dir/src/Buffer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaronb/Projects/LC-3_VirtualMachine/src/Buffer.cpp -o CMakeFiles/lc3.dir/src/Buffer.cpp.s

CMakeFiles/lc3.dir/src/UnixBuffer.cpp.o: CMakeFiles/lc3.dir/flags.make
CMakeFiles/lc3.dir/src/UnixBuffer.cpp.o: src/UnixBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaronb/Projects/LC-3_VirtualMachine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lc3.dir/src/UnixBuffer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lc3.dir/src/UnixBuffer.cpp.o -c /Users/jaronb/Projects/LC-3_VirtualMachine/src/UnixBuffer.cpp

CMakeFiles/lc3.dir/src/UnixBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc3.dir/src/UnixBuffer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaronb/Projects/LC-3_VirtualMachine/src/UnixBuffer.cpp > CMakeFiles/lc3.dir/src/UnixBuffer.cpp.i

CMakeFiles/lc3.dir/src/UnixBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc3.dir/src/UnixBuffer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaronb/Projects/LC-3_VirtualMachine/src/UnixBuffer.cpp -o CMakeFiles/lc3.dir/src/UnixBuffer.cpp.s

CMakeFiles/lc3.dir/src/VirtualMachine.cpp.o: CMakeFiles/lc3.dir/flags.make
CMakeFiles/lc3.dir/src/VirtualMachine.cpp.o: src/VirtualMachine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaronb/Projects/LC-3_VirtualMachine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lc3.dir/src/VirtualMachine.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lc3.dir/src/VirtualMachine.cpp.o -c /Users/jaronb/Projects/LC-3_VirtualMachine/src/VirtualMachine.cpp

CMakeFiles/lc3.dir/src/VirtualMachine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc3.dir/src/VirtualMachine.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaronb/Projects/LC-3_VirtualMachine/src/VirtualMachine.cpp > CMakeFiles/lc3.dir/src/VirtualMachine.cpp.i

CMakeFiles/lc3.dir/src/VirtualMachine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc3.dir/src/VirtualMachine.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaronb/Projects/LC-3_VirtualMachine/src/VirtualMachine.cpp -o CMakeFiles/lc3.dir/src/VirtualMachine.cpp.s

CMakeFiles/lc3.dir/src/WinBuffer.cpp.o: CMakeFiles/lc3.dir/flags.make
CMakeFiles/lc3.dir/src/WinBuffer.cpp.o: src/WinBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaronb/Projects/LC-3_VirtualMachine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lc3.dir/src/WinBuffer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lc3.dir/src/WinBuffer.cpp.o -c /Users/jaronb/Projects/LC-3_VirtualMachine/src/WinBuffer.cpp

CMakeFiles/lc3.dir/src/WinBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc3.dir/src/WinBuffer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaronb/Projects/LC-3_VirtualMachine/src/WinBuffer.cpp > CMakeFiles/lc3.dir/src/WinBuffer.cpp.i

CMakeFiles/lc3.dir/src/WinBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc3.dir/src/WinBuffer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaronb/Projects/LC-3_VirtualMachine/src/WinBuffer.cpp -o CMakeFiles/lc3.dir/src/WinBuffer.cpp.s

CMakeFiles/lc3.dir/src/main.cpp.o: CMakeFiles/lc3.dir/flags.make
CMakeFiles/lc3.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaronb/Projects/LC-3_VirtualMachine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lc3.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lc3.dir/src/main.cpp.o -c /Users/jaronb/Projects/LC-3_VirtualMachine/src/main.cpp

CMakeFiles/lc3.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lc3.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaronb/Projects/LC-3_VirtualMachine/src/main.cpp > CMakeFiles/lc3.dir/src/main.cpp.i

CMakeFiles/lc3.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lc3.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaronb/Projects/LC-3_VirtualMachine/src/main.cpp -o CMakeFiles/lc3.dir/src/main.cpp.s

# Object files for target lc3
lc3_OBJECTS = \
"CMakeFiles/lc3.dir/src/Buffer.cpp.o" \
"CMakeFiles/lc3.dir/src/UnixBuffer.cpp.o" \
"CMakeFiles/lc3.dir/src/VirtualMachine.cpp.o" \
"CMakeFiles/lc3.dir/src/WinBuffer.cpp.o" \
"CMakeFiles/lc3.dir/src/main.cpp.o"

# External object files for target lc3
lc3_EXTERNAL_OBJECTS =

lc3: CMakeFiles/lc3.dir/src/Buffer.cpp.o
lc3: CMakeFiles/lc3.dir/src/UnixBuffer.cpp.o
lc3: CMakeFiles/lc3.dir/src/VirtualMachine.cpp.o
lc3: CMakeFiles/lc3.dir/src/WinBuffer.cpp.o
lc3: CMakeFiles/lc3.dir/src/main.cpp.o
lc3: CMakeFiles/lc3.dir/build.make
lc3: CMakeFiles/lc3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaronb/Projects/LC-3_VirtualMachine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable lc3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lc3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lc3.dir/build: lc3

.PHONY : CMakeFiles/lc3.dir/build

CMakeFiles/lc3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lc3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lc3.dir/clean

CMakeFiles/lc3.dir/depend:
	cd /Users/jaronb/Projects/LC-3_VirtualMachine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaronb/Projects/LC-3_VirtualMachine /Users/jaronb/Projects/LC-3_VirtualMachine /Users/jaronb/Projects/LC-3_VirtualMachine /Users/jaronb/Projects/LC-3_VirtualMachine /Users/jaronb/Projects/LC-3_VirtualMachine/CMakeFiles/lc3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lc3.dir/depend

