#include <set>
#include <iostream>

int main() {
    int requests;
    std::cin >> requests;

    int number;
    std::set<int, std::greater<>> numbers;
    for (int i = 0; i < requests; ++i) {
        std::cin >> number;
        numbers.insert(number);
    }

    for (const auto &num: numbers) {
        std::cout << num << std::endl;
    }
}