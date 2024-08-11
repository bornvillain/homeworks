#include <cmath>
#include "line3d.h"

Line3D::Line3D(Point3D a, Point3D b)
        : a_(a), b_(b) {}

double Line3D::get_volume() const {
    return 0;
}

double Line3D::get_square() const {
    return 0;
}

double Line3D::get_length() const {
    return std::sqrt((a_.x_ - b_.x_) * (a_.x_ - b_.x_) + (a_.y_ - b_.y_) * (a_.y_ - b_.y_) +
                     (a_.z_ - b_.z_) * (a_.z_ - b_.z_));
}

void Line3D::shift(double m, double n, double k) {
    a_.x_ += m;
    a_.y_ += n;
    a_.z_ += k;
    b_.x_ += m;
    b_.y_ += n;
    b_.z_ += k;
}

void Line3D::scaleX(double a) {
    a_.x_ *= a;
    b_.x_ *= a;
}

void Line3D::scaleY(double d) {
    a_.y_ *= d;
    b_.y_ *= d;
}

void Line3D::scaleZ(double e) {
    a_.z_ *= e;
    b_.z_ *= e;
}

void Line3D::scale(double s) {
    a_.x_ /= s;
    a_.y_ /= s;
    a_.z_ /= s;
    b_.x_ /= s;
    b_.y_ /= s;
    b_.z_ /= s;
}
