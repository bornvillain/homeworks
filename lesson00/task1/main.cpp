#include <stdexcept>
#include <iostream>

class smart_array {
public:
    smart_array(int capacity)
            : size_(0), capacity_(capacity), ptr_(new int[capacity]) {}

    smart_array(const smart_array &other)
            : size_(other.size_), capacity_(other.capacity_), ptr_(new int[other.capacity_]) {
        for (int i = 0; i < other.size_; ++i) {
            *(ptr_ + i) = *(other.ptr_ + i);
        }
    }

    smart_array &operator=(const smart_array &rhs) {
        smart_array copy(rhs);
        swap(copy);
        return *this;
    }

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

    void swap(smart_array &copy) {
        std::swap(size_, copy.size_);
        std::swap(capacity_, copy.capacity_);
        std::swap(ptr_, copy.ptr_);
    }
};

int main() {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;

}