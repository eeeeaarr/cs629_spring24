# Homework 1: Get OpenGL working

The objective of this homework is to get OpenGL working on your machine. This directory contains a "hello world" project that just opens up an OpenGL window. The program paints the entire window on every frame and keeps changing the color, so if it's running correctly, you'll see it fade from black to red over and over again. That's all it does.

In order to get this program to work, you'll have to set up some OpenGL components. The specific instructions depend on what system you are using.

## Windows Setup

1. Download 64 bit GLFW precompiled binaries from https://www.glfw.org/download.html. This will be a zipfile.
   1. Extract the zipfile. You should have a folder named "glfw-3.3.9.bin.WIN64"
   1. Put that folder in the "dependencies" folder of this project
1. Download GLEW binaries from here: https://glew.sourceforge.net/
   1. Extract the zipfile. You should have a folder named "glew-2.1.0"
   1. Put that folder in the "dependencies" folder of this project
1. There is a DLL in glew-2.1.0\bin\Release\x64 that needs to be in the search path when you run your program. The command for adding a directory to your search path in powershell is `$env:PATH += ";the/directory/goes/here`. If the program runs but doesn't do anything and just exits, check your spelling of the directory and the path again. Once you've got it working, I think there's a control panel you can use to permanently add that directory to the path. Note that there are different ways to get a DLL into the search path -- if all else fails, you can drag it into the C:\Windows\System32 folder.

## Mac Setup

Important note: Macs do not natively support OpenGL versions after 4.1. This should be fine for this class, and in class we will not be discussing any OpenGL functions later than 4.1. However if you are scouring the [OpenGL reference](https://registry.khronos.org/OpenGL-Refpages/gl4/) looking for something that we didn't discuss in class, check the version compatibility matrix at the bottom of the reference page to make sure that this works in 4.1 or earlier.

1. Install Homebrew from https://brew.sh/
1. Type `brew install glfw` in the terminal.
1. Type `brew install glew` in the terminal.

## Linux Setup

1. Install glew with `sudo apt-get install libglew-dev`
1. Install glfw with two commands: `sudo apt-get install libglfw3` and `sudo apt-get install libglfw3-dev`
