cmake_minimum_required(VERSION 3.10)

project(homework2_exe)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(APPLE)
   set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk")
   set(CMAKE_C_COMPILER "/Library/Developer/CommandLineTools/usr/bin/gcc")
   set(CMAKE_CXX_COMPILER "/Library/Developer/CommandLineTools/usr/bin/g++")
endif()

file(GLOB
     SOURCES
     *.cpp)

add_executable(homework2_exe ${SOURCES})


