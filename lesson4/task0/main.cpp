#include<iostream>
#include "math.h"

int main() {
    int a, b, op;
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;
    std::cout << "Select operation (1: +, 2: -, 3: *, 4: /, 5: ^): ";
    std::cin >> op;
    switch (op) {
        case 1:
            std::cout << a << " + " << b << " = " << plus(a, b);
            break;
        case 2:
            std::cout << a << " - " << b << " = " << minus(a, b);
            break;
        case 3:
            std::cout << a << " * " << b << " = " << multiply(a, b);
            break;
        case 4:
            std::cout << a << " / " << b << " = " << divide(a, b);
            break;
        case 5:
            std::cout << a << " ^ " << b << " = " << power(a, b);
            break;
        default:
            std::cout << "Unknown operation!" << std::endl;
    }
}