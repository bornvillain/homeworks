#include <stdexcept>
#include <iostream>

class smart_array {
public:
    smart_array(int capacity)
            : size_(0), capacity_(capacity), ptr_(new int[capacity]{}) {}

    void add_element(int elem) {
        if (size_ <= capacity_) {
            *(ptr_ + size_) = elem;
        } else {
            capacity_ *= 2;
            int *tmp = new int[capacity_];

            for (int i = 0; i < size_; ++i) {
                *(tmp + i) = *(ptr_ + i);
            }
            *(tmp + size_) = elem;
            std::swap(tmp, ptr_);
            delete[] tmp;
        }
        ++size_;
    }

    int get_element(int index) {
        if (index >= size_) {
            throw std::out_of_range("index is out of range!");
        }
        return *(ptr_ + index);
    }

    ~smart_array() {
        delete[] ptr_;
    }

private:
    int size_;
    int capacity_;
    int *ptr_;
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
}