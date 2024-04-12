# Final Project Milestone 1

## Basic Requirements

You will create your own game engine and implement a short first-person cutscene for a game (30-60 seconds long). You will be implementing this game engine in C++ using OpenGL (you will not use Unity or Unreal or any of the other engines available).

For your cutscene, you have two choices for your theme:

* **Descent**: You are in a spaceship flying through a large mining facility. You are flying forward through a maze-like series of rooms and chambers.
* **Alice**: You are Alice from the book Alice in Wonderland falling down the rabbit hole. You are slowly floating downward through a series of different rooms with different sizes and shapes.

More information about the themes can be found in the [Lecture 7 notes](https://docs.google.com/presentation/d/1_c8itd-UIc2KtUcgpMrC-OMsC2qaFT01DEZlL1kj680/edit#slide=id.g2be51250d72_1_0)

For this first milestone, the only part of the cutscene that you need to implement is the following:

* An environment model (some set of rooms, corridors, and spaces)
* Camera movement through the environment
* Basic point lights distributed throughout the environment

You do not need to implement

* Textures
* Different materials (all the walls can be the same material)
* Shadow maps (it's okay if the lights shine "through" the walls)
* Any animation other than camera movement
* Specular reflections, or any form of shading more advanced than Gourad shading

Note that you do not need to implement any type of user control with the keyboard or mouse. The definition of a cutscene is a short section of a video game where you just see an in-game "movie" and you don't control what's happening.

Part of your grade will be the complexity of the environment, or how "interesting" the cutscene is. If you just fly through two rooms that are perfect cubes, and that's it, you won't get as good a grade as if you flew through an "interesting" maze with lots of twists and turns.

## Recommendations

I've provided some resources to help you implement this. These are some recommendations: you don't have to follow all these, but IMO these will help you:

* Build the scene in Blender, adding point lights and adding a bezier curve for the flight (or falling) path.
* Use the two scripts I've provided in the "scripts" folder to export your curve and lights.
* Export the environment model as an OBJ file.
* Provide input files on the command line, so you can use simpler models to debug.
* Reuse the bezier and obj file loader code from your earlier homeworks, and reference the week 8 class slides for shader code.
    * If you didn't implement the "faded bezier" section of Homework 3, and you used the midpoint algorithm to render the other two beziers, you may need to go back to your book in order to find the correct algorithm for interpolating a point along a bezier curve.
* Use a "t" variable to track the time within the animation, where 0.0 means the start of the animation, and 1.0 means the end (use glfwGetTime to make sure that the animation actually takes 30-60 seconds -- otherwise animation speed will be dependent on the speed of the computer)
* Think carefully about the interpolation of t across all the separate bezier curves in your complete motion path
* Create a uniform variable for the camera position and model position, and use GLM for matrix transforms in your engine.
* Put your shader code in a raw string variable in a header file (i.e. `R"()"`)
* For your data classes, create operator overloads for the output stream (`<<`) operator, so you can print them to `std::cout` for debugging
* First test your engine with very simple elements, like a single triangle and a single light, to make sure things are working.
* Make sure to exit the program if shader compilation fails, and print out the error messages from shader compilation.
* Implement your game engine in an object-oriented way. For example, you could have the following set of classes:
    * Entity -- handles OpenGL code for initializing and drawing a single OBJ-file based model
    * PointLight -- represents a light
    * Camera -- represents the camera
    * Scene -- contains the whole scene, i.e.: a camera, a list of lights, and a list of entities (the environment is one of the entities)
    * Engine -- handles the OpenGL setup code and delegates to the scene to render the contents of the scene

In class, I will present and show the code I've written to do this, so you can see how I've done it. I'm happy to answer any questions.

## What to Submit

Please submit only the following things:

1. Your source code
1. Any input files needed (such as OBJ files, light and bezier input files, etc)
1. (As a backup) a video of your program running.

Do NOT submit:

1. Visual Studio project files
1. project files from any other IDE (for example, XCode)
1. compiled binaries

If you have followed along with the previous homework instructions and used cmake as recommended (so that you are running `cmake ./src` from the parent folder), then you can just submit your "src" folder plus the input files.

## Grading

The basic metrics on which you will be graded are:

* Does the project compile and run with minimal tweaking?
* Is the code implementation correct?
* Is the scene interesting and complex?

Obviously, hitting all these marks is optimal, and two out of three is better than one out of three.

## Template Files

I am not providing any template files for this project, however you have access to all the template files from the previous homeworks, which (in addition to the lecture notes) contain a lot of code you can reuse.

## Due Date and Late Submissions

The due date is Friday, 4/26. I am no longer allowing late submissions. The deadline is the deadline. If you haven't submitted anything before the deadline, it's a zero.

