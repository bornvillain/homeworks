#include "figure.h"
#include "triangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "quadrilateral.h"
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "rhombus.h"
#include "wrong_figure.h"

int main() {

    try {
        Figure f;
        Triangle t(10, 20, 30, 45, 45, 90);
        RightTriangle rt(3, 4, 5, 40, 50);
        EquilateralTriangle et(14);
        IsoscelesTriangle it(10, 10, 30, 120);
        Quadrilateral q(1, 2, 3, 4, 80, 70, 50, 160);
        Parallelogram p(10, 20, 80, 100);
        Square s(5);
        Rectangle r(6, 6);
        Rhombus rh(1, 110, 70);
    }
    catch (WrongFigure &ex) {
        std::cout << ex.what() << std::endl;
    }

}