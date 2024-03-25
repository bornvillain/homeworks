#include <iostream>
#include "quadrilateral.h"
#include "wrong_figure.h"

Quadrilateral::Quadrilateral(int a, int b, int c, int d, double A, double B, double C, double D)
        : Figure("Quadrilateral", 4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    ThrowIfIncorrectQuadrilateral();
    GetInfo();
}

Quadrilateral::Quadrilateral(std::string name, int a, int b, int c, int d, double A, double B, double C, double D)
        : Figure(name, 4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    ThrowIfIncorrectQuadrilateral();
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

void Quadrilateral::ThrowIfIncorrectQuadrilateral() {
    if (A + B + C + D != 360) {
        throw WrongFigure("Error creating figure " + name + ". Reason: the sum of the angles does not equal 360.");
    }
}