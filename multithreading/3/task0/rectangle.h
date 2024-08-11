#pragma once

#include "shape.h"
#include "line2d.h"

class Rectangle : public Shape {
    Rectangle(Line2D a, Line2D b);

    double get_volume() const override;

    double get_square() const override;

    void shift(double m, double n, double k) override;

    void scaleX(double a) override;

    void scaleY(double d) override;

    void scale(double s) override;

private:
    Line2D a_, b_;
};