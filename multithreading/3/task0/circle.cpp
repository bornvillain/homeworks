#define _USE_MATH_DEFINES

#include <math.h>
#include "circle.h"

Circle::Circle(Point2D center, double radius)
        : center_(center), radius_(radius) {}

double Circle::get_volume() const {
    return 0;
}

double Circle::get_square() const {
    return M_PI * radius_ * radius_;
}

double Circle::get_radius() const {
    return radius_;
}