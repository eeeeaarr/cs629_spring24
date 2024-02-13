#include <iostream>
#include "renderer/renderer.h"
#include "renderer/renderer_types.h"

int main(int argc, char **argv)
{
   Frame frame;
   Renderer renderer;

   Color c = { 255, 0, 0 };

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
}