#include <exception>
#include <iostream>
#include <cassert>

template<typename Type>
class smart_ptr {
public:
    smart_ptr(Type *raw_ptr)
            : raw_ptr_(raw_ptr) {}

    smart_ptr(const Type *&raw_ptr) = delete;

    Type *operator=(const Type *&other) = delete;

    Type &operator*() const {
        if (!raw_ptr_) {
            throw std::invalid_argument("raw pointer is nullptr!");
        }
        return *raw_ptr_;
    }

    Type *operator->() const {
        if (!raw_ptr_) {
            throw std::invalid_argument("raw pointer is nullptr!");
        }
        return raw_ptr_;
    }

    Type *release() {
        Type *raw_ptr = raw_ptr_;
        raw_ptr_ = nullptr;
        return raw_ptr;
    }

    ~smart_ptr() {
        delete raw_ptr_;
    }

private:
    Type *raw_ptr_ = nullptr;
};

class test_obj {
public:
    test_obj(int value)
            : value_(value) {
        std::cout << "ctor called!" << std::endl;
    }

    int get() const {
        return value_;
    }

    ~test_obj() {
        std::cout << "dtor called!" << std::endl;
    }

private:
    int value_ = 0;
};

int main() {
    {
        smart_ptr sp = smart_ptr(new test_obj(2));
    }

    smart_ptr sp = smart_ptr(new test_obj(2));
    assert((*sp).get() == 2);
    assert(sp->get() == 2);
    test_obj *p = sp.release();
    assert(p->get() == 2);

    try {
        *sp;
    }
    catch (std::invalid_argument &ex) {
        std::cout << ex.what() << std::endl;
        delete p;
    }
}