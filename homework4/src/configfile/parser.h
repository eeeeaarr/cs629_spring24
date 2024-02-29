#include <string>

#include "scenedata.h"

class Parser {
 public:
  RenderingInfo* parseFile(std::string filename);
};
