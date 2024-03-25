#include<iostream>
#include "figure.h"

Figure::Figure() {
    GetInfo();
}

Figure::Figure(std::string name, int sides)
        : name(name), sides(sides) {}

void Figure::GetInfo() {
    std::cout << name << " created." << std::endl;
    if (IsRegular()) {
        std::cout << "Regular" << std::endl;
    } else {
        std::cout << "Irregular" << std::endl;
    }
    std::cout << "Number of sides: " << GetSides() << std::endl;
};

int Figure::GetSides() {
    return sides;
}

bool Figure::IsRegular() {
    return true;
}

void print_info(Figure *f) {
    f->GetInfo();
}