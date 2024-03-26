#include <iostream>
#include "quadrilateral.h"

Quadrilateral::Quadrilateral(int a, int b, int c, int d, double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    name = "Quadrilateral";
    sides = 4;
}

bool Quadrilateral::IsRegular() {
    if (a == b && b == c && c == d && A == B && B == C && C == D) {
        return true;
    }
    return false;
}

void Quadrilateral::GetInfo() {
    Figure::GetInfo();
    std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n'
              << "Аngles: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
}

