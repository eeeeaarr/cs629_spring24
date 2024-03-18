#include "renderer_types.h"
#include <iostream>

Color operator"" _c(unsigned long long inc) {
  int r = (inc & 0xFF0000) >> 16;
  int g = (inc & 0x00FF00) >> 8;
  int b = (inc & 0x0000FF);
  return {r / 255.0f, g / 255.0f, b / 255.0f};
}

Color operator*(Color p, float f) { return {p.r * f, p.g * f, p.b * f}; }

Color operator*(float f, Color p) { return {p.r * f, p.g * f, p.b * f}; }

Color operator+=(Color &p1, Color p2) {
  p1.r += p2.r;
  p1.g += p2.g;
  p1.b += p2.b;
  return p1;
}

std::ostream& operator<<(std::ostream& os, const Color& obj) {
    os << "[ r: " << obj.r << ", g: " << obj.g << ", b: " << obj.b << " ]";
    return os;
}