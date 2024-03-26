#include "isosceles_triangle.h"

IsoscelesTriangle::IsoscelesTriangle(int a, int b, double A, double B) : Triangle(a, b, a, A, B, A) {
    name = "IsoscelesTriangle";
}
