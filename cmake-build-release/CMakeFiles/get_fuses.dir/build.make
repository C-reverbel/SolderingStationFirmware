# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\carlos\Desktop\Git\SolderingStationFirmware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-release

# Utility rule file for get_fuses.

# Include the progress variables for this target.
include CMakeFiles/get_fuses.dir/progress.make

CMakeFiles/get_fuses:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Get fuses from atmega328p"
	"C:\Program Files (x86)\Arduino Programmer\avrdude.exe" -p atmega328p -c arduino -P COM3 -n -U lfuse:r:-:b -U hfuse:r:-:b

get_fuses: CMakeFiles/get_fuses
get_fuses: CMakeFiles/get_fuses.dir/build.make

.PHONY : get_fuses

# Rule to build all files generated by this target.
CMakeFiles/get_fuses.dir/build: get_fuses

.PHONY : CMakeFiles/get_fuses.dir/build

CMakeFiles/get_fuses.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\get_fuses.dir\cmake_clean.cmake
.PHONY : CMakeFiles/get_fuses.dir/clean

CMakeFiles/get_fuses.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\carlos\Desktop\Git\SolderingStationFirmware C:\Users\carlos\Desktop\Git\SolderingStationFirmware C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-release C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-release C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-release\CMakeFiles\get_fuses.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/get_fuses.dir/depend

