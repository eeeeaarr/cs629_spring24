#pragma once
#include <string>
#include <vector>

#include "../renderer/renderer_types.h"
#include "../vect/vect.h"

// Do not modify any of this data after parsing.
// Treat this as a read-only data structure.

struct Material {
  Color color;
  float glossiness;
  float p;
  std::string name;
};

struct Sphere {
  Vect center;
  float radius;
  Material* material;
  std::string materialName;
};

struct Triangle {
  Vect p0;
  Vect p1;
  Vect p2;
  Material* material;
  std::string materialName;
};

struct Light {
  Vect position;
  float intensity;
};

struct DirectionalLight {
  Vect direction;
  float h_intensity;
};

struct RenderingInfo {
  float ambient;
  float focal_length;
  DirectionalLight* dir_light;
  std::vector<Light*> point_lights;
  std::vector<Triangle*> triangles;
  std::vector<Sphere*> spheres;
  std::vector<Material*> materials;
};
