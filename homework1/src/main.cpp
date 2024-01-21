#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600

GLenum error;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
   {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
   }
}

int main(int argc, char **argv)
{
   std::cout << "program launched" << std::endl;
   if (!glfwInit())
      return 1;

   // At least one of these is required on a mac
   // but may need to be ommitted on PC.
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

   /* Create a windowed mode window and its OpenGL context */
   GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Test OpenGL", NULL, NULL);

   if (!window)
   {
      glfwTerminate();
      return 1;
   }

   /* Make the window's context current */
   glfwMakeContextCurrent(window);
   glfwSetKeyCallback(window, key_callback);

   glewExperimental = GL_TRUE;
   glewInit();

   float r = 0.0f;
   while (!glfwWindowShouldClose(window))
   {
      float red[] = {r, 0.0f, 0.0f, 0.0f};
      glClearBufferfv(GL_COLOR, 0, red);
      glfwSwapBuffers(window);
      glfwPollEvents();
      r += 0.001f;
      if (r >= 1.0f)
      {
         r = 0.0f;
      }
   }
   glfwDestroyWindow(window);
   glfwTerminate();
   return 0;
}