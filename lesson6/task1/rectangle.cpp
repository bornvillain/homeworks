#include "rectangle.h"

Rectangle::Rectangle(int a, int b)
        : Quadrilateral("Rectangle", a, b, a, b, 90, 90, 90, 90) {
    GetInfo();
}

