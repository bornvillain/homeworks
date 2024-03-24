#include <iostream>
#include "counter.h"

int main() {
    std::cout << "Вы хотите указать начальное значение счётчика ? Введите да или нет: ";
    std::string answer;
    std::cin >> answer;
    bool default_value;

    if (answer == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        int initial_value;
        std::cin >> initial_value;
        Counter c(initial_value);
        InteractWithUser(c);
    } else if (answer == "нет") {
        Counter c;
        InteractWithUser(c);
    }
}