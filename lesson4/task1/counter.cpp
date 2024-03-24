#include <iostream>
#include "counter.h"

Counter::Counter() {
    value_ = 1;
}

Counter::Counter(int value) {
    value_ = value;
}

void Counter::Increment() {
    ++value_;
}

void Counter::Decrement() {
    --value_;
}

int Counter::GetValue() {
    return value_;
}

void InteractWithUser(Counter &c) {

    do {
        std::cout << "Введите команду: ";
        char op;
        std::cin >> op;

        if (op == '+') {
            c.Increment();
        } else if (op == '-') {
            c.Decrement();
        } else if (op == '=') {
            std::cout << c.GetValue() << std::endl;
        } else if (op == 'x') {
            break;
        }
    } while (true);
    std::cout << "До свидания!";
}