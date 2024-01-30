# cs629 spring 2024 Homework Starter Projects

Note: specific instructions for each homework assignment have been moved into the respective folders.

[Homework 1](homework1/README.md)

[Homework 2](homework2/README.md)

## General information:

Most of the homeworks will require that you have some facility with running commands at the terminal (or Powershell on Windows). See "resources" section below if you need help with this.

You are currently looking at a github repository containing the homework "starter" files. You'll do a "git clone" to copy these files to your local machine, and then a "git pull" as I add more homework files during the semester. At a minimum, you'll have to know how to use git. I'll add some links to the "resources" section about this as well.

The homework starter projects are intended to be built using CMake. CMake attempts to be a cross-platform "build file builder" -- it will try to create a set of build files that work on your platform.

Generally, to build your project: you will cd into the directory and type cmake, passing it the source directory, like so:

```
cd homeworkN
cmake ./src
```

This will generate a set of files needed to build the project. Then you will run a platform-specific command to actually build the project and run it (see below)

Platform-specific system setup information below.

## Windows Setup

1. Install Visual Studio 2022 (not just VS Code). When you install, you'll have the choice to select different options. Make sure you install any components related to command line development, C++, Graphics, and OpenGL. If in doubt, just install everything.
1. Follow OpenGL setup instructions (see homework 1)
1. Type `cmake ./src` in the homework folder.
1. After you run `cmake ./src` there will be a Visual Studio `.sln` file in your directory. Open it in Visual Studio and build (but don't try to run anything yet).
1. To run the project, come back out to the command line and run it from there (e.g. `.\Debug\homework1_exe.exe`)

## Mac Setup

1. Install XCode command line tools from https://developer.apple.com/xcode/resources/. Note: these should be installed in this directory: `/Library/Developer/CommandLineTools` -- if for some reason they are not, let me know and I'll update the CMakeLists.txt file to try a few locations. If you have an older version of MacOS you may need to download an older version of XCode.
1. Follow OpenGL setup instructions (see homework 1)
1. Type `cmake ./src` in the homework folder.
1. Type `make` to build your project.
1. Run the executable by typing `./homework1_exe`

## Linux Setup

1. Follow OpenGL setup instructions (see homework 1)
1. Install cmake with `sudo apt-get install cmake`
1. Install g++ with `sudo apt-get install g++`
1. Type `cmake ./src` in the homework folder.
1. Type `make` to build your project.
1. Run the executable by typing `./homework1_exe`

## Resources
* [PowerShell for Programmers](https://devblogs.microsoft.com/scripting/powershell-for-programmers-a-quick-start-guide/)
* [Web Developer's Guide to the Mac Terminal](https://scrimba.com/articles/web-developer-terminal/)
* [Linux Terminal for Beginners](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview)
* [Learn the Basics of Git in Under 10 Minutes](https://www.freecodecamp.org/news/learn-the-basics-of-git-in-under-10-minutes-da548267cc91/)

Note that if you aren't a heavy git user and don't plan to use git to manage your own changes, the only commands you really need to know are "git clone" and "git pull."