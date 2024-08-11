#pragma once

struct Point2D {
    Point2D(double x, double y)
            : x_(x), y_(y) {}

    double x_, y_;
};

struct Point3D : public Point2D {
    Point3D(double x, double y, double z)
            : Point2D(x, y), z_(z) {}

    double z_;
};