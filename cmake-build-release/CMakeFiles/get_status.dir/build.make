# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\carlos\Dropbox\Projetos\Estacao_de_solda\Codigo\SolderingStationFirmware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\carlos\Dropbox\Projetos\Estacao_de_solda\Codigo\SolderingStationFirmware\cmake-build-release

# Utility rule file for get_status.

# Include the progress variables for this target.
include CMakeFiles/get_status.dir/progress.make

CMakeFiles/get_status:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\carlos\Dropbox\Projetos\Estacao_de_solda\Codigo\SolderingStationFirmware\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Get status from ATMEGA328P"
	"C:\Program Files (x86)\Arduino Programmer\avrdude.exe" -p ATMEGA328P -c arduino -P COM7 -n -v

get_status: CMakeFiles/get_status
get_status: CMakeFiles/get_status.dir/build.make

.PHONY : get_status

# Rule to build all files generated by this target.
CMakeFiles/get_status.dir/build: get_status

.PHONY : CMakeFiles/get_status.dir/build

CMakeFiles/get_status.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\get_status.dir\cmake_clean.cmake
.PHONY : CMakeFiles/get_status.dir/clean

CMakeFiles/get_status.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\carlos\Dropbox\Projetos\Estacao_de_solda\Codigo\SolderingStationFirmware C:\Users\carlos\Dropbox\Projetos\Estacao_de_solda\Codigo\SolderingStationFirmware C:\Users\carlos\Dropbox\Projetos\Estacao_de_solda\Codigo\SolderingStationFirmware\cmake-build-release C:\Users\carlos\Dropbox\Projetos\Estacao_de_solda\Codigo\SolderingStationFirmware\cmake-build-release C:\Users\carlos\Dropbox\Projetos\Estacao_de_solda\Codigo\SolderingStationFirmware\cmake-build-release\CMakeFiles\get_status.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/get_status.dir/depend

