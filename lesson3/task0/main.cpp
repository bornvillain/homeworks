#include <iostream>

class Figure {
public:
    int GetSides() {
        return sides;
    }

protected:
    int sides = 0;
};

class Triangle : public Figure {
public:
    Triangle() {
        sides = 3;
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral() {
        sides = 4;
    }
};

int main() {
    Figure f;
    std::cout << "Фигура: " << f.GetSides() << std::endl;

    Triangle t;
    std::cout << "Треугольник: " << t.GetSides() << std::endl;

    Quadrilateral q;
    std::cout << "Четырёхугольник: " << q.GetSides() << std::endl;
}
