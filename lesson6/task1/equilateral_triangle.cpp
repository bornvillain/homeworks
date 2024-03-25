#include "equilateral_triangle.h"

EquilateralTriangle::EquilateralTriangle(int a)
        : Triangle("EquilateralTriangle", a, a, a, 60, 60, 60) {
    GetInfo();
}

