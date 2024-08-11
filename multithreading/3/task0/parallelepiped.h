#pragma once

#include "shape.h"
#include "line3d.h"

class Parallelepiped : public Shape {
public:
    Parallelepiped(Line3D a, Line3D b, Line3D c);

    double get_volume() const override;

    double get_square() const override;

    void shift(double m, double n, double k) override;

    void scaleX(double a) override;

    void scaleY(double d) override;

    void scaleZ(double e) override;

    void scale(double s) override;

private:
    Line3D a_, b_, c_;
};
