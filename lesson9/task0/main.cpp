#include <iostream>
#include "greeter.h"

int main() {
    Greeter g;
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << g.greet(name) << std::endl;
}