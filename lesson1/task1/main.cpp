#include <iostream>

class Counter {
public:
    Counter() {
        value_ = 1;
    }

    Counter(int value) {
        value_ = value;
    }

    void Increment() {
        ++value_;
    }

    void Decrement() {
        --value_;
    }

    int GetValue() {
        return value_;
    }

private:
    int value_;

};


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