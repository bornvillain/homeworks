#include "triangle.h"
#include "wrong_figure.h"

Triangle::Triangle(int a, int b, int c, double A, double B, double C)
        : Figure("Triangle", 3), a(a), b(b), c(c), A(A), B(B), C(C) {

    ThrowIfIncorrectTriangle();
    GetInfo();
}

Triangle::Triangle(std::string name, int a, int b, int c, double A, double B, double C)
        : Figure(name, 3), a(a), b(b), c(c), A(A), B(B), C(C) {
    ThrowIfIncorrectTriangle();
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

void Triangle::ThrowIfIncorrectTriangle() {
    if (A + B + C != 180) {
        throw WrongFigure("Error creating figure " + name + ". Reason: the sum of the angles does not equal 180.");
    }
}