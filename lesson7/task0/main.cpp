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
        return numerator_ == r.numerator_ && denominator_ == r.denominator_;
    }

    bool operator!=(const Fraction &r) {
        return !(*this == r);
    }

    bool operator<(const Fraction &r) {
        return ((numerator_ * r.denominator_) - (r.numerator_ * denominator_)) / (denominator_ * r.denominator_) < 0;
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
};

int main() {
    Fraction f1(4, 3);
    Fraction f2(8, 6);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
    return 0;
}