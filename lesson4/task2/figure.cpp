#include<iostream>
#include "figure.h"

void Figure::GetInfo() {
    std::cout << name << std::endl;
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
