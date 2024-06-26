#include <exception>
#include <iostream>
#include <cassert>

template<typename Type>
class smart_ptr {
public:
    smart_ptr(Type *raw_ptr)
            : raw_ptr_(raw_ptr) {}

    smart_ptr(const smart_ptr &) = delete;

    smart_ptr &operator=(const smart_ptr &) = delete;

    smart_ptr(smart_ptr &&other) noexcept {
        raw_ptr_ = other.raw_ptr_;
        other.raw_ptr_ = nullptr;
    }

    smart_ptr &operator=(smart_ptr &&rhs) noexcept {
        delete raw_ptr_;
        raw_ptr_ = rhs.raw_ptr_;
        rhs.raw_ptr_ = nullptr;
        return *this;
    }

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
        smart_ptr sp1 = smart_ptr(new test_obj(2));
        smart_ptr sp2 = std::move(sp1);
        sp1 = std::move(sp2);
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