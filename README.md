# cs629 spring 2024 Homework Starter Projects

These homework starter projects are intended to be built using CMake. CMake attempts to be a cross-platform "build file builder" -- it will try to create a set of build files that work on your platform.

Generally, to build your project: you will cd into the directory and type cmake, passing it the source directory, like so:

```
cd homework1
cmake ./src
```

This will generate a set of files needed to build the project. Then you will run a platform-specific command to actually build the project and run it (see below)

Platform-specific system setup information below.

## Windows Setup

1. Install Visual Studio 2022 (not just VS Code).
1. Download 64 bit GLFW precompiled binaries from https://www.glfw.org/download.html. This will be a zipfile.
    1. Extract the zipfile. You should have a folder named "glew-2.1.0"
    1. Put that folder in the "dependencies" folder of this project
1. Download GLEW binaries from here: https://glew.sourceforge.net/
    1. Extract the zipfile. You should have a folder named "glfw-3.3.9.bin.WIN64"
    1. Put that folder in the "dependencies" folder of this project
1. There is a DLL in glew-2.1.0\bin\Release\x64 that needs to be in the search path when you run your program. The command for adding a directory to your search path in powershell is `$env:PATH += ";the/directory/goes/here`. If the program runs but doesn't do anything and just exits, check your spelling of the directory and the path again. Once you've got it working, I think there's a control panel you can use to permanently add that directory to the path.
1. After you run `cmake ./src` there will be a Visual Studio `.sln` file in your directory. Open it in Visual Studio and build (but don't try to run anything yet).
1. To run the project, come back out to the command line and run it from there (e.g. `.\Debug\homework1_exe.exe`)

## Mac Setup

Important note: Macs do not natively support OpenGL versions after 4.1. This should be fine for this class, and in class we will not be discussing any OpenGL functions later than 4.1. However if you are scouring the [OpenGL reference](https://registry.khronos.org/OpenGL-Refpages/gl4/) looking for something that we didn't discuss in class, check the version compatibility matrix at the bottom of the reference page to make sure that this works in 4.1 or earlier.

1. Install XCode command line tools from https://developer.apple.com/xcode/resources/. Note: these should be installed in this directory: `/Library/Developer/CommandLineTools` -- if for some reason they are not, let me know and I'll update the CMakeLists.txt file to try a few locations.
1. Install Homebrew from https://brew.sh/
1. Type `brew install glfw` in the terminal.
1. Type `brew install glew` in the terminal.
1. Type `cmake ./src` in the homework folder.
1. Type `make` to build your project.
1. Run the executable by typing `./homework1_exe`

## Linux Setup

1. Install glew with `sudo apt-get install libglew-dev`
1. Install glfw with two commands: `sudo apt-get install libglfw3` and `sudo apt-get install libglfw3-dev`
1. Install cmake with `sudo apt-get install cmake`
1. Install g++ with `sudo apt-get install g++`
1. build with `make`
1. run with `./homework1_exe`
