#include "triangle.h"

Triangle::Triangle(int a, int b, int c, double A, double B, double C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {
    name = "Triangle";
    sides = 3;
}

bool Triangle::IsRegular() {
    if (a == b && b == c && A == B && B == C) {
        return true;
    }
    return false;
}

void Triangle::GetInfo() {
    Figure::GetInfo();
    std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << '\n'
              << "Angles: A=" << A << " B=" << B << " C=" << C << std::endl;
}

