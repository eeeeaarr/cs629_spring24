#include <iostream>
#include <string>

int main(int argc, char **argv)
{
   if (argc < 2) {
      std::cout << "USAGE: homework2_exe [filename]" << std::endl;
      return 1;
   }
   std::string filename { argv[1] };
   // Parse this file...
}