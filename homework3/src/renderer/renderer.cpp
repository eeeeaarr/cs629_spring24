#include "frag_glsl.h"
#include "renderer.h"
#include "vert_glsl.h"
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLenum error;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
   {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
   }
}

void glCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
   std::cerr << message << std::endl;
};

bool Renderer::initGL(GLfloat *tex_data)
{
   GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

   glShaderSource(vertexShader, 1, V_SHADER, NULL);
   glCompileShader(vertexShader);
   GLint compileStatus;
   glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileStatus);
   if (compileStatus != GL_TRUE)
   {
      char infolog[512];
      glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
      std::cerr << "Vertex shader compilation failed" << std::endl;
      std::cerr << infolog << std::endl;
      return false;
   }

   // load fragment shader
   GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
   glShaderSource(fragmentShader, 1, F_SHADER, NULL);
   glCompileShader(fragmentShader);
   glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileStatus);
   if (compileStatus != GL_TRUE)
   {
      char infolog[512];
      glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
      std::cerr << "Fragment shader compilation failed" << std::endl;
      std::cerr << infolog << std::endl;
      return false;
   }

   // create shader program
   GLuint shaderProgram = glCreateProgram();
   glAttachShader(shaderProgram, vertexShader);
   glAttachShader(shaderProgram, fragmentShader);
   glLinkProgram(shaderProgram);

   GLint status;
   glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
   if (status != GL_TRUE)
   {
      char infolog[512];
      glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
      std::cerr << "Shader program linking failed" << std::endl;
      std::cerr << infolog << std::endl;
      return false;
   }

   glUseProgram(shaderProgram);

   GLint sampler_uniform_loc = glGetUniformLocation(shaderProgram, "tex");
   std::cout << "uniform: " << sampler_uniform_loc << std::endl;
   glUniform1i(sampler_uniform_loc, 0);

   /*********************/
   /*  set up textures  */
   /*  also samplers    */
   /*********************/

   // Seg fault is when you try to create the texture.

   glGenTextures(1, &tex);
   glBindTexture(GL_TEXTURE_2D, tex);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, WIDTH, HEIGHT, 0, GL_RGBA, GL_FLOAT, tex_data);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   //   glGenerateMipmap(GL_TEXTURE_2D);

   glBindTexture(GL_TEXTURE_2D, 0);

   /***************************/
   /*  set up vertex buffers  */
   /*  and vertex arrays      */
   /***************************/

   GLfloat square[] = {
       -1.0f, 1.0f, 0.0f, // vertex
       0.0f, 0.0f,        // texture coordinate

       1.0f, 1.0f, 0.0f,
       1.0f, 0.0f,

       -1.0f, -1.0f, 0.0f,
       0.0f, 1.0f,

       1.0f, -1.0f, 0.0f,
       1.0f, 1.0f};

   glGenBuffers(1, &vbo);
   glGenVertexArrays(1, &vao);

   int stride = 5 * sizeof(GLfloat);
   int offset = 3 * sizeof(GLfloat);

   glBindBuffer(GL_ARRAY_BUFFER, vbo);
   glBindVertexArray(vao);

   glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(GLfloat), square, GL_STATIC_DRAW);

   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void *)0);
   glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void *)offset);
   glEnableVertexAttribArray(0);
   glEnableVertexAttribArray(1);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
   glBindVertexArray(0);

   return true;
}

bool Renderer::init(const Frame &frame)
{
   /* Initialize the library */
   if (!glfwInit())
      return false;

   // At least one of these is required on a mac
   // but may need to be ommitted on PC.
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

   /* Create a windowed mode window and its OpenGL context */
   window = glfwCreateWindow(WIDTH, HEIGHT, "Line Drawing Exercise", NULL, NULL);

   if (!window)
   {
      glfwTerminate();
      return false;
   }

   /* Make the window's context current */
   glfwMakeContextCurrent(window);
   glfwSetKeyCallback(window, key_callback);

   glewExperimental = GL_TRUE;
   glewInit();

   // This only works in OpenGL 4.6
   // glEnable(GL_DEBUG_OUTPUT);
   // glDebugMessageCallback(glCallback, NULL);
   // glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);

   //   turn the colors in the frame into gl format
   std::vector<GLfloat> tex_data;
   for (int y = 0; y < HEIGHT; y++)
   {
      for (int x = 0; x < WIDTH; x++)
      {
         Color c = frame.getColor(x, y);
         tex_data.push_back(c.r);
         tex_data.push_back(c.g);
         tex_data.push_back(c.b);
         tex_data.push_back(1.0f);
      }
   }

   if (!initGL(tex_data.data()))
   {
      glfwDestroyWindow(window);
      glfwTerminate();
      return false;
   }
   return true;
}

std::string getErrorString(GLenum error) {
   switch(error) {
      case GL_NO_ERROR:
         return "No error has been recorded.";
      case GL_INVALID_ENUM:
         return "An unacceptable value is specified for an enumerated argument.";
      case GL_INVALID_VALUE:
         return "A numeric argument is out of range.";
      case GL_INVALID_OPERATION:
         return "The specified operation is not allowed in the current state.";
      case GL_INVALID_FRAMEBUFFER_OPERATION:
         return "The framebuffer object is not complete.";
      case GL_OUT_OF_MEMORY:
         return "There is not enough memory left to execute the command.";
      case GL_STACK_UNDERFLOW:
         return "An attempt has been made to perform an operation that would cause an internal stack to underflow.";
      case GL_STACK_OVERFLOW:
         return "An attempt has been made to perform an operation that would cause an internal stack to overflow.";
   }
}

bool Renderer::render()
{
   /* Loop until the user closes the window */
   if (!glfwWindowShouldClose(window))
   {
      static const float black[] = {0.0f, 0.0f, 0.0f, 0.0f};
      glClearBufferfv(GL_COLOR, 0, black);
      //      glClear(GL_COLOR_BUFFER_BIT);

      glBindVertexArray(vao);
      glBindBuffer(GL_ARRAY_BUFFER, vbo);
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, tex);
      glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
      if ((error = glGetError()) != GL_NO_ERROR)
         std::cerr << "Error e: " << getErrorString(error) << std::endl;
      glBindTexture(GL_TEXTURE_2D, 0);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindVertexArray(0);

      glfwSwapBuffers(window);
      glfwPollEvents();
      return true;
   }
   else
   {
      glfwDestroyWindow(window);
      glfwTerminate();
      return false;
   }
}
