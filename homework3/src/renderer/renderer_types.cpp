#include "renderer_types.h"

Color operator"" _c(unsigned long long inc)
{
   int r = (inc & 0xFF0000) >> 16;
   int g = (inc & 0x00FF00) >> 8;
   int b = (inc & 0x0000FF);
   return {r / 255.0f, g / 255.0f, b / 255.0f};
}

Color operator*(Color p, float f)
{
   return {p.r * f, p.g * f, p.b * f};
}

Color operator*(float f, Color p)
{
   return {p.r * f, p.g * f, p.b * f};
}