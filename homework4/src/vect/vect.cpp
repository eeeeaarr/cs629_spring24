#include <iostream>
#include "vect.h"

Vect operator*(float scaleFactor, Vect v) { return v * scaleFactor; }

std::ostream& operator<<(std::ostream& os, const Vect& obj) {
    os << "( x: " << obj.x << ", y: " << obj.y << ", z: " << obj.z << " )";
    return os;
}