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
include CMakeFiles/icpc-runtime.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/icpc-runtime.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/icpc-runtime.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/icpc-runtime.dir/flags.make

CMakeFiles/icpc-runtime.dir/src/main.cpp.o: CMakeFiles/icpc-runtime.dir/flags.make
CMakeFiles/icpc-runtime.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/icpc-runtime.dir/src/main.cpp.o: CMakeFiles/icpc-runtime.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/icpc-runtime.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/icpc-runtime.dir/src/main.cpp.o -MF CMakeFiles/icpc-runtime.dir/src/main.cpp.o.d -o CMakeFiles/icpc-runtime.dir/src/main.cpp.o -c /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/main.cpp

CMakeFiles/icpc-runtime.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/icpc-runtime.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/main.cpp > CMakeFiles/icpc-runtime.dir/src/main.cpp.i

CMakeFiles/icpc-runtime.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/icpc-runtime.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/src/main.cpp -o CMakeFiles/icpc-runtime.dir/src/main.cpp.s

# Object files for target icpc-runtime
icpc__runtime_OBJECTS = \
"CMakeFiles/icpc-runtime.dir/src/main.cpp.o"

# External object files for target icpc-runtime
icpc__runtime_EXTERNAL_OBJECTS =

libicpc-runtime.a: CMakeFiles/icpc-runtime.dir/src/main.cpp.o
libicpc-runtime.a: CMakeFiles/icpc-runtime.dir/build.make
libicpc-runtime.a: CMakeFiles/icpc-runtime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libicpc-runtime.a"
	$(CMAKE_COMMAND) -P CMakeFiles/icpc-runtime.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/icpc-runtime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/icpc-runtime.dir/build: libicpc-runtime.a
.PHONY : CMakeFiles/icpc-runtime.dir/build

CMakeFiles/icpc-runtime.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/icpc-runtime.dir/cmake_clean.cmake
.PHONY : CMakeFiles/icpc-runtime.dir/clean

CMakeFiles/icpc-runtime.dir/depend:
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022 /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022 /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW2-ICPC-Management-System-2022/build/CMakeFiles/icpc-runtime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/icpc-runtime.dir/depend
