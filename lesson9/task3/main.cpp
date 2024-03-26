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

void print_info(Figure *f) {
    f->GetInfo();
}

int main() {
    Figure f;
    Figure *f_ptr = &f;
    print_info(f_ptr);

    Triangle t(10, 20, 30, 50, 60, 70);
    Figure *t_ptr = &t;
    print_info(t_ptr);

    RightTriangle rt(10, 20, 30, 50, 60);
    Figure *rt_ptr = &rt;
    print_info(rt_ptr);

    IsoscelesTriangle it(10, 20, 50, 60);
    Figure *it_ptr = &it;
    print_info(it_ptr);

    EquilateralTriangle et(30);
    Figure *et_ptr = &et;
    print_info(et_ptr);

    Quadrilateral q(10, 20, 30, 40, 50, 60, 70, 80);
    Figure *q_ptr = &q;
    print_info(q_ptr);

    Rectangle r(10, 20);
    Figure *r_ptr = &r;
    print_info(r_ptr);

    Square s(20);
    Figure *s_ptr = &s;
    print_info(s_ptr);

    Parallelogram p(20, 30, 30, 40);
    Figure *p_ptr = &p;
    print_info(p_ptr);

    Rhombus rh(30, 30, 40);
    Figure *rh_ptr = &rh;
    print_info(rh_ptr);
}