# Homework 4: Ray Tracer

You will write a raytracer, as discussed in class and in your book. Your raytracer will render one scene as a still image, using `Frame`, `Renderer`, and `Color` classes, like in homework 3. The code for the renderer will be in the `renderer` folder, as before.

At startup, your raytracer will read in a configuration file that contains all the information about what is in the scene. The code for parsing that configuration file will be provided to you, so you can focus on the raytracing part. The code for doing this is in the `configfile` folder.

I recommend that you put all your source code in the src folder, and that you don't make any changes to the code in the `renderer` or `configfile` folders.

Your raytracer needs to support the following entity types:

* spheres
* triangles
* point lights
* directional lights (one per scene)

And the following lighting calculations:
* ambient
* diffuse
* specular

The focal length of your raytracer needs to be configurable and will be passed in via the config file.

To grade this assignment, we will pass a config file into your raytracer and compare the output to a reference image. Your output doesn't have to resemble the reference image in every pixel, but it should be close.

Some notes:
* You will specify materials separately from objects, so for example, you could define a material called "ShinyBlue" and then apply that material to different objects. A material has color and other information about how to shade objects with that material.
* If you read about the fact that lights can have their own color, or specular reflections can have color, don't worry about that. The only thing that will have color is diffuse and ambient reflections, everything else is white.
* The amount of specular lighting on a given surface is controlled by a coefficient from 0-1 called glossiness. After doing the specular calculation from the notes, you multiply by the glossy coefficient. Full glossy means that the coefficient is 1 and you get the entire specular term. No glossiness means that there are no specular reflections.
* The amount of diffuse reflection is just controlled by the color you are using for diffuse/ambient lighting (use a darker color for objects that have few diffuse reflections).
* directional lights are specified with a vector that tells you the direction the light is shining.

## Config file

I will provide an example config file, however I recommend you get used to the config file format, so you can test out your raytracer with different scenes. To grade the assignment we will use a different config file than the example.

### Config File Format

Each line of the config file will declare something:

* *material*: this creates a material. It has a name, the color (for diffuse and ambient lighting), the "glossiness" coefficcient, and the Phong exponent.
* *sphere*: this creates a sphere. Center and radius are specified, also a material.
* *triangles*: this creates a triangle. The three vertices of the triangle are specified, also a material.
* *light*: this creates a point light at the given position with the given intensity.
* *direction*: this creates a directional light in the scene with the given intensity (H)
* *ambient*: this tells the raytracer to give every object in the scene this much ambient lighting
* *focal_length*: this tells the raytracer to use this focal length.

The syntax is more or less this:
```
objectname attribute attribute attribute
```

There are three types of attributes:

```
# vector attribute
->foo:(1, 1, 1)

# number attribute
foo:23.34

# string attribute
$foo:"hello"
```
You can have comments in the file, but they have to be on their own line by themselves,
starting with `#`.

You can use whitespace but do not put spaces in the attribute names. So, for example this is okay:

```
gloss: 0.4
->foo: ( 3, 4, 5)
$foo: "hello"
```
But these won't work:
```
gloss  : 0.4
-> foo: ( 3, 4, 5)
```

### Example file:

```
# materials:
material $name:"MatA" ->col:(0.2, 0.1, 0.4) gloss:0.4 p:20

# objects:
sphere ->center:(10, 20, 40) radius:5 $mat:"MatA"
triangle ->p0:(100, 200, 300) ->p1:(200, 210, 310) ->p2:(300, 310, 10) $mat:"MatA"

# lights:
light ->pos:(10, 30, 40) i:10
direction ->d:(30, 40, 50) h:30

# rendering info:
global ambient: 0.1 focal_length: 1.2
```

### Parsed Data

The data will be returned back to you from the parse method in the following data structure:

```
struct Material {
  Color color;
  float glossiness;
  float p;
};

struct Sphere {
  Vect center;
  float radius;
  Material* material;
};

struct Triangle {
  Vect p0;
  Vect p1;
  Vect p2;
  Material* material;
};

struct Light {
  Vect position;
  float intensity;
};

struct DirectionalLight {
  Vect direction;
  float h_intensity;
};

struct RenderingInfo {
  float ambient;
  float focal_length;
  DirectionalLight* dir_light;
  std::vector<Light*> point_lights;
  std::vector<Triangle*> triangles;
  std::vector<Sphere*> spheres;
  std::vector<Material*> materials;
};
```

## Drawing API

(note: this is more or less the same info that was in the Homework 3 instructions)

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
  // usually do nothing here
}
```

## Optional Extra Credit

I've added a feature to the frame API so that you can animate your image. The example code does this: it draws a square slowly moving around in a circle. As an experiment, try to animate some aspect of your raytracer, and see how slow the output is. You can make a video of what happened and give a short explanation and analysis of your thoughts about what went wrong/right when attempting to do this.

<br>
<br>

