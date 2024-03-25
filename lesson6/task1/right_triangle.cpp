#include "right_triangle.h"
#include "wrong_figure.h"

RightTriangle::RightTriangle(int a, int b, int c, double A, double B)
        : Triangle("RightTriangle", a, b, c, A, B, 90) {
    if (a * a + b * b != c * c) {
        throw WrongFigure("Error creating figure " + name + ". Reason: A^2+B^2!=C^2");
    }
    GetInfo();
}

