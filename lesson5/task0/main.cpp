#include <iostream>

#define MODE 1

#if MODE == 1

int add(int a, int b) {
    return a + b;
}

#endif

#ifndef MODE
error MODE macro required
#endif

int main(int argc, char **argv) {
#if MODE == 0
    std::cout<<"Working in training mode"<<std::endl;
#elif MODE == 1
    std::cout << "Working in combat mode" << std::endl;
    int a, b;
    std::cout << "Enter number 1: ";
    std::cin >> a;
    std::cout << "Enter number 2: ";
    std::cin >> b;
    std::cout << "Addition result: " << add(a, b);
#else
    std::cout<<"Unknown mode. Shutdown"<<std::endl;
#endif
}