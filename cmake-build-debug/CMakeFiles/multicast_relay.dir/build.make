# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\mattt\OneDrive\Desktop\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\mattt\OneDrive\Desktop\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/multicast_relay.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/multicast_relay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/multicast_relay.dir/flags.make

CMakeFiles/multicast_relay.dir/client.c.obj: CMakeFiles/multicast_relay.dir/flags.make
CMakeFiles/multicast_relay.dir/client.c.obj: ../client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/multicast_relay.dir/client.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\multicast_relay.dir\client.c.obj   -c C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\client.c

CMakeFiles/multicast_relay.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/multicast_relay.dir/client.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\client.c > CMakeFiles\multicast_relay.dir\client.c.i

CMakeFiles/multicast_relay.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/multicast_relay.dir/client.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\client.c -o CMakeFiles\multicast_relay.dir\client.c.s

CMakeFiles/multicast_relay.dir/server.c.obj: CMakeFiles/multicast_relay.dir/flags.make
CMakeFiles/multicast_relay.dir/server.c.obj: ../server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/multicast_relay.dir/server.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\multicast_relay.dir\server.c.obj   -c C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\server.c

CMakeFiles/multicast_relay.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/multicast_relay.dir/server.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\server.c > CMakeFiles\multicast_relay.dir\server.c.i

CMakeFiles/multicast_relay.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/multicast_relay.dir/server.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\server.c -o CMakeFiles\multicast_relay.dir\server.c.s

# Object files for target multicast_relay
multicast_relay_OBJECTS = \
"CMakeFiles/multicast_relay.dir/client.c.obj" \
"CMakeFiles/multicast_relay.dir/server.c.obj"

# External object files for target multicast_relay
multicast_relay_EXTERNAL_OBJECTS =

multicast_relay.exe: CMakeFiles/multicast_relay.dir/client.c.obj
multicast_relay.exe: CMakeFiles/multicast_relay.dir/server.c.obj
multicast_relay.exe: CMakeFiles/multicast_relay.dir/build.make
multicast_relay.exe: CMakeFiles/multicast_relay.dir/linklibs.rsp
multicast_relay.exe: CMakeFiles/multicast_relay.dir/objects1.rsp
multicast_relay.exe: CMakeFiles/multicast_relay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable multicast_relay.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\multicast_relay.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/multicast_relay.dir/build: multicast_relay.exe

.PHONY : CMakeFiles/multicast_relay.dir/build

CMakeFiles/multicast_relay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\multicast_relay.dir\cmake_clean.cmake
.PHONY : CMakeFiles/multicast_relay.dir/clean

CMakeFiles/multicast_relay.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\cmake-build-debug C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\cmake-build-debug C:\Users\mattt\OneDrive\Desktop\vivoh\git\multicast_relay\cmake-build-debug\CMakeFiles\multicast_relay.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/multicast_relay.dir/depend
