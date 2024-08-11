#include "rectangle.h"

Rectangle::Rectangle(Line2D a, Line2D b)
        : a_(a), b_(b) {}

double Rectangle::get_volume() const {
    return 0;
}

double Rectangle::get_square() const {
    return a_.get_length() * b_.get_length();
}

void Rectangle::shift(double m, double n, double k) {
    a_.shift(m, n, k);
    b_.shift(m, n, k);
}

void Rectangle::scaleX(double a) {
    a_.scaleX(a);
    b_.scaleX(a);
}

void Rectangle::scaleY(double d) {
    a_.scaleY(d);
    b_.scaleY(d);
}

void Rectangle::scale(double s) {
    a_.scale(s);
    b_.scale(s);
}

