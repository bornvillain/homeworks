#include "rhombus.h"

Rhombus::Rhombus(int a, double A, double B)
        : Quadrilateral("Rhombus", a, a, a, a, A, B, A, B) {
    GetInfo();
}
