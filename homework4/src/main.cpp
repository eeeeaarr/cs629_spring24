#include <iostream>
#include <string>

#include "configfile/parser.h"
#include "configfile/scenedata.h"
#include "renderer/renderer.h"
#include "renderer/renderer_types.h"

class TestSquare {
 private:
  float n;

 public:
  TestSquare() : n(0) {}
  void drawSquare(Frame& frame);
};

void TestSquare::drawSquare(Frame& frame) {
  n += 0.1;
  float sn = sin(n);
  float cn = cos(n);
  int x = 400 + (int)(sn * 100);
  int y = 300 + (int)(cn * 100);
  Color c = {1.0, 0, 0};
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      frame.setColor(x + i, y + j, c);
    }
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <config file>" << std::endl;
    return 1;
  }

  Parser parser;
  RenderingInfo* info = parser.parseFile(argv[1]);
  if (info == nullptr) {
    std::cout << "Failed to parse file" << std::endl;
    return 1;
  }

  Frame frame;
  Renderer renderer;

  // Instead of drawing the test square,
  // use the rendering info to render the scene
  TestSquare ts;
  ts.drawSquare(frame);

  if (!renderer.init(frame)) {
    std::cout << "Failed to init renderer" << std::endl;
    return 1;
  }
  while (renderer.render()) {
    // Animating is extra credit, if you're not doing
    // animation delete the code inside this loop.
    frame.clear();
    ts.drawSquare(frame);
    renderer.changeFrame(frame);
  }
}