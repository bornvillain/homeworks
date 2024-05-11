#include <iostream>

template<typename T>
class table {
public:
    table(int rows, int cols)
            : data_(new T *[rows]), rows_(rows), cols_(cols) {
        for (int i = 0; i < rows_; ++i) {
            data_[i] = new T[cols_];
        }
    }

    T *operator[](int index) {
        return data_[index];
    }

    const T *operator[](int index) const {
        return data_[index];
    }

    int Size() const {
        return rows_ * cols_;
    }

    ~table() {
        for (int i = 0; i < rows_; ++i) {
            delete[] data_[i];
        }
        delete[] data_;
    }

private:
    T **data_;
    int rows_, cols_;
};

int main() {
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0];
}