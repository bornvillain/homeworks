#include <mutex>
#include <iostream>

class Data {
public:
    int value;
    std::mutex m;
};

void swap1(Data &d1, Data &d2) {
    std::lock(d1.m, d2.m);
    std::lock_guard<std::mutex>(d1.m, std::adopt_lock);
    std::lock_guard<std::mutex>(d2.m, std::adopt_lock);
    std::swap(d1.value, d2.value);
}

void swap2(Data &d1, Data &d2) {
    std::unique_lock lock1(d1.m, std::defer_lock);
    std::unique_lock lock2(d2.m, std::defer_lock);
    std::lock(lock1, lock2);
    std::swap(d1.value, d2.value);
}

void swap3(Data &d1, Data &d2) {
    std::scoped_lock(d1.m, d2.m);
    std::swap(d1.value, d2.value);
}

int main() {
    Data d1, d2;
    d1.value = 1;
    d2.value = 2;

    swap1(d1, d2);
    std::cout << "d1 value: " << d1.value << ", d2 value: " << d2.value << std::endl;

    swap2(d1, d2);
    std::cout << "d1 value: " << d1.value << ", d2 value: " << d2.value << std::endl;

    swap3(d1, d2);
    std::cout << "d1 value: " << d1.value << ", d2 value: " << d2.value << std::endl;
}
