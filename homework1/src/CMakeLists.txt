cmake_minimum_required(VERSION 3.10)

if(APPLE)
   set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk")
   set(CMAKE_C_COMPILER "/Library/Developer/CommandLineTools/usr/bin/gcc")
   set(CMAKE_CXX_COMPILER "/Library/Developer/CommandLineTools/usr/bin/g++")
endif()

project(homework1_exe)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB
     SOURCES
     *.cpp)

add_executable(homework1_exe ${SOURCES})

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(homework1_exe PRIVATE glfw GLEW::GLEW)
if (APPLE)
   target_link_libraries(homework1_exe PRIVATE "-framework OpenGL")   
endif()