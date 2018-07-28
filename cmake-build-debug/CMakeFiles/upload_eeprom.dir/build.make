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
CMAKE_BINARY_DIR = C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug

# Utility rule file for upload_eeprom.

# Include the progress variables for this target.
include CMakeFiles/upload_eeprom.dir/progress.make

CMakeFiles/upload_eeprom: firmware-atmega328p-eeprom.hex
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Uploading firmware-atmega328p-eeprom.hex to atmega328p using arduino"
	"C:\Program Files (x86)\Arduino Programmer\avrdude.exe" -p atmega328p -c arduino -b 115200 -D -U eeprom:w:firmware-atmega328p-eeprom.hex -P COM3

firmware-atmega328p-eeprom.hex: firmware-atmega328p.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating firmware-atmega328p-eeprom.hex"
	C:\Users\carlos\.arduinocdt\packages\arduino\tools\avr-gcc\4.9.2-atmel3.5.4-arduino2\bin\avr-objcopy.exe -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex firmware-atmega328p.elf firmware-atmega328p-eeprom.hex

upload_eeprom: CMakeFiles/upload_eeprom
upload_eeprom: firmware-atmega328p-eeprom.hex
upload_eeprom: CMakeFiles/upload_eeprom.dir/build.make

.PHONY : upload_eeprom

# Rule to build all files generated by this target.
CMakeFiles/upload_eeprom.dir/build: upload_eeprom

.PHONY : CMakeFiles/upload_eeprom.dir/build

CMakeFiles/upload_eeprom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\upload_eeprom.dir\cmake_clean.cmake
.PHONY : CMakeFiles/upload_eeprom.dir/clean

CMakeFiles/upload_eeprom.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\carlos\Desktop\Git\SolderingStationFirmware C:\Users\carlos\Desktop\Git\SolderingStationFirmware C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug C:\Users\carlos\Desktop\Git\SolderingStationFirmware\cmake-build-debug\CMakeFiles\upload_eeprom.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/upload_eeprom.dir/depend

