#include "parallelepiped.h"

Parallelepiped::Parallelepiped(Line3D a, Line3D b, Line3D c)
        : a_(a), b_(b), c_(c) {}

double Parallelepiped::get_volume() const {
    return a_.get_length() * b_.get_length() * c_.get_length();
}

double Parallelepiped::get_square() const {
    return 2 * (a_.get_length() * b_.get_length() + a_.get_length() * c_.get_length() +
                b_.get_length() * c_.get_length());
}

void Parallelepiped::shift(double m, double n, double k) {
    a_.shift(m, n, k);
    b_.shift(m, n, k);
    c_.shift(m, n, k);
}

void Parallelepiped::scaleX(double a) {
    a_.scaleX(a);
    b_.scaleX(a);
    c_.scaleX(a);
}

void Parallelepiped::scaleY(double d) {
    a_.scaleY(d);
    b_.scaleY(d);
    c_.scaleY(d);
}

void Parallelepiped::scaleZ(double e) {
    a_.scaleZ(e);
    b_.scaleZ(e);
    c_.scaleZ(e);
}

void Parallelepiped::scale(double s) {
    a_.scale(s);
    b_.scale(s);
    c_.scale(s);
}
