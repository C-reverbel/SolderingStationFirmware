# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\carlos\Desktop\Git\SolderingStationFirmware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-release

# Utility rule file for disassemble_alc.

# Include the progress variables for this target.
include CMakeFiles\disassemble_alc.dir\progress.make

CMakeFiles\disassemble_alc: alc-ATMEGA328P.elf
	C:\Users\carlos\.arduinocdt\packages\arduino\tools\avr-gcc\4.9.2-atmel3.5.4-arduino2\bin\avr-objdump.exe -h -S alc-ATMEGA328P.elf > alc.lst

disassemble_alc: CMakeFiles\disassemble_alc
disassemble_alc: CMakeFiles\disassemble_alc.dir\build.make

.PHONY : disassemble_alc

# Rule to build all files generated by this target.
CMakeFiles\disassemble_alc.dir\build: disassemble_alc

.PHONY : CMakeFiles\disassemble_alc.dir\build

CMakeFiles\disassemble_alc.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\disassemble_alc.dir\cmake_clean.cmake
.PHONY : CMakeFiles\disassemble_alc.dir\clean

CMakeFiles\disassemble_alc.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\carlos\Desktop\Git\SolderingStationFirmware C:\Users\carlos\Desktop\Git\SolderingStationFirmware C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-release C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-release C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-release\CMakeFiles\disassemble_alc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\disassemble_alc.dir\depend

