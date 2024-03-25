#include <iostream>
#include <numeric>

class Fraction {
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator) {
        numerator_ = numerator / std::gcd(numerator, denominator);
        denominator_ = denominator / std::gcd(numerator, denominator);
    }

    bool operator==(const Fraction &r) {
        return numerator_ = r.numerator_ && denominator_ == r.denominator_;
    }

    bool operator!=(const Fraction &r) {
        return !(*this == r);
    }

    bool operator<(const Fraction &r) {
        return ((numerator_ * r.denominator_ - r.numerator_ * denominator_) / (denominator_ * r.denominator_)) < 0;
    }

    bool operator>=(const Fraction &r) {
        return !(*this < r);
    }

    bool operator>(const Fraction &r) {
        return !(*this < r) && (*this != r);
    }

    bool operator<=(const Fraction &r) {
        return !(*this > r);
    }

    Fraction operator+(const Fraction &r) {
        return Fraction(numerator_ * r.denominator_ + r.numerator_ * denominator_, denominator_ * r.denominator_);
    }

    Fraction operator-(const Fraction &r) {
        return Fraction(numerator_ * r.denominator_ - r.numerator_ * denominator_, denominator_ * r.denominator_);
    }

    Fraction operator*(const Fraction &r) {
        return Fraction(numerator_ * r.numerator_, denominator_ * r.denominator_);
    }

    Fraction operator/(const Fraction &r) {
        return Fraction(numerator_ * r.denominator_, denominator_ * r.numerator_);
    }

    Fraction operator-() {
        return Fraction(-numerator_, denominator_);
    }

    Fraction &operator++() {
        numerator_ = numerator_ + denominator_;
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction &operator--() {
        numerator_ = numerator_ - denominator_;
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    friend std::ostream &operator<<(std::ostream &os, const Fraction &f);
};

std::ostream &operator<<(std::ostream &os, const Fraction &f) {
    os << f.numerator_ << "/" << f.denominator_;
    return os;
}

int main() {
    int numerator1, denominator1, numerator2, denominator2;
    std::cout << "Enter the numerator of fraction 1: ";
    std::cin >> numerator1;
    std::cout << "Enter the denominator of fraction 1: ";
    std::cin >> denominator1;
    std::cout << "Enter the numerator of fraction 2: ";
    std::cin >> numerator2;
    std::cout << "Enter the denominator of fraction 2: ";
    std::cin >> denominator2;
    Fraction f1(numerator1, denominator1);
    Fraction f2(numerator2, denominator2);
    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;
    std::cout << "++" << f1 << " * " << f2 << " = " << ++f1 * f2 << std::endl;
    std::cout << "Fraction value 1: " << f1 << std::endl;
    std::cout << f1 << "--" << " * " << f2 << " = " << f1-- * f2 << std::endl;
    std::cout << "Fraction value 1: " << f1 << std::endl;
    return 0;
}