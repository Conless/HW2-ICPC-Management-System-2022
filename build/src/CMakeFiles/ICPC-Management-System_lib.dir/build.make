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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build

# Include any dependencies generated for this target.
include src/CMakeFiles/ICPC-Management-System_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/ICPC-Management-System_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ICPC-Management-System_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ICPC-Management-System_lib.dir/flags.make

src/CMakeFiles/ICPC-Management-System_lib.dir/input.cc.o: src/CMakeFiles/ICPC-Management-System_lib.dir/flags.make
src/CMakeFiles/ICPC-Management-System_lib.dir/input.cc.o: ../src/input.cc
src/CMakeFiles/ICPC-Management-System_lib.dir/input.cc.o: src/CMakeFiles/ICPC-Management-System_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ICPC-Management-System_lib.dir/input.cc.o"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ICPC-Management-System_lib.dir/input.cc.o -MF CMakeFiles/ICPC-Management-System_lib.dir/input.cc.o.d -o CMakeFiles/ICPC-Management-System_lib.dir/input.cc.o -c /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/input.cc

src/CMakeFiles/ICPC-Management-System_lib.dir/input.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ICPC-Management-System_lib.dir/input.cc.i"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/input.cc > CMakeFiles/ICPC-Management-System_lib.dir/input.cc.i

src/CMakeFiles/ICPC-Management-System_lib.dir/input.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ICPC-Management-System_lib.dir/input.cc.s"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/input.cc -o CMakeFiles/ICPC-Management-System_lib.dir/input.cc.s

src/CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.o: src/CMakeFiles/ICPC-Management-System_lib.dir/flags.make
src/CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.o: src/CMakeFiles/ICPC-Management-System_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.o"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.o -MF CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.o.d -o CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.o -c /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/main.cpp

src/CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.i"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/main.cpp > CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.i

src/CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.s"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/main.cpp -o CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.s

src/CMakeFiles/ICPC-Management-System_lib.dir/team.cc.o: src/CMakeFiles/ICPC-Management-System_lib.dir/flags.make
src/CMakeFiles/ICPC-Management-System_lib.dir/team.cc.o: ../src/team.cc
src/CMakeFiles/ICPC-Management-System_lib.dir/team.cc.o: src/CMakeFiles/ICPC-Management-System_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/ICPC-Management-System_lib.dir/team.cc.o"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ICPC-Management-System_lib.dir/team.cc.o -MF CMakeFiles/ICPC-Management-System_lib.dir/team.cc.o.d -o CMakeFiles/ICPC-Management-System_lib.dir/team.cc.o -c /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/team.cc

src/CMakeFiles/ICPC-Management-System_lib.dir/team.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ICPC-Management-System_lib.dir/team.cc.i"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/team.cc > CMakeFiles/ICPC-Management-System_lib.dir/team.cc.i

src/CMakeFiles/ICPC-Management-System_lib.dir/team.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ICPC-Management-System_lib.dir/team.cc.s"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/team.cc -o CMakeFiles/ICPC-Management-System_lib.dir/team.cc.s

# Object files for target ICPC-Management-System_lib
ICPC__Management__System_lib_OBJECTS = \
"CMakeFiles/ICPC-Management-System_lib.dir/input.cc.o" \
"CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.o" \
"CMakeFiles/ICPC-Management-System_lib.dir/team.cc.o"

# External object files for target ICPC-Management-System_lib
ICPC__Management__System_lib_EXTERNAL_OBJECTS =

../out/lib/libICPC-Management-System_lib.a: src/CMakeFiles/ICPC-Management-System_lib.dir/input.cc.o
../out/lib/libICPC-Management-System_lib.a: src/CMakeFiles/ICPC-Management-System_lib.dir/main.cpp.o
../out/lib/libICPC-Management-System_lib.a: src/CMakeFiles/ICPC-Management-System_lib.dir/team.cc.o
../out/lib/libICPC-Management-System_lib.a: src/CMakeFiles/ICPC-Management-System_lib.dir/build.make
../out/lib/libICPC-Management-System_lib.a: src/CMakeFiles/ICPC-Management-System_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../out/lib/libICPC-Management-System_lib.a"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ICPC-Management-System_lib.dir/cmake_clean_target.cmake
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ICPC-Management-System_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ICPC-Management-System_lib.dir/build: ../out/lib/libICPC-Management-System_lib.a
.PHONY : src/CMakeFiles/ICPC-Management-System_lib.dir/build

src/CMakeFiles/ICPC-Management-System_lib.dir/clean:
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ICPC-Management-System_lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ICPC-Management-System_lib.dir/clean

src/CMakeFiles/ICPC-Management-System_lib.dir/depend:
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022 /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/src/CMakeFiles/ICPC-Management-System_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ICPC-Management-System_lib.dir/depend

