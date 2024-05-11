#include <iostream>
#include <vector>

template<typename T>
T square(T elem) {
    return elem * elem;
}

template<typename Type>
std::vector<Type> square(const std::vector<Type> &v) {
    std::vector<Type> result;
    for (const auto &elem: v) {
        result.push_back(elem * elem);
    }
    return result;
}

int main() {
    int a = 4;
    std::cout << square(a) << std::endl;

    std::vector<int> v = {-1, 4, 8};
    for (const auto &elem: square(v)) {
        std::cout << elem << " ";
    }
    return 0;
}
