#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cassert>

template<typename Type>
class simple_vector {
public:

    simple_vector() = default;

    simple_vector(const simple_vector &other)
            : size_(other.size_), capacity_(other.capacity_), data_(new Type[other.capacity_]) {
        for (int i = 0; i < other.size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    simple_vector &operator=(const simple_vector &rhs) {
        simple_vector rhs_copy(rhs);
        swap(rhs_copy);
        return *this;
    }

    Type &operator[](int index) {
        return data_[index];
    }


    const Type &operator[](int index) const {
        return data_[index];
    }

    Type &at(int index) const {
        if (index >= size_) {
            throw std::out_of_range("index is out of range!");
        }
        return data_[index];
    }

    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    void push_back(const Type &value) {
        if (size_ >= capacity_) {
            capacity_ = (size_ == 0) ? 1 : 2 * size_;
            Type *temp = new Type[capacity_];
            for (int i = 0; i < size_; ++i) {
                temp[i] = data_[i];
            }
            std::swap(data_, temp);
            delete[] temp;
        }
        data_[size_] = value;
        ++size_;
    }


    ~simple_vector() {
        delete[] data_;
    }

private:
    int size_ = 0, capacity_ = 0;
    Type *data_ = nullptr;

    void swap(simple_vector &other) {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(data_, other.data_);
    }
};

int main() {
    simple_vector<int> sv1;
    std::cout << sv1.size() << " " << sv1.capacity() << std::endl;
    sv1.push_back(1);
    std::cout << sv1.size() << " " << sv1.capacity() << std::endl;
    sv1.push_back(2);
    std::cout << sv1.size() << " " << sv1.capacity() << std::endl;
    sv1.push_back(3);
    std::cout << sv1.size() << " " << sv1.capacity() << std::endl;
    simple_vector<int> sv2;
    sv2 = sv1;
    std::cout << sv2.at(0) << std::endl;
    std::cout << sv2.at(1) << std::endl;
    std::cout << sv2.at(2) << std::endl;
    bool exception_throw = false;
    try {
        std::cout << sv2.at(3) << std::endl;
    }
    catch (std::out_of_range &ex) {
        exception_throw = true;
        std::cout << ex.what() << std::endl;
    }
    assert(exception_throw);
}