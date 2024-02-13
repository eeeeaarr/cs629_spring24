# Homework 1: Get OpenGL working

The objective of this homework is to get OpenGL working on your machine. This directory contains a "hello world" project that just opens up an OpenGL window. The program paints the entire window on every frame and keeps changing the color, so if it's running correctly, you'll see it fade from black to red over and over again. That's all it does, you don't actually see the words "hello world".

In order to get this program to work, you'll have to set up some OpenGL components. The specific instructions depend on what system you are using.

## Windows Setup

1. Install Visual Studio 2022 (not just VS Code). When you install, you'll have the choice to select different options. Make sure you install any components related to command line development, C++, Graphics, and OpenGL. If in doubt, just install everything.
1. Open up the developer PowerShell with Tools > Command Line > Developer PowerShell -- you will use this for all the terminal commands.
1. Install git if you don't have it: https://git-scm.com/download/win
1. git clone this repo by typing `git clone https://github.com/eeeeaarr/cs629_spring24.git` at the terminal.
1. Install CMake (get it here: https://cmake.org/download/)
1. Download 64 bit GLFW precompiled binaries from https://www.glfw.org/download.html. This will be a zipfile.
   1. Extract the zipfile. You should have a folder named "glfw-3.3.9.bin.WIN64"
   1. Put that folder in the "dependencies" folder of this project
1. Download GLEW binaries from here: https://glew.sourceforge.net/
   1. Extract the zipfile. You should have a folder named "glew-2.1.0"
   1. Put that folder in the "dependencies" folder of this project
1. There is a DLL in glew-2.1.0\bin\Release\x64 called "glew32.dll" that needs to be in the search path when you run your program. There are multiple ways to do this. If you don't do this correctly, the program will compile, but when you try to run it, it will immediately exit with no warning or message.
   1. The easy way is to just drag the file into the C:\Windows\System32 folder.
   1. You can also add the location of the file to your search path. The command for adding a directory to your search path in powershell is `$env:PATH += ";the/directory/goes/here`. 
1. Type `cmake ./src` in the homework folder.
1. After you run `cmake ./src` there will be a Visual Studio `.sln` file in your directory. Open it in Visual Studio and go to "Build > Build Solution". Note: do not click on the green arrow in the task bar to build and run. You JUST want to build, you will run the program from the command line.
1. To run the project, come back out to the command line and run it from there (e.g. `.\Debug\homework1_exe.exe`)

## Mac Setup

Important note: Macs do not natively support OpenGL versions after 4.1. This should be fine for this class, and in class we will not be discussing any OpenGL functions later than 4.1. However if you are scouring the [OpenGL reference](https://registry.khronos.org/OpenGL-Refpages/gl4/) looking for something that we didn't discuss in class, check the version compatibility matrix at the bottom of the reference page to make sure that this works in 4.1 or earlier.

1. Open up the Mac terminal.
1. git clone this repo by typing `git clone https://github.com/eeeeaarr/cs629_spring24.git` at the terminal.
1. Install XCode command line tools from https://developer.apple.com/xcode/resources/. Note: these should be installed in this directory by default: `/Library/Developer/CommandLineTools` -- if for some reason they are not, let me know and I'll update the CMakeLists.txt file to try a few locations. If you have an older version of MacOS you may need to download an older version of XCode.
1. Install Homebrew from https://brew.sh/
1. Type `brew install glfw` in the terminal.
1. Type `brew install glew` in the terminal.
1. Type `cmake ./src` in the homework folder.
1. Type `make` to build your project.
1. Run the executable by typing `./homework1_exe`

## Linux Setup

1. git clone this repo.
1. Install glew with `sudo apt-get install libglew-dev`
1. Install glfw with two commands: `sudo apt-get install libglfw3` and `sudo apt-get install libglfw3-dev`
1. Install cmake with `sudo apt-get install cmake`
1. Install g++ with `sudo apt-get install g++`
1. Type `cmake ./src` in the homework folder.
1. Type `make` to build your project.
1. Run the executable by typing `./homework1_exe`



