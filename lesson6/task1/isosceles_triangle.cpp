#include "isosceles_triangle.h"

IsoscelesTriangle::IsoscelesTriangle(int a, int b, double A, double B)
        : Triangle("IsoscelesTriangle", a, b, a, A, B, A) {
    GetInfo();
}
