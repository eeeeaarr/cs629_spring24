# Homework 3: Line Drawing Exercise

You will create a command line program that draws lines and curves on a surface. Which lines or curves to draw, and how to draw them, will be specified as command line arguments to the program.

The program should support as many as possible of the following line and curve types. The more types you support, the more credit/points you will get on this assigment.

1. straight lines drawn using the midpoint algorithm
1. anti-aliased straight lines (using the box filter algorithm)
1. anti-aliased straight lines (using weighted area sampling, i.e. the cone filter - see lecture notes)
1. Bézier curves drawn using midpoint algorithm (remember, to draw a curve you draw a lot of short lines)
1. anti-aliased Bézier curves drawn using the box filter algorithm
1. a "faded" Bézier curve where each segment starts off with full intensity at the start of the curve and gradually fades to black by the end of the curve.

If your program doesn't support one of the line types, it should just ignore the input (not crash and not draw anything).

## Invoking the program

To invoke the program you will pass arguments to tell it what lines or curves to draw. It should process all the arguments and it should be able to draw multiple lines. All lines should be drawn at the same time on the same surface.

For each line or curve there will be two arguments: an opcode that tells it what to draw, and a specifier that tells the program how to draw the curve or line.

The opcodes should be (these correspond to the types listed above):
```
1. line
2. aaline
3. aalinewas
4. bezier
5. aabezier
6. faded
```

For lines, the specifier should give the start x and y, and the end x and y, of the line:
```
sx,sy:ex,ey
```

For Bézier curves, the specifier should give the control points p0, p1, p2, and p3:
```
p0x,p0y;p1x,p1y;p2x,p2y;p3x,p3y
```

Example invocations follow.

<br>

```
homework3_exe.exe --aaline "10,11;100,110"
```
Draw an anti-aliased line, using the box filter algorithm, from the point (10, 11) to the point (100, 110).

<br>
<br>
 
```
homework3_exe.exe --bezier "10,11;50,11;10,50;100,110"
```
Draw a bezier curve segment, using the midpoint algorithm, with these control points:

* **p0**: (10,11) (start point)
* **p1**: (50,11)
* **p2**: (10,50)
* **p3**: (100,110) (end point)

<br>
<br>

```
homework3_exe.exe --bezier "10,11;50,11;10,50;100,110" --aaline "10,11;100,110"
```
Draw both lines listed above.

## Drawing API

I've provided a miniature drawing API for you to use so you can focus on the algorithm part of this assignment. There are three classes you will use to do your drawing. The `Frame` object is what you draw into, a `Renderer` object that does the drawing, and the `Color` object represents a color to draw with. Note that for this assignment, all the lines should be white (0xFFFFFF) except the "faded" line, which should fade from white to black (0xFFFFFF to 0x000000).

This example draws a small red square.

```
Frame frame;
Renderer renderer;

// colors range from 0 to 1
Color c = { 1.0, 0.0, 0.0 };

for (int i = 100; i < 110; i++) {
    for (int j = 100; j < 110; j++) {
        frame.setColor(i, j, c);
    }
}

if (!renderer.init(frame))
{
    std::cout << "Failed to init renderer" << std::endl;
    return 1;
}
while (renderer.render())
{
}
```


<br>
<br>

