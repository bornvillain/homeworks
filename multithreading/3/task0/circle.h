#pragma once

#include "shape.h"
#include "point.h"

class Circle : public Shape {
public:
    Circle(Point2D center, double radius);

    double get_volume() const override;

    double get_square() const override;

    double get_radius() const;

private:
    Point2D center_;
    double radius_;
};