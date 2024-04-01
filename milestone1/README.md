# Final Project Milestone 1

You will create an OpenGL program which implements a cutscene for a video game. You have two choices for your theme:

* Descent
* Alice

More information about the themes can be found in the [Lecture 7 notes](https://docs.google.com/presentation/d/1_c8itd-UIc2KtUcgpMrC-OMsC2qaFT01DEZlL1kj680/edit#slide=id.g2be51250d72_1_0)

When the program is launched, you should see one of two things:

* **Descent**: You are flying forward through a maze-like series of rooms and chambers
* **Alice**: You are falling slowly downward through a series of different rooms with different sizes and shapes

For this milestone, you do not have to implement any other models aside from the environment model.

Your project should contain the following elements:

1. Three input files:
    1. An environment model for the cutscene (i.e. the rooms or chambers), modeled created in Blender and exported as an OBJ file.
    1. A file containing a list of light positions, positioned in the same world-coordinates as the environment model
    1. A file with a description of a series of connected Bezier curves that describe a motion path through the environment model
1. An OpenGL program that does the following things:
    1. Loads data from the 3 input files
    1. Sets up the necessary OpenGL data buffers for the environment model
    1. Sets up the necessary uniform variables for light positions and bezier curves
    1. Sets up a frame number or time variable to control the animation
    1. Loads and compiles fragment and vertex shaders that implement the rendering logic
    1. Renders the animation from beginning to end, incrementing the frame number or time parameter on each frame, and rendering the scene according to that frame number.
    1. Stops at the last frame and waits for the user to exit

I will provide a Blender script that exports the light list file and the motion path file. You already have parsing code for the OBJ file. Parsing the light list file and bezier file should be straightforward. You could also hard code them into your code, but I don't recommend doing this for the OBJ file.

## Invoking the program

When myself or the TA run your program, we should be able to run it from the command line without modifying your source code in any way.

## What to Submit

Please submit only the following things:

1. Your source code
1. Your three input files.

Do NOT submit:

1. Visual Studio project files
1. project files from any other IDE (for example, XCode)
1. compiled binaries
1. videos of the output of your program

If you have followed along with the previous homework instructions and used cmake as recommended (so that you are running `cmake ./src` from the parent folder), then you can just submit your "src" folder plus the three input files.

## Template Files

I am not providing any template files for this project, however you have access to all the template files from the previous homeworks, which (in addition to the lecture notes) contain a lot of code you can reuse.
