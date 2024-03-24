#include <iostream>

class Figure {
public:
    virtual void GetInfo() {
        std::cout << name << std::endl;
        if (IsRegular()) {
            std::cout << "Regular" << std::endl;
        } else {
            std::cout << "Irregular" << std::endl;
        }
        std::cout << "Number of sides: " << GetSides() << std::endl;
    };

    int GetSides() {
        return sides;
    }

    virtual bool IsRegular() {
        return true;
    }

protected:
    int sides = 0;
    std::string name = "Figure";
};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c, double A, double B, double C)
            : a(a), b(b), c(c), A(A), B(B), C(C) {
        name = "Triangle";
        sides = 3;
    }

    bool IsRegular() override {
        if (a == b && b == c && A == B && B == C) {
            return true;
        }
        return false;
    }

    void GetInfo() override {
        Figure::GetInfo();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << '\n'
                  << "Angles: A=" << A << " B=" << B << " C=" << C << std::endl;
    }

protected:
    int a, b, c;
    double A, B, C;
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, double A, double B) : Triangle(a, b, c, A, B, 90) {
        name = "RightTriangle";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, double A, double B) : Triangle(a, b, a, A, B, A) {
        name = "IsoscelesTriangle";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
        name = "EquilateralTriangle";
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(int a, int b, int c, int d, double A, double B, double C, double D)
            : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
        name = "Quadrilateral";
        sides = 4;
    }

    bool IsRegular() override {
        if (a == b && b == c && c == d && A == B && B == C && C == D) {
            return true;
        }
        return false;
    }

    void GetInfo() override {
        Figure::GetInfo();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n'
                  << "Аngles: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }

private:
    int a, b, c, d;
    double A, B, C, D;
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
        name = "Rectangle";
    }
};

class Square : public Quadrilateral {
public:
    Square(int a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90) {
        name = "Square";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, double A, double B) : Quadrilateral(a, b, a, b, A, B, A, B) {
        name = "Parallelogram";
    }
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(int a, double A, double B) : Quadrilateral(a, a, a, a, A, B, A, B) {
        name = "Rhombus";
    }
};

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
