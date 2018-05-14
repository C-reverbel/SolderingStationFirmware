cmake_minimum_required(VERSION 3.10)
set(CMAKE_TOOLCHAIN_FILE CMake/Toolchains/AVR.cmake)

set(AVR_PROGRAMMER arduino)

if(NOT AVR_UPLOADTOOL_PORT)
    set(AVR_UPLOADTOOL_PORT usb)
endif()
# AVR and fuses needs to be set

set(AVR_MCU         ATMEGA328P)
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
        Source/LCD/LCD.cpp
        #Source/LCD/LiquidCrystal.cpp
        Source/GPIO/GPIO.cpp
        Source/GPIO/FastPWMPin.cpp
        Source/LCD/WString.cpp
        Source/LCD/Print.cpp
        Source/Menu/Menu.cpp
        Source/Menu/ApplicationMenu.cpp
        Source/USER_IO/RotaryEncoder.cpp
        #Source/LCD/Printable.h
        #${AVRTools}
        )

add_avr_executable(alc ${srcs})
target_include_directories(alc-${AVR_MCU}.elf
        PUBLIC Source)

add_definitions("-DF_CPU=${MCU_SPEED}")
