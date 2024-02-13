#pragma once

#include "renderer_types.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class Renderer
{
private:
   GLFWwindow *window;

   GLuint vao;
   GLuint vbo;
   GLuint tex;

   bool initGL(GLfloat *tex_data);

public:
   bool init(const Frame &frame);
   bool render();
};