#pragma once

#include "point.h"
#include "shape.h"

class Line2D : public Shape {
public:
    Line2D(Point2D a, Point2D b);

    double get_volume() const override;

    double get_square() const override;

    double get_length() const;

    void shift(double m, double n, double k) override;

    void scaleX(double a) override;

    void scaleY(double d) override;

    void scale(double s) override;

private:
    Point2D a_, b_;
};