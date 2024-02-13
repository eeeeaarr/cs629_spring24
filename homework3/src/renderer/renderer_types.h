#pragma once
#include <algorithm>
#include <vector>
#include "definitions.h"

struct Color
{
   float r;
   float g;
   float b;

   Color() : r(0), g(0), b(0) {}
   Color(float in_r, float in_g, float in_b) : r(in_r), g(in_g), b(in_b) {}

   Color operator+(Color p)
   {
      float newRed = std::min(r + p.r, 1.0f);
      float newGreen = std::min(g + p.g, 1.0f);
      float newBlue = std::min(b + p.b, 1.0f);
      return {newRed, newGreen, newBlue};
   }
};

Color operator*(Color p, float f);

Color operator*(float f, Color p);

Color operator"" _c(unsigned long long inc);

struct Frame
{
   std::vector<Color> colors;

   Frame()
   {
      colors.resize(WIDTH * HEIGHT);
   }

   Color getColor(int x, int y) const
   {
      return colors[y * WIDTH + x];
   }

   void setColor(int x, int y, Color p)
   {
      colors[y * WIDTH + x] = p;
   }
};
