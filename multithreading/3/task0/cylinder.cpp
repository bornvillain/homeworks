#define _USE_MATH_DEFINES

#include <math.h>
#include "cylinder.h"

Cylinder::Cylinder(const Circle &circle, double height)
        : circle_(circle), height_(height) {}

double Cylinder::get_volume() const {
    return M_PI * circle_.get_radius() * circle_.get_radius() * height_;
}

double Cylinder::get_square() const {
    return 2 * M_PI * circle_.get_radius() * (height_ + circle_.get_radius());
}

