#include "right_triangle.h"

RightTriangle::RightTriangle(int a, int b, int c, double A, double B) : Triangle(a, b, c, A, B, 90) {
    name = "RightTriangle";
}

