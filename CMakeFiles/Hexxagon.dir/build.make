# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/walker2/Projects/Hexxagon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/walker2/Projects/Hexxagon

# Include any dependencies generated for this target.
include CMakeFiles/Hexxagon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Hexxagon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hexxagon.dir/flags.make

CMakeFiles/Hexxagon.dir/main.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Hexxagon.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/main.cpp.o -c /home/walker2/Projects/Hexxagon/main.cpp

CMakeFiles/Hexxagon.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/main.cpp > CMakeFiles/Hexxagon.dir/main.cpp.i

CMakeFiles/Hexxagon.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/main.cpp -o CMakeFiles/Hexxagon.dir/main.cpp.s

CMakeFiles/Hexxagon.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/main.cpp.o.requires

CMakeFiles/Hexxagon.dir/main.cpp.o.provides: CMakeFiles/Hexxagon.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/main.cpp.o.provides

CMakeFiles/Hexxagon.dir/main.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/main.cpp.o


CMakeFiles/Hexxagon.dir/Game.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/Game.cpp.o: Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Hexxagon.dir/Game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/Game.cpp.o -c /home/walker2/Projects/Hexxagon/Game.cpp

CMakeFiles/Hexxagon.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/Game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/Game.cpp > CMakeFiles/Hexxagon.dir/Game.cpp.i

CMakeFiles/Hexxagon.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/Game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/Game.cpp -o CMakeFiles/Hexxagon.dir/Game.cpp.s

CMakeFiles/Hexxagon.dir/Game.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/Game.cpp.o.requires

CMakeFiles/Hexxagon.dir/Game.cpp.o.provides: CMakeFiles/Hexxagon.dir/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/Game.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/Game.cpp.o.provides

CMakeFiles/Hexxagon.dir/Game.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/Game.cpp.o


CMakeFiles/Hexxagon.dir/Board.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/Board.cpp.o: Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Hexxagon.dir/Board.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/Board.cpp.o -c /home/walker2/Projects/Hexxagon/Board.cpp

CMakeFiles/Hexxagon.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/Board.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/Board.cpp > CMakeFiles/Hexxagon.dir/Board.cpp.i

CMakeFiles/Hexxagon.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/Board.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/Board.cpp -o CMakeFiles/Hexxagon.dir/Board.cpp.s

CMakeFiles/Hexxagon.dir/Board.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/Board.cpp.o.requires

CMakeFiles/Hexxagon.dir/Board.cpp.o.provides: CMakeFiles/Hexxagon.dir/Board.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/Board.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/Board.cpp.o.provides

CMakeFiles/Hexxagon.dir/Board.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/Board.cpp.o


CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o: States/Intro_State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o -c /home/walker2/Projects/Hexxagon/States/Intro_State.cpp

CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/States/Intro_State.cpp > CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.i

CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/States/Intro_State.cpp -o CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.s

CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o.requires

CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o.provides: CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o.provides

CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o


CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o: States/Menu_State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o -c /home/walker2/Projects/Hexxagon/States/Menu_State.cpp

CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/States/Menu_State.cpp > CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.i

CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/States/Menu_State.cpp -o CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.s

CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o.requires

CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o.provides: CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o.provides

CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o


CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o: States/Multiplayer_State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o -c /home/walker2/Projects/Hexxagon/States/Multiplayer_State.cpp

CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/States/Multiplayer_State.cpp > CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.i

CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/States/Multiplayer_State.cpp -o CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.s

CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o.requires

CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o.provides: CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o.provides

CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o


CMakeFiles/Hexxagon.dir/Player.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/Player.cpp.o: Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Hexxagon.dir/Player.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/Player.cpp.o -c /home/walker2/Projects/Hexxagon/Player.cpp

CMakeFiles/Hexxagon.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/Player.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/Player.cpp > CMakeFiles/Hexxagon.dir/Player.cpp.i

CMakeFiles/Hexxagon.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/Player.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/Player.cpp -o CMakeFiles/Hexxagon.dir/Player.cpp.s

CMakeFiles/Hexxagon.dir/Player.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/Player.cpp.o.requires

CMakeFiles/Hexxagon.dir/Player.cpp.o.provides: CMakeFiles/Hexxagon.dir/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/Player.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/Player.cpp.o.provides

CMakeFiles/Hexxagon.dir/Player.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/Player.cpp.o


CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o: ResourceManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o -c /home/walker2/Projects/Hexxagon/ResourceManager.cpp

CMakeFiles/Hexxagon.dir/ResourceManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/ResourceManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/ResourceManager.cpp > CMakeFiles/Hexxagon.dir/ResourceManager.cpp.i

CMakeFiles/Hexxagon.dir/ResourceManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/ResourceManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/ResourceManager.cpp -o CMakeFiles/Hexxagon.dir/ResourceManager.cpp.s

CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o.requires

CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o.provides: CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o.provides

CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o


CMakeFiles/Hexxagon.dir/GameGUI.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/GameGUI.cpp.o: GameGUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Hexxagon.dir/GameGUI.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/GameGUI.cpp.o -c /home/walker2/Projects/Hexxagon/GameGUI.cpp

CMakeFiles/Hexxagon.dir/GameGUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/GameGUI.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/GameGUI.cpp > CMakeFiles/Hexxagon.dir/GameGUI.cpp.i

CMakeFiles/Hexxagon.dir/GameGUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/GameGUI.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/GameGUI.cpp -o CMakeFiles/Hexxagon.dir/GameGUI.cpp.s

CMakeFiles/Hexxagon.dir/GameGUI.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/GameGUI.cpp.o.requires

CMakeFiles/Hexxagon.dir/GameGUI.cpp.o.provides: CMakeFiles/Hexxagon.dir/GameGUI.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/GameGUI.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/GameGUI.cpp.o.provides

CMakeFiles/Hexxagon.dir/GameGUI.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/GameGUI.cpp.o


CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o: States/Difficulty_Singleplayer_State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o -c /home/walker2/Projects/Hexxagon/States/Difficulty_Singleplayer_State.cpp

CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/States/Difficulty_Singleplayer_State.cpp > CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.i

CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/States/Difficulty_Singleplayer_State.cpp -o CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.s

CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o.requires

CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o.provides: CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o.provides

CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o


CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o: CMakeFiles/Hexxagon.dir/flags.make
CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o: States/Difficulty_Computerwars_State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o -c /home/walker2/Projects/Hexxagon/States/Difficulty_Computerwars_State.cpp

CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/walker2/Projects/Hexxagon/States/Difficulty_Computerwars_State.cpp > CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.i

CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/walker2/Projects/Hexxagon/States/Difficulty_Computerwars_State.cpp -o CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.s

CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o.requires:

.PHONY : CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o.requires

CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o.provides: CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o.requires
	$(MAKE) -f CMakeFiles/Hexxagon.dir/build.make CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o.provides.build
.PHONY : CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o.provides

CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o.provides.build: CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o


# Object files for target Hexxagon
Hexxagon_OBJECTS = \
"CMakeFiles/Hexxagon.dir/main.cpp.o" \
"CMakeFiles/Hexxagon.dir/Game.cpp.o" \
"CMakeFiles/Hexxagon.dir/Board.cpp.o" \
"CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o" \
"CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o" \
"CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o" \
"CMakeFiles/Hexxagon.dir/Player.cpp.o" \
"CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o" \
"CMakeFiles/Hexxagon.dir/GameGUI.cpp.o" \
"CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o" \
"CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o"

# External object files for target Hexxagon
Hexxagon_EXTERNAL_OBJECTS =

Hexxagon: CMakeFiles/Hexxagon.dir/main.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/Game.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/Board.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/Player.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/GameGUI.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o
Hexxagon: CMakeFiles/Hexxagon.dir/build.make
Hexxagon: /usr/lib/i386-linux-gnu/libsfml-window.so
Hexxagon: /usr/lib/i386-linux-gnu/libsfml-system.so
Hexxagon: /usr/lib/i386-linux-gnu/libsfml-graphics.so
Hexxagon: /usr/lib/i386-linux-gnu/libsfml-network.so
Hexxagon: /usr/lib/i386-linux-gnu/libsfml-audio.so
Hexxagon: CMakeFiles/Hexxagon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/walker2/Projects/Hexxagon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable Hexxagon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Hexxagon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hexxagon.dir/build: Hexxagon

.PHONY : CMakeFiles/Hexxagon.dir/build

CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/main.cpp.o.requires
CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/Game.cpp.o.requires
CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/Board.cpp.o.requires
CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/States/Intro_State.cpp.o.requires
CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/States/Menu_State.cpp.o.requires
CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/States/Multiplayer_State.cpp.o.requires
CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/Player.cpp.o.requires
CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/ResourceManager.cpp.o.requires
CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/GameGUI.cpp.o.requires
CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/States/Difficulty_Singleplayer_State.cpp.o.requires
CMakeFiles/Hexxagon.dir/requires: CMakeFiles/Hexxagon.dir/States/Difficulty_Computerwars_State.cpp.o.requires

.PHONY : CMakeFiles/Hexxagon.dir/requires

CMakeFiles/Hexxagon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Hexxagon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Hexxagon.dir/clean

CMakeFiles/Hexxagon.dir/depend:
	cd /home/walker2/Projects/Hexxagon && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/walker2/Projects/Hexxagon /home/walker2/Projects/Hexxagon /home/walker2/Projects/Hexxagon /home/walker2/Projects/Hexxagon /home/walker2/Projects/Hexxagon/CMakeFiles/Hexxagon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Hexxagon.dir/depend

