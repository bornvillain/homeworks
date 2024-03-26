#include <iostream>
#include "leaver.h"

int main() {
    Leaver l;
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << l.leave(name) << std::endl;
}