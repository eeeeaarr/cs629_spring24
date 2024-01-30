# Homework 2: Create an OBJ file parser

The [OBJ file format](https://en.wikipedia.org/wiki/Wavefront_.obj_file) is an open source file format used to describe 3D model geometry. It was originally created by Wavefront Technologies for their Advanced Visualizer animation package, but because of its simplicity has become a de-facto standard for situations where a simple geometry description is needed for CG projects.

In this homework, you will write a program in C++ that:

1. Reads an OBJ file and parses it, storing it in memory in a format that will be usable by OpenGL.
1. Prints to the terminal a description of the file in the format detailed below.

To test your program, you should download a free 3d model from the internet. I use [Turbosquid](https://turbosquid.com) but there are plenty of other options (GCTrader, Sketchfab). I don't recommend paying for a model because there are plenty of free models available, and at this point you're just getting started. You can download and use any kind of model you want (provided, of course, it adheres to the university code of conduct -- that goes for any third party asset you use in this class).

What you will submit:

1. the source code of your program (zip up the homework2 folder)
2. the .OBJ file that you used

The OBJ file format is simple enough that pretty much everything you need to know to implement your parser is available on the Wikipedia page (see [here](https://en.wikipedia.org/wiki/Wavefront_.obj_file) or the link above).

You should use C++ standard library functions (i.e., the STL) to read the file and print the output -- if you stick to the STL, your program should be able to be compiled on any system. We will go over these more next week, but if you want to get started now, the libraries you'll need to read up on are:

```
<string>
<iostream>
<fstream>
<sstream> // maybe
```
This homework is due 2/11.

## Data format

Your data should be stored in the following format:

```
struct VertexInfo
{
   // coordinates
   float x;
   float y;
   float z;
   // normal
   float normal_x;
   float normal_y;
   float normal_z;
   // texture coordinates
   float u;
   float v;
};

struct Triangle
{
    VertexInfo v1;
    VertexInfo v2;
    VertexInfo v3;
}

```

If your model doesn't have texture coordinates leave those equal to zero. The vertices should be specified in the same order they appear in the OBJ file (order is important when it comes to distinguishing the front vs. back faces of the triangle). Note that if a vertex appears in multiple triangles, all of its data should be duplicated in all of the triangles that it is used in -- in other words, do not use pointers or references. If you've done this correctly, you should have this:

```
Triangle allTriangles[nTriangles]
```

And you should be able to cast it to this:

```
VertexInfo* verticesOfTriangles = (VertexInfo*) allTriangles
```

This `VertexInfo` array will be what you pass into OpenGL, and it should be exactly equivalent to an array of VertexInfo structs having a length of `3 * nTriangles`.

## Output

Your program output should look like this (t: means start of triangle, v: means start of vertex). Please try to stick to this format so I can validate that your program is working right. Obviously the numbers below are just for demonstration purposes, your program should output the real values for all the structs. The triangles should be output in the same order they appear in the .OBJ file.

```
t:
v:
x=1.1264256245
y=2.22542345
z=1.4262562
nx=1.56456325
ny=4.12342356
nz=4.33424234234
u=23.24561
v=59.356
v:
x=1.1264256245
y=2.22542345
z=1.4262562
nx=1.56456325
ny=4.12342356
nz=4.33424234234
u=23.24561
v=59.356
v:
x=1.1264256245
y=2.22542345
z=1.4262562
nx=1.56456325
ny=4.12342356
nz=4.33424234234
u=23.24561
v=59.356
t:
v:
x=1.1264256245
y=2.22542345
z=1.4262562
nx=1.56456325
ny=4.12342356
nz=4.33424234234
u=23.24561
v=59.356
v:
x=1.1264256245
y=2.22542345
z=1.4262562
nx=1.56456325
ny=4.12342356
nz=4.33424234234
u=23.24561
v=59.356
v:
x=1.1264256245
y=2.22542345
z=1.4262562
nx=1.56456325
ny=4.12342356
nz=4.33424234234
u=23.24561
v=59.356
```