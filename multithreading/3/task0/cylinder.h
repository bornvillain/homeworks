#pragma once

#include "shape.h"
#include "circle.h"

class Cylinder : public Shape {
public:
    Cylinder(const Circle &circle, double height);

    double get_volume() const override;

    double get_square() const override;

private:
    Circle circle_;
    double height_;
};
