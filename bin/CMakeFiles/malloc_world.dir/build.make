# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lin/CLionProjects/3a/malloc_world

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lin/CLionProjects/3a/malloc_world/bin

# Include any dependencies generated for this target.
include CMakeFiles/malloc_world.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/malloc_world.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/malloc_world.dir/flags.make

CMakeFiles/malloc_world.dir/main.c.o: CMakeFiles/malloc_world.dir/flags.make
CMakeFiles/malloc_world.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/malloc_world.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_world.dir/main.c.o -c /Users/lin/CLionProjects/3a/malloc_world/main.c

CMakeFiles/malloc_world.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_world.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lin/CLionProjects/3a/malloc_world/main.c > CMakeFiles/malloc_world.dir/main.c.i

CMakeFiles/malloc_world.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_world.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lin/CLionProjects/3a/malloc_world/main.c -o CMakeFiles/malloc_world.dir/main.c.s

CMakeFiles/malloc_world.dir/sources/game.c.o: CMakeFiles/malloc_world.dir/flags.make
CMakeFiles/malloc_world.dir/sources/game.c.o: ../sources/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/malloc_world.dir/sources/game.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_world.dir/sources/game.c.o -c /Users/lin/CLionProjects/3a/malloc_world/sources/game.c

CMakeFiles/malloc_world.dir/sources/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_world.dir/sources/game.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lin/CLionProjects/3a/malloc_world/sources/game.c > CMakeFiles/malloc_world.dir/sources/game.c.i

CMakeFiles/malloc_world.dir/sources/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_world.dir/sources/game.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lin/CLionProjects/3a/malloc_world/sources/game.c -o CMakeFiles/malloc_world.dir/sources/game.c.s

CMakeFiles/malloc_world.dir/sources/initialization.c.o: CMakeFiles/malloc_world.dir/flags.make
CMakeFiles/malloc_world.dir/sources/initialization.c.o: ../sources/initialization.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/malloc_world.dir/sources/initialization.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_world.dir/sources/initialization.c.o -c /Users/lin/CLionProjects/3a/malloc_world/sources/initialization.c

CMakeFiles/malloc_world.dir/sources/initialization.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_world.dir/sources/initialization.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lin/CLionProjects/3a/malloc_world/sources/initialization.c > CMakeFiles/malloc_world.dir/sources/initialization.c.i

CMakeFiles/malloc_world.dir/sources/initialization.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_world.dir/sources/initialization.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lin/CLionProjects/3a/malloc_world/sources/initialization.c -o CMakeFiles/malloc_world.dir/sources/initialization.c.s

CMakeFiles/malloc_world.dir/sources/menu.c.o: CMakeFiles/malloc_world.dir/flags.make
CMakeFiles/malloc_world.dir/sources/menu.c.o: ../sources/menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/malloc_world.dir/sources/menu.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_world.dir/sources/menu.c.o -c /Users/lin/CLionProjects/3a/malloc_world/sources/menu.c

CMakeFiles/malloc_world.dir/sources/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_world.dir/sources/menu.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lin/CLionProjects/3a/malloc_world/sources/menu.c > CMakeFiles/malloc_world.dir/sources/menu.c.i

CMakeFiles/malloc_world.dir/sources/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_world.dir/sources/menu.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lin/CLionProjects/3a/malloc_world/sources/menu.c -o CMakeFiles/malloc_world.dir/sources/menu.c.s

CMakeFiles/malloc_world.dir/sources/newGame.c.o: CMakeFiles/malloc_world.dir/flags.make
CMakeFiles/malloc_world.dir/sources/newGame.c.o: ../sources/newGame.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/malloc_world.dir/sources/newGame.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_world.dir/sources/newGame.c.o -c /Users/lin/CLionProjects/3a/malloc_world/sources/newGame.c

CMakeFiles/malloc_world.dir/sources/newGame.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_world.dir/sources/newGame.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lin/CLionProjects/3a/malloc_world/sources/newGame.c > CMakeFiles/malloc_world.dir/sources/newGame.c.i

CMakeFiles/malloc_world.dir/sources/newGame.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_world.dir/sources/newGame.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lin/CLionProjects/3a/malloc_world/sources/newGame.c -o CMakeFiles/malloc_world.dir/sources/newGame.c.s

CMakeFiles/malloc_world.dir/sources/display.c.o: CMakeFiles/malloc_world.dir/flags.make
CMakeFiles/malloc_world.dir/sources/display.c.o: ../sources/display.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/malloc_world.dir/sources/display.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_world.dir/sources/display.c.o -c /Users/lin/CLionProjects/3a/malloc_world/sources/display.c

CMakeFiles/malloc_world.dir/sources/display.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_world.dir/sources/display.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lin/CLionProjects/3a/malloc_world/sources/display.c > CMakeFiles/malloc_world.dir/sources/display.c.i

CMakeFiles/malloc_world.dir/sources/display.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_world.dir/sources/display.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lin/CLionProjects/3a/malloc_world/sources/display.c -o CMakeFiles/malloc_world.dir/sources/display.c.s

CMakeFiles/malloc_world.dir/sources/npc.c.o: CMakeFiles/malloc_world.dir/flags.make
CMakeFiles/malloc_world.dir/sources/npc.c.o: ../sources/npc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/malloc_world.dir/sources/npc.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_world.dir/sources/npc.c.o -c /Users/lin/CLionProjects/3a/malloc_world/sources/npc.c

CMakeFiles/malloc_world.dir/sources/npc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_world.dir/sources/npc.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lin/CLionProjects/3a/malloc_world/sources/npc.c > CMakeFiles/malloc_world.dir/sources/npc.c.i

CMakeFiles/malloc_world.dir/sources/npc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_world.dir/sources/npc.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lin/CLionProjects/3a/malloc_world/sources/npc.c -o CMakeFiles/malloc_world.dir/sources/npc.c.s

CMakeFiles/malloc_world.dir/sources/respawn.c.o: CMakeFiles/malloc_world.dir/flags.make
CMakeFiles/malloc_world.dir/sources/respawn.c.o: ../sources/respawn.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/malloc_world.dir/sources/respawn.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_world.dir/sources/respawn.c.o -c /Users/lin/CLionProjects/3a/malloc_world/sources/respawn.c

CMakeFiles/malloc_world.dir/sources/respawn.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_world.dir/sources/respawn.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lin/CLionProjects/3a/malloc_world/sources/respawn.c > CMakeFiles/malloc_world.dir/sources/respawn.c.i

CMakeFiles/malloc_world.dir/sources/respawn.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_world.dir/sources/respawn.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lin/CLionProjects/3a/malloc_world/sources/respawn.c -o CMakeFiles/malloc_world.dir/sources/respawn.c.s

CMakeFiles/malloc_world.dir/sources/harvest.c.o: CMakeFiles/malloc_world.dir/flags.make
CMakeFiles/malloc_world.dir/sources/harvest.c.o: ../sources/harvest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/malloc_world.dir/sources/harvest.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc_world.dir/sources/harvest.c.o -c /Users/lin/CLionProjects/3a/malloc_world/sources/harvest.c

CMakeFiles/malloc_world.dir/sources/harvest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_world.dir/sources/harvest.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lin/CLionProjects/3a/malloc_world/sources/harvest.c > CMakeFiles/malloc_world.dir/sources/harvest.c.i

CMakeFiles/malloc_world.dir/sources/harvest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_world.dir/sources/harvest.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lin/CLionProjects/3a/malloc_world/sources/harvest.c -o CMakeFiles/malloc_world.dir/sources/harvest.c.s

# Object files for target malloc_world
malloc_world_OBJECTS = \
"CMakeFiles/malloc_world.dir/main.c.o" \
"CMakeFiles/malloc_world.dir/sources/game.c.o" \
"CMakeFiles/malloc_world.dir/sources/initialization.c.o" \
"CMakeFiles/malloc_world.dir/sources/menu.c.o" \
"CMakeFiles/malloc_world.dir/sources/newGame.c.o" \
"CMakeFiles/malloc_world.dir/sources/display.c.o" \
"CMakeFiles/malloc_world.dir/sources/npc.c.o" \
"CMakeFiles/malloc_world.dir/sources/respawn.c.o" \
"CMakeFiles/malloc_world.dir/sources/harvest.c.o"

# External object files for target malloc_world
malloc_world_EXTERNAL_OBJECTS =

malloc_world: CMakeFiles/malloc_world.dir/main.c.o
malloc_world: CMakeFiles/malloc_world.dir/sources/game.c.o
malloc_world: CMakeFiles/malloc_world.dir/sources/initialization.c.o
malloc_world: CMakeFiles/malloc_world.dir/sources/menu.c.o
malloc_world: CMakeFiles/malloc_world.dir/sources/newGame.c.o
malloc_world: CMakeFiles/malloc_world.dir/sources/display.c.o
malloc_world: CMakeFiles/malloc_world.dir/sources/npc.c.o
malloc_world: CMakeFiles/malloc_world.dir/sources/respawn.c.o
malloc_world: CMakeFiles/malloc_world.dir/sources/harvest.c.o
malloc_world: CMakeFiles/malloc_world.dir/build.make
malloc_world: CMakeFiles/malloc_world.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable malloc_world"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/malloc_world.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/malloc_world.dir/build: malloc_world
.PHONY : CMakeFiles/malloc_world.dir/build

CMakeFiles/malloc_world.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/malloc_world.dir/cmake_clean.cmake
.PHONY : CMakeFiles/malloc_world.dir/clean

CMakeFiles/malloc_world.dir/depend:
	cd /Users/lin/CLionProjects/3a/malloc_world/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lin/CLionProjects/3a/malloc_world /Users/lin/CLionProjects/3a/malloc_world /Users/lin/CLionProjects/3a/malloc_world/bin /Users/lin/CLionProjects/3a/malloc_world/bin /Users/lin/CLionProjects/3a/malloc_world/bin/CMakeFiles/malloc_world.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/malloc_world.dir/depend

