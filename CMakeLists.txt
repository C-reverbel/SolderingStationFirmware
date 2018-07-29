cmake_minimum_required(VERSION 3.10)
set(CMAKE_TOOLCHAIN_FILE CMake/Toolchains/AVR.cmake)

set(AVR_PROGRAMMER arduino)

#if(NOT AVR_UPLOADTOOL_PORT)
#    set(AVR_UPLOADTOOL_PORT usb)
#endif()

set(AVR_UPLOADTOOL_PORT COM3)

# AVR and fuses needs to be set

set(AVR_MCU atmega328p)
set(AVR_H_FUSE 0xde)
set(AVR_L_FUSE 0xff)
#set(AVR_E_FUSE 0x05)
# set the MCU speed in Hz
set(MCU_SPEED "16000000UL")

set(AVR_UPLOAD_MCU  atmega328p)
set(AVR_UPLOADTOOL_OPTIONS -b 115200 -D)

project(SolderingStationFirmware)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -flto -Os")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -Os")


# Optimize for size in Debug
set(CMAKE_C_FLAGS_DEBUG "-Os")
set(CMAKE_CXX_FLAGS_DEBUG "-Os")

#file(GLOB_RECURSE srcs
#        Source/*.h
#        Source/*.hpp
#        Source/*.c
#        Source/*.cpp)

#file(GLOB_RECURSE AVRTools Source/AVRTools/*.cpp)

set(srcs Source/main.cpp
         Source/utils/LCD/LCD.cpp
         Source/utils/GPIO/GPIO.cpp
         Source/utils/GPIO/FastPWMPin.cpp
         Source/utils/GPIO/AnalogPin.cpp
         Source/utils/LCD/WString.cpp
         Source/utils/LCD/Print.cpp
         Source/frontend/USER_IO/RotaryEncoder.cpp
         Source/frontend/USER_IO/Button.cpp
         Source/utils/PID/PID_v1.cpp
         Source/utils/AVRTools/SystemClock.cpp
         Source/backend/Backend.cpp
         Source/frontend/Frontend.cpp
         Source/frontend/MenuStructure/MenuItem.cpp
         Source/frontend/MenuStructure/rootMenu/RootMenu.cpp
         Source/frontend/MenuStructure/rootMenu/appMenu/AppMenu.cpp
         Source/frontend/MenuStructure/rootMenu/selectionMenu/SelectionMenu.cpp
         Source/frontend/MenuStructure/rootMenu/optionsMenu/OptionsMenu.cpp
         Source/frontend/MenuStructure/rootMenu/optionsMenu/MinTempOption.cpp
         Source/frontend/MenuStructure/rootMenu/optionsMenu/MaxTempOption.cpp
         Source/frontend/MenuStructure/rootMenu/optionsMenu/TempUnitOption.cpp
        )

add_avr_executable(firmware ${srcs})
target_include_directories(firmware-${AVR_MCU}.elf
        PUBLIC Source)

add_definitions("-DF_CPU=${MCU_SPEED}")
