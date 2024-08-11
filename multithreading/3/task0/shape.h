#pragma once

class Shape {
public:
    virtual double get_volume() const = 0;

    virtual double get_square() const = 0;

    virtual void shift(double m, double n, double k) {}

    virtual void scaleX(double a) {}

    virtual void scaleY(double d) {}

    virtual void scaleZ(double e) {}

    virtual void scale(double s) {}
};