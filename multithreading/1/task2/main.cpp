#include <mutex>
#include <iostream>

class Data {
public:
    int value;
    std::mutex m;
};

void swap1(Data &d1, Data &d2) {
    d1.m.lock();
    d2.m.lock();
    std::swap(d1.value, d2.value);
    d2.m.unlock();
    d2.m.unlock();
}

void swap2(Data &d1, Data &d2) {
    std::unique_lock lock1(d1.m);
    std::unique_lock lock2(d2.m);
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

    swap3(d1, d2);
    std::cout << "d1 value: " << d1.value << ", d2 value: " << d2.value << std::endl;
}
