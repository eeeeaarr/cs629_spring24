# cs629 spring 2024 Homework Starter Projects

## General information:

You are currently looking at a github repository containing the homework "starter" files. Each homework has its own directory with the starter files you need for that homework. You'll do a "git clone" to copy these files to your local machine, and do any setup as needed to get the files to compile, etc.  As I add new starter files, you'll do a "git pull" to fetch them.

[Homework 1: OpenGL "Hello World"](homework1/)

[Homework 2: OBJ file loader](homework2/)

[Homework 3: Line Drawing Exercise](homework3/)

The homework starter projects are intended to be built using CMake. CMake attempts to be a cross-platform "build file builder" -- it will try to create a set of build files that work on your platform.

Generally, in each homework directory what you will do is:

```
cd homeworkN
cmake ./src
```

This will generate a set of files needed to build the project. Then you will run a platform-specific command to actually build the project.

For specific setup instructions for your platform, go into the Homework 1 folder and read the README there.

## Resources
* [PowerShell for Programmers](https://devblogs.microsoft.com/scripting/powershell-for-programmers-a-quick-start-guide/)
* [Web Developer's Guide to the Mac Terminal](https://scrimba.com/articles/web-developer-terminal/)
* [Linux Terminal for Beginners](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview)
* [Learn the Basics of Git in Under 10 Minutes](https://www.freecodecamp.org/news/learn-the-basics-of-git-in-under-10-minutes-da548267cc91/)

Note that if you aren't a heavy git user and don't plan to use git to manage your own changes, the only commands you really need to know are "git clone" and "git pull."