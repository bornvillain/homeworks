#pragma once

#include "shape.h"
#include "point.h"

class Line3D : public Shape {
public:
    Line3D(Point3D a, Point3D b);

    double get_volume() const override;

    double get_square() const override;

    double get_length() const;

    void shift(double m, double n, double k) override;

    void scaleX(double a) override;

    void scaleY(double d) override;

    void scaleZ(double e) override;

    void scale(double s) override;

private:
    Point3D a_, b_;
};