#include <cmath>
#include "line2d.h"


Line2D::Line2D(Point2D a, Point2D b)
        : a_(a), b_(b) {}

double Line2D::get_volume() const {
    return 0;
}

double Line2D::get_square() const {
    return 0;
}

double Line2D::get_length() const {
    return std::sqrt((a_.x_ - b_.x_) * (a_.x_ - b_.x_) + (a_.y_ - b_.y_) * (a_.y_ - b_.y_));
}

void Line2D::shift(double m, double n, double k) {
    a_.x_ += m;
    a_.y_ += n;
    b_.x_ += m;
    b_.y_ += n;
}

void Line2D::scaleX(double a) {
    a_.x_ *= a;
    b_.x_ *= a;
}

void Line2D::scaleY(double d) {
    a_.y_ *= d;
    b_.y_ *= d;
}

void Line2D::scale(double s) {
    a_.x_ /= s;
    a_.y_ /= s;
    b_.x_ /= s;
    b_.y_ /= s;
}

